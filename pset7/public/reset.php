<?php
     //configuration
    require("../includes/config.php");
    
    //if GET request is made
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // else render form
        render("reset_form.php", ["title" => "Reset your password"]);
    }
    
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        $old_password= CS50::query("SELECT hash FROM users WHERE id = ?", $_SESSION["id"]);
        
        if(empty($_POST["old_password"]))
        {
            apologize("Current password needs to be entered");
        }
        
        else if(empty($_POST["new_password"]))
        {
            apologize("New password needs to be entered");
        }
        
        else if(empty($_POST["confirmation"]))
        {
            apologize("Please enter new password again");
        }
        
        else if($old_password[0]["hash"] != crypt($_POST["old_password"], $old_password[0]["hash"]))
        {
            apologize("Current password is wrong");
        }
        
        else if ($_POST["new_password"] != $_POST["confirmation"])
        {
            apologize("Sorry, passwords incorrect");
        }
        
        else
        {
            CS50::query("UPDATE users SET hash = ? WHERE id = ?", crypt($_POST["new_password"]), $_SESSION["id"]);
            print("Password reset OK");
            redirect("index.php");
        }
    }
?>
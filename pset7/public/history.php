<?php
    // configuration
    require("../includes/config.php");
    
    // Query current users shares
    $query = CS50::query("SELECT  symbol,name,action, shares, price, date FROM history
        WHERE user_id = ? order by date desc", $_SESSION["id"]);
    
    if (count($query) == 0)
    {
        apologize("No recorded transactions for this user exist.");
    }
    // render history
    render("history_form.php", ["title" => "History", "history" => $query]);
?>
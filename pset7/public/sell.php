
<?php

    // configuration
    require("../includes/config.php");
 

  if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
       
       if(empty($_POST["symbol"]))
       {
           apologize("You must provide one Symbol");
       }
       
       $stock = lookup($_POST["symbol"]);
       
       if($stock === false)
       {
        apologize("Invalid Symbol.");
       }
       
       $query = CS50::query("SELECT shares FROM portfolio WHERE user_id = ? and symbol = ? ",  $_SESSION["id"], strtoupper($_POST["symbol"]));
      
      if(count($query)==1){
          $shares = $query[0]["shares"];
          
      }else{
          
          apologize("Symbol not found");
          
      }
      
      $value = $stock["price"] * $shares;
            
           $query = CS50::query("DELETE FROM portfolio WHERE user_id = ? and symbol = ?", $_SESSION["id"], strtoupper($_POST["symbol"]));
            if ($query === false)
            {
                apologize("Error while selling shares.");
            }
            
            $query = CS50::query("UPDATE users SET cash = cash + ? where id = ?", $value, $_SESSION["id"]);
            
            if ($query === false)
            {
               apologize("Error while selling shares.");
            }
            
             $query = CS50::query("SELECT cash FROM users WHERE id = ?",  $_SESSION["id"]);
            $cash = $query[0]["cash"]; 
           
               
            $cash += $value;
            
            // // Log the history
            $query = CS50::query("INSERT INTO history(user_id, symbol,name, action, shares, price, date) VALUES (?, ?, ?, ?, ?, ?, Now())"
                       ,$_SESSION["id"], strtoupper($stock["symbol"]), $stock["name"], "SELL", $shares, $stock["price"]);
                       
                       
            // Redirect to home
             redirect("index.php");
        }
    
    else
    {
        // Fill the array of user shares
        $query = CS50::query("SELECT symbol FROM portfolio WHERE user_id = ?", $_SESSION["id"]);
        render("sell_form.php", ["title" => "SELL", "symbols" => $query]);
    }
?>
<?php

    // configuration
    require("../includes/config.php"); 
    
    $query = CS50::query("SELECT symbol, shares, price FROM portfolio WHERE user_id = ?", $_SESSION["id"]);
    
    
    $shares = [];
    
    foreach ($query as $q){
        $stock = lookup ($q["symbol"]);
        
        if ($stock!== false){
            $shares[] = [  "symbol" => $q["symbol"],
                           "name" => $stock["name"],
                           "shares" => $q["shares"], 
                           "price"  => $stock["price"], 
                           "total" => $q["shares"]*$stock["price"]
                        ];
        }
    } 
    
    $cash = CS50::query("SELECT cash FROM users WHERE id = ?", $_SESSION["id"]);
    
      //  print_r ($shares);
    // render portfolio
   render("portfolio.php", ["shares" => $shares, "title" => "portfolio" , "cash" => $cash]);
    
?>

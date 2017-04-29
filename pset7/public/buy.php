
<?php

    // configuration
    require("../includes/config.php");
 

  if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
       
       if(empty($_POST["symbol"]))
       {
           apologize("You must provide one Symbol");
       }
       
       
        if (empty($_POST["shares"]) || !is_numeric($_POST["shares"]) || !preg_match("/^\d+$/", $_POST["shares"]))
        {
            apologize("Upsss!!! Something wrong!!  Enter the correct amount of shares!");
        }
       
       $stock = lookup($_POST["symbol"]);
       
       if($stock === false)
       {
        apologize("Invalid Symbol.");
       }
       
       $value = $stock["price"] * $_POST["shares"];
       
       $query = CS50::query("SELECT cash FROM users WHERE id = ?",  $_SESSION["id"]);
       $cash = $query[0]['cash']; 
            
            // Check the amount of cash
            if ($cash < $value)
            {
                apologize("You don't have sufficient amount of deposited money.");
            }
            else
            {
                
                
                // $query = CS50::query("SELECT * FROM portfolio WHERE id = ? and symbol = ?", $_SESSION["id"], $_POST["symbol"] );
                // if($query === false){
                //     $query = CS50::query("INSERT INTO portfolio(user_id, symbol, shares",$_SESSION["id"], strtoupper($stock["symbol"]), $_POST["shares"]); 
                    
                    
                // }else{
                //     $query = CS50::query("UPDATE portfolio SET shares = shares + ? ", $_POST["shares"]);
                    
                // }
       
      $query = CS50::query("INSERT INTO portfolio(user_id, symbol, shares, price) VALUES (?, ?, ?, ?)
                        ON DUPLICATE KEY UPDATE shares = shares + VALUES(shares)",
                        $_SESSION["id"], strtoupper($stock["symbol"]), $_POST["shares"], $stock["price"]);
                        
                       // echo ($query[0]["symbol"]);
                    
        if($query ===false){
            apologize("You can't buy shares with this parameters");
        }
            }
         $query = CS50::query("UPDATE users SET cash = cash - ? where id = ?", $value, $_SESSION["id"]);
         
         if($query ===false){
            apologize("You can't buy shares with this parameters");
        }
        
        $cash -= $value;
        
        //////////////////////////////////
       // me falta mostrar la tabla con las  acciones  de cada uno
        
        ///////////////////////////
          $query = CS50::query("INSERT INTO history(user_id, symbol,name, action, shares, price, date) VALUES (?, ?, ?, ?, ?, ?, Now())"
                       ,$_SESSION["id"], strtoupper($stock["symbol"]), $stock["name"], "Buy", $_POST["shares"], $stock["price"]);
                    
                     redirect("index.php");
                    
           
           
            }
        
    
    else{
        render("buy_view1.php", ["title" => "Buy"]);
        
    }
           
    

?>
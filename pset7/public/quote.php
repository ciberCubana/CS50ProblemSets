<?php

    // configuration
    require("../includes/config.php");
 

  if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
       if(empty($_POST["symbol"])){
       apologize("You must provide one Symbol.");
           
       }
       
       
       $stock = lookup($_POST["symbol"]);
       
       if($stock === false){
        apologize("Invalid Symbol.");
       }
       
       else{
    render("quote_form1.php", ["title" => "Quote", "symbol" => $stock["symbol"] , "name" => $stock["name"], "price" => $stock["price"]]);
       }
      }
       else{
         
   render("quote_form.php", ["title" => "Quote"]);
       }
           
    

?>
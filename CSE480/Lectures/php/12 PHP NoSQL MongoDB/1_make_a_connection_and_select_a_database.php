<?php
    require 'vendor/autoload.php';
   // connect to mongodb
   $m = new MongoDB\Client;
	
   echo "Connection to database successfully";
   // select a database
   $db = $m->mydb;
	
   echo "Database mydb selected";
?>
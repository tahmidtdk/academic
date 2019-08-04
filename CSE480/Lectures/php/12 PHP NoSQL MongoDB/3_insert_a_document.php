<?php
    require 'vendor/autoload.php';
   // connect to mongodb
   $m = new MongoDB\Client;
   echo "Connection to database successfully";
	
   // select a database
   $db = $m->mydb;
   echo "Database mydb selected";
   $collection = $db->mycol;
   echo "Collection selected succsessfully";
	
   $document = array( 
      "title" => "MongoDB", 
      "description" => "database", 
      "likes" => 100
   );
	
   $collection->insertOne($document);
   echo "Document inserted successfully";
?>
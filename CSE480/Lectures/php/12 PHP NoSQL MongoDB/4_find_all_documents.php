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

   $cursor = $collection->find();
   // iterate cursor to display title of documents
	echo "<br>";
   foreach ($cursor as $document) {
      echo $document["title"] . "\n";
   }
?>
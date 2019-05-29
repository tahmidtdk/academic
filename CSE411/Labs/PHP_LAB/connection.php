<?php

$servername = "localhost";
$username = "root";
$password = "";
$dbname = "sample_database";

$connection = mysqli_connect($servername, $username, $password, $dbname);

if (!$connection) {
    die("Connection failed: " . mysqli_connect_error());
	echo "Connection Failure!";
}
else{
	echo "Successfully Connected";
}

echo "<br> </br>";
?>
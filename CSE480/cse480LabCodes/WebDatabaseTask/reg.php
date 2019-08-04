<?php 

require 'db.php';
session_start();

$id = $_POST['id'];
$name = $_POST['name'];
$email = $_POST['email'];
$pass = $_POST['password'];
$confirm = $_POST['confirmpassword'];
$type = $_POST['type'];

if($pass != $confirm){
	$_SESSION['error'] = 'Password not match';
	header('Location: registration.php');
}
$sql = "SELECT id FROM user WHERE `id` = '$id'";
$act = $db->query($sql);
$row = mysqli_num_rows($act);
if($row==1)
{
	$_SESSION['error'] = $row ;
	header('Location: registration.php');
}
else
{
	$sql2 = "INSERT INTO `user`(`id`, `name`, `email`, `password`, `type`) VALUES ('$id','$name','$email', '$pass','$type')";
	$act2 = $db->query($sql2);
	header('Location: login.php');
}


?>
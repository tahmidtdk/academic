<?php 

$current = $_POST['oldpassword'];
$pass = $_POST['password'];
$confirm = $_POST['newpassword'];
$id = $_POST['id'];


require 'db.php';

$sql2 = "SELECT * FROM user WHERE `id` = '$id' AND `password` = '$current' " ;
$act = $db->query($sql2);

$row = mysqli_num_rows($act);

if($row){
	$sql = "Update `user` SET `password` = '$pass' WHERE `id` = '$id'";
	$act = $db->query($sql);

	header('Location: index.php');
	
}else{
	session_start();
	$_SESSION['error'] = 'Password not matched.';
	header('Location: change.php');
}

?>
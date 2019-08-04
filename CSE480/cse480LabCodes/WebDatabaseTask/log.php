<?php 

require 'db.php';
session_start();

$id = $_POST['id'];
$pass = $_POST['password'];
$rememberme = $_POST['rememberme'];



$sql = "SELECT * FROM user WHERE `id` = '$id' AND `password` = '$pass' ";

$act = $db->query($sql);
$row = mysqli_num_rows($act);

foreach ($act as $key) {
	$name = $key['name'];
	$type = $key['type'];
}
echo $row;
if($row == 1){
	if($rememberme == 'check'){
		setcookie('login', 'yes', time() + (86400 * 30), "/");
		setcookie('id', $id, time() + (86400 * 30), "/");
		setcookie('name', $name, time() + (86400 * 30), "/");
		setcookie('type', $type, time() + (86400 * 30), "/");
	}

	$_SESSION['id'] = $id;
	$_SESSION['type'] = $type;
	$_SESSION['name'] = $name;
	$_SESSION['error'] = null;
	header('Location: index.php');

} else {
	$_SESSION['error'] = 'ID / Password is not match';

	header('Location: login.php');
}


?>
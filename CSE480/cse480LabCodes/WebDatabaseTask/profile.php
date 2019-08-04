<!DOCTYPE html>
<html>
<head>
	<title>Users list</title>
	<link rel="stylesheet" type="text/css" href="style.css">
</head>
<body>

<?php 

session_start();

if(isset($_SESSION['id'])){
	$id = $_SESSION['id'];

}else {
	header('Location : login.php');
}


	require 'db.php';

	$sql = "SELECT * FROM user WHERE `id` = '$id' ";
	$act = $db->query($sql);

	foreach ($act as $key) {
		
	}

?>


	<table border="1" align="center">
		<tr>
			<td colspan="2" align="center">Profile</td>
		</tr>
		<tr>
			<td>ID</td>
			<td><?php echo $key['id']; ?></td>
		</tr>
		<tr>
			<td>NAME</td>
			<td><?php echo $key['name']; ?></td>
		</tr>
		<tr>
			<td>EMAIL</td>
			<td><?php echo $key['email']; ?></td>
		</tr>
		<tr>
			<td>USER TYPE</td>
			<td><?php echo $key['type']; ?></td>
		</tr>
 
		<tr>
			<td colspan="2"><a href="index.php" style="text-decoration: underline; float: right">Go Home</a></td>
		</tr>
	</table>


</body>
</html>
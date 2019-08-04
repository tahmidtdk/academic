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
	if($_SESSION['type'] != 'admin'){
		echo 'You have no admin access';
		echo '<a href="index.php"> Home </a>';
	} 
}else {
	header('Location : login.php');
}


	require 'db.php';

	$sql = "SELECT * FROM user";
	$act = $db->query($sql);

?>


	<table border="1" align="center">
		<tr>
			<th colspan="4">Users</th>
		</tr>
		<tr>
			<th>ID</th>
			<th>NAME</th>
			<th>EMAIL</th>
			<th>USER TYPE</th>
		<?php foreach ($act as $key): ?>
		</tr>
			<td><?php echo $key['id']; ?></td>
			<td><?php echo $key['name']; ?></td>
			<td><?php echo $key['email']; ?></td>
			<td><?php echo $key['type']; ?></td>
		<tr>
		<?php endforeach ?>
			
		</tr>
		<tr>
			<td colspan="4"><a href="index.php" style="text-decoration: underline; float: right">Go Home</a></td>
		</tr>
	</table>


</body>
</html>
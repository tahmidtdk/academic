<!DOCTYPE html>
<html>
<head>
	<title>Registration</title>
	<link rel="stylesheet" type="text/css" href="style.css">
</head>
<body>

	<fieldset>
		<legend>Registration</legend>
		<form action="reg.php" method="post">
			ID <br>
			<input type="text" name="id"> <br>
			Password <br>
			<input type="password" name="password"> <br>
			Confirm Password <br>
			<input type="password" name="confirmpassword"> <br>
			Name <br>
			<input type="text" name="name"> <br>
			Email <br>
			<input type="email" name="email"> <br>
			User Type [User/Admin] <br>
			<select name="type">
				<option value="user">User</option>
				<option value="admin">Admin</option>
			</select> <br>
			<hr>
			<input type="submit" name="registration" value="Register">
			<a href="login.php">Login</a>
		</form>
	</fieldset>

	<?php 
	session_start();

	if(isset($_SESSION['error'])){
		echo '<li>'.$_SESSION['error']. '</li>';
	}
	?>


</body>
</html>
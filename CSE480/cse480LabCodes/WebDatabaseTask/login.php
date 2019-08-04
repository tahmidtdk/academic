<!DOCTYPE html>
<html>
<head>
	<title>Login</title>
	<link rel="stylesheet" type="text/css" href="style.css">
</head>
<body>

	<?php 

	session_start();
	if(isset($_SESSION['id'])){
		header('Location: index.php');
	}

	?>

	<fieldset>
		<legend>Login</legend>
		<form action="log.php" method="post">
			User ID <br>
			<input type="text" name="id"> <br>
			Password <br>
			<input type="password" name="password"> <br> <br>

			<input type="checkbox" name="rememberme" value="check"> Remember Me <br> 
			
			<hr>
			<input type="submit" name="login" value="Login">
			<a href="registration.php">Register</a>
		</form>
	</fieldset>


	<?php 

		if(isset($_SESSION['error'])){
			echo '<li>'. $_SESSION['error'] . '</li>';
		}

 	?>


</body>
</html>
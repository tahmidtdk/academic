<!DOCTYPE html>
<html>
<head>
	<title>Login</title>
	<link rel="stylesheet" type="text/css" href="style.css">
</head>
<body>

	<?php 

	session_start();
	if(!isset($_SESSION['id'])){
		header('Location: index.php');
	}

	?>

	<fieldset>
		<legend>Change Password</legend>
		<form action="update.php" method="post" oninput='newpassword.setCustomValidity(newpassword.value != password.value ? "Passwords do not match." : "")'>
			<input type="hidden" name="id" value="<?php echo $_SESSION['id']; ?>"> <br>

			Current Password <br>
			<input type="password" name="oldpassword" required> <br>
			New Password <br>
			<input type="password" name="password" required> <br> 
			Retype New Password <br>
			<input type="password" name="newpassword" required> <br> <br>
			
	<?php 

		if(isset($_SESSION['error'])){
	
		echo '<li>'. $_SESSION['error'] . '</li>';

		unset($_SESSION['error']);
		}

 	?>

			<hr>
			<input type="submit" name="login" value="Change">
			<a href="index.php">Home</a>
		</form>
	</fieldset>



</body>
</html>
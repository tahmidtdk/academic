<!DOCTYPE html>
<html>
<head>
	<title>Home Page</title>
	<link rel="stylesheet" type="text/css" href="style.css">
</head>
<body>

	<?php 
		session_start();

		if (!isset($_SESSION['id'])) {
				header('Location: login.php');
		}
		if (isset($_COOKIE['login'])) {
				$_SESSION['id'] = $_COOKIE['id'];
				$_SESSION['name'] = $_COOKIE['name'];
				$_SESSION['type'] = $_COOKIE['type'];
		}

	?>
<div align="center">

	<h1>Welcome <?php echo $_SESSION['name']; ?>!</h1>

	<ul>
		<li><a href="profile.php">Profile</a></li>
		<li><a href="change.php">Change Password</a></li>
<?php 
	if($_SESSION['type'] == 'admin'){ ?>
		<li><a href="user.php">View Users</a></li>

<?php 
	}

?>
		
		<li><a href="logout.php">Logout</a></li>

	</ul>

</div>


	<?php 
		if(isset($_SESSION['error'])){
			echo '<li>'. $_SESSION['error'] . '</li>';
		}
 	?>
</body>
</html>
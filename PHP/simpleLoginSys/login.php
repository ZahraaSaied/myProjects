<?php
	session_start();
	require 'connect.php';
?>
<!DOCTYPE html>
<html>
<head>
	<title>Login</title>
	<link rel="stylesheet" type="text/css" href="style.css">
</head>
<body>
	<div class="myform">
		<form method="post" action="">
			<label>Username</label>
			<input type="text" name="username" placeholder="Username" />
			<label>Password</label>
			<input type="password" name="password" placeholder="Password" />
			<br>
			<input type="submit" name="login" value="Login">
		</form>
	</div>
</body>
</html>
<?php
if (isset($_POST['login'])) {
	$username = $_POST['username'];
	$password = $_POST['password'];
	$query = "SELECT * FROM `users` WHERE `username` LIKE '$username' AND `password` LIKE '$password' ";
	$result = mysqli_query($connect, $query);
	$numrows = mysqli_num_rows($result);
	if ($numrows == 1) {
		$_SESSION['username']=$username;
		echo 'hello'. ' '. $username;
	}
	else
	{
		echo 'login failed';
	}

}


?>
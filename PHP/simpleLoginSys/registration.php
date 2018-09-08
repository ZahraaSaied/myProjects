<?php
	require 'connect.php';
?>
<!DOCTYPE html>
<html>
	<head>
		<title>Register</title>
		<link rel="stylesheet" type="text/css" href="style.css">
	</head>
	<body>
		<div class="myform">
			<form method="post" action="">
				<label>Username</label>
				<input type="text" name="username" placeholder="Username" />
				<label>Password</label>
				<input type="password" name="password" placeholder="Password" />
				<label>E-mail</label>
				<input type="email" name="email" placeholder="E-mail" />
				<br>
				<input type="submit" name="submit" value="Sign Up" />
			</form>
		</div>
	</body>
</html>
<?php
	if (isset($_POST['submit'])) 
	{
	$username = $_POST['username'];
	$password = $_POST['password'];
	$email = $_POST['email'];
	$query = "INSERT INTO `users` (`id`, `username`, `password`, `email`) VALUES (NULL, '$username', '$password', '$email')";
	mysqli_query($connect, $query);
	echo '<p>Registration Complete</p>'; 

	} 
?> 
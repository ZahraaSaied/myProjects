<?php
	session_start();
	if (isset($_SSESION['user'])) 
	{
		header('Location: main.php');	
		die();
	} 
?>
<!DOCTYPE html>
<html>
<head>
	<title>Login</title>
	<style type="text/css">
		.login-form 
		{
			margin: 0 auto;
			margin-top: 100px;
			border: 1px solid #ccc;
			padding: 50px;
			width: 300px;
			text-align: center;
		}
		#err-msg
		{
			color: #f00;
		}

	</style>
</head>
<body>
	<div class="login-form">
		<h2>Login</h2>
		<?php if (@$_GET['err'] == 1) { ?>
			<div id="err-msg">Login Erorr.Please try again</div>
		<?php } ?> 
		<form action="../index.php" method="POST">
			<p>Username <br>
			<input type="text" name="user">
			</p>
			<p>Password <br>
			<input type="password" name="pass">
			</p>
			<input type="submit" name="submit" value="login">
	</form>
	</div>
</body>
</html>
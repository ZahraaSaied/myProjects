<?php
	require_once '../models/UserModel.php';
	session_start();
	if (! isset($_SESSION['user'])) 
	{
		header('Location: login.php');
		die();	
	}
	else
	{
		$user = $_SESSION['user'];
	}
?>
<!DOCTYPE html>
<html>
<head>
	<title></title>
</head>
<body>
	<p>
		Welcome <?php echo $user->get_username() ?>
		You Are Now Logged In And Can Use Our Services.<br>
		<a href="../index.php?submit=logout">Logout</a>
	</p>

</body>
</html>
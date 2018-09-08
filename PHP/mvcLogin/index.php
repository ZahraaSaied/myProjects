<?php
	require_once 'models/UserModel.php';
	require_once 'controllers/UserController.php';

	@$req = $_REQUEST['submit'];
		$user_con = new UserController();
		switch ($req) {
			case 'login':
				$user = $_POST['user'];
				$pass = $_POST['pass'];
				if ($user_con->login($user, $pass)) 
				{
					header('Location: views/main.php');
					die();	
				}
				else
				{
					header('Location: views/login.php?err=1');
					die();
				}
				break;
			case 'logout':
				$user_con->logout();
				header('Location: views/login.php');
				die();
				break;
			
			default:
				header('Location: views/login.php');
				die();
				break;
		}
		
?>
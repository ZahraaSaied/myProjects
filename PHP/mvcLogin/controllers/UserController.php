<?php 
	
	class UserController
	{
		
		function __construct()
		{
			# code...
		}
		function create($username, $password, $email)
		{
			//create a new user record in db
		}
		function login($username, $password)
		{
			if ($this->authenticate($username, $password)) 
			{
				session_start();
				$user = new UserModel($username);
				$_SESSION['user'] = $user;
				return true;
			}
			else
			{
				return false;

			}
		}
		function authenticate($user, $pass)
		{
			$authentic = false;
			//check against db
			if ($user == "az" && $pass == "azaz")
				$authentic = true;
			return $authentic;
		}
		function logout()
		{
			//session_start();
			session_destroy();
		}
	}
 ?>
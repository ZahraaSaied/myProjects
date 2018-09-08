<?php 

	class UserModel 
	{
		private $username;
		
		function __construct($username)
		{
			$this->username = $username;
			
		}
		function get_username()
		{
			return $this->username;
		}
		function set_username($username)
		{
			$this->username = $username;
		}
	}

?>
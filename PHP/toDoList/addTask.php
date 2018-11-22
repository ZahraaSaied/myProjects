<?php 
	include_once 'db.php';
	if (isset($_POST['submit-task'])) 
	{
		$task = mysqli_real_escape_string($conn, $_POST['task']);
		$query = "INSERT INTO tasks (task_id, task_name, task_value, list_num) VALUES (NULL, '$task', '0', '1')";
		$result = mysqli_query($conn, $query);
		header("Location: index.php");
		die();
	}
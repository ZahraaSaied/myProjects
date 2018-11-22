<?php 
	include_once 'db.php';
	////////////////////delete///////////////////
	$id = $_GET['id'];
	//DELETE FROM `tasks WHERE `tasks`.`task_id` = 30;
	$query = "DELETE FROM tasks WHERE task_id = ".$id;
	$result = mysqli_query($conn, $query);
	header("Location: index.php");
	die();
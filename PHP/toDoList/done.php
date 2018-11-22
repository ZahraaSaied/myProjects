<?php 
	include_once 'db.php';
	////////////////////delete///////////////////
	$id = $_GET['id'];
	$query = "UPDATE tasks SET task_value = '1' WHERE task_id = ".$id;
	$result = mysqli_query($conn, $query);
	header("Location: index.php");
	die();
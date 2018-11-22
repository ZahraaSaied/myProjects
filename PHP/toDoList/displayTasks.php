<?php  
	include_once 'db.php';
	session_start();
	$query = "SELECT * FROM tasks";
	$result = mysqli_query($conn, $query);
	$numRows = mysqli_num_rows($result);
	if ($numRows > 0) 
	{
		while ($row = mysqli_fetch_assoc($result)) 
		{
			$tasks[] = $row;
		}
	}
	$_SESSION['myTasks'] = $tasks;
?>
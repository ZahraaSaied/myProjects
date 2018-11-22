<?php  
	include_once 'displayTasks.php';
?>
<!DOCTYPE html>
<html>
<head>
	<title>List</title>
	<link rel="stylesheet" type="text/css" href="main.css">
</head>
<body>
	<h2>Here is your To Do list !</h2>
	<?php
		foreach ($_SESSION['myTasks'] as $task => $info) 
		{
			echo "<ul><li>".@$_SESSION['myTasks'][$task]['task_name']; ?>
			<?php 
				if ($_SESSION['myTasks'][$task]['task_value'] == 0) 
				{
			?>
					<button><a href="done.php?id=<?php echo $_SESSION['myTasks'][$task]['task_id'];?>">Mark as done</a></button>
			<?php	
				} //end of if 
			?>
			<?php 
				if ($_SESSION['myTasks'][$task]['task_value'] == 1)
				{
			?>
				<span>done !</span>
			<?php
				}
			 ?>
			<button><a href="delete.php?id=<?php echo $_SESSION['myTasks'][$task]['task_id'];?>">Delete</a></button>
	<?php
		echo "</li></ul>";	
		} //end of foreach
	?>

	<form action="addTask.php" method="post">
		<input type="text" name="task" placeholder="write your task.." required autocomplete="off">
		<input type="submit" name="submit-task" value="Add Task">
	</form>
</body>
</html>
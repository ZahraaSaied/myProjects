<!DOCTYPE html>
<html>
<head>
	<title>Day of Week</title>
	<style type="text/css">
		p 
		{
			text-align: center; 
			color: #b90f4e; 
			font-size: 50px;  
		}
	</style>
</head>
<body>
	<?php
		$dayOfWeek = date('w');
		switch ($dayOfWeek) 
		{
			case 0:
				echo "<p>It's Sunday!</p>";
				break;
			case 1:
				echo "<p>It's Monday!</p>";
				break;
			case 2:
				echo "<p>It's Tuesday!</p>";
				break;
			case 3:
				echo "<p>It's Wednesday!</p>";
				break;
			case 4:
				echo "<p>It's Thursday!</p>";
				break;
			case 5:
				echo "<p>It's Friday!</p>";
				break;
			case 6:
				echo "It's Saturday!";
				break;
			default:
				echo "Unexcepected day!";
				break;
		}
		
	?>

</body>
</html>
<?php 
	include_once 'db.php';
?>
<!DOCTYPE html>
<html>
<head>
	<title>Article Page</title>
	<link rel="stylesheet" type="text/css" href="style.css">
</head>
<body>
	<div class="article-container">
		<?php 
			$title = $_GET['title'];
			$date = $_GET['date'];
				$query = "SELECT * FROM articles WHERE a_title = '$title' AND a_date = '$date'";
				$result = mysqli_query($conn, $query);
				$numRows = mysqli_num_rows($result);
				if ($numRows > 0) 
				{
					while ($row = mysqli_fetch_assoc($result)) 
					{
						echo "<div class ='article-box'>
							<h3>".$row['a_title']."<h3>
							<p>".$row['a_content']."</p>
							<p>".$row['a_date']."</p>
							<p>Written By: ".$row['a_auther']."</p>
						</div><hr>";
					}
				}
		?>
		
	</div>
</body>
</html>
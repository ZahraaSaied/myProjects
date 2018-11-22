<?php 
	include_once 'db.php';
?>
<!DOCTYPE html>
<html>
<head>
	<title>Home Page</title>
	<link rel="stylesheet" type="text/css" href="style.css">
</head>
<body>
	<form action="search.php" method="POST">
		<input type="text" name="search" placeholder="Search">
		<button type="submit" name="submit-search">Search</button>	
	</form>
	<h2>All articles: </h2>
	<div class="article-container">
		<?php 
			$query = "select * from articles";
			$result = mysqli_query($conn, $query);
			$resultRows = mysqli_num_rows($result);
			if ($resultRows > 0) 
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
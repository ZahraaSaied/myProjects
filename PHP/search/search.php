<?php 
	include_once 'db.php';
?>
<!DOCTYPE html>
<html>
<head>
	<title>Search Page</title>
	<link rel="stylesheet" type="text/css" href="style.css">
</head>
<body>
	<h2>Search Result</h2>
	<div class="article-container">
		<?php 
			if (isset($_POST['submit-search'])) 
			{
				$search = mysqli_real_escape_string($conn, $_POST['search']);
				$query = "SELECT * FROM articles WHERE a_title LIKE '%$search%' OR a_content LIKE '%$search%' OR a_auther LIKE '%$search%' OR a_date LIKE '%$search%'";
				$result = mysqli_query($conn, $query);
				$numRows = mysqli_num_rows($result);
				if ($numRows > 0) 
				{
					echo "There is ".$numRows." search result!";
					while ($row = mysqli_fetch_assoc($result)) 
					{
						echo "<a href = 'article.php?title=".$row['a_title']."&date=".$row['a_date']."'><div class ='article-box'>
							<h3>".$row['a_title']."<h3>
							<p>Written By: ".$row['a_auther']."</p>
						</div></a><hr>";
					}
				}
				else
				{
					echo "There is no result matches your search !";
				}

			}

		?>
		
	</div>

</body>
</html>
<?php
//database connection
	$connect = mysqli_connect("localhost", "root", "", "products")
	or die(mysql_error());
//collect post data
	$output = "";
	if (isset($_POST['submit'])) 
	{
		$search = mysqli_real_escape_string($connect, $_POST['search']);
		//prepare search query for DB search
		//$search_query = preg_replace("#[^0-9a-z]#i", "", $search);
		$query = "SELECT * FROM items WHERE pname LIKE '%$search%'OR price LIKE '%$search%'";
		//run query and get result
		$result = mysqli_query($connect, $query);
		$numrows = mysqli_num_rows($result);
		if ($numrows = 0) 
		{
			echo "No Search Result!";
		}
		else
		{
			while ($row = mysqli_fetch_assoc($result)) 
			{
				$pname = $row['pname'];
				$price = $row['price'];
				$output .= "<div>Product Name: ".$pname."  And Its Price: ".$price."$</div>";
			}
		}

	}
		 
?>
<!DOCTYPE html>
<html>
<head>
	<title>Search</title>
</head>
<body>
	<form action="searchProducts.php" method="post">
		<input type="text" name="search" placeholder="search products.." required>
		<input type="submit" name="submit" value="search">
	</form>
	<?php
		echo "<br>".$output; 
	?>
</body>
</html>
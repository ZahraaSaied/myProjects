<!DOCTYPE html>
<html>
<head>
	<title>Simple Calculator</title>
	<style type="text/css">
		form {text-align: center; height: 150px; width: 300px; background-color: #EEE; border: 1px solid #ccc; margin: 50px; margin-left: 400px; padding-top: 20px}
		input, select {display: block; height: 20px; width: 150px; margin: 5px; text-align: center;margin-left: 80px}
		p { border: 1px solid #ccc; font: 12px; text-align: center; margin-top: 10px; width: 300px; height: 25px; background-color: #eee; padding-top: 2px; margin-left: 400px }
	</style>
</head>
<body>
	<form action="<?php echo $_SERVER["PHP_SELF"]?>" method="post">
		<input type="number" name="num1" placeholder="Number 1" autocomplete="off" required>
		<input type="number" name="num2" placeholder="Number 2" autocomplete="off" required>
		<select name="operator" required>
			<option>Add</option>
			<option>Subtract</option>
			<option>Multiply</option>
			<option>Divide</option>
		</select>
		
		<input type="submit" name="submit" value="Calculate">
	</form>
</body>
</html>
<?php 
	if (isset($_POST["submit"])) 
	{
		$num1 = $_POST["num1"];
		$num2 = $_POST["num2"];
		$operator = $_POST["operator"];

		switch ($operator) 
		{
			case 'Add':
				$result = $num1+$num2;
				break;
			case 'Subtract':
				$result =  $num1 - $num2;
				break;
			case 'Multiply':
				$result =  $num1 * $num2;
				break;
			case 'Divide':
				$result =  $num1 / $num2;
				break;
			default:
				echo "Wrong operator!";
				break;
		}

		echo  "<p> The Answer is ". $result ."</p>";
	}

?>
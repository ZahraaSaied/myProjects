<!DOCTYPE html>
<html>
<head>
  <title>registration form</title>
  <style type="text/css">
    form {text-align: center; height: 300px; width: 300px; position: absolute; margin-top: 40px}
    input {text-align: center; display: block; font-size: 20px;border-radius: 2px; margin: auto; margin-bottom: 5px; padding-bottom: 5px}
    .sucess {color: green; font-size: 20px; margin-right: 15px}
    .error {color: red; font-size: 20px; margin-left: 20px}
  </style>
</head>
<body>
  <form action="includes/register.php" method="POST">
    <h2>Register</h2>
    <input type="text" name="fname" placeholder="First Name" <?php if (isset($_GET['fname'])) 
    {
      $fname = $_GET['fname'];
      echo "value ='$fname'";
    }?> 
    >
    <input type="text" placeholder="Email" name="email" 
    <?php if (isset($_GET['email'])) 
    {
      $email = $_GET['email'];
      echo "value ='$email'";
    }?>
    >
    <input type="text" placeholder="Username"  name="username" 
    <?php if (isset($_GET['username'])) 
    {
      $username = $_GET['username'];
      echo "value ='$username'";
    }?>
    >
    <input type="password" placeholder="Password" name="password">
    <input type="submit" name="register" value="Register">
  </form>
<?php  
  if (isset($_GET['register'])) 
  {
    if ($_GET['register'] == 'empty') 
    {
      echo "<p class = 'error'>You must fill all fields!</p>";
      exit();
    }
    elseif ($_GET['register'] == 'fname') 
    {
      echo "<p class = 'error'>Invalid Name!</p>";
      exit();
    }
    elseif ($_GET['register'] == 'username') 
    {
      echo "<p class = 'error'>Invalid Username!</p>";
      exit();
    }
    elseif ($_GET['register'] == 'email') 
    {
      echo "<p class = 'error'>Invalid Email!</p>";
      exit();
    }
    elseif ($_GET['register'] == 'success') 
    {
      echo "<p class = 'sucess'>You Registered Sucessfully ^^</p>";
      exit();
    }
  }
?>
</body>
</html>
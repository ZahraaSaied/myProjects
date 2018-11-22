<?php
  //collect post data
  if (isset($_POST['register']))
  {
    //connect database
    include_once 'connect.php';
    $fname = $_POST['fname'];
    $email = $_POST['email'];
    $username = $_POST['username'];
    $password = $_POST['password'];

    if (empty($fname) || empty($username) || empty($email) || empty($password)) 
    {
      header("Location: ../index.php?register=empty&fname=$fname&username=$username&email=$email");
      exit();
    }
    else
    {
      if(!preg_match("/^[a-zA-Z]*$/", $fname))
      {
        header("Location: ../index.php?register=fname&username=$username&email=$email");
        exit();
      }
      else
      {
        if(!preg_match("/^[a-zA-Z0-9]*$/", $username))
        {
          header("Location: ../index.php?register=username&fname=$fname&email=$email");
          exit();
        }
        else
        {
          if(!filter_var($email, FILTER_VALIDATE_EMAIL))
          {
            header("Location: ../index.php?register=email&fname=$fname&username=$username");
            exit();
          }
          else
          {
            $sql="INSERT INTO users (fname, username, email, password) VALUES ('$fname','$username', '$email', '$password')";
            mysqli_query($conn, $sql);
            header("Location: ../index.php?register=success");
            exit();
          }
        }
      }
    }
  }
  else
  {
    header("Location: ../index.php?register=error");
    exit();
  }
?>
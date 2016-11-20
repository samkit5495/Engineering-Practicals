<!--
Name - Samkitkumar H Jain
Class - TEIT Roll No 20
		Part C
	Assignment 2a
-->

<!DOCTYPE html>
<html>
<head>
	<title>Email Validation</title>
</head>
<body>
<br>
<hr>
<h1 align="center">Email Validation</h1>
<hr>
<form name="form1" method="post" action="">
	<center>

		<label>Enter Your Email Id</label>
		
		<input type="text" name="email">
		
		<br><br>
		
		<input type="submit">
	
	</center>

</form>
<?php 
	extract($_POST);
	if(empty($_POST))
		echo "Enter Email Id";
	else
	{
		echo "Your Email id is: $email";
		if(filter_var($email,FILTER_VALIDATE_EMAIL))
			echo "<br>Email is valid";
		else
			echo "<br>Email is invalid";
	}
 ?>
</body>
</html>

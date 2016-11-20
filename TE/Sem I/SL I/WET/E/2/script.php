<!--
Name - Samkitkumar H Jain
Class:TEIT Roll No. 20
Assignment E-2
-->
<!DOCTYPE html>
<html>
<head>
	<title>Data Retrivation</title>
</head>
<body>

<?php
session_start();
$con=mysql_connect("localhost","root","mysql");
$sel_db=mysql_select_db('login',$con);
if($con)
	echo "Connection Established!<br>";
else
	echo "Connection not Established!<br>";
?>
<form method="post" action="Login.html">
<?php
	$data=mysql_query("select * from user where username='".$_POST['username']."' and password='".$_POST['password']."';");
	$_SESSION["user_id"] =$_POST["username"];
	if(isset($_SESSION["user_id"]))
	{
		echo "User:".$_SESSION["user_id"]."<br>";
	}
	$num_rows = mysql_num_rows($data);
	if($num_rows > 0)
	{
		echo "<table align=center border=1>";
		echo "<tr>";
		echo "<th>Name</th>";
		echo "<th>Address</th>";
		echo "<th>Email Id</th>";
		echo "</tr>";
	    while($row = mysql_fetch_array($data))
	    {
			echo "<tr>";
			echo "<td>".$row['name']."</td>";
			echo "<td>".$row['address']."</td>";
			echo "<td>".$row['email']."</td>";
			echo "</tr>";
		}
		echo "</table>";
	}
	else
		echo "Table is empty!<br>";
?>

	<input type="submit" value="Logout">
</form>
</body>
</html>
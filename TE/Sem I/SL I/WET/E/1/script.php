<!--
Name - Samkitkumar H Jain
Class:TEIT Roll No. 20
Assignment E-1
-->
<!DOCTYPE html>
<html>
<head>
	<title>Data Retrivation</title>
</head>
<body>

<?php

$con=mysql_connect("localhost","root","mysql");
$sel_db=mysql_select_db('feedback',$con);
if($con)
	echo "Connection Established!<br>";
else
	echo "Connection not Established!<br>";

if(isset($_POST['insert']))
{
	extract($_POST);
	$ins_data=mysql_query("insert into feedback values('".$_POST['fname']."','".$_POST['lname']."','".$_POST['address']."','".$_POST['email']."','".$_POST['comment']."',".$_POST['mobno'].");");
	if($ins_data)
		echo "Data Inserted!";
	else
		echo "Data not inserted!";
}

if(isset($_POST['update']))
{
	extract($_POST);
	$update_data=mysql_query("update feedback set lname='".$_POST['lname']."',address='".$_POST['address']."',email='".$_POST['email']."',comment='".$_POST['comment']."',mobno=".$_POST['mobno']." where fname='".$_POST['fname']."';");
	if($update_data)
		echo "Data Updated!";
	else
		echo "Data not Updated!";
}

if(isset($_POST['delete']))
{
	extract($_POST);
	$del_data=mysql_query("delete from feedback where fname='".$_POST['fname']."';");
	if($del_data)
		echo "Data Deleted!";
	else
		echo "Data not Deleted!";
}

?>

<?php
	$data=mysql_query("select * from feedback;");
	$rownos=mysql_num_rows($data);
	if ( $rownos< 0)
		echo "No Record Found!";
	else
	{
		echo "<table align=center border=1>";
		echo "<tr>";
		echo "<th>First Name</th>";
		echo "<th>Last Name</th>";
		echo "<th>Address</th>";
		echo "<th>Email Id</th>";
		echo "<th>Comment</th>";
		echo "<th>Mobile No</th>";
		echo "</tr>";
	    while($row = mysql_fetch_array($data))
	    {
			echo "<tr>";
			echo "<td>".$row['fname']."</td>";
			echo "<td>".$row['lname']."</td>";
			echo "<td>".$row['address']."</td>";
			echo "<td>".$row['email']."</td>";
			echo "<td>".$row['comment']."</td>";
			echo "<td>".$row['mobno']."</td>";
			echo "</tr>";
		}
		echo "</table>";
	}
?>

</body>
</html>
<!--
Name - Samkitkumar H Jain
Class - TEIT Roll No 20
		Part C
	Assignment 1
-->

<!DOCTYPE html>
<html>
<head>
	<title>Calculator</title>
</head>
<body>
<br>
<hr>
<h1 align="center">Calculator</h1>
<hr>
<br>
<form align="center" method="post" action="">
	<label>Number 1 : </label>
	<input type="text" name="no1">
	<br><br>
	<label>Number 2 : </label>
	<input type="text" name="no2">
	<br><br>
	<input type="submit">
</form>

</body>
</html>

<?php  

	function add($no1,$no2)
	{
		echo "Addition is ".($no1+$no2)."<br>";
	}
	function sub($no1,$no2)
	{
		echo "Substraction is ".($no1-$no2)."<br>";
	}
	function mul($no1,$no2)
	{
		echo "Multiplication is ".($no1*$no2)."<br>";
	}
	function div($no1,$no2)
	{
		echo "Division is ".($no1/$no2)."<br>";
	}
	function mod($no1,$no2)
	{
		echo "Modulus is ".($no1%$no2)."<br>";
	}
	function avg($no1,$no2)
	{
		echo "Average is ".(($no1+$no2)/2)."<br>";
	}
	function maxi($no1,$no2)
	{
		echo "Maximum is ".max($no1,$no2)."<br>";
	}
	function mini($no1,$no2)
	{
		echo "Maximum is ".min($no1,$no2)."<br>";
	}
	extract($_POST);
	if(empty($_POST))
		echo "Enter Numbers";
	elseif(is_numeric($no1)&&is_numeric($no2))
	{ 
		echo "Number 1 is $no1<br>";
		echo "Number 2 is $no2<br>";
		add($no1,$no2);
		sub($no1,$no2);
		mul($no1,$no2);
		div($no1,$no2);
		mod($no1,$no2);
		avg($no1,$no2);
		maxi($no1,$no2);
		mini($no1,$no2);
	}
?>
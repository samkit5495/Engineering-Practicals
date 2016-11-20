<!--
Name - Samkitkumar H Jain
Class - TEIT Roll No 20
		Part C
	Assignment 2c
-->

<!DOCTYPE html>
<html>
<head>
	<title>Febonicci Series</title>
</head>
<body>

<?php 
	$num1=0;
	$num2=1;
	$sum=$num1+$num2;
	echo "<hr><center><h1>Febonicci Series</h1></center><hr>";
	echo "<br>$num1 <br> $num2 <br>";	
	for ($i=0; $i<=15  ; $i++)
	{ 
		echo $sum."<br>";
		$num1=$num2;
		$num2=$sum;
		$sum=$num1+$num2;
	}
 ?>

</body>
</html>

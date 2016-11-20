<!--
Name - Samkitkumar H Jain
Class - TEIT Roll No 20
		Part C
	Assignment 2b
-->

<!DOCTYPE html>
<html>
<head>
	<title>Color Change</title>

<?php 
	echo date('d-m-y h:i:s a');
	$hour=date('h');
	switch ($hour)
	{
		case 1:
			$bgcolor="chocolate";
			break;
		case 2:
			$bgcolor="aqua";
			break;
		case 3:
			$bgcolor="pink";
			break;
		case 4:
			$bgcolor="red";
			break;
		case 5:
			$bgcolor="green";
			break;
		case 6:
			$bgcolor="blue";
			break;
		case 7:
			$bgcolor="cyan";
			break;
		case 8:
			$bgcolor="magenta";
			break;
		case 9:
			$bgcolor="yellow";
			break;
		case 10:
			$bgcolor="brown";
			break;
		case 11:
			$bgcolor="gray";
			break;
		case 12:
			$bgcolor="orange";
			break;
	}
 ?>

</head>
<body bgcolor="<?php echo $bgcolor;  ?>">


</body>
</html>

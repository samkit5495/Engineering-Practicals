xquery version "1.0";

(: Generated with EditiX XML Editor (http://www.editix.com) at Thu Jan 05 17:41:01 IST 2017 :)

let $stud := (doc("D:/Dropbox/Documents/College Programs/SL-VI/Assignment 7/Student/student.xml") /BEIT/Student)
return <results>
{

	for $x in $stud
	where $x/Aggregate > 70
	order by  $x/Aggregate
	return <li>{data($x/Name)}</li>
}
</results>

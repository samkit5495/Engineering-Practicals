xquery version "1.0";

(: Generated with EditiX XML Editor (http://www.editix.com) at Sun Apr 23 14:02:57 IST 2017 :)

<ul>
{
for $x in doc("C:/Users/samkit5495/Assignment 7/data.xml")/BEIT/Student
return <li>{count($x/first_name)}</li>
}
</ul>

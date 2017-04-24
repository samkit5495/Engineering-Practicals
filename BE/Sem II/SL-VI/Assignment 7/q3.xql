xquery version "1.0";

(: Generated with EditiX XML Editor (http://www.editix.com) at Sun Apr 23 13:25:00 IST 2017 :)

for $x in doc("C:/Users/samkit5495/Assignment 7/data.xml")/BEIT/Student
where $x/marks>88
order by $x/first_name
return <li>{data($x/first_name)}</li>

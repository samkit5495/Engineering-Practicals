xquery version "1.0";


<ul>
{
for $x in doc("D:/Dropbox/Documents/College Programs/SL-VI/Assignment 7/order/customerOrders.xml")/Customer/orders
order by $x/amount
return <li>{$x/custname}</li>
}

</ul>

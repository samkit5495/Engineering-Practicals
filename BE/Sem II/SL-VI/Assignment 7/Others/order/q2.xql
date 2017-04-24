xquery version "1.0";

for $x in doc("D:/Dropbox/Documents/College Programs/SL-VI/Assignment 7/order/customerOrders.xml")/Customer/orders
order by $x/custname
return $x/custname

xquery version "1.0";

for $x in doc("D:/Dropbox/Documents/College Programs/SL-VI/Assignment 7/order/customerOrders.xml")/Customer/orders
return if($x/amount<20000)
then <Good>{data($x/custname)}</Good>
else <Excellent>{data($x/custname)}</Excellent>

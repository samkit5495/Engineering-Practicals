xquery version "1.0";

(: Generated with EditiX XML Editor (http://www.editix.com) at Thu Jan 12 11:40:17 IST 2017 :)

for $x in doc("D:/Dropbox/Documents/College Programs/SL-VI/Assignment 7/order/customerOrders.xml")/Customer/orders
return $x/custname

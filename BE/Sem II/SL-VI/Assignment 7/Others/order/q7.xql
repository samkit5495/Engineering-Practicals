for $x in doc("D:/Dropbox/Documents/College Programs/SL-VI/Assignment 7/order/customerOrders.xml")/Customer/orders
where $x/custname="Samkit" and $x/itemname="TV"
return $x/amount

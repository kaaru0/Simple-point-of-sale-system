===========================================================
Project Title 
===========================================================
Simple Point of Sale System for stationary supplies store


===========================================================
Project Details
===========================================================
For the text file based login system, a text file with employee details would be references before
granting access to the Point of sale system. This was done using File I/O commands of C programming to
that enables the program to read data from an external text file.

A class named item was constructed for the inventory list of the stationary/school supplies store with
public variables inside which pertains to the item’s name, item code, price and quantity defined by item_name,
item_code, price and quantity respectively. The name of the item is defined as a character variable type while
the rest is defined as integers. 

An object array was then defined in the displaymenu() function called myitem[20]
with a maximum of 21 elements. Only 15 items were defined in the store but additional items can be easily
defined in the source code. Each element in the array was also defined along with the variables in its
respective class. In order to display the inventory list. A for loop was implemented in tabular form which
would incrementally display the defined myitem array with their respective class variables. The processing of
orders generally revolved around these arrays. Additional arrays were defined where the specific orders were
stored. As orders are being taken by inputting their specific item code (defined within the source code), they
are subsequently being placed in these arrays for their respective price and quantity taken as well as the item
name which would be later displayed. Additionally, for each order of a specific item, the quantity of the item
in the inventory will also decrease depending on how many of the item was ordered. An updated inventory
list then exists after every order.

A separate class for discounts was also created with specific methods defined for each discount type.
The program essentially asks if a discount should be applied and if the input pertains to yes, then the program
would ask which type of discount whether PWD, senior or student discount. The first two would mean a 20%
off discount while the latter would get a 10% discount which is seen in the specific methods in the discount
class. Each discount type was also defined as objects in the class named senior, PWD, and student.
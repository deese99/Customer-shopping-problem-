# Customer-shopping-problem
A new shop opened recently on Lovely Street. It is extremely popular and you have been asked to help organize how the shoppers can enter and leave the shop. You must use semaphores as your synchronization mechanism for this problem. Before a shopper can enter, they must call EnterShop(), and this function blocks until it is ok to enter the shop. To enter the shop, the shopper then calls ShopForAWhile(). This function is already written and provided to you; it returns when you are done shopping. To indicate to the rest of the world that they are done shopping, a shopper must call LeaveShop(). You will write the EnterShop() and LeaveShop() functions.
So, a left-handed shopper would call these functions in this way:
EnterShop(LEFT); ShopForAWhile(); LeaveShop(LEFT);
The shopkeeper is a bit peculiar and has some strange rules that you must enforce:
1.	Shoppers can only enter the shop in pairs (groups of 2). Each group must have one left-handed person and one right-hand person. You must wait outside until you have found a pair. This means that both EnterShop() and LeaveShop() are called with a parameter of LEFT or RIGHT.
2.	At most one pair of shoppers can be in the store at the same time.
3.	Shoppers can leave the shop one at a time, but both shoppers must leave before the next pair can enter.

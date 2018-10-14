#name: Alex Vorhies
#date: September 10th, 2015
#description: A program that simulates shopping in a store

subtotal = 0.0 #pre-defining values of variables before starting the program
payment = 0.0
baseScrewdriver = 5.33 #defining the base cost of each item
baseHammer = 7.16
baseLadder = 20.67
cost_ladders = 0.0 #Defining total cost of items purchased before program runs
cost_screwdrivers = 0.0
cost_hammers = 0.0
quantity_hammers=0 #pre-defining number of items requested
quantity_ladders=0
quantity_screwdrivers=0
keepShopping = "yes" #pre-defining the keepShopping variable so the while loop isn't skipped

print("Welcome to Home Depot!\n" #I learned about moving output to a new line from the textbook
      "Screwdriver: $5.33\n"
      "Hammer: $7.16\n"
      "Ladder: $20.67")
while keepShopping.lower() == "yes":
    choice = input("What would you like to buy? ")
    if choice.lower() == "screwdriver": #if you select screwdriver, then this code runs
        quantity_screwdrivers = int(input("How many would you like? "))
        cost_screwdrivers = quantity_screwdrivers*baseScrewdriver
        subtotal = cost_hammers+cost_ladders+cost_screwdrivers
        print("So far, your total is $",format(subtotal,".2f"),sep="")
        keepShopping = input("Do you want to keep shopping? ") #if you say yes, you can select another item
    elif choice.lower() == "hammer": #if you select hammer, then this code runs
        quantity_hammers = int(input("How many would you like? "))
        cost_hammers = quantity_hammers*baseHammer
        subtotal = cost_hammers+cost_ladders+cost_screwdrivers
        print("So far, your total is $",format(subtotal,".2f"),sep="")
        keepShopping = input("Do you want to keep shopping? ")
    elif choice.lower() == "ladder": #if you select ladder, then this code runs
        quantity_ladders = int(input("How many would you like? "))
        cost_ladders = quantity_ladders*baseLadder
        subtotal = cost_hammers+cost_ladders+cost_screwdrivers
        print("So far, your total is $",format(subtotal, ".2f"),sep="")
        keepShopping = input("Do you want to keep shopping? ")
    else: #if your selection doesn't match any choice, then this code runs
        print("Please proceed to checkout.")
        keepShopping = "no"

print("Let's review your purchases:")
print(quantity_screwdrivers,"screwdrivers,",quantity_hammers,"hammers, and",quantity_ladders,"ladders.")
#print total number of items requested ^
print("Your subtotal is $",format(subtotal, ".2f"),sep="") #displays subtotal of items requested
sales_tax = float(input("What is sales tax? Put .05 for 5%. "))
total_cost = round(subtotal+(subtotal*sales_tax),2) #calculates total cost from subtotal and sales tax
#total cost gets rounded to two decimal places to avoid errors
print("Your total is $",format(total_cost,".2f"),sep="")
payment = float(input("How much will you be paying for your purchases? "))
if payment>=total_cost: #if payment exceeds or equals total cost, then this code runs
    change = payment-total_cost
    print("Your change is $",format(change,".2f"),sep="")
    dollars = int((change*100)//100) #Calculates number of dollars, quarters, dimes, etc. to return as change
    changeRemain = (change*100)%100
    quarters = int(changeRemain//25)
    changeRemain %= 25 #shortcut for changeRemain = changeRemain%25
    dimes = int(changeRemain//10)
    changeRemain %= 10
    nickels = int(changeRemain//5)
    changeRemain %= 5
    pennies = int(round(changeRemain,0)) #number of pennies gets rounded to avoid any calculation issues
    print(dollars,"dollar(s),",quarters,"quarter(s),",dimes,"dime(s),",nickels,"nickel(s), and",pennies,"pennie(s).")
    print("Thank you! Come again!")
else: #if payment does not exceed total cost, then this code runs
    print("That is not enough to complete your purchase.\n"
          "You cannot buy these items until you have enough money.")

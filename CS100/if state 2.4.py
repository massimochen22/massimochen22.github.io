print("Hi! Welcome to Hotel Massimo")
count = 0
while True:

  while count == "no":
    print("Ok, Bye!")
    break

  
  if count =="yes":
    print("Ok!")
    count = 0
    fail = True
    while fail:
      fail = False
      nights = input ("How many nights would you like to stay?")
      try:
          nights = int(nights)
          nights_p = (nights * 30000)
      except:
          print ("please enter the number of nights you want to stay.")
          fail = True


    fail2 = True
    while fail2:
      fail2 = False
      people = input ("How many people are staying?")
      try:
        people = int(people)
        if people > 2:
          people_p = (people-2)*10000*nights
        elif people <= 2:
          people_p = 0
      except:
        print ("please enter the number of people that are staying.")
        fail2 = True



    meal = 0
    while True:
      
      if meal == "yes":
        meal = 10000 * nights * people
        break
      elif meal == "no":
        meal = 0
        print("Ok.")
        break 
      else:
        meal = input("Would you like to have meals during your staying?Yes or no?")

    trip = 0
    while True:
      if trip == "yes":
        trip = 250000 * people
        break
      elif trip == "no":
        trip = 0
        print("Ok.")
        break 
      else:
        trip = input("Would you like to have a safari trip?Yes or no?")

    




    subtottsh = people_p + nights_p + meal + trip
    subtotus = subtottsh / 2000
    
    print("")
    print("Your Subtotal in TSH is",subtottsh,"  -->  Your Subtotal in USD is",subtotus) 
    print("Tax is",subtottsh*0.17,"TSH (17%)     -->  Tax is",subtotus*0.17,"USD (17%)")
    print("")
    tottsh = (subtottsh*0.17)+ subtottsh
    totus = (subtotus*0.17)+ subtotus

    print("Your total is",tottsh,"TSH            --> Your total is",totus,"USD")
    print("")
    print("")
    print("")
    print("")
  else:
    count = input ("Would you like to start calculate your price?")
  
  
  
  

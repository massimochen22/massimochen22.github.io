print("MATCHING SECTION. Italian to English")
print("")
print("1. Arrivederci       a. Eating")
print("")
print("2. Signora           b. See you/Bye")
print("")
print("3. Colazione         c. Breakfast")
print("")
print("4. Mangiare          d. Lady")
print("")
print("")
again="yes"
while True:
  if again == "no":
    print("Ok, Goodbye!")
    break

  elif again == "yes":
    correct = 0
    one = input("What is the translation for number 1?")
    one = one.strip()
    one = one.lower()
    if one=="b":
      print("Correct!")
      correct += 1
      print("")
    else:
      print("Incorrect...")
      print("")

    two = input("What is the translation for number 2?")
    two = two.strip()
    two = two.lower()
    if two =="d":
      print("Correct!")
      correct += 1
      print("")
    else:
      print("Incorrect...")
      print("")

      
    three = input("What is the translation for number 3?")
    three = three.strip()
    three = three.lower()
    if three =="c":
      print("Correct!")
      correct += 1
      print("")
    else:
      print("Incorrect...")
      print("")

    four = input("What is the translation for number 4?")
    four = four.strip()
    four = four.lower()
    if four =="a":
      print("Correct!")
      correct += 1
      print("")
    else:
      print("Incorrect...")
      print("")
      

    print("You scored",correct,"/ 4")
    print("")
    print("")
    again = input("Would you like to restart? Yes or No?")
    again = again.strip()
    again = again.lower()
    print("")

  else: 
    again = input("Would you like to restart? Yes or No?")
    print("")
    
  
    

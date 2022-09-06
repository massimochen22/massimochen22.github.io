again = 0
print("You are lost in a mysterious place after you woke up. You find 4 doors: the first one in front of you, the second one at your left, the third one behind you, and the last one at your right.") 
while True:

  if again == "no":
    print("Ok, Goodbye!")
    break 

  while again != "yes" and again != "no":
    if again == "no":
      print("Ok, Goodbye!")
      break

    else:
      again = input("Would you like to start? Yes or No?")

  else:
    direction = input("What door would you choose? Please type in \"front\" for the first one, \"left\" for the second one, \"back\" for the third one, and \"right\" for the fourth one")
    direction = direction.strip()
    direction = direction.lower()
    if direction == "front":
      print("Sorry the 1st door was a fake one, but it was poisonous, so you are dead.")
      again = input("Would you like to restart? Yes or No?")
      again = again.strip()
      again = again.lower()

    elif direction == "left":
      print("You found your way! Congratulations!")
      break

    elif direction == "back":
      print("You opened the back door and you fall in the trap. You are bleeding until you die")
      again = input("Would you like to restart? Yes or No?")
      again = again.strip()
      again = again.lower()

    elif direction == "right":
      print("Mr. Steen comes out from that door, and he forces you to code. You become crazy and commit suicide.")
      again = input("Would you like to restart? Yes or No?")
      again = again.strip()
      again = again.lower()

    else:
      direction = input("What door would you choose? Please type in \"front\" for the first one, \"left\" for the second one, \"back\" for the third one, and \"right\" for the fourth one")
      direction = direction.strip()
      direction = direction.lower()
   
    
    
    




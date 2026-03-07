age = int(input("How old are you?"))

if age <= 15:
    print("Sorry kid you are too young to get a driver license")

if age == 16:
    print("Hey! take Driver's Ed and get a permit!")

if age == 17:
    liscence = input("Did you take Driver's Ed already?")
    if liscence == "yes":
      print("Take the driving test then!")
    if liscence == "no":
      print("What are you waiting for? Take Driver's Ed and get a permit!")

if age >= 18:
    liscence2 = input("Did you take Driver's Ed already?")
    if liscence2 == "yes":
      passed = input("Did you pass the test?")
      if passed == "no":
        print("Too bad. You should try again")
      if passed == "yes":
        print("Nice job!Give me a ride")
    if liscence2 == "no":
      print("What are you waiting for? Take Driver's Ed and get a permit!")

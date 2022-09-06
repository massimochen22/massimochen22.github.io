
print("BIRTHDAY PROGRAM")
print("")
start = input("Would you like to start?")
start = (start.strip())
start = (start.lower())
bd = "ni"

while True:
  if start == "no":
    print("Ok, Goodbye!")
    break

  elif start == "yes":


    if bd == "no":
      print("Alright, use me when it is your birthday")
      break
    
    elif bd != "yes" and bd != "no":
      bd = input("Is it your birthday?")
      bd = (bd.strip())
      bd = (bd.lower())

    elif bd == "yes":
      age = int(input("How old are you?"))
      for i in range (1, age , 1):
        print("is it your birthday",i,"?")
      print("Yes it is your birthday! Happy birthday you are",age,"!")
      start = input("Would you like to restart?")
      start = (start.strip())
      start = (start.lower())
      bd = "ni"
    


  elif start != "no" and start != "yes":
    start = input("Would you like to restart?")
    start = (start.strip())
    start = (start.lower())

 



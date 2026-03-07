import random, math
rand_n = random.randint(1,100)
count = 0

number = input("please enter a number from 1 to 100")
while number != rand_n:
  
  fail = True
  while fail:
    fail = False
    try:
      number = int(number)
      if rand_n > number:
        print("Too low")
        number = input("please enter a number from 1 to 100")
        count += 1
      elif rand_n < number:
        print("too high")
        number = input("please enter a number from 1 to 100")
        count += 1
      elif rand_n == number:
        count += 1
        print("Good Job")
        break
      
    except:
      print("Oops that is not a number")
      number = input("please enter a number from 1 to 100")
      fail = True


print("Your guessing count:",count)

    

    
  





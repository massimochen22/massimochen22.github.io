number = int(input("Please tell me how many numbers of the fibonacci sequence would you like to see (please choose a number greater or equal to 2"))
if isinstance(number, int):
  number = int(input("please type in a number"))
  while number >= 0 and number < 2:
    number = int(input("Please tell me how many numbers of the fibonacci sequence would you like to see (please choose a number greater or equal to 2"))
## elif number != 
if number >=2:
  loops = 0
  x = 0
  y = 1
  z = 1
  print(x)
  print(y)
  while loops != number-2:
    z = y + x
    print(z)
    x = y
    y = z
    loops += 1


  


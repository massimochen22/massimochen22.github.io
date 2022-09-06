import random, math
again = input("Do you want a set of cards? yes or no?")

  
while again == "yes":
  spades = chr(9824)
  hearts = chr(9829)
  clubs = chr(9827)
  diamonds = chr(9830)
  count = 0

  while count != 5:
    rand_suit = random.randint(1,4)
    if rand_suit == 1:
      rand_suit = spades
    elif rand_suit == 2:
      rand_suit = hearts
    elif rand_suit == 3:
      rand_suit = clubs
    elif rand_suit == 4:
      rand_suit = diamonds
      
    rand_n = random.randint(1,13)
    if rand_n == 1:
      rand_n = "Ace"
    elif rand_n == 11:
      rand_n = "Jack"
    elif rand_n == 12:
      rand_n ="Queen"
    elif rand_n == 13:
      rand_n ="king"
      
    print(rand_n,rand_suit) 
    count += 1
    
  again = input("Do you want a set of cards? yes or no?")
  

if again == "no":
  print("Ok, Goodbye!")

while again != "yes" and again != "no":
  again = input("Do you want a set of cards? yes or no?")
  

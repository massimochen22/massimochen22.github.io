print("Greetings my dear customer, welcome to Massimo's Hotel")
print( " ")
nights = int(input("How many nights are you going to stay?"))

subtot = nights*99
hottax = subtot*0.15
saletax = subtot*0.06
total = subtot + hottax + saletax
print(" " )
print("staying for",nights,"nights will cost you--->",subtot,"$")
print(" " )
print("the hotel tax (15%) will be--->",hottax,"$")
print( " ")
print("the sale tax (6%) will be--->",saletax,"$")
print(" " )
print("--------------------------------------------" )
print("the total you have to pay is--->",total,"$")
print("--------------------------------------------" )

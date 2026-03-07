name = input("Hey brother! What is your name?")
print(" ")
print(" ")
print("Hi",name,"are you enjoying the USA? Nice health care right?")
print(" ")
print("These are some of the conversions that will be helpful to you")
print(" ")
print("Celsius to fahreneit formula---> °C × 9/5) + 32 = °F ")
print(" ")
print("Km to miles formula---> km / 1609 = mi")
print(" ")
print("Litres to gallons formula---> L/3.785 = gal")
print(" ")
print("Canadian dollars to US dollars formula---> CAD*0.74 = USD")
print(" ")
print(" ")
print("Too lazy to do the calculations? I got you",name)
print(" ")
celc= float(input("How many celcius you want to convert?"))
fahr= celc* (9/5) + 32
print(celc,"C =",fahr,"F")
print(" ")
km = float(input("How many km you want to convert?"))
mls= km / 1.609
print(km,"km =",mls,"mi")
print(" ")
print("Hey, let me also convert your gas price with ours")       
gas_lit_price= float(input("Please tell me how much is the gas per litre in CAD/l"))
gas_gal_price= gas_lit_price*1.12/0.264172
print(gas_lit_price,"CAD/L =",gas_gal_price,"USD/gal")
print("Lol we all know that such a price doesn't exist here in USA. We have cheaper gas.")

    
    

  

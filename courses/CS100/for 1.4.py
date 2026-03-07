count = 0
number = 1

for q in range(5):
  
  print("   x",number)
  for w in range(number,number*11,number):
    count += 1
    print(number,"x",count,"=",w)
  print("")
  number+=1
  count=0

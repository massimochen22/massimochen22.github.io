while True:
  first = float(input("please type your grade from the 1st quarter"))
  second = float(input("please type your grade from the 2nd quarter"))
  goal = float(input("What grade are you trying to achieve?"))
  final = (first * 0.45) + (second * 0.45)
  exam = (goal - final)*10
  print ("to get:",goal,"you have to get at least:",exam,"in your final")



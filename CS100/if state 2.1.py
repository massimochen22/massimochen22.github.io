print("Welcome to ECHS grading system.")
print("")
print("")
grade1 = float(input("please type in your first grade."))
grade2 = float(input("please type in your second grade."))
grade3 = float(input("please type in your third grade."))
gpa = (grade1+grade2+grade3)/3
print("")
print("")
if gpa >= 95.5:
  print("Nice job you got:",gpa,"= A")
elif gpa >= 92.5 and gpa<95.5:
  print("you got:",gpa,"= A-")
elif gpa >= 90.5 and gpa<=92.5:
  print("you got:",gpa,"= B+")
elif gpa >= 86.5 and gpa<90.5:
  print("you got:",gpa,"= B")
elif gpa >= 84.5 and gpa<86.5:
  print("you got:",gpa,"= B-")
elif gpa >= 82.5 and gpa<84.5:
  print("you got:",gpa,"= C+")
elif gpa >= 78.5 and gpa<82.5:
  print("you got:",gpa,"= C")
elif gpa >= 76.5 and gpa<78.5:
  print("you got:",gpa,"= C-")
  print("Oh you should be careful with your grade! Come on start studying!")
elif gpa >= 74.5 and gpa<76.5:
  print("you got:",gpa,"= D+")
  print("Oh you should be careful with your grade! Come on start studying!")
elif gpa >= 71.5 and gpa<74.5:
  print("you got:",gpa,"= D")
  print("Oh you should be careful with your grade! Come on start studying!")
elif gpa >= 69.5 and gpa<71.5:
  print("you got:",gpa,"= D-")
  print("Oh you should be careful with your grade! Come on start studying!")
elif gpa <= 69.5:
  print("you got:",gpa,"= F")
  print("You are failing! Try to improve your grade!")

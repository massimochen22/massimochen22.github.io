phrase = input("Hey write me a sentence. Please finish your sentence with a period")
leght_phrase = int(len(phrase)) - 1
if phrase[leght_phrase] != ".":
  print("please use a period at the end of the phrase")
  phrase = input("Rewrite me the sentence. Please finish your sentence with a period")
  leght_phrase = int(len(phrase)) - 1
  if phrase[leght_phrase] != ".":
    print("Bro are you kidding me? Where is the period?I'm not going to play with you anymore.")
  else:
    print("Now, I'm going to capitalize all your characters!")
    print(phrase.upper())
    print("Now, everything lower case!")
    print(phrase.lower())
    print(" ")
    print("Impressed huh?")
    print("Your sentence has",int(len(phrase)),"characters (including spaces and punctuations)")
    search = phrase.find("donut")
    if search == -1:
      print ("Now I'm going to replace all your \"Ls\" in \"Zs\"")
      print (phrase.replace("L","Z"))
    else:
      print ("I love donut!They are my favorite.")
      print ("Now I'm going to replace all your \"Ls\" in \"Zs\"")
      print (phrase.replace("L","Z"))
else:
  print("nice sentence!")
  print("Now, I'm going to capitalize all your characters!")
  print(phrase.upper())
  print("Now, everything lower case!")
  print(phrase.lower())
  print(" ")
  print("Impressed huh?")
  print("Your sentence has",int(len(phrase)),"characters (including spaces and punctuations)")
  search = phrase.find("donut")
  if search == -1:
    print ("Now I'm going to replace all your \"Ls\" in \"Zs\"")
    print (phrase.replace("l","z"))

  else:
    print ("I love donuts! They are my favorite.")
    print ("Now I'm going to replace all your \"Ls\" in \"Zs\"")
    print (phrase.replace("l","z"))

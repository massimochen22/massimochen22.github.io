import random

ans = input("Would you like to start? Yes or No?")
ans = ( ans.strip())
ans = ( ans.lower())

while True:
  if ans == "no":
    print("Ok, Goodbye!")
    break

  elif ans == "yes":
    a = ["Elf", "Dwarf", "Hobbit", "Human", "Gnome"]
    characters = (random.choice(a))
    b = ["Paladin", "Thief", "Barbarian", "Healer", "Magician", "Bard"]
    characters_class = (random.choice(b))

    your_character = (characters + " " +characters_class)
    print(your_character)


    dice = random.randint(1,6) + random.randint(1,6) + random.randint(1,6)
    if characters_class == "Paladin":
      dice = dice + 3
    print("Strength:",dice) ##(great for Paladins)

    dice = random.randint(1,6) + random.randint(1,6) + random.randint(1,6)
    if characters_class == "Thief":
      dice = dice + 3
    print("Dexterity:",dice) ##(...Thiefs)

    dice = random.randint(1,6) + random.randint(1,6) + random.randint(1,6)
    if characters_class == "Barbarian":
      dice = dice + 3
    print("Constitution:",dice) ##(...Barbarians)

    dice = random.randint(1,6) + random.randint(1,6) + random.randint(1,6)
    if characters_class == "Healer":
      dice = dice + 3
    print("Wisdom:",dice) ##(...Healers)

    dice = random.randint(1,6) + random.randint(1,6) + random.randint(1,6)
    if characters_class == "Magician":
      dice = dice + 3
    print("Intelligence:",dice) ##(...Magicians)

    dice = random.randint(1,6) + random.randint(1,6) + random.randint(1,6)
    if characters_class == "Bard":
      dice = dice + 3
    print("Charisma:",dice) ##(...Bards)

    ans = input("Would you like to restart? Yes or No?")
    ans = ( ans.strip())
    ans = ( ans.lower())

  else:
    ans = input("Would you like to start? Yes or No?")
    ans = ( ans.strip())
    ans = ( ans.lower())



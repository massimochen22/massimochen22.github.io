example = 'Hello World'

print ( example[0] )
                           # will output H
                           
print ( example[10] )
                           #will output d

print ( example[0:5] )
                           # will output Hello
                           
string1 = "Hello"
string2 = "World"
print ( string1 + string2)
                           # will output HelloWorld
                           
print ( string1 * 3)
                           #will output HelloHelloHello

print (string2.upper())
                           #will output WORLD

print (string1.lower())
                           #will output hello

print ( len(string1) )
                           #will output 5

space = "    America    " 
print ( space.strip() )
                           #will output America

space = "Outer Space" 
new_space = space.replace('Sp','Tr')
print (new_space)
                           #will output Outer Trace

example = 'Hello'
search = example.find(o)
print ( search )                     #<-- will output 4 (search will equal the position of the letter)
if search == -1:
  print ("Not found!")        #<-- if the letter is not found, it will set search to -1

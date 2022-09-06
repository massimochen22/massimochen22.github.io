import turtle as t

obj_2 = t.Turtle()


sc = t.Screen()
sc.title('China')

sc.setup(width=800, height=600)
#sc.tracer(0)

#big star
obj_2.penup()
obj_2.goto(-280,180)
obj_2.color('yellow','yellow')
obj_2.begin_fill()
for i in range (5):
  
  obj_2.left(72)
  obj_2.fd(50)
  obj_2.right(144)
  obj_2.fd(50)
obj_2.end_fill()

#small star1
obj_2.penup()
obj_2.goto(-133.5,255)
obj_2.color('yellow','yellow')
obj_2.begin_fill()
obj_2.left(52)
obj_2.fd(15)
obj_2.right(144)
obj_2.fd(15)
for i in range (4):
  
  obj_2.left(72)
  obj_2.fd(15)
  obj_2.right(144)
  obj_2.fd(15)
obj_2.end_fill()

#small star2
obj_2.penup()
obj_2.goto(-88,183)
obj_2.color('yellow','yellow')
obj_2.begin_fill()
obj_2.left(62)
obj_2.fd(15)
obj_2.right(144)
obj_2.fd(15)
for i in range (4):
  
  obj_2.left(72)
  obj_2.fd(15)
  obj_2.right(144)
  obj_2.fd(15)
obj_2.end_fill()

#small star3
obj_2.penup()
obj_2.goto(-85,96)
obj_2.color('yellow','yellow')
obj_2.begin_fill()
obj_2.left(30)
obj_2.fd(15)
obj_2.right(144)
obj_2.fd(15)
for i in range (4):
  
  obj_2.left(72)
  obj_2.fd(15)
  obj_2.right(144)
  obj_2.fd(15)
obj_2.end_fill()

#small star4
obj_2.penup()
obj_2.goto(-133.5,45)
obj_2.color('yellow','yellow')
obj_2.begin_fill()
obj_2.left(52)
obj_2.fd(15)
obj_2.right(144)
obj_2.fd(15)
for i in range (4):
  
  obj_2.left(72)
  obj_2.fd(15)
  obj_2.right(144)
  obj_2.fd(15)
obj_2.end_fill()


obj_2.hideturtle()


sc.bgcolor('red')
t.done() 

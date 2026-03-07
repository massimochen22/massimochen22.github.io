import turtle as t

obj = t.Turtle()
obj_1 = t.Turtle()
y=200

sc = t.Screen()
sc.title('USA')

sc.setup(width=760, height=400)
sc.tracer(0)


obj.penup()
obj.goto(-380,200)
obj.color('firebrick','firebrick')
obj.begin_fill()
for n in range(7):
  for x in range(2):
    obj.fd(760)
    obj.right(90)
    obj.fd(30.76)
    obj.right(90)
  obj.penup()
  y= y - 61.52
  obj.goto(-380,y)
obj.end_fill()



obj.penup()
obj.goto(-380,200)
obj.color('midnight blue','midnight blue')
obj.begin_fill()

for s in range(2):
  obj.fd(304)
  obj.right(90)
  obj.fd(215.4)
  obj.right(90)
obj.end_fill()




t.done() 

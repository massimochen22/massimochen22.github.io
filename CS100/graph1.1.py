import simplegui


def draw_handler(canvas):
    canvas.draw_line((100,600), (400, 0), 10, 'white')
    canvas.draw_line((400, 0), (700, 600), 10, 'white')
    canvas.draw_line((100,600), (700, 600), 10, 'white')
    canvas.draw_line((250,300), (550, 300), 10, 'white')
    canvas.draw_line((250,300), (400, 600), 10, 'white')
    canvas.draw_line((400, 600), (550, 300), 10, 'pwhite')
    
    
frame = simplegui.create_frame('Testing', 800, 600)
frame.set_draw_handler(draw_handler)
frame.start()

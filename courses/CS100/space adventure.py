import pygame , sys, os, time , random

pygame.init()

display_width = 800
display_height = 600

brown = (25,11,3)
black = (0, 0, 0)
white = (255,255,255)
red = (190,0,0)
green = (0,190,0)
bright_red = (255,0,0)
bright_green = (0,255,0)

pause = True
car_width = 73
car_height = 110

moon_x = 0
moon_y = 0


gameDisplay = pygame.display.set_mode((display_width,display_height))
pygame.display.set_caption('Space Adventure')
clock = pygame.time.Clock()
background = os.path.join("/Users/Massimo2/Desktop/Python 2019 files/space.PNG")
moon = pygame.image.load(background)
racecar = os.path.join("/Users/Massimo2/Desktop/Python 2019 files/jet.PNG")
carImg = pygame.image.load(racecar)
things_up = os.path.join("/Users/Massimo2/Desktop/Python 2019 files/asteroid.PNG")
thingsImg = pygame.image.load(things_up)


def unpause():
    global pause
    pause = False

    
def paused():
    global pause
    largeText = pygame.font.SysFont("comicsansms",115)
    TextSurf, TextRect = text_objects("Paused", largeText)
    TextRect.center = ((display_width/2),(display_height/2))
    gameDisplay.blit(TextSurf, TextRect)
    
    pause = True
    while pause:
        for event in pygame.event.get():

            if event.type == pygame.QUIT:
                pygame.quit()
                quit()
                
        #gameDisplay.fill(white)
        

        button("Continue",150,450,100,50,green,bright_green,unpause)
        button("Quit",550,450,100,50,red,bright_red,quitgame)

        pygame.display.update()
        clock.tick(15)
        
def back(moon_x, moon_y):
    gameDisplay.blit(moon,(moon_x,moon_y))
    
def quitgame():
    pygame.quit()
    quit()

    
def game_intro():

    intro = True

    while intro:
        for event in pygame.event.get():
            #print(event)
            if event.type == pygame.QUIT:
                pygame.quit()
                quit()
                
        gameDisplay.fill(white)
        back(moon_x, moon_y)
        largeText = pygame.font.Font('freesansbold.ttf',90)
        TextSurf, TextRect = text_objects("Space Adventure", largeText)
        TextRect.center = ((display_width/2),(display_height/2))
        gameDisplay.blit(TextSurf, TextRect)
        mouse = pygame.mouse.get_pos()
        button('Go!',150,450,100,50,green,bright_green,game_loop)
        button('Quit!',550,450,100,50,red,bright_red,quitgame)
        


        pygame.display.update()
        clock.tick(15)

def button(msg,x,y,w,h,ic,ac,action=None):
    mouse = pygame.mouse.get_pos()
    click = pygame.mouse.get_pressed()
    if x+w > mouse[0] > x and y+h > mouse[1] > y:
        pygame.draw.rect(gameDisplay, ac,(x,y,w,h))
        if click[0] == 1 and action != None:
            action()
    else:
        pygame.draw.rect(gameDisplay, ic,(x,y,w,h))

    smallText = pygame.font.Font("freesansbold.ttf",20)
    textSurf, textRect = text_objects(msg, smallText)
    textRect.center = ( (x+(w/2)), (y+(h/2)) )
    gameDisplay.blit(textSurf, textRect)

def things_dodged(count):
    font = pygame.font.SysFont(None, 25)
    text = font.render("Dodged:"+str(count), True, white)
    gameDisplay.blit(text,(0,0))
                       
def things(things_x,things_y):
    gameDisplay.blit(thingsImg,(things_x,things_y))

def car(x,y):
    gameDisplay.blit(carImg,(x,y))

def text_objects(text, font):
    textSurface = font.render(text, True,(200, 255, 200))
    return textSurface, textSurface.get_rect()
    
def message(text):
    font = pygame.font.Font('freesansbold.ttf', 100)
    text_surface = font.render(text, True, (200, 255, 200))
    gameDisplay.blit(text_surface, (90, 250))
    pygame.display.update()

def message_display(text):
    import threading

    p1 = threading.Thread(target=message, args=(text, ))
    
    # start the thread execution
    p1.start()

    # wait for it to complete to join it with the main program
    p1.join()

    time.sleep(2)
    game_loop()

def crash():
    global dodged
    dodged = str(dodged)
    largeText = pygame.font.SysFont("comicsansms",115)
    TextSurf, TextRect = text_objects('You Crashed', largeText)
    TextRect.center = ((display_width/2),(display_height/2))
    gameDisplay.blit(TextSurf, TextRect)
    largeText = pygame.font.SysFont("comicsansms",30)
    TextSurf, TextRect = text_objects('You dodged: '+ dodged, largeText)
    TextRect.center = ((display_width/2),(display_height/1.5))
    gameDisplay.blit(TextSurf, TextRect)

    while True:
        for event in pygame.event.get():
            #print(event)
            if event.type == pygame.QUIT:
                pygame.quit()
                quit()
                
        #gameDisplay.fill(white)
        

        button("Play Again",150,450,120,50,green,bright_green,game_loop)
        button("Quit",550,450,100,50,red,bright_red,quitgame)

        pygame.display.update()
        clock.tick(15) 
    
    
def game_loop():
    global pause
    global dodged

    x = (display_width * 0.45)
    y = (display_height * 0.8)

    x_change = 0
    y_change = 0

    things_x = random.randrange(0,display_width-100)
    things_y = -600

    things_speed =  4
    things_width = 80
    things_height = 80

    dodged = 0
    
    gameExit = False

    while not gameExit:
        
        for event in pygame.event.get():
            
            if event.type == pygame.QUIT:
                pygame.quit()
                quit()

            elif event.type == pygame.KEYDOWN:
                if event.key == pygame.K_LEFT:
                    x_change = -5
                elif event.key == pygame.K_RIGHT:
                    x_change = 5
                
                elif event.key == pygame.K_UP:
                    y_change = -5
                elif event.key == pygame.K_DOWN:
                    y_change = 5
                    
                

            
            elif event.type == pygame.KEYUP:
                if event.key == pygame.K_LEFT or event.key == pygame.K_RIGHT:
                    x_change = 0

                elif event.key == pygame.K_UP or event.key == pygame.K_DOWN:
                    y_change = 0

    
                   

                
        
        x += x_change
        y += y_change
        
        gameDisplay.fill(white)
        back(moon_x,moon_y)
        #things(thingx,thingy,thingw,thingh,color):
        things(things_x,things_y)
        things_y += things_speed

        car(x,y)

        things_dodged(dodged)
        #button('Pause',700,0,80,30,white,black,paused)

        if x > display_width - car_width or x < 0:
            crash()
            
            
        elif y > display_height - 70 or y < 0:
            crash()
            

        elif things_y > display_height:
          things_y = 0 - things_height
          things_x = random.randrange(0,display_width-100)
          dodged += 1
          things_speed = things_speed * 1.05
          
          
        elif y < things_y+things_height and y > things_y or y + car_height < things_y+things_height and y + car_height > things_y:
          #if y + car_height:

            

          if x > things_x and x < things_x + things_width or x+car_width > things_x and x + car_width < things_x+things_width:
            
            crash()
            
        
        button('Pause',700,0,80,30,black,black,paused)
        pygame.display.update()
        clock.tick(60)

game_intro()
game_loop()
pygame.quit()
quit()

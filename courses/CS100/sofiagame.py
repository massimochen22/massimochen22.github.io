import pygame,sys, os
import time, random 

pygame.init()

display_width = 800
display_height = 600

black = (0,0,0)
white = (255,255,255)
red = (255,0,0)

car_width = 73
car_height = 96

moon_x = 0
moon_y = 0

gameDisplay = pygame.display.set_mode((display_width,display_height))
pygame.display.set_caption('Massimo\'s first game')
clock = pygame.time.Clock()


background = os.path.join("/Users/Massimo2/Documents/befane.PNG")
moon = pygame.image.load(background)

racecar = os.path.join("/Users/Massimo2/Documents/sofia.PNG")
carImg = pygame.image.load(racecar)

things_up = os.path.join("/Users/Massimo2/Documents/poop.PNG")
thingsImg = pygame.image.load(things_up)

def back(moon_x, moon_y):
    gameDisplay.blit(moon,(moon_x,moon_y))

def things(things_x,things_y):
    gameDisplay.blit(thingsImg,(things_x,things_y))
    
def car(x,y):
    gameDisplay.blit(carImg,(x,y))

def text_objects(text, font):
    textSurface = font.render(text, True, black)
    return textSurface, textSurface.get_rect()
    
def message(text):
    font = pygame.font.Font('freesansbold.ttf', 80)
    text_surface = font.render(text, True, (255, 0, 0))
    gameDisplay.blit(text_surface, (150, 250))
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
    message_display('Game Over')
    
    
def game_loop():
    x = (display_width * 0.45)
    y = (display_height * 0.8)

    x_change = 0
    y_change = 0

    things_x = random.randrange(0,display_width-100)
    things_y = -600

    things_speed =  14
    things_width = 73
    things_height = 63
    
    gameExit = False

    while not gameExit:

        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                quit()

            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_LEFT:
                    x_change = -5
                elif event.key == pygame.K_RIGHT:
                    x_change = 5
                elif event.key == pygame.K_UP:
                    y_change = -5
                elif event.key == pygame.K_DOWN:
                    y_change = 5

            if event.type == pygame.KEYUP:
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

        if x > display_width - car_width or x < 0:
            crash()
            
        if y > display_height - 70 or y < 0:
            crash()   

        if things_y > display_height:
          things_y = 0 - things_height
          things_x = random.randrange(0,display_width-100)

        if y < things_y+things_height and y > things_y or y + car_height < things_y+things_height and y + car_height > things_y:
          #if y + car_height:

            

          if x > things_x and x < things_x + things_width or x+car_width > things_x and x + car_width < things_x+things_width:
            
            crash()

        
        pygame.display.update()
        clock.tick(60)

game_loop()
pygame.quit()
quit()


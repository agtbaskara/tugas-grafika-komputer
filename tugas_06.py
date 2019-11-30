# Baskara 16/398499/PA/17460

import pygame
import random
import math
 
pygame.init()

pygame.font.init()
font = pygame.font.SysFont('Arial', 20)

SCREEN_WIDTH = 700
SCREEN_HEIGHT = 500
screen = pygame.display.set_mode([SCREEN_WIDTH, SCREEN_HEIGHT])
pygame.display.set_caption("Animasi SIN")

clock = pygame.time.Clock()

ball_size = 25
ball_x = ball_size
ball_y = 0
ball_speed = 2

done = False

while not done:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            done = True

    ball_x += ball_speed
    ball_y = int((SCREEN_HEIGHT/2)+(SCREEN_HEIGHT/3)*math.sin(math.radians(ball_x)))

    if ball_x > SCREEN_WIDTH - ball_size or ball_x < ball_size:
        ball_speed *= -1
    
    background_image = pygame.image.load("MIPA_UGM.jpg").convert()
    screen.blit(background_image, [0, 0])
    text1 = font.render("x: "+str(ball_x), False, (0, 0, 0))
    text2 = font.render("y: "+str(ball_y), False, (0, 0, 0))
    screen.blit(text1,(5, 0))
    screen.blit(text2,(5, 20))

    pygame.draw.circle(screen, (255,0,0), [ball_x, ball_y], ball_size)

    clock.tick(60)
    pygame.display.flip()

pygame.quit()
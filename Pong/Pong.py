#author: Alex Vorhies
#date: 11/10/15
#description: The Driver class for a Pong game

#import processes required for boing.wav to work
import subprocess
import threading
#importing the classes needed for this class to work
from Paddle import *
from Ball import *
from tkinter import *

class Pong:
    def __init__(self):
        self.__threads = [] #required for boing.wav to work
        self.__score = 0 #initialize score
        window = Tk()
        window.title("Avoid the ball") # Set a title

        # set callback routine when mouse is moved
        window.bind("<Motion>", self.callback)

        # establish the canvas
        self.__width = 400 # Width of the self.canvas
        self.__height = 400 # Width of the self.canvas
        self.__canvas = Canvas(window, bg = "white",
            width = self.__width, height = self.__height)
        self.__canvas.pack()

        # create ball and paddle objects
        self.__ball = Ball(30,40,"red", self.__canvas, 30)
        self.__paddle = Paddle(380,380,"black", self.__canvas, 100, 20)

        # start the animation loop
        self.animate()
    #define the methods required to play boing.wav
    def worker(self):
        subprocess.call(["afplay","boing.wav"])

    def play_sound(self):
        t = threading.Thread(target=self.worker)
        self.__threads.append(t)
        t.start()
    #define score methods
    def get_score(self):
        return self.__score

    def set_score(self,score):
        self.__score = score

    # callback method
    # when mouse is moved, get the x-position of the mouse
    # set it to be the paddle x position
    def callback(self, event):
        x = event.x
        self.__paddle.set_x(x)

    # animation
    def animate(self):
        while True:
            self.__canvas.after(20) # Sleep
            self.__canvas.update() # Update self.canvas

            # colision detection code will go here
            if self.__ball.get_going_down() == True and \
            self.__ball.get_y()+self.__ball.get_diameter() >= self.__paddle.get_y() and \
            self.__ball.get_x() <= self.__paddle.get_x()+self.__paddle.get_width() and \
            self.__ball.get_x()+self.__ball.get_diameter() >= self.__paddle.get_x(): #if the ball hits the paddle
                self.__ball.set_speed(0) #stop the ball
                self.__paddle.set_color("red") #change the paddle to red
                self.__canvas.delete("score") #remove the score text from the applet
                #generate the game over text
                self.__canvas.delete("gameOver")
                self.__canvas.create_text(200,40,text="Game Over",font=("Helvetica",30),fill="black",tags="gameOver")
            elif self.__ball.get_y()+self.__ball.get_diameter() >= 408:
                #if the ball is at y 408 or greater
                self.__ball.set_speed(self.__ball.get_speed()+1) #increase the speed
                self.__paddle.set_color("black") #in case the paddle changes color too soon
                self.play_sound() #plays boing.wav
                self.set_score(self.get_score()+1) #increase the score by 1
                #generate the score text
                self.__canvas.delete("score")
                self.__canvas.create_text(200,40,text="Score: "+str(self.get_score()),
                      font=("Helvetica",30),fill="black",tags="score") #print score text


            # move the ball and draw the objects
            self.__ball.move()
            self.__ball.draw()
            self.__paddle.draw()

Pong()

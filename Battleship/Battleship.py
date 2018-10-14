#author: Alex Vorhies
#date: September 24, 2015
#description: A computer-generated Battleship game.
#proposed points (out of 20): I feel that because I have everything except for the two-dimension aspect
#of the program, I should receive 18 points on this assignment.

#import the random number generation
import random

#Pre-defining variables
guess = -1
attempts = 1

#determining the size of the map
columns = int(input("How many columns? "))

#choosing between random and choice of location
locationChoice = input("Do you want a random location? ")
if locationChoice.lower() == "yes":
    location = random.randint(0,(columns-1))
else:
    location = int(input("Please enter an integer between 0 and your columns minus 1: "))

#Printing the grid
for c in range(columns):
    if c == location:
        print("X",end=" ")
    else:
        print("O",end=" ")
print("")

#Playing the game
while attempts != 6: #while you have not exceeded 5 guesses
    while guess != location: #while you have not guessed the location
        print("Attempt #",attempts,sep="")
        guess = int(input("Guess an integer between 0 and your columns minus 1: "))
        locationDistance = abs(guess-location)
        if locationDistance>=3: #if your guess was 3 or more squares away
            print("You missed by a mile!")
            attempts += 1
            for x in range(columns): #re-print the map with the last guess marked
                if x == location:
                    print("X",end=" ")
                elif x == guess:
                    print("@",end=" ")
                else:
                    print("O",end=" ")
            print("")
        elif locationDistance==2: #if your guess was 2 squares away
            print("You're cold.")
            attempts += 1
            for x in range(columns): #re-print the map with the last guess marked
                if x == location:
                    print("X",end=" ")
                elif x == guess:
                    print("@",end=" ")
                else:
                    print("O",end=" ")
            print("")
        elif locationDistance==1: #if your guess was 1 square away
            print("You're getting warm.")
            attempts += 1
            for x in range(columns): #re-print the map with the last guess marked
                if x == location:
                    print("X",end=" ")
                elif x == guess:
                    print("@",end=" ")
                else:
                    print("O",end=" ")
            print("")
        else: #if you hit the battleship
            print("You sunk my battleship in",attempts,"attempt(s)!")
            for x in range(columns):
                if x == location and guess == location: #prints the map, but this time, the ship is marked with !
                    print("!",end=" ")
                else:
                    print("O",end=" ")
            print("")
            attempts = 6
print("Game over.")
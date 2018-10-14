#author: Alex Vorhies
#date: October 6, 2015
#description: A program that alters the Mona Lisa to display hidden messages or print it gray-scale
#proposed points (out of 20): I feel that because I have each aspect of the program that was required,
#I should receive 20 points

def printImage(): #defining writing of each pixel to the image
    if choice != 4:
        draw()
    else:
        if col<5 or row<5 or col>294 or row>449:
            draw()
        else:
            outfile.write(str(rGray) + "\n") #writes each gray-scale pixel to the image
            outfile.write(str(gGray) + "\n")
            outfile.write(str(bGray) + "\n")

def draw():
    outfile.write(str(r) + "\n") #prints the image, border and all
    outfile.write(str(g) + "\n")
    outfile.write(str(b) + "\n")

rTotal = 0 #pre-defining the total red, green, and blue component variables
bTotal = 0
gTotal = 0

infile = open("MonaLisa.ppm","r") #opens MonaLisa.ppm for read-only
outfile = open("out.ppm","w") #creates out.ppm for writing

line1 = infile.readline() #reads the first four lines of MonaLisa.ppm
line2 = infile.readline() #these are not pixels
line3 = infile.readline()
line4 = infile.readline()

outfile.write(line1) #writes the first four lines of out.ppm based on the first four lines of MonaLisa.ppm
outfile.write(line2) #these are not pixels
outfile.write(line3)
outfile.write(line4)

print("Red steganography: enter 1\n" #prints choices for the user to make
      "Green steganography: enter 2\n"
      "Blue steganography: enter 3\n"
      "Gray-scale: enter 4")
choice = int(input("What would you like to do? (enter an integer between 1 and 4) ")) #asks the user for a choice

for row in range(454): #reads each pixel in the picture
    for col in range(300):
        r = int(infile.readline()) #gets the RGB value for the current pixel and stores it in a variable
        rTotal += r #adds the current component value to rTotal
        g = int(infile.readline())
        gTotal += g
        b = int(infile.readline())
        bTotal += b
        if choice == 1: #if the user chooses red steganography
            if r%2 == 0 and b != 255: #if the red component is even and it's not on the border
                r=0 #black
                g=0
                b=0
            else: #if the red component is odd
                r=255 #white
                g=255
                b=255
        elif choice == 2: #if the user chooses green steganography
            if g%2 == 0 and b != 255: #if the green component is even and it's not on the border
                r=0 #black
                g=0
                b=0
            else: #if the green component is odd
                r=255 #white
                g=255
                b=255
        elif choice == 3: #if the user chooses blue steganography
            if b%2 == 0: #if the blue component is even
                r=0 #black
                g=0
                b=0
            else: #if the blue component is odd
                r=255 #white
                g=255
                b=255
        elif choice == 4: #if the user chooses gray-scale
            rGray = (r+g+b)//3 #makes each pixel gray-scale
            gGray = (r+g+b)//3
            bGray = (r+g+b)//3
        if col<5 or row<5 or col>294 or row>449:
            r=0
            g=0
            b=255
        printImage()

rAverage = round(rTotal/(454*300),3) #calculates the average components in MonaLisa.ppm
gAverage = round(gTotal/(454*300),3) #rounds values to 3 decimal places
bAverage = round(bTotal/(454*300),3)
print("Average red: ",rAverage) #prints the average components in MonaLisa.ppm
print("Average green: ",gAverage)
print("Average blue: ",bAverage)

outfile.close() #closes out.ppm
infile.close() #closes MonaLisa.ppm
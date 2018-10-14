#author: Alex Vorhies
#date: October 22, 2015
#description: A program that analyzes movie reviews
#proposed points (out of 20): I feel that because I have coded all of the menu choices provided,
#I should receive 20 points

choice = 0

def fileAverage(): #finds the average score of a file
    total = 0 #initialize total and count to equal 0
    count = 0
    fileName = input("What file would you like to open? ")
    wordFile = open(fileName,"r") #open the file name provided
    words = wordFile.readline().split() #makes the list called words from the line read
    for w in range(len(words)): #loop through all words in the list
        infile = open("movieReviews.txt","r") #opens the file movieReviews.txt for reading
        for line in infile: #for each line in movieReviews.txt
            data = line.rstrip("\n") #removes the \n character from the line read by Python
            list = data.split() #splits the line into a list
            score = int(list[0]) #list index 0 is the score of the review
            if words[w] in list: #if the word is in the current list
                total += score #add score to total
                count += 1 #add 1 to count
    print("The average score of words in",fileName,"is",round(total/count,2))
    print()
    infile.close() #close movieReviews.txt
    wordFile.close() #close the file with the words you were scoring

def getWord(): #scores a word that is found in movieReviews.txt
    total = 0
    count = 0
    word = input("What word would you like to search for? ")
    infile = open("movieReviews.txt","r") #opens the file movieReviews.txt for reading
    for line in infile:
        data = line.rstrip("\n") #removes the \n character from the line read by Python
        list = data.split() #splits the line into a list
        score = int(list[0]) #list index 0 is the score of the review
        if word in list: #if the word is in the current list
            count += 1 #add 1 to count
            total += score #add score to total
    print("The word \"",word,"\" was found ",count," times.",sep="")
    print("The average rating was",round(total/count,2))
    print()
    infile.close() #close movieReviews.txt

def highLow(): #finds the highest and lowest scoring words in a file provided by the user
    total = [] #need empty lists for below
    count = []
    avg = []
    max = float("-inf") #initialize max as -infinity and min as infinity
    min = float("inf")
    maxValue = 0
    minValue = 0
    fileName = input("What file would you like to open? ")
    wordFile = open(fileName,"r") #open the file provided in the input statement above
    words = wordFile.readline().split()
    wordsLength = len(words) #find out how many words are in the file provided
    for w in range(wordsLength): #loop through each word in the list
        total.append(0) #add 0 to the end of the pre-defined lists
        count.append(0)
        avg.append(0)
        infile = open("movieReviews.txt","r") #opens movieReviews.txt for reading
        for line in infile:
            data = line.rstrip("\n") #removes the \n character from the line read by Python
            list = data.split() #split the line into a list
            score = int(list[0]) #list index 0 is the score of the review
            if words[w] in list: #if the word in list element w is in the current list
                total[w] += score
                count[w] += 1
    for i in range(len(total)): #for each item in the list total
        if total[i]>max: #if the number in total element i is greater than the max
            max = total[i]
            maxValue = i
        if total[i]<min: #if the number in total element i is less than the min
            min = total[i]
            minValue = i
    print("The highest rated word was \"",words[maxValue],"\" with an average rating of ",round(total[maxValue]/count[maxValue],2),sep="")
    print("The lowest rated word was \"",words[minValue],"\" with an average rating of ",round(total[minValue]/count[minValue],2),sep="")
    print()
    infile.close() #close movieReviews.txt
    wordFile.close() #close the file with the words you are scoring

#print the menu
print("What would you like to do? \n"
          "1. Get the score of a word \n"
          "2. Get the average score of words in a file \n"
          "3. Find the highest/lowest scoring words in a file \n"
          "4. Exit")
choice = int(input("Enter a number: "))
while choice != 4: #while the user does not select 4 as a choice
    if choice == 1: #if the user chooses 1
        getWord()
    elif choice == 2: #if the user chooses 2
        fileAverage()
    elif choice == 3: #if the user chooses 3
        highLow()
    print("Would you like to do something else? \n"
              "1. Get the score of a word \n"
              "2. Get the average score of words in a file \n"
              "3. Find the highest/lowest scoring words in a file \n"
              "4. Exit")
    choice = int(input("Enter a number: "))

print("Thank you for using this service. Please come again.")
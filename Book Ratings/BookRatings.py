#author: Alex Vorhies
#date: October 29, 2015
#description: A program that takes ratings on books, determines the best and worst ones, and determines
#with whom you match best
#proposed points (out of 20): I feel that because I have each aspect of the program working without issue
#I should receive 20 points

ratingsMatrix = [] #pre-defining lists and variables before the code runs
books = []
myRating = []
names = []
suggested = []
maxBookSum = float("-inf") #float("-inf") means negative infinity
minBookSum = float("inf") #float("inf") means infinity
maxBookIndex = 0
minBookIndex = 0
maxScore = float("-inf")
bestMatch = 0

infile = open("bookRatings.txt","r") #read in data for the ratings matrix
for line in infile:
    data = line.rstrip("\n")
    list = data.split()
    ratingsMatrix.append(list)
infile.close()

infile = open("books.txt","r") #read in book titles
for line in infile:
    data = line.rstrip("\n")
    books.append(data)
infile.close()

infile = open("names.txt","r") #read in each of the names of the reviewers
for line in infile:
    data = line.rstrip("\n")
    names.append(data)
infile.close()

infile = open("myRatings.txt","r") #read in your ratings of the books
for line in infile:
    data = line.rstrip("\n")
    myRating.append(data)
infile.close()

for book in range(55): #for each book in the ratings matrix
    sumOfRatings = 0
    for person in range(86): #for each person in the ratings matrix
        sumOfRatings += int(ratingsMatrix[person][book])
    if sumOfRatings>maxBookSum: #is the current book the highest rated?
        maxBookSum = sumOfRatings
        maxBookIndex = book
    if sumOfRatings<minBookSum: #is the current book the lowest rated?
        minBookSum = sumOfRatings
        minBookIndex = book

print("The highest rated book with a sum of",maxBookSum,"and an index of",maxBookIndex,"is",books[maxBookIndex])
print("The lowest rated book with a sum of",minBookSum,"an an index of",minBookIndex,"is",books[minBookIndex])

for person in range(86): #for each person in the ratings matrix
    score = 0
    for book in range(55): #for each book in the ratings matrix
        score += int(ratingsMatrix[person][book])*int(myRating[book])
    if score>maxScore: #is this person the best match with your ratings?
        maxScore = score
        bestMatch = person

for book in range(55): #for each book in the ratings matrix
    if int(myRating[book]) == 0 and int(ratingsMatrix[bestMatch][book])>2:
        #if you have not read a particular book and your best match rated it highly
        suggested.append(books[book])

print("You match best with",names[bestMatch])
print("Here are some books that",names[bestMatch],"has read and rated highly that you have not read:")
for i in suggested: #for each item in the list named suggested
    print(i)
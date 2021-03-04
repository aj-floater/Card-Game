import sys
import os
import game

from betterinput import authInput
from betterinput import pressEnter

# these are all the arrays used in authentication
mainMenuChoices = ['1', '2', '3', '4']

####################---------------------- Main -------------------------##########################


os.system('cls')

# print(os. getcwd())

while True: # main
    print("Task 3 - Card Game\n")
    print("1. Play Game \n2. How to play \n3. Leaderboard \n4. Exit Game")
    menuSelect = authInput("> ", mainMenuChoices, True)
    os.system('cls')

    if menuSelect == '1': # starts the game
        print("PLAY GAME")
        game.playGame()
        print("GAME END")
        pressEnter()
    try:
        if menuSelect == '2': # outputs 'rules.txt'
            print("HOW TO PLAY")
            f = open("rules.txt")
            tempRules = ""
            print()
            for x in f:
                tempRules += x #when outputting text files using print(x) the formatting was changed
            print(tempRules)   #this prevents that
            pressEnter()
        if menuSelect == '3': # outputs the top 5 players in 'scores.txt'
            print("LEADERBOARD")
            f = open("scores.txt")
            #looks through the text file and finds the key values needed (i.e the name and the score) and turns them into an array
            scores = []
            index = 0
            isValueError = False
            try:
                for x in f:
                    name = ""
                    temp = 0
                    number = ""
                    stopName = 0
                    for i in x:
                        if i == ' ':
                            stopName += 1
                        if stopName == 0:
                            name += i
                        if stopName == 2:
                            number += i
                    scores.append([name, int(number)])
                    index += 1
            except ValueError:
                isValueError = True
                print("There was an error when reading 'scores.txt', please check for syntax errors in the file (if the problem persists, reinstall the package)")
            if isValueError != True:
                #this looks through the array and finds the highest score, it adds the score to another array and deletes the score from the array
                top5 = []
                i = 0
                isIndexError = False
                try:
                    for i in range(5):
                        index = 0
                        recordNum = []
                        for n in scores:
                            if index == 0:
                                recordNum.append(n[1])
                                recordNum.append(index)
                            elif n[1] > recordNum[0]:
                                recordNum[0] = n[1]
                                recordNum[1] = index
                            index += 1
                        
                        top5.append(scores[recordNum[1]])
                        scores.pop(recordNum[1])
                except IndexError:
                    isIndexError = True
                    print("There are only " + str(i) + " records so")
                    print("The top " + str(i) + " players are:")
                
                if isIndexError != True: # if there are more than 5 players tell the players
                    print("The top 5 players are:")

                #this is repeated until the top scores are found and put into an array
                print()
                index = 1
                for i in top5: #then, for each item in the array with the top scores print them
                    print(str(index) + ". " + i[0] + " with " + str(i[1]) + " points")
                    index += 1
            pressEnter()
    except FileNotFoundError:
        print("The file could not be found, please re-add the correct txt file or re-install the package")
        pressEnter()
    if menuSelect == '4': # exits the program
        sys.exit()
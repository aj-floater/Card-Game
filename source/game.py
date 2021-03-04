import random
from card import Card
from card import logic

from betterinput import authInput

def playGame(): # starts the game
    
    Authenticated_Names = []
    try:
        n = open("names.txt", "r")
        for l in n:
            Authenticated_Names.append(str.rstrip(l)) # str.rstrip() removes the trailing newline
    except FileNotFoundError:
        print("File 'names.txt' was not found, the game cannot run. Please re-add the correct txt file or re-install the package")
        return 0

    ################------------------- Name Authenication ----------------------######################

    Player1_NAME = authInput("Player 1: ", Authenticated_Names, False)
    Player2_NAME = authInput("Player 2: ", Authenticated_Names, False)

    ###################------------------- Pick Ups ----------------------###########################

    deck = [] # clears the deck
    for colourIterator in range(3):
        for num in range(10):
            colour = ''
            if colourIterator == 0: colour = 'R'
            if colourIterator == 1: colour = 'Y'
            if colourIterator == 2: colour = 'B'
            deck.append(Card(colour, num))

    random.shuffle(deck) #shuffles the deck

    # this declares the players hands as lists
    Player1_Hand = []
    Player2_Hand = []

    player1Num = 0
    player2Num = 0

    while len(deck) > 0: #keeps picking up Cards and comparing them until the deck is empty
        logic.pick_up(Player1_Hand, deck) #calls the pick_up function
        logic.pick_up(Player2_Hand, deck) 

        string = logic.compare(Player1_Hand, Player2_Hand) #returns which player wins in a temporary string

        if string == 'player1':
            logic.pick_up(Player1_Hand, Player2_Hand)
        elif string == 'player2':
            logic.pick_up(Player2_Hand, Player1_Hand)
        #if either player wins pick up the top Card from the other player

    ###################------------------- Who Won? ----------------------###########################

    outcome = 0
    if len(Player1_Hand) > len(Player2_Hand):
        print("\nPlayer 1 won with " + str(len(Player1_Hand)) + " cards!")
        outcome = 1
    elif len(Player2_Hand) > len(Player1_Hand):
        print("\nPlayer 2 won with " + str(len(Player2_Hand)) + " cards!")
        outcome = 2
    else:
        print("\nDraw!")

    if outcome != 0:
        f = open("scores.txt", "a")
        if outcome == 1:
            f.write(Player1_NAME + " Scored: " + str(len(Player1_Hand)) + "\n")
        else:
            f.write(Player2_NAME + " Scored: " + str(len(Player2_Hand)) + "\n")
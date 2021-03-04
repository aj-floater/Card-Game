def compareColour(Player1, Player2): # compares the colours of the cards
    #Red + Black = Red
    if Player1.colour == "R" and Player2.colour == "B":
        return "player1"
    if Player2.colour == "R" and Player1.colour == "B":
        return "player2"
    #Yellow + Red = Yellow
    if Player1.colour == "Y" and Player2.colour == "R":
        return "player1"
    if Player2.colour == "Y" and Player1.colour == "R":
        return "player2"
    #Black + Yellow = Black
    if Player1.colour == "B" and Player2.colour == "Y":
        return "player1"
    if Player2.colour == "B" and Player1.colour == "Y":
        return "player2"
    else: return "neither"

class logic:
    def pick_up(hand, deck): # this defines the function that picks up from the top of the deck and places the card in a players hand
        hand.insert(0, deck[0])
        deck.pop(0)
        return(hand, deck)

    def compare(Player1, Player2): # defines the function that compares the two cards
        whoWins = compareColour(Player1[0], Player2[0])
        if whoWins == "neither":
            whoWins = "player1" if (Player1[0].number > Player2[0].number) else "player2"
        return whoWins

class Card:
    def __init__(self, colour, number):
        self.colour = colour
        self.number = number


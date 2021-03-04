def authInput(message, array, isInputRequirements): # ensures user input can be processed by the program
    while True:
        temp = input(message)
        temp = temp.upper()
        if (temp) in array:
            return temp
            break
        else:
            if isInputRequirements: # this adds some level of security to the function
                print("The input requirements are: " + str(array) + ", you have not met these requirements\n")
            else:
                print("You have not met the input requirements, authenticated names can be found at names.txt")

def pressEnter():
    input("\nPress enter to continue...")
    import os
    os.system('cls')
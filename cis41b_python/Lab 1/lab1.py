'''
Lab 1

Trang Van
CIS 41B

Driver code that uses Scores class to implement functions

'''
from scores import Scores

# main() creates Scores object, reads the input file, and loops through the menu options
#    call functions
def main():
    s1 = Scores("input1.txt")
    s1.readFile()
    while True:  # CORRECTION: instead while choice != 5:
        menu_options = [0,printByTotal,printByLimit,generateCountry,printByFrequency,5]
        menu_choice = displayMenu()
        if menu_choice == 5:
            break
        menu_options[menu_choice](s1)        

# Prints menu option and validates user's input, returns the user's input as an int
def displayMenu():
    print("\n1. Print by total score\n2. Print by limit\n3. Print one\n4. Print score frequency\n5. Quit")
    
    user_choice = int(input(">> Enter your choice:"))
    
    while user_choice < 1 or user_choice > 5:
        print("Error: Invalid Input")
        user_choice = int(input(">> Enter your choice:"))
    
    return user_choice

# Uses Scores object and its function to print the total score in ascending order
def printByTotal(s1):
    s1.total_scores()

# Prompts user for a limit and whether they want to go above or below to pass into function
def printByLimit(s1):
    limit = input("Enter a score limit:")
    a_b = input("Above or below {}? (a/b):".format(limit))
    if a_b == 'a':
        s1.score_limit(limit, True)
    elif a_b == 'b':
        s1.score_limit(limit)

# Uses Score object to call funtion that checks the frequency of the scores
def printByFrequency(s1):
    s1.score_frequency()

# Generates a country and it's scores upon pressing the enter key, and pressing any
#    other key will exit the function
def generateCountry(s1):
    while True:
        user_input = input("Press enter key to print a country record, or enter any character to end: ")
        if user_input == '':
            s1.generate_country() 
        else:
            break
   

main()    #call to main()


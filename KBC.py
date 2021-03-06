'''
Created on 24 Mar 2021

@author: Aditya Asok
'''

# List of questions
questions = ['When is World Earth Day?',
             'Which country was part of the allies in World War 2?',
             'Which is fastest car in 2021?',
             'Which is full form of BCCI?',
             'Who developed Python language']

# Options available
options = [
['10 June', '25 December', '22 April' , '29 Febuary'],
['The UK', 'Japan', 'South Africa' , 'Australia'],
['Ferrari', 'Tesla Model 3', 'Buggati' , 'SSC Tuatara'],
['Board of Control for Cricket', 'Board of Control for Cricket in India', 'Board of Cricket in India' , 'Board of Council for Cricket in India'],
['Charles Babbage', 'Dennis Ritchie', 'Djarne' , 'Guido Van'],
]

#Correct answers
answers = ['22 April', 'The UK', 'SSC Tuatara', 'Board of Control for Cricket in India', 'Guido Van']


def play_game(name, questions, answers, options):

    print("Hello",name, ".. All the best!!")

    scores = 0
    for i in range(len(questions)):
        current_question = questions[i]
        correct_answer = answers[i]
        current_options = options[i]
        print("\nQuestion : ",current_question)
        for counter, each_option in enumerate(current_options):
            print(counter+1, ") ", each_option, sep='')

        user_answer_index = int(input("Please enter your option : "))
        
        
        user_answer = current_options[user_answer_index-1]

        if user_answer == correct_answer:
            print("Correct Answer")
            scores += 100
        else:
            print("Wrong Answer")
            break

    print("Your final score : ", scores)
    return name, scores


def view_score(names_and_scores):
    for name, score in names_and_scores.items():
        print(name, "scored", score)

# Menu
def KBC(questions, answers, options):

    names_and_scores = {}
    while True:
        print("Welcome to the KBC Game...")
        print("1) Play Game\n2) View Scores\n3) Exit")
        user_input = int(input("Please enter your input : "))
        if user_input == 1:
            name = input("Please enter your name : ")
            name, score = play_game(name, questions, answers, options)
            names_and_scores[name] = score
        
        elif user_input == 2:
            view_score(names_and_scores)

        elif user_input == 3:
            break
        else:
            print("Invalid input.. Please enter valid input again...")

KBC(questions, answers, options)
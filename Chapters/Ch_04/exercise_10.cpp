// Write a program that plays the game “Rock, Paper, Scissors.” If you are not
// familiar with the game do some research (e.g., on the web using Google).
// Research is a common task for programmers. Use a switch-statement to solve
// this exercise. Also, the machine should give random answers (i.e., select the
// next rock, paper, or scissors randomly). Real randomness is too hard to
// provide just now, so just build a vector with a sequence of values to be used
// as “the next value.” If you build the vector into the program, it will always
// play the same game, so maybe you should let the user enter some values. Try
// variations to make it less easy for the user to guess which move the machine
// will make next. 

#include "std_lib_facilities.h"

char getWinner(char userChoice, char computerChoice)
{
    switch (userChoice) {
        case 'r':
            switch (computerChoice) {
                case 'r':
                    return 'n';
                case 'p':
                    return 'c';
                case 's':
                    return 'u';
            }
        case 'p':
            switch (computerChoice) {
                case 'r':
                    return 'u';
                case 'p':
                    return 'n';
                case 's':
                    return 'c';
            }
        case 's':
            switch (computerChoice) {
                case 'r':
                    return 'c';
                case 'p':
                    return 'u';
                case 's':
                    return 'n';
            }
    }
    return 'n';
}


int main()
{
    cout << ""; // INTRO PART
    cout << "Ready? (y)es or (n)o.\n";
    char userPlay;
    cin >> userPlay;
    vector<char> computerOptions = {'r', 'p', 's'};
    char userChoice;
    int numRounds = 0;
    int computerChoiceNum;
    char computerChoice;
    char roundWinner;
    int userPoints = 0;
    int computerPoints = 0;

    // Main game loop
    while (userPlay == 'y') {
        cout << "~~~~~\n\n~~~~~\n";
        ++numRounds;
        cout << "Round " << numRounds << "\n";
        cout << "Please enter your move: (r)ock, (p)aper, or (s)cissors.\n";
        cin >> userChoice;

        // Refuse to begin until the player input is correct
        while (userChoice != 'r' && userChoice != 'p' && userChoice != 's') {
            cout << "Please enter a valid choice: either (r)ock, (p)aper, or (s)cissors.\n";
            cin >> userChoice;
        }

        computerChoiceNum = randint(0, 2);
        computerChoice = computerOptions[computerChoiceNum];
        cout << "The computer played ";
        switch (computerChoice) {
            case 'r': cout << "rock.\n"; break;
            case 'p': cout << "paper.\n"; break;
            case 's': cout << "scissors.\n"; break;
        }
        roundWinner = getWinner(userChoice, computerChoice);

        // Output who won
        switch (roundWinner){
            case 'u': // User won
                cout << "You win this round! 1 Point to the human.\n";
                ++userPoints;
                break;
            case 'c': // Computer won
                cout << "You lose this round! 1 Point to the computer.\n";
                ++computerPoints;
                break;
            case 'n': // No one won
                cout << "No one wins! No points allocated.\n";
                break;
            default:
                break;
        }

        cout << "Do you want to play again? (y)es or (n)o. ";
        cin >> userPlay;
    }

    if (numRounds != 0) {
        cout << "~~~~~\n\n~~~~~\nYou got: " << userPoints << " points!\n";
        cout << "The computer got: " << computerPoints << " points!\n";
        cout << "The final winner is ... ";
        if (userPoints > computerPoints) {
            cout << "the human! Congratulations!\n";
        } else if (userPoints < computerPoints) {
            cout <<"the computer! Better luck next time.\n";
        } else if (userPoints == computerPoints) {
            cout << "no one! You both scored " << userPoints << " points.\n";
        }
    }

    cout << "Thanks for playing! Bye!\n";
    keep_window_open();
    return 0;
}
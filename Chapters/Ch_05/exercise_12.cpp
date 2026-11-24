// Program the game "Bulls and Cows".

#include "std_lib_facilities.h"


class badInput{};
class seedOutOfRange{};


vector<int> createRandomSet(int seed)
{
    vector<int> set;
    bool within = false;

    seed_randint(seed);
    while (set.size() != 4) {
        within = false;
        int nextNum = randint(0, 9);
        for (int setNum : set) {
            if (setNum == nextNum) {
                within = true;
            }
        }
        if (!within) {
            set.push_back(nextNum);
        }
    }
    return set;
}


int getNumCows(vector<int> answerSet, vector<int> userGuess)
// NOTE: A cow is a correct digit in the wrong position
{
    int numCows = 0;
    int userIndex;
    int answerIndex = 0;
    while (answerIndex < 4) {
        userIndex = 0;
        while (userIndex < 4) {
            if (userIndex != answerIndex) {
                if (userGuess[userIndex] == answerSet[answerIndex]) ++numCows;
            }
            ++userIndex;
        }
        ++answerIndex;
    }
    return numCows;
}


int getNumBulls(vector<int> answerSet, vector<int> userGuess)
{
    int numBulls = 0;
    for (int i = 0; i < 4; ++i)
    {
        if (answerSet[i] == userGuess[i]) ++numBulls;
    }

    return numBulls;
}


vector<int> convertToVector(string guessString)
{
    vector<int> guess;
    for (char num : guessString) {
        switch (num) {
            case '0':
                guess.push_back(0);
                break;
            case '1':
                guess.push_back(1);
                break;
            case '2':
                guess.push_back(2);
                break;
            case '3':
                guess.push_back(3);
                break;
            case '4':
                guess.push_back(4);
                break;
            case '5':
                guess.push_back(5);
                break;
            case '6':
                guess.push_back(6);
                break;
            case '7':
                guess.push_back(7);
                break;
            case '8':
                guess.push_back(8);
                break;
            case '9':
                guess.push_back(9);
                break;
            default:
                cerr << "Invalid guess.\n";
                throw badInput{};
                break;
        }
    }
    return guess;
}


int main()
try {
    int seed;
    vector<int> set;
    string userGuessString;    
    vector<int> guess;
    int numBulls = 0;
    int numCows = 0;
    int score = 100;

    cout << "Please enter a random integer between 0 and 2147483647 (this will be the seed).\n";
    cin >> seed;
    if (seed < 0) throw seedOutOfRange{};
    if (seed > 2147483647) throw seedOutOfRange{};

    set = createRandomSet(seed);

    while (numBulls != 4) {
        guess = {};
        cout << "Your guess: ";
        cin >> userGuessString;
        guess = convertToVector(userGuessString);
        if (numBulls < 4) {
            --score;
            numCows = getNumCows(set, guess);
            numBulls = getNumBulls(set, guess);
            cout << numCows << " cows and " << numBulls << " bulls.\n\n";
        }
    }
    cout << "\n\nYou won!\n";
    cout << "FINAL SCORE: " << score << ".\n";
    keep_window_open();
    return 0;
}
catch (badInput) {
    cerr << "\n";
    keep_window_open();
}
catch (seedOutOfRange) {
    cerr << "Inputted seed is out of the acceptable range of [0, 2147483647].\n";
    keep_window_open();
    return 0;
}
catch (...) {
    cerr << "Something went wrong.\n";
    keep_window_open();
    return 0;
}
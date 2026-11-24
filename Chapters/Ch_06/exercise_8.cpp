// Redo the "Bulls and Cows" game from exercise 12 in Chapter 5 to use four
// letters rather than four digits.

#include "std_lib_facilities.h"

class repeatedLetterInGuess{};
class seedOutOfRange{};
class guessSizeWrong{};


void getAndSetSeed() {
    double seedDouble;
    int seed;

    cout << "Please enter a random integer between 0 and 2147483647 (this will be the seed).\n";
    cin >> seedDouble;
    if (seedDouble < 0) throw seedOutOfRange{};
    if (seedDouble > 2147483647) throw seedOutOfRange{};
    seed = int(seedDouble);
    seed_randint(seed);
}


vector<char> createRandomSet()
{
    vector<char> alphabet = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k',
                             'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
                             'w', 'x', 'y', 'z'};
    vector<char> set;
    bool within = false;

    while (set.size() != 4) {
        within = false;
        int nextLetterNum = randint(0, 26);
        char nextLetter = alphabet[nextLetterNum];
        for (char setLetter : set) {
            if (setLetter == nextLetter) {
                within = true;
            }
        }
        if (!within) {
            set.push_back(nextLetter);
        }
    }
    return set;
}


vector<char> convertToVector(string guessString)
{
    vector<char> guess;
    for (char letter : guessString) {
        guess.push_back(letter);
    }

    for (int i = 0; i < guess.size(); ++i) {
        for (int j = 0; j < guess.size(); ++j) {
            if (i != j && guess[i] == guess[j]) throw repeatedLetterInGuess{};
        }
    }

    return guess;
}


int getNumCows(vector<char> answerSet, vector<char> userGuess)
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


int getNumBulls(vector<char> answerSet, vector<char> userGuess)
{
    int numBulls = 0;
    for (int i = 0; i < 4; ++i)
    {
        if (answerSet[i] == userGuess[i]) ++numBulls;
    }
    return numBulls;
}


void showResult(int result, vector<char> set, int score) {
    switch (result) {
        case 0:  // quit
            cout << "The answer was: ";
            for (char letter : set) cout << letter;
            cout << ".\n\nFINAL SCORE: 0.\n";
            keep_window_open();
        case 1:  // win
            cout << "You win! The answer was: ";
            for (char letter : set) cout << letter;
            cout << ".\n\nFINAL SCORE: " << score << ".\n";
            keep_window_open();
        }
}


void playGame()
{
    const vector<char> set = createRandomSet();
    string userGuessString;    
    int numBulls = 0;
    int numCows = 0;
    int score = 100;
    vector<char> guess;

    while (numBulls != 4) {
        guess = {};
        cout << "Your guess: ";
        cin >> userGuessString;
        if (userGuessString == "q") showResult(0, set, score);  // '0' for quit
        if (userGuessString.length() != 4) throw guessSizeWrong{};
        guess = convertToVector(userGuessString);
        --score;
        numCows = getNumCows(set, guess);
        numBulls = getNumBulls(set, guess);
        cout << numCows << " cows and " << numBulls << " bulls.\n\n";
    }
    showResult(1, set, score);  // '1' for success

}


int main()
try {
    getAndSetSeed();
    playGame();
    return 1;  // Success
}
catch (repeatedLetterInGuess) {
    cerr << "Your guess has a repeated letter.\n";
    keep_window_open();
    return 0;
}
catch (seedOutOfRange) {
    cerr << "Inputted seed is out of the acceptable range of [0, 2147483647].\n";
    keep_window_open();
    return 0;
}
catch (guessSizeWrong) {
    cerr << "Your guess did not consist of four letters.\n";
    keep_window_open();
    return 0;
}
catch (...) {
    cerr << "Something went wrong.\n";
    keep_window_open();
    return 0;
}
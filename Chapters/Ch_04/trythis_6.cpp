// Write a program that "bleeps" out words that you don't like; that is, you
// read in words using cin and print them again on cout. If a word is among a
// few you have defined, you write out BLEEP instead of that word. Start with
// one "disliked word" such as
// string disliked = "Broccoli";
// When that words, add a few more.

#include "std_lib_facilities.h"

int main()
{
    vector<string> disliked_words = {"broccoli", "spinach", "mushrooms", "tomatoes", "asparagus"};
    cout << "Please type your sentence below:\n";
    bool disliked = false;

    for (string word; cin >> word;) {
        disliked = false;
        
        // Check if the word is disliked
        for (string disliked_word : disliked_words) {
            if (word == disliked_word) {
                disliked = true;
            }
        }
        
        // Only print the word if it is not disliked
        if (disliked == true) {
            cout << "BLEEP ";
        } else {
            cout << word << " ";
        }
    }

    cout << "\n";
}
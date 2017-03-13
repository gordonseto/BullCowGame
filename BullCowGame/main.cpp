//
//  main.cpp
//  BullCowGame
//
//  Created by Gordon Seto on 2017-03-12.
//  Copyright © 2017 Gordon Seto. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

void PrintIntro();
void PlayGame();
string GetGuess();
bool AskToPlayAgain();

int main(){

    do {
        PrintIntro();
        PlayGame();
    } while(AskToPlayAgain());
    
    
    return 0;
}

void PrintIntro(){
    constexpr int WORD_LENGTH = 9;
    
    cout << "Welcome to Bulls and Cows, a fun word game!\n";
    cout << "Can you guess the " << WORD_LENGTH << " letter isogram I'm thinking of?\n";
    return;
}

void PlayGame(){
    constexpr int MAX_GUESSES = 5;
    
    for(int i; i < MAX_GUESSES; i++){
        string Guess = GetGuess();
        cout << "Your guess was: " << Guess << endl;
        cout << endl;
    }
    
}

string GetGuess(){
    cout << "Enter your guess: ";
    string Guess = "";
    getline(cin, Guess);
    return Guess;
}

bool AskToPlayAgain(){
    cout << "Do you want to play again?\n";
    string Response = "";
    getline(cin, Response);
    cout << endl;
    return (Response[0] == 'y') || (Response[0] == 'Y');
}

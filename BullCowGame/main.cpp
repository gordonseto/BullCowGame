//
//  main.cpp
//  BullCowGame
//
//  Created by Gordon Seto on 2017-03-12.
//  Copyright © 2017 Gordon Seto. All rights reserved.
//

#include <iostream>
#include <string>
#include "FBullCowGame.hpp"

void PrintIntro();
void PlayGame();
std::string GetGuess();
bool AskToPlayAgain();

FBullCowGame BCGame;

int main(){

    bool bPlayAgain = false;
    do {
        PrintIntro();
        PlayGame();
        bPlayAgain = AskToPlayAgain();
    } while(bPlayAgain);
    
    
    return 0;
}

void PrintIntro(){
    constexpr int WORD_LENGTH = 9;
    
    std::cout << "Welcome to Bulls and Cows, a fun word game!\n";
    std::cout << "Can you guess the " << WORD_LENGTH << " letter isogram I'm thinking of?\n";
    return;
}

void PlayGame(){
    BCGame.Reset();
    int MaxTries = BCGame.GetMaxTries();
    
    for(int i = 0; i < MaxTries; i++){
        std::string Guess = GetGuess(); // TODO: Make loop checking valid
        std::cout << "Your guess was: " << Guess << std::endl;
        std::cout << std::endl;
    }

    return;
}

std::string GetGuess(){
    std::cout << "Try " << BCGame.GetCurrentTry() << ". Enter your guess: ";
    std::string Guess = "";
    getline(std::cin, Guess);
    return Guess;
}

bool AskToPlayAgain(){
    std::cout << "Do you want to play again? (y/n) \n";
    std::string Response = "";
    std::getline(std::cin, Response);
    std::cout << std::endl;
    return (Response[0] == 'y') || (Response[0] == 'Y');
}

//
//  main.cpp
//  BullCowGame
//
//  Created by Gordon Seto on 2017-03-12.
//  Copyright © 2017 Gordon Seto. All rights reserved.
//

/*
 This is the console executable that makes use of the BullCow clas
 This acts as the view in a MVC pattern and is responsible for all
 user int32eraction. For game logic, see FBullCowGame class.
 */

#pragma once

#include <iostream>
#include <string>
#include "FBullCowGame.hpp"

using FText = std::string;
using int32 = int;

void Print32int32ro();
void PlayGame();
FText GetValidGuess();
bool AskToPlayAgain();
void PrintGameSummary();

FBullCowGame BCGame;

int main(){
    
    bool bPlayAgain = false;
    do {
        Print32int32ro();
        PlayGame();
        bPlayAgain = AskToPlayAgain();
    } while(bPlayAgain);
    
    
    return 0;
}

void Print32int32ro(){
    std::cout << "Welcome to Bulls and Cows, a fun word game!\n";
    std::cout << "Can you guess the " << BCGame.GetHiddenWordLength() << " letter isogram I'm thinking of?\n";
    return;
}

void PlayGame(){
    BCGame.Reset();
    int32 MaxTries = BCGame.GetMaxTries();
    
    while(!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries) {
        FText Guess = GetValidGuess(); 
        
        FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);
        
        std::cout << "Bulls = " << BullCowCount.Bulls;
        std::cout << ". Cows = " << BullCowCount.Cows << std::endl;
    }
    
    PrintGameSummary();
    
    return;
}

// loop continously until get valid guess
FText GetValidGuess(){
    
    EGuessStatus Status = EGuessStatus::Invalid_Status;
    
    FText Guess = "";
    
    do {
        std::cout << "Try " << BCGame.GetCurrentTry() << ". Enter your guess: ";
        getline(std::cin, Guess);
        
        Status = BCGame.CheckGuessValidity(Guess);
        
        switch(Status) {
            case EGuessStatus::Wrong_Length:
                std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word.\n";
                break;
            case EGuessStatus::Not_Isogram:
                std::cout << "Please enter an isogram.\n";
                break;
            case EGuessStatus::Not_Lowercase:
                std::cout << "Please enter a word with all lowercases.\n";
                break;
            default:
                break;
        }
        std::cout << std::endl;
    } while(Status != EGuessStatus::OK);
    
    return Guess;
}

bool AskToPlayAgain(){
    std::cout << "Do you want to play again? (y/n) \n";
    FText Response = "";
    std::getline(std::cin, Response);
    std::cout << std::endl;
    return (Response[0] == 'y') || (Response[0] == 'Y');
}

void PrintGameSummary(){
    if (BCGame.IsGameWon()){
        std::cout << "YOU HAVE WON!\n\n";
    } else {
        std::cout << "You Lose!\n\n";
    }
    return;
}

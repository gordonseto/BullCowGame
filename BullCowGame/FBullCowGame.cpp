//
//  FBullCowGame.cpp
//  BullCowGame
//
//  Created by Gordon Seto on 2017-03-13.
//  Copyright © 2017 Gordon Seto. All rights reserved.
//
#pragma once

#include "FBullCowGame.hpp"
#include <map>
#define TMap std::map

FBullCowGame::FBullCowGame(){
    Reset();
}

int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return (int32)MyHiddenWord.length(); }
bool FBullCowGame::IsGameWon() const { return bHasWon; }

int32 FBullCowGame::GetMaxTries() const {
    TMap<int32, int32> WordLengthToMaxTries {{3, 5}, {4, 5}, {5, 5}, {6, 5}};
    return WordLengthToMaxTries[(int32)MyHiddenWord.length()];
}

void FBullCowGame::Reset(){
    const FString HIDDEN_WORD = "planet";
    
    MyCurrentTry = 1;
    MyHiddenWord = HIDDEN_WORD;
    bHasWon = false;
    
    return;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const {
    if (!IsIsogram(Guess)){
        return EGuessStatus::Not_Isogram;
    } else if (Guess.length() != GetHiddenWordLength()){
        return EGuessStatus::Wrong_Length;
    } else if (!IsLowercase(Guess)){
        return EGuessStatus::Not_Lowercase;
    }
    return EGuessStatus::OK;
}

bool FBullCowGame::IsIsogram(FString Word) const {
    TMap<char, bool> Map;
    
    for (auto Letter : Word){
        Letter = tolower(Letter);
        
        if (Map[Letter]) {
            return false;
        } else {
            Map[Letter] = true;
        }
    }
    
    return true;
}

bool FBullCowGame::IsLowercase(FString Word) const {
    for (auto Letter : Word){
        if (!islower(Letter)) {
            return false;
        }
    }
    return true;
}

//receives a VALID guess, increments turn and returns count
FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess){
    
    MyCurrentTry++;
    FBullCowCount BullCowCount;
    
    int32 WordLength = GetHiddenWordLength(); // assuming same length as guess
    
    for (int32 i = 0; i < WordLength; i++){
        for (int32 j = 0; j < WordLength; j++){
            if (Guess[j] == MyHiddenWord[i]) {
                if (i == j){
                    BullCowCount.Bulls++;
                } else {
                    BullCowCount.Cows++;
                }
            }
        }
    }
    if (BullCowCount.Bulls == WordLength) {
        bHasWon = true;
    }
    
    return BullCowCount;
}

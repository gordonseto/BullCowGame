//
//  FBullCowGame.cpp
//  BullCowGame
//
//  Created by Gordon Seto on 2017-03-13.
//  Copyright © 2017 Gordon Seto. All rights reserved.
//

#include "FBullCowGame.hpp"

FBullCowGame::FBullCowGame(){
    Reset();
}

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return (int32)MyHiddenWord.length(); }

void FBullCowGame::Reset(){
    constexpr int32 MAX_TRIES = 8;
    const FString HIDDEN_WORD = "planet";
    
    MyMaxTries = MAX_TRIES;
    MyCurrentTry = 1;
    MyHiddenWord = HIDDEN_WORD;
    
    return;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const {
    if (Guess.length() != GetHiddenWordLength()){
        return EGuessStatus::Wrong_Length;
    }
    return EGuessStatus::OK;
}

bool FBullCowGame::IsGameWon() const {
    return false;
}

//receives a VALID guess, increments turn and returns count
FBullCowCount FBullCowGame::SubmitGuess(FString Guess){
    
    MyCurrentTry++;
    FBullCowCount FBullCowCount;
    
    int32 count = GetHiddenWordLength();
    
    for (int32 i = 0; i < count; i++){
        for (int32 j = 0; j < count; j++){
            if (Guess[i] == MyHiddenWord[j]) {
                if (i == j){
                    FBullCowCount.Bulls++;
                } else {
                    FBullCowCount.Cows++;
                }
            }
        }
    }
    
    return FBullCowCount;
}

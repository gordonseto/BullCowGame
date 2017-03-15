//
//  FBullCowGame.hpp
//  BullCowGame
//
//  Created by Gordon Seto on 2017-03-13.
//  Copyright © 2017 Gordon Seto. All rights reserved.
//

#pragma once
#include <string>

using FString = std::string;
using int32 = int;

struct FBullCowCount {
    int32 Bulls = 0;
    int32 Cows = 0;
};

enum class EGuessStatus {
    Invalid_Status,
    OK,
    Not_Isogram,
    Wrong_Length,
    Not_Lowercase
};

class FBullCowGame {
public:
    FBullCowGame();
    
    int32 GetMaxTries() const;
    int32 GetCurrentTry() const;
    int32 GetHiddenWordLength() const;
    bool IsGameWon() const;
    EGuessStatus CheckGuessValidity(FString) const;
    
    void Reset();
    FBullCowCount SubmitValidGuess(FString);
    
private:
    int32 MyCurrentTry;
    FString MyHiddenWord;
    bool bHasWon;
    
    bool IsIsogram(FString) const;
    bool IsLowercase(FString) const;
};

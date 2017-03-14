//
//  FBullCowGame.hpp
//  BullCowGame
//
//  Created by Gordon Seto on 2017-03-13.
//  Copyright © 2017 Gordon Seto. All rights reserved.
//

#pragma once
#include <string>

class FBullCowGame {
public:
    FBullCowGame();
    
    int GetMaxTries() const;
    int GetCurrentTry() const;
    bool IsGameWon() const;
    
    void Reset();
    bool CheckGuessValidity(std::string);
    
private:
    int MyCurrentTry;
    int MyMaxTries;
};

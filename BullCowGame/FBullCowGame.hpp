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
    void Reset();
    int GetMaxTries();
    int GetCurrentTry();
    bool CheckGuessValidity(std::string);
    bool IsGameWon();
    
private:
    int MyCurrentTry;
    int MyMaxTries;
};

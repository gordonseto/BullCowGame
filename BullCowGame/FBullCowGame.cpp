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

int FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }

void FBullCowGame::Reset(){
    constexpr int MAX_TRIES = 8;
    
    MyMaxTries = MAX_TRIES;
    MyCurrentTry = 1;
    return;
}

bool FBullCowGame::CheckGuessValidity(std::string){
    return false;
}

bool FBullCowGame::IsGameWon() const {
    return false;
}


//
//  FBullCowGame.hpp
//  Bull Cow Game Overview
//
//  Created by rommel santiago on 11/15/17.
//  Copyright © 2017 Rommel Fowler. All rights reserved.
//

#ifndef FBullCowGame_hpp
#define FBullCowGame_hpp
#include <string>

class FBullCowGame {
public:
    FBullCowGame(); // constructor
    
    int GetMaxTries() const;
    int GetCurrentTry() const;
    bool IsGameWon() const;
    
    void Reset(); // TODO make a more rich return value.
    bool CheckGuessValidity(std::string); // TODO make a more rich return value.
    
    
    
    // ^^ Please try and ignore this and focus on the interface above ^^
private:
    // see constructor for initialisation
    int MyCurrentTry;
    int MyMaxTries;
};

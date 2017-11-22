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


#include <stdio.h>

#endif /* FBullCowGame_hpp */


class FBullCowGame {
public:
    void Reset();   //@TODO - make a more rich return val
    int GetMaxTries();
    int GetCurrentTry();
    bool IsgameWon();
    bool CheckGuessValidity(std::string); // TODO make more rich return val
    
    
    
// IGNORE FOR NOW
private:
    int MyCurrentTry;
    int MyMaxTries;
};

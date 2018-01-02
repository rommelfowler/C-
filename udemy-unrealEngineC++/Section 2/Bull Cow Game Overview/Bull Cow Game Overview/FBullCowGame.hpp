//
//  FBullCowGame.hpp
//  Bull Cow Game Overview
//
//  Created by rommel santiago on 11/15/17.
//  Copyright © 2017 Rommel Fowler. All rights reserved.
//

#define FBullCowGame_cpp
#include <string>

using int32 = int;
using FString = std::string;

// Struct is just like class except that it's public and NOT private
// All values initialized to 0
struct BullCowCount {
    int32 Bulls = 0;
    int32 Cows = 0;
};

class FBullCowGame {
public:
    FBullCowGame(); // constructor - Take name of the file and make it a method.
    
    int32 GetMaxTries() const;
    int32 GetCurrentTry() const;
    bool IsGameWon() const;
    
    void Reset(); // TODO make a more rich return value.
    bool CheckGuessValidity(FString); // TODO make a more rich return value.
    BullCowCount SubmitGuess(FString);
    
    // ^^ Please try and ignore this and focus on the interface above ^^
private:
    // see constructor for initialisation
    int32 MyCurrentTry;
    int32 MyMaxTries;
    FString MyHiddenWord;
};

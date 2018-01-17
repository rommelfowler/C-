//
//  FBullCowGame.cpp
//  Bull Cow Game Overview
//
//  Created by rommel santiago on 11/15/17.
//  Copyright © 2017 Rommel Fowler. All rights reserved.
//

#include "FBullCowGame.hpp"

using int32 = int;

//Constructor   
FBullCowGame::FBullCowGame() { Reset(); }

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries;}
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }


void FBullCowGame::Reset()
{
    constexpr int32 MAX_TRIES = 8;
    const FString HIDDEN_WORD = "planet";
    MyMaxTries = MAX_TRIES;
    MyHiddenWord = HIDDEN_WORD;
    MyCurrentTry = 1;
    return;
}
bool FBullCowGame::IsGameWon() const
{
    return false;
}
/*
 NOTES: Make sure to always place a handle when calling something inside.
 ERROR-CHECKING
 */
EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
    
    if(false) //If the guess isn't an isogram,
    {
        return EGuessStatus::Not_Isogram;
    }
    else if (false)  //if the guess isnt all lowercase
    {
        return EGuessStatus::Not_Lowercase;
    }
    else if (Guess.length() != GetHiddenWordLength()) // if the guess length is wrong
    {
        return EGuessStatus::Wrong_legnth;
    }
    else
    {
        return EGuessStatus::Ok;
    }
    return EGuessStatus::Ok;

   
}
int32 FBullCowGame::GetHiddenWordLength() const
{
    return MyHiddenWord.length();
}


// receives a VALID guess, incriment turn, and returns count
BullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
    MyCurrentTry++;
    BullCowCount BullCowCount;
    // loop through all letters in the hidden word
    int32 WordLength = MyHiddenWord.length();
    
    for (int32 HWChar = 0; HWChar < WordLength; ++HWChar) {
        // compare lettesr against the guess
        for (int32 GChar = 0; GChar< WordLength; ++GChar) {
            // if they match then
            if (Guess[GChar] == MyHiddenWord[HWChar])
            {
                // incriment bulls if theyre in the same place
                if(HWChar== GChar) {
                    BullCowCount.Cows++;
                } else {
                    BullCowCount.Bulls++;
                }
            }
           
        }
        
     }
    return BullCowCount;
}









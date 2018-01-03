//
//  FBullCowGame.cpp
//  Bull Cow Game Overview
//
//  Created by rommel santiago on 11/15/17.
//  Copyright © 2017 Rommel Fowler. All rights reserved.
//

#include "FBullCowGame.hpp"

using int32 = int;

//Constructor   
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
bool FBullCowGame::IsGameWon() const { return false; }
bool FBullCowGame::CheckGuessValidity(std::string) const {  return false; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }


// receives a VALID guess, incriment turn, and returns count
BullCowCount FBullCowGame::SubmitGuess(FString Guess) {
    // incriment the turn nunber
    MyCurrentTry++;
    
    // setup a return var
    BullCowCount BullCowCount;
    int32 HiddenWordLength = MyHiddenWord.length();
    // loop through all letters in the guess
    for (int32 HWChar = 0; HWChar < HiddenWordLength; ++HWChar) {
        // compare lettesr against the hidden word
        for (int32 GChar = 0; GChar<HiddenWordLength; ++GChar) {
            // if they match then
            if (Guess[GChar] == MyHiddenWord[HWChar])
            // incriment bulls if theyre in the same place
                if(HWChar== GChar) {
                    BullCowCount.Cows++; // incriment cows

                } else {
                    BullCowCount.Bulls++; // incriment bulls

                }
        }
        
     }
    return BullCowCount;
}









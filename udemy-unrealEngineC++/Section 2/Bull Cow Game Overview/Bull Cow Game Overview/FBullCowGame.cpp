//
//  FBullCowGame.cpp
//  Bull Cow Game Overview
//
//  Created by rommel santiago on 11/15/17.
//  Copyright © 2017 Rommel Fowler. All rights reserved.
//

#include "FBullCowGame.hpp"
#include <map> // Make Map library available
#define TMap std::map

using int32 = int;

//Constructor   
FBullCowGame::FBullCowGame() { Reset(); } //default


int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
bool FBullCowGame::IsGameWon() const { return bGameIsWon; }

int32 FBullCowGame::GetMaxTries() const {
    TMap<int32, int32> WordLengthToMaxTries {{3,5}, {4,5}, {5,5}, {6,5} };
    return WordLengthToMaxTries[MyHiddenWord.length()];
}

void FBullCowGame::Reset()
{
    constexpr int32 MAX_TRIES = 3; //DONT NEED
    const FString HIDDEN_WORD = "planet";
    MyMaxTries = MAX_TRIES;//DONT NEED
    MyHiddenWord = HIDDEN_WORD;
    MyCurrentTry = false;
    return;
}

/*
 NOTES: Make sure to always place a handle when calling something inside.
 ERROR-CHECKING
 */
EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
    /*
     Avoid implicit dependencies
     Implicit: suggested though not directly expressed.
     Dependent: reliant on something else
     NOTE: An implicit dependency is when it's nto completely clear that one thing depends on another.
        For example, the order of checks in CheckGuessValidity().
     */
    if(!IsIsogram(Guess))
    {
        return EGuessStatus::Not_Isogram;
    }
    else if (!IsLowerase(Guess))  //if the guess isnt all lowercase
    {
        return EGuessStatus::Not_Lowercase; //TODO write function
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
    if (BullCowCount.Bulls == WordLength) {
        bGameIsWon = true;
    } else {
        bGameIsWon = false;
    }
    return BullCowCount;
}

bool FBullCowGame::IsIsogram(FString Word) const
{
    // treat 0 and 1 letter words as isogram
    if (Word.length() <= 1) {
        return true;
    }
    TMap<char,bool> LetterSeen; // setup our map
    for (auto Letter : Word) // for all LETTERS of the WORD
    {
        // loop through all the letters of the word
        Letter = tolower(Letter); // handle mixed case
        
        // if the letter is in the map
        if (LetterSeen[Letter]) {
            return false; // We do not have isogram
        } else {
            // add the letter to the map as seen
            LetterSeen[Letter] = true;
        }
    }
    return true; // for examples in cases where /0 is entered
}

bool FBullCowGame::IsLowerase(FString Word) const {
    for (auto Letter : Word)
    {
        if(!islower(Letter)) // if not a lowercase letter
            //then return false
            return false;
    }
    return true;
}











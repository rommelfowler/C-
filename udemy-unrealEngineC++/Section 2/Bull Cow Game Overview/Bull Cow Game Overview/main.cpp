//
//  main.cpp
//  Bull Cow Game Overview
//
//  Created by rommel santiago on 11/8/17.
//  Copyright © 2017 Rommel Fowler. All rights reserved.
//  @package - Bull Cow Game. Guess the correct number out of 5
//
/*
 This is the console executable that makes use of the BullCow class.
 This acts as the view in the MVC pattern, and is responsible for all user
 interaction. For game logic see the FBullCowGame class.
 */
#include <iostream>
#include <string>
#include "FBullCowGame.hpp"


using FText = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
FText GetValidGuess();
bool AskToPlayAgain();
void PrintGameSummary();

FBullCowGame BCGame; // instantiate a new game

// the entry point for our application
int main()
{
    bool bPlayAgain = false;
    do {
        PrintIntro();
        PlayGame();
        bPlayAgain = AskToPlayAgain();
    }
    while (bPlayAgain);
    
    return 0; // exit the application
}


// introduce the game
void PrintIntro()
{
    std::cout << "Welcome to Bulls and Cows, a fun word game.\n";
    std::cout << "Can you guess the " << BCGame.GetHiddenWordLength();
    std::cout << " letter isogram I'm thinking of?\n";
    std::cout << std::endl;
    return;
}

void PlayGame()
{
    BCGame.Reset();
    int32 MaxTries = BCGame.GetMaxTries();
    
    // loop for the number of turns asking for guesses
    // loop asking for guesses while the game is not won and there are still tries remaining
    while (!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries) {
        FText Guess = GetValidGuess();
     
        // submit valid guess to the game
        BullCowCount BullCowCount = BCGame.SubmitGuess(Guess);
        
        // print number of balls and cows
        std::cout << "Bulls + " << BullCowCount.Bulls;
        std::cout << ". Cows + " << BullCowCount.Cows << "\n\n";
     
    }
    // TODO add a game summary
    PrintGameSummary();
    return;
}

// loop continually until the user gives a valid guess
FText GetValidGuess()
{
    FText Guess = "";
    EGuessStatus Status = EGuessStatus::Invalid_Status;
    do {
        // get a guess from the player
        int32 CurrentTry = BCGame.GetCurrentTry();
        std::cout << "Try " << CurrentTry << " of " << BCGame.GetMaxTries();
        std::cout << ". Enter your guess: ";
        std::getline(std::cin, Guess);
        Status = BCGame.CheckGuessValidity(Guess); // This is the debugger.
        /*
         Switch - check guess validity
         */
        switch (Status)
        {
            case EGuessStatus::Wrong_legnth:
                std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word. \n\n";
                break;
            case EGuessStatus::Not_Isogram:
                std::cout << "Please enter a word without repeating letters. \n\n";
                break;
            case EGuessStatus::Not_Lowercase:
                std::cout << "Please enter all lowercase letters. \n\n";
                break;
            default: //assume the guess is valid
                break;
        }
        std::cout << std::endl;
    } while (Status == EGuessStatus::Ok);
    return Guess;
}

bool AskToPlayAgain()
{
    std::cout << "Do you want to play again with same hidden word (y/n)? ";
    FText Response = "";
    std::getline(std::cin, Response);
    return (Response[0] == 'y') || (Response[0] == 'Y');

}
void PrintGameSummary()
{
    if (BCGame.IsGameWon())
    {
        std::cout << "WELL DONE _ YOU WIN! \n";
    }
    else
    {
        std::cout << "Better luck next time!\n";
    }
}

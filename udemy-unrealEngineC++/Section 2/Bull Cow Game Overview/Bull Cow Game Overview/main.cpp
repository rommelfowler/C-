//
//  main.cpp
//  Bull Cow Game Overview
//
//  Created by rommel santiago on 11/8/17.
//  Copyright © 2017 Rommel Fowler. All rights reserved.
//  @package - Bull Cow Game. Guess the correct number out of 5
//

#include <iostream>
#include <string>

// using namespace std; TO DANGEROUS!! 

//FUNCTIONS
void PrintIntro();
void PlayGame();
bool AskToPlayAgain();
std::string GetGuess();

//To avoid using magic numbers, we use a const and specify that number.
//@package constexpr - means that it can be avaluated right now.
constexpr int WORD_LEGNTH = 5;

//Entry point for app.
int main()
{
    bool playAgain = false;
    do {
        PrintIntro();                       //Print Intro void function
        PlayGame();                         //For Loop number of guesses
        playAgain = AskToPlayAgain();           //Bool number of guesses
        std::cout << std::endl;
    } while (playAgain);
    
    return 0;
}

void PrintIntro()
{
    //========================
    // Introduce the game
    //========================
    std::cout << "Welcome to Bulls and Cows, a fun word game.\n";
    std::cout << "Can you guess the " << WORD_LEGNTH << " letter isogram I'm thinking of?" << std::endl;
    std::cout << std::endl;
}

void PlayGame()
{
    for(int i = 0; i < WORD_LEGNTH; ++i){
        std::string Guess = GetGuess();

        std::cout << "Your guess was " << Guess << std::endl;
        std::cout << std::endl;
    }
}

std::string GetGuess()
{
    std::string Guess = "";

    //Get a guess from the player
    std::cout << "Enter your guess: ";
    //========================
    //What happens when a user uses two words rather than one common - input? Use getline()
    //@package - DO NOT USE - std::cin >> Guess;
    //========================
    getline(std::cin, Guess);
    
    return Guess;
}
bool AskToPlayAgain()
{
    std::string Response = "";
    
    std::cout << "Do you want to play again?";
    getline(std::cin, Response);
    return (Response[0] == 'y') || (Response[0] == 'Y');
    
}

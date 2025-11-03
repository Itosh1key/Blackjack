#include "Deck.h"
#include "ErrorHandling.h"
#include "Random.h" // for Random::mt
#include <array>
#include <iostream>
#include <string>
#include <vector>

namespace AboutProgram {
    std::string name { "Blackjack" };
    std::string version { "1.0.0" };
    std::string author { "Itosh1key" };

    void print()
    {
        std::cout << name << " v" << version << '\n'
                  << "By " << author << "\n\n";
    }
} // namespace AboutProgram

namespace Settings {
    constexpr int bustThreshold { 21 };
    constexpr int dealerDrawThreshold { 17 };
} // namespace Settings

struct Player
{
    int score{};
};

bool playerWantsHit()
{
    while (true) {
        std::cout << "(h) to hit, or (s) to stand: ";

        char input {};
        std::cin >> input;

        if (ErrorHandling::clearFailedExtraction()) {
            std::cout << "That is an invalid input.  Try again: ";
            continue;
        }

        switch (input) {
        case 'h':
            return true;
        case 's':
            return false;
        }
    }
}

// Returns true if the player went bust. False otherwise.
bool playerTurn(Deck& deck, Player& player)
{
    while (player.score < Settings::bustThreshold && playerWantsHit()) {
        Deck::Card card { deck.dealCard() };
        player.score += card.value();

        std::cout << "You were dealt " << card
                  << "  You now have: " << player.score << '\n';
    }

    if (player.score > Settings::bustThreshold) {
        std::cout << "You went bust!\n";
        return true;
    }

    return false;
}

// Returns true if the dealer went bust. False otherwise.
bool dealerTurn(Deck& deck, Player& dealer)
{
    // Dealer's turn
    while (dealer.score < Settings::dealerDrawThreshold) {
        Deck::Card card { deck.dealCard() };
        dealer.score += card.value();
        
        std::cout << "The dealer flips a " << card 
                  << ".  They now have: "  << dealer.score << '\n';
    }
    
    if (dealer.score > Settings::bustThreshold)
    {
        std::cout<<"The dealer went bust!\n";
        return true;
    }

    return false;
}

bool playBlackJack()
{
    Deck deck {};
    deck.shuffle(); // Shuffle the deck

    Player dealer { deck.dealCard().value() };
    Player player { deck.dealCard().value() + deck.dealCard().value() };

    std::cout << "The dealer is showing: " << dealer.score << '\n'
              << "You have score: " << player.score << '\n';

    if (playerTurn(deck, player))
        return false;
        
    if (dealerTurn(deck, dealer))
        return true;

    return (player.score > dealer.score);
}


int main()
{
    AboutProgram::print();

    if (playBlackJack())
        std::cout << "You win!\n";
    else
        std::cout << "You lose!\n";
}
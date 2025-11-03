#ifndef DECK_H
#define DECK_H

#include <iostream>
#include <array>

class Deck {
public:
    struct Card {
        enum Ranks {
            rank_ace,
            rank_2,
            rank_3,
            rank_4,
            rank_5,
            rank_6,
            rank_7,
            rank_8,
            rank_9,
            rank_10,
            rank_jack,
            rank_queen,
            rank_king,
            max_ranks,
        };

        enum Suits {
            suit_club,
            suit_diamond,
            suit_heart,
            suit_spade,
            max_suits,
        };

        Ranks rank {};
        Suits suit {};

        static constexpr std::array allRanks {
            rank_ace, rank_2, rank_3, rank_4, rank_5, rank_6, rank_7,
            rank_8, rank_9, rank_10, rank_jack, rank_queen, rank_king
        };
        static constexpr std::array allSuits {
            suit_club, suit_diamond, suit_heart, suit_spade
        };

        static_assert(std::size(allRanks) == max_ranks,
            "Card::allRanks: array length mismatch");
        static_assert(std::size(allSuits) == max_suits,
            "Card::allSuits: array length mismatch");

        friend std::ostream& operator<<(std::ostream& out, const Deck::Card& card);

        int value()
        {
            static constexpr std::array rankValues {
                11, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10
            };

            return rankValues[rank];
        }
    };

    Deck();

    void shuffle();
    Deck::Card dealCard();

private:
    std::array<Card, 52> m_cards {};
    std::size_t m_nextCardIndex { 0 };
};

std::ostream& operator<<(std::ostream& out, const Deck::Card& card);

#endif
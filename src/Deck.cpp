#include "Deck.h"
#include "Random.h"
#include <algorithm>
#include <cassert>

Deck::Deck()
{
    std::size_t count { 0 };
    for (const auto& suit : Card::allSuits)
        for (const auto& rank : Card::allRanks)
            m_cards[count++] = Card { rank, suit };
}

void Deck::shuffle()
{
    std::shuffle(m_cards.begin(), m_cards.end(), Random::mt);
    m_nextCardIndex = 0;
}

Deck::Card Deck::dealCard()
{
    assert(m_nextCardIndex != 52 && "Deck::dealCard ran out of cards");
    return m_cards[m_nextCardIndex++];
}

// Teach operator<< how to print Card
std::ostream& operator<<(std::ostream& out, const Deck::Card& card)
{
    static constexpr std::array ranks {
        'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'
    };
    static constexpr std::array suits { 'C', 'D', 'H', 'S' };

    out << ranks[card.rank] << suits[card.suit];
    return out;
}
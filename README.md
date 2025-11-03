# Blackjack
Implementation of the card game, [Blackjack](https://en.wikipedia.org/wiki/Blackjack)!

This is a simplified version of blackjack. We won't keep track of the specific cards dealt to the player or the dealer. Instead, we’ll only track the sum of the card values for the player and the dealer.

**RULES**
- The dealer gets one card to start.
- The player gets two cards to start.
- The player goes first.
- A player can repeatedly “hit” or “stand”.
- If the player “stands”, their turn is over, and their score is calculated based on the cards they have been dealt.
- If the player “hits”, they get another card and the value of that card is added to their total score.
- For simplicity, we’ll count the Ace as an 11 here.
- If the player goes over a score of 21, they bust and lose immediately.
- When the player is done, it is the dealer’s turn.
- The dealer repeatedly draws until they reach a score of 17 or more, at which point they must stop drawing.
- If the dealer goes over a score of 21, they bust and the player wins immediately.
- Otherwise, if the player has a higher score than the dealer, the player wins. Otherwise, the player loses (ties are considered as dealer wins for simplicity).
  
**COMMANDS**

Enter:
- h - to hit
- s - to stand

**EXAMPLE OUTPUT**
```
Blackjack v1.0.0
By Itosh1key

The dealer is showing: 2
You have score: 17
(h) to hit, or (s) to stand: h
You were dealt 3S  You now have: 20
(h) to hit, or (s) to stand: s
The dealer flips a KC.  They now have: 12
The dealer flips a 5H.  They now have: 17
You win!
```

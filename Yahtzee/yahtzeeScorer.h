//
//  yahtzeeScorer.h
//  Yahtzee
//
//  Created by Emily Eaton on 2/27/18.
//

#ifndef yahtzeeScorer_h
#define yahtzeeScorer_h

#include <stdbool.h>
#include "yahtzeeTypes.h"

// Function prototypes for routines callable by other modules
bool IsThreeOfAKind(const FiveDiceType * dice);
bool IsFourOfAKind(const FiveDiceType * dice);
bool IsFullHouse(const FiveDiceType * dice);
bool IsSmallStraight(const FiveDiceType * dice);
bool IsLargeStraight(const FiveDiceType * dice);
bool IsYahtzee(const FiveDiceType * dice);
unsigned int ScoreAsTopSection(const FiveDiceType * dice, unsigned int rank);
unsigned int ScoreAsThreeOfAKind(const FiveDiceType * dice);
unsigned int ScoreAsFourOfAKind(const FiveDiceType * dice);
unsigned int ScoreAsFullHouse(const FiveDiceType * dice);
unsigned int ScoreAsSmallStraight(const FiveDiceType * dice);
unsigned int ScoreAsLargeStraight(const FiveDiceType * dice);
unsigned int ScoreAsYahtzee(const FiveDiceType * dice);
unsigned int ScoreAsChance(const FiveDiceType * dice);

#endif /* yahtzeeScorer_h */

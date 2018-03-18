//
//  yahtzeeScorer.h
//  Yahtzee
//
//  Created by Emily Eaton on 2/27/18.
//

#ifndef yahtzeeScorer_h
#define yahtzeeScorer_h

#include "yahtzeeTypes.h"

// Function prototypes for routines callable by other modules
unsigned int ScoreAsTopSection(const FiveDiceType* dice, unsigned int rank);
unsigned int ScoreAsThreeOfAKind(const FiveDiceType* dice);
unsigned int ScoreAsFourOfAKind(const FiveDiceType* dice);
unsigned int ScoreAsFullHouse(const FiveDiceType* dice);
unsigned int ScoreAsSmallStraight(const FiveDiceType* dice);
unsigned int ScoreAsLargeStraight(const FiveDiceType* dice);
unsigned int ScoreAsYahtzee(const FiveDiceType* dice);
unsigned int ScoreAsChance(const FiveDiceType* dice);


#endif /* yahtzeeScorer_h */

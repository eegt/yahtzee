//
//  yahtzee.h
//  Yahtzee
//
//  Created by Emily Eaton on 2/22/18.
//

#ifndef yahtzee_h
#define yahtzee_h

#include "yahtzeeTypes.h"

// Function prototypes for routines callable by other modules
void PrintDiceValues(const FiveDiceType turns[], unsigned int nTurns);
void PrintResults(const ScoreResultsType * results, int playerNum);
void InitializeGameResults(ScoreResultsType * results);

#endif /* yahtzee_h */

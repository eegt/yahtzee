//
//  yahtzeeScoreChecker.h
//
//
//  Created by Emily Eaton on 3/14/18.
//  Copyright © 2018 Emily Eaton. All rights reserved.
//

#ifndef yahtzeeScoreChecker_h
#define yahtzeeScoreChecker_h

#include "yahtzeeTypes.h"

// Error codes for score checking
typedef enum scoringError
{
   ERR_NONE = 0,
   ERR_ONES,
   ERR_TWOS,
   ERR_THREES,
   ERR_FOURS,
   ERR_FIVES,
   ERR_SIXES,
   ERR_THREEOFAKIND,
   ERR_FOUROFAKIND,
   ERR_FULLHOUSE,
   ERR_SMALLSTRAIGHT,
   ERR_LARGESTRAIGHT,
   ERR_YAHTZEE,
   ERR_CHANCE,
   ERR_BONUS,
   ERR_UPPERTOTAL,
   ERR_LOWERTOTAL,
   ERR_TOTAL
} ScoringErrorType;

// Function prototypes for routines callable by other modules
ScoringErrorType ScoreResultsAreValid(const ScoreResultsType * results);


#endif /* yahtzeeScoreChecker_h */

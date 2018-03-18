//
//  yahtzeeScoreChecker.c
//  Yahtzee
//
//  Created by Emily Eaton on 3/14/18.
//  Copyright © 2018 Emily Eaton. All rights reserved.
//

#include "yahtzeeScoreChecker.h"
#include "yahtzeeTypes.h"


// Function prototypes for private routines
ScoringErrorType OnesIsValid(unsigned int onesVal);
ScoringErrorType TwosIsValid(unsigned int twosVal);
ScoringErrorType ThreesIsValid(unsigned int threesVal);
ScoringErrorType FoursIsValid(unsigned int foursVal);
ScoringErrorType FivesIsValid(unsigned int fivesVal);
ScoringErrorType SixesIsValid(unsigned int sixesVal);
ScoringErrorType ThreeOfAKindIsValid(unsigned int threeOfAKindVal);
ScoringErrorType FourOfAKindIsValid(unsigned int fourOfAKindVal);
ScoringErrorType FullHouseIsValid(unsigned int fullHouseVal);
ScoringErrorType SmallStraightIsValid(unsigned int smallStraightVal);
ScoringErrorType LargeStraightIsValid(unsigned int largeStraightVal);
ScoringErrorType YahtzeeIsValid(unsigned int yahtzeeVal);
ScoringErrorType ChanceIsValid(unsigned int chanceVal);
ScoringErrorType TotalsAreValid(const ScoreResultsType * results);


//--------------------------------------------------------------------------
//--------------------------------------------------------------------------

// ScoreResultsAreValid
// Input: a Yahtzee results structure (scores and totals)
// Returns: an error code indicating result validity
//
// Examples:
//   If no errors are found, returns ERR_NONE.
//   If there's a 7 in "threes", that's invalid and will return ERR_THREES.
//   If there's a 40 in "yahtzee", that's invalid and will return ERR_YAHTZEE.
//   If upper total is 60 but bonus is 35, will return ERR_BONUS.
//
// Note: Stops checking as soon as the first error is found, so it will
//   only report one error regardless of how many are present.
ScoringErrorType ScoreResultsAreValid(const ScoreResultsType * results)
{
   ScoringErrorType err = ERR_NONE;

   err = (ERR_NONE == err) ? OnesIsValid(results->scores.ones) : err;
   err = (ERR_NONE == err) ? TwosIsValid(results->scores.twos) : err;
   err = (ERR_NONE == err) ? ThreesIsValid(results->scores.threes) : err;
   err = (ERR_NONE == err) ? FoursIsValid(results->scores.fours) : err;
   err = (ERR_NONE == err) ? FivesIsValid(results->scores.fives) : err;
   err = (ERR_NONE == err) ? SixesIsValid(results->scores.sixes) : err;

   err = (ERR_NONE == err) ? ThreeOfAKindIsValid(results->scores.threeOfAKind) : err;
   err = (ERR_NONE == err) ? FourOfAKindIsValid(results->scores.fourOfAKind) : err;
   err = (ERR_NONE == err) ? FullHouseIsValid(results->scores.fullHouse) : err;
   err = (ERR_NONE == err) ? SmallStraightIsValid(results->scores.smallStraight) : err;
   err = (ERR_NONE == err) ? LargeStraightIsValid(results->scores.largeStraight) : err;
   err = (ERR_NONE == err) ? YahtzeeIsValid(results->scores.yahtzee) : err;
   err = (ERR_NONE == err) ? ChanceIsValid(results->scores.chance) : err;

   err = (ERR_NONE == err) ? TotalsAreValid(results) : err;

   return err;
}


// Only valid values for "ones" are 0, 1, 2, 3, ,4, 5
ScoringErrorType OnesIsValid(unsigned int onesVal)
{
    if (onesVal>5)
        return ERR_ONES;
    else
        return ERR_NONE;
}

// Only valid values for "twos" are 0, 2, 4, 6, ,8, 10
ScoringErrorType TwosIsValid(unsigned int twosVal)
{
    if ((twosVal>10) || (twosVal % 2))
        return ERR_TWOS;
    else
        return ERR_NONE;
}

// Only valid values for "threes" are 0, 3, 6, 9, ,12, 15
ScoringErrorType ThreesIsValid(unsigned int threesVal)
{
    if ((threesVal>15) || (threesVal % 3))
        return ERR_THREES;
    else
        return ERR_NONE;
}

// Only valid values for "fours" are 0, 4, 8, 12, 16, 20
ScoringErrorType FoursIsValid(unsigned int foursVal)
{
    if ((foursVal>20) || (foursVal % 4))
        return ERR_FOURS;
    else
        return ERR_NONE;
}

// Only valid values for "fives" are 0, 5, 10, 15, ,20, 25
ScoringErrorType FivesIsValid(unsigned int fivesVal)
{
    if ((fivesVal>25) || (fivesVal % 5))
        return ERR_FIVES;
    else
        return ERR_NONE;
}

// Only valid values for "sixes" are 0, 6, 12, 18, 24, 30
ScoringErrorType SixesIsValid(unsigned int sixesVal)
{
    if ((sixesVal>30) || (sixesVal % 6))
        return ERR_SIXES;
    else
        return ERR_NONE;
}

// Scores as the sum of all dice, or 0 if no three are alike.
// So valid values are 0, or [5..30].
ScoringErrorType ThreeOfAKindIsValid(unsigned int threeOfAKindVal)
{
    if ((threeOfAKindVal > 30) || ((threeOfAKindVal > 0) && (threeOfAKindVal < 5)))
        return ERR_THREEOFAKIND;
    else
        return ERR_NONE;
}

// Scores as the sum of all dice, or 0 if no four are alike.
// So valid values are 0, or [5..30].
ScoringErrorType FourOfAKindIsValid(unsigned int fourOfAKindVal)
{
    if ((fourOfAKindVal > 30) || ((fourOfAKindVal > 0) && (fourOfAKindVal < 5)))
        return ERR_FOUROFAKIND;
    else
        return ERR_NONE;

}

// Can only be 0 or 25
ScoringErrorType FullHouseIsValid(unsigned int fullHouseVal)
{
    if ((fullHouseVal != 0) && (fullHouseVal != 25))
        return ERR_FULLHOUSE;
    else
        return ERR_NONE;
}

// Can only be 0 or 30
ScoringErrorType SmallStraightIsValid(unsigned int smallStraightVal)
{
    if ((smallStraightVal != 0) && (smallStraightVal != 30))
        return ERR_SMALLSTRAIGHT;
    else
        return ERR_NONE;
}

// Can only be 0 or 40
ScoringErrorType LargeStraightIsValid(unsigned int largeStraightVal)
{
    if ((largeStraightVal != 0) && (largeStraightVal != 40))
        return ERR_LARGESTRAIGHT;
    else
        return ERR_NONE;
}

// Can only be 0 or 50
ScoringErrorType YahtzeeIsValid(unsigned int yahtzeeVal)
{
    if ((yahtzeeVal != 0) && (yahtzeeVal != 50))
        return ERR_YAHTZEE;
    else
        return ERR_NONE;
}

// Chance is simply the sum of all dice, so must be in the range [5..30]
ScoringErrorType ChanceIsValid(unsigned int chanceVal)
{
    if ((chanceVal < 5) || (chanceVal > 30))
        return ERR_CHANCE;
    else
        return ERR_NONE;
}

// Checks for consistency between the totals and the scores contained
// in the results. Does not check for the validity of the individual
// scores that sum to make the totals.
ScoringErrorType TotalsAreValid(const ScoreResultsType * results)
{
   ScoringErrorType err = ERR_NONE;
   const ScoreAssignmentsType * const pScores = &(results->scores);

   // Calculate the section totals
   unsigned int upperSum = pScores->ones + pScores->twos + pScores->threes
                            + pScores->fours + pScores->fives + pScores->sixes;
   unsigned int lowerSum = pScores->threeOfAKind + pScores->fourOfAKind
                            + pScores->fullHouse + pScores->smallStraight
                            + pScores->largeStraight + pScores->yahtzee
                            + pScores->chance;

   // The bonus can be only 0 (if upper section is less than 63) or 35 (if
   // upper section is 63 or greater).
   unsigned int bonus = upperSum < 63 ? 0 : 35;

   // Check the results against the calculated totals
   if (results->upperTotalWithoutBonus != upperSum)
      err = ERR_UPPERTOTAL;
   else if (results->lowerTotal != lowerSum)
      err = ERR_LOWERTOTAL;
   else if (results->upperBonus != bonus)
      err = ERR_BONUS;
   else if (results->total != (upperSum + lowerSum + bonus))
      err = ERR_TOTAL;

   return err;
}

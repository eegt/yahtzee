//
//  yahtzeePlayer.c
//  Yahtzee
//
//  Created by Emily Eaton on 3/18/18.
//

#include <stdbool.h>
#include <assert.h>
#include "yahtzeePlayerEmily.h"
#include "yahtzeeTypes.h"
#include "yahtzee.h"
#include "yahtzeeScorer.h"
#include "yahtzeeToolbox.h"

#define INVALID_SCORE 1000

typedef enum ScoresheetField
{
    ONES,
    TWOS,
    THREES,
    FOURS,
    FIVES,
    SIXES,
    THREEOFAKIND,
    FOUROFAKIND,
    FULLHOUSE,
    SMALLSTRAIGHT,
    LARGESTRAIGHT,
    YAHTZEE,
    CHANCE,
    NFIELDS
} ScoresheetFieldType;

unsigned int g_scoresheet[NFIELDS];

void CopyScores(ScoreAssignmentsType * destScores);

void InvalidateAllScores();
bool IsUnscored(ScoresheetFieldType field);
bool IsUnscoredUpperSection(unsigned int rank);
unsigned int HowManyHaveBeenScored();

void ScoreWithThreeOfAKind(const FiveDiceType * pDice);
void ScoreWithJunk(const FiveDiceType * pDice);

void RollForRank(FiveDiceType * pDice, unsigned int rank);
void RollForLargestSum(FiveDiceType * pDice, unsigned int rankToKeep);
void RollForFullHouse(FiveDiceType * pDice);
void RollForLargeStraight(FiveDiceType * pDice);

void RerollWithSmallStraight(FiveDiceType * pDice);
void RerollWithThreeOfAKind(FiveDiceType * pDice);
void RollAllWithUpperSectionCheck(FiveDiceType * pDice);
void RerollWithJunk(FiveDiceType * pDice);


// Changes to put in the template:
//    - Remove the commented out ScoreAssignmentsType * variable
//    - Remove the Sophia Sophia


// playEmily
// Inputs: a pointer to 13 initial dice rolls, a structure for storing results
// Returns: none, but the results structure is updated
//
void PlayEmily(const FiveDiceType * pThirteenTurns, ScoreResultsType * pResults)
{
    FiveDiceType thisTurn;
    bool turnHasBeenScored;
    unsigned int rerollsRemaining;
    unsigned int nFieldsScored = 0;

    InvalidateAllScores();

    for (int i=0; i<NTURNS; i++)
    {
        // Start of a turn - get the dice, reset the "scored" flag and number of rolls
        thisTurn = *pThirteenTurns++;
        turnHasBeenScored = false;
        rerollsRemaining = 3;

        while (rerollsRemaining-- && !turnHasBeenScored)
        {
            // If there is a yahtzee and we still need one, always score it
            if (IsYahtzee(&thisTurn) && IsUnscored(YAHTZEE))
                g_scoresheet[YAHTZEE] = ScoreAsYahtzee(&thisTurn);

            // If there is a large straight and we still need one, always score it
            else if (IsLargeStraight(&thisTurn) && IsUnscored(LARGESTRAIGHT))
                g_scoresheet[LARGESTRAIGHT] = ScoreAsLargeStraight(&thisTurn);

            // If there is a full house and we still need one, always score it
            else if (IsFullHouse(&thisTurn) && IsUnscored(FULLHOUSE))
                g_scoresheet[FULLHOUSE] = ScoreAsFullHouse(&thisTurn);

            // If we find a small straight, there are a few cases.
            //
            // If we still need both straights...
            //    if rerolls remain, try to get large
            //    if no rerolls remain, score it as small
            // If we already have small straight but still need large...
            //    if rerolls remain, try to get large
            //    if no rerolls remain, this is a "score as junk" case
            // If we already have a large straight but still need small...
            //    just score it, even if there are rolls remaining
            // If none of these...
            //    fall through to next cases; this is basically junk
            else if (IsSmallStraight(&thisTurn) && IsUnscored(SMALLSTRAIGHT) && IsUnscored(LARGESTRAIGHT))
            {
                if (rerollsRemaining)
                    RollForLargeStraight(&thisTurn);
                else
                    g_scoresheet[SMALLSTRAIGHT] = ScoreAsSmallStraight(&thisTurn);
            }
            else if (IsSmallStraight(&thisTurn) && !IsUnscored(SMALLSTRAIGHT) && IsUnscored(LARGESTRAIGHT))
            {
                if (rerollsRemaining)
                    RollForLargeStraight(&thisTurn);
                else
                    ScoreWithJunk(&thisTurn);
            }
            else if (IsSmallStraight(&thisTurn) && IsUnscored(SMALLSTRAIGHT) && !IsUnscored(LARGESTRAIGHT))
            {
                g_scoresheet[SMALLSTRAIGHT] = ScoreAsSmallStraight(&thisTurn);
            }

            // If we find three or more of the same dice rank, need to apply more
            // logic, since three of a kind could be the basis for many different
            // fields on the scoresheet.
            else if (IsThreeOfAKind(&thisTurn))
            {
                if (rerollsRemaining)
                    RerollWithThreeOfAKind(&thisTurn);
                else
                    ScoreWithThreeOfAKind(&thisTurn);
            }

            // If we've gotten to this point, we don't have more than two of
            // any rank, and we don't have a straight. Need to apply more logic
            // to decide how to roll (if rolls remain) or how to score (if
            // we're out of rolls)
            else
            {
                if (rerollsRemaining)
                    RerollWithJunk(&thisTurn);
                else
                    ScoreWithJunk(&thisTurn);
            }

            // Check to see if a turn was scored this time through the logic
            if (nFieldsScored < HowManyHaveBeenScored())
            {
                turnHasBeenScored = true;
                nFieldsScored = HowManyHaveBeenScored();
            }
        }

        // Copy the scores to the official results
        CopyScores(&pResults->scores);

    }

    // Calculate your section totals, bonus, and game total

}

//------------------------------------------------------------
// Scoresheet maintainance routines
//------------------------------------------------------------

// CopyScores
// Inputs: none
// Returns: none
//
// Copies scores from our tacky global scoresheet variable to the return struct
void CopyScores(ScoreAssignmentsType * destScores)
{
    destScores->ones = g_scoresheet[ONES];
    destScores->twos = g_scoresheet[TWOS];
    destScores->threes = g_scoresheet[THREES];
    destScores->fours = g_scoresheet[FOURS];
    destScores->fives = g_scoresheet[FIVES];
    destScores->sixes = g_scoresheet[SIXES];
    destScores->threeOfAKind = g_scoresheet[THREEOFAKIND];
    destScores->fourOfAKind = g_scoresheet[FOUROFAKIND];
    destScores->fullHouse = g_scoresheet[FULLHOUSE];
    destScores->smallStraight = g_scoresheet[SMALLSTRAIGHT];
    destScores->largeStraight = g_scoresheet[LARGESTRAIGHT];
    destScores->yahtzee = g_scoresheet[YAHTZEE];
    destScores->chance = g_scoresheet[CHANCE];
}

// InvalidateAllScores
// Inputs: none
// Returns: none
//
// Sets all the scores in the tacky global scoresheet to an invalid value.
// Useful in keeping track of which items have been scored already.
void InvalidateAllScores()
{
    for (int i=0; i<NFIELDS; i++)
    {
        g_scoresheet[i] = INVALID_SCORE;
    }
}

// IsUnscored
// Inputs: the scoresheet field we're checking for 'unscored/scored' status
// Returns: true if the score is invalid,
//          false if it's been replaced with a valid score
bool IsUnscored(ScoresheetFieldType field)
{
    return (g_scoresheet[field] == INVALID_SCORE);
}

// IsUnscoredUpperSection
// Inputs: a dice rank
// Returns: true if that rank's field in the upper section hasn't been scored,
//          false if it has been scored
bool IsUnscoredUpperSection(unsigned int rank)
{
    bool returnVal = false;
    switch (rank)
    {
        case 1: returnVal = IsUnscored(ONES); break;
        case 2: returnVal = IsUnscored(TWOS); break;
        case 3: returnVal = IsUnscored(THREES); break;
        case 4: returnVal = IsUnscored(FOURS); break;
        case 5: returnVal = IsUnscored(FIVES); break;
        case 6: returnVal = IsUnscored(SIXES); break;
        default: assert(false);
    }

    return returnVal;
}

// HowManyHaveBeenScored
// Inputs: none
// Returns: the number of fields in the scoresheet that have been scored
unsigned int HowManyHaveBeenScored()
{
    unsigned int nScoredFields = 0;
    for (int i=0; i<NFIELDS; i++)
    {
        if (g_scoresheet[i] != INVALID_SCORE)
           nScoredFields++;
    }

    return nScoredFields;

}

//------------------------------------------------------------
// Scoring logic routines
//------------------------------------------------------------

// ScoreWithThreeOfAKind
// Inputs: pointer to a set of five dice (with at least three of the same rank)
// Returns: none
//
// Decides the best scoresheet field to score this set of dice, based on which
// fields have already been scored. Three or more of a kind could be scored in
// the upper section, as three- or four-of a kind, as a full house, or in
// yahtzee.
void ScoreWithThreeOfAKind(const FiveDiceType * pDice)
{
    // Find the rank that has three or more dice
    unsigned int targetRank = MostCommonRank(pDice);

    // Error check: This routine should only be called with a dice set having
    // at least three of the target rank.
    assert(HowManyOfRank(pDice, targetRank) > 2);

    // Priority 1: Score as yahtzee
    if (IsYahtzee(pDice) && IsUnscored(YAHTZEE))
        g_scoresheet[YAHTZEE] = ScoreAsYahtzee(pDice);

    // Priority 2: Score as full house
    else if (IsFullHouse(pDice) && IsUnscored(FULLHOUSE))
        g_scoresheet[FULLHOUSE] = ScoreAsFullHouse(pDice);

    // Priority 3: Score in the upper section
    else if (IsUnscoredUpperSection(targetRank))
    {
        switch (targetRank)
        {
            case 1: g_scoresheet[ONES] =   ScoreAsTopSection(pDice, 1); break;
            case 2: g_scoresheet[TWOS] =   ScoreAsTopSection(pDice, 2); break;
            case 3: g_scoresheet[THREES] = ScoreAsTopSection(pDice, 3); break;
            case 4: g_scoresheet[FOURS] =  ScoreAsTopSection(pDice, 4); break;
            case 5: g_scoresheet[FIVES] =  ScoreAsTopSection(pDice, 5); break;
            case 6: g_scoresheet[SIXES] =  ScoreAsTopSection(pDice, 6); break;
            default: assert(false);
        }
    }

    // Priority 4: Score as four of a kind
    else if (IsUnscored(FOUROFAKIND) && HowManyOfRank(pDice, targetRank) == 4)
        g_scoresheet[FOUROFAKIND] = ScoreAsFourOfAKind(pDice);

    // Priority 5: Score as three of a kind
    else if (IsUnscored(THREEOFAKIND))
        g_scoresheet[THREEOFAKIND] = ScoreAsThreeOfAKind(pDice);

    // Bummer... we have no need for this rank. We'll have to underscore or zero
    // something, or score chance.
    else
        ScoreWithJunk(pDice);
}

// ScoreWithJunk
// Inputs: pointer to set of five dice
// Returns: none
//
// This routine is called when the dice don't match any available scoring
// fields. Makes a logical choice of which unused scoring field is best to
// use... whether to score in chance, or zero a field, or under-score a field
// in the top section.
//
// Note that this is the scoring routine of last resort, so it must give
// the opportunity to touch every field, in case there is only one unscored
// field remaining
void ScoreWithJunk(const FiveDiceType * pDice)
{
    // Priority 1: use chance if the total is large
    if (IsUnscored(CHANCE) && (ScoreAsChance(pDice) > 18))
        g_scoresheet[CHANCE] = ScoreAsChance(pDice);

    // Priority 2: zero yahtzee
    else if (IsUnscored(YAHTZEE))
        g_scoresheet[YAHTZEE] = ScoreAsYahtzee(pDice);

    // Priority 3: score as ones, even if zeroing
    else if (IsUnscored(ONES))
        g_scoresheet[ONES] = ScoreAsTopSection(pDice, 1);

    // Priority 4: zero large straight
    else if (IsUnscored(LARGESTRAIGHT))
        g_scoresheet[LARGESTRAIGHT] = ScoreAsLargeStraight(pDice);

    // Priority 5: zero four of a kind
    else if (IsUnscored(FOUROFAKIND))
        g_scoresheet[FOUROFAKIND] = ScoreAsFourOfAKind(pDice);

    // Priority 6: lower the threshold for scoring as chance
    else if (IsUnscored(CHANCE) && (ScoreAsChance(pDice) > 12))
        g_scoresheet[CHANCE] = ScoreAsChance(pDice);

    // Priority 6: score as twos, even if zeroing
    else if (IsUnscored(TWOS))
        g_scoresheet[TWOS] = ScoreAsTopSection(pDice, 2);

    // Priority 7: zero full house
    else if (IsUnscored(FULLHOUSE))
        g_scoresheet[FULLHOUSE] = ScoreAsFullHouse(pDice);

    // Priority 8: score in an upper section field if at least 2 of a rank
    else if (IsUnscored(THREES) && (HowManyOfRank(pDice, 3) > 1))
        g_scoresheet[THREES] = ScoreAsTopSection(pDice, 3);
    else if (IsUnscored(FOURS) && (HowManyOfRank(pDice, 4) > 1))
        g_scoresheet[FOURS] = ScoreAsTopSection(pDice, 4);
    else if (IsUnscored(FIVES) && (HowManyOfRank(pDice, 5) > 1))
        g_scoresheet[FIVES] = ScoreAsTopSection(pDice, 5);
    else if (IsUnscored(SIXES) && (HowManyOfRank(pDice, 6) > 1))
        g_scoresheet[SIXES] = ScoreAsTopSection(pDice, 6);

    // Priority 9: score in an upper section field if more at least 1 of a rank
    else if (IsUnscored(THREES) && (HowManyOfRank(pDice, 3) > 0))
        g_scoresheet[THREES] = ScoreAsTopSection(pDice, 3);
    else if (IsUnscored(FOURS) && (HowManyOfRank(pDice, 4) > 0))
       g_scoresheet[FOURS] = ScoreAsTopSection(pDice, 4);
    else if (IsUnscored(FIVES) && (HowManyOfRank(pDice, 5) > 0))
        g_scoresheet[FIVES] = ScoreAsTopSection(pDice, 5);
    else if (IsUnscored(SIXES) && (HowManyOfRank(pDice, 6) > 0))
        g_scoresheet[SIXES] = ScoreAsTopSection(pDice, 6);

    // Priority 10: zero an upper section field
    else if (IsUnscored(THREES))
        g_scoresheet[THREES] = ScoreAsTopSection(pDice, 3);
    else if (IsUnscored(FOURS))
        g_scoresheet[FOURS] = ScoreAsTopSection(pDice, 4);
    else if (IsUnscored(FIVES))
        g_scoresheet[FIVES] = ScoreAsTopSection(pDice, 5);
    else if (IsUnscored(SIXES))
        g_scoresheet[SIXES] = ScoreAsTopSection(pDice, 6);

    // Priority 11: zero three of a kind
    else if (IsUnscored(THREEOFAKIND))
        g_scoresheet[THREEOFAKIND] = ScoreAsThreeOfAKind(pDice);

    // Priority 12: zero small straight
    else if (IsUnscored(SMALLSTRAIGHT))
        g_scoresheet[SMALLSTRAIGHT] = ScoreAsSmallStraight(pDice);

    // Last priority: score as chance
    else if (IsUnscored(CHANCE))
        g_scoresheet[CHANCE] = ScoreAsChance(pDice);

    // If we got here, then something is wrong, because this function should
    // touch every possible scoring field and shouldn't be called unless at
    // least one scoring field is available.
    else
        assert(false);
}

//------------------------------------------------------------
// Reroll logic routines
//------------------------------------------------------------

// RollForRank
// Inputs: pointer to set of five dice, the rank we want to roll for
// Returns: none
//
// Rerolls any dice that aren't of the specified rank
void RollForRank(FiveDiceType * pDice, unsigned int rank)
{
    RollDice(pDice, pDice->d1 != rank,
                    pDice->d2 != rank,
                    pDice->d3 != rank,
                    pDice->d4 != rank,
                    pDice->d5 != rank);
}

// RollForLargestSum
// Inputs: pointer to set of five dice, a rank we want to keep
// Returns: none
//
// Keeps all dice of the specified rank unchanged.
// For the rest, rerolls the smaller ranks and keeps the larger ones.
// Can pass in 0 as the target rank to make all eligible for reroll.
void RollForLargestSum(FiveDiceType * pDice, unsigned int rankToKeep)
{
    RollDice(pDice, (pDice->d1 != rankToKeep) && (pDice->d1 < 4),
                    (pDice->d2 != rankToKeep) && (pDice->d2 < 4),
                    (pDice->d3 != rankToKeep) && (pDice->d3 < 4),
                    (pDice->d4 != rankToKeep) && (pDice->d4 < 4),
                    (pDice->d5 != rankToKeep) && (pDice->d5 < 4));
}

// RollForFullHouse
// Inputs: pointer to score structure, pointer to set of five dice
// Returns: none
//
// Rerolls dice in an attempt to get a full house
void RollForFullHouse(FiveDiceType * pDice)
{
    // Case 0: Already have a full house... do nothing
    if (ScoreAsFullHouse(pDice))
    {
        // do nothing
    }

    // Case 1: 5 of a kind... reroll two of them
    else if (ScoreAsYahtzee(pDice))
    {
        RollDice(pDice, true, true, false, false, false);
    }

    // Case 2: 4 of a kind... reroll one of the four matched dice
    else if (ScoreAsFourOfAKind(pDice))
    {
        unsigned int rankWithFour = MostCommonRank(pDice);
        if (pDice->d1 == rankWithFour)
            RollDice(pDice, true, false, false, false, false);
        else
            RollDice(pDice, false, true, false, false, false);
    }

    // Case 3: 3 of a kind... reroll one of the mismatched dice
    else if (ScoreAsThreeOfAKind(pDice))
    {
        unsigned int rankWithThree = MostCommonRank(pDice);
        if (pDice->d1 != rankWithThree)
            RollDice(pDice, true, false, false, false, false);
        else if (pDice->d2 != rankWithThree)
            RollDice(pDice, false, true, false, false, false);
        else if (pDice->d3 != rankWithThree)
            RollDice(pDice, false, false, true, false, false);
        else  // d1, d2, d3 are the three of a kind, so d4 and d5 are mistmatched
            RollDice(pDice, false, false, false, true, false);
    }

    // There are no more than two of any rank
    else
    {
        // Look for pairs
        unsigned int pairA = 0;
        unsigned int pairB = 0;
        for (int r=6; r>=1; r--)
        {
            if (HowManyOfRank(pDice, r) == 2)
            {
                if (pairA)
                    pairB = r;
                else
                    pairA = r;
            }
        }

        // Case 4: two pair... reroll the one that's not part of a pair
        if (pairA && pairB)
        {
            RollDice(pDice, (pDice->d1 != pairA) && (pDice->d1 != pairB),
                            (pDice->d2 != pairA) && (pDice->d2 != pairB),
                            (pDice->d3 != pairA) && (pDice->d3 != pairB),
                            (pDice->d4 != pairA) && (pDice->d4 != pairB),
                            (pDice->d5 != pairA) && (pDice->d5 != pairB));
        }


        // Case 5: only one pair... reroll all that aren't part of the pair
        else if (pairA)
            RollForRank(pDice, pairA);

        // Case 6: all dice are unique... reroll all
        else
            RollAllWithUpperSectionCheck(pDice);
    }
}

// RollForLargeStraight
// Inputs: pointer to set of five dice
// Returns: none
//
// Rerolls dice in an attempt to get a large straight
void RollForLargeStraight(FiveDiceType * pDice)
{
    // Case 0: there is already a large straight
    if (ScoreAsLargeStraight(pDice))
    {
        // do nothing
    }

    // Case 1: there is already a small straight, try to extend to large
    // There are a limited number of dice sets that contain a small straight
    // without a large straight:
    //      1-2-3-4 with an extra 1, 2, 3, or 4     reroll one of the duplicates
    //      1-2-3-4 with a 6                        reroll the 6
    //      2-3-4-5 with an extra 2, 3, 4, or 5     reroll one of the duplicates
    //      3-4-5-6 with an extra 3, 4, 5, or 6     reroll one of the duplicates
    //      3-4-5-6 with a 1                        reroll the 1
    else if (ScoreAsSmallStraight(pDice))
    {
        // Find duplicate dice
        unsigned int straightCounter[] = {0, 0, 0, 0, 0, 0, 0};
        unsigned int duplicateRank = 0;
        for (int r=1; r<=6; r++)
        {
            straightCounter[r] = HowManyOfRank(pDice, r);
            if (straightCounter[r] > 1)
                duplicateRank = r;
        }

        // If there's a duplicate rank, roll one of them
        if (duplicateRank)
        {
            if (pDice->d1 == duplicateRank)
                RollDice(pDice, true, false, false, false, false);
            else if (pDice->d2 == duplicateRank)
                RollDice(pDice, false, true, false, false, false);
            else if (pDice->d3 == duplicateRank)
                RollDice(pDice, false, false, true, false, false);
            else  // d1, d2, d3 aren't in the duplicate, so d4 and d5 must be
                RollDice(pDice, false, false, false, true, false);
        }

        // If no duplicate rank, there are only two cases left.
        // If 1-3-4-5-6, roll the 1.
        else if (straightCounter[2] == 0)
        {
            if (pDice->d1 == 1)
                RollDice(pDice, true, false, false, false, false);
            else if (pDice->d2 == 1)
                RollDice(pDice, false, true, false, false, false);
            else if (pDice->d3 == 1)
                RollDice(pDice, false, false, true, false, false);
            else if (pDice->d4 == 1)
                RollDice(pDice, false, false, false, true, false);
            else
                RollDice(pDice, false, false, false, false, true);
        }

        // If 1-2-3-4-6, roll the 6.
        else if (straightCounter[5] == 0)
        {
            if (pDice->d1 == 6)
                RollDice(pDice, true, false, false, false, false);
            else if (pDice->d2 == 6)
                RollDice(pDice, false, true, false, false, false);
            else if (pDice->d3 == 6)
                RollDice(pDice, false, false, true, false, false);
            else if (pDice->d4 == 6)
                RollDice(pDice, false, false, false, true, false);
            else
                RollDice(pDice, false, false, false, false, true);
        }
    }

    // Case 2: there isn't a small straight to preserve
    // Keep at most one 2, 3, 4, and 5.
    // Roll all 1's and 6's plus any duplicates of 2-3-4-5.
    else
    {
        // Find duplicate dice
        unsigned int straightCounter[] = {0, 0, 0, 0, 0, 0, 0};
        for (int r=1; r<=6; r++)
        {
            straightCounter[r] = HowManyOfRank(pDice, r);
        }

        // First check for ones and sixes
        bool rollD1 = (pDice->d1 == 1) || (pDice->d1 == 6);
        bool rollD2 = (pDice->d2 == 1) || (pDice->d2 == 6);
        bool rollD3 = (pDice->d3 == 1) || (pDice->d3 == 6);
        bool rollD4 = (pDice->d4 == 1) || (pDice->d4 == 6);
        bool rollD5 = (pDice->d5 == 1) || (pDice->d5 == 6);

        // Then check for duplicates
        if (straightCounter[pDice->d1] > 1)
        {
            rollD1 = true;
            straightCounter[pDice->d1]--;
        }
        if (straightCounter[pDice->d2] > 1)
        {
            rollD2 = true;
            straightCounter[pDice->d2]--;
        }
        if (straightCounter[pDice->d3] > 1)
        {
            rollD3 = true;
            straightCounter[pDice->d3]--;
        }
        if (straightCounter[pDice->d4] > 1)
        {
            rollD4 = true;
            straightCounter[pDice->d4]--;
        }
        if (straightCounter[pDice->d5] > 1)
        {
            rollD5 = true;
            straightCounter[pDice->d5]--;
        }

        RollDice(pDice, rollD1, rollD2, rollD3, rollD4, rollD5);
    }
}

// RerollWithSmallStraight
// Inputs: pointer to set of five dice
// Returns: none
//
// When a small straight is already present, chooses which dice to reroll
void RerollWithSmallStraight(FiveDiceType * pDice)
{
    // Error check: This routine should only be called with dice that already
    // contain a small straight
    if (!ScoreAsSmallStraight(pDice))
        assert(false);

    // If we don't have a large straight yet, try for that
    else if (IsUnscored(LARGESTRAIGHT))
        RollForLargeStraight(pDice);

    // If we don't have a small straight yet, just keep what we have`
    else if (IsUnscored(g_scoresheet[SMALLSTRAIGHT]))
    {
        // do nothing
    }

    // We've scored both straights, so we need to reroll for something else
    else
    {
        // If there are multiple of 3's, 4's, 5's, or 6's, roll for more
        if ((MostCommonRankCount(pDice) > 1) && (MostCommonRank(pDice) > 2))
            RollForRank(pDice, MostCommonRank(pDice));

        else
            RollAllWithUpperSectionCheck(pDice);
    }
}

// RerollWithThreeOfAKind
// Inputs: pointer to set of five dice
// Returns: none
//
// When three dice of the same rank are already present, chooses which dice
// to reroll
void RerollWithThreeOfAKind(FiveDiceType * pDice)
{
    // Error check: This routine should only be called with a dice set having
    // at least three of the target rank.
    assert(MostCommonRankCount(pDice) > 2);

    unsigned int rankWithThree = MostCommonRank(pDice);

    // Priority 1: Try to fill upper section
    if (IsUnscoredUpperSection(rankWithThree))
        RollForRank(pDice, rankWithThree);

    // Priority 2: Try to get yahtzee
    else if (IsUnscored(YAHTZEE))
        RollForRank(pDice, rankWithThree);

    // Priority 3: Try to get four of a kind
    else if (IsUnscored(FOUROFAKIND))
    {
        if (rankWithThree == 3)
            RollForRank(pDice, rankWithThree);
        else  // numOfTargetRank == 4
            RollForLargestSum(pDice, rankWithThree);
    }

    // Priority 4: Try to get full house
    else if (IsUnscored(FULLHOUSE))
        RollForFullHouse(pDice);

    // Priority 5: Try to improve the three of a kind score
    else if (IsUnscored(THREEOFAKIND))
        RollForLargestSum(pDice, rankWithThree);

    // Priority 6: Increase the total sum for chance
    else if (IsUnscored(CHANCE) && (rankWithThree > 4))
        RollForLargestSum(pDice, 0);

    // Bummer... we have no need for this rank. Reroll all.
    else
        RollAllWithUpperSectionCheck(pDice);
}

// RollAllWithUpperSectionCheck
// Inputs: pointer to set of five dice
// Returns: none
//
// Checks which upper sections are still unscored, and whether any of the
// dice match an unscored section. Then makes a logical choice about which
// dice to keep and which dice to reroll.
void RollAllWithUpperSectionCheck(FiveDiceType * pDice)
{
    // Find the two highest rank upper section fields that we still need.
    // But not ones or twos... those aren't worth rolling for.
    // Identify up to two ranks to try to roll for.
    unsigned int targetRankA = 0;
    unsigned int targetRankB = 0;
    for (int r=6; r>=3; r--)
    {
        if (IsUnscoredUpperSection(r))
        {
            if (targetRankB)
            {
                // do nothing
            }
            else if (targetRankA)
                targetRankB = r;
            else
                targetRankA = r;
        }
    }

    RollDice(pDice, (pDice->d1 != targetRankA) && (pDice->d1 != targetRankB),
                    (pDice->d2 != targetRankA) && (pDice->d2 != targetRankB),
                    (pDice->d3 != targetRankA) && (pDice->d3 != targetRankB),
                    (pDice->d4 != targetRankA) && (pDice->d4 != targetRankB),
                    (pDice->d5 != targetRankA) && (pDice->d5 != targetRankB));
}

// RerollWithJunk
// Inputs: pointer to a set of five dice
// Returns: none
//
// Decides how to reroll when the current set of dice doesn't point clearly
// to a particular scoring strategy
void RerollWithJunk(FiveDiceType * pDice)
{
    bool rolled = false;

    // Do we have two of any needed top section rank? If so, roll for more
    for (int r=6; r>=1; r--)
    {
        if ((HowManyOfRank(pDice, r) > 1) && IsUnscoredUpperSection(r))
        {
            RollForRank(pDice, r);
            rolled = true;
            break;
        }
    }

    // Do we have two of a value worth rolling for three or four of a kind?
    // If so, roll for more.
    if (!rolled && (IsUnscored(THREEOFAKIND) || IsUnscored(FOUROFAKIND)))
    {
        for (int r=6; r>=4; r--)
        {
            if (HowManyOfRank(pDice, r) > 1)
            {
                RollForRank(pDice, r);
                rolled = true;
                break;
            }
        }
    }

    // Do we have one of any needed top section rank? If so, roll for more
    if (!rolled)
    {
        for (int r=6; r>=1; r--)
        {
            if ((HowManyOfRank(pDice, r) > 0) && IsUnscoredUpperSection(r))
            {
                RollForRank(pDice, r);
                rolled = true;
                break;
            }
        }
    }


    // Everything is awful... just reroll them all
    if (!rolled)
    {
        RollDice(pDice, true, true, true, true, true);
    }

}

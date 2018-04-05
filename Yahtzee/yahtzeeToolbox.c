#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#include <assert.h>
#include "yahtzeeTypes.h"
#include "yahtzeeToolbox.h"

unsigned int GetDiceRoll(void);

// HowManyOfRank
// Inputs:  set of five dice, a target rank
// Returns: the number of dice with the given rank
//
// Examples:
//   Scoring the dice (2-2-2-2-2) for rank 2 --> returns 5
//   Scoring the dice (5-3-4-1-2) for rank 1 --> returns 1
//   Scoring the dice (6-5-1-6-4) for rank 5 --> returns 2
unsigned int HowManyOfRank(const FiveDiceType * dice, unsigned int rank)
{
    unsigned int count = 0;

    if (dice->d1 == rank)
        count++;
    if (dice->d2 == rank)
        count++;
    if (dice->d3 == rank)
        count++;
    if (dice->d4 == rank)
        count++;
    if (dice->d5 == rank)
        count++;

    return count;

}

// SumOfAllDice
// Inputs:  set of five dice
// Returns: The sum of the five dice
//
// Examples:
//   Scoring the dice (2-2-2-2-2) --> returns 10
//   Scoring the dice (5-3-4-1-2) --> returns 15
//   Scoring the dice (6-5-1-6-4) --> returns 22
unsigned int SumOfAllDice(const FiveDiceType* dice)
{
    return (dice->d1 + dice->d2 + dice->d3 + dice->d4 + dice->d5);
}

// RollDice
// Inputs:  set of five dice, booleans indicating which are to be rolled
// Returns: none
//
// Examples:
//   Pass in dice (2-4-5-2-6), false, true, true, false, true...
//         ... the 4, 5, and 6 are re-rolled and the 2's are kept.
//   Pass in any dice with 5 trues...
//         ... all dice are rolled.
//   Pass in any dice with 5 falses...
//         ... none of the dice are rolled.
void RollDice(FiveDiceType * dice, bool rollD1, bool rollD2,
                 bool rollD3, bool rollD4, bool rollD5)
{
    if (rollD1)
        dice->d1 = GetDiceRoll();
    if (rollD2)
        dice->d2 = GetDiceRoll();
    if (rollD3)
        dice->d3 = GetDiceRoll();
    if (rollD4)
        dice->d4 = GetDiceRoll();
    if (rollD5)
        dice->d5 = GetDiceRoll();
}

// GetDiceRoll
// Inputs:  none
// Returns: a randomly chosen integer in the range [1..6]
unsigned int GetDiceRoll(void)
{
    static bool randIsNotInitialized = true;

    // This inititalizaton is required for the random number generator
    // we use for dice rolls. It should be done exactly once.
    if (randIsNotInitialized)
    {
        srand((unsigned int)time(NULL));
        randIsNotInitialized = false;
    }

    return (rand() % 7) + 1;
}

// GetRankCounts
// Inputs:  pointer to set of 5 dice, pointer to location for counts
// Returns: none
//
// Updates counts with the number of dice of each rank. For example, if
// dice contains 2-4-5-2-1, the counts will be nOnes = 1, nTwos = 2,
// nThrees = 0, etc.
void GetRankCounts(FiveDiceType * pDice, DiceCountsType * counts)
{
    counts->nOnes = HowManyOfRank(pDice, 1);
    counts->nTwos = HowManyOfRank(pDice, 2);
    counts->nThrees = HowManyOfRank(pDice, 3);
    counts->nFours = HowManyOfRank(pDice, 4);
    counts->nFives = HowManyOfRank(pDice, 5);
    counts->nSixes = HowManyOfRank(pDice, 6);

    // There are five dice, so if the sum of the rank counts isn't five,
    // something is quite wrong.
    unsigned int sum = counts->nOnes + counts->nTwos + counts->nThrees
                         + counts->nFours + counts->nFives + counts->nSixes;
    assert(sum==5);
}

// MostCommonRank
// Inputs:  pointer to set of 5 dice
// Returns: the rank that occurs most often in the set, or 0 if there is a tie
unsigned int MostCommonRank(FiveDiceType * dice)
{
    DiceCountsType counts;
    GetRankCounts(dice, &counts);

    unsigned int returnRank = 0;

    // If there are three or more of any rank, we know that's the most common
    if (counts.nOnes > 2)
        returnRank = 1;
    else if (counts.nTwos > 2)
        returnRank = 2;
    else if (counts.nThrees > 2)
        returnRank = 3;
    else if (counts.nFours > 2)
        returnRank = 4;
    else if (counts.nFives > 2)
        returnRank = 5;
    else if (counts.nSixes > 2)
        returnRank = 6;

    // There are no more than two of any rank. Check for pairs.
    else
    {
        unsigned int nPairs = 0;
        if (counts.nOnes == 2)
        {
            nPairs++;
            returnRank = 1;
        }
        if (counts.nTwos == 2)
        {
            nPairs++;
            returnRank = 2;
        }
        if (counts.nThrees == 2)
        {
            nPairs++;
            returnRank = 3;
        }
        if (counts.nFours == 2)
        {
            nPairs++;
            returnRank = 4;
        }
        if (counts.nFives == 2)
        {
            nPairs++;
            returnRank = 5;
        }
        if (counts.nSixes == 2)
        {
            nPairs++;
            returnRank = 6;
        }

        // If there are no pairs, then each die is unique -> no most common
        // If there are two pairs -> no most common
        // Only if there is exactly one pair do we have a most common rank
        if (nPairs != 1)
            returnRank = 0;
    }

    return returnRank;
}

// MostCommonRankCount
// Inputs:  pointer to set of 5 dice
// Returns: the number of dice having the most common rank, or 0 if there is
//          no most common rank
unsigned int MostCommonRankCount(FiveDiceType * dice)
{
    unsigned int rank = MostCommonRank(dice);
    if (rank)
        return HowManyOfRank(dice, rank);
    else
        return 0;
}

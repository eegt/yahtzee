//
//  yahtzeePlayer.c
//  Yahtzee
//
//  Created by Emily Eaton on 2/22/18.
//

#include <stdbool.h>
#include "yahtzeeTypes.h"
#include "yahtzeeScorer.h"

// Function prototypes for private functions
unsigned int SumOfAllDice(const FiveDiceType* dice);
unsigned int NumOfRank(const FiveDiceType* dice, unsigned int rank);


// ScoreAsTopSection
// Inputs:  set of five dice, the rank being scored (1's, 2's, 3's, etc..)
// Returns: the sum of the dice of that rank
//
// Examples:
//   Scoring the dice (2-5-5-1-5) for rank 5 --> returns 15
//   Scoring the dice (1-3-3-4-5) for rank 1 --> returns 1
//   Scoring the dice (1-2-3-4-5) for rank 6 --> returns 0
unsigned int ScoreAsTopSection(const FiveDiceType* dice, unsigned int rank)
{
    unsigned int returnVal = 0;

    if (rank == 1)
        returnVal = NumOfRank(dice, 1);
    if (rank == 2)
        returnVal = 2 * NumOfRank(dice, 2);
    if (rank == 3)
        returnVal = 3 * NumOfRank(dice, 3);
    if (rank == 4)
        returnVal = 4 * NumOfRank(dice, 4);
    if (rank == 5)
        returnVal = 5 * NumOfRank(dice, 5);
    if (rank == 6)
        returnVal = 6 * NumOfRank(dice, 6);

    return returnVal;
}

// ScoreAsThreeOfAKind
// Inputs:  set of five dice
// Returns: If there are at least three of any rank, the sum of ALL dice. Otherwise 0.
//
// Examples:
//   Scoring the dice (2-4-4-1-4) --> returns 15
//   Scoring the dice (4-4-4-4-4) --> returns 20
//   Scoring the dice (1-4-4-2-5) --> returns 0
unsigned int ScoreAsThreeOfAKind(const FiveDiceType* dice)
{

    if ((NumOfRank(dice, 1) > 2) ||
        (NumOfRank(dice, 2) > 2) ||
        (NumOfRank(dice, 3) > 2) ||
        (NumOfRank(dice, 4) > 2) ||
        (NumOfRank(dice, 5) > 2) ||
        (NumOfRank(dice, 6) > 2))
    {
        return SumOfAllDice(dice);
    }
    else
    {
        return 0;
    }
}

// ScoreAsFourOfAKind
// Inputs:  set of five dice
// Returns: If there are at least four of any rank, the sum of ALL dice. Otherwise 0.
//
// Examples:
//   Scoring the dice (4-4-4-1-4) --> returns 17
//   Scoring the dice (4-4-4-4-4) --> returns 20
//   Scoring the dice (1-4-4-2-5) --> returns 0
unsigned int ScoreAsFourOfAKind(const FiveDiceType* dice)
{
    if ((NumOfRank(dice, 1) > 3) ||
        (NumOfRank(dice, 2) > 3) ||
        (NumOfRank(dice, 3) > 3) ||
        (NumOfRank(dice, 4) > 3) ||
        (NumOfRank(dice, 5) > 3) ||
        (NumOfRank(dice, 6) > 3))
    {
        return SumOfAllDice(dice);
    }
    else
    {
        return 0;
    }
}

// ScoreAsFullHouse
// Inputs:  set of five dice
// Returns: If there are two of one rank and three of another, 25. Otherwise 0.
//
// Note: Five of a kind is NOT a full house.
//
// Examples:
//   Scoring the dice (2-4-4-2-4) --> returns 25
//   Scoring the dice (4-4-4-4-4) --> returns 0
//   Scoring the dice (1-4-4-2-2) --> returns 0
unsigned int ScoreAsFullHouse(const FiveDiceType* dice)
{
    bool isFullHouse = false;

    if (NumOfRank(dice, 1) > 2)
    {
        if ((NumOfRank(dice, 2) > 1) || (NumOfRank(dice, 3) > 1) || (NumOfRank(dice, 4) > 1) ||
            (NumOfRank(dice, 5) > 1) || (NumOfRank(dice, 6) > 1))
        {
            isFullHouse = true;
        }
    }
    if (NumOfRank(dice, 2) > 2)
    {
        if ((NumOfRank(dice, 1) > 1) || (NumOfRank(dice, 3) > 1) || (NumOfRank(dice, 4) > 1) ||
            (NumOfRank(dice, 5) > 1) || (NumOfRank(dice, 6) > 1))
        {
            isFullHouse = true;
        }
    }
    if (NumOfRank(dice, 3) > 2)
    {
        if ((NumOfRank(dice, 1) > 1) || (NumOfRank(dice, 2) > 1) || (NumOfRank(dice, 4) > 1) ||
            (NumOfRank(dice, 5) > 1) || (NumOfRank(dice, 6) > 1))
        {
            isFullHouse = true;
        }
    }
    if (NumOfRank(dice, 4) > 2)
    {
        if ((NumOfRank(dice, 1) > 1) || (NumOfRank(dice, 2) > 1) || (NumOfRank(dice, 3) > 1) ||
            (NumOfRank(dice, 5) > 1) || (NumOfRank(dice, 6) > 1))
        {
            isFullHouse = true;
        }
    }
    if (NumOfRank(dice, 5) > 2)
    {
        if ((NumOfRank(dice, 1) > 1) || (NumOfRank(dice, 2) > 1) || (NumOfRank(dice, 3) > 1) ||
            (NumOfRank(dice, 4) > 1) || (NumOfRank(dice, 6) > 1))
        {
            isFullHouse = true;
        }
    }
    if (NumOfRank(dice, 6) > 2)
    {
        if ((NumOfRank(dice, 1) > 1) || (NumOfRank(dice, 2) > 1) || (NumOfRank(dice, 3) > 1) ||
            (NumOfRank(dice, 4) > 1) || (NumOfRank(dice, 5) > 1))
        {
            isFullHouse = true;
        }
    }

    if (isFullHouse)
        return 25;
    else
        return 0;
}

// ScoreAsSmallStraight
// Inputs:  set of five dice
// Returns: If the set contains 1-2-3-4, 2-3-4-5, or 3-4-5-6, return 30. Otherwise, 0.
//
// Note: Order doesn't matter.
//
// Examples:
//   Scoring the dice (2-3-4-1-6) --> returns 30
//   Scoring the dice (3-5-2-1-6) --> returns 0
//   Scoring the dice (4-6-3-2-5) --> returns 30
unsigned int ScoreAsSmallStraight(const FiveDiceType* dice)
{
    if (((NumOfRank(dice,1) > 0) && (NumOfRank(dice,2) > 0) && (NumOfRank(dice,3) > 0) && (NumOfRank(dice,4) > 0)) ||
        ((NumOfRank(dice,2) > 0) && (NumOfRank(dice,3) > 0) && (NumOfRank(dice,4) > 0) && (NumOfRank(dice,5) > 0)) ||
        ((NumOfRank(dice,3) > 0) && (NumOfRank(dice,4) > 0) && (NumOfRank(dice,5) > 0) && (NumOfRank(dice,6) > 0)))
    {
        return 30;
    }
    else
    {
        return 0;
    }
}

// ScoreAsLargeStraight
// Inputs:  set of five dice
// Returns: If the set contains 1-2-3-4-5 or 2-3-4-5-6, return 40. Otherwise, 0.
//
// Note: Order doesn't matter.
//
// Examples:
//   Scoring the dice (2-3-4-1-6) --> returns 0
//   Scoring the dice (2-3-4-1-5) --> returns 40
//   Scoring the dice (4-6-3-2-5) --> returns 40
unsigned int ScoreAsLargeStraight(const FiveDiceType* dice)
{
    if ((NumOfRank(dice,2) == 1) && (NumOfRank(dice,3) == 1) && (NumOfRank(dice,4) == 1) && (NumOfRank(dice,5) == 1))
    {
        return 40;
    }
    else
    {
        return 0;
    }
}

// ScoreAsYahtzee
// Inputs:  set of five dice
// Returns: If all five dice are the same, 50. Otherwise, 0.
//
// Examples:
//   Scoring the dice (2-2-2-2-2) --> returns 50
//   Scoring the dice (5-5-5-5-5) --> returns 50
//   Scoring the dice (2-2-2-2-1) --> returns 0
unsigned int ScoreAsYahtzee(const FiveDiceType* dice)
{
    if ((NumOfRank(dice, 1) == 5) ||
        (NumOfRank(dice, 2) == 5) ||
        (NumOfRank(dice, 3) == 5) ||
        (NumOfRank(dice, 4) == 5) ||
        (NumOfRank(dice, 5) == 5) ||
        (NumOfRank(dice, 6) == 5))
    {
        return 50;
    }
    else
    {
        return 0;
    }
}

// ScoreAsChance
// Inputs:  set of five dice
// Returns: The sum of all five dice.
unsigned int ScoreAsChance(const FiveDiceType* dice)
{
    return SumOfAllDice(dice);
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

// NumOfRank
// Inputs:  set of five dice
// Returns: the number of dice with the given rank
//
// Examples:
//   Scoring the dice (2-2-2-2-2) for rank 2 --> returns 5
//   Scoring the dice (5-3-4-1-2) for rank 1 --> returns 1
//   Scoring the dice (6-5-1-6-4) for rank 5 --> returns 2
unsigned int NumOfRank(const FiveDiceType* dice, unsigned int rank)
{
    unsigned int count = 0;

    if (dice->d1 == rank)
        count++;
    if (dice->d2 == rank)
        count ++;
    if (dice->d3 == rank)
        count++;
    if (dice->d4 == rank)
        count++;
    if (dice->d5 == rank)
        count++;

    return count;
}

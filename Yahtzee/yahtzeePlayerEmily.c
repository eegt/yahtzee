//
//  yahtzeePlayer.c
//  Yahtzee
//
//  Created by Emily Eaton on 4/4/18.
//

#include "yahtzeePlayerEmily.h"
#include "yahtzeeTypes.h"
#include "yahtzeeScorer.h"

// Function prototypes for private routines
void DumbScore2(ScoreResultsType * results, FiveDiceType * dice, int turnNum);


// playTemplate
// Inputs: a pointer to 13 initial dice rolls, a structure for storing results
// Returns: none, but the results structure is updated
//
// This is the top-level "play" function called by the competition loop.
// Change its name to playSam or playSophia or playToby, but don't change
// its input parameters.
//
// In this template function, the logic isn't filled in - there's just a dummy
// routine there to fill the results with valid scores. Your job is to fill in
// the logic to determine which dice to roll and how to best score your
// results.
//
// Feel free to write whatever subroutines might be useful to make your code
// well-abstracted or to help with test and debug. (You can look at yahtzee.c
// for some example print routines... printing the dice values, score values,
//  etc. can be useful in testing.)
void PlayEmily(const FiveDiceType * thirteenTurns, ScoreResultsType * results)
{
    FiveDiceType thisTurn;

    for (int i=0; i<NTURNS; i++)
    {
        thisTurn = *thirteenTurns++;

        // Look at the dice and decide how you want to re-roll

        // Call getDiceRoll() on each die value you want to replace

        // Look at the dice and decide how you want to re-roll

        // Call getDiceRoll() on each die value you want to replace

        // Look at the dice and decide how you want to score your turn
        // Remember you can only score each category once, so you'll need a way
        //   to keep track of which categories you've already used

        // Place your score in results
        DumbScore(results, &thisTurn, i);  // Remove this
    }

    // Calculate your section totals, bonus, and game total

}

// DumbScore
// This is just a dummy function to give us some valid scores
void DumbScore2(ScoreResultsType * results, FiveDiceType * dice, int turnNum)
{
    switch (turnNum)
    {
        case 0: results->scores.ones = ScoreAsTopSection(dice, 1);
        case 1: results->scores.twos = ScoreAsTopSection(dice, 2);
        case 2: results->scores.threes = ScoreAsTopSection(dice, 3);
        case 3: results->scores.fours = ScoreAsTopSection(dice, 4);
        case 4: results->scores.fives = ScoreAsTopSection(dice, 5);
        case 5: results->scores.sixes = ScoreAsTopSection(dice, 6);

        case 6: results->scores.threeOfAKind = ScoreAsThreeOfAKind(dice);
        case 7: results->scores.fourOfAKind = ScoreAsFourOfAKind(dice);
        case 8: results->scores.fullHouse = ScoreAsFullHouse(dice);
        case 9: results->scores.smallStraight = ScoreAsSmallStraight(dice);
        case 10: results->scores.largeStraight = ScoreAsLargeStraight(dice);
        case 11: results->scores.yahtzee = ScoreAsYahtzee(dice);
        case 12: results->scores.chance = ScoreAsChance(dice);
    }
}

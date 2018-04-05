//
//  yahtzee.c
//  The top-level Yahtzee file.
//  Contains main() and some support routines
//
//  Created by Emily Eaton on 2/22/18.
//

//-----------------------------------------------------------------------------
// INCLUDES (how C files know how to talk to each other)
//-----------------------------------------------------------------------------

// Includes in <...> are C standard libraries.
// These give you functions like print, random number generators, etc.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Includes in "..." are headers for our own files.
// Each C-file has a corresponding H-file that contains function signatures,
//    structures, constants, etc. that are specific to that C-file.
//    This is what lets you organize your functions into different files
//    that now how to coordinate with each other.
//
// In general, structures and functions prototypes used only in a single
//    C file go in that C file. Structures or function prototypes that other
//    files will use go in the H file.
#include "yahtzee.h"
#include "yahtzeeTypes.h"
#include "yahtzeePlayerTemplate.h"
#include "yahtzeePlayerEmily.h"
#include "yahtzeeScoreChecker.h"
#include "yahtzeeToolbox.h"


//-----------------------------------------------------------------------------
// DECLARATIONS (stuff this file needs to know about)
//-----------------------------------------------------------------------------

// Declarations might include constants (placed here at the top so they're
// easy to change later), structures and typedefs, global variables (use
// sparingly), and function declarations.

// In C we also include function declarations for subroutines in this file.
// In C, it's typical to have your main or top-level routine first in the file,
// and subroutines later. But in strict C, functions don't know about other
// functions that come later in the file unless they're declared first.

// Here are a couple of constants... from here we can easily change the number
// of players or games later if we want to.
#define NPLAYERS 2
#define NGAMES 3

// Here is a structure type definition.
// Typedefs aren't required, but they often make code more readable and they
// give the compiler some clues that will help it catch potential bugs.
//
// This structure represents one Yahtzee player. It contains:
//    - a pointer to the players "play" routine
//    - an array to contain the player's score for each game played
typedef struct
{
    void (* playFn) (const FiveDiceType* thirteenTurns, ScoreResultsType* results);
    unsigned int scores[NGAMES];
} PlayerType;

// Here are the function prototypes. These just say, "hey, first function(s),
// here are some routines that are defined later in the file, in case you
// need them."
void PrintGameDiceValues(const FiveDiceType turns[], unsigned int nTurns, int gameNum);
void CalculateTotals(ScoreResultsType * results);


//-----------------------------------------------------------------------------
// MAIN (where the program starts executing)
//-----------------------------------------------------------------------------

// There's only one main(), no matter how many files I have in the program.
int main()
{
    // Create some storage locations:
    //   - an array of players who are competing
    //   - an array to contain a game's worth of dice rolls
    //   - a location to store game results
    PlayerType players[NPLAYERS];
    FiveDiceType thirteenTurns[NTURNS];
    ScoreResultsType gameResults;

    // Function pointers! An advanced concept.
    // Each player has a pointer to the function s/he'll use to decide
    // what to do with the dice rolls.
    players[0].playFn = &PlayTemplate;
    players[1].playFn = &PlayEmily;

    printf("\n");
    printf(" ----------------------------------------------------\n");
    printf("|                   YAHTZEE SIMULATOR                |\n");
    printf(" ----------------------------------------------------\n");
    printf("\n");

    // One game isn't much of a sample size to test whose player is better,
    // so this loop allows us to play multiple games
    for (int gg=0; gg<NGAMES; gg++)
    {
        // Each player will play the game using the same initial
        // dice rolls. Here we're generating 13 sets of 5 dice...
        // a complete game.
        for (int tt=0; tt<(NTURNS); tt++)
        {
            RollDice(&thirteenTurns[tt], true, true, true, true, true);
        }

        PrintGameDiceValues(thirteenTurns, 13, gg);

        // Each player takes a turn
        for (int pp=0; pp<NPLAYERS; pp++)
        {
            InitializeGameResults(&gameResults);

            // Call the player's play function using the function pointer
            (players[pp].playFn)(thirteenTurns, &gameResults);

            // If the player didn't do totals, calculate them
            if (0 == gameResults.total)
            {
                CalculateTotals(&gameResults);
            }

            // Verify that the results are legal values
            ScoringErrorType err = ScoreResultsAreValid(&gameResults);

            // Store the player's score.
            // If no errors were found, then the score is the total from
            // the results structure. If there was an error, then just
            // score 0 for this round.
            players[pp].scores[gg] = (ERR_NONE == err) ? gameResults.total : 0;

            PrintResults(&gameResults, pp);

            if (ERR_NONE != err)
            {
                printf("\n");
                printf("   Player %d's scores are invalid in game %d.\n", pp, gg);
                printf("   ERROR CODE: %d\n", err);
            }

        }

    }

    return 0;
}


//-----------------------------------------------------------------------------
// Private Subroutines
//-----------------------------------------------------------------------------

// PrintGameDiceValues
// Inputs: array of dice values, number of dice sets in the array, game number
// Returns: nothing
//
// Prints a title followed by the dice values for a single game
void PrintGameDiceValues(const FiveDiceType turns[], unsigned int nTurns, int gameNum)
{
    printf("\n");
    printf("-----------------------\n");
    printf(" GAME %d\n", gameNum);
    printf("-----------------------\n");
    printf("\n");

    PrintDiceValues(turns, nTurns);

    printf("\n");
}

// CalculateTotals
// Inputs: score results
// Results: none, but updates the results structure with totals
void CalculateTotals(ScoreResultsType * results)
{
    ScoreAssignmentsType * pScores = &(results->scores);
    results->upperTotalWithoutBonus = pScores->ones + pScores->twos + pScores->threes
                         + pScores->fours + pScores->fives + pScores->sixes;
    results->lowerTotal = pScores->threeOfAKind + pScores->fourOfAKind
                         + pScores->fullHouse + pScores->smallStraight + pScores->largeStraight
                         + pScores->yahtzee + pScores->chance;
    results->upperBonus = results->upperTotalWithoutBonus >= 63 ? 35 : 0;
    results->total = results->upperTotalWithoutBonus + results->upperBonus + results->lowerTotal;
}

//-------------------------------------------------------------
// Public Subroutines
//-------------------------------------------------------------

// PrintDiceValues
// Inputs: array of dice values
// Returns: nothing
//
// Prints the dice values for a single game
void PrintDiceValues(const FiveDiceType turns[], unsigned int nTurns)
{
    for (int i=0; i<nTurns; i++)
    {
        printf("   Roll %d: ", i+1);
        printf("%d ", turns[i].d1);
        printf("%d ", turns[i].d2);
        printf("%d ", turns[i].d3);
        printf("%d ", turns[i].d4);
        printf("%d\n", turns[i].d5);
    }
}

// PrintResults
// Inputs: game results
// Outputs: none
//
// Prints the total and scorecard values for a single player
void PrintResults(const ScoreResultsType * results, int playerNum)
{
    printf("PLAYER %d scored %d\n", playerNum, results->total);
    printf("\n");
    printf("   Ones:     %d\n", results->scores.ones);
    printf("   Twos:     %d\n", results->scores.twos);
    printf("   Threes:   %d\n", results->scores.threes);
    printf("   Fours:    %d\n", results->scores.fours);
    printf("   Fives:    %d\n", results->scores.fives);
    printf("   Sixes:    %d\n", results->scores.sixes);
    printf("   BONUS:    %d\n", results->upperBonus);
    printf("   SUBTOTAL  %d\n", results->upperTotalWithoutBonus + results->upperBonus);
    printf("\n");
    printf("   Three of A Kind: %d\n", results->scores.threeOfAKind);
    printf("   Four of a Kind:  %d\n", results->scores.fourOfAKind);
    printf("   Full House:      %d\n", results->scores.fullHouse);
    printf("   Small Straight:  %d\n", results->scores.smallStraight);
    printf("   Large Straight:  %d\n", results->scores.largeStraight);
    printf("   Yahtzee:         %d\n", results->scores.yahtzee);
    printf("   Chance:          %d\n", results->scores.chance);
    printf("   SUBTOTAL:        %d\n", results->lowerTotal);
    printf("\n");
}

// InitializeGameResults
// Inputs: score results structure
// Results: none, but updates the results structure with all zeroes
void InitializeGameResults(ScoreResultsType * results)
{
    ScoreAssignmentsType * pScores = &(results->scores);
    pScores->ones = 0;
    pScores->twos = 0;
    pScores->threes = 0;
    pScores->fours = 0;
    pScores->fives = 0;
    pScores->sixes = 0;
    pScores->threeOfAKind = 0;
    pScores->fourOfAKind = 0;
    pScores->fullHouse = 0;
    pScores->smallStraight = 0;
    pScores->largeStraight = 0;
    pScores->yahtzee = 0;
    pScores->chance = 0;
    results->upperTotalWithoutBonus = 0;
    results->upperBonus = 0;
    results->lowerTotal = 0;
    results->total = 0;
}

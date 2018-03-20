//
//  tests_yahtzeeScorer.c
//  YahtzeeTests
//
//  Created by Emily Eaton on 2/22/18.
//


#include "tests_yahtzeeScorer.h"
#include "yahtzeeTypes.h"
#include "yahtzeeScorer.h"
#include "testframework.h"

// Function prototypes for test subroutines
void Test_ScoreAsTopSection(unsigned int testNum);
void Test_ScoreAsThreeOfAKind(unsigned int testNum);
void Test_ScoreAsFourOfAKind(unsigned int testNum);
void Test_ScoreAsFullHouse(unsigned int testNum);
void Test_ScoreAsSmallStraight(unsigned int testNum);
void Test_ScoreAsLargeStraight(unsigned int testNum);
void Test_ScoreAsYahtzee(unsigned int testNum);
void Test_ScoreAsChance(unsigned int testNum);

// Function prototypes for helper routines
void SetDice(FiveDiceType * dice, unsigned int d1, unsigned int d2,
                 unsigned int d3, unsigned int d4, unsigned int d5);


//-----------------------------------------------
// Top level
//-----------------------------------------------

// Test_YahtzeeScorer
// Inputs: none
// Outputs: none
//
// Calls the subroutines to test each Yahtzee Scorer function.
//
// The "testNum" parameter passed to each creates unique codes
// for each test. In a more polished testing setup, each code
// would have an associated string that would report the name
// of the failed test.
void Test_YahtzeeScorer()
{
    Test_ScoreAsTopSection(1000);
    Test_ScoreAsThreeOfAKind(1100);
    Test_ScoreAsFourOfAKind(1200);
    Test_ScoreAsFullHouse(1300);
    Test_ScoreAsSmallStraight(1400);
    Test_ScoreAsLargeStraight(1500);
    Test_ScoreAsYahtzee(1600);
    Test_ScoreAsChance(1700);
}

//-----------------------------------------------
// Upper section tests
//-----------------------------------------------

// Test_ScoreAsTopSection
// Inputs: test number base
// Outputs: none, but test failures will be printed to stdout
//
// Unit tests for the yahtzeeScorer routine ScoreAsTopSection().
// The first test will have id number 'testNum', the second
// test 'testNum+1', etc.
void Test_ScoreAsTopSection(unsigned int testNum)
{
    FiveDiceType dice;

    SetDice(&dice, 1, 1, 1, 1, 1);
    TestAssert_UInt(ScoreAsTopSection(&dice, 1), 5, testNum++);
    TestAssert_UInt(ScoreAsTopSection(&dice, 2), 0, testNum++);
    SetDice(&dice, 2, 2, 2, 2, 2);
    TestAssert_UInt(ScoreAsTopSection(&dice, 2), 10, testNum++);
    TestAssert_UInt(ScoreAsTopSection(&dice, 3), 0, testNum++);
    SetDice(&dice, 3, 3, 3, 3, 3);
    TestAssert_UInt(ScoreAsTopSection(&dice, 3), 15, testNum++);
    TestAssert_UInt(ScoreAsTopSection(&dice, 4), 0, testNum++);
    SetDice(&dice, 4, 4, 4, 4, 4);
    TestAssert_UInt(ScoreAsTopSection(&dice, 4), 20, testNum++);
    TestAssert_UInt(ScoreAsTopSection(&dice, 5), 0, testNum++);
    SetDice(&dice, 5, 5, 5, 5, 5);
    TestAssert_UInt(ScoreAsTopSection(&dice, 5), 25, testNum++);
    TestAssert_UInt(ScoreAsTopSection(&dice, 6), 0, testNum++);
    SetDice(&dice, 6, 6, 6, 6, 6);
    TestAssert_UInt(ScoreAsTopSection(&dice, 6), 30, testNum++);
    TestAssert_UInt(ScoreAsTopSection(&dice, 1), 0, testNum++);

    SetDice(&dice, 1, 2, 4, 5, 6);
    TestAssert_UInt(ScoreAsTopSection(&dice, 1), 1, testNum++);
    TestAssert_UInt(ScoreAsTopSection(&dice, 2), 2, testNum++);
    TestAssert_UInt(ScoreAsTopSection(&dice, 4), 4, testNum++);
    TestAssert_UInt(ScoreAsTopSection(&dice, 5), 5, testNum++);
    TestAssert_UInt(ScoreAsTopSection(&dice, 6), 6, testNum++);
    TestAssert_UInt(ScoreAsTopSection(&dice, 3), 0, testNum++);

    SetDice(&dice, 2, 2, 4, 4, 4);
    TestAssert_UInt(ScoreAsTopSection(&dice, 2), 4, testNum++);
    TestAssert_UInt(ScoreAsTopSection(&dice, 4), 12, testNum++);
}

//-----------------------------------------------
// Lower section tests
//-----------------------------------------------

// Test_ScoreAsThreeOfAKind
// Inputs: test number base
// Outputs: none, but test failures will be printed to stdout
//
// Unit tests for the yahtzeeScorer routine ScoreAsThreeOfAKind().
// The first test will have id number 'testNum', the second
// test 'testNum+1', etc.
void Test_ScoreAsThreeOfAKind(unsigned int testNum)
{
    FiveDiceType dice;

    SetDice(&dice, 1, 1, 1, 1, 1);
    TestAssert_UInt(ScoreAsThreeOfAKind(&dice), 5, testNum++);
    SetDice(&dice, 2, 2, 2, 2, 2);
    TestAssert_UInt(ScoreAsThreeOfAKind(&dice), 10, testNum++);
    SetDice(&dice, 3, 3, 3, 3, 3);
    TestAssert_UInt(ScoreAsThreeOfAKind(&dice), 15, testNum++);
    SetDice(&dice, 4, 4, 4, 4, 4);
    TestAssert_UInt(ScoreAsThreeOfAKind(&dice), 20, testNum++);
    SetDice(&dice, 5, 5, 5, 5, 5);
    TestAssert_UInt(ScoreAsThreeOfAKind(&dice), 25, testNum++);
    SetDice(&dice, 6, 6, 6, 6, 6);
    TestAssert_UInt(ScoreAsThreeOfAKind(&dice), 30, testNum++);

    SetDice(&dice, 1, 1, 1, 2, 3);
    TestAssert_UInt(ScoreAsThreeOfAKind(&dice), 8, testNum++);
    SetDice(&dice, 4, 2, 2, 2, 5);
    TestAssert_UInt(ScoreAsThreeOfAKind(&dice), 15, testNum++);
    SetDice(&dice, 1, 2, 3, 3, 3);
    TestAssert_UInt(ScoreAsThreeOfAKind(&dice), 12, testNum++);
    SetDice(&dice, 4, 5, 4, 6, 4);
    TestAssert_UInt(ScoreAsThreeOfAKind(&dice), 23, testNum++);
    SetDice(&dice, 5, 5, 1, 5, 3);
    TestAssert_UInt(ScoreAsThreeOfAKind(&dice), 19, testNum++);
    SetDice(&dice, 4, 6, 6, 5, 6);
    TestAssert_UInt(ScoreAsThreeOfAKind(&dice), 27, testNum++);

    SetDice(&dice, 1, 1, 2, 2, 3);
    TestAssert_UInt(ScoreAsThreeOfAKind(&dice), 0, testNum++);
    SetDice(&dice, 4, 2, 5, 2, 5);
    TestAssert_UInt(ScoreAsThreeOfAKind(&dice), 0, testNum++);
    SetDice(&dice, 1, 4, 6, 4, 1);
    TestAssert_UInt(ScoreAsThreeOfAKind(&dice), 0, testNum++);
    SetDice(&dice, 1, 2, 3, 4, 4);
    TestAssert_UInt(ScoreAsThreeOfAKind(&dice), 0, testNum++);
    SetDice(&dice, 1, 2, 3, 4, 5);
    TestAssert_UInt(ScoreAsThreeOfAKind(&dice), 0, testNum++);
    SetDice(&dice, 5, 3, 2, 6, 1);
    TestAssert_UInt(ScoreAsThreeOfAKind(&dice), 0, testNum++);
}

// Test_ScoreAsFourOfAKind
// Inputs: test number base
// Outputs: none, but test failures will be printed to stdout
//
// Unit tests for the yahtzeeScorer routine ScoreAsFourOfAKind().
// The first test will have id number 'testNum', the second
// test 'testNum+1', etc.
void Test_ScoreAsFourOfAKind(unsigned int testNum)
{
    FiveDiceType dice;

    SetDice(&dice, 1, 1, 1, 1, 1);
    TestAssert_UInt(ScoreAsFourOfAKind(&dice), 5, testNum++);
    SetDice(&dice, 2, 2, 2, 2, 2);
    TestAssert_UInt(ScoreAsFourOfAKind(&dice), 10, testNum++);
    SetDice(&dice, 3, 3, 3, 3, 3);
    TestAssert_UInt(ScoreAsFourOfAKind(&dice), 15, testNum++);
    SetDice(&dice, 4, 4, 4, 4, 4);
    TestAssert_UInt(ScoreAsFourOfAKind(&dice), 20, testNum++);
    SetDice(&dice, 5, 5, 5, 5, 5);
    TestAssert_UInt(ScoreAsFourOfAKind(&dice), 25, testNum++);
    SetDice(&dice, 6, 6, 6, 6, 6);
    TestAssert_UInt(ScoreAsFourOfAKind(&dice), 30, testNum++);

    SetDice(&dice, 1, 1, 1, 1, 3);
    TestAssert_UInt(ScoreAsFourOfAKind(&dice), 7, testNum++);
    SetDice(&dice, 2, 2, 2, 5, 2);
    TestAssert_UInt(ScoreAsFourOfAKind(&dice), 13, testNum++);
    SetDice(&dice, 3, 3, 6, 3, 3);
    TestAssert_UInt(ScoreAsFourOfAKind(&dice), 18, testNum++);
    SetDice(&dice, 4, 1, 4, 4, 4);
    TestAssert_UInt(ScoreAsFourOfAKind(&dice), 17, testNum++);
    SetDice(&dice, 3, 5, 5, 5, 5);
    TestAssert_UInt(ScoreAsFourOfAKind(&dice), 23, testNum++);

    SetDice(&dice, 1, 1, 1, 2, 3);
    TestAssert_UInt(ScoreAsFourOfAKind(&dice), 0, testNum++);
    SetDice(&dice, 4, 2, 2, 2, 5);
    TestAssert_UInt(ScoreAsFourOfAKind(&dice), 0, testNum++);
    SetDice(&dice, 1, 2, 3, 3, 3);
    TestAssert_UInt(ScoreAsFourOfAKind(&dice), 0, testNum++);
    SetDice(&dice, 4, 5, 4, 6, 4);
    TestAssert_UInt(ScoreAsFourOfAKind(&dice), 0, testNum++);
    SetDice(&dice, 5, 5, 1, 5, 3);
    TestAssert_UInt(ScoreAsFourOfAKind(&dice), 0, testNum++);
    SetDice(&dice, 4, 6, 6, 5, 6);
    TestAssert_UInt(ScoreAsFourOfAKind(&dice), 0, testNum++);

    SetDice(&dice, 1, 1, 2, 2, 3);
    TestAssert_UInt(ScoreAsFourOfAKind(&dice), 0, testNum++);
    SetDice(&dice, 4, 2, 5, 2, 5);
    TestAssert_UInt(ScoreAsFourOfAKind(&dice), 0, testNum++);
    SetDice(&dice, 1, 4, 6, 4, 1);
    TestAssert_UInt(ScoreAsFourOfAKind(&dice), 0, testNum++);
    SetDice(&dice, 1, 2, 3, 4, 4);
    TestAssert_UInt(ScoreAsFourOfAKind(&dice), 0, testNum++);
    SetDice(&dice, 1, 2, 3, 4, 5);
    TestAssert_UInt(ScoreAsFourOfAKind(&dice), 0, testNum++);
    SetDice(&dice, 5, 3, 2, 6, 1);
    TestAssert_UInt(ScoreAsFourOfAKind(&dice), 0, testNum++);
}

// Test_ScoreAsFullHouse
// Inputs: test number base
// Outputs: none, but test failures will be printed to stdout
//
// Unit tests for the yahtzeeScorer routine ScoreAsFullHouse().
// The first test will have id number 'testNum', the second
// test 'testNum+1', etc.
void Test_ScoreAsFullHouse(unsigned int testNum)
{
    FiveDiceType dice;

    SetDice(&dice, 1, 1, 1, 1, 1);
    TestAssert_UInt(ScoreAsFullHouse(&dice), 0, testNum++);
    SetDice(&dice, 2, 2, 2, 2, 2);
    TestAssert_UInt(ScoreAsFullHouse(&dice), 0, testNum++);
    SetDice(&dice, 3, 3, 3, 3, 3);
    TestAssert_UInt(ScoreAsFullHouse(&dice), 0, testNum++);
    SetDice(&dice, 4, 4, 4, 4, 4);
    TestAssert_UInt(ScoreAsFullHouse(&dice), 0, testNum++);
    SetDice(&dice, 5, 5, 5, 5, 5);
    TestAssert_UInt(ScoreAsFullHouse(&dice), 0, testNum++);
    SetDice(&dice, 6, 6, 6, 6, 6);
    TestAssert_UInt(ScoreAsFullHouse(&dice), 0, testNum++);

    SetDice(&dice, 1, 1, 1, 1, 3);
    TestAssert_UInt(ScoreAsFullHouse(&dice), 0, testNum++);
    SetDice(&dice, 2, 2, 2, 5, 2);
    TestAssert_UInt(ScoreAsFullHouse(&dice), 0, testNum++);
    SetDice(&dice, 3, 3, 6, 3, 3);
    TestAssert_UInt(ScoreAsFullHouse(&dice), 0, testNum++);
    SetDice(&dice, 4, 1, 4, 4, 4);
    TestAssert_UInt(ScoreAsFullHouse(&dice), 0, testNum++);
    SetDice(&dice, 3, 5, 5, 5, 5);
    TestAssert_UInt(ScoreAsFullHouse(&dice), 0, testNum++);

    SetDice(&dice, 1, 1, 1, 2, 3);
    TestAssert_UInt(ScoreAsFullHouse(&dice), 0, testNum++);
    SetDice(&dice, 4, 2, 2, 2, 5);
    TestAssert_UInt(ScoreAsFullHouse(&dice), 0, testNum++);
    SetDice(&dice, 1, 2, 3, 3, 3);
    TestAssert_UInt(ScoreAsFullHouse(&dice), 0, testNum++);
    SetDice(&dice, 4, 5, 4, 6, 4);
    TestAssert_UInt(ScoreAsFullHouse(&dice), 0, testNum++);
    SetDice(&dice, 5, 5, 1, 5, 3);
    TestAssert_UInt(ScoreAsFullHouse(&dice), 0, testNum++);
    SetDice(&dice, 4, 6, 6, 5, 6);
    TestAssert_UInt(ScoreAsFullHouse(&dice), 0, testNum++);

    SetDice(&dice, 1, 1, 1, 2, 2);
    TestAssert_UInt(ScoreAsFullHouse(&dice), 25, testNum++);
    SetDice(&dice, 4, 2, 2, 2, 4);
    TestAssert_UInt(ScoreAsFullHouse(&dice), 25, testNum++);
    SetDice(&dice, 6, 6, 3, 3, 3);
    TestAssert_UInt(ScoreAsFullHouse(&dice), 25, testNum++);
    SetDice(&dice, 4, 3, 4, 3, 4);
    TestAssert_UInt(ScoreAsFullHouse(&dice), 25, testNum++);
    SetDice(&dice, 5, 5, 1, 5, 1);
    TestAssert_UInt(ScoreAsFullHouse(&dice), 25, testNum++);
    SetDice(&dice, 4, 6, 6, 4, 6);
    TestAssert_UInt(ScoreAsFullHouse(&dice), 25, testNum++);
}

// Test_ScoreAsSmallStraight
// Inputs: test number base
// Outputs: none, but test failures will be printed to stdout
//
// Unit tests for the yahtzeeScorer routine ScoreAsSmallStraight().
// The first test will have id number 'testNum', the second
// test 'testNum+1', etc.
void Test_ScoreAsSmallStraight(unsigned int testNum)
{
    FiveDiceType dice;

    SetDice(&dice, 1, 1, 1, 1, 1);
    TestAssert_UInt(ScoreAsSmallStraight(&dice), 0, testNum++);
    SetDice(&dice, 2, 2, 2, 2, 2);
    TestAssert_UInt(ScoreAsSmallStraight(&dice), 0, testNum++);
    SetDice(&dice, 3, 3, 3, 3, 3);
    TestAssert_UInt(ScoreAsSmallStraight(&dice), 0, testNum++);
    SetDice(&dice, 4, 4, 4, 4, 4);
    TestAssert_UInt(ScoreAsSmallStraight(&dice), 0, testNum++);
    SetDice(&dice, 5, 5, 5, 5, 5);
    TestAssert_UInt(ScoreAsSmallStraight(&dice), 0, testNum++);
    SetDice(&dice, 6, 6, 6, 6, 6);
    TestAssert_UInt(ScoreAsSmallStraight(&dice), 0, testNum++);

    SetDice(&dice, 1, 1, 1, 1, 3);
    TestAssert_UInt(ScoreAsSmallStraight(&dice), 0, testNum++);
    SetDice(&dice, 2, 2, 2, 5, 2);
    TestAssert_UInt(ScoreAsSmallStraight(&dice), 0, testNum++);
    SetDice(&dice, 3, 3, 6, 3, 3);
    TestAssert_UInt(ScoreAsSmallStraight(&dice), 0, testNum++);
    SetDice(&dice, 4, 1, 4, 4, 4);
    TestAssert_UInt(ScoreAsSmallStraight(&dice), 0, testNum++);
    SetDice(&dice, 3, 5, 5, 5, 5);
    TestAssert_UInt(ScoreAsSmallStraight(&dice), 0, testNum++);

    SetDice(&dice, 1, 1, 1, 2, 3);
    TestAssert_UInt(ScoreAsSmallStraight(&dice), 0, testNum++);
    SetDice(&dice, 4, 2, 2, 2, 5);
    TestAssert_UInt(ScoreAsSmallStraight(&dice), 0, testNum++);
    SetDice(&dice, 1, 2, 3, 3, 3);
    TestAssert_UInt(ScoreAsSmallStraight(&dice), 0, testNum++);
    SetDice(&dice, 4, 5, 4, 6, 4);
    TestAssert_UInt(ScoreAsSmallStraight(&dice), 0, testNum++);
    SetDice(&dice, 5, 5, 1, 5, 3);
    TestAssert_UInt(ScoreAsSmallStraight(&dice), 0, testNum++);
    SetDice(&dice, 4, 6, 6, 5, 6);
    TestAssert_UInt(ScoreAsSmallStraight(&dice), 0, testNum++);

    SetDice(&dice, 1, 1, 1, 2, 2);
    TestAssert_UInt(ScoreAsSmallStraight(&dice), 0, testNum++);
    SetDice(&dice, 4, 2, 2, 2, 4);
    TestAssert_UInt(ScoreAsSmallStraight(&dice), 0, testNum++);
    SetDice(&dice, 6, 6, 3, 3, 3);
    TestAssert_UInt(ScoreAsSmallStraight(&dice), 0, testNum++);
    SetDice(&dice, 4, 3, 4, 3, 4);
    TestAssert_UInt(ScoreAsSmallStraight(&dice), 0, testNum++);
    SetDice(&dice, 5, 5, 1, 5, 1);
    TestAssert_UInt(ScoreAsSmallStraight(&dice), 0, testNum++);
    SetDice(&dice, 4, 6, 6, 4, 6);
    TestAssert_UInt(ScoreAsSmallStraight(&dice), 0, testNum++);

    SetDice(&dice, 1, 2, 3, 4, 5);
    TestAssert_UInt(ScoreAsSmallStraight(&dice), 30, testNum++);
    SetDice(&dice, 1, 2, 6, 3, 4);
    TestAssert_UInt(ScoreAsSmallStraight(&dice), 30, testNum++);
    SetDice(&dice, 4, 2, 3, 1, 1);
    TestAssert_UInt(ScoreAsSmallStraight(&dice), 30, testNum++);
    SetDice(&dice, 2, 3, 4, 5, 6);
    TestAssert_UInt(ScoreAsSmallStraight(&dice), 30, testNum++);
    SetDice(&dice, 1, 3, 4, 5, 2);
    TestAssert_UInt(ScoreAsSmallStraight(&dice), 30, testNum++);
    SetDice(&dice, 2, 3, 3, 5, 4);
    TestAssert_UInt(ScoreAsSmallStraight(&dice), 30, testNum++);
    SetDice(&dice, 3, 4, 5, 6, 2);
    TestAssert_UInt(ScoreAsSmallStraight(&dice), 30, testNum++);
    SetDice(&dice, 1, 3, 4, 5, 6);
    TestAssert_UInt(ScoreAsSmallStraight(&dice), 30, testNum++);
    SetDice(&dice, 6, 5, 4, 3, 5);
    TestAssert_UInt(ScoreAsSmallStraight(&dice), 30, testNum++);
}

// Test_ScoreAsLargeStraight
// Inputs: test number base
// Outputs: none, but test failures will be printed to stdout
//
// Unit tests for the yahtzeeScorer routine ScoreAsLargeStraight().
// The first test will have id number 'testNum', the second
// test 'testNum+1', etc.
void Test_ScoreAsLargeStraight(unsigned int testNum)
{
    FiveDiceType dice;

    SetDice(&dice, 1, 1, 1, 1, 1);
    TestAssert_UInt(ScoreAsLargeStraight(&dice), 0, testNum++);
    SetDice(&dice, 2, 2, 2, 2, 2);
    TestAssert_UInt(ScoreAsLargeStraight(&dice), 0, testNum++);
    SetDice(&dice, 3, 3, 3, 3, 3);
    TestAssert_UInt(ScoreAsLargeStraight(&dice), 0, testNum++);
    SetDice(&dice, 4, 4, 4, 4, 4);
    TestAssert_UInt(ScoreAsLargeStraight(&dice), 0, testNum++);
    SetDice(&dice, 5, 5, 5, 5, 5);
    TestAssert_UInt(ScoreAsLargeStraight(&dice), 0, testNum++);
    SetDice(&dice, 6, 6, 6, 6, 6);
    TestAssert_UInt(ScoreAsLargeStraight(&dice), 0, testNum++);

    SetDice(&dice, 1, 1, 1, 1, 3);
    TestAssert_UInt(ScoreAsLargeStraight(&dice), 0, testNum++);
    SetDice(&dice, 2, 2, 2, 5, 2);
    TestAssert_UInt(ScoreAsLargeStraight(&dice), 0, testNum++);
    SetDice(&dice, 3, 3, 6, 3, 3);
    TestAssert_UInt(ScoreAsLargeStraight(&dice), 0, testNum++);
    SetDice(&dice, 4, 1, 4, 4, 4);
    TestAssert_UInt(ScoreAsLargeStraight(&dice), 0, testNum++);
    SetDice(&dice, 3, 5, 5, 5, 5);
    TestAssert_UInt(ScoreAsLargeStraight(&dice), 0, testNum++);

    SetDice(&dice, 1, 1, 1, 2, 3);
    TestAssert_UInt(ScoreAsLargeStraight(&dice), 0, testNum++);
    SetDice(&dice, 4, 2, 2, 2, 5);
    TestAssert_UInt(ScoreAsLargeStraight(&dice), 0, testNum++);
    SetDice(&dice, 1, 2, 3, 3, 3);
    TestAssert_UInt(ScoreAsLargeStraight(&dice), 0, testNum++);
    SetDice(&dice, 4, 5, 4, 6, 4);
    TestAssert_UInt(ScoreAsLargeStraight(&dice), 0, testNum++);
    SetDice(&dice, 5, 5, 1, 5, 3);
    TestAssert_UInt(ScoreAsLargeStraight(&dice), 0, testNum++);
    SetDice(&dice, 4, 6, 6, 5, 6);
    TestAssert_UInt(ScoreAsLargeStraight(&dice), 0, testNum++);

    SetDice(&dice, 1, 1, 1, 2, 2);
    TestAssert_UInt(ScoreAsLargeStraight(&dice), 0, testNum++);
    SetDice(&dice, 4, 2, 2, 2, 4);
    TestAssert_UInt(ScoreAsLargeStraight(&dice), 0, testNum++);
    SetDice(&dice, 6, 6, 3, 3, 3);
    TestAssert_UInt(ScoreAsLargeStraight(&dice), 0, testNum++);
    SetDice(&dice, 4, 3, 4, 3, 4);
    TestAssert_UInt(ScoreAsLargeStraight(&dice), 0, testNum++);
    SetDice(&dice, 5, 5, 1, 5, 1);
    TestAssert_UInt(ScoreAsLargeStraight(&dice), 0, testNum++);
    SetDice(&dice, 4, 6, 6, 4, 6);
    TestAssert_UInt(ScoreAsLargeStraight(&dice), 0, testNum++);

    SetDice(&dice, 1, 2, 3, 4, 5);
    TestAssert_UInt(ScoreAsLargeStraight(&dice), 40, testNum++);
    SetDice(&dice, 5, 4, 3, 2, 1);
    TestAssert_UInt(ScoreAsLargeStraight(&dice), 40, testNum++);
    SetDice(&dice, 1, 3, 5, 4, 2);
    TestAssert_UInt(ScoreAsLargeStraight(&dice), 40, testNum++);
    SetDice(&dice, 1, 5, 3, 2, 4);
    TestAssert_UInt(ScoreAsLargeStraight(&dice), 40, testNum++);

    SetDice(&dice, 2, 3, 4, 5, 6);
    TestAssert_UInt(ScoreAsLargeStraight(&dice), 40, testNum++);
    SetDice(&dice, 6, 5, 4, 3, 2);
    TestAssert_UInt(ScoreAsLargeStraight(&dice), 40, testNum++);
    SetDice(&dice, 3, 4, 5, 6, 2);
    TestAssert_UInt(ScoreAsLargeStraight(&dice), 40, testNum++);
    SetDice(&dice, 2, 4, 6, 3, 5);
    TestAssert_UInt(ScoreAsLargeStraight(&dice), 40, testNum++);

    SetDice(&dice, 1, 2, 6, 3, 4);
    TestAssert_UInt(ScoreAsLargeStraight(&dice), 0, testNum++);
    SetDice(&dice, 4, 2, 3, 1, 1);
    TestAssert_UInt(ScoreAsLargeStraight(&dice), 0, testNum++);
    SetDice(&dice, 2, 3, 3, 5, 4);
    TestAssert_UInt(ScoreAsLargeStraight(&dice), 0, testNum++);
    SetDice(&dice, 1, 3, 4, 5, 6);
    TestAssert_UInt(ScoreAsLargeStraight(&dice), 0, testNum++);
    SetDice(&dice, 6, 5, 4, 3, 5);
    TestAssert_UInt(ScoreAsLargeStraight(&dice), 0, testNum++);
}

// Test_ScoreAsYahtzee
// Inputs: test number base
// Outputs: none, but test failures will be printed to stdout
//
// Unit tests for the yahtzeeScorer routine ScoreAsYahtzee().
// The first test will have id number 'testNum', the second
// test 'testNum+1', etc.
void Test_ScoreAsYahtzee(unsigned int testNum)
{
    FiveDiceType dice;

    SetDice(&dice, 1, 1, 1, 1, 1);
    TestAssert_UInt(ScoreAsYahtzee(&dice), 50, testNum++);
    SetDice(&dice, 2, 2, 2, 2, 2);
    TestAssert_UInt(ScoreAsYahtzee(&dice), 50, testNum++);
    SetDice(&dice, 3, 3, 3, 3, 3);
    TestAssert_UInt(ScoreAsYahtzee(&dice), 50, testNum++);
    SetDice(&dice, 4, 4, 4, 4, 4);
    TestAssert_UInt(ScoreAsYahtzee(&dice), 50, testNum++);
    SetDice(&dice, 5, 5, 5, 5, 5);
    TestAssert_UInt(ScoreAsYahtzee(&dice), 50, testNum++);
    SetDice(&dice, 6, 6, 6, 6, 6);
    TestAssert_UInt(ScoreAsYahtzee(&dice), 50, testNum++);

    SetDice(&dice, 1, 1, 1, 1, 3);
    TestAssert_UInt(ScoreAsYahtzee(&dice), 0, testNum++);
    SetDice(&dice, 2, 2, 2, 5, 2);
    TestAssert_UInt(ScoreAsYahtzee(&dice), 0, testNum++);
    SetDice(&dice, 3, 3, 6, 3, 3);
    TestAssert_UInt(ScoreAsYahtzee(&dice), 0, testNum++);
    SetDice(&dice, 4, 1, 4, 4, 4);
    TestAssert_UInt(ScoreAsYahtzee(&dice), 0, testNum++);
    SetDice(&dice, 3, 5, 5, 5, 5);
    TestAssert_UInt(ScoreAsYahtzee(&dice), 0, testNum++);

    SetDice(&dice, 1, 1, 1, 2, 3);
    TestAssert_UInt(ScoreAsYahtzee(&dice), 0, testNum++);
    SetDice(&dice, 4, 2, 2, 2, 5);
    TestAssert_UInt(ScoreAsYahtzee(&dice), 0, testNum++);
    SetDice(&dice, 1, 2, 3, 3, 3);
    TestAssert_UInt(ScoreAsYahtzee(&dice), 0, testNum++);
    SetDice(&dice, 4, 5, 4, 6, 4);
    TestAssert_UInt(ScoreAsYahtzee(&dice), 0, testNum++);
    SetDice(&dice, 5, 5, 1, 5, 3);
    TestAssert_UInt(ScoreAsYahtzee(&dice), 0, testNum++);
    SetDice(&dice, 4, 6, 6, 5, 6);
    TestAssert_UInt(ScoreAsYahtzee(&dice), 0, testNum++);

    SetDice(&dice, 1, 1, 1, 2, 2);
    TestAssert_UInt(ScoreAsYahtzee(&dice), 0, testNum++);
    SetDice(&dice, 4, 2, 2, 2, 4);
    TestAssert_UInt(ScoreAsYahtzee(&dice), 0, testNum++);
    SetDice(&dice, 6, 6, 3, 3, 3);
    TestAssert_UInt(ScoreAsYahtzee(&dice), 0, testNum++);
    SetDice(&dice, 4, 3, 4, 3, 4);
    TestAssert_UInt(ScoreAsYahtzee(&dice), 0, testNum++);
    SetDice(&dice, 5, 5, 1, 5, 1);
    TestAssert_UInt(ScoreAsYahtzee(&dice), 0, testNum++);
    SetDice(&dice, 4, 6, 6, 4, 6);
    TestAssert_UInt(ScoreAsYahtzee(&dice), 0, testNum++);
}

// Test_ScoreAsChance
// Inputs: test number base
// Outputs: none, but test failures will be printed to stdout
//
// Unit tests for the yahtzeeScorer routine ScoreAsChance().
// The first test will have id number 'testNum', the second
// test 'testNum+1', etc.
void Test_ScoreAsChance(unsigned int testNum)
{
    FiveDiceType dice;

    SetDice(&dice, 1, 1, 1, 1, 1);
    TestAssert_UInt(ScoreAsChance(&dice), 5, testNum++);
    SetDice(&dice, 2, 2, 2, 2, 2);
    TestAssert_UInt(ScoreAsChance(&dice), 10, testNum++);
    SetDice(&dice, 3, 3, 3, 3, 3);
    TestAssert_UInt(ScoreAsChance(&dice), 15, testNum++);
    SetDice(&dice, 4, 4, 4, 4, 4);
    TestAssert_UInt(ScoreAsChance(&dice), 20, testNum++);
    SetDice(&dice, 5, 5, 5, 5, 5);
    TestAssert_UInt(ScoreAsChance(&dice), 25, testNum++);
    SetDice(&dice, 6, 6, 6, 6, 6);
    TestAssert_UInt(ScoreAsChance(&dice), 30, testNum++);

    SetDice(&dice, 1, 1, 1, 1, 3);
    TestAssert_UInt(ScoreAsChance(&dice), 7, testNum++);
    SetDice(&dice, 2, 2, 2, 5, 2);
    TestAssert_UInt(ScoreAsChance(&dice), 13, testNum++);
    SetDice(&dice, 3, 3, 6, 3, 3);
    TestAssert_UInt(ScoreAsChance(&dice), 18, testNum++);
    SetDice(&dice, 4, 1, 4, 4, 4);
    TestAssert_UInt(ScoreAsChance(&dice), 17, testNum++);
    SetDice(&dice, 3, 5, 5, 5, 5);
    TestAssert_UInt(ScoreAsChance(&dice), 23, testNum++);

    SetDice(&dice, 1, 1, 1, 2, 3);
    TestAssert_UInt(ScoreAsChance(&dice), 8, testNum++);
    SetDice(&dice, 4, 2, 2, 2, 5);
    TestAssert_UInt(ScoreAsChance(&dice), 15, testNum++);
    SetDice(&dice, 1, 2, 3, 3, 3);
    TestAssert_UInt(ScoreAsChance(&dice), 12, testNum++);
    SetDice(&dice, 4, 5, 4, 6, 4);
    TestAssert_UInt(ScoreAsChance(&dice), 23, testNum++);
    SetDice(&dice, 5, 5, 1, 5, 3);
    TestAssert_UInt(ScoreAsChance(&dice), 19, testNum++);
    SetDice(&dice, 4, 6, 6, 5, 6);
    TestAssert_UInt(ScoreAsChance(&dice), 27, testNum++);

    SetDice(&dice, 1, 1, 1, 2, 2);
    TestAssert_UInt(ScoreAsChance(&dice), 7, testNum++);
    SetDice(&dice, 4, 2, 2, 2, 4);
    TestAssert_UInt(ScoreAsChance(&dice), 14, testNum++);
    SetDice(&dice, 6, 6, 3, 3, 3);
    TestAssert_UInt(ScoreAsChance(&dice), 21, testNum++);
    SetDice(&dice, 4, 3, 4, 3, 4);
    TestAssert_UInt(ScoreAsChance(&dice), 18, testNum++);
    SetDice(&dice, 5, 5, 1, 5, 1);
    TestAssert_UInt(ScoreAsChance(&dice), 17, testNum++);
    SetDice(&dice, 4, 6, 6, 4, 6);
    TestAssert_UInt(ScoreAsChance(&dice), 26, testNum++);

    SetDice(&dice, 1, 2, 3, 4, 5);
    TestAssert_UInt(ScoreAsChance(&dice), 15, testNum++);
    SetDice(&dice, 5, 4, 3, 2, 1);
    TestAssert_UInt(ScoreAsChance(&dice), 15, testNum++);
    SetDice(&dice, 1, 3, 5, 4, 2);
    TestAssert_UInt(ScoreAsChance(&dice), 15, testNum++);
    SetDice(&dice, 1, 5, 3, 2, 4);
    TestAssert_UInt(ScoreAsChance(&dice), 15, testNum++);

    SetDice(&dice, 2, 3, 4, 5, 6);
    TestAssert_UInt(ScoreAsChance(&dice), 20, testNum++);
    SetDice(&dice, 6, 5, 4, 3, 2);
    TestAssert_UInt(ScoreAsChance(&dice), 20, testNum++);
    SetDice(&dice, 3, 4, 5, 6, 2);
    TestAssert_UInt(ScoreAsChance(&dice), 20, testNum++);
    SetDice(&dice, 2, 4, 6, 3, 5);
    TestAssert_UInt(ScoreAsChance(&dice), 20, testNum++);

    SetDice(&dice, 1, 2, 6, 3, 4);
    TestAssert_UInt(ScoreAsChance(&dice), 16, testNum++);
    SetDice(&dice, 4, 2, 3, 1, 1);
    TestAssert_UInt(ScoreAsChance(&dice), 11, testNum++);
    SetDice(&dice, 2, 3, 3, 5, 4);
    TestAssert_UInt(ScoreAsChance(&dice), 17, testNum++);
    SetDice(&dice, 1, 3, 4, 5, 6);
    TestAssert_UInt(ScoreAsChance(&dice), 19, testNum++);
    SetDice(&dice, 6, 5, 4, 3, 5);
    TestAssert_UInt(ScoreAsChance(&dice), 23, testNum++);
}

//-----------------------------------------------
// Helper routines
//-----------------------------------------------

// SetDice
// Inputs: a pointer to a dice structure, plus 5 dice values
// Outputs: none, but the dice structure is updated
//
// Updates the dice structure to coontain the five dice values
void SetDice(FiveDiceType * dice, unsigned int d1, unsigned int d2,
                 unsigned int d3, unsigned int d4, unsigned int d5)
{
    dice->d1 = d1;
    dice->d2 = d2;
    dice->d3 = d3;
    dice->d4 = d4;
    dice->d5 = d5;
}

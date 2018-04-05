//
//  tests_yahtzeeToolbox.c
//  YahtzeeTests
//
//  Created by Emily Eaton on 4/4/18.
//


#include "tests_yahtzeeToolbox.h"
#include "yahtzeeTypes.h"
#include "yahtzeeToolbox.h"
#include "testframework.h"

// Function prototypes for test subroutines
void Test_HowManyOfRank(unsigned int testNum);
void Test_SumOfAllDice(unsigned int testNum);
void Test_RollDice(unsigned int testNum);
void Test_GetRankCounts(unsigned int testNum);
void Test_MostCommonRank(unsigned int testNum);
void Test_MostCommonRankCount(unsigned int testNum);

// Function prototypes for helper routines
void SetDice2(FiveDiceType * dice, unsigned int d1, unsigned int d2,
                 unsigned int d3, unsigned int d4, unsigned int d5);


//-----------------------------------------------
// Top level
//-----------------------------------------------

// Test_YahtzeeToolbox
// Inputs: none
// Outputs: none
//
// Calls the subroutines to test each Yahtzee Toolbox function.
//
// The "testNum" parameter passed to each creates unique codes
// for each test. In a more polished testing setup, each code
// would have an associated string that would report the name
// of the failed test.
void Test_YahtzeeToolbox()
{
    Test_HowManyOfRank(2000);
    Test_SumOfAllDice(2100);
    Test_RollDice(2200);
    Test_GetRankCounts(2300);
    Test_MostCommonRank(2400);
    Test_MostCommonRankCount(2500);
}

//-----------------------------------------------
// Individual tests
//-----------------------------------------------

// Test_HowManyOfRank
// Inputs: test number base
// Outputs: none, but test failures will be printed to stdout
//
// Unit tests for the yahtzeeToolbox routine HowManyOfRank().
// The first test will have id number 'testNum', the second
// test 'testNum+1', etc.
void Test_HowManyOfRank(unsigned int testNum)
{
    FiveDiceType dice;

    SetDice2(&dice, 1, 1, 1, 1, 1);
    TestAssert_UInt(HowManyOfRank(&dice, 1), 5, testNum++);
    TestAssert_UInt(HowManyOfRank(&dice, 2), 0, testNum++);
    SetDice2(&dice, 2, 2, 2, 2, 2);
    TestAssert_UInt(HowManyOfRank(&dice, 2), 5, testNum++);
    TestAssert_UInt(HowManyOfRank(&dice, 3), 0, testNum++);
    SetDice2(&dice, 3, 3, 3, 3, 3);
    TestAssert_UInt(HowManyOfRank(&dice, 3), 5, testNum++);
    TestAssert_UInt(HowManyOfRank(&dice, 4), 0, testNum++);
    SetDice2(&dice, 4, 4, 4, 4, 4);
    TestAssert_UInt(HowManyOfRank(&dice, 4), 5, testNum++);
    TestAssert_UInt(HowManyOfRank(&dice, 5), 0, testNum++);
    SetDice2(&dice, 5, 5, 5, 5, 5);
    TestAssert_UInt(HowManyOfRank(&dice, 5), 5, testNum++);
    TestAssert_UInt(HowManyOfRank(&dice, 6), 0, testNum++);
    SetDice2(&dice, 6, 6, 6, 6, 6);
    TestAssert_UInt(HowManyOfRank(&dice, 6), 5, testNum++);
    TestAssert_UInt(HowManyOfRank(&dice, 1), 0, testNum++);

    SetDice2(&dice, 1, 2, 4, 5, 6);
    TestAssert_UInt(HowManyOfRank(&dice, 1), 1, testNum++);
    TestAssert_UInt(HowManyOfRank(&dice, 2), 1, testNum++);
    TestAssert_UInt(HowManyOfRank(&dice, 3), 0, testNum++);
    TestAssert_UInt(HowManyOfRank(&dice, 4), 1, testNum++);
    TestAssert_UInt(HowManyOfRank(&dice, 5), 1, testNum++);
    TestAssert_UInt(HowManyOfRank(&dice, 6), 1, testNum++);

    SetDice2(&dice, 2, 2, 4, 4, 4);
    TestAssert_UInt(HowManyOfRank(&dice, 1), 0, testNum++);
    TestAssert_UInt(HowManyOfRank(&dice, 2), 2, testNum++);
    TestAssert_UInt(HowManyOfRank(&dice, 3), 0, testNum++);
    TestAssert_UInt(HowManyOfRank(&dice, 4), 3, testNum++);
    TestAssert_UInt(HowManyOfRank(&dice, 5), 0, testNum++);
    TestAssert_UInt(HowManyOfRank(&dice, 6), 0, testNum++);
}

// Test_SumOfAllDice
// Inputs: test number base
// Outputs: none, but test failures will be printed to stdout
//
// Unit tests for the yahtzeeToolbox routine SumOfAllDice().
// The first test will have id number 'testNum', the second
// test 'testNum+1', etc.
void Test_SumOfAllDice(unsigned int testNum)
{
    FiveDiceType dice;

    SetDice2(&dice, 1, 1, 1, 1, 1);
    TestAssert_UInt(SumOfAllDice(&dice), 5, testNum++);
    SetDice2(&dice, 2, 2, 2, 2, 2);
    TestAssert_UInt(SumOfAllDice(&dice), 10, testNum++);
    SetDice2(&dice, 3, 3, 3, 3, 3);
    TestAssert_UInt(SumOfAllDice(&dice), 15, testNum++);
    SetDice2(&dice, 4, 4, 4, 4, 4);
    TestAssert_UInt(SumOfAllDice(&dice), 20, testNum++);
    SetDice2(&dice, 5, 5, 5, 5, 5);
    TestAssert_UInt(SumOfAllDice(&dice), 25, testNum++);
    SetDice2(&dice, 6, 6, 6, 6, 6);
    TestAssert_UInt(SumOfAllDice(&dice), 30, testNum++);

    SetDice2(&dice, 1, 2, 3, 4, 5);
    TestAssert_UInt(SumOfAllDice(&dice), 15, testNum++);
    SetDice2(&dice, 1, 1, 1, 2, 3);
    TestAssert_UInt(SumOfAllDice(&dice), 8, testNum++);
    SetDice2(&dice, 4, 2, 2, 2, 5);
    TestAssert_UInt(SumOfAllDice(&dice), 15, testNum++);
    SetDice2(&dice, 1, 2, 3, 3, 3);
    TestAssert_UInt(SumOfAllDice(&dice), 12, testNum++);
    SetDice2(&dice, 4, 5, 4, 6, 4);
    TestAssert_UInt(SumOfAllDice(&dice), 23, testNum++);
    SetDice2(&dice, 5, 5, 1, 5, 3);
    TestAssert_UInt(SumOfAllDice(&dice), 19, testNum++);
    SetDice2(&dice, 4, 6, 6, 5, 6);
    TestAssert_UInt(SumOfAllDice(&dice), 27, testNum++);
}

// Test_RollDice
// Inputs: test number base
// Outputs: none, but test failures will be printed to stdout
//
// Unit tests for the yahtzeeScorer routine RollDice().
// The first test will have id number 'testNum', the second
// test 'testNum+1', etc.
void Test_RollDice(unsigned int testNum)
{
    FiveDiceType dice;

    SetDice2(&dice, 0, 0, 0, 0, 0);
    RollDice(&dice, false, false, false, false, false);
    TestAssert_Bool(dice.d1==0 && dice.d2==0 && dice.d3==0 && dice.d4==0 && dice.d5==0, true, testNum++);

    SetDice2(&dice, 0, 0, 0, 0, 0);
    RollDice(&dice, true, false, false, false, false);
    TestAssert_Bool(dice.d1!=0 && dice.d2==0 && dice.d3==0 && dice.d4==0 && dice.d5==0, true, testNum++);
    SetDice2(&dice, 0, 0, 0, 0, 0);
    RollDice(&dice, false, true, false, false, false);
    TestAssert_Bool(dice.d1==0 && dice.d2!=0 && dice.d3==0 && dice.d4==0 && dice.d5==0, true, testNum++);
    SetDice2(&dice, 0, 0, 0, 0, 0);
    RollDice(&dice, false, false, true, false, false);
    TestAssert_Bool(dice.d1==0 && dice.d2==0 && dice.d3!=0 && dice.d4==0 && dice.d5==0, true, testNum++);
    SetDice2(&dice, 0, 0, 0, 0, 0);
    RollDice(&dice, false, false, false, true, false);
    TestAssert_Bool(dice.d1==0 && dice.d2==0 && dice.d3==0 && dice.d4!=0 && dice.d5==0, true, testNum++);
    SetDice2(&dice, 0, 0, 0, 0, 0);
    RollDice(&dice, false, false, false, false, true);
    TestAssert_Bool(dice.d1==0 && dice.d2==0 && dice.d3==0 && dice.d4==0 && dice.d5!=0, true, testNum++);

    SetDice2(&dice, 0, 0, 0, 0, 0);
    RollDice(&dice, true, true, true, true, true);
    TestAssert_Bool(dice.d1!=0 && dice.d2!=0 && dice.d3!=0 && dice.d4!=0 && dice.d5!=0, true, testNum++);

    SetDice2(&dice, 0, 0, 0, 0, 0);
    RollDice(&dice, false, true, true, true, true);
    TestAssert_Bool(dice.d1==0 && dice.d2!=0 && dice.d3!=0 && dice.d4!=0 && dice.d5!=0, true, testNum++);
    SetDice2(&dice, 0, 0, 0, 0, 0);
    RollDice(&dice, true, false, true, true, true);
    TestAssert_Bool(dice.d1!=0 && dice.d2==0 && dice.d3!=0 && dice.d4!=0 && dice.d5!=0, true, testNum++);
    SetDice2(&dice, 0, 0, 0, 0, 0);
    RollDice(&dice, true, true, false, true, true);
    TestAssert_Bool(dice.d1!=0 && dice.d2!=0 && dice.d3==0 && dice.d4!=0 && dice.d5!=0, true, testNum++);
    SetDice2(&dice, 0, 0, 0, 0, 0);
    RollDice(&dice, true, true, true, false, true);
    TestAssert_Bool(dice.d1!=0 && dice.d2!=0 && dice.d3!=0 && dice.d4==0 && dice.d5!=0, true, testNum++);
    SetDice2(&dice, 0, 0, 0, 0, 0);
    RollDice(&dice, true, true, true, true, false);
    TestAssert_Bool(dice.d1!=0 && dice.d2!=0 && dice.d3!=0 && dice.d4!=0 && dice.d5==0, true, testNum++);

    SetDice2(&dice, 0, 0, 0, 0, 0);
    RollDice(&dice, true, false, true, false, true);
    TestAssert_Bool(dice.d1!=0 && dice.d2==0 && dice.d3!=0 && dice.d4==0 && dice.d5!=0, true, testNum++);
    SetDice2(&dice, 0, 0, 0, 0, 0);
    RollDice(&dice, false, true, false, true, false);
    TestAssert_Bool(dice.d1==0 && dice.d2!=0 && dice.d3==0 && dice.d4!=0 && dice.d5==0, true, testNum++);
}

// Test_GetRankCounts
// Inputs: test number base
// Outputs: none, but test failures will be printed to stdout
//
// Unit tests for the yahtzeeScorer routine GetRankCounts().
// The first test will have id number 'testNum', the second
// test 'testNum+1', etc.
void Test_GetRankCounts(unsigned int testNum)
{
    FiveDiceType dice;
    DiceCountsType c;

    SetDice2(&dice, 1, 1, 1, 1, 1);
    GetRankCounts(&dice, &c);
    TestAssert_Bool(c.nOnes==5 && c.nTwos==0 && c.nThrees==0 && c.nFours==0 && c.nFives==0 && c.nSixes==0, true, testNum++);
    SetDice2(&dice, 2, 2, 2, 2, 2);
    GetRankCounts(&dice, &c);
    TestAssert_Bool(c.nOnes==0 && c.nTwos==5 && c.nThrees==0 && c.nFours==0 && c.nFives==0 && c.nSixes==0, true, testNum++);
    SetDice2(&dice, 3, 3, 3, 3, 3);
    GetRankCounts(&dice, &c);
    TestAssert_Bool(c.nOnes==0 && c.nTwos==0 && c.nThrees==5 && c.nFours==0 && c.nFives==0 && c.nSixes==0, true, testNum++);
    SetDice2(&dice, 4, 4, 4, 4, 4);
    GetRankCounts(&dice, &c);
    TestAssert_Bool(c.nOnes==0 && c.nTwos==0 && c.nThrees==0 && c.nFours==5 && c.nFives==0 && c.nSixes==0, true, testNum++);
    SetDice2(&dice, 5, 5, 5, 5, 5);
    GetRankCounts(&dice, &c);
    TestAssert_Bool(c.nOnes==0 && c.nTwos==0 && c.nThrees==0 && c.nFours==0 && c.nFives==5 && c.nSixes==0, true, testNum++);
    SetDice2(&dice, 6, 6, 6, 6, 6);
    GetRankCounts(&dice, &c);
    TestAssert_Bool(c.nOnes==0 && c.nTwos==0 && c.nThrees==0 && c.nFours==0 && c.nFives==0 && c.nSixes==5, true, testNum++);

    SetDice2(&dice, 1, 1, 1, 1, 3);
    GetRankCounts(&dice, &c);
    TestAssert_Bool(c.nOnes==4 && c.nTwos==0 && c.nThrees==1 && c.nFours==0 && c.nFives==0 && c.nSixes==0, true, testNum++);
    SetDice2(&dice, 2, 2, 2, 5, 2);
    GetRankCounts(&dice, &c);
    TestAssert_Bool(c.nOnes==0 && c.nTwos==4 && c.nThrees==0 && c.nFours==0 && c.nFives==1 && c.nSixes==0, true, testNum++);
    SetDice2(&dice, 3, 3, 6, 3, 3);
    GetRankCounts(&dice, &c);
    TestAssert_Bool(c.nOnes==0 && c.nTwos==0 && c.nThrees==4 && c.nFours==0 && c.nFives==0 && c.nSixes==1, true, testNum++);
    SetDice2(&dice, 4, 1, 4, 4, 4);
    GetRankCounts(&dice, &c);
    TestAssert_Bool(c.nOnes==1 && c.nTwos==0 && c.nThrees==0 && c.nFours==4 && c.nFives==0 && c.nSixes==0, true, testNum++);
    SetDice2(&dice, 3, 5, 5, 5, 5);
    GetRankCounts(&dice, &c);
    TestAssert_Bool(c.nOnes==0 && c.nTwos==0 && c.nThrees==1 && c.nFours==0 && c.nFives==4 && c.nSixes==0, true, testNum++);
    SetDice2(&dice, 4, 6, 6, 6, 6);
    GetRankCounts(&dice, &c);
    TestAssert_Bool(c.nOnes==0 && c.nTwos==0 && c.nThrees==0 && c.nFours==1 && c.nFives==0 && c.nSixes==4, true, testNum++);

    SetDice2(&dice, 1, 1, 1, 2, 3);
    GetRankCounts(&dice, &c);
    TestAssert_Bool(c.nOnes==3 && c.nTwos==1 && c.nThrees==1 && c.nFours==0 && c.nFives==0 && c.nSixes==0, true, testNum++);
    SetDice2(&dice, 4, 2, 2, 2, 5);
    GetRankCounts(&dice, &c);
    TestAssert_Bool(c.nOnes==0 && c.nTwos==3 && c.nThrees==0 && c.nFours==1 && c.nFives==1 && c.nSixes==0, true, testNum++);
    SetDice2(&dice, 1, 2, 3, 3, 3);
    GetRankCounts(&dice, &c);
    TestAssert_Bool(c.nOnes==1 && c.nTwos==1 && c.nThrees==3 && c.nFours==0 && c.nFives==0 && c.nSixes==0, true, testNum++);
    SetDice2(&dice, 4, 5, 4, 6, 4);
    GetRankCounts(&dice, &c);
    TestAssert_Bool(c.nOnes==0 && c.nTwos==0 && c.nThrees==0 && c.nFours==3 && c.nFives==1 && c.nSixes==1, true, testNum++);
    SetDice2(&dice, 5, 5, 1, 5, 3);
    GetRankCounts(&dice, &c);
    TestAssert_Bool(c.nOnes==1 && c.nTwos==0 && c.nThrees==1 && c.nFours==0 && c.nFives==3 && c.nSixes==0, true, testNum++);
    SetDice2(&dice, 4, 6, 6, 5, 6);
    GetRankCounts(&dice, &c);
    TestAssert_Bool(c.nOnes==0 && c.nTwos==0 && c.nThrees==0 && c.nFours==1 && c.nFives==1 && c.nSixes==3, true, testNum++);

    SetDice2(&dice, 1, 1, 1, 2, 2);
    GetRankCounts(&dice, &c);
    TestAssert_Bool(c.nOnes==3 && c.nTwos==2 && c.nThrees==0 && c.nFours==0 && c.nFives==0 && c.nSixes==0, true, testNum++);
    SetDice2(&dice, 4, 2, 2, 2, 4);
    GetRankCounts(&dice, &c);
    TestAssert_Bool(c.nOnes==0 && c.nTwos==3 && c.nThrees==0 && c.nFours==2 && c.nFives==0 && c.nSixes==0, true, testNum++);
    SetDice2(&dice, 6, 6, 3, 3, 3);
    GetRankCounts(&dice, &c);
    TestAssert_Bool(c.nOnes==0 && c.nTwos==0 && c.nThrees==3 && c.nFours==0 && c.nFives==0 && c.nSixes==2, true, testNum++);
    SetDice2(&dice, 4, 3, 4, 3, 4);
    GetRankCounts(&dice, &c);
    TestAssert_Bool(c.nOnes==0 && c.nTwos==0 && c.nThrees==2 && c.nFours==3 && c.nFives==0 && c.nSixes==0, true, testNum++);
    SetDice2(&dice, 5, 5, 1, 5, 1);
    GetRankCounts(&dice, &c);
    TestAssert_Bool(c.nOnes==2 && c.nTwos==0 && c.nThrees==0 && c.nFours==0 && c.nFives==3 && c.nSixes==0, true, testNum++);
    SetDice2(&dice, 4, 6, 6, 4, 6);
    GetRankCounts(&dice, &c);
    TestAssert_Bool(c.nOnes==0 && c.nTwos==0 && c.nThrees==0 && c.nFours==2 && c.nFives==0 && c.nSixes==3, true, testNum++);

    SetDice2(&dice, 1, 2, 3, 4, 5);
    GetRankCounts(&dice, &c);
    TestAssert_Bool(c.nOnes==1 && c.nTwos==1 && c.nThrees==1 && c.nFours==1 && c.nFives==1 && c.nSixes==0, true, testNum++);
    SetDice2(&dice, 1, 2, 4, 5, 6);
    GetRankCounts(&dice, &c);
    TestAssert_Bool(c.nOnes==1 && c.nTwos==1 && c.nThrees==0 && c.nFours==1 && c.nFives==1 && c.nSixes==1, true, testNum++);
}

// Test_MostCommonRank
// Inputs: test number base
// Outputs: none, but test failures will be printed to stdout
//
// Unit tests for the yahtzeeScorer routine MostCommonRank().
// The first test will have id number 'testNum', the second
// test 'testNum+1', etc.
void Test_MostCommonRank(unsigned int testNum)
{
    FiveDiceType dice;

    SetDice2(&dice, 1, 1, 1, 1, 1);
    TestAssert_UInt(MostCommonRank(&dice), 1, testNum++);
    SetDice2(&dice, 2, 2, 2, 2, 2);
    TestAssert_UInt(MostCommonRank(&dice), 2, testNum++);
    SetDice2(&dice, 3, 3, 3, 3, 3);
    TestAssert_UInt(MostCommonRank(&dice), 3, testNum++);
    SetDice2(&dice, 4, 4, 4, 4, 4);
    TestAssert_UInt(MostCommonRank(&dice), 4, testNum++);
    SetDice2(&dice, 5, 5, 5, 5, 5);
    TestAssert_UInt(MostCommonRank(&dice), 5, testNum++);
    SetDice2(&dice, 6, 6, 6, 6, 6);
    TestAssert_UInt(MostCommonRank(&dice), 6, testNum++);

    SetDice2(&dice, 1, 1, 1, 1, 3);
    TestAssert_UInt(MostCommonRank(&dice), 1, testNum++);
    SetDice2(&dice, 2, 2, 2, 5, 2);
    TestAssert_UInt(MostCommonRank(&dice), 2, testNum++);
    SetDice2(&dice, 3, 3, 6, 3, 3);
    TestAssert_UInt(MostCommonRank(&dice), 3, testNum++);
    SetDice2(&dice, 4, 1, 4, 4, 4);
    TestAssert_UInt(MostCommonRank(&dice), 4, testNum++);
    SetDice2(&dice, 3, 5, 5, 5, 5);
    TestAssert_UInt(MostCommonRank(&dice), 5, testNum++);
    SetDice2(&dice, 4, 6, 6, 6, 6);
    TestAssert_UInt(MostCommonRank(&dice), 6, testNum++);

    SetDice2(&dice, 1, 1, 1, 2, 3);
    TestAssert_UInt(MostCommonRank(&dice), 1, testNum++);
    SetDice2(&dice, 4, 2, 2, 2, 5);
    TestAssert_UInt(MostCommonRank(&dice), 2, testNum++);
    SetDice2(&dice, 1, 2, 3, 3, 3);
    TestAssert_UInt(MostCommonRank(&dice), 3, testNum++);
    SetDice2(&dice, 4, 5, 4, 6, 4);
    TestAssert_UInt(MostCommonRank(&dice), 4, testNum++);
    SetDice2(&dice, 5, 5, 1, 5, 3);
    TestAssert_UInt(MostCommonRank(&dice), 5, testNum++);
    SetDice2(&dice, 4, 6, 6, 5, 6);
    TestAssert_UInt(MostCommonRank(&dice), 6, testNum++);

    SetDice2(&dice, 1, 1, 3, 2, 2);
    TestAssert_UInt(MostCommonRank(&dice), 0, testNum++);
    SetDice2(&dice, 4, 2, 6, 2, 4);
    TestAssert_UInt(MostCommonRank(&dice), 0, testNum++);
    SetDice2(&dice, 6, 6, 3, 5, 3);
    TestAssert_UInt(MostCommonRank(&dice), 0, testNum++);
    SetDice2(&dice, 4, 3, 4, 3, 1);
    TestAssert_UInt(MostCommonRank(&dice), 0, testNum++);
    SetDice2(&dice, 4, 5, 1, 5, 1);
    TestAssert_UInt(MostCommonRank(&dice), 0, testNum++);
    SetDice2(&dice, 4, 3, 6, 4, 6);
    TestAssert_UInt(MostCommonRank(&dice), 0, testNum++);

    SetDice2(&dice, 1, 2, 3, 4, 5);
    TestAssert_UInt(MostCommonRank(&dice), 0, testNum++);
    SetDice2(&dice, 1, 2, 4, 5, 6);
    TestAssert_UInt(MostCommonRank(&dice), 0, testNum++);
}

// Test_MostCommonRankCount
// Inputs: test number base
// Outputs: none, but test failures will be printed to stdout
//
// Unit tests for the yahtzeeScorer routine MostCommonRankCount().
// The first test will have id number 'testNum', the second
// test 'testNum+1', etc.
void Test_MostCommonRankCount(unsigned int testNum)
{
    FiveDiceType dice;

    SetDice2(&dice, 1, 1, 1, 1, 1);
    TestAssert_UInt(MostCommonRankCount(&dice), 5, testNum++);
    SetDice2(&dice, 2, 2, 2, 2, 2);
    TestAssert_UInt(MostCommonRankCount(&dice), 5, testNum++);
    SetDice2(&dice, 3, 3, 3, 3, 3);
    TestAssert_UInt(MostCommonRankCount(&dice), 5, testNum++);
    SetDice2(&dice, 4, 4, 4, 4, 4);
    TestAssert_UInt(MostCommonRankCount(&dice), 5, testNum++);
    SetDice2(&dice, 5, 5, 5, 5, 5);
    TestAssert_UInt(MostCommonRankCount(&dice), 5, testNum++);
    SetDice2(&dice, 6, 6, 6, 6, 6);
    TestAssert_UInt(MostCommonRankCount(&dice), 5, testNum++);

    SetDice2(&dice, 1, 1, 1, 1, 3);
    TestAssert_UInt(MostCommonRankCount(&dice), 4, testNum++);
    SetDice2(&dice, 2, 2, 2, 5, 2);
    TestAssert_UInt(MostCommonRankCount(&dice), 4, testNum++);
    SetDice2(&dice, 3, 3, 6, 3, 3);
    TestAssert_UInt(MostCommonRankCount(&dice), 4, testNum++);
    SetDice2(&dice, 4, 1, 4, 4, 4);
    TestAssert_UInt(MostCommonRankCount(&dice), 4, testNum++);
    SetDice2(&dice, 3, 5, 5, 5, 5);
    TestAssert_UInt(MostCommonRankCount(&dice), 4, testNum++);
    SetDice2(&dice, 4, 6, 6, 6, 6);
    TestAssert_UInt(MostCommonRankCount(&dice), 4, testNum++);

    SetDice2(&dice, 1, 1, 1, 2, 3);
    TestAssert_UInt(MostCommonRankCount(&dice), 3, testNum++);
    SetDice2(&dice, 4, 2, 2, 2, 5);
    TestAssert_UInt(MostCommonRankCount(&dice), 3, testNum++);
    SetDice2(&dice, 1, 2, 3, 3, 3);
    TestAssert_UInt(MostCommonRankCount(&dice), 3, testNum++);
    SetDice2(&dice, 4, 5, 4, 6, 4);
    TestAssert_UInt(MostCommonRankCount(&dice), 3, testNum++);
    SetDice2(&dice, 5, 5, 1, 5, 3);
    TestAssert_UInt(MostCommonRankCount(&dice), 3, testNum++);
    SetDice2(&dice, 4, 6, 6, 5, 6);
    TestAssert_UInt(MostCommonRankCount(&dice), 3, testNum++);

    SetDice2(&dice, 1, 1, 3, 2, 2);
    TestAssert_UInt(MostCommonRankCount(&dice), 0, testNum++);
    SetDice2(&dice, 4, 2, 6, 2, 4);
    TestAssert_UInt(MostCommonRankCount(&dice), 0, testNum++);
    SetDice2(&dice, 6, 6, 3, 5, 3);
    TestAssert_UInt(MostCommonRankCount(&dice), 0, testNum++);
    SetDice2(&dice, 4, 3, 4, 3, 1);
    TestAssert_UInt(MostCommonRankCount(&dice), 0, testNum++);
    SetDice2(&dice, 4, 5, 1, 5, 1);
    TestAssert_UInt(MostCommonRankCount(&dice), 0, testNum++);
    SetDice2(&dice, 4, 3, 6, 4, 6);
    TestAssert_UInt(MostCommonRankCount(&dice), 0, testNum++);

    SetDice2(&dice, 1, 2, 3, 4, 5);
    TestAssert_UInt(MostCommonRankCount(&dice), 0, testNum++);
    SetDice2(&dice, 1, 2, 4, 5, 6);
    TestAssert_UInt(MostCommonRankCount(&dice), 0, testNum++);
}


//-----------------------------------------------
// Helper routines
//-----------------------------------------------

// SetDice2
// Inputs: a pointer to a dice structure, plus 5 dice values
// Outputs: none, but the dice structure is updated
//
// Note - the tacky "SetDice2" instead of just "SetDice" avoids a linker
// error because multiple test files use the SetDice function. The right
// way to do this is to put SetDice in a separate file... may do that
// in the future.
//
// Updates the dice structure to coontain the five dice values
void SetDice2(FiveDiceType * dice, unsigned int d1, unsigned int d2,
                 unsigned int d3, unsigned int d4, unsigned int d5)
{
    dice->d1 = d1;
    dice->d2 = d2;
    dice->d3 = d3;
    dice->d4 = d4;
    dice->d5 = d5;
}

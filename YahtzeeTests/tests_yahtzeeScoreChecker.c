//
//  tests_yahtzeeScoreChecker.h
//  Yahtzee Tests
//
//  Created by Emily Eaton on 2/22/18.
//

#include "tests_yahtzeeScoreChecker.h"
#include "../Yahtzee/yahtzeeTypes.h"
#include "../Yahtzee/yahtzeeScoreChecker.h"
#include "testframework.h"

// Function prototypes for test subroutines
void Test_Ones(unsigned int testNum);
void Test_Twos(unsigned int testNum);
void Test_Threes(unsigned int testNum);
void Test_Fours(unsigned int testNum);
void Test_Fives(unsigned int testNum);
void Test_Sixes(unsigned int testNum);
void Test_ThreeOfAKind(unsigned int testNum);
void Test_FourOfAKind(unsigned int testNum);
void Test_FullHouse(unsigned int testNum);
void Test_SmallStraight(unsigned int testNum);
void Test_LargeStraight(unsigned int testNum);
void Test_Yahtzee(unsigned int testNum);
void Test_Chance(unsigned int testNum);
void Test_UpperTotalWithoutBonus(unsigned int testNum);
void Test_UpperBonus(unsigned int testNum);
void Test_LowerTotal(unsigned int testNum);
void Test_Total(unsigned int testNum);

// Function prototypes for helper routines
void InitToZeros(ScoreResultsType * results);
void InitToMin(ScoreResultsType * results);
void InitToMax(ScoreResultsType * results);
void RecalculateTotals(ScoreResultsType * results);

//-----------------------------------------------
// Top level
//-----------------------------------------------

// Test_YahtzeeScoreChecker
// Inputs: none
// Outputs: none
//
// Calls the subroutines to test each Yahtzee Score Checker function.
//
// The "testNum" parameter passed to each creates unique codes
// for each test. In a more polished testing setup, each code
// would have an associated string that would report the name
// of the failed test.
void Test_YahtzeeScoreChecker()
{
    unsigned int testNum = 1;

    ScoreResultsType testResults;

    InitToMin(&testResults);

    testNum = 100;
    TestAssert_ErrCode(ScoreResultsAreValid(&testResults), ERR_NONE, testNum++);

    Test_Ones(210);
    Test_Twos(220);
    Test_Threes(230);
    Test_Fours(240);
    Test_Fives(250);
    Test_Sixes(260);

    Test_ThreeOfAKind(310);
    Test_FourOfAKind(320);
    Test_FullHouse(330);
    Test_SmallStraight(340);
    Test_LargeStraight(350);
    Test_Yahtzee(360);
    Test_Chance(370);

    Test_UpperTotalWithoutBonus(400);
    Test_UpperBonus(500);
    Test_LowerTotal(600);
    Test_Total(700);

}

//-----------------------------------------------
// Upper section tests
//-----------------------------------------------

// Test_Ones
// Inputs: test number base
// Outputs: none, but test failures will be printed to stdout
//
// Unit tests for the yahtzeeScoreChecker routine ScoreResultsAreValid().
// These cases exercise checks on the score in the "ones" box.
// The first test will have id number 'testNum', the second
// test 'testNum+1', etc.
void Test_Ones(unsigned int testNum)
{
    ScoreResultsType testResults;

    InitToMin(&testResults);
    testResults.scores.ones = 1;
    RecalculateTotals(&testResults);
    TestAssert_ErrCode(ScoreResultsAreValid(&testResults), ERR_NONE, testNum++);
    testResults.scores.ones = 2;
    RecalculateTotals(&testResults);
    TestAssert_ErrCode(ScoreResultsAreValid(&testResults), ERR_NONE, testNum++);
    testResults.scores.ones = 3;
    RecalculateTotals(&testResults);
    TestAssert_ErrCode(ScoreResultsAreValid(&testResults), ERR_NONE, testNum++);
    testResults.scores.ones = 4;
    RecalculateTotals(&testResults);
    TestAssert_ErrCode(ScoreResultsAreValid(&testResults), ERR_NONE, testNum++);
    testResults.scores.ones = 5;
    RecalculateTotals(&testResults);
    TestAssert_ErrCode(ScoreResultsAreValid(&testResults), ERR_NONE, testNum++);
    testResults.scores.ones = 6;
    RecalculateTotals(&testResults);
    TestAssert_ErrCode(ScoreResultsAreValid(&testResults), ERR_ONES, testNum++);
}

// Test_Twos
// Inputs: test number base
// Outputs: none, but test failures will be printed to stdout
//
// Unit tests for the yahtzeeScoreChecker routine ScoreResultsAreValid().
// These cases exercise checks on the score in the "twos" box.
// The first test will have id number 'testNum', the second
// test 'testNum+1', etc.
void Test_Twos(unsigned int testNum)
{
    ScoreResultsType testResults;

    InitToMin(&testResults);
    testResults.scores.twos = 2;
    RecalculateTotals(&testResults);
    TestAssert_ErrCode(ScoreResultsAreValid(&testResults), ERR_NONE, testNum++);
    testResults.scores.twos = 4;
    RecalculateTotals(&testResults);
    TestAssert_ErrCode(ScoreResultsAreValid(&testResults), ERR_NONE, testNum++);
    testResults.scores.twos = 6;
    RecalculateTotals(&testResults);
    TestAssert_ErrCode(ScoreResultsAreValid(&testResults), ERR_NONE, testNum++);
    testResults.scores.twos = 8;
    RecalculateTotals(&testResults);
    TestAssert_ErrCode(ScoreResultsAreValid(&testResults), ERR_NONE, testNum++);
    testResults.scores.twos = 10;
    RecalculateTotals(&testResults);
    TestAssert_ErrCode(ScoreResultsAreValid(&testResults), ERR_NONE, testNum++);
    testResults.scores.twos = 1;
    RecalculateTotals(&testResults);
    TestAssert_ErrCode(ScoreResultsAreValid(&testResults), ERR_TWOS, testNum++);
    testResults.scores.twos = 11;
    RecalculateTotals(&testResults);
    TestAssert_ErrCode(ScoreResultsAreValid(&testResults), ERR_TWOS, testNum++);
    testResults.scores.twos = 12;
    RecalculateTotals(&testResults);
    TestAssert_ErrCode(ScoreResultsAreValid(&testResults), ERR_TWOS, testNum++);
}

// Test_Threes
// Inputs: test number base
// Outputs: none, but test failures will be printed to stdout
//
// Unit tests for the yahtzeeScoreChecker routine ScoreResultsAreValid().
// These cases exercise checks on the score in the "threes" box.
// The first test will have id number 'testNum', the second
// test 'testNum+1', etc.
void Test_Threes(unsigned int testNum)
{
    ScoreResultsType testResults;

    InitToMin(&testResults);
    testResults.scores.threes = 3;
    RecalculateTotals(&testResults);
    TestAssert_ErrCode(ScoreResultsAreValid(&testResults), ERR_NONE, testNum++);
    testResults.scores.threes = 6;
    RecalculateTotals(&testResults);
    TestAssert_ErrCode(ScoreResultsAreValid(&testResults), ERR_NONE, testNum++);
    testResults.scores.threes = 9;
    RecalculateTotals(&testResults);
    TestAssert_ErrCode(ScoreResultsAreValid(&testResults), ERR_NONE, testNum++);
    testResults.scores.threes = 12;
    RecalculateTotals(&testResults);
    TestAssert_ErrCode(ScoreResultsAreValid(&testResults), ERR_NONE, testNum++);
    testResults.scores.threes = 15;
    RecalculateTotals(&testResults);
    TestAssert_ErrCode(ScoreResultsAreValid(&testResults), ERR_NONE, testNum++);
    testResults.scores.threes = 1;
    RecalculateTotals(&testResults);
    TestAssert_ErrCode(ScoreResultsAreValid(&testResults), ERR_THREES, testNum++);
    testResults.scores.threes = 16;
    RecalculateTotals(&testResults);
    TestAssert_ErrCode(ScoreResultsAreValid(&testResults), ERR_THREES, testNum++);
    testResults.scores.threes = 18;
    RecalculateTotals(&testResults);
    TestAssert_ErrCode(ScoreResultsAreValid(&testResults), ERR_THREES, testNum++);
}

// Test_Fours
// Inputs: test number base
// Outputs: none, but test failures will be printed to stdout
//
// Unit tests for the yahtzeeScoreChecker routine ScoreResultsAreValid().
// These cases exercise checks on the score in the "fours" box.
// The first test will have id number 'testNum', the second
// test 'testNum+1', etc.
void Test_Fours(unsigned int testNum)
{
    ScoreResultsType testResults;

    InitToMin(&testResults);
    testResults.scores.fours = 4;
    RecalculateTotals(&testResults);
    TestAssert_ErrCode(ScoreResultsAreValid(&testResults), ERR_NONE, testNum++);
    testResults.scores.fours = 8;
    RecalculateTotals(&testResults);
    TestAssert_ErrCode(ScoreResultsAreValid(&testResults), ERR_NONE, testNum++);
    testResults.scores.fours = 12;
    RecalculateTotals(&testResults);
    TestAssert_ErrCode(ScoreResultsAreValid(&testResults), ERR_NONE, testNum++);
    testResults.scores.fours = 16;
    RecalculateTotals(&testResults);
    TestAssert_ErrCode(ScoreResultsAreValid(&testResults), ERR_NONE, testNum++);
    testResults.scores.fours = 20;
    RecalculateTotals(&testResults);
    TestAssert_ErrCode(ScoreResultsAreValid(&testResults), ERR_NONE, testNum++);
    testResults.scores.fours = 1;
    RecalculateTotals(&testResults);
    TestAssert_ErrCode(ScoreResultsAreValid(&testResults), ERR_FOURS, testNum++);
    testResults.scores.fours = 21;
    RecalculateTotals(&testResults);
    TestAssert_ErrCode(ScoreResultsAreValid(&testResults), ERR_FOURS, testNum++);
    testResults.scores.fours = 24;
    RecalculateTotals(&testResults);
    TestAssert_ErrCode(ScoreResultsAreValid(&testResults), ERR_FOURS, testNum++);
}

// Test_Fives
// Inputs: test number base
// Outputs: none, but test failures will be printed to stdout
//
// Unit tests for the yahtzeeScoreChecker routine ScoreResultsAreValid().
// These cases exercise checks on the score in the "fives" box.
// The first test will have id number 'testNum', the second
// test 'testNum+1', etc.
void Test_Fives(unsigned int testNum)
{
    ScoreResultsType testResults;

    InitToMin(&testResults);
    testResults.scores.fives = 5;
    RecalculateTotals(&testResults);
    TestAssert_ErrCode(ScoreResultsAreValid(&testResults), ERR_NONE, testNum++);
    testResults.scores.fives = 10;
    RecalculateTotals(&testResults);
    TestAssert_ErrCode(ScoreResultsAreValid(&testResults), ERR_NONE, testNum++);
    testResults.scores.fives = 15;
    RecalculateTotals(&testResults);
    TestAssert_ErrCode(ScoreResultsAreValid(&testResults), ERR_NONE, testNum++);
    testResults.scores.fives = 20;
    RecalculateTotals(&testResults);
    TestAssert_ErrCode(ScoreResultsAreValid(&testResults), ERR_NONE, testNum++);
    testResults.scores.fives = 25;
    RecalculateTotals(&testResults);
    TestAssert_ErrCode(ScoreResultsAreValid(&testResults), ERR_NONE, testNum++);
    testResults.scores.fives = 1;
    RecalculateTotals(&testResults);
    TestAssert_ErrCode(ScoreResultsAreValid(&testResults), ERR_FIVES, testNum++);
    testResults.scores.fives = 26;
    RecalculateTotals(&testResults);
    TestAssert_ErrCode(ScoreResultsAreValid(&testResults), ERR_FIVES, testNum++);
    testResults.scores.fives = 30;
    RecalculateTotals(&testResults);
    TestAssert_ErrCode(ScoreResultsAreValid(&testResults), ERR_FIVES, testNum++);
}

// Test_Sixes
// Inputs: test number base
// Outputs: none, but test failures will be printed to stdout
//
// Unit tests for the yahtzeeScoreChecker routine ScoreResultsAreValid().
// These cases exercise checks on the score in the "sixes" box.
// The first test will have id number 'testNum', the second
// test 'testNum+1', etc.
void Test_Sixes(unsigned int testNum)
{
    ScoreResultsType testResults;

    InitToMin(&testResults);
    testResults.scores.sixes = 6;
    RecalculateTotals(&testResults);
    TestAssert_ErrCode(ScoreResultsAreValid(&testResults), ERR_NONE, testNum++);
    testResults.scores.sixes = 12;
    RecalculateTotals(&testResults);
    TestAssert_ErrCode(ScoreResultsAreValid(&testResults), ERR_NONE, testNum++);
    testResults.scores.sixes = 18;
    RecalculateTotals(&testResults);
    TestAssert_ErrCode(ScoreResultsAreValid(&testResults), ERR_NONE, testNum++);
    testResults.scores.sixes = 24;
    RecalculateTotals(&testResults);
    TestAssert_ErrCode(ScoreResultsAreValid(&testResults), ERR_NONE, testNum++);
    testResults.scores.sixes = 30;
    RecalculateTotals(&testResults);
    TestAssert_ErrCode(ScoreResultsAreValid(&testResults), ERR_NONE, testNum++);
    testResults.scores.sixes = 1;
    RecalculateTotals(&testResults);
    TestAssert_ErrCode(ScoreResultsAreValid(&testResults), ERR_SIXES, testNum++);
    testResults.scores.sixes = 21;
    RecalculateTotals(&testResults);
    TestAssert_ErrCode(ScoreResultsAreValid(&testResults), ERR_SIXES, testNum++);
    testResults.scores.sixes = 36;
    RecalculateTotals(&testResults);
    TestAssert_ErrCode(ScoreResultsAreValid(&testResults), ERR_SIXES, testNum++);
}

//-----------------------------------------------
// Lower section tests
//-----------------------------------------------

// Test_ThreeOfAKind
// Inputs: test number base
// Outputs: none, but test failures will be printed to stdout
//
// Unit tests for the yahtzeeScoreChecker routine ScoreResultsAreValid().
// These cases exercise checks on the score in the "three of a kind" box.
// The first test will have id number 'testNum', the second
// test 'testNum+1', etc.
void Test_ThreeOfAKind(unsigned int testNum)
{
    ScoreResultsType testResults;

    InitToMin(&testResults);
    testResults.scores.threeOfAKind = 0;
    RecalculateTotals(&testResults);
    TestAssert_ErrCode(ScoreResultsAreValid(&testResults), ERR_NONE, testNum++);
    testResults.scores.threeOfAKind = 1;
    RecalculateTotals(&testResults);
    TestAssert_ErrCode(ScoreResultsAreValid(&testResults), ERR_THREEOFAKIND, testNum++);
    testResults.scores.threeOfAKind = 5;
    RecalculateTotals(&testResults);
    TestAssert_ErrCode(ScoreResultsAreValid(&testResults), ERR_NONE, testNum++);
    testResults.scores.threeOfAKind = 30;
    RecalculateTotals(&testResults);
    TestAssert_ErrCode(ScoreResultsAreValid(&testResults), ERR_NONE, testNum++);
    testResults.scores.threeOfAKind = 31;
    RecalculateTotals(&testResults);
    TestAssert_ErrCode(ScoreResultsAreValid(&testResults), ERR_THREEOFAKIND, testNum++);
}

// Test_FourOfAKind
// Inputs: test number base
// Outputs: none, but test failures will be printed to stdout
//
// Unit tests for the yahtzeeScoreChecker routine ScoreResultsAreValid().
// These cases exercise checks on the score in the "four of a kind" box.
// The first test will have id number 'testNum', the second
// test 'testNum+1', etc.
void Test_FourOfAKind(unsigned int testNum)
{
    ScoreResultsType testResults;

    InitToMin(&testResults);
    testResults.scores.fourOfAKind = 0;
    RecalculateTotals(&testResults);
    TestAssert_ErrCode(ScoreResultsAreValid(&testResults), ERR_NONE, testNum++);
    testResults.scores.fourOfAKind = 1;
    RecalculateTotals(&testResults);
    TestAssert_ErrCode(ScoreResultsAreValid(&testResults), ERR_FOUROFAKIND, testNum++);
    testResults.scores.fourOfAKind = 5;
    RecalculateTotals(&testResults);
    TestAssert_ErrCode(ScoreResultsAreValid(&testResults), ERR_NONE, testNum++);
    testResults.scores.fourOfAKind = 30;
    RecalculateTotals(&testResults);
    TestAssert_ErrCode(ScoreResultsAreValid(&testResults), ERR_NONE, testNum++);
    testResults.scores.fourOfAKind = 31;
    RecalculateTotals(&testResults);
    TestAssert_ErrCode(ScoreResultsAreValid(&testResults), ERR_FOUROFAKIND, testNum++);
}

// Test_FullHouse
// Inputs: test number base
// Outputs: none, but test failures will be printed to stdout
//
// Unit tests for the yahtzeeScoreChecker routine ScoreResultsAreValid().
// These cases exercise checks on the score in the "full house" box.
// The first test will have id number 'testNum', the second
// test 'testNum+1', etc.
void Test_FullHouse(unsigned int testNum)
{
    ScoreResultsType testResults;

    InitToMin(&testResults);
    testResults.scores.fullHouse = 0;
    RecalculateTotals(&testResults);
    TestAssert_ErrCode(ScoreResultsAreValid(&testResults), ERR_NONE, testNum++);
    testResults.scores.fullHouse = 1;
    RecalculateTotals(&testResults);
    TestAssert_ErrCode(ScoreResultsAreValid(&testResults), ERR_FULLHOUSE, testNum++);
    testResults.scores.fullHouse = 25;
    RecalculateTotals(&testResults);
    TestAssert_ErrCode(ScoreResultsAreValid(&testResults), ERR_NONE, testNum++);
    testResults.scores.fullHouse = 26;
    RecalculateTotals(&testResults);
    TestAssert_ErrCode(ScoreResultsAreValid(&testResults), ERR_FULLHOUSE, testNum++);
    testResults.scores.fullHouse = 30;
    RecalculateTotals(&testResults);
    TestAssert_ErrCode(ScoreResultsAreValid(&testResults), ERR_FULLHOUSE, testNum++);
    testResults.scores.fullHouse = 40;
    RecalculateTotals(&testResults);
    TestAssert_ErrCode(ScoreResultsAreValid(&testResults), ERR_FULLHOUSE, testNum++);
    testResults.scores.fullHouse = 50;
    RecalculateTotals(&testResults);
    TestAssert_ErrCode(ScoreResultsAreValid(&testResults), ERR_FULLHOUSE, testNum++);
}

// Test_SmallStraight
// Inputs: test number base
// Outputs: none, but test failures will be printed to stdout
//
// Unit tests for the yahtzeeScoreChecker routine ScoreResultsAreValid().
// These cases exercise checks on the score in the "small straight" box.
// The first test will have id number 'testNum', the second
// test 'testNum+1', etc.
void Test_SmallStraight(unsigned int testNum)
{
    ScoreResultsType testResults;

    InitToMin(&testResults);
    testResults.scores.smallStraight = 0;
    RecalculateTotals(&testResults);
    TestAssert_ErrCode(ScoreResultsAreValid(&testResults), ERR_NONE, testNum++);
    testResults.scores.smallStraight = 1;
    RecalculateTotals(&testResults);
    TestAssert_ErrCode(ScoreResultsAreValid(&testResults), ERR_SMALLSTRAIGHT, testNum++);
    testResults.scores.smallStraight = 25;
    RecalculateTotals(&testResults);
    TestAssert_ErrCode(ScoreResultsAreValid(&testResults), ERR_SMALLSTRAIGHT, testNum++);
    testResults.scores.smallStraight = 30;
    RecalculateTotals(&testResults);
    TestAssert_ErrCode(ScoreResultsAreValid(&testResults), ERR_NONE, testNum++);
    testResults.scores.smallStraight = 31;
    RecalculateTotals(&testResults);
    TestAssert_ErrCode(ScoreResultsAreValid(&testResults), ERR_SMALLSTRAIGHT, testNum++);
    testResults.scores.smallStraight = 40;
    RecalculateTotals(&testResults);
    TestAssert_ErrCode(ScoreResultsAreValid(&testResults), ERR_SMALLSTRAIGHT, testNum++);
    testResults.scores.smallStraight = 50;
    RecalculateTotals(&testResults);
    TestAssert_ErrCode(ScoreResultsAreValid(&testResults), ERR_SMALLSTRAIGHT, testNum++);
}

// Test_LargeStraight
// Inputs: test number base
// Outputs: none, but test failures will be printed to stdout
//
// Unit tests for the yahtzeeScoreChecker routine ScoreResultsAreValid().
// These cases exercise checks on the score in the "large straight" box.
// The first test will have id number 'testNum', the second
// test 'testNum+1', etc.
void Test_LargeStraight(unsigned int testNum)
{
    ScoreResultsType testResults;

    InitToMin(&testResults);
    testResults.scores.largeStraight = 0;
    RecalculateTotals(&testResults);
    TestAssert_ErrCode(ScoreResultsAreValid(&testResults), ERR_NONE, testNum++);
    testResults.scores.largeStraight = 1;
    RecalculateTotals(&testResults);
    TestAssert_ErrCode(ScoreResultsAreValid(&testResults), ERR_LARGESTRAIGHT, testNum++);
    testResults.scores.largeStraight = 25;
    RecalculateTotals(&testResults);
    TestAssert_ErrCode(ScoreResultsAreValid(&testResults), ERR_LARGESTRAIGHT, testNum++);
    testResults.scores.largeStraight = 30;
    RecalculateTotals(&testResults);
    TestAssert_ErrCode(ScoreResultsAreValid(&testResults), ERR_LARGESTRAIGHT, testNum++);
    testResults.scores.largeStraight = 40;
    RecalculateTotals(&testResults);
    TestAssert_ErrCode(ScoreResultsAreValid(&testResults), ERR_NONE, testNum++);
    testResults.scores.largeStraight = 41;
    RecalculateTotals(&testResults);
    TestAssert_ErrCode(ScoreResultsAreValid(&testResults), ERR_LARGESTRAIGHT, testNum++);
    testResults.scores.largeStraight = 50;
    RecalculateTotals(&testResults);
    TestAssert_ErrCode(ScoreResultsAreValid(&testResults), ERR_LARGESTRAIGHT, testNum++);
}

// Test_Yahtzee
// Inputs: test number base
// Outputs: none, but test failures will be printed to stdout
//
// Unit tests for the yahtzeeScoreChecker routine ScoreResultsAreValid().
// These cases exercise checks on the score in the "yahtzee" box.
// The first test will have id number 'testNum', the second
// test 'testNum+1', etc.
void Test_Yahtzee(unsigned int testNum)
{
    ScoreResultsType testResults;

    InitToMin(&testResults);
    testResults.scores.yahtzee = 0;
    RecalculateTotals(&testResults);
    TestAssert_ErrCode(ScoreResultsAreValid(&testResults), ERR_NONE, testNum++);
    testResults.scores.yahtzee = 1;
    RecalculateTotals(&testResults);
    TestAssert_ErrCode(ScoreResultsAreValid(&testResults), ERR_YAHTZEE, testNum++);
    testResults.scores.yahtzee = 25;
    RecalculateTotals(&testResults);
    TestAssert_ErrCode(ScoreResultsAreValid(&testResults), ERR_YAHTZEE, testNum++);
    testResults.scores.yahtzee = 30;
    RecalculateTotals(&testResults);
    TestAssert_ErrCode(ScoreResultsAreValid(&testResults), ERR_YAHTZEE, testNum++);
    testResults.scores.yahtzee = 40;
    RecalculateTotals(&testResults);
    TestAssert_ErrCode(ScoreResultsAreValid(&testResults), ERR_YAHTZEE, testNum++);
    testResults.scores.yahtzee = 50;
    RecalculateTotals(&testResults);
    TestAssert_ErrCode(ScoreResultsAreValid(&testResults), ERR_NONE, testNum++);
    testResults.scores.yahtzee = 51;
    RecalculateTotals(&testResults);
    TestAssert_ErrCode(ScoreResultsAreValid(&testResults), ERR_YAHTZEE, testNum++);
}

// Test_Chance
// Inputs: test number base
// Outputs: none, but test failures will be printed to stdout
//
// Unit tests for the yahtzeeScoreChecker routine ScoreResultsAreValid().
// These cases exercise checks on the score in the "chance" box.
// The first test will have id number 'testNum', the second
// test 'testNum+1', etc.
void Test_Chance(unsigned int testNum)
{
    ScoreResultsType testResults;

    InitToMin(&testResults);
    testResults.scores.chance = 0;
    RecalculateTotals(&testResults);
    TestAssert_ErrCode(ScoreResultsAreValid(&testResults), ERR_CHANCE, testNum++);
    testResults.scores.chance = 1;
    RecalculateTotals(&testResults);
    TestAssert_ErrCode(ScoreResultsAreValid(&testResults), ERR_CHANCE, testNum++);
    testResults.scores.chance = 5;
    RecalculateTotals(&testResults);
    TestAssert_ErrCode(ScoreResultsAreValid(&testResults), ERR_NONE, testNum++);
    testResults.scores.chance = 30;
    RecalculateTotals(&testResults);
    TestAssert_ErrCode(ScoreResultsAreValid(&testResults), ERR_NONE, testNum++);
    testResults.scores.chance = 31;
    RecalculateTotals(&testResults);
    TestAssert_ErrCode(ScoreResultsAreValid(&testResults), ERR_CHANCE, testNum++);
}

//-----------------------------------------------
// Totals tests
//-----------------------------------------------

// Test_UpperTotalWithoutBonus
// Inputs: test number base
// Outputs: none, but test failures will be printed to stdout
//
// Unit tests for the yahtzeeScoreChecker routine ScoreResultsAreValid().
// These cases exercise checks on the sum calculation for the upper section.
// The first test will have id number 'testNum', the second
// test 'testNum+1', etc.
void Test_UpperTotalWithoutBonus(unsigned int testNum)
{
    ScoreResultsType testResults;

    InitToMin(&testResults);
    RecalculateTotals(&testResults);
    TestAssert_ErrCode(ScoreResultsAreValid(&testResults), ERR_NONE, testNum++);
    InitToMax(&testResults);
    RecalculateTotals(&testResults);
    TestAssert_ErrCode(ScoreResultsAreValid(&testResults), ERR_NONE, testNum++);

    InitToMin(&testResults);
    testResults.scores.ones = 1;
    testResults.scores.twos = 2;
    testResults.scores.threes = 3;
    testResults.scores.fours = 4;
    testResults.scores.fives = 5;
    testResults.scores.sixes = 6;
    testResults.upperTotalWithoutBonus = 21;
    testResults.upperBonus = 0;
    testResults.total = 21 + 5;  // 5 for chance, which can't be valid as 0
    TestAssert_ErrCode(ScoreResultsAreValid(&testResults), ERR_NONE, testNum++);
    testResults.upperTotalWithoutBonus = 20;
    TestAssert_ErrCode(ScoreResultsAreValid(&testResults), ERR_UPPERTOTAL, testNum++);
    testResults.upperTotalWithoutBonus = 22;
    TestAssert_ErrCode(ScoreResultsAreValid(&testResults), ERR_UPPERTOTAL, testNum++);

    testResults.scores.ones = 3;
    testResults.scores.twos = 6;
    testResults.scores.threes = 9;
    testResults.scores.fours = 12;
    testResults.scores.fives = 15;
    testResults.scores.sixes = 18;
    testResults.upperTotalWithoutBonus = 63;
    testResults.upperBonus = 35;
    testResults.total = 63 + 35 + 5;
    TestAssert_ErrCode(ScoreResultsAreValid(&testResults), ERR_NONE, testNum++);
    testResults.upperTotalWithoutBonus = 64;
    TestAssert_ErrCode(ScoreResultsAreValid(&testResults), ERR_UPPERTOTAL, testNum++);
    testResults.upperTotalWithoutBonus = 62;
    TestAssert_ErrCode(ScoreResultsAreValid(&testResults), ERR_UPPERTOTAL, testNum++);
    testResults.upperTotalWithoutBonus = 63;

    testResults.scores.ones = 2;
    testResults.upperTotalWithoutBonus = 62;
    testResults.upperBonus = 0;
    testResults.total = 62 + 5;
    TestAssert_ErrCode(ScoreResultsAreValid(&testResults), ERR_NONE, testNum++);
    testResults.upperTotalWithoutBonus = 63;
    TestAssert_ErrCode(ScoreResultsAreValid(&testResults), ERR_UPPERTOTAL, testNum++);
    testResults.upperTotalWithoutBonus = 61;
    TestAssert_ErrCode(ScoreResultsAreValid(&testResults), ERR_UPPERTOTAL, testNum++);
    testResults.upperTotalWithoutBonus = 62;

    testResults.scores.ones = 4;
    testResults.upperTotalWithoutBonus = 64;
    testResults.upperBonus = 35;
    testResults.total = 64 + 35 + 5;
    TestAssert_ErrCode(ScoreResultsAreValid(&testResults), ERR_NONE, testNum++);
    testResults.upperTotalWithoutBonus = 65;
    TestAssert_ErrCode(ScoreResultsAreValid(&testResults), ERR_UPPERTOTAL, testNum++);
    testResults.upperTotalWithoutBonus = 63;
    TestAssert_ErrCode(ScoreResultsAreValid(&testResults), ERR_UPPERTOTAL, testNum++);
    testResults.upperTotalWithoutBonus = 64;

    testResults.scores.ones = 5;
    testResults.scores.twos = 10;
    testResults.scores.threes = 15;
    testResults.scores.fours = 20;
    testResults.scores.fives = 25;
    testResults.scores.sixes = 30;
    testResults.upperTotalWithoutBonus = 105;
    testResults.upperBonus = 35;
    testResults.total = 105 + 35 + 5;
    TestAssert_ErrCode(ScoreResultsAreValid(&testResults), ERR_NONE, testNum++);
    testResults.upperTotalWithoutBonus = 106;
    TestAssert_ErrCode(ScoreResultsAreValid(&testResults), ERR_UPPERTOTAL, testNum++);
    testResults.upperTotalWithoutBonus = 104;
    TestAssert_ErrCode(ScoreResultsAreValid(&testResults), ERR_UPPERTOTAL, testNum++);
    testResults.upperTotalWithoutBonus = 105;
}

// Test_UpperBonus
// Inputs: test number base
// Outputs: none, but test failures will be printed to stdout
//
// Unit tests for the yahtzeeScoreChecker routine ScoreResultsAreValid().
// These cases exercise checks on the upper section bonus application.
// The first test will have id number 'testNum', the second
// test 'testNum+1', etc.
void Test_UpperBonus(unsigned int testNum)
{
    ScoreResultsType testResults;

    InitToMin(&testResults);
    RecalculateTotals(&testResults);
    TestAssert_ErrCode(ScoreResultsAreValid(&testResults), ERR_NONE, testNum++);
    InitToMax(&testResults);
    RecalculateTotals(&testResults);
    TestAssert_ErrCode(ScoreResultsAreValid(&testResults), ERR_NONE, testNum++);

    InitToMin(&testResults);
    testResults.scores.ones = 1;
    testResults.scores.twos = 2;
    testResults.scores.threes = 3;
    testResults.scores.fours = 4;
    testResults.scores.fives = 5;
    testResults.scores.sixes = 6;
    testResults.upperTotalWithoutBonus = 21;
    testResults.upperBonus = 0;
    testResults.total = 21 + 5;  // 5 for chance, which can't be valid as 0
    TestAssert_ErrCode(ScoreResultsAreValid(&testResults), ERR_NONE, testNum++);
    testResults.upperBonus = 35;
    TestAssert_ErrCode(ScoreResultsAreValid(&testResults), ERR_BONUS, testNum++);
    testResults.upperBonus = 1;
    TestAssert_ErrCode(ScoreResultsAreValid(&testResults), ERR_BONUS, testNum++);
    testResults.upperBonus = 36;
    TestAssert_ErrCode(ScoreResultsAreValid(&testResults), ERR_BONUS, testNum++);

    testResults.scores.ones = 3;
    testResults.scores.twos = 6;
    testResults.scores.threes = 9;
    testResults.scores.fours = 12;
    testResults.scores.fives = 15;
    testResults.scores.sixes = 18;
    testResults.upperTotalWithoutBonus = 63;
    testResults.upperBonus = 35;
    testResults.total = 63 + 35 + 5;
    TestAssert_ErrCode(ScoreResultsAreValid(&testResults), ERR_NONE, testNum++);
    testResults.upperBonus = 0;
    TestAssert_ErrCode(ScoreResultsAreValid(&testResults), ERR_BONUS, testNum++);
    testResults.upperBonus = 1;
    TestAssert_ErrCode(ScoreResultsAreValid(&testResults), ERR_BONUS, testNum++);

    testResults.scores.ones = 2;
    testResults.upperTotalWithoutBonus = 62;
    testResults.upperBonus = 0;
    testResults.total = 62 + 5;
    TestAssert_ErrCode(ScoreResultsAreValid(&testResults), ERR_NONE, testNum++);
    testResults.upperBonus = 35;
    TestAssert_ErrCode(ScoreResultsAreValid(&testResults), ERR_BONUS, testNum++);

    testResults.scores.ones = 4;
    testResults.upperTotalWithoutBonus = 64;
    testResults.upperBonus = 35;
    testResults.total = 64 + 35 + 5;
    TestAssert_ErrCode(ScoreResultsAreValid(&testResults), ERR_NONE, testNum++);
    testResults.upperBonus = 0;
    TestAssert_ErrCode(ScoreResultsAreValid(&testResults), ERR_BONUS, testNum++);

    testResults.scores.ones = 5;
    testResults.scores.twos = 10;
    testResults.scores.threes = 15;
    testResults.scores.fours = 20;
    testResults.scores.fives = 25;
    testResults.scores.sixes = 30;
    testResults.upperTotalWithoutBonus = 105;
    testResults.upperBonus = 35;
    testResults.total = 105 + 35 + 5;
    TestAssert_ErrCode(ScoreResultsAreValid(&testResults), ERR_NONE, testNum++);
    testResults.upperBonus = 0;
    TestAssert_ErrCode(ScoreResultsAreValid(&testResults), ERR_BONUS, testNum++);
}

// Test_LowerTotal
// Inputs: test number base
// Outputs: none, but test failures will be printed to stdout
//
// Unit tests for the yahtzeeScoreChecker routine ScoreResultsAreValid().
// These cases exercise checks on the sum calculation for the lower section.
// The first test will have id number 'testNum', the second
// test 'testNum+1', etc.
void Test_LowerTotal(unsigned int testNum)
{
    ScoreResultsType testResults;

    InitToMin(&testResults);
    RecalculateTotals(&testResults);
    TestAssert_ErrCode(ScoreResultsAreValid(&testResults), ERR_NONE, testNum++);
    testResults.lowerTotal--;
    TestAssert_ErrCode(ScoreResultsAreValid(&testResults), ERR_LOWERTOTAL, testNum++);
    testResults.lowerTotal++;
    testResults.lowerTotal++;
    TestAssert_ErrCode(ScoreResultsAreValid(&testResults), ERR_LOWERTOTAL, testNum++);
    testResults.lowerTotal = 0;
    TestAssert_ErrCode(ScoreResultsAreValid(&testResults), ERR_LOWERTOTAL, testNum++);

    InitToMax(&testResults);
    RecalculateTotals(&testResults);
    TestAssert_ErrCode(ScoreResultsAreValid(&testResults), ERR_NONE, testNum++);
    testResults.lowerTotal--;
    TestAssert_ErrCode(ScoreResultsAreValid(&testResults), ERR_LOWERTOTAL, testNum++);
    testResults.lowerTotal++;
    testResults.lowerTotal++;
    TestAssert_ErrCode(ScoreResultsAreValid(&testResults), ERR_LOWERTOTAL, testNum++);
    testResults.lowerTotal = 0;
    TestAssert_ErrCode(ScoreResultsAreValid(&testResults), ERR_LOWERTOTAL, testNum++);

    InitToMin(&testResults);
    testResults.scores.threeOfAKind = 15;
    testResults.scores.fourOfAKind = 20;
    testResults.scores.fullHouse = 25;
    testResults.scores.smallStraight = 0;
    testResults.scores.largeStraight = 40;
    testResults.scores.yahtzee = 0;
    testResults.scores.chance = 19;
    testResults.lowerTotal = 15+20+25+40+19;
    testResults.total = 15+20+25+40+19;
    TestAssert_ErrCode(ScoreResultsAreValid(&testResults), ERR_NONE, testNum++);
    testResults.lowerTotal--;
    TestAssert_ErrCode(ScoreResultsAreValid(&testResults), ERR_LOWERTOTAL, testNum++);
    testResults.lowerTotal++;
    testResults.lowerTotal++;
    TestAssert_ErrCode(ScoreResultsAreValid(&testResults), ERR_LOWERTOTAL, testNum++);
}

// Test_Total
// Inputs: test number base
// Outputs: none, but test failures will be printed to stdout
//
// Unit tests for the yahtzeeScoreChecker routine ScoreResultsAreValid().
// These cases exercise checks on the overall total calculation.
// The first test will have id number 'testNum', the second
// test 'testNum+1', etc.
void Test_Total(unsigned int testNum)
{
    ScoreResultsType testResults;

    InitToMin(&testResults);
    RecalculateTotals(&testResults);
    TestAssert_ErrCode(ScoreResultsAreValid(&testResults), ERR_NONE, testNum++);
    testResults.total--;
    TestAssert_ErrCode(ScoreResultsAreValid(&testResults), ERR_TOTAL, testNum++);
    testResults.total++;
    testResults.total++;
    TestAssert_ErrCode(ScoreResultsAreValid(&testResults), ERR_TOTAL, testNum++);
    testResults.total = 0;
    TestAssert_ErrCode(ScoreResultsAreValid(&testResults), ERR_TOTAL, testNum++);

    InitToMax(&testResults);
    RecalculateTotals(&testResults);
    TestAssert_ErrCode(ScoreResultsAreValid(&testResults), ERR_NONE, testNum++);
    testResults.total--;
    TestAssert_ErrCode(ScoreResultsAreValid(&testResults), ERR_TOTAL, testNum++);
    testResults.total++;
    testResults.total++;
    TestAssert_ErrCode(ScoreResultsAreValid(&testResults), ERR_TOTAL, testNum++);
    testResults.total = 0;
    TestAssert_ErrCode(ScoreResultsAreValid(&testResults), ERR_TOTAL, testNum++);
}

//-----------------------------------------------
// Helpers for initializing the test testResults
//-----------------------------------------------

// InitToZeros
// Inputs: results structure
// Outputs: none, but updates results
//
// Sets the entire structure to zeros. Note that this isn't a valid set
// of results, because Chance has a minimum value of 5.
void InitToZeros(ScoreResultsType * results)
{
    results->scores.ones = 0;
    results->scores.twos = 0;
    results->scores.threes = 0;
    results->scores.fours = 0;
    results->scores.fives = 0;
    results->scores.sixes = 0;
    results->scores.threeOfAKind = 0;
    results->scores.fourOfAKind = 0;
    results->scores.fullHouse = 0;
    results->scores.smallStraight = 0;
    results->scores.largeStraight = 0;
    results->scores.yahtzee = 0;
    results->scores.chance = 0;
    results->upperBonus = 0;
    results->upperTotalWithoutBonus = 0;
    results->lowerTotal = 0;
    results->total = 0;
}

// InitToMin
// Inputs: results structure
// Outputs: none, but updates results
//
// Sets the entire structure to minimum legal values. This means all scores
// are 0 except chance, which is 5.
void InitToMin(ScoreResultsType * results)
{
    results->scores.ones = 0;
    results->scores.twos = 0;
    results->scores.threes = 0;
    results->scores.fours = 0;
    results->scores.fives = 0;
    results->scores.sixes = 0;
    results->scores.threeOfAKind = 0;
    results->scores.fourOfAKind = 0;
    results->scores.fullHouse = 0;
    results->scores.smallStraight = 0;
    results->scores.largeStraight = 0;
    results->scores.yahtzee = 0;
    results->scores.chance = 5;
    results->upperBonus = 0;
    results->upperTotalWithoutBonus = 0;
    results->lowerTotal = 5;
    results->total = 5;
}

// InitToMax
// Inputs: results structure
// Outputs: none, but updates results
//
// Sets the entire structure to maximum legal values.
void InitToMax(ScoreResultsType * results)
{
    results->scores.ones = 5;
    results->scores.twos = 10;
    results->scores.threes = 15;
    results->scores.fours = 20;
    results->scores.fives = 25;
    results->scores.sixes = 30;
    results->scores.threeOfAKind = 30;
    results->scores.fourOfAKind = 30;
    results->scores.fullHouse = 25;
    results->scores.smallStraight = 30;
    results->scores.largeStraight = 40;
    results->scores.yahtzee = 50;
    results->scores.chance = 30;
    results->upperBonus = 35;
    results->upperTotalWithoutBonus = 5+10+15+20+25+30;
    results->lowerTotal = 30+30+25+30+40+50+30;
    results->total = results->upperBonus + results->upperTotalWithoutBonus + results->lowerTotal;
}

// RecalculateTotals
// Inputs: results structure
// Outputs: none, but updates results
//
// Sets the totals and bonus based on the scores. Does NOT check to make sure
// the individual scores are valid.
void RecalculateTotals(ScoreResultsType * results)
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

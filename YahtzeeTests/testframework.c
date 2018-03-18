#include <stdio.h>
#include <stdbool.h>
#include "testframework.h"

// TestAssert_ErrCode
// Inputs: two ScoringErrorType values to compare, a test number
// Outputs: none, but reports its results
//
// If the value and expected value are equal, the test passes. If they
// are not equal, the test fails. A test failure message is printed to
// stdout, and the failure is reported.
//
// A static variable stopTesting allows the reporting routine to signal
// that a threshold number of tests has failed, and no more tests should
// be performed. This prevents a broken program from running a huge
// number of failing tests.
void TestAssert_ErrCode(ScoringErrorType val, ScoringErrorType expectedVal, unsigned int testNum)
{
    static bool stopTesting = false;

    if (!stopTesting)
    {
        if (val == expectedVal)
        {
            ReportTestResult(true, testNum);
        }
        else
        {
            printf("Test %d: expected %d, found %d\n", testNum, expectedVal, val);
            stopTesting = ReportTestResult(false, testNum);
        }
    }
}

// TestAssert_UInt
// Inputs: two unsigned int values to compare, a test number
// Outputs: none, but reports its results
//
// If the value and expected value are equal, the test passes. If they
// are not equal, the test fails. A test failure message is printed to
// stdout, and the failure is reported.
//
// A static variable stopTesting allows the reporting routine to signal
// that a threshold number of tests has failed, and no more tests should
// be performed. This prevents a broken program from running a huge
// number of failing tests.
void TestAssert_UInt(unsigned int val, unsigned int expectedVal, unsigned int testNum)
{
    static bool stopTesting = false;

    if (!stopTesting)
    {
        if (val == expectedVal)
        {
            ReportTestResult(true, testNum);
        }
        else
        {
            printf("Test %d: expected %d, found %d\n", testNum, expectedVal, val);
            stopTesting = ReportTestResult(false, testNum);
        }
    }
}

// ReportTestResult
// Inputs: boolean pass/fail indicator, and the test number
// Outputs: nonzero to flag that further tests should be halted, 0 otherwise
//
// This routine:
//    - counts the number of passed and failed tests
//    - records the test numbers of failed tests
//    - detects when MAXFAILS tests have failed
//    - prints the failed test numbers when MAXFAILS threshold is reached
//    - prints the counts of passed/failed tests when testNum=0 is passed in
//
// The return value allows this routine to signal that a threshold number
// of tests has failed, and no more tests should be performed. this prevents
// a broken program from running a huge number of failing tests.
int ReportTestResult(bool testPassed, unsigned int testNum)
{
    static unsigned int nTestsPassed = 0;
    static unsigned int nTestsFailed = 0;
    static unsigned int failedTests[MAXFAILS] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    if (testNum == 0)
    {
        printf("%d tests passed.\n", nTestsPassed);
        printf("%d tests failed.\n", nTestsFailed);
        return 0;
    }

    int returnVal = 0;
    if (nTestsFailed < MAXFAILS)
    {
        if (!testPassed) {
            failedTests[nTestsFailed] = testNum;
            nTestsFailed++;
        } else {
            nTestsPassed++;
        }

        if (nTestsFailed >= MAXFAILS)
        {
            printf("Too many failed tests. These tests failed: ");
            for (int i=0; i<MAXFAILS; i++)
            {
                printf("%d ", failedTests[i]);
            }
            printf("\n");
            returnVal = 1;
        }
    }
    else
    {
        returnVal = 2;
    }

    return returnVal;
}

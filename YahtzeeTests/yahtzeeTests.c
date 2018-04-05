//
//  yahtzeeTests.c
//  YahtzeeTests
//
//  Top-level routine that calls the tester for each module and
//  reports the overall results.
//
//  Created by Emily Eaton on 3/14/18.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tests_yahtzeeScoreChecker.h"
#include "tests_yahtzeeScorer.h"
#include "tests_yahtzeeToolbox.h"
#include "testframework.h"


int main()
{
    Test_YahtzeeScoreChecker();
    Test_YahtzeeScorer();
    Test_YahtzeeToolbox();

    ReportTestResult(true, 0);

    return 0;
}

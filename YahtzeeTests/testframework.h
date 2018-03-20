
#include <stdbool.h>
#include "yahtzeeScoreChecker.h"

#define MAXFAILS 10

void TestAssert_ErrCode(ScoringErrorType val, ScoringErrorType expectedVal, unsigned int testNum);
void TestAssert_UInt(unsigned int val, unsigned int expectedVal, unsigned int testNum);
int ReportTestResult(bool testPassed, unsigned int testNum);

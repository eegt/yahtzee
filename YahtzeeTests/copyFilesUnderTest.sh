#!/bin/bash

# Copies the most recent versions of source under test,
# plus a required header file. Not an elegant solution.
# Probably better to link to libraries. But this gets
# us going for starters.
cp ../Yahtzee/yahtzeeScoreChecker.c yahtzeeScoreChecker.c
cp ../Yahtzee/yahtzeeScoreChecker.h yahtzeeScoreChecker.h
cp ../Yahtzee/yahtzeeScorer.c yahtzeeScorer.c
cp ../Yahtzee/yahtzeeScorer.h yahtzeeScorer.h
cp ../Yahtzee/yahtzeeTypes.h yahtzeeTypes.h

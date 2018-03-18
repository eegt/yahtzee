//
//  yahtzeeTypes.h
//
//  Structures, constants, etc. used in the Yahtzee program
//
//  Created by Emily Eaton on 2/22/18.
//

#ifndef yahtzeeTypes_h
#define yahtzeeTypes_h

#define NDICE 5
#define NTURNS 13

typedef struct
{
    unsigned int d1;
    unsigned int d2;
    unsigned int d3;
    unsigned int d4;
    unsigned int d5;

} FiveDiceType;

typedef struct
{
    unsigned int ones;
    unsigned int twos;
    unsigned int threes;
    unsigned int fours;
    unsigned int fives;
    unsigned int sixes;

    unsigned int threeOfAKind;
    unsigned int fourOfAKind;
    unsigned int fullHouse;
    unsigned int smallStraight;
    unsigned int largeStraight;
    unsigned int yahtzee;
    unsigned int chance;
} ScoreAssignmentsType;

typedef struct
{
    ScoreAssignmentsType scores;
    unsigned int upperBonus;
    unsigned int upperTotalWithoutBonus;
    unsigned int lowerTotal;
    unsigned int total;
} ScoreResultsType;


#endif /* yahtzeeTypes_h */

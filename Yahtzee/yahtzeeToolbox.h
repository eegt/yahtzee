#include <stdbool.h>
#include "yahtzeeTypes.h"

unsigned int HowManyOfRank(const FiveDiceType * dice, unsigned int rank);
unsigned int SumOfAllDice(const FiveDiceType* dice);
void RollDice(FiveDiceType * dice, bool rollD1, bool rollD2,
                 bool rollD3, bool rollD4, bool rollD5);
void GetRankCounts(FiveDiceType * dice, DiceCountsType * counts);
unsigned int MostCommonRank(FiveDiceType * dice);
unsigned int MostCommonRankCount(FiveDiceType * dice);

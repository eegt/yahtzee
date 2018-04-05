#include <stdbool.h>
#include "yahtzeeTypes.h"

unsigned int HowManyOfRank(const FiveDiceType * dice, unsigned int rank);
unsigned int SumOfAllDice(const FiveDiceType* dice);
void RollDice(FiveDiceType * dice, bool rollD1, bool rollD2,
                 bool rollD3, bool rollD4, bool rollD5);
void GetRankCounts(const FiveDiceType * dice, DiceCountsType * counts);
unsigned int MostCommonRank(const FiveDiceType * dice);
unsigned int MostCommonRankCount(const FiveDiceType * dice);

#include "header.h"

void main()
{
	int level = GetLevel();
	int hyper = GetHyperStancePoint();
	int attackMainStat = GetAttackMainstatPoint();

	int point = GetTotalStat(level);
	int remainPoints = point - hyper - attackMainStat;
	printf("Remain points : %d\n", remainPoints);
	remainPoints -= totalStatPoint[10] * 4;
	printf("Remain points(when 4 stauts level is 11 : %d", remainPoints);
}
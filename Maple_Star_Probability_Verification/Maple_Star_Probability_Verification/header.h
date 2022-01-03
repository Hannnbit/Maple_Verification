#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

long long expectedMeso[25] = { 0 };

int GetItemLevel()
{
	printf("Input Item Level : ");

	char itemLevel[100] = { 0 };
	int temp = scanf("%s", itemLevel);

	return atoi(itemLevel);
}
int GetCurrentStarLevel()
{
	printf("Input star levels of Item : ");

	char CurrentStarLevel[100] = { 0 };
	int temp = scanf("%s", CurrentStarLevel);
	return atoi(CurrentStarLevel);
}	 
int GetGoalStarLevel()
{
	printf("Input goal of your star force item : ");

	char GoalStarLevel[100] = { 0 };
	int temp = scanf("%s", GoalStarLevel);
	return atoi(GoalStarLevel);
}
int ChkStarCatch()
{
	printf("Input 'O' if you use starcatch, or not intpur 'X' : ");

	char starcatch[100] = { 0 };
	int temp = scanf("%s",starcatch);
	_strupr(starcatch);

	return starcatch[0] == 'O' ? 1 : 0;
}

double GetCalculatedProbability(int nowLevel,int starCatch)
{
	double revisionPro = starCatch ? 1.05 : 1;
	int starPro = nowLevel > 13 ? 30 : 100 - (nowLevel) * 5;
	starPro = nowLevel < 3 ? starPro - 5 : starPro;

	return starPro * revisionPro;
}
int GetNeededMeso(int itemLevel, int currentStar)
{
	int L = itemLevel * itemLevel * itemLevel;
	int S = currentStar;
	double meso = 0;

	if (currentStar < 10)
	{
		meso = 1000 + L * (S + 1) / 25;
	}
	else if (currentStar < 15)
	{
		meso = 1000 + L * pow((S + 1), 2.7) / 400;
	}
	else
	{
		meso = 1000 + L * pow((S + 1), 2.7) / 200;
	}
	return (int)meso;
}
long long GetExProMeso(int star, double sucPro, double meso, int itemLevel, int starCatch, int totalMeso)
{
	double upPer = sucPro;
	double failPer = 100 - sucPro;
	double desPer[13] = { 0.6,1.3,1.4,2.1,2.1,2.1,2.8,2.8,7,7,19.4,29.4,39.6};

	if (expectedMeso[star] == 0)
	{
		if (star <= 10)
		{
			expectedMeso[star] = (long long)(100 / upPer * meso);
		}
		else if (star == 11)
		{
			double upPerMeso = 100 / upPer * meso;
			double failPerMeso = 100 / failPer * expectedMeso[star - 1];
			expectedMeso[star] = (upPerMeso + failPerMeso);
		}
		else if (star <= 16)
		{
			failPer -= desPer[star - 12];
			double upPerMeso = 100 / upPer * meso;
			double failPerMeso = 100 / failPer * expectedMeso[star - 1];
			double desPerMeso = 100 / desPer[star-12] * totalMeso;
			expectedMeso[star] = (upPerMeso*upPer/100 + failPerMeso*failPer/100 + desPerMeso*desPer[star-12]/100);
		}
		else
		{
			failPer -= desPer[star - 12];
			double upPerMeso = 100 / upPer * meso;
			double failPerMeso = 100 / failPer * expectedMeso[star - 1];
			double desPerMeso = 100 / desPer[star - 12] * totalMeso;
			expectedMeso[star] = (upPerMeso + failPerMeso + desPerMeso);
		}
	}

	return expectedMeso[star];
}

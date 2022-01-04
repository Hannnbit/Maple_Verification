#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int hyperStatPoint[15] = { 1,2,4,8,10,15,20,25,30,35,50,65,80,95,110 };
int totalStatPoint[15] = { 1,3,7,15,25,40,60,85,115,150,200,265,345,440,550 };

int GetLevel()
{
	int level = 0;
	do
	{
		printf("Input Your Level : ");
		char str_level[1000] = { 0 };

		level =  scanf("%s", str_level);
		level = atoi(str_level);
	} while (level < 140 || level > 300);

	return level;
}
int GetHyperStancePoint()
{
	int stance = 0;

	do
	{
		printf("Input Your Hyper Stance Level : ");
		char str_stance[1000] = { 0 };

		stance = scanf("%s", str_stance);
		stance = atoi(str_stance);
	} while (stance < 0 || stance > 15);

	int totalStat = 0;
	for (int i = 0; i < stance; i++)		totalStat += hyperStatPoint[i];
	return totalStat;
}
int GetAttackMainstatPoint()
{
	int attack = 0;

	do
	{
		printf("Input Your attack and main stat Level : ");
		char str_attack[1000] = { 0 };

		scanf("%s", str_attack);
		attack = atoi(str_attack);
	} while (attack < 0 || attack > 15);

	int totalStat = 0;
	for (int i = 0; i < attack; i++)		totalStat += hyperStatPoint[i] * 2;
	return totalStat;
}

int GetTotalStat(int level)
{
	int temp = level - 140;
	int point = 0;
	int income = 3;
	for (int i = 0; i <= temp; i++)
	{
		point += income;
		if (i != 0 && i % 10 == 9)
			income++;
	}
	return point;
}


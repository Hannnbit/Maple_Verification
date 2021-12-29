#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <stdio.h>
#include <math.h>

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
int GetExpectedValue()
{
	printf("Input starforce expected value : ");

	char expected[100] = { 0 };
	int temp = scanf("%s", expected);
	return atoi(expected);
}

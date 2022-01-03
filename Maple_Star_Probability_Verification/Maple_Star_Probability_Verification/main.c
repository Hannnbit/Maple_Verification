#include "header.h"

void main()
{
	int itemLevel = GetItemLevel();
	int currentStarLevel = GetCurrentStarLevel();
	int goalStarLevel = GetGoalStarLevel();
	int starCatch = ChkStarCatch();
	
	int starGap = goalStarLevel - currentStarLevel;
	long long totalMeso = 0;
	for (int i = 0; i < 10; i++)
	{
		double sucPro = GetCalculatedProbability(currentStarLevel + i, starCatch);
		printf("\n%d성 : %.1lf", currentStarLevel + i + 1, sucPro);

		int meso = GetNeededMeso(itemLevel, currentStarLevel+i);
		printf("\t필요메소 : %d", meso);

		long long exMeso = GetExProMeso(currentStarLevel + i, sucPro, meso, itemLevel,
			starCatch, totalMeso);
		printf("\t 기댓값메소 : %lld", exMeso);

		totalMeso += exMeso;
		printf("\t 총 메소 : %lld", totalMeso);
	}
}
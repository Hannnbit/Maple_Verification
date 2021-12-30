#include "header.h"

void main()
{
	int itemLevel = GetItemLevel();
	int currentStarLevel = GetCurrentStarLevel();
	int goalStarLevel = GetGoalStarLevel();
	int starCatch = ChkStarCatch();
	
	int starGap = goalStarLevel - currentStarLevel;
	long long totalMeso = 0;
	for (int i = 0; i < starGap; i++)
	{
		double sucPro = GetCalculatedProbability(currentStarLevel + i, starCatch);
		printf("\n%d성 : %.1lf", currentStarLevel + i + 1, sucPro);

		int meso = GetNeededMeso(itemLevel, currentStarLevel+i);
		printf("\t필요메소 : %d", meso);

		int exMeso = GetExProMeso(currentStarLevel+i,sucPro,meso);
		printf("\t 기댓값메소 : %d", exMeso);

		totalMeso += exMeso;
		printf("\t 총 메소 : %lld", totalMeso);
	}
	printf("\n\n\n\n\n\n\n\n\n\n\n");
}
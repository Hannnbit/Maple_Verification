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
		printf("\n%d�� : %.1lf", currentStarLevel + i + 1, sucPro);

		int meso = GetNeededMeso(itemLevel, currentStarLevel+i);
		printf("\t�ʿ�޼� : %d", meso);

		int exMeso = GetExProMeso(currentStarLevel+i,sucPro,meso);
		printf("\t ��񰪸޼� : %d", exMeso);

		totalMeso += exMeso;
		printf("\t �� �޼� : %lld", totalMeso);
	}
	printf("\n\n\n\n\n\n\n\n\n\n\n");
}
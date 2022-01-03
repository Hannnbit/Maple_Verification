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
		printf("\n%d�� : %.1lf", currentStarLevel + i + 1, sucPro);

		int meso = GetNeededMeso(itemLevel, currentStarLevel+i);
		printf("\t�ʿ�޼� : %d", meso);

		long long exMeso = GetExProMeso(currentStarLevel + i, sucPro, meso, itemLevel,
			starCatch, totalMeso);
		printf("\t ��񰪸޼� : %lld", exMeso);

		totalMeso += exMeso;
		printf("\t �� �޼� : %lld", totalMeso);
	}
}
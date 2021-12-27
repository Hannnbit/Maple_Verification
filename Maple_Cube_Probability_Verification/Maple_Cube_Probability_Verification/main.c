#include "function.h"

void main()
{
    CursorView();
    do
    {
        int cube = SelectCube();
        int cubeGrade = CurrentCubeGrade();
        int cubeGoal = GetCubeGoal(cube);
        int miracleTime = CheckMiracle();

        if (cubeGrade >= cubeGoal) { continue; }
        else
        {
            double expected = GetExpected();
            int cubeCnt = GetTotalCube(cube, cubeGrade, cubeGoal, miracleTime, expected);
            PrintCubeInfo(cube, cubeCnt);
        }
    } while (CheckAgain());
}

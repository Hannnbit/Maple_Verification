#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
#include <conio.h>

enum CubeNum {
    CubeStrange = 1, CubeSemiMaster,
    CubeMaster, CubeRed,
    CubeBlack, CubeEditional
};
enum CubeGoal {
    Rare = 1, Epic, Unique, Legend
};


#define CUBE_STRANGE_EPIC 0.9901
#define CUBE_SEMIMASTER_EPIC 4.7619
#define CUBE_SEMIMASTER_UNIQUE 1.1858
#define CUBE_MASTER_EPIC 7.9994
#define CUBE_MASTER_UNIQUE 1.6959
#define CUBE_MASTER_LEGEND 0.1996
#define CUBE_RED_EPIC 6
#define CUBE_RED_UNIQUE 1.8
#define CUBE_RED_LEGEND 0.3
#define CUBE_BLACK_EPIC 15
#define CUBE_BLACK_UNIQUE 3.5
#define CUBE_BLACK_LEGEND 1
#define CUBE_EDITIONAL_EPIC 4.7619
#define CUBE_EDITIONAL_UNIQUE 1.9608
#define CUBE_EDITIONAL_LEGEND 0.4975

#define CUBE_STRANGE_PRICE 18000
#define CUBE_SEMIMASTER_PRICE 10000000
#define CUBE_MASTER_PRICE 31000000
#define CUBE_RED_PRICE 900
#define CUBE_BLACK_PRICE 1650
#define CUBE_EDITIONAL_PRICE 1890


int SelectCube()
{
    system("cls");
    printf("===========================\n");
    printf("1. 수 상 한 큐브\n");
    printf("2. 장 인 의 큐브\n");
    printf("3. 명 장 의 큐브\n");
    printf("4. 레    드 큐브\n");
    printf("5. 블    랙 큐브\n");
    printf("6. 에디셔널 큐브\n");
    printf("===========================\n");
    int cubeNum = _getch() - 48;
    return cubeNum;
}
int CurrentCubeGrade(int cube)
{
    system("cls");
    int cubeGrade = 0;

    if (cube == CubeStrange) {
        cubeGrade = 1;
    }
    else if (cube == CubeSemiMaster) {
        printf("=========현재 잠재=========\n");
        printf("1. 레어\n");
        printf("2. 에픽\n");
        printf("===========================\n");
        cubeGrade = _getch() - 48;
    }
    else {
        printf("=========현재 잠재=========\n");
        printf("1. 레어\n");
        printf("2. 에픽\n");
        printf("3. 유니크\n");
        printf("===========================\n");
        cubeGrade = _getch() - 48;
    }
    return cubeGrade;
}
int SelectCubeGoal()
{
    system("cls");
    printf("=========목표 잠재=========\n");
    printf("1. 에픽\n");
    printf("2. 유니크\n");
    printf("3. 레전더리\n");
    printf("===========================\n");
    int cubeGoal = _getch() - 48;
    return cubeGoal + 1;
}
int GetCubeGoal(int cube)
{
    switch (cube)
    {
    case CubeStrange:
        return Epic;
        break;

    case CubeSemiMaster:
        system("cls");
        printf("=========목표 잠재=========\n");
        printf("1. 에픽\n");
        printf("2. 유니크\n");
        printf("===========================\n");

        int cubeGoal = _getch() - 48;
        return cubeGoal + 1;
    }
    return SelectCubeGoal();
}
int CheckMiracle()
{
    system("cls");
    printf("========미라클 타임========\n");
    printf("1. 미라클타임 O\n");
    printf("2. 미라클타임 X\n");
    printf("===========================\n");

    int checkMiracle = _getch() - 48;
    system("cls");
    return !(checkMiracle - 1);
}

double GetExpected()
{
    printf("========기댓값 입력========\n");
    printf("1~99%\n");
    printf("===========================\n");
    printf("Input : ");
    double expected = 0;
    scanf("%lf", &expected);
    system("cls");

    return expected;
}
int GetCubeCnt(double expected, double successPercentage)
{
    double failpercentage = (100 - successPercentage) / 100;
    double accumilationFail = failpercentage;

    int cubeCnt = 1;
    expected = (100 - expected) / 100;
    while (accumilationFail >= expected)
    {
        cubeCnt++;
        accumilationFail *= failpercentage;
    }
    return cubeCnt;
}
int GetTotalCube(int cube, int cubeGrade, int cubeGoal, int miracleTime, double expected)
{
    int totalCubeCnt = 0;
    switch (cube)
    {
        case CubeStrange: {
            totalCubeCnt = GetCubeCnt(expected, CUBE_STRANGE_EPIC);
            break;
        }
        case CubeSemiMaster: {
            if (cubeGoal >= Epic && cubeGrade < Epic)
                totalCubeCnt += GetCubeCnt(expected, CUBE_SEMIMASTER_EPIC);
            if (cubeGoal >= Unique && cubeGrade < Unique)
                totalCubeCnt += GetCubeCnt(expected, CUBE_SEMIMASTER_UNIQUE);
            break;
        }
        case CubeMaster: {
            if (cubeGoal >= Epic && cubeGrade < Epic)
                totalCubeCnt += GetCubeCnt(expected, CUBE_MASTER_EPIC);
            if (cubeGoal >= Unique && cubeGrade < Unique)
                totalCubeCnt += GetCubeCnt(expected, CUBE_MASTER_UNIQUE);
            if (cubeGoal == Legend && cubeGrade < Legend)
                totalCubeCnt += GetCubeCnt(expected, CUBE_MASTER_LEGEND);
            break;
        }
        case CubeRed: {
            if (cubeGoal >= Epic && cubeGrade < Epic)
                totalCubeCnt += GetCubeCnt(expected, CUBE_RED_EPIC);
            if (cubeGoal >= Unique && cubeGrade < Unique)
                totalCubeCnt += GetCubeCnt(expected, CUBE_RED_UNIQUE);
            if (cubeGoal == Legend && cubeGrade < Legend)
                totalCubeCnt += GetCubeCnt(expected, CUBE_RED_LEGEND);
            break;
        }
        case CubeBlack: {
            if (cubeGoal >= Epic && cubeGrade < Epic)
                totalCubeCnt += GetCubeCnt(expected, CUBE_BLACK_EPIC);
            if (cubeGoal >= Unique && cubeGrade < Unique)
                totalCubeCnt += GetCubeCnt(expected, CUBE_BLACK_UNIQUE);
            if (cubeGoal == Legend && cubeGrade < Legend)
                totalCubeCnt += GetCubeCnt(expected, CUBE_BLACK_LEGEND);
            break;
        }
        case CubeEditional: {
            if (cubeGoal >= Epic && cubeGrade < Epic)
                totalCubeCnt += GetCubeCnt(expected, CUBE_EDITIONAL_EPIC);
            if (cubeGoal >= Unique && cubeGrade < Unique)
                totalCubeCnt += GetCubeCnt(expected, CUBE_EDITIONAL_UNIQUE);
            if (cubeGoal == Legend && cubeGrade < Legend)
                totalCubeCnt += GetCubeCnt(expected, CUBE_EDITIONAL_LEGEND);
            break;
        }
    }

    if (miracleTime && totalCubeCnt > 1)
        totalCubeCnt /= 2;

    return totalCubeCnt;
}
void PrintCubeInfo(int cube, int cnt)
{
    if (cube <= 3)
    {
        long long meso = 0;
        switch (cube)
        {
        case 1:
            meso = cnt * CUBE_STRANGE_PRICE;
            break;
        case 2:
            meso = cnt * CUBE_SEMIMASTER_PRICE;
        case 3:
            meso = cnt * CUBE_MASTER_PRICE;
        }
        printf("===========================\n");
        printf("필요 큐브 개수 : %d\n", cnt);
        printf("필요 메소 : %lld\n", meso);
        printf("===========================\n");
    }
    else
    {
        int cash = 0;
        switch (cube)
        {
        case 4:
            cash = cnt * CUBE_RED_PRICE;
            break;
        case 5:
            cash = cnt * CUBE_BLACK_PRICE;
        case 6:
            cash = cnt * CUBE_EDITIONAL_PRICE;
        }

        printf("===========================\n");
        printf("필요 큐브 개수 : %d\n", cnt);
        printf("필요 캐시 : %d\n", cash);
        printf("===========================\n");
    }

    fflush(stdin);
    _getch();
    system("cls");
}

int CheckAgain()
{
    printf("========Check Again========\n");
    printf("Yes : 1\n");
    printf("No : 2\n");
    printf("Input : ");

    int temp = 0;
    scanf("%d", &temp);
    return !(temp - 1);

}
void CursorView()
{
    CONSOLE_CURSOR_INFO cursorInfo = { 0, };
    cursorInfo.dwSize = 1; //커서 굵기 (1 ~ 100)
    cursorInfo.bVisible = FALSE; //커서 Visible TRUE(보임) FALSE(숨김)
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}
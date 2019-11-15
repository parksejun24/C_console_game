#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <mmsystem.h>
#include <time.h>

#pragma comment(lib, "winmm.lib")


#define ENTER 13
#define MAPSIZE 25
#define MAPSIZE2 20
#define MAPSIZE3 39

#define RIGHT 0x27
#define LEFT  0x25
#define DOWN  0x28
#define UP  0x26

#define F3 0x72
#define ENTER 0x0D
#define R 0x52
#define S  0x53

typedef struct human {
	double record;
	char name[50];
} human;

typedef struct need {
	int key;
	int X;
	int Y;
	int FX;
	int FY;
} need;

typedef struct need2 {
	int key2;
	int X2;
	int Y2;
	int FX2;
	int FY2;
} need2;

typedef struct need3 {
	int key3;
	int X3;
	int Y3;
	int FX3;
	int FY3;
} need3;

typedef struct rankOutPut {
	char name[30];
	double Score;
} rop;


int map[MAPSIZE][MAPSIZE] = {
  {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
  {1, 2, 1, 0, 1, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1},
  {1, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 1, 0, 1, 0, 1},
  {1, 0, 1, 0, 1, 1, 0, 1, 0, 0, 0, 1, 1, 0, 1, 1, 0, 1, 0, 1, 0, 0, 1, 0, 1},
  {1, 0, 1, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 1, 0, 1},
  {1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 1},
  {1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 1, 0, 0, 1, 0, 1, 1, 1, 1, 0, 1},
  {1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1},
  {1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1},
  {1, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1},
  {1, 0, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 0, 1, 1, 0, 1, 1, 1, 0, 0, 1, 0, 1},
  {1, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0, 1},
  {1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 0, 1},
  {1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1},
  {1, 1, 1, 1, 0, 1, 1, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 1, 1, 1, 0, 1, 1, 0, 1},
  {1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1},
  {1, 0, 1, 1, 0, 0, 1, 0, 1, 1, 1, 1, 0, 1, 0, 0, 1, 1, 0, 1, 1, 1, 0, 1, 1},
  {1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 0, 1, 0, 1, 0, 1, 1},
  {1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 0, 1, 1, 1, 0, 0, 1, 0, 1, 0, 1, 1},
  {1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1},
  {1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 0, 1, 1, 1, 0, 0, 0, 1, 0, 1, 0, 1, 1},
  {1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 1},
  {1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 0, 0, 1, 0, 1, 1, 0, 1},
  {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 3, 1},
  {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}

};//미로 정수형 배열로 틀을 구성함

int map2[MAPSIZE2][MAPSIZE2] =
{
  {1, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
  {1, 0, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1},
  {1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
  {1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1},
  {1, 0, 1, 0, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1},
  {1, 0, 1, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1},
  {1, 0, 1, 0, 1, 1, 1, 1, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1},
  {1, 0, 1, 0, 0, 0, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 1, 0, 1},
  {1, 0, 1, 0, 1, 1, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 1},
  {1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1},
  {1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 1},
  {1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 0, 2},
  {1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1, 0, 1},
  {1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1, 1, 0, 1, 0, 0, 1, 0, 1},
  {1, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 1, 1, 1},
  {1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 1, 1, 0, 1},
  {1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1},
  {1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1},
  {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
  {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

int map3[MAPSIZE3][MAPSIZE3] =
{
  {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
  {1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1},
  {1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
  {3, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
  {1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1},
  {1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1},
  {1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1},
  {1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1},
  {1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1},
  {1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1},
  {1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1},
  {1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1},
  {1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1},
  {1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1},
  {1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1},
  {1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1},
  {1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1},
  {1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
  {1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1},
  {1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
  {1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1},
  {1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1},
  {1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1},
  {1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1},
  {1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1},
  {1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1},
  {1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1},
  {1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1},
  {1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1},
  {1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1},
  {1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1},
  {1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1},
  {1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1},
  {1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
  {1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1},
  {1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1},
  {1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1},
  {1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1},
  {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}

};

char outputmap[MAPSIZE][MAPSIZE];
char outputmap2[MAPSIZE2][MAPSIZE2];
char outputmap3[MAPSIZE3][MAPSIZE3];

void fullscreen() {
	SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0);
}

void remove_scrollbar()
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(handle, &info);
	COORD new_size =
	{
	  info.srWindow.Right - info.srWindow.Left + 1,
	  info.srWindow.Bottom - info.srWindow.Top + 1
	};
	SetConsoleScreenBufferSize(handle, new_size);
}

void clearCursor()  // 커서 없애기
{
	CONSOLE_CURSOR_INFO c;
	c.bVisible = FALSE;    // false = 커서숨김, true = 보임
	c.dwSize = 1;          // 커서두께
	SetConsoleCursorInfo(
		GetStdHandle(STD_OUTPUT_HANDLE),
		&c
	);
}

void gotoxy(int x, int y)  // 커서 위치 이동
{
	COORD pos = { x, y };

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

HWND getConsoleWindowHandle() {

	WCHAR title[2048] = { 0 };
	GetConsoleTitle(title, 2048);
	HWND hWnd = FindWindow(NULL, title);
	SetConsoleTitle(title);
	return hWnd;
}//콘솔 응용 프로그램 창 핸들을 얻는다.

void GetBMP(HDC hdc, HDC memdc, HBITMAP image) {
	BITMAP bitmap;
	HDC bitmapDC = CreateCompatibleDC(hdc);

	GetObject(image, sizeof(bitmap), &bitmap);
	SelectObject(bitmapDC, image);
	BitBlt(memdc, 0, 0, bitmap.bmWidth, bitmap.bmHeight, bitmapDC, 0, 0, SRCCOPY);

	DeleteDC(bitmapDC);
}//memdc에 bitmap를 넣어준다.

void paint(HWND hWnd, HBITMAP image) {

	HDC hdc = GetDC(hWnd);
	HDC memdc = CreateCompatibleDC(hdc);

	//이미지정보를 넣기 위한 공간을 1920*1080으로 만든다.
	HBITMAP bitmap = CreateCompatibleBitmap(hdc, 1920, 1080);

	//해당 이미지 정보와 메모리 공간을 연결시킨다.
	SelectObject(memdc, bitmap);

	//image를 memdc에 담아오도록 한다.
	GetBMP(hdc, memdc, image);

	// 콘솔창에 memdc에 들어 있는 이미지를 1920*1080으로 그려준다.
	StretchBlt(hdc, 0, 0, 1920, 1080, memdc, 0, 0, 1920, 1080, SRCCOPY);

	DeleteDC(memdc);
	DeleteObject(bitmap);
	ReleaseDC(hWnd, hdc);
}

void pushImage() {
	char filename[100];
	HBITMAP bitmap;
	//콘솔창의 핸들을 가져온다.
	HWND hWnd = getConsoleWindowHandle();

	sprintf(filename, "mazewalkerbmp.bmp");
	bitmap = (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	paint(hWnd, bitmap);
}//시작화면 출력

void pushStartImage() {
	char filename[100];
	HBITMAP bitmap;
	//콘솔창의 핸들을 가져온다.
	HWND hWnd = getConsoleWindowHandle();

	sprintf(filename, "start.bmp");
	bitmap = (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	paint(hWnd, bitmap);
}//설명화면 출력

void pushEndingImage() {
	char filename[100];
	HBITMAP bitmap;
	//콘솔창의 핸들을 가져온다.
	HWND hWnd = getConsoleWindowHandle();

	sprintf(filename, "ending.bmp");
	bitmap = (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	paint(hWnd, bitmap);
}//마지막 종료화면 출력


void makeMaze(need* a) {

	for (int i = 0; i < MAPSIZE; i++)
	{
		for (int j = 0; j < MAPSIZE; j++)
		{
			if (map[i][j] == 1)
			{
				outputmap[i][j] = '1';
			}
			else if (map[i][j] == 0)
			{
				outputmap[i][j] = '0';
			}
			else if (map[i][j] == 2)
			{
				outputmap[i][j] = '2';
			}
			else if (map[i][j] == 3)
			{
				outputmap[i][j] = '3';
			}
		}
	}
	printf("%2600s", "\n");
	for (int i = 0; i < MAPSIZE; i++)
	{
		printf("%68s", "  ");
		for (int j = 0; j < MAPSIZE; j++)
		{
			if (outputmap[i][j] == '0')
			{
				printf("  ");
			}

			else if (outputmap[i][j] == '1')
			{
				printf("■");
			}

			else if (outputmap[i][j] == '2')
			{
				printf("＠");
				a->FX = j;
				a->FY = i;
			}

			else if (outputmap[i][j] == '3')
			{
				a->X = j;
				a->Y = i;
				printf("?");//일부로 1byte이모티콘을 넣어 미로가 흔들려 어지럽게 만드는 효과를 주게 만듬
			}
		}
		printf("\n");
	}
}//첫번째 미로 출력

void moveStar(need* a) {

	Sleep(30);
	if (GetAsyncKeyState(UP))
	{
		if (map[a->Y - 1][a->X] != 1)
		{
			map[a->Y][a->X] = 0;
			map[a->Y - 1][a->X] = 3;
		}
	}

	else if (GetAsyncKeyState(DOWN))
	{
		if (map[a->Y + 1][a->X] != 1)
		{
			map[a->Y][a->X] = 0;
			map[a->Y + 1][a->X] = 3;
		}
	}

	else if (GetAsyncKeyState(LEFT))
	{
		if (map[a->Y][a->X - 1] != 1)
		{
			map[a->Y][a->X] = 0;
			map[a->Y][a->X - 1] = 3;
		}
	}

	else if (GetAsyncKeyState(RIGHT))
	{
		if (map[a->Y][a->X + 1] != 1)
		{
			map[a->Y][a->X] = 0;
			map[a->Y][a->X + 1] = 3;
		}
	}
}//첫번쨰 미로 캐릭터 이동하게 만들어주는 함수



void makeMaze2(need2* b) {

	for (int i = 0; i < MAPSIZE2; i++)
	{
		for (int j = 0; j < MAPSIZE2; j++)
		{
			if (map2[i][j] == 1)
			{
				outputmap2[i][j] = '1';
			}
			else if (map2[i][j] == 0)
			{
				outputmap2[i][j] = '0';
			}
			else if (map2[i][j] == 2)
			{
				outputmap2[i][j] = '2';
			}
			else if (map2[i][j] == 3)
			{
				outputmap2[i][j] = '3';
			}
		}
	}
	printf("%2600s", "\n");
	for (int i = 0; i < MAPSIZE2; i++)
	{
		printf("%68s", "  ");
		for (int j = 0; j < MAPSIZE2; j++)
		{
			if (outputmap2[i][j] == '0')
			{
				printf("  ");
			}

			else if (outputmap2[i][j] == '1')
			{
				printf("■");
			}

			else if (outputmap2[i][j] == '2')
			{
				printf("＠");
				b->FX2 = j;
				b->FY2 = i;
			}

			else if (outputmap2[i][j] == '3')
			{
				b->X2 = j;
				b->Y2 = i;
				printf("?");//일부로 1byte이모티콘을 넣어 미로가 흔들려 어지럽게 만드는 효과를 주게 만듬
			}
		}
		printf("\n");
	}
}//두번째 미로출력

void moveStar2(need2* b) {

	Sleep(30);
	if (GetAsyncKeyState(UP))
	{
		if (map2[b->Y2 - 1][b->X2] != 1)
		{
			map2[b->Y2][b->X2] = 0;
			map2[b->Y2 - 1][b->X2] = 3;
		}
	}

	else if (GetAsyncKeyState(DOWN))
	{
		if (map2[b->Y2 + 1][b->X2] != 1)
		{
			map2[b->Y2][b->X2] = 0;
			map2[b->Y2 + 1][b->X2] = 3;
		}
	}

	else if (GetAsyncKeyState(LEFT))
	{
		if (map2[b->Y2][b->X2 - 1] != 1)
		{
			map2[b->Y2][b->X2] = 0;
			map2[b->Y2][b->X2 - 1] = 3;
		}
	}

	else if (GetAsyncKeyState(RIGHT))
	{
		if (map2[b->Y2][b->X2 + 1] != 1)
		{
			map2[b->Y2][b->X2] = 0;
			map2[b->Y2][b->X2 + 1] = 3;
		}
	}
}//두번째 미로 에서 캐릭터가 움직이게 만드는 함수


void makeMaze3(need3* c) {

	for (int i = 0; i < MAPSIZE3; i++)
	{
		for (int j = 0; j < MAPSIZE3; j++)
		{
			if (map3[i][j] == 1)
			{
				outputmap3[i][j] = '1';
			}
			else if (map3[i][j] == 0)
			{
				outputmap3[i][j] = '0';
			}
			else if (map3[i][j] == 2)
			{
				outputmap3[i][j] = '2';
			}
			else if (map3[i][j] == 3)
			{
				outputmap3[i][j] = '3';
			}
		}
	}
	printf("%1500s", "\n");
	for (int i = 0; i < MAPSIZE3; i++)
	{
		printf("%53s", "  ");
		for (int j = 0; j < MAPSIZE3; j++)
		{
			if (outputmap3[i][j] == '0')
			{
				printf("  ");
			}

			else if (outputmap3[i][j] == '1')
			{
				printf("■");
			}

			else if (outputmap3[i][j] == '2')
			{
				printf("＠");
				c->FX3 = j;
				c->FY3 = i;
			}

			else if (outputmap3[i][j] == '3')
			{
				c->X3 = j;
				c->Y3 = i;
				printf("?");//일부로 1byte이모티콘을 넣어 미로가 흔들려 어지럽게 만드는 효과를 주게 만듬
			}
		}
		printf("\n");
	}
}// 세번째 미로 출력

void moveStar3(need3* c) {

	Sleep(0.001);
	if (GetAsyncKeyState(UP))
	{
		if (map3[c->Y3 - 1][c->X3] != 1)
		{
			map3[c->Y3][c->X3] = 0;
			map3[c->Y3 - 1][c->X3] = 3;
		}
	}

	else if (GetAsyncKeyState(DOWN))
	{
		if (map3[c->Y3 + 1][c->X3] != 1)
		{
			map3[c->Y3][c->X3] = 0;
			map3[c->Y3 + 1][c->X3] = 3;
		}
	}

	else if (GetAsyncKeyState(LEFT))
	{
		if (map3[c->Y3][c->X3 - 1] != 1)
		{
			map3[c->Y3][c->X3] = 0;
			map3[c->Y3][c->X3 - 1] = 3;
		}
	}

	else if (GetAsyncKeyState(RIGHT))
	{
		if (map3[c->Y3][c->X3 + 1] != 1)
		{
			map3[c->Y3][c->X3] = 0;
			map3[c->Y3][c->X3 + 1] = 3;
		}
	}
}//세번째 미로에서 캐릭터가 움직이게 만들어줌

void reStart() {

	if (GetAsyncKeyState(R))
	{
		map[1][1] = 2;
		map[23][23] = 3;
		map2[0][1] = 3;
		map2[11][19] = 2;
		map3[3][0] = 3;
		map3[0][25] = 2;
	}


}//게임을 다시시작할수 있게 해주는 함수

void save(human* h) {
	FILE* fp1 = fopen("ranking.txt", "a");

	printf("Time : %.2lf\n", h->record);
	printf("이름을 입력하세요");
	scanf("%s", h->name);
	printf("이름: %s 기록: %.2lf", h->name, h->record);

	Sleep(1000); // ? 9o
	if (fp1 == NULL) {
		printf("저장 실패");
		return 1;
	}
	fprintf(fp1, "%s %.2lf\n", h->name, h->record);
	fclose(fp1);
	printf("  저장 완료");
	Sleep(1000);
	system("cls");
}//기록을 띄워준후 txt파일에 기록을 저장함

void rank(rop* r) {
	int i = 0;
	int j = 0;
	int fast = 0;
	FILE* fp1 = fopen("ranking.txt", "r");

	while (fscanf(fp1, "%s %lf\n", r[i].name, &r[i].Score) != EOF)
	{
		i++;
	}

	for (int j = 0; j < i; j++)
	{
		if (r[fast].Score > r[j].Score)
		{
			fast = j;
		}
	}
	gotoxy(75, 23);
	printf("랭킹1위: %s %.2lf", r[fast].name, r[fast].Score);
}//현재까지 기록중 1등을 알려줌


int main() {
first:;
	need a;
	need2 b;
	need3 c;
	human h;
	rop r[10000];

	int key = 0;

	FILE* fp1 = fopen("ranking.txt", "a");
	PlaySound(TEXT("Interstellar Main Theme - Extra Extended - Soundtrack by Hans Zimmer.wav"), NULL, SND_ASYNC | SND_LOOP); //음악재생 다시시작하면 노래가 처음부터 출력되게 만듬

	fullscreen();//전체화면
	remove_scrollbar();//스크롤바 삭제


	while (!GetAsyncKeyState(ENTER))
	{
		pushImage();
	}//enter누르기 전까지 이미지 출력

	Sleep(400);
	while (!GetAsyncKeyState(ENTER))
	{
		pushStartImage();
	}//enter누르기 전까지 이미지 출력

	system("cls");

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	//색상 변경

	makeMaze(&a);
	clock_t start = clock();
	//시작하자마자 플레이 타임 카운트
	while (map[a.FY][a.FX] == 2)
	{
		clearCursor();//커서를 숨김
		moveStar(&a);
		gotoxy(0, 0);
		makeMaze(&a);
	}
	system("cls");//화면 초기화

	//stage1

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
	//색상 변경

	makeMaze2(&b);
	while (map2[b.FY2][b.FX2] == 2)
	{
		clearCursor();//커서를 숨김
		moveStar2(&b);
		gotoxy(0, 0);
		makeMaze2(&b);
	}
	system("cls");// 화면 초기화


	//stage2

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	//색상 변경

	makeMaze3(&c);
	while (map3[c.FY3][c.FX3] == 2)
	{
		clearCursor();//커서를 숨김
		moveStar3(&c);
		gotoxy(0, 0);
		makeMaze3(&c);
	}
	//stage3

	clock_t end = clock();//플레이 타임 카운트 종료
	system("cls");

	h.record = ((double)(end - start) / CLOCKS_PER_SEC);//플레이 타임 구조체에 저장

	save(&h);

	rank(&r);

	Sleep(2000);

	system("cls");//화면 초기화

	Sleep(100);//Sleep을 안주면 key받는것이 중복되어 동시에 이미지가 넘어가 Sleep을 넣어줌

	while (1)
	{
		if (key == 102)
		{
			return 0;
		}
		else if (key == 114) {
			map[1][1] = 2;
			map[23][23] = 3;
			map2[0][1] = 3;
			map2[11][19] = 2;
			map3[3][0] = 3;
			map3[0][25] = 2;

			goto first;
		}

		pushEndingImage();

		key = _getch();
	}//마지막 ending이미지 출력하고 r은 다시시작 f는 종료 구현



}
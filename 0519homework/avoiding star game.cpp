/*
	별피하기 구성 요소

	보드 : 
		보드판, 
		점수, 
		각 요소 위치 갱신, - ?
		위치 출력

	플레이어 : 
		좌표, 
		좌우 움직이기

	별 : 
		일정 갯수 생성, 
		x축 무작위, 
		자동으로 y축 1씩 증가
		피하면 점수 증가

	각 구성요소를 엮는 법..?
*/

#include <iostream>
#include <random>
#include <conio.h>
#include <Windows.h>

using namespace std;

random_device rd;
mt19937_64 mersenne(rd());
uniform_int_distribution<> randNum(1, 12);

struct Coordinate
{
	int x;
	int y;
};

class Board
{
	int BoardArray[16][14] = {
		{3,3,3,3,3,3,3,3,3,3,3,3,3,3},
		{3,0,0,0,0,0,0,0,0,0,0,0,0,3},
		{3,0,0,0,0,0,0,0,0,0,0,0,0,3}, 
		{3,0,0,0,0,0,0,0,0,0,0,0,0,3}, 
		{3,0,0,0,0,0,0,0,0,0,0,0,0,3}, 
		{3,0,0,0,0,0,0,0,0,0,0,0,0,3}, 
		{3,0,0,0,0,0,0,0,0,0,0,0,0,3}, 
		{3,0,0,0,0,0,0,0,0,0,0,0,0,3}, 
		{3,0,0,0,0,0,0,0,0,0,0,0,0,3}, 
		{3,0,0,0,0,0,0,0,0,0,0,0,0,3}, 
		{3,0,0,0,0,0,0,0,0,0,0,0,0,3}, 
		{3,0,0,0,0,0,0,0,0,0,0,0,0,3}, 
		{3,0,0,0,0,0,0,0,0,0,0,0,0,3}, 
		{3,0,0,0,0,0,0,0,0,0,0,0,0,3}, 
		{3,0,0,0,0,0,0,1,0,0,0,0,0,3}, 
		{3,3,3,3,3,3,3,3,3,3,3,3,3,3}
	}; // 가로 14 *  세로 16 보드판, 0 : 공백, 1 : 플레이어, 2 : 별, 3 : 벽
	int score = 0; // 점수 초기화

public:
	void SetScore()
	{
		score += 100;
	}
	
	int GetScore() { return score; }

	void SetBoard(Player& player, Stars& stars) // 각 요소 위치 세팅
	{

	}
	
	void DrawBoard() // 위치 출력
	{
		system("cls");

		for (int i = 0; i < 16; i++)
		{
			for (int j = 0; j < 14; j++)
			{
				switch (BoardArray[i][j])
				{
				case 0: // 공백
					cout << "  ";
					break;
				case 1: // 플레이어
					cout << "◆";
					break;
				case 2: // 별
					cout << "★";
					break;
				case 3: // 벽
					cout << "■";
					break;
				}
			}
			cout << endl;
		}
	}
};

class Player
{
	Coordinate pCoordinate = { 7, 14 }; // 처음 시작지점
	int BoardNum = 1;

public:
	int GetPlayerXcoordinate() { return pCoordinate.x; }

	int GetPlayerYcoordinate() { return pCoordinate.y; }

	int GetPlayerNum() { return BoardNum; }

	void MovingPlayer()
	{
		if (GetAsyncKeyState(VK_RIGHT) & 0x8000 && pCoordinate.x < 12)
		{
			pCoordinate.x++;
		}
		else if (GetAsyncKeyState(VK_LEFT) & 0x8000 && pCoordinate.x > 1)
		{
			pCoordinate.x--;
		}
	}
};

class Stars
{
	// 별은 x 좌표 1 ~ 12 중 랜덤하게 드랍 
	Coordinate sCoordinate = { randNum(mersenne), 1 };
	int BoardNum = 2;
	int Velocity = 1;

public:
	int GetStarsXcoordinate() { return sCoordinate.x; }

	int GetStarsYcoordinate() { return sCoordinate.y; }

	int GetStarsNum() { return BoardNum; }

	void MovingStar(Board& board)
	{
		sCoordinate.y++;
		if (sCoordinate.y == 15)
			board.SetScore();
	}
};

int main()
{
	HANDLE hOP; // 핸들값 가져오기
	hOP = GetStdHandle(STD_OUTPUT_HANDLE);

	// 커서 숨기기
	CONSOLE_CURSOR_INFO curInfo;
	curInfo.bVisible = false;
	curInfo.dwSize = 1;
	SetConsoleCursorInfo(hOP, &curInfo);

	return 0;
}
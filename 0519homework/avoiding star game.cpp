/*
	�����ϱ� ���� ���

	���� : 
		������, 
		����, 
		�� ��� ��ġ ����, - ?
		��ġ ���

	�÷��̾� : 
		��ǥ, 
		�¿� �����̱�

	�� : 
		���� ���� ����, 
		x�� ������, 
		�ڵ����� y�� 1�� ����
		���ϸ� ���� ����

	�� ������Ҹ� ���� ��..?
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
	}; // ���� 14 *  ���� 16 ������, 0 : ����, 1 : �÷��̾�, 2 : ��, 3 : ��
	int score = 0; // ���� �ʱ�ȭ

public:
	void SetScore()
	{
		score += 100;
	}
	
	int GetScore() { return score; }

	void SetBoard(Player& player, Stars& stars) // �� ��� ��ġ ����
	{

	}
	
	void DrawBoard() // ��ġ ���
	{
		system("cls");

		for (int i = 0; i < 16; i++)
		{
			for (int j = 0; j < 14; j++)
			{
				switch (BoardArray[i][j])
				{
				case 0: // ����
					cout << "  ";
					break;
				case 1: // �÷��̾�
					cout << "��";
					break;
				case 2: // ��
					cout << "��";
					break;
				case 3: // ��
					cout << "��";
					break;
				}
			}
			cout << endl;
		}
	}
};

class Player
{
	Coordinate pCoordinate = { 7, 14 }; // ó�� ��������
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
	// ���� x ��ǥ 1 ~ 12 �� �����ϰ� ��� 
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
	HANDLE hOP; // �ڵ鰪 ��������
	hOP = GetStdHandle(STD_OUTPUT_HANDLE);

	// Ŀ�� �����
	CONSOLE_CURSOR_INFO curInfo;
	curInfo.bVisible = false;
	curInfo.dwSize = 1;
	SetConsoleCursorInfo(hOP, &curInfo);

	return 0;
}
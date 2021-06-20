#include <iostream>
#include <conio.h>
using namespace std;

struct _tagPoint
{
	int x;
	int y;
};

typedef _tagPoint POINT;
typedef _tagPoint* PPOINT;

typedef struct _tagPlayer
{
	_tagPoint tPos;
	bool bWallPush;
	bool bTransParency;
	int iBombPower;
}PLAYER, *PPLAYER;


void SetMaze(char Maze[21][21], PPLAYER pPlayer, PPOINT pStartPos, PPOINT pEndPos) {
	// 0 wall 1 road, 2 start, 3 end 
	// 4 bomb, 5 item1 power up, 6 item2 push, 7 item3 fly
	pStartPos->x = 0;
	pStartPos->y = 0;
	pEndPos->x = 19;
	pEndPos->y = 19;

	pPlayer->tPos = *pStartPos;

	strcpy_s(Maze[0],  "21000000000000000000");
	strcpy_s(Maze[1],  "01000000000000040000");
	strcpy_s(Maze[2],  "01000005005000000000");
	strcpy_s(Maze[3],  "01000000000000000000");
	strcpy_s(Maze[4],  "01000000000000000000");
	strcpy_s(Maze[5],  "01000000000000000000");
	strcpy_s(Maze[6],  "01000007560000000000");
	strcpy_s(Maze[7],  "01000000000000000000");
	strcpy_s(Maze[8],  "01000000000000000000");
	strcpy_s(Maze[9],  "01000000000000000000");
	strcpy_s(Maze[10], "01000000000000000000");
	strcpy_s(Maze[11], "01000500000000000000");
	strcpy_s(Maze[12], "01000000000000000000");
	strcpy_s(Maze[13], "01000000000000000000");
	strcpy_s(Maze[14], "01000000005000000000");
	strcpy_s(Maze[15], "01000000000000000000");
	strcpy_s(Maze[16], "01000000000000000000");
	strcpy_s(Maze[17], "01000000000050000000");
	strcpy_s(Maze[18], "01000000000070000000");
	strcpy_s(Maze[19], "01111111111111111113");
	
}

void Output(char Maze[21][21], PPLAYER pPlayer)
{
	for (int i = 0; i < 21; ++i)
	{
		for (int j = 0; j < 21; ++j)
		{
			if (pPlayer->tPos.x == j && pPlayer->tPos.y == i)
				cout << "¡Û";

			else if (Maze[i][j] == '0')
				cout << "¡á";
			else if (Maze[i][j] == '1')
				cout << "¡¡"; // ¤¡ ÇÑÀÚ 1
			else if (Maze[i][j] == '2') // start
				cout << "¡Ù";
			else if (Maze[i][j] == '3') // end
				cout << "¡Ú";
			else if (Maze[i][j] == '4') // bomb
				cout << "¡Ý";
			else if (Maze[i][j] == '5') // power up
				cout << "¨Ü";
			else if (Maze[i][j] == '6') // kick
				cout << "¨×";
			else if (Maze[i][j] == '7') // fly
				cout << "¨Ò";
			
		}
		printf("\n");
	}
	cout << "ÆøÅº ÆÄ¿ö: " << pPlayer->iBombPower << endl;
	cout << "º®Åë°ú: ";
	if (pPlayer->bTransParency)
		cout << "ON\t";
	else
		cout << "OFF\t";
	cout << "º®¹Ð±â: ";
	if (pPlayer->bWallPush)
		cout << "ON\n";
	else
		cout << "OFF\n";
}
bool AddItem(char cItemType, PPLAYER pPlayer)
{
	switch (cItemType)
	{
	case '5':
		++pPlayer->iBombPower;
		return true;
	case '6':
		pPlayer->bWallPush = true;
		return true;
	case '7':
		pPlayer->bTransParency = true;
		return true;
	}
	return false;
}

void MoveUp(char Maze[21][21], PPLAYER pPlayer)
{
	if (pPlayer->tPos.y - 1 >= 0)
	{
		if (pPlayer->bTransParency)
			--pPlayer->tPos.y;
		else if (Maze[pPlayer->tPos.y - 1][pPlayer->tPos.x] != '0'
			&& Maze[pPlayer->tPos.y - 1][pPlayer->tPos.x] != '4')
			--pPlayer->tPos.y;

		if (AddItem(Maze[pPlayer->tPos.y][pPlayer->tPos.x], pPlayer))
			Maze[pPlayer->tPos.y][pPlayer->tPos.x] = '1';
	}
		
}
void MoveDown(char Maze[21][21], PPLAYER pPlayer)
{
	if (pPlayer->tPos.y + 1 < 20)
	{
		if (pPlayer->bTransParency)
			++pPlayer->tPos.y;
		else if (Maze[pPlayer->tPos.y + 1][pPlayer->tPos.x] != '0'
			&& Maze[pPlayer->tPos.y + 1][pPlayer->tPos.x] != '4')
			++pPlayer->tPos.y;

		if (AddItem(Maze[pPlayer->tPos.y][pPlayer->tPos.x], pPlayer))
			Maze[pPlayer->tPos.y][pPlayer->tPos.x] = '1';
	}
}
void MoveLeft(char Maze[21][21], PPLAYER pPlayer)
{
	if (pPlayer->tPos.x - 1 >= 0) 
	{
		if (pPlayer->bTransParency)
			--pPlayer->tPos.x;
		else if (Maze[pPlayer->tPos.y][pPlayer->tPos.x - 1] != '0'
			&& Maze[pPlayer->tPos.y][pPlayer->tPos.x - 1] != '4')
			--pPlayer->tPos.x;

		if (AddItem(Maze[pPlayer->tPos.y][pPlayer->tPos.x], pPlayer))
			Maze[pPlayer->tPos.y][pPlayer->tPos.x] = '1';
	}
}
void MoveRight(char Maze[21][21], PPLAYER pPlayer)
{
	if (pPlayer->tPos.x + 1 < 20) {
		if (pPlayer->bTransParency)
			++pPlayer->tPos.x;
		else if (Maze[pPlayer->tPos.y][pPlayer->tPos.x + 1] != '0'
			&& Maze[pPlayer->tPos.y][pPlayer->tPos.x + 1] != '4')
			++pPlayer->tPos.x;

		if (AddItem(Maze[pPlayer->tPos.y][pPlayer->tPos.x], pPlayer))
			Maze[pPlayer->tPos.y][pPlayer->tPos.x] = '1';
	}
}


void MovePlayer(char Maze[21][21], PPLAYER pPlayer, char cInput)
{
	switch (cInput)
	{
	case 'w': case'W':
		MoveUp(Maze, pPlayer);
		break;
	case 'a': case'A':
		MoveLeft(Maze, pPlayer);
		break;
	case 's': case'S':
		MoveDown(Maze, pPlayer);
		break;
	case 'd': case'D':
		MoveRight(Maze, pPlayer);
		break;
	default:
		break;
	}
}

void CreateBomb(char Maze[21][21], const PPLAYER pPlayer, PPOINT pBombArr, int* pBombCount) 
{
	if (*pBombCount == 5)
		return;

	if (Maze[pPlayer->tPos.y][pPlayer->tPos.x] == '0')
		return;

	for (int i = 0; i < *pBombCount; i++)
	{
		if (pPlayer->tPos.x == pBombArr[i].x && pPlayer->tPos.y == pBombArr[i].y)
			return;
	}

	pBombArr[*pBombCount] = pPlayer->tPos;
	++(*pBombCount);
	Maze[pPlayer->tPos.y][pPlayer->tPos.x] = '4';
}

void FireBomb(char Maze[21][21], const PPLAYER pPlayer, PPOINT pBombArr, int* iBombCount) 
{
	//Maze[pPlayer->y][pPlayer->x] = '5';
	for (int i = 0; i < *iBombCount; i++)
	{
		for (int power = 1; power <= pPlayer->iBombPower; power++)
		{
			if (pBombArr[i].y - power >= 0) 
			{
				if (Maze[pBombArr[i].y - power][pBombArr[i].x] == '5' ||
					Maze[pBombArr[i].y - power][pBombArr[i].x] == '6' ||
					Maze[pBombArr[i].y - power][pBombArr[i].x] == '7')
				{
					Maze[pBombArr[i].y - power][pBombArr[i].x] = '1';
				}
				else if (Maze[pBombArr[i].y - power][pBombArr[i].x] == '0')
				{
					Maze[pBombArr[i].y - power][pBombArr[i].x] = '1';
					break;
				}
			}
		}
		for (int power = 1; power <= pPlayer->iBombPower; power++)
		{
			if (pBombArr[i].y + power < 20) 
			{
				if (Maze[pBombArr[i].y + power][pBombArr[i].x] == '5' ||
					Maze[pBombArr[i].y + power][pBombArr[i].x] == '6' ||
					Maze[pBombArr[i].y + power][pBombArr[i].x] == '7')
				{
					Maze[pBombArr[i].y + power][pBombArr[i].x] = '1';
				}
				else if (Maze[pBombArr[i].y + power][pBombArr[i].x] == '0')
				{
					Maze[pBombArr[i].y + power][pBombArr[i].x] = '1';
					break;

				}
			}
		}
		for (int power = 1; power <= pPlayer->iBombPower; power++)
		{
			if (pBombArr[i].x - power >= 0)
			{
				if (Maze[pBombArr[i].y][pBombArr[i].x - power] == '5' ||
					Maze[pBombArr[i].y][pBombArr[i].x - power] == '6' ||
					Maze[pBombArr[i].y][pBombArr[i].x - power] == '7')
				{
					Maze[pBombArr[i].y][pBombArr[i].x - power] = '1';
				}
				else if (Maze[pBombArr[i].y][pBombArr[i].x - power] == '0')
				{
					Maze[pBombArr[i].y][pBombArr[i].x - power] = '1';
					break;
				}
			}
		}
		for (int power = 1; power <= pPlayer->iBombPower; power++)
		{
			if (pBombArr[i].x + power < 20)
			{
				if (Maze[pBombArr[i].y][pBombArr[i].x + power] == '5' ||
					Maze[pBombArr[i].y][pBombArr[i].x + power] == '6' ||
					Maze[pBombArr[i].y][pBombArr[i].x + power] == '7')
				{
					Maze[pBombArr[i].y][pBombArr[i].x + power] = '1';
				}
				else if (Maze[pBombArr[i].y][pBombArr[i].x + power] == '0')
				{
					Maze[pBombArr[i].y][pBombArr[i].x + power] = '1';
					break;
				}
			}
		}
		Maze[pBombArr[i].y][pBombArr[i].x] = '1';
	}
	*iBombCount = 0;
}

int main() {
	// 20 * 20
	char strMaze[21][21];
	PLAYER tPlayer;
	POINT tStartPos;
	POINT tEndPos;
	tPlayer.iBombPower = 1;
	tPlayer.bWallPush = false;
	tPlayer.bTransParency = false;

	int iBombCount = 0;
	
	POINT tBombPos[5];

	SetMaze(strMaze, &tPlayer, &tStartPos, &tEndPos);
	while (true)
	{
		system("cls");
		Output(strMaze, &tPlayer);

		if (tPlayer.tPos.x == tEndPos.x && tPlayer.tPos.y == tEndPos.y)
		{
			cout << "µµÂøÇß½À´Ï´Ù." << endl;
			break;
		}

		cout << "q: ÆøÅº¼³Ä¡, u: ÆøÅº ÅÍÆ®¸®±â i: º® ¹Ð±â " << endl;
		cout << "w: À§, s:¾Æ·¡, a: ¿ÞÂÊ, d; ¿À¸¥ÂÊ, p: Á¾·á : ";
		char cInput = _getch();
		if (cInput == 'p' || cInput == 'P')
			break;

		else if (cInput == 'q' || cInput == 'Q')
		{
			CreateBomb(strMaze, &tPlayer, tBombPos, &iBombCount);
		}
		else if (cInput == 'u' || cInput == 'U')
		{
			FireBomb(strMaze, &tPlayer, tBombPos, &iBombCount);
		}

		else
			MovePlayer(strMaze, &tPlayer, cInput);

	}

	return 0;
}
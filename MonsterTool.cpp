#include <iostream>

using namespace std;

#define	NAME_SIZE	32

struct _tagMonster
{
	char	strName[NAME_SIZE];
	int		iAttackMin;
	int		iAttackMax;
	int		iArmorMin;
	int		iArmorMax;
	int		iHP;
	int		iHPMax;
	int		iMP;
	int		iMPMax;
	int		iLevel;
	int		iExp;
	int		iGoldMin;
	int		iGoldMax;
};

enum MAP_TYPE
{
	MT_EASY,
	MT_NORMAL,
	MT_HARD,
	MT_END
};

enum MAIN_MENU
{
	MM_NONE,
	MM_ADD,
	MM_LOAD,
	MM_SAVE,
	MM_EXIT
};

int InputInt()
{
	int iInput;
	cin >> iInput;

	if (cin.fail())
	{
		cin.clear();
		cin.ignore(1024, '\n');
		return INT_MAX;
	}
	return iInput;
}

void AddMonster(_tagMonster* pMonsterArr)
{
	int iMap = 0;
	while (true)
	{
		system("cls");
		cout << "1. 쉬움" << endl;
		cout << "2. 보통" << endl;
		cout << "3. 어려움" << endl;
		cout << "4. 취소" << endl;
		cout << "메뉴를 선택하세요: ";
		int iMenu = InputInt();
		if (iMenu == 4)
			return;
		else if (iMap < 1 || iMap > 4)
			continue;

		--iMap;
		break;
	}
}

int main()
{
	_tagMonster tMonster[MT_END] = {};

	while (true)
	{
		system("cls");
		cout << "1. 몬스터추가" << endl;
		cout << "2. 읽어오기" << endl;
		cout << "3. 저장" << endl;
		cout << "4. 종료" << endl;
		cout << "메뉴를 선택하세요: ";
		int iMenu = InputInt();
		if (iMenu == MM_EXIT)
			break;

		switch (iMenu) 
		{
		case MM_ADD:
			AddMonster(tMonster);
			break;
		case MM_LOAD:
			break;
		case MM_SAVE:
			break;
		}
	}
		 
	return 0;
}
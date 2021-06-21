#include "List.h"


enum MAIN_MENU
{
	MM_NONE,
	MM_INSERT,
	MM_DELETE,
	MM_SEARCH,
	MM_PRINT,
	MM_EXIT
};

int OutputMenu()
{
	system("cls");
	cout << "1. 추가" << endl;
	cout << "2. 삭제" << endl;
	cout << "3. 탐색" << endl;
	cout << "4. 출력" << endl;
	cout << "5. 종료" << endl;
	cout << "메뉴를 선택하세요:";
	int iInput = InputInt();
	if (iInput <= MM_NONE || iInput > MM_EXIT)
	{
		return MM_NONE;
	}
	return iInput;

}

void ClearList(PLIST pList)
{
	PNODE pNode = pList->pBegin;
	while (pNode != NULL)
	{
		PNODE	pNext = pNode->pNext;
		delete	pNode;
		pNode = pNext;
	}

	pList->pBegin = NULL;
	pList->pEnd = NULL;
	pList->iSize = 0;

}

int main()
{
	LIST	tList;
	InitList(&tList);


	while (true)
	{
		int iMenu = OutputMenu();
		if (iMenu == MM_EXIT)
			break;

		switch (iMenu)
		{
		case MM_INSERT:
			PushBack(&tList);
			break;
		case MM_DELETE:
			Delete(&tList);
			break;
		case MM_SEARCH:
			Search(&tList);
			break;
		case MM_PRINT:
			Output(&tList);
			break;
		}
	}
	DestroyList(&tList);
	return 0;
}
#include <iostream>

using namespace std;
#define NAME_SIZE 50

enum MAIN_MENU 
{
	MM_NONE,
	MM_INSERT,
	MM_DELETE,
	MM_SEARCH,
	MM_PRINT,
	MM_EXIT
};

// 데이터
typedef struct data
{
	int pk;
	char name[NAME_SIZE];
}DATA, * PDATA;

// 리스트 노드
typedef struct _tagNode
{
	DATA		tData;
	_tagNode*	pNext;
	
}NODE, *PNODE;

// 연결리스트 구조체
typedef struct _tagList
{
	PNODE	pBegin;
	PNODE	pEnd;
	int		iSize;
}LIST, *PLIST;

void InitList(PLIST pList)
{
	pList->pBegin = NULL;
	pList->pEnd = NULL;
	pList->iSize = 0;
}
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
void InputString(char* pString, int iSize)
{
	cin.clear();
	cin.ignore(1024, '\n');
	cin.getline(pString, iSize - 1);
}

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

void Insert(PLIST pList)
{
	system("cls");
	cout << "======추가======" << endl;

	DATA tData = {};
	if (pList->pEnd == NULL)
		tData.pk = 1;
	else
		tData.pk = pList->pEnd->tData.pk + 1;
	cout << "name: ";
	InputString(tData.name, NAME_SIZE);

	// 추가할 노드 생성
	PNODE pNode = new NODE;
	pNode->pNext = NULL;
	pNode->tData = tData;

	if (pList->pBegin == NULL)
		pList->pBegin = pNode;
	else
		pList->pEnd->pNext = pNode;

	pList->pEnd = pNode;
	++pList->iSize;
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
void OutputData(const PDATA pData) 
{
	cout << "--------------" << endl;
	cout << "pk: " << pData->pk << endl;
	cout << "name: " << pData->name << endl;
	cout << "--------------" << endl;
}
void Output(PLIST pList)
{
	system("cls");
	cout << "========= 출력 ==========" << endl;
	cout << "Total: " << pList->iSize << endl;

	PNODE pNode = pList->pBegin;
	while (pNode != NULL)
	{
		OutputData(&pNode->tData);
		pNode = pNode->pNext;
	}
	system("pause");
}

void Delete(PLIST pList) 
{
	system("cls");
	cout << "========= 삭제 ==========" << endl;
	cout << "삭제할 이름을 입력하세요: ";
	char name[NAME_SIZE] = {};
	InputString(name, NAME_SIZE);

	PNODE pNode = pList->pBegin;
	PNODE pPrev = NULL;
	while (pNode != NULL)
	{
		if (strcmp(pNode->tData.name, name) == 0)
		{
			PNODE pNext = pNode->pNext;
			if (pPrev == NULL)
			{
				delete pNode;
				pList->pBegin = pNext;

				if (pNext == NULL)
					pList->pEnd = NULL;
			}
			else
			{
				delete pNode;
				pPrev->pNext = pNext;

				if (pNext == NULL)
					pList->pEnd = pPrev;
			}
			--pList->iSize;
			cout << "삭제 완료" << endl;
			system("pause");
			return;
		}
		pPrev = pNode;
		pNode = pNode->pNext;
	}
	cout << "해당 이름을 찾을수 없습니다." << endl;
	system("pause");
}
void Search(PLIST pList) 
{
	system("cls");
	cout << "========= 탐색 ==========" << endl;
	cout << "탐색할 이름을 입력하세요: ";
	char name[NAME_SIZE] = {};
	InputString(name, NAME_SIZE);

	PNODE pNode = pList->pBegin;
	PNODE pPrev = NULL;
	while (pNode != NULL)
	{
		if (strcmp(pNode->tData.name, name) == 0)
		{
			OutputData(&pNode->tData);
			system("pause");
			return;
		}
		pPrev = pNode;
		pNode = pNode->pNext;
	}
	cout << "해당 이름을 찾을수 없습니다." << endl;
	system("pause");
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
			Insert(&tList);
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
	ClearList();
	return 0;
}
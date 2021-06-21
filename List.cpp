#include "List.h"

unsigned long long g_pk = 0;
enum OUTPUT_TYPE
{
	OT_NONE,
	OT_OUTPUT,
	OT_INVERSE,
};

void InitList(PLIST pList)
{
	pList->iSize = 0;

	// 데이터를 저장하는 노드가 아님
	pList->pBegin = new NODE;
	pList->pEnd = new NODE;

	pList->pBegin->pNext = pList->pEnd;
	pList->pEnd->pPrev = pList->pBegin;

	pList->pEnd->pNext = NULL;
	pList->pBegin->pPrev = NULL;

}

void DestroyList(PLIST pList)
{
	PNODE pNode = pList->pBegin;
	
	while (pNode != NULL)
	{
		PNODE pNext = pNode->pNext;
		delete pNode;
		pNode = pNext;
	}
	pList->iSize = 0;
	pList->pBegin = NULL;
	pList->pEnd = NULL;

}

void PushBack(PLIST pList)
{
	system("cls");
	cout << "======추가======" << endl;

	DATA tData = {};
	
	tData.pk = g_pk;
	g_pk++;
	cout << "name: ";
	InputString(tData.name, NAME_SIZE);

	PNODE pNode = new NODE;
	pNode->tData = tData;
	 
	// 새로 추가되는 노드는 end노드의 이전노드와 end 노드 사이에 추가해됨
	PNODE pPrev = pList->pEnd->pPrev;
	pPrev->pNext = pNode;
	pNode->pPrev = pPrev;

	pNode->pNext = pList->pEnd;
	pList->pEnd->pPrev = pNode;
	
	++pList->iSize;

}

void PushFront(PLIST pList)
{
}

void Output(PLIST pList)
{
	int iMenu;
	while (true)
	{
		system("cls");
		cout << "========= 출력 ==========" << endl;
		cout << "1. 정방향" << '\t' << "2. 역방향" << endl;
		cout << "메뉴를 선택하세요: ";
		iMenu = InputInt();

		if (iMenu > OT_NONE && iMenu <= OT_INVERSE)
			break;
	}

	cout << "Total: " << pList->iSize << endl;

	PNODE pNode = NULL;
	switch (iMenu)
	{
	case OT_OUTPUT:
		pNode = pList->pBegin->pNext;
		while (pNode != pList->pEnd)
		{
			OutputData(&pNode->tData);
			pNode = pNode->pNext;
		}
		break;
	case OT_INVERSE:
		pNode = pList->pEnd->pPrev;
		while (pNode != pList->pBegin)
		{
			OutputData(&pNode->tData);
			pNode = pNode->pPrev;
		}
		break;
	}

	system("pause");
}
void OutputData(const PDATA pData)
{
	cout << "--------------" << endl;
	cout << "pk: " << pData->pk << endl;
	cout << "name: " << pData->name << endl;
	cout << "--------------" << endl;
}

void Delete(PLIST pList)
{
	system("cls");
	cout << "========= 삭제 ==========" << endl;
	cout << "삭제할 이름을 입력하세요: ";
	char name[NAME_SIZE] = {};
	InputString(name, NAME_SIZE);

	PNODE pNode = pList->pBegin->pNext;
	while (pNode != pList->pEnd)
	{
		if (strcmp(pNode->tData.name, name) == 0)
		{
			pNode->pPrev->pNext = pNode->pNext;
			pNode->pNext->pPrev = pNode->pPrev;
			delete pNode;
			--pList->iSize;
			cout << "삭제 완료" << endl;
			system("pause");
			return;
		}
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

	PNODE pNode = pList->pBegin->pNext;
	while (pNode != pList->pEnd)
	{
		if (strcmp(pNode->tData.name, name) == 0)
		{
			OutputData(&pNode->tData);
			system("pause");
			return;
		}
		pNode = pNode->pNext;
	}
	cout << "해당 이름을 찾을수 없습니다." << endl;
	system("pause");
}
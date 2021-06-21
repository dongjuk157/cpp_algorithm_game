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

	// �����͸� �����ϴ� ��尡 �ƴ�
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
	cout << "======�߰�======" << endl;

	DATA tData = {};
	
	tData.pk = g_pk;
	g_pk++;
	cout << "name: ";
	InputString(tData.name, NAME_SIZE);

	PNODE pNode = new NODE;
	pNode->tData = tData;
	 
	// ���� �߰��Ǵ� ���� end����� �������� end ��� ���̿� �߰��ص�
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
		cout << "========= ��� ==========" << endl;
		cout << "1. ������" << '\t' << "2. ������" << endl;
		cout << "�޴��� �����ϼ���: ";
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
	cout << "========= ���� ==========" << endl;
	cout << "������ �̸��� �Է��ϼ���: ";
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
			cout << "���� �Ϸ�" << endl;
			system("pause");
			return;
		}
		pNode = pNode->pNext;
	}
	cout << "�ش� �̸��� ã���� �����ϴ�." << endl;
	system("pause");
}

void Search(PLIST pList)
{
	system("cls");
	cout << "========= Ž�� ==========" << endl;
	cout << "Ž���� �̸��� �Է��ϼ���: ";
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
	cout << "�ش� �̸��� ã���� �����ϴ�." << endl;
	system("pause");
}
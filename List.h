// #pragma once �� ��������� �� �ѹ��� ���Խ�Ŵ
#pragma once

#include <iostream>

using namespace std;

//������Ͽ��� �Լ� ���� �κ��� ��������
#define NAME_SIZE 50
// ������
typedef struct data
{
	int pk;
	char name[NAME_SIZE];
}DATA, * PDATA;

// ���� ��ũ�� ����Ʈ
typedef struct _tagNode {
	DATA		tData;
	_tagNode* pPrev;
	_tagNode* pNext;
}NODE, * PNODE;


// ���Ḯ��Ʈ ����ü
typedef struct _tagList
{
	PNODE	pBegin;
	PNODE	pEnd;
	int		iSize;
}LIST, * PLIST;

static int InputInt()
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

static void InputString(char* pString, int iSize)
{
	cin.clear();
	cin.ignore(1024, '\n');
	cin.getline(pString, iSize - 1);
}

void InitList(PLIST pList);
//void ClearList(PLIST pList);
void DestroyList(PLIST pList);
void PushBack(PLIST pList);
void PushFront(PLIST pList);
void Output(PLIST pList);
void OutputData(const PDATA pData);
void Delete(PLIST pList);
void Search(PLIST pList);

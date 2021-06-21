// #pragma once 이 헤더파일을 딱 한번만 포함시킴
#pragma once

#include <iostream>

using namespace std;

//헤더파일에는 함수 선언 부분을 만들어놓음
#define NAME_SIZE 50
// 데이터
typedef struct data
{
	int pk;
	char name[NAME_SIZE];
}DATA, * PDATA;

// 더블 링크드 리스트
typedef struct _tagNode {
	DATA		tData;
	_tagNode* pPrev;
	_tagNode* pNext;
}NODE, * PNODE;


// 연결리스트 구조체
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

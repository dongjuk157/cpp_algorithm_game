#include<iostream>
using namespace std;

int main()
{

	FILE*	pFile = NULL;
	// 인자: 파일의 이중 포인터, 파일의 이름, 모드
	// 모드 : rwa 읽기쓰기 접근/ tb 텍스트, 바이너리
	/*
	fopen_s(&pFile, "test.txt","wt");

	if (pFile != NULL)
	{
		// fwrite, fread
		// fputs, fgets
		const char* pText = "abcd";

		// 인자: 
		// 저장하고자하는 값의 메모리주소, 
		// 저장하는 값의 변수 타입의 메모리 크기를 넣어줌
		// 저장하고자 하는 값의 개수
		// 파일의 스트림
		fwrite(pText, 1, 4, pFile);
		fclose(pFile);
		cout << "파일만들기 성공" << endl;
	}*/

	fopen_s(&pFile, "test.txt", "rt");
	if (pFile)
	{
		char strText[5] = {};
		fread(strText, 1, 4, pFile);
		cout << strText << endl;
	}

	return 0;
}
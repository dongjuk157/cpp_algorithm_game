#include<iostream>
using namespace std;

int main()
{

	FILE*	pFile = NULL;
	// ����: ������ ���� ������, ������ �̸�, ���
	// ��� : rwa �б⾲�� ����/ tb �ؽ�Ʈ, ���̳ʸ�
	/*
	fopen_s(&pFile, "test.txt","wt");

	if (pFile != NULL)
	{
		// fwrite, fread
		// fputs, fgets
		const char* pText = "abcd";

		// ����: 
		// �����ϰ����ϴ� ���� �޸��ּ�, 
		// �����ϴ� ���� ���� Ÿ���� �޸� ũ�⸦ �־���
		// �����ϰ��� �ϴ� ���� ����
		// ������ ��Ʈ��
		fwrite(pText, 1, 4, pFile);
		fclose(pFile);
		cout << "���ϸ���� ����" << endl;
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
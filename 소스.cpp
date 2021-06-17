//#include<stdio.h>
//#include<stdlib.h>
//#include<Windows.h>
//#include<conio.h>
//typedef enum { NOCURSOR, SOLIDCURSOR, NORMALCURSOR } CURSOR_TYPE;
//const int refreshRate = 50;
//void setcursortype(CURSOR_TYPE c) {
//	CONSOLE_CURSOR_INFO CurInfo;
//	switch (c)
//	{
//	case NOCURSOR:
//		CurInfo.dwSize = 1;
//		CurInfo.bVisible = FALSE;
//		break;
//	case SOLIDCURSOR:
//		CurInfo.dwSize = 100;
//		CurInfo.bVisible = TRUE;
//		break;
//	case NORMALCURSOR:
//		CurInfo.dwSize = 20;
//		CurInfo.bVisible = TRUE;
//		break;
//	default:
//		break;
//	}
//	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CurInfo);
//}
//
//void gotoxy(int x, int y) {
//	COORD CursorPosition = { x, y };
//	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CursorPosition);
//}
//
//
//int main(void) {
//	setcursortype(NOCURSOR);
//	int x = 0, y = 0;
//	int cnt = 1;
//	int ch;
//	gotoxy(x, y);
//	printf("@");
//	while (1) {
//		ch = '\0';
//		if (_kbhit())
//			ch = _getch();
//		
//		gotoxy(x, y);
//		printf(" ");
//		if (ch == 224) {
//			ch = _getch();
//		}
//		switch (ch) {
//		case (int)'w': case 72:
//			if (y > 0) y--;
//			break;
//		case (int)'s': case 80:
//			if (y < 24) y++;
//			break;
//		case (int)'a': case 75:
//			if (x > 0) x--;
//			break;
//		case (int)'d': case 77:
//			if (x < 79) x++;
//			break;
//		}
//		gotoxy(x, y);
//		printf("@");
//
//		gotoxy(0, 0);
//		printf("%d", cnt);
//		if (cnt % 50 == 0)
//			printf("\n%d", cnt / refreshRate);
//		Sleep(1000 / refreshRate);
//		cnt++;
//	}
//	
//	return 0;
//}
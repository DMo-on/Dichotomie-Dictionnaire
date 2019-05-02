/*
	Nom: DJEBRI MOUNIRA
	Matricule:201500009092
	Section:ISIL B
	Gr:01
	Date: 09/12/16 20:10
	Description: Projet recherche dichotomique dans dico
*/
#ifndef __ALT_CONIO_H__
#define __ALT_CONIO_H__


void gotoxy(int x,int y);
void setx(int x);
void sety(int y);
void setcolor(unsigned short color,unsigned short bg);
void delay(unsigned long milisec);
void setcursor(int ctype);
void clrscr(void);
int getx(void);
int gety(void);
int assert(int x);
#ifndef ALT_OUTPUT
int print(const char *x);
#endif
//char getc(int kc);
int align(int align,const char *str);

#include <windows.h>
#include <conio.h>
#include <time.h>

#define WIN_32_LEAN_AND_MEAN

#define KEY_HOME   71
#define KEY_UP     72
#define KEY_PGUP   73
#define KEY_LEFT   75
#define KEY_CENTER 76
#define KEY_RIGHT  77
#define KEY_END    79
#define KEY_DOWN   80
#define KEY_PGDN   81
#define KEY_INSERT 82
#define KEY_DELETE 83
#define KEY_F1     59
#define KEY_F2     60
#define KEY_F3     61
#define KEY_F4     62
#define KEY_F5     63
#define KEY_F6     64
#define KEY_F7     65
#define KEY_F8     66
#define KEY_F9     67
#define KEY_SPC    32
#define KEY_BACKSPACE 8
#define KEY_TAB     9
#define KEY_ENTER  13
#define KEY_ESC    27

#define LEFT   0
#define CENTER 1
#define RIGHT  2

#define _NOCURSOR     0
#define _SOLIDCURSOR  1
#define _MEDIUMCURSOR 2
#define _NORMALCURSOR 3

#ifdef ALT_OUTPUT
#define write(x) printf(x)
#else
#define write(x)
#endif

enum colors { BLACK, BLUE, GREEN, CYAN, RED, MAGENTA, BROWN, LIGHTGRAY, GRAY, LIGHTBLUE, LIGHTGREEN, TURQUOISE, LIGHTRED, PINK, YELLOW, WHITE };

union k
{
      char c;
      int i;
} key;

void gotoxy(int x,int y)
{
     setx(x);
     sety(y);
}

void setx(int x)
{
     COORD pos;
     pos.X = x;
     pos.Y = gety();
     SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}

void sety(int y)
{
     COORD pos;
     pos.X = getx();
     pos.Y = y;
     SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}

void setcolor(unsigned short int color,unsigned short int bg)
{
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),((bg*16)+(color)));
}

void delay(unsigned long int milisec)
{
     clock_t start,end,loop;
     start = clock();
     end = (start+milisec);

     do {
         loop = clock();
     } while(loop<end);
}

void setcursor(int ctype)
{
     CONSOLE_CURSOR_INFO type;
     switch(ctype)
     {
		  case _NOCURSOR:
			   type.bVisible = 0;
			   break;
		  case _SOLIDCURSOR:
			   type.dwSize = 100;
			   type.bVisible = 1;
			   break;
		  case _MEDIUMCURSOR:
			   type.dwSize = 50;
			   type.bVisible = 1;
			   break;
		  case _NORMALCURSOR:
			   type.dwSize = 1;
			   type.bVisible = 1;
			   break;
		  default:
			   type.dwSize = 1;
			   type.bVisible = 1;
			   break;
     }
     SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&type);
}

void clrscr()
{
     COORD pos;
     COORD cs = { 0, 0 };
     DWORD written;
     CONSOLE_SCREEN_BUFFER_INFO window;
     pos.X = 0;
     pos.Y = 0;
     GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE),&window);
     FillConsoleOutputCharacter(GetStdHandle(STD_OUTPUT_HANDLE),' ',window.dwSize.X*window.dwSize.Y,cs,&written);
     gotoxy(0,0);
}

int getx(void)
{
    CONSOLE_SCREEN_BUFFER_INFO window;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE),&window);
    return window.dwCursorPosition.X;
}

int gety(void)
{
    CONSOLE_SCREEN_BUFFER_INFO window;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE),&window);
    return window.dwCursorPosition.Y;
}

int assert(int x)
{
    if(!(x)) return 1;
    else if(x) return 0;
}

#ifndef ALT_OUTPUT
int print(const char *x)
{
    printf("%s",x);
}
#endif
/*
char getc(int kc)
{
     key.i = kc;
     key.c = (char)key.i;
     return key.c;
}
*/
int align(int align,const char *str)
{
	int x;
	switch(align)
	{
		case 0:
			x = (0);
			break;
		case 1:
			x = (40-(strlen(str)/2));
			break;
		case 2:
			x = (80-(strlen(str)));
			break;
		default:
			return 1;
		break;
	}
	if(strlen(str) > 79) {
	}
	else {
		gotoxy(x,gety());printf("%s",str);
	}
}

#endif

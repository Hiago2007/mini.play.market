//інклюди
#include <iostream>
#include<windows.h>
#include<time.h>
#include <iostream>
#include <iomanip>
#include <stdint.h>
#include <io.h>
#include <fcntl.h>
#include <Windows.h>
#include <cstdio>
#include <stdio.h>
#include <iostream>
#include <io.h>
#include <fcntl.h>
#include <Windows.h>
#include <conio.h>
#include<string>
using namespace std;

void gotoxy(int x, int y) {
	COORD p = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
}
bool KEY[256];
void GetKEY()
{
	int i = 0;
	while (i < 256)
	{
		if (GetAsyncKeyState(i)) KEY[i] = 1; else KEY[i] = 0;
		i++;
	}
}
void perenos(int x, int y) {
	COORD position_1 = { x,y }; //позиция x и y
	HANDLE hConsole_1 = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsole_1, position_1);
}
void ConsoleCursorVisible(bool show, short size)
{
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &structCursorInfo);
	structCursorInfo.bVisible = show;
	structCursorInfo.dwSize = size;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &structCursorInfo);
}
enum ConsoleColor {
	// Standard text colors
	GRAY = 8, BLUE, GREEN,
	TEAL, RED, PINK,
	YELLOW, WHITE,
	// Faded text colors
	BLACK = 0, BLUE_FADE, GREEN_FADE,
	TEAL_FADE, RED_FADE, PINK_FADE,
	YELLOW_FADE, WHITE_FADE,
};
void SetColor(ConsoleColor text, ConsoleColor background)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (short)text | ((short)background << 4));
}


void skin_ramka() {
	system("cls");
	perenos(12, 3);
	cout << "1) ";
	perenos(13, 3);
	SetColor(WHITE, BLACK);

	cout << "White";
	SetColor(WHITE, BLACK);
	perenos(12, 4);
	cout << "2) ";
	perenos(13, 4);
	SetColor(PINK, BLACK);
	cout << "Pink";
	SetColor(WHITE, BLACK);
	perenos(12, 5);
	cout << "3) ";
	perenos(13, 5);
	SetColor(YELLOW, BLACK);
	cout << "Yellow";
	SetColor(WHITE, BLACK);
	perenos(12, 6);
	cout << "4) ";
	perenos(13, 6);
	SetColor(GREEN, BLACK);
	cout << "Green";
	SetColor(WHITE, BLACK);
	perenos(12, 7);
	cout << "5) ";
	perenos(13, 7);
	SetColor(RED, BLACK);
	cout << "Red";
	SetColor(WHITE, BLACK);
	perenos(12, 8);
	cout << "6) ";
	perenos(13, 8);
	SetColor(TEAL, BLACK);
	cout << "Teal";

	GetKEY();
	int color = 0;
	if (KEY[49])
	{
		color = 1;

	}
	else if (KEY[50]) {
		color = 2;
	}
	else if (KEY[51]) {
		color = 3;
	}
	else if (KEY[52]) {
		color = 4;
	}
	else if (KEY[53]) {
		color = 5;
	}
	else if (KEY[54]) {
		color = 6;
	}
	SetColor(WHITE, BLACK);
	perenos(5, 10);
	cout << "ВИБЕРІТЬ КОЛЬОР";
	perenos(5, 11);
	cout << "СПОМОЩУ ЦИФЕР 1-6";
}

void ramka() {
	perenos(0, 0);
	for (int i = 0; i < 24; i++) {
		cout << "*";
	}

	for (int j = 1; j < 13; j++) {
		perenos(0, j);
		for (int i = 0; i < 24; i++) {

			perenos(i, j);
			if (i == 23) {
				cout << "*" << endl;
			}
		}
	}
	perenos(0, 12);
	for (int i = 0; i < 24; i++) {
		cout << "*";
	}




}

void color_black(int gde) {
	for (int i = 0; i < 23; i++) {
		perenos(i, gde);
		SetColor(RED_FADE, BLACK);
		cout << " ";
	}
}
void color_pink(int gde) {
	for (int i = 0; i < 23; i++) {
		perenos(i, gde);
		SetColor(RED_FADE, PINK_FADE);
		cout << " ";
	}
}
void ball_right(int& gde, int& obman_x, int& obman_y, int& bonus, bool& anti_bonus, int& or_or, int& x_y1, int& i, int& i1, int& i2, int& bonus_per, int& bonus_x, int& bonus_y, int& anti_bonus_x, int& anti_bonus_y, int& bonus_perevirka, int& perevirka) {
	if (anti_bonus == TRUE) {
		if (bonus_per <= 10) {
			bonus_per++;
		}
	}
	if (obman_y == 1 or obman_y == 13 or obman_x == 23 or obman_x == 2) {

		or_or = 1 + rand() % (3);

	}


	if (obman_y == i or obman_y == i1 or obman_y == i2) {
		if (obman_x == 3) {
			or_or = 1 + rand() % (3);
		}
	}

	if (x_y1 == 1) {



		if (or_or == 1) {
			if (obman_y < 14 and obman_x < 24 and obman_y > 0) {




				perenos(obman_x, obman_y);
				cout << " ";

				obman_x++;
				obman_y++;
				if (obman_x > 24) {
					obman_x = 22;
				}
				if (bonus_x == obman_x) {
					if (bonus_y == obman_y) {
						bonus = 2;
						anti_bonus = TRUE;
					}
				}
				if (anti_bonus_x == obman_x) {
					if (anti_bonus_y == obman_y) {
						bonus = 0;
						bonus_perevirka = 0;
					}
				}
				if (obman_y > 12) {
					obman_y = 11;
				}
				if (obman_y == i or obman_y == i1 or obman_y == i2) {
					if (obman_x == 3) {
						perevirka = 1;
					}
				}
				perenos(obman_x, obman_y);
				cout << "o";

				Sleep(85);




			}
		}

		else
			if (or_or == 2) {
				if (obman_y < 14 and obman_x < 24 and obman_y > 0) {

					if (obman_y == i or obman_y == i1 or obman_y == i2) {
						if (obman_x == 3) {
							perevirka = 1;
						}
					}


					perenos(obman_x, obman_y);
					cout << " ";
					obman_x++;
					obman_x++;
					obman_y++;
					if (obman_x > 24) {
						obman_x = 22;
					}
					if (bonus_x == obman_x) {
						if (bonus_y == obman_y) {
							bonus = 2;
							anti_bonus = TRUE;
						}
					}
					if (anti_bonus_x == obman_x) {
						if (anti_bonus_y == obman_y) {
							bonus = 0;
							bonus_perevirka = 0;
						}
					}
					if (obman_y > 12) {
						obman_y = 11;
					}
					perenos(obman_x, obman_y);
					cout << "o";


					Sleep(85);




				}
				if (obman_x == 21) {
					or_or = 1;
				}
			}

			else
				if (or_or == 3) {
					if (obman_y < 14 and obman_x < 24 and obman_y > 0) {

						if (obman_y == i or obman_y == i1 or obman_y == i2) {
							if (obman_x == 3) {
								perevirka = 1;
							}
						}


						perenos(obman_x, obman_y);
						cout << " ";

						obman_x++;
						obman_y++;
						obman_y++;
						if (obman_x > 24) {
							obman_x = 22;
						}
						if (bonus_x == obman_x) {
							if (bonus_y == obman_y) {
								bonus = 2;
								anti_bonus = TRUE;
							}
						}
						if (anti_bonus_x == obman_x) {
							if (anti_bonus_y == obman_y) {
								bonus = 0;
								bonus_perevirka = 0;
							}
						}
						if (obman_y > 12) {
							obman_y = 11;
						}
						perenos(obman_x, obman_y);
						cout << "o";


						Sleep(85);




					}
					if (obman_y == 11) {
						or_or = 1;
					}
				}



		if (obman_y == 12) {
			x_y1 = 2;

		}

		if (obman_x == 22) {
			perevirka = 2;
		}




		//50\50








	}
	//право-верх
	if (x_y1 == 2) {

		if (or_or == 1) {
			if (obman_y < 14 and obman_x < 24 and obman_y > 0) {

				if (obman_y == i or obman_y == i1 or obman_y == i2) {
					if (obman_x == 3) {
						perevirka = 1;
					}
				}


				perenos(obman_x, obman_y);
				cout << " ";

				obman_x++;
				obman_y--;
				if (obman_x > 24) {
					obman_x = 22;
				}
				if (obman_y < 0) {
					obman_y = 1;
				}
				if (bonus_x == obman_x) {
					if (bonus_y == obman_y) {
						bonus = 2;
						anti_bonus = TRUE;
					}
				}
				if (anti_bonus_x == obman_x) {
					if (anti_bonus_y == obman_y) {
						bonus = 0;
						bonus_perevirka = 0;
					}
				}
				perenos(obman_x, obman_y);
				cout << "o";

				Sleep(85);




			}
		}

		else
			if (or_or == 2) {
				if (obman_y < 14 and obman_x < 24 and obman_y > 0) {

					if (obman_y == i or obman_y == i1 or obman_y == i2) {
						if (obman_x == 3) {
							perevirka = 1;
						}
					}


					perenos(obman_x, obman_y);
					cout << " ";
					obman_x++;
					obman_x++;
					obman_y--;
					if (obman_x > 24) {
						obman_x = 22;
					}
					if (obman_y < 0) {
						obman_y = 1;
					}
					if (bonus_x == obman_x) {
						if (bonus_y == obman_y) {
							bonus = 2;
							anti_bonus = TRUE;
						}
					}
					if (anti_bonus_x == obman_x) {
						if (anti_bonus_y == obman_y) {
							bonus = 0;
							bonus_perevirka = 0;
						}
					}
					perenos(obman_x, obman_y);
					cout << "o";


					Sleep(85);




				}
				if (obman_x == 21) {
					or_or = 1;
				}
			}

			else
				if (or_or == 3) {
					if (obman_y < 13 and obman_x < 23 and obman_y > 0) {
						if (obman_y == i or obman_y == i1 or obman_y == i2) {
							if (obman_x == 3) {
								perevirka = 1;
							}
						}



						perenos(obman_x, obman_y);
						cout << " ";

						obman_x++;
						obman_y--;
						obman_y--;
						if (obman_x > 24) {
							obman_x = 22;
						}

						if (obman_y < 0) {
							obman_y = 1;
						}
						if (bonus_x == obman_x) {
							if (bonus_y == obman_y) {
								bonus = 2;
								anti_bonus = TRUE;
							}
						}
						if (anti_bonus_x == obman_x) {
							if (anti_bonus_y == obman_y) {
								bonus = 0;
								bonus_perevirka = 0;
							}
						}
						perenos(obman_x, obman_y);
						cout << "o";


						Sleep(85);




					}
					if (obman_y == 2) {
						or_or = 1;
					}

					if (obman_y == 0) {
						cout << "*";
						perenos(obman_x, 1);
						cout << "o";
						x_y1 = 1;
					}
				}




	}


	if (obman_y == 12) {
		x_y1 = 2;

	}
	if (obman_y == 1) {
		x_y1 = 1;

	}
	if (obman_x == 22) {
		perevirka = 2;
	}




	if (obman_x == 0) {
		perevirka = 2;
	}

	if (obman_y == 0) {
		cout << "*";
		perenos(obman_x, 1);
		cout << "o";
		x_y1 = 1;
	}
}
void ball_left(int& gde, int& obman_x, int& obman_y, int& bonus, bool& anti_bonus, int& or_or, int& x_y1, int& i, int& i1, int& i2, int& bonus_per, int& bonus_x, int& bonus_y, int& anti_bonus_x, int& anti_bonus_y, int& bonus_perevirka, int& perevirka, int& i3, int& chochik, int& x_y, int& right) {
	if (obman_y == 1 or obman_y == 13 or obman_x == 23 or obman_x == 2) {

		or_or = 1 + rand() % (3);

	}


	if (obman_y == i or obman_y == i1 or obman_y == i2) {
		if (obman_x == 3) {
			or_or = 1 + rand() % (3);
		}
	}


	//ліво-верх
	if (x_y == 1) {


		if (or_or == 1) {
			if (obman_y < 14 and obman_x > 1 and obman_y > 0) {

				if (obman_y == i or obman_y == i1 or obman_y == i2) {
					if (obman_x == 3 or obman_x == 2) {
						perevirka = 1;
					}
				}

				perenos(obman_x, obman_y);
				cout << " ";

				obman_x--;
				obman_y--;
				if (obman_y < 0) {
					obman_y = 1;
				}
				if (obman_x > 24) {
					obman_x = 22;
				}
				if (bonus_x == obman_x) {
					if (bonus_y == obman_y) {
						bonus = 2;
						anti_bonus = TRUE;
					}
				}
				if (anti_bonus_x == obman_x) {
					if (anti_bonus_y == obman_y) {
						bonus = 0;
						bonus_perevirka = 0;
					}
				}
				if (bonus == 0) {
					if (obman_y == i or obman_y == i1 or obman_y == i2) {
						if (obman_x == 3) {
							perevirka = 1;
						}
					}
				}
				if (bonus == 2) {
					if (obman_y == i or obman_y == i1 or obman_y == i2 or obman_y == i3) {
						if (obman_x == 3) {
							perevirka = 1;
						}
					}
				}
				perenos(obman_x, obman_y);
				cout << "o";


				Sleep(85);




			}
		}

		else
			if (or_or == 2) {
				if (obman_y < 14 and obman_x > 1 and obman_y > 0) {
					if (obman_y == i or obman_y == i1 or obman_y == i2) {
						if (obman_x == 3 or obman_x == 2) {
							perevirka = 1;
						}
					}



					perenos(obman_x, obman_y);
					cout << " ";
					obman_x--;
					obman_x--;
					obman_y--;
					if (obman_y < 0) {
						obman_y = 1;
					}
					if (obman_x == 0) {
						obman_x = 1;
					}
					if (obman_x > 24) {
						obman_x = 22;
					}
					if (bonus_x == obman_x) {
						if (bonus_y == obman_y) {
							bonus = 2;
							anti_bonus = TRUE;
						}
					}
					if (bonus == 0) {
						if (obman_y == i or obman_y == i1 or obman_y == i2) {
							if (obman_x == 3 or obman_x == 2) {
								perevirka = 1;
							}
						}
					}
					if (anti_bonus_x == obman_x) {
						if (anti_bonus_y == obman_y) {
							bonus = 0;
							bonus_perevirka = 0;
						}
					}
					if (bonus == 2) {
						if (obman_y == i or obman_y == i1 or obman_y == i2 or obman_y == i3) {
							if (obman_x == 3 or obman_x == 2) {
								perevirka = 1;
							}
						}
					}
					perenos(obman_x, obman_y);
					cout << "o";


					Sleep(85);




				}
				if (obman_x == 2) {
					or_or = 1;
				}
			}

			else
				if (or_or == 3) {
					if (obman_y < 14 and obman_x > 1 and obman_y > 0 and obman_y <= 11) {

						if (obman_y == i or obman_y == i1 or obman_y == i2) {
							if (obman_x == 3 or obman_x == 2) {
								perevirka = 1;
							}
						}


						perenos(obman_x, obman_y);
						cout << " ";

						obman_x--;
						obman_y--;
						obman_y--;
						if (obman_y < 0) {
							obman_y = 1;
						}
						if (obman_x > 24) {
							obman_x = 22;
						}
						if (bonus_x == obman_x) {
							if (bonus_y == obman_y) {
								bonus = 2;
								anti_bonus = TRUE;
							}
						}
						if (anti_bonus_x == obman_x) {
							if (anti_bonus_y == obman_y) {
								bonus = 0;
								bonus_perevirka = 0;
							}
						}
						if (bonus == 0) {
							if (obman_y == i or obman_y == i1 or obman_y == i2) {
								if (obman_x == 3 or obman_x == 2) {
									perevirka = 1;
								}
							}
						}
						if (bonus == 2) {
							if (obman_y == i or obman_y == i1 or obman_y == i2 or obman_y == i3) {
								if (obman_x == 3 or obman_x == 2) {
									perevirka = 1;
								}
							}
						}
						perenos(obman_x, obman_y);
						cout << "o";

						Sleep(85);




					}
					if (obman_y == 11) {
						or_or = 1;
					}
				}













		if (obman_y == 12) {
			x_y = 1;

		}

		if (obman_x == 1) {
			perevirka = 1;
		}


		if (obman_y == 1) {
			x_y = 2;

		}
		if (obman_y == -1) {
			perenos(0, 0);
			for (int i = 0; i < right; i++) {
				cout << "*";
			}
			obman_y = 1;

			x_y = 1 + rand() % (2);

		}
		if (obman_y == 0) {
			cout << "*";
			perenos(obman_x, 1);

			x_y = 2;

		}
		if (obman_x == 0) {
			x_y = perevirka = 1;

		}

	}
	//ліво низ
	if (x_y == 2) {
		if (or_or == 1) {
			if (obman_y < 14 and obman_x > 1 and obman_y > 0) {

				if (obman_y == i or obman_y == i1 or obman_y == i2) {
					if (obman_x == 3 or obman_x == 2) {
						perevirka = 1;
					}
				}


				perenos(obman_x, obman_y);
				cout << " ";

				obman_x--;
				obman_y++;
				if (obman_y > 12) {
					obman_y = 11;
				}
				if (obman_x > 24) {
					obman_x = 22;
				}
				if (bonus_x == obman_x) {
					if (bonus_y == obman_y) {
						bonus = 2;
						anti_bonus = TRUE;
					}
				}
				if (bonus == 0) {
					if (obman_y == i or obman_y == i1 or obman_y == i2) {
						if (obman_x == 3 or obman_x == 2) {
							perevirka = 1;
						}
					}
				}
				if (anti_bonus_x == obman_x) {
					if (anti_bonus_y == obman_y) {
						bonus = 0;
						bonus_perevirka = 0;
					}
				}
				if (bonus == 2) {
					if (obman_y == i or obman_y == i1 or obman_y == i2 or obman_y == i3) {
						if (obman_x == 3 or obman_x == 2) {
							perevirka = 1;
						}
					}
				}
				perenos(obman_x, obman_y);
				cout << "o";
				Sleep(85);




			}
		}

		else
			if (or_or == 2) {
				if (obman_y < 14 and obman_x > 1 and obman_y > 0) {

					if (obman_y == i or obman_y == i1 or obman_y == i2) {
						if (obman_x == 3 or obman_x == 2) {
							perevirka = 1;
						}
					}


					perenos(obman_x, obman_y);
					cout << " ";
					obman_x--;
					obman_x--;
					obman_y++;
					if (obman_x > 24) {
						obman_x = 22;
					}
					if (obman_y > 12) {
						obman_y = 11;
					}
					if (bonus_x == obman_x) {
						if (bonus_y == obman_y) {
							bonus = 2;
							anti_bonus = TRUE;
						}
					}
					if (anti_bonus_x == obman_x) {
						if (anti_bonus_y == obman_y) {
							bonus = 0;
							bonus_perevirka = 0;
						}
					}
					if (bonus == 0) {
						if (obman_y == i or obman_y == i1 or obman_y == i2) {
							if (obman_x == 3 or obman_x == 2) {
								perevirka = 1;
							}
						}
					}
					if (bonus == 2) {
						if (obman_y == i or obman_y == i1 or obman_y == i2 or obman_y == i3) {
							if (obman_x == 3 or obman_x == 2) {
								perevirka = 1;
							}
						}
					}
					perenos(obman_x, obman_y);
					cout << "o";
					Sleep(85);




				}
				if (obman_x == 2) {
					or_or = 1;
				}
			}

			else
				if (or_or == 3) {
					if (obman_y < 14 and obman_x > 1 and obman_y > 0) {

						if (obman_y == i or obman_y == i1 or obman_y == i2) {
							if (obman_x == 3 or obman_x == 2) {
								perevirka = 1;
							}
						}


						perenos(obman_x, obman_y);
						cout << " ";

						obman_x--;
						obman_y++;
						obman_y++;
						if (obman_y > 12) {
							obman_y = 11;
						}
						if (bonus_x == obman_x) {
							if (bonus_y == obman_y) {
								bonus = 2;
								anti_bonus = TRUE;
							}
						}
						if (obman_x > 24) {
							obman_x = 22;
						}
						if (bonus == 0) {
							if (obman_y == i or obman_y == i1 or obman_y == i2) {
								if (obman_x == 3 or obman_x == 2) {
									perevirka = 1;
								}
							}
						}
						if (anti_bonus_x == obman_x) {
							if (anti_bonus_y == obman_y) {
								bonus = 0;
								bonus_perevirka = 0;
							}
						}
						if (bonus == 2) {
							if (obman_y == i or obman_y == i1 or obman_y == i2 or obman_y == i3) {
								if (obman_x == 3 or obman_x == 2) {
									perevirka = 1;
								}
							}
						}
						perenos(obman_x, obman_y);
						cout << "o";
						Sleep(85);




					}
					if (obman_y == 11) {
						or_or = 1;
					}
				}

		if (obman_y == 12) {
			x_y = 1;

		}

		if (obman_x == 1) {
			perevirka = 1;
		}
		if (obman_y == -1) {
			perenos(0, 0);
			for (int i = 0; i < right; i++) {
				cout << "*";
			}
			obman_y = 1;

			x_y = 1 + rand() % (2);

		}

		if (obman_x == 0) {
			x_y = perevirka = 1;

		}

	}

	if (obman_y == i or obman_y == i1 or obman_y == i2) {
		if (obman_x == 3) {
			perevirka = 1;
			chochik = chochik + 100;
			gotoxy(80, 0);
			cout << "щочик балов:  ";
			gotoxy(93, 0);
			cout << chochik;
		}

	}

	if (obman_x < 2) {

		chochik = chochik - 50;
		gotoxy(80, 0);
		cout << "щочик балов:  ";
		gotoxy(93, 0);
		cout << chochik;
	}



	if (obman_x == 0) {
		perevirka = 1;
	}


	if (obman_y == i or obman_y == i1 or obman_y == i2) {
		if (obman_x == 3) {
			perevirka = 1;
		}
	}




	if (obman_x == 0) {
		x_y = perevirka = 1;

	}
}
void nachalo(int& gde, int& what_1) {


	perenos(0, 0);
	GetKEY();

	if (KEY[38])
	{
		gde = 1;
		if (gde == 1) {
			color_black(gde);
			perenos(6, gde);

			cout << "начати гру";









			perenos(0, gde);


			color_pink(gde);
			perenos(6, gde);
			cout << "начати гру";

		}


		if (gde == 2) {

			color_black(1);
			perenos(6, 1);
			cout << "начати гру";
			gde--;
		}
		else
			if (gde == 1) {

				color_black(2);
				perenos(6, 2);

				cout << "правила ігор";
				gde++;
			}


	}
	//клавиша вниз
	else
		if (KEY[40])
		{
			gde = 2;
			if (gde == 2) {

				color_black(gde);
				perenos(6, gde);










				perenos(0, gde);


				color_pink(gde);
				perenos(6, gde);
				cout << "правила ігор";

			}

			if (gde == 2) {

				color_black(1);
				perenos(6, 1);
				cout << "начати гру";
				gde--;
			}
			else
				if (gde == 1) {

					color_black(2);
					perenos(6, 2);

					cout << "правила ігор";
					gde++;
				}
		}
		else
			if (KEY[13])
			{
				if (gde == 1) {
					what_1 = 2;
				}
				else if (gde == 2) {
					what_1 = 3;
				}

			}
}
void pravila() {

	system("cls");
	perenos(25, 0);
	cout << "гра 1 ping-pong її правила : ";
	perenos(25, 1);
	cout << "потрібно двигати платформою і відбивати мяч ";
	perenos(25, 2);
	cout << "якщо мяч заходить за платформу - 50 очков якщо відбивається +100 ";

	perenos(25, 3);
	cout << "гра 2 mini_race її правила : ";

	perenos(25, 4);
	cout << "потрібно уварачоватися від машин щоб не збитися ";
	perenos(25, 5);
	cout << "якщо машина заходить за вас то +10% до нового уровня якщо збивається то ви програли";




	Sleep(10000);


}
void game_player(int& gde, int& what_1, int& regim, int& true_false_1) {

	if (what_1 == 1) {
		perenos(0, 0);
		GetKEY();

		if (KEY[38])
		{
			gde = 1;
			if (gde == 1) {
				color_black(gde);
				perenos(3, gde);
				cout << "на одного гравця";









				perenos(0, gde);


				color_pink(gde);
				perenos(3, gde);
				cout << "на одного гравця";

			}


			if (gde == 2) {
				color_black(1);
				perenos(3, 1);
				cout << "на одного гравця";
				gde--;
			}
			else
				if (gde == 1) {

					color_black(2);
					perenos(3, 2);
					cout << "на двох гравців";
					gde++;
				}


		}
		//клавиша вниз
		else
			if (KEY[40])
			{
				gde = 2;
				if (gde == 2) {

					color_black(gde);
					perenos(3, gde);










					perenos(0, gde);


					color_pink(gde);
					perenos(3, gde);
					cout << "на двох гравців";

				}

				if (gde == 2) {

					color_black(1);
					perenos(3, 1);
					cout << "на одного гравця";
					gde--;
				}
				else
					if (gde == 1) {

						color_black(2);
						perenos(3, 2);
						cout << "на двох гравців";
						gde++;
					}
			}
			else
				if (KEY[13])
				{
					if (gde == 1) {
						what_1 = 2;
					}
					else if (gde == 2) {
						what_1 = 3;
					}

				}
	}
	SetColor(WHITE, BLACK);


	if (what_1 == 3) {
		regim = 1;
		true_false_1 = 0;


	}
	if (what_1 == 2) {
		regim = 2;
		true_false_1 = 0;
	}




}
void verx_vniz(int& i, int& i1, int& i2, int& i3, int& bonus) {
	GetKEY();

	//обрлбка верх


	//клавиша верх
	if (KEY[38])
	{

		if (i > 1 or i3 > 1) {
			//закраска старих
			i++;
			i1++;
			i2++;
			i3++;
			perenos(2, i);
			cout << " ";
			perenos(2, i1);
			cout << " ";

			perenos(2, i2);
			cout << " ";
			if (bonus == 2) {
				perenos(2, i3);
				cout << " ";
			}
			//+ в верх
			i--;
			i1--;
			i2--;

			i--;
			i1--;
			i2--;
			i3--;
			i3--;
			perenos(2, i);
			cout << "*";
			perenos(2, i1);
			cout << "*";

			perenos(2, i2);
			cout << "*";
			if (bonus == 2) {
				perenos(2, i3);
				cout << "*";
			}

		}


	}
	//клавиша вниз
	else
		if (KEY[40])
		{
			if (i2 < 11) {
				//закраска старих
				i--;
				i1--;
				i2--;
				i3--;
				perenos(2, i);
				cout << " ";
				perenos(2, i1);
				cout << " ";
				perenos(2, i2);
				cout << " ";
				if (bonus == 2) {
					perenos(2, i3);
					cout << " ";
				}
				//+ в верх
				i++;
				i1++;
				i2++;

				i++;
				i1++;
				i2++;
				i3++;
				i3++;
				perenos(2, i);
				cout << "*";
				perenos(2, i1);
				cout << "*";

				perenos(2, i2);
				cout << "*";
				if (bonus == 2) {
					perenos(2, i3);
					cout << "*";
				}
			}



		}


}

void new_skin(int& set_skin) {
	if (set_skin == 1) {

		SetColor(WHITE, BLACK);

	}
	else if (set_skin == 2) {

		SetColor(PINK, BLACK);

	}
	else if (set_skin == 3) {

		SetColor(YELLOW, BLACK);

	}
	else if (set_skin == 4) {

		SetColor(GREEN, BLACK);

	}
	else if (set_skin == 5) {

		SetColor(RED, BLACK);

	}
	else if (set_skin == 6) {

		SetColor(TEAL, BLACK);

	}

}
void skin(int& set_skin, int& game) {
	system("cls");

	ramka();
	perenos(12, 1);
	SetColor(WHITE, BLACK);
	cout << "SKIN";
	perenos(12, 3);
	cout << "1) ";
	perenos(13, 3);
	SetColor(WHITE, BLACK);

	cout << "White";
	SetColor(WHITE, BLACK);
	perenos(12, 4);
	cout << "2) ";
	perenos(13, 4);
	SetColor(PINK, BLACK);
	cout << "Pink";
	SetColor(WHITE, BLACK);
	perenos(12, 5);
	cout << "3) ";
	perenos(13, 5);
	SetColor(YELLOW, BLACK);
	cout << "Yellow";
	SetColor(WHITE, BLACK);
	perenos(12, 6);
	cout << "4) ";
	perenos(13, 6);
	SetColor(GREEN, BLACK);
	cout << "Green";
	SetColor(WHITE, BLACK);
	perenos(12, 7);
	cout << "5) ";
	perenos(13, 7);
	SetColor(RED, BLACK);
	cout << "Red";
	SetColor(WHITE, BLACK);
	perenos(12, 8);
	cout << "6) ";
	perenos(13, 8);
	SetColor(TEAL, BLACK);
	cout << "Teal";

	GetKEY();

	if (KEY[49])
	{
		set_skin = 1;
		game = 1;
	}
	else if (KEY[50]) {
		set_skin = 2;
		game = 1;
	}
	else if (KEY[51]) {
		set_skin = 3;
		game = 1;
	}
	else if (KEY[52]) {
		set_skin = 4;
		game = 1;
	}
	else if (KEY[53]) {
		set_skin = 5;
		game = 1;
	}
	else if (KEY[54]) {
		set_skin = 6;
		game = 1;
	}
	SetColor(WHITE, BLACK);
	perenos(5, 10);
	cout << "ВИБЕРІТЬ СКІН";
	perenos(5, 11);
	cout << "СПОМОЩУ ЦИФЕР 1-6";
}



void chot(int bal) {

	SetColor(WHITE, BLACK);


	SetColor(PINK, BLACK);
	perenos(108, 0);
	cout << "|**********|";

	perenos(108, 1);
	cout << "|";
	perenos(108, 2);
	cout << "|";

	perenos(119, 1);
	cout << "|";
	perenos(119, 2);
	cout << "|";


	perenos(108, 3);
	cout << "|**********|";
	SetColor(RED_FADE, BLACK);
	perenos(110, 1);
	cout << "бали: ";
	SetColor(TEAL_FADE, BLACK);
	perenos(116, 1);
	cout << bal;


	SetColor(WHITE, BLACK);


}
void nachalo1(int& gde, int& game) {


	perenos(0, 0);

		GetKEY();

		if (KEY[49])
		{
			gde = 1;
			if (gde == 1) {
				color_black(gde);

				perenos(6, gde);

				cout << "начати гру";









				perenos(0, gde);


				color_pink(gde);
				perenos(6, gde);
				cout << "начати гру";

			}


			if (gde == 2) {

				color_black(1);
				perenos(6, 1);
				cout << "начати гру";
				gde--;
			}
			else
				if (gde == 1) {

					color_black(2);
					perenos(6, 2);

					cout << "skin";
					gde++;
				}


		}
		//клавиша вниз
		else
			if (KEY[50])
			{
				gde = 2;
				if (gde == 2) {

					color_black(gde);

					perenos(6, gde);
					cout << "skin";









					perenos(0, gde);


					color_pink(gde);
					perenos(6, gde);
					cout << "skin";

				}

				if (gde == 2) {

					color_black(1);
					perenos(6, 1);
					cout << "начати гру";
					gde--;
				}
				else
					if (gde == 1) {

						color_black(2);
						perenos(6, 2);

						cout << "skin";
						gde++;
					}
			}
			else
				if (KEY[13])
				{
					if (gde == 1) {
						game = 2;
					}
					else if (gde == 2) {
						game = 1;
					}

				}
	
}
void game1() {
	ConsoleCursorVisible(false, 100);
	setlocale(LC_ALL, "Ukrainian");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	srand(time(NULL));
	system("cls");

	int set_skin = 0;
	int game = 0;
	int gde = 2;
	int g = 0;
	int end = 1;
	while (1) {
		//------------------------------------------------------------------------
		if (game == 0) {
			ramka();
			while (g < 1) {
				color_pink(1);

				perenos(6, 1);

				cout << "начати гру";
				color_black(2);

				perenos(6, 2);

				cout << "skin";
				g++;
			}
			nachalo1(gde, game);


		}
		if (game == 2) {

			skin(set_skin, game);
		}



		if (game == 1) {
			system("cls");

			int snak_x = 10;
			int snak_y = 5;
			int bal = 0;
			int y = 0;
			int x = 1;
			int speed = 100;
			int speed_x = 50;

			int aple_ran = 0;
			int aple_x = 0;
			int aple_y = 0;
			bool aple = FALSE;
			int chochik_bal = 0;
			
		
				while (end) {
					ramka();
					chot(bal);
					SetColor(WHITE, BLACK);
					perenos(40, 1);
					cout << "SKIN -> *";
					if (aple_x > 1 and aple_y > 1) {
						perenos(aple_x, aple_y);



						SetColor(PINK, BLACK);
						cout << "?";
						SetColor(WHITE, BLACK);
					}
					if (aple_x == snak_x and aple_y == snak_y) {
						bal = bal + 1;
						aple_ran = 0;
						aple_x = 0;
						aple_y = 0;
						aple = FALSE;
						chochik_bal++;
					}
					if (chochik_bal == 10) {
						speed = speed - 5;
						speed_x = speed_x - 10;
						chochik_bal = 0;
					}
					if (snak_x != 0 && snak_x != 23 && snak_y != 0 && snak_y != 13) {

						if (y == 0 and x == 1) //right
						{
							new_skin(set_skin);
							Sleep(speed_x);
							perenos(snak_x, snak_y);
							cout << "   ";
							snak_x++;
							perenos(snak_x, snak_y);
							cout << "*";


						}

						if (y == 0 and x == 2) //left
						{
							new_skin(set_skin);
							Sleep(speed_x);
							perenos(snak_x, snak_y);
							cout << "   ";
							snak_x--;
							perenos(snak_x, snak_y);
							cout << "*";


						}
						if (y == 1 and x == 0)//verx
						{
							new_skin(set_skin);
							Sleep(speed);
							perenos(snak_x, snak_y);
							cout << "   ";
							snak_y--;

							perenos(snak_x, snak_y);
							cout << "*";

						}

						if (y == 2 and x == 0)//verx
						{
							new_skin(set_skin);
							Sleep(speed);
							perenos(snak_x, snak_y);
							cout << "   ";
							snak_y++;

							perenos(snak_x, snak_y);
							cout << "*";

						}
						if (snak_x == 0 or snak_x == 23 or snak_y == 0 or snak_y == 13) {
							system("cls");
							SetColor(BLACK, WHITE);
							perenos(40, 3);
							cout << "нажаль ви програливаш щочик зправа";


							chot(bal);

							Sleep(5000);
							game = 0;
							end = 1;


							exit(0);

						}

					}
					if (aple == FALSE) {
						aple_ran = 1 + rand() % (100);
						if (aple_ran == 43 or aple_ran == 99) {
							aple_x = 1 + rand() % (22);
							aple_y = 1 + rand() % (11);
							aple = TRUE;
						}
					}




					GetKEY();

					//обрлбка верх


					//клавиша верх
					if (KEY[37])//ливо
					{
						y = 0;
						x = 2;

					}


					else
						if (KEY[38])//верх
						{
							x = 0;
							y = 1;
						}

						else
							if (KEY[39])//право
							{
								y = 0;
								x = 1;

							}

							else
								if (KEY[40])//низ
								{
									x = 0;
									y = 2;

								}


								else
									if (KEY[106])//низ
									{
										g = 0;
										end = 0;
										game = 0;
										system("cls");
									}





				}

				
		}

	}
}


void pong(int & what) {
	
		what = 2;
		if (what == 2) {
			SetColor(WHITE, BLACK);
			system("cls");
			system("cls");


			int gde = 2;



			int what_1 = 1;
			int true_false_1 = 1;


			//рамки гри
			system("cls");
			gotoxy(0, 0);
			int mozno = 0;
			int verh = 13;
			int right = 25;

			ramka();
			//набросок гри
			//верх
			perenos(2, 8);

			cout << "*";
			//середня
			perenos(2, 9);
			cout << "*";
			//низ
			perenos(2, 10);
			cout << "*";
			//мяч
			perenos(7, 8);
			cout << "o";


			//нічого
			perenos(25, 25);
			cout << " ";
			//це інти які я використовую в процесі
			int i3 = 7;
			int i = 8;
			int i1 = 9;
			int i2 = 10;
			//обробка клавиш

			int obman_x = 7;
			int obman_y = 8;
			int k = obman_x;
			int perevirka = 1;
			int chochik = 0;
			gotoxy(80, 0);
			cout << "щочик балов:  ";
			gotoxy(93, 0);
			cout << chochik;
			gotoxy(90, 0);
			gotoxy(100, 0);

			cout << "ник:  ";

			gotoxy(106, 0);

			cout << "Лучка Кирил  ";
			int x_y1 = 0;
			int x_y = 0;
			int or_or = 1;
			int or_all = 0;
			int x_rand = 0;
			int y_rand = 0;
			//1 верх
			int predel = 0;
			//генератори рандомних чисел
			x_y = 1 + rand() % (2);
			x_y1 = 1 + rand() % (2);
			int anti = 0;
			int bonus = 0;
			int bonus_perevirka = 0;
			int bonus_x = 0;
			int bonus_y = 0;
			int anti_bonus_x = 0;
			int anti_bonus_y = 0;
			int bonus_per = 0;
			int bonus_per_print = 0;
			bool anti_bonus = FALSE;
			while (anti != 1)
			{
				if (mozno == 0) {
					if (chochik == -200) {
						anti = 1;
						mozno = 1;
					}
					//х y мяча
					ConsoleCursorVisible(false, 100);
					perenos(0, 12);
					for (int i = 0; i < 24; i++) {
						cout << "*";

					}
					gotoxy(92, 20);
					cout << obman_x << "-" << obman_y;


					gotoxy(92, 0);
					cout << " ";
					gotoxy(93, 0);
					cout << " ";
					gotoxy(94, 0);
					cout << " ";
					gotoxy(95, 0);
					cout << " ";
					gotoxy(96, 0);
					cout << " ";
					gotoxy(93, 0);
					cout << chochik;
					perenos(2, i);
					cout << "*";

					perenos(2, i1);
					cout << "*";

					perenos(2, i2);
					cout << "*";
					if (bonus == 2) {
						perenos(2, i3);
						cout << "*";
					}

					if (bonus == 0) {
						bonus_perevirka = 1 + rand() % (100);
					}
					if (bonus_perevirka == 50) {

						bonus_x = 5 + rand() % (19);
						bonus_y = 3 + rand() % (10);
						bonus = 1;
						bonus_perevirka = 0;
					}

					if (bonus == 1) {
						perenos(bonus_x, bonus_y);

						SetColor(PINK_FADE, BLACK);
						cout << "?";

						SetColor(WHITE, BLACK);

					}
					if (anti_bonus == TRUE) {
						if (bonus_per == 10) {

							anti_bonus_x = 5 + rand() % (19);
							anti_bonus_y = 3 + rand() % (9);
							bonus_per_print = 6;

						}
						if (bonus_per_print == 6) {
							perenos(anti_bonus_x, anti_bonus_y);

							SetColor(PINK_FADE, BLACK);
							cout << "^";
							anti_bonus = FALSE;
							bonus_per = 50;
							SetColor(WHITE, BLACK);
						}
					}
					//мяч


					if (perevirka == 1) {
						ball_right(gde, obman_x, obman_y, bonus, anti_bonus, or_or, x_y1, i, i1, i2, bonus_per, bonus_x, bonus_y, anti_bonus_x, anti_bonus_y, bonus_perevirka, perevirka);

					}

					else if (perevirka == 2) {
						ball_left(gde, obman_x, obman_y, bonus, anti_bonus, or_or, x_y1, i, i1, i2, bonus_per, bonus_x, bonus_y, anti_bonus_x, anti_bonus_y, bonus_perevirka, perevirka, i3, chochik, x_y, right);

					}




					verx_vniz(i, i1, i2, i3, bonus);


				}

			}
			while (anti == 1) {

				system("cls");
				perenos(30, 1);
				cout << "ви нажаль програли";
				perenos(30, 2);
				cout << "через 5 секунд програма закриється";
				Sleep(5000);
				break;


			}
			//обробка мяча



		}

	

}
void race(int & what) {

	system("cls");
	if (what == 3) {
		SetColor(WHITE, BLACK);

		color_pink(1);
		perenos(6, 1);
		cout << "lvl 1";

		color_black(2);
		perenos(6, 2);
		cout << "lvl 2";
		color_black(3);
		perenos(6, 3);
		cout << "lvl 3";
		int lvl = 0;
		int gde = 1;
		while (1) {
			ramka();
			GetKEY();

			if (KEY[49])
			{
				gde = 1;
				if (gde == 1) {
					color_pink(1);
					perenos(6, 1);
					cout << "lvl 1";

					color_black(2);
					perenos(6, 2);
					cout << "lvl 2";
					color_black(3);
					perenos(6, 3);
					cout << "lvl 3";

				}

			}


			else if (KEY[50])
			{
				gde = 2;
				if (gde == 2) {
					color_black(1);
					perenos(6, 1);
					cout << "lvl 1";

					color_pink(2);
					perenos(6, 2);
					cout << "lvl 2";
					color_black(3);
					perenos(6, 3);
					cout << "lvl 3";

				}

			}

			else if (KEY[51])
			{
				gde = 3;
				if (gde == 3) {
					color_black(1);
					perenos(6, 1);
					cout << "lvl 1";

					color_black(2);
					perenos(6, 2);
					cout << "lvl 2";
					color_pink(3);
					perenos(6, 3);
					cout << "lvl 3";
					SetColor(RED, BLACK);
				}

			}


			if (KEY[13])
			{
				if (gde == 1) {
					lvl = 1;

					if (lvl == 1) {
						system("cls");
						SetColor(WHITE, BLACK);
						system("cls");
						gotoxy(0, 0);
						int verh = 14;
						int right = 14;

						for (int i = 0; i < right; i++) {
							cout << "*";
						}
						cout << endl;
						for (int j = 0; j < verh; j++) {
							for (int i = 0; i < 14; i++) {
								cout << " ";
								if (i == 13) {
									cout << "*" << endl;
								}
							}
						}

						for (int i = 0; i < 14; i++) {
							cout << "*";
						}//242
						//інти які я використовую//
						int perevirka = 1;
						int plat_x = 7;
						int plat_y = 13;



						int plat_x_1 = 7;
						int plat_y_1 = 12;
						int patron_x = plat_x_1;
						int patron_y = plat_y_1 - 1;

						//набросок
						perenos(plat_x, plat_y);
						cout << "@";

						perenos(plat_x_1, plat_y_1);
						cout << "|";

						perenos(30, 1);
						cout << "суть ігри уварачеватися від машин";
						perenos(20, 20);
						//ще інти
						int rand_car = 5;//rand_car = 0 + rand() % (12);
						int car_x = 5;
						int car_y = 0;


						int dead = 1;

						int speed = 110;
						int speed_score = 9;
						int rang = 1;
						int new_ckore = 0;
						int car_perevirka = 1;
						perenos(30, 2);
						/// <summary>
						///щочики
						/// </summary>
						cout << "рівень швидкості: " << rang;

						perenos(30, 3);
						cout << "машин до нового рівня: " << speed_score;
						while (dead)
						{
							//рандом машин
							if (car_perevirka == 1) {
								car_x = 0 + rand() % (14);
								car_x = 0 + rand() % (14);
								car_x = 0 + rand() % (14);
								car_perevirka = 2;
							}

							//рандомні машини і їх двіженіє 
							if (car_y < 14) {
								Sleep(speed);
								perenos(car_x, car_y);
								cout << " ";
								car_y++;

								perenos(car_x, car_y);
								cout << "D";

								if (car_y == 14) {
									perenos(car_x, car_y);
									cout << " ";
									car_y = 0;
									car_perevirka = 1;
									speed_score--;
									perenos(30, 3);
									cout << "машин до нового рівня: " << speed_score;
									if (speed >= 10) {
										if (speed_score == 0) {
											speed = speed - 10;
											speed_score = 9;
											rang++;
											perenos(30, 2);
											cout << "рівень швидкості: " << rang;


										}
									}

								}
								if (plat_y == car_y and plat_x == car_x) {
									perenos(car_x, car_y);
									cout << " ";

									dead = 0;
								}

								if (plat_y_1 == car_y and plat_x_1 == car_x) {
									perenos(car_x, car_y);
									cout << " ";

									dead = 0;

								}

							}





							//обробка клавиш 


							GetKEY();

							//клвашива в ліво
							if (KEY[37])//left
							{


								if (plat_x >= 1 and plat_x_1 >= 1) {
									perenos(plat_x, plat_y);
									cout << " ";

									perenos(plat_x_1, plat_y_1);
									cout << " ";





									plat_x--;
									plat_x_1--;

									perenos(plat_x, plat_y);
									cout << "@";

									perenos(plat_x_1, plat_y_1);
									cout << "|";


								}


							}
							//клавиша в право
							else
								if (KEY[39])//right
								{

									if (plat_x <= 12 and plat_x_1 <= 12) {
										//закраска старих
										perenos(plat_x, plat_y);
										cout << " ";

										perenos(plat_x_1, plat_y_1);
										cout << " ";





										plat_x++;
										plat_x_1++;

										perenos(plat_x, plat_y);
										cout << "@";

										perenos(plat_x_1, plat_y_1);
										cout << "|";

									}



								}











							if (dead == 0) {
								perenos(30, 50);
								cout << "ви проиграли ви збилися в машину";
								Sleep(1000);
								exit(0);
							}


						}
					}
				}









				else if (gde == 2) {
					lvl = 2;
					SetColor(WHITE, BLACK);
					if (lvl == 2) {
						system("cls");
						gotoxy(0, 0);
						int verh = 14;
						int right = 14;

						for (int i = 0; i < right; i++) {
							cout << "*";
						}
						cout << endl;
						for (int j = 0; j < verh; j++) {
							for (int i = 0; i < 14; i++) {
								cout << " ";
								if (i == 13) {
									cout << "*" << endl;
								}
							}
						}

						for (int i = 0; i < 14; i++) {
							cout << "*";
						}//242
						//інти які я використовую//
						int perevirka = 1;
						int plat_x = 7;
						int plat_y = 13;



						int plat_x_1 = 7;
						int plat_y_1 = 12;


						//набросок
						perenos(plat_x, plat_y);
						cout << "@";

						perenos(plat_x_1, plat_y_1);
						cout << "|";

						perenos(30, 1);
						cout << "суть ігри уварачеватися від машин";
						perenos(20, 20);
						//ще інти
						int rand_car = 5;//rand_car = 0 + rand() % (12);
						int rand_car1 = 5;//rand_car = 0 + rand() % (12);
						int car_x = 5;
						int car_y = 0;
						int car_x1 = 5;
						int car_y1 = 0;

						int dead = 1;

						int speed = 110;
						int speed_score = 9;
						int rang = 1;
						int new_ckore = 0;
						int car_perevirka = 1;
						perenos(30, 2);
						/// <summary>
						///щочики
						/// </summary>
						cout << "рівень швидкості: " << rang;

						perenos(30, 3);
						cout << "машин до нового рівня: " << speed_score;
						while (dead)
						{
							//рандом машин
							if (car_perevirka == 1) {
								car_x = 0 + rand() % (14);
								car_x = 0 + rand() % (14);
								car_x = 0 + rand() % (14);

								car_x1 = 0 + rand() % (14);
								car_x1 = 0 + rand() % (14);
								car_x1 = 0 + rand() % (14);
								if (car_x == car_x1) {
									car_x = 0 + rand() % (14);
									car_x = 0 + rand() % (14);
									car_x = 0 + rand() % (14);

									car_x1 = 0 + rand() % (14);
									car_x1 = 0 + rand() % (14);
									car_x1 = 0 + rand() % (14);
								}
								car_perevirka = 2;
							}

							//рандомні машини і їх двіженіє 
							if (car_y < 14) {
								Sleep(speed);
								perenos(car_x, car_y);
								cout << " ";
								car_y++;

								perenos(car_x, car_y);
								cout << "D";

								//2
								perenos(car_x1, car_y1);
								cout << " ";
								car_y1++;

								perenos(car_x1, car_y1);
								cout << "D";

								if (car_y == 14) {
									perenos(car_x, car_y);
									cout << " ";
									car_y = 0;

									perenos(car_x1, car_y1);
									cout << " ";
									car_y1 = 0;

									car_perevirka = 1;
									speed_score--;
									perenos(30, 3);
									cout << "машин до нового рівня: " << speed_score;
									if (speed >= 10) {
										if (speed_score == 0) {
											speed = speed - 10;
											speed_score = 9;
											rang++;
											perenos(30, 2);
											cout << "рівень швидкості: " << rang;


										}
									}

								}
								if (plat_y == car_y and plat_x == car_x) {
									perenos(car_x, car_y);
									cout << " ";

									dead = 0;
								}

								if (plat_y_1 == car_y and plat_x_1 == car_x) {
									perenos(car_x, car_y);
									cout << " ";

									dead = 0;

								}



								if (plat_y == car_y1 and plat_x == car_x1) {
									perenos(car_x1, car_y1);
									cout << " ";

									dead = 0;
								}

								if (plat_y_1 == car_y1 and plat_x_1 == car_x1) {
									perenos(car_x1, car_y1);
									cout << " ";

									dead = 0;

								}

							}





							//обробка клавиш 


							GetKEY();

							//клвашива в ліво
							if (KEY[37])//left
							{


								if (plat_x >= 1 and plat_x_1 >= 1) {
									perenos(plat_x, plat_y);
									cout << " ";

									perenos(plat_x_1, plat_y_1);
									cout << " ";





									plat_x--;
									plat_x_1--;

									perenos(plat_x, plat_y);
									cout << "@";

									perenos(plat_x_1, plat_y_1);
									cout << "|";


								}


							}
							//клавиша в право
							else
								if (KEY[39])//right
								{

									if (plat_x <= 12 and plat_x_1 <= 12) {
										//закраска старих
										perenos(plat_x, plat_y);
										cout << " ";

										perenos(plat_x_1, plat_y_1);
										cout << " ";





										plat_x++;
										plat_x_1++;

										perenos(plat_x, plat_y);
										cout << "@";

										perenos(plat_x_1, plat_y_1);
										cout << "|";

									}



								}











							if (dead == 0) {
								perenos(30, 50);
								cout << "ви проиграли ви збилися в машину";
								Sleep(1000);
								exit(0);
							}


						}
					}

				}










				else if (gde == 3) {
					lvl = 3;
					SetColor(WHITE, BLACK);
					if (lvl == 3) {
						system("cls");
						gotoxy(0, 0);
						int verh = 14;
						int right = 14;

						for (int i = 0; i < right; i++) {
							cout << "*";
						}
						cout << endl;
						for (int j = 0; j < verh; j++) {
							for (int i = 0; i < 14; i++) {
								cout << " ";
								if (i == 13) {
									cout << "*" << endl;
								}
							}
						}

						for (int i = 0; i < 14; i++) {
							cout << "*";
						}//242
						//інти які я використовую//
						int perevirka = 1;
						int plat_x = 7;
						int plat_y = 13;



						int plat_x_1 = 7;
						int plat_y_1 = 12;


						//набросок
						perenos(plat_x, plat_y);
						cout << "@";

						perenos(plat_x_1, plat_y_1);
						cout << "|";

						perenos(30, 1);
						cout << "суть ігри уварачеватися від машин";
						perenos(20, 20);
						//ще інти
						int rand_car = 5;//rand_car = 0 + rand() % (12);
						int rand_car1 = 5;//rand_car = 0 + rand() % (12);
						int car_x = 5;
						int car_y = 0;
						int car_x1 = 5;
						int car_y1 = 0;
						int car_x2 = 5;
						int car_y2 = 0;
						int dead = 1;

						int speed = 110;
						int speed_score = 9;
						int rang = 1;
						int new_ckore = 0;
						int car_perevirka = 1;
						perenos(30, 2);
						/// <summary>
						///щочики
						/// </summary>
						cout << "рівень швидкості: " << rang;

						perenos(30, 3);
						cout << "машин до нового рівня: " << speed_score;
						while (dead)
						{
							//рандом машин
							if (car_perevirka == 1) {
								car_x = 0 + rand() % (14);
								car_x = 0 + rand() % (14);
								car_x = 0 + rand() % (14);

								car_x1 = 0 + rand() % (14);
								car_x1 = 0 + rand() % (14);
								car_x1 = 0 + rand() % (14);
								car_x2 = 0 + rand() % (14);
								car_x2 = 0 + rand() % (14);
								car_x2 = 0 + rand() % (14);
								if (car_x == car_x1 or car_x1 == car_x2 or car_x2 == car_x) {
									car_x = 0 + rand() % (14);
									car_x = 0 + rand() % (14);
									car_x = 0 + rand() % (14);

									car_x1 = 0 + rand() % (14);
									car_x1 = 0 + rand() % (14);
									car_x1 = 0 + rand() % (14);
									car_x2 = 0 + rand() % (14);
									car_x2 = 0 + rand() % (14);
									car_x2 = 0 + rand() % (14);
								}
								car_perevirka = 2;
							}

							//рандомні машини і їх двіженіє 
							if (car_y < 14) {
								Sleep(speed);
								perenos(car_x, car_y);
								cout << " ";
								car_y++;

								perenos(car_x, car_y);
								cout << "D";

								//2
								perenos(car_x1, car_y1);
								cout << " ";
								car_y1++;

								perenos(car_x1, car_y1);
								cout << "D";
								//3
								perenos(car_x2, car_y2);
								cout << " ";
								car_y2++;

								perenos(car_x2, car_y2);
								cout << "D";
								if (car_y == 14) {
									perenos(car_x, car_y);
									cout << " ";
									car_y = 0;

									perenos(car_x1, car_y1);
									cout << " ";
									car_y1 = 0;
									perenos(car_x2, car_y2);
									cout << " ";
									car_y2 = 0;
									car_perevirka = 1;
									speed_score--;
									perenos(30, 3);
									cout << "машин до нового рівня: " << speed_score;
									if (speed >= 10) {
										if (speed_score == 0) {
											speed = speed - 10;
											speed_score = 9;
											rang++;
											perenos(30, 2);
											cout << "рівень швидкості: " << rang;


										}
									}

								}
								if (plat_y == car_y and plat_x == car_x) {
									perenos(car_x, car_y);
									cout << " ";

									dead = 0;
								}

								if (plat_y_1 == car_y and plat_x_1 == car_x) {
									perenos(car_x, car_y);
									cout << " ";

									dead = 0;

								}



								if (plat_y == car_y1 and plat_x == car_x1) {
									perenos(car_x1, car_y1);
									cout << " ";

									dead = 0;
								}

								if (plat_y_1 == car_y1 and plat_x_1 == car_x1) {
									perenos(car_x1, car_y1);
									cout << " ";

									dead = 0;

								}


								if (plat_y == car_y2 and plat_x == car_x2) {
									perenos(car_x2, car_y2);
									cout << " ";

									dead = 0;
								}

								if (plat_y_1 == car_y2 and plat_x_1 == car_x2) {
									perenos(car_x2, car_y2);
									cout << " ";

									dead = 0;

								}


							}





							//обробка клавиш 


							GetKEY();
							//1
							//клвашива в ліво
							if (KEY[37])//left
							{


								if (plat_x >= 1 and plat_x_1 >= 1) {
									perenos(plat_x, plat_y);
									cout << " ";

									perenos(plat_x_1, plat_y_1);
									cout << " ";





									plat_x--;
									plat_x_1--;

									perenos(plat_x, plat_y);
									cout << "@";

									perenos(plat_x_1, plat_y_1);
									cout << "|";


								}


							}
							//клавиша в право
							else
								if (KEY[39])//right
								{

									if (plat_x <= 12 and plat_x_1 <= 12) {
										//закраска старих
										perenos(plat_x, plat_y);
										cout << " ";

										perenos(plat_x_1, plat_y_1);
										cout << " ";





										plat_x++;
										plat_x_1++;

										perenos(plat_x, plat_y);
										cout << "@";

										perenos(plat_x_1, plat_y_1);
										cout << "|";

									}



								}











							if (dead == 0) {
								perenos(30, 50);
								cout << "ви проиграли ви збилися в машину";
								Sleep(1000);
								exit(0);
							}


						}
					}

				}
			}
		}














	}


}
void vibor_game(int& what) {
	ramka();
	int gde = 1;
	while (1) {
		GetKEY();

		if (KEY[49])
		{
			gde = 1;
			if (gde == 1) {
				color_pink(1);
				perenos(6, 1);
				cout << "Pong";

				color_black(2);
				perenos(6, 2);
				cout << "Mini_Race";
				color_black(3);
				perenos(6, 3);
				cout << "Zmeika";

				color_black(4);
				perenos(6, 4);
				cout << "<-BACK--";
			}

		}


		else if (KEY[50])
		{
			gde = 2;
			if (gde == 2) {
				color_black(1);
				perenos(6, 1);
				cout << "Pong";

				color_pink(2);
				perenos(6, 2);
				cout << "Mini_Race";
				color_black(3);
				perenos(6, 3);
				cout << "Zmeika";
				color_black(4);
				perenos(6, 4);
				cout << "<-BACK--";
			}

		}

		else if (KEY[51])
		{
			gde = 3;
			if (gde == 3) {
				color_black(1);
				perenos(6, 1);
				cout << "Pong";

				color_black(2);
				perenos(6, 2);
				cout << "Mini_Race";
				color_pink(3);
				perenos(6, 3);
				cout << "Zmeika";
				color_black(4);
				perenos(6, 4);
				cout << "<-BACK--";
			}

		}
		else if (KEY[52])
		{
			gde = 4;
			if (gde == 4) {
				color_black(1);
				perenos(6, 1);
				cout << "Pong";

				color_black(2);
				perenos(6, 2);
				cout << "Mini_Race";
				color_black(3);
				perenos(6, 3);
				cout << "Zmeika";
				color_pink(4);
				perenos(6, 4);
				cout << "<-BACK--";
			}

		}
		
		if (KEY[13])
		{
			SetColor(WHITE, BLACK);
			//понг
			if (gde == 1) {
				SetColor(WHITE, BLACK);
				pong(what);

			}



			//гонка
			else if (gde == 2) {
				SetColor(WHITE, BLACK);
				what = 3;
				race(what);

			}


			//змейка
			else if (gde == 3) {
				SetColor(WHITE, BLACK);
				game1();

		}
			//back
			else if (gde == 4) {
			what = 0;
			if (what == 0) {
				setlocale(LC_ALL, "Ukrainian");
				SetConsoleOutputCP(1251);
				SetConsoleCP(1251);
				srand(time(NULL));
				system("cls");
				ramka();
				int gde = 1;
				color_pink(1);
				perenos(6, 1);
				cout << "Начати гру";

				color_black(2);
				perenos(6, 2);
				cout << "правила";
				color_black(3);
				perenos(6, 3);
				cout << "вийти";
				while (1) {
					GetKEY();

					if (KEY[49])
					{
						gde = 1;
						if (gde == 1) {
							color_pink(1);
							perenos(6, 1);
							cout << "Начати гру";

							color_black(2);
							perenos(6, 2);
							cout << "правила";
							color_black(3);
							perenos(6, 3);
							cout << "вийти";

						}

					}


					else if (KEY[50])
					{
						gde = 2;
						if (gde == 2) {
							color_black(1);
							perenos(6, 1);
							cout << "Начати гру";

							color_pink(2);
							perenos(6, 2);
							cout << "правила";
							color_black(3);
							perenos(6, 3);
							cout << "вийти";

						}

					}
					else if (KEY[51])
					{
						gde = 3;
						if (gde == 3) {
							color_black(1);
							perenos(6, 1);
							cout << "Начати гру";

							color_black(2);
							perenos(6, 2);
							cout << "правила";
							color_pink(3);
							perenos(6, 3);
							cout << "вийти";

						}

					}

					//вибір гри


					if (KEY[13])
					{
						if (gde == 1) {
							what = 1;
							int regim = 0;
							if (what == 1) {
								system("cls");
								setlocale(LC_ALL, "Ukrainian");
								SetConsoleOutputCP(1251);
								SetConsoleCP(1251);
								srand(time(NULL));
								color_pink(1);
								perenos(6, 1);
								cout << "Pong";

								color_black(2);
								perenos(6, 2);
								cout << "Mini_Race";
								color_black(3);
								perenos(6, 3);
								cout << "Zmeika";
								vibor_game(what);

							}
						}

						if (gde == 2) {
							pravila();
							what = 1;
							if (what == 1) {
								system("cls");
								setlocale(LC_ALL, "Ukrainian");
								SetConsoleOutputCP(1251);
								SetConsoleCP(1251);
								srand(time(NULL));
								color_pink(1);
								perenos(6, 1);
								cout << "Pong";

								color_black(2);
								perenos(6, 2);
								cout << "Mini_Race";
								color_black(3);
								perenos(6, 3);
								cout << "Zmeika";
								vibor_game(what);

							}
						}


						if (gde == 3) {
							system("cls");

							perenos(50, 1);
							SetColor(BLACK, WHITE);
							cout << "Допобаченя!";
							Sleep(5000);
							exit(0);
						}
					}
				}
			}
		}


	}


}
}

void all() {
	ConsoleCursorVisible(false, 100);
	setlocale(LC_ALL, "Ukrainian");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	srand(time(NULL));




	int what = 0;
	int yes_or_no = 0;


	if (what == 0) {
		setlocale(LC_ALL, "Ukrainian");
		SetConsoleOutputCP(1251);
		SetConsoleCP(1251);
		srand(time(NULL));
		system("cls");
		ramka();
		int gde = 1;
		color_pink(1);
		perenos(6, 1);
		cout << "Начати гру";

		color_black(2);
		perenos(6, 2);
		cout << "правила";
		color_black(3);
		perenos(6, 3);
		cout << "вийти";
		while (1) {
			GetKEY();

			if (KEY[49])
			{
				gde = 1;
				if (gde == 1) {
					color_pink(1);
					perenos(6, 1);
					cout << "Начати гру";

					color_black(2);
					perenos(6, 2);
					cout << "правила";
					color_black(3);
					perenos(6, 3);
					cout << "вийти";

				}

			}


			else if (KEY[50])
			{
				gde = 2;
				if (gde == 2) {
					color_black(1);
					perenos(6, 1);
					cout << "Начати гру";

					color_pink(2);
					perenos(6, 2);
					cout << "правила";
					color_black(3);
					perenos(6, 3);
					cout << "вийти";

				}

			}
			else if (KEY[51])
			{
				gde = 3;
				if (gde == 3) {
					color_black(1);
					perenos(6, 1);
					cout << "Начати гру";

					color_black(2);
					perenos(6, 2);
					cout << "правила";
					color_pink(3);
					perenos(6, 3);
					cout << "вийти";

				}

			}
			
			//вибір гри


			if (KEY[13])
			{
				if (gde == 1) {
					what = 1;
					int regim = 0;
					if (what == 1) {
						system("cls");
						setlocale(LC_ALL, "Ukrainian");
						SetConsoleOutputCP(1251);
						SetConsoleCP(1251);
						srand(time(NULL));
						color_pink(1);
						perenos(6, 1);
						cout << "Pong";

						color_black(2);
						perenos(6, 2);
						cout << "Mini_Race";
						color_black(3);
						perenos(6, 3);
						cout << "Zmeika";
						vibor_game(what);

					}
				}

				if (gde == 2) {
					pravila();
					what = 1;
					if (what == 1) {
						system("cls");
						setlocale(LC_ALL, "Ukrainian");
						SetConsoleOutputCP(1251);
						SetConsoleCP(1251);
						srand(time(NULL));
						color_pink(1);
						perenos(6, 1);
						cout << "Pong";

						color_black(2);
						perenos(6, 2);
						cout << "Mini_Race";
						color_black(3);
						perenos(6, 3);
						cout << "Zmeika";
						color_black(4);
						perenos(6, 4);
						cout << "<-BACK--";
						vibor_game(what);

					}
				}

				
				if (gde == 3) {
					system("cls");
					
					perenos(50, 1);
					SetColor(BLACK, WHITE);
					cout << "Допобаченя!";
					Sleep(5000);
					exit(0);
				}
			}
		}
	}

}
//новий


//конец


int main()
{
	setlocale(LC_ALL, "Ukrainian");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	srand(time(NULL));

	all();


}

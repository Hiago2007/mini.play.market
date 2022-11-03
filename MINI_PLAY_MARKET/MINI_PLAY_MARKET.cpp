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


//функція яка переносить вас
void gotoxy(int x, int y) {
	COORD p = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
}
//функція яка робить обробку клавиш
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

//це 1 ф-ція яка переносить
void perenos(int x, int y) {
	COORD position_1 = { x,y }; //позиция x и y
	HANDLE hConsole_1 = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsole_1, position_1);
}
//щоб не видно курсора 
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
void ramka() {

	perenos(0,0);
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













void ball_right(int & gde, int& obman_x , int& obman_y , int& bonus, bool& anti_bonus, int & or_or, int & x_y1, int & i,  int& i1, int& i2, int& bonus_per, int& bonus_x, int& bonus_y, int& anti_bonus_x, int& anti_bonus_y, int& bonus_perevirka, int& perevirka) {
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
				if (obman_x >= 24) {
					obman_x = 23;
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
					if (obman_x >= 24) {
						obman_x = 23;
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
						if (obman_x >= 24) {
							obman_x = 23;
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
				if (obman_x >= 24) {
					obman_x = 23;
				}
				if (obman_y <= 0) {
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
					if (obman_x >= 24) {
						obman_x = 23;
					}
					if (obman_y <= 0) {
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
						if (obman_x >= 24) {
							obman_x = 23;
						}

						if (obman_y <= 0) {
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


void ball_left(int& gde, int& obman_x, int& obman_y, int& bonus, bool& anti_bonus, int& or_or, int& x_y1, int& i, int& i1, int& i2, int& bonus_per, int& bonus_x, int& bonus_y, int& anti_bonus_x, int& anti_bonus_y, int& bonus_perevirka, int& perevirka, int &i3, int& chochik, int& x_y, int& right) {
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
				if (obman_y <= 0) {
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
					if (obman_y <= 0) {
						obman_y = 1;
					}
					if (obman_x == 0) {
						obman_x = 1;
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
						if (obman_y <= 0) {
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
void reg(int gde) {

}
void login(int gde) {

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
		int gde = 2;
		SetColor(RED_FADE, WHITE);

		perenos(6, 1);
		SetColor(RED_FADE, PINK_FADE);
		cout << "начати гру";

		perenos(6, 2);
		SetColor(RED_FADE, BLACK);
		cout << "правила ігор";

		int what_1 = 1;
		int true_false = 1;
		while (true_false != 0) {
			if (what_1 == 1) {
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
						if (gde ==1) {

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
			SetColor(WHITE, BLACK);


			if (what_1 == 2) {
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




				Sleep(20000);

				what_1 = 3;


			}
			if (what_1 == 3) {
				what = 1;
				true_false = 0;
			}







		}
	}
	//вибір гри
	if (what == 1) {
		system("cls");
		setlocale(LC_ALL, "Ukrainian");
		SetConsoleOutputCP(1251);
		SetConsoleCP(1251);
		srand(time(NULL));
		ramka();
		int gde = 2;
		SetColor(RED_FADE, WHITE);
		perenos(6, 1);
		SetColor(RED_FADE, PINK_FADE);
		cout << "гра pong";
		perenos(6, 2);
		SetColor(RED_FADE, BLACK);
		cout << "гра mini_race";
		int what_1 = 1;
		int true_false = 1;
		while (true_false != 0) {
			if (what_1 == 1) {
				perenos(0, 0);
				GetKEY();

				if (KEY[38])
				{
					gde = 1;
					if (gde == 1) {
						color_black(gde);
						perenos(6, gde);

						cout << "гра pong";









						perenos(0, gde);


						color_pink(gde);
						perenos(6, gde);
						cout << "гра pong";

					}


					if (gde == 2) {

						color_black(1);
						perenos(6, 1);
						cout << "гра pong";
						gde--;
					}
					else
						if (gde == 1) {

							color_black(2);
							perenos(6, 2);

							cout << "гра mini_race";
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
							cout << "гра mini_race";

						}

						if (gde == 2) {

							color_black(1);
							perenos(6, 1);
							cout << "гра pong";
							gde--;
						}
						else
							if (gde == 1) {

								color_black(2);
								perenos(6, 2);

								cout << "гра mini_race";
								gde++;
							}
					}
					else
						if (KEY[13])
						{
							if (gde == 1) {
								what_1 = 3;
							}
							else if (gde == 2) {
								what_1 = 2;
							}

						}
			}
						if (what_1 == 2) {
							true_false = 0;
							what = 2;

						}
						if (what_1 == 3) {
							what = 3;
							true_false = 0;
						}
			
			SetColor(WHITE, BLACK);


		







		}
	




	}
	int regim = 0;
	//гра 1 пін-понг
	if (what == 2) {
		system("cls");

		ramka();
		int gde = 2;
	

		perenos(3, 1);
		SetColor(RED_FADE, PINK_FADE);
		cout << "на одного гравця";

		perenos(3, 2);
		SetColor(RED_FADE, BLACK);
		cout << "на двох гравців";

		int what_1 = 1;
		int true_false_1 = 1;
		while (true_false_1 != 0) {
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
		if (regim == 1) {
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
						anti_bonus_y = 3 + rand() % (10);
						bonus_per_print = 6;

					}
					if (bonus_per_print == 6) {
						perenos(anti_bonus_x, anti_bonus_y);

						SetColor(PINK_FADE, BLACK);
						cout << "^";
						anti_bonus = FALSE;
						bonus_per  = 50;
						SetColor(WHITE, BLACK);
					}
				}
				//мяч
				
				
					if (perevirka == 1) {
						ball_right(gde, obman_x, obman_y, bonus, anti_bonus, or_or, x_y1, i, i1, i2, bonus_per, bonus_x, bonus_y, anti_bonus_x, anti_bonus_y, bonus_perevirka, perevirka);

					}

					else if (perevirka == 2) {
						ball_left(gde, obman_x, obman_y, bonus, anti_bonus, or_or, x_y1, i, i1, i2, bonus_per, bonus_x, bonus_y, anti_bonus_x, anti_bonus_y, bonus_perevirka, perevirka,i3,  chochik,  x_y,  right);
						
					}








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
							if(bonus == 2){
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

		if (regim == 2) {
			gotoxy(0, 0);
			int mozno = 0;
			int anti = 0;
			int verh = 13;
			int right = 25;

			for (int i = 0; i < right; i++) {
				cout << "*";
			}
			cout << endl;
			for (int j = 0; j < verh; j++) {
				for (int i = 0; i < 24; i++) {
					cout << " ";
					if (i == 23) {
						cout << "*" << endl;
					}
				}
			}

			for (int i = 0; i < 25; i++) {
				cout << "*";
			}
			int i = 8;
			int i1 = 9;
			int i2 = 10;
			int i_1 = 8;
			int i1_1 = 9;
			int i2_1 = 10;
			//верх
			perenos(2, i);

			cout << "*";
			//середня
			perenos(2, i1);
			cout << "*";
			//низ
			perenos(2, i2);
			cout << "*";
			//мяч
			perenos(7, 8);
			cout << "o";

			perenos(20, i_1);

			cout << "*";
			//середня
			perenos(20, i1_1);
			cout << "*";
			//низ
			perenos(20, i2_1);
			cout << "*";
			//мяч

			//нічого
			perenos(25, 25);
			cout << " ";
			int obman_x = 7;
			int obman_y = 8;
			int k = obman_x;
			int perevirka = 1;
			int chochik = 0;
			int chochik1 = 0;
			
	
			


			int x_y1 = 0;
			int x_y = 0;
			int or_all = 0;
			int x_rand = 0;
			int y_rand = 0;
			int left_or_right = 0;//1right 2left
			//1 верх
			int predel = 0;
			//генератори рандомних чисел
			x_y = 1 + rand() % (2);
			x_y1 = 1 + rand() % (2);
			int or_or = 1;
			while (anti != 1)
			{
				//х y мяча
				ConsoleCursorVisible(false, 100);
				perenos(2, i);
				cout << "*";

				perenos(2, i1);
				cout << "*";

				perenos(2, i2);
				cout << "*";
			
				
				perenos(20, i_1);
				cout << "*";

				perenos(20, i1_1);
				cout << "*";

				perenos(20, i2_1);
				cout << "*";

				perenos(100, 10);
				cout << obman_x << "  " << obman_y;
				//мяч
				int right_left = 0;
				if (mozno == 0) {
					if (perevirka == 1) {
						left_or_right = 1;
						if (obman_y == 1 or obman_y == 13 or obman_x == 23 or obman_x == 2) {

							or_or = 1 + rand() % (3);

						}


						if (obman_y == i or obman_y == i1 or obman_y == i2) {
							if (obman_x == 3) {
								or_or = 1 + rand() % (3);
							}
						}

						if (obman_y == i_1 or obman_y == i1_1 or obman_y == i2_1) {
							if (obman_x == 19) {
								or_or = 1 + rand() % (3);
							}
						}
						if (x_y1 == 1) {



							if (or_or == 1) {
								if (obman_y < 14 and obman_x < 24 and obman_y > 0) {

									if (obman_y == i or obman_y == i1 or obman_y == i2) {
										if (obman_x == 3) {
											perevirka = 1;
										}
									}
									if (obman_y == i_1 or obman_y == i1_1 or obman_y == i2_1) {
										if (obman_x == 19) {
											perevirka = 2;
										}
									}

									perenos(obman_x, obman_y);
									cout << " ";

									obman_x++;
									obman_y++;
									if (obman_x >= 24) {
										obman_x = 23;
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
										if (obman_y == i_1 or obman_y == i1_1 or obman_y == i2_1) {
											if (obman_x == 19) {
												perevirka = 2;
											}
										}

										perenos(obman_x, obman_y);
										cout << " ";
										obman_x++;
										obman_x++;
										obman_y++;
										if (obman_x >= 24) {
											obman_x = 23;
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
											if (obman_y == i_1 or obman_y == i1_1 or obman_y == i2_1) {
												if (obman_x == 19) {
													perevirka = 2;
												}
											}

											perenos(obman_x, obman_y);
											cout << " ";

											obman_x++;
											obman_y++;
											obman_y++;
											if (obman_x >= 24) {
												obman_x = 23;
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

									if (obman_y == i_1 or obman_y == i1_1 or obman_y == i2_1) {
										if (obman_x == 19) {
											perevirka = 2;
										}
									}
									perenos(obman_x, obman_y);
									cout << " ";

									obman_x++;
									obman_y--;
									if (obman_x >= 24) {
										obman_x = 23;
									}
									if (obman_y == 0) {
										obman_y = 1;
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
										if (obman_y == i_1 or obman_y == i1_1 or obman_y == i2_1) {
											if (obman_x == 19) {
												perevirka = 2;
											}
										}

										perenos(obman_x, obman_y);
										cout << " ";
										obman_x++;
										obman_x++;
										obman_y--;
										if (obman_x >= 24) {
											obman_x = 23;
										}
										if (obman_y == 0) {
											obman_y = 1;
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
											if (obman_y == i_1 or obman_y == i1_1 or obman_y == i2_1) {
												if (obman_x == 19) {
													perevirka = 2;
												}
											}


											perenos(obman_x, obman_y);
											cout << " ";

											obman_x++;
											obman_y--;
											if (obman_x >= 24) {
												obman_x = 23;
											}
											obman_y--;
											if (obman_y == 0) {
												obman_y = 1;
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
						if (obman_y == 14) {
							for (int i = 0; i < right; i++) {
								cout << "*";
							}

							x_y1 = 1 + rand() % (2);
							obman_y = 13;

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

					else if (perevirka == 2) {
						left_or_right = 2;
						if (obman_y == 1 or obman_y == 13 or obman_x == 23 or obman_x == 2) {

							or_or = 1 + rand() % (3);

						}


						if (obman_y == i or obman_y == i1 or obman_y == i2) {
							if (obman_x == 3) {
								or_or = 1 + rand() % (3);
							}
						}
						if (obman_y == i_1 or obman_y == i1_1 or obman_y == i2_1) {
							if (obman_x == 19) {
								or_or = 1 + rand() % (3);
							}
						}

						//ліво-верх
						if (x_y == 1) {


							if (or_or == 1) {
								if (obman_y < 14 and obman_x > 1 and obman_y > 0) {

									if (obman_y == i or obman_y == i1 or obman_y == i2) {
										if (obman_x == 3) {
											perevirka = 1;
										}
									}

									perenos(obman_x, obman_y);
									cout << " ";

									obman_x--;
									obman_y--;
									if (obman_y == 0) {
										obman_y = 1;
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
											if (obman_x == 3) {
												perevirka = 1;
											}
										}



										perenos(obman_x, obman_y);
										cout << " ";
										obman_x--;
										obman_x--;
										obman_y--;
										if (obman_y == 0) {
											obman_y = 1;
										}
										if (obman_x == 0) {
											obman_x = 1;
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
												if (obman_x == 3) {
													perevirka = 1;
												}
											}


											perenos(obman_x, obman_y);
											cout << " ";

											obman_x--;
											obman_y--;
											obman_y--;
											if (obman_y == 0) {
												obman_y = 1;
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
								perevirka = 1;

							}

						}
						//ліво низ
						if (x_y == 2) {
							if (or_or == 1) {
								if (obman_y < 14 and obman_x > 1 and obman_y > 0) {

									if (obman_y == i or obman_y == i1 or obman_y == i2) {
										if (obman_x == 3) {
											perevirka = 1;
										}
									}


									perenos(obman_x, obman_y);
									cout << " ";

									obman_x--;
									obman_y++;
									perenos(obman_x, obman_y);
									cout << "o";
									Sleep(85);




								}
							}

							else
								if (or_or == 2) {
									if (obman_y < 14 and obman_x > 1 and obman_y > 0) {

										if (obman_y == i or obman_y == i1 or obman_y == i2) {
											if (obman_x == 3) {
												perevirka = 1;
											}
										}


										perenos(obman_x, obman_y);
										cout << " ";
										obman_x--;
										obman_x--;
										obman_y++;
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
												if (obman_x == 3) {
													perevirka = 1;
												}
											}


											perenos(obman_x, obman_y);
											cout << " ";

											obman_x--;
											obman_y++;
											obman_y++;
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








					GetKEY();

					//обрлбка верх


					//клавиша верх
					if (left_or_right == 2) {
						if (KEY[38])
						{

							if (i >= verh - 11) {
								//закраска старих
								i++;
								i1++;
								i2++;
								perenos(2, i);
								cout << " ";
								perenos(2, i1);
								cout << " ";

								perenos(2, i2);
								cout << " ";
								//+ в верх
								i--;
								i1--;
								i2--;

								i--;
								i1--;
								i2--;
								perenos(2, i);
								cout << "*";
								perenos(2, i1);
								cout << "*";

								perenos(2, i2);
								cout << "*";

							}


						}
						//клавиша вниз
						else
							if (KEY[40])
							{
								if (i <= verh - 3) {
									//закраска старих
									i--;
									i1--;
									i2--;
									perenos(2, i);
									cout << " ";
									perenos(2, i1);
									cout << " ";
									perenos(2, i2);
									cout << " ";
									//+ в верх
									i++;
									i1++;
									i2++;

									i++;
									i1++;
									i2++;
									perenos(2, i);
									cout << "*";
									perenos(2, i1);
									cout << "*";

									perenos(2, i2);
									cout << "*";

								}



							}
					}
				}

				if (left_or_right == 1) {
					if (KEY[38])
					{

						if (i_1 >= verh - 11) {
							//закраска старих
							i_1++;
							i1_1++;
							i2_1++;
							perenos(20, i_1);
							cout << " ";
							perenos(20, i1_1);
							cout << " ";

							perenos(20, i2_1);
							cout << " ";
							//+ в верх
							i_1--;
							i1_1--;
							i2_1--;

							i_1--;
							i1_1--;
							i2_1--;
							perenos(20, i_1);
							cout << "*";
							perenos(20, i1_1);
							cout << "*";

							perenos(20, i2_1);
							cout << "*";

						}


					}
					//клавиша вниз
					else
						if (KEY[40])
						{
							if (i_1 <= verh - 3) {
								//закраска старих
								i_1--;
								i1_1--;
								i2_1--;
								perenos(20, i_1);
								cout << " ";
								perenos(20, i1_1);
								cout << " ";
								perenos(20, i2_1);
								cout << " ";
								//+ в верх
								i_1++;
								i1_1++;
								i2_1++;

								i_1++;
								i1_1++;
								i2_1++;
								perenos(20, i_1);
								cout << "*";
								perenos(20, i1_1);
								cout << "*";

								perenos(20, i2_1);
								cout << "*";

							}



						}
				}
				}



				
						
					

		

	}
	}
	
	//гра 2 гонка
	if (what == 3) {
		int lvl = 0;
		gotoxy(0, 2400);
		cout << "у вас на вибір є 3 lvl 1 lvl дуже простий 2 lvl средній 3 lvl hard";
		gotoxy(0, 2401);
		cout << "ваш вибір: ";
		cin >> lvl;
		//контур
		if (lvl == 1) {
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


			int dead = 0;

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
			while (1)
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

						dead = 1;
					}

					if (plat_y_1 == car_y and plat_x_1 == car_x) {
						perenos(car_x, car_y);
						cout << " ";

						dead = 1;

					}
					if (patron_x == car_x and patron_y == car_y) {
						perenos(car_x, car_y);
						cout << " ";
						car_y = 0;
						car_perevirka = 1;
						perevirka = 1;

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











				if (dead == 1) {
					perenos(30, 50);
					cout << "ви проиграли ви збилися в машину";
					Sleep(1000);
					break;
				}


			}
		}
		else
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

				int dead = 0;

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
				while (1)
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

							dead = 1;
						}

						if (plat_y_1 == car_y and plat_x_1 == car_x) {
							perenos(car_x, car_y);
							cout << " ";

							dead = 1;

						}



						if (plat_y == car_y1 and plat_x == car_x1) {
							perenos(car_x1, car_y1);
							cout << " ";

							dead = 1;
						}

						if (plat_y_1 == car_y1 and plat_x_1 == car_x1) {
							perenos(car_x1, car_y1);
							cout << " ";

							dead = 1;

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











					if (dead == 1) {
						perenos(30, 50);
						cout << "ви проиграли ви збилися в машину";
						Sleep(1000);
						break;
					}


				}
			}
			else
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
					int dead = 0;

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
					while (1)
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

								dead = 1;
							}

							if (plat_y_1 == car_y and plat_x_1 == car_x) {
								perenos(car_x, car_y);
								cout << " ";

								dead = 1;

							}



							if (plat_y == car_y1 and plat_x == car_x1) {
								perenos(car_x1, car_y1);
								cout << " ";

								dead = 1;
							}

							if (plat_y_1 == car_y1 and plat_x_1 == car_x1) {
								perenos(car_x1, car_y1);
								cout << " ";

								dead = 1;

							}


							if (plat_y == car_y2 and plat_x == car_x2) {
								perenos(car_x2, car_y2);
								cout << " ";

								dead = 1;
							}

							if (plat_y_1 == car_y2 and plat_x_1 == car_x2) {
								perenos(car_x2, car_y2);
								cout << " ";

								dead = 1;

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











						if (dead == 1) {
							perenos(30, 50);
							cout << "ви проиграли ви збилися в машину";
							Sleep(1000);
							break;
						}


					}
				}

	}
	//калькурятор калорій
	

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



// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"




//інт через який визвав основну ф-цію



// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"

﻿//інклюди
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

	perenos(0,1000);
	for (int i = 0; i < 24; i++) {
		cout << "*";
	}

	for (int j = 1001; j < 1013; j++) {
		perenos(0, j);
		for (int i = 0; i < 24; i++) {
			
			perenos(i, j);
			if (i == 23) {
				cout << "*" << endl;
			}
		}
	}
	perenos(0, 1012);
	for (int i = 0; i < 24; i++) {
		cout << "*";
	}
}










//основна ф-ція




void all() {
	ConsoleCursorVisible(false, 100);
	setlocale(LC_ALL, "Ukrainian");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	srand(time(NULL));




	int what = 0;
	int yes_or_no = 0;
	//меню

	if (what == 0) {
		setlocale(LC_ALL, "Ukrainian");
		SetConsoleOutputCP(1251);
		SetConsoleCP(1251);
		srand(time(NULL));

		ramka();
		int gde = 2;
		SetColor(RED_FADE, WHITE);

		perenos(6, 1001);
		cout << "начати гру";

		perenos(6, 1002);
		cout << "правила ігор";

		int what_1 = 1;
		int true_false = 1;
		while (true_false != 0) {
			if (what_1 == 1) {
				perenos(0, 1000);
				GetKEY();

				if (KEY[38])
				{
					gde = 1001;
					if (gde == 1001) {
						for (int i = 0; i < 23; i++) {
							perenos(i, gde);
							SetColor(RED_FADE, WHITE);
							cout << " ";
						}
						perenos(6, gde);
						cout << "начати гру";









						perenos(0, gde);


						for (int i = 0; i < 23; i++) {
							perenos(i, gde);
							SetColor(RED_FADE, BLACK);
							cout << " ";
						}
						perenos(6, gde);
						cout << "начати гру";

					}


					if (gde == 1002) {

						for (int i = 0; i < 23; i++) {
							perenos(i, 1001);
							SetColor(RED_FADE, WHITE);
							cout << " ";
						}
						perenos(6, 1001);
						cout << "начати гру";
						gde--;
					}
					else
						if (gde == 1001) {

							for (int i = 0; i < 23; i++) {
								perenos(i, 1002);
								SetColor(RED_FADE, WHITE);
								cout << " ";
							}
							perenos(6, 1002);

							cout << "правила ігор";
							gde++;
						}


				}
				//клавиша вниз
				else
					if (KEY[40])
					{
						gde = 1002;
						if (gde == 1002) {

							for (int i = 0; i < 23; i++) {
								perenos(i, gde);
								SetColor(RED_FADE, WHITE);
								cout << " ";
							}
							perenos(6, gde);










							perenos(0, gde);


							for (int i = 0; i < 23; i++) {
								perenos(i, gde);
								SetColor(RED_FADE, BLACK);
								cout << " ";
							}
							perenos(6, gde);
							cout << "правила ігор";

						}

						if (gde == 1002) {

							for (int i = 0; i < 23; i++) {
								perenos(i, 1001);
								SetColor(RED_FADE, WHITE);
								cout << " ";
							}
							perenos(6, 1001);
							cout << "начати гру";
							gde--;
						}
						else
							if (gde == 1001) {

								for (int i = 0; i < 23; i++) {
									perenos(i, 1002);
									SetColor(RED_FADE, WHITE);
									cout << " ";
								}
								perenos(6, 1002);

								cout << "правила ігор";
								gde++;
							}
					}
					else
						if (KEY[13])
						{
							if (gde == 1001) {
								what_1 = 2;
							}
							else if (gde == 1002) {
								what_1 = 3;
							}

						}
			}
			SetColor(WHITE, BLACK);


			if (what_1 == 2) {
				perenos(25, 1200);
				cout << "гра 1 ping-pong її правила : ";
				perenos(25, 1201);
				cout << "потрібно двигати платформою і відбивати мяч ";
				perenos(25, 1202);
				cout << "якщо мяч заходить за платформу - 50 очков якщо відбивається +100 ";

				perenos(25, 1203);
				cout << "гра 2 mini_race її правила : ";

				perenos(25, 1204);
				cout << "потрібно уварачоватися від машин щоб не збитися ";
				perenos(25, 1205);
				cout << "якщо машина заходить за вас то +10% до нового уровня якщо збивається то ви програли";

				perenos(25, 1206);
				cout << "програма  3 калорії її правила : ";


				perenos(25, 1207);
				cout << "правил немає тому що там все розписано і це не гра ";


				Sleep(20000);

				what_1 = 1;


			}
			if (what_1 == 3) {
				what = 1;
				true_false = 0;
			}







		}
	}
	//вибір гри
	if (what == 1) {

		gotoxy(25, 800);
		cout << "Добрый день вы зашли в игру MINI_GOOGLE_PLAY";
		gotoxy(25, 801);
		cout << "у вас є на вибор 2 ігри і 1 програма";
		gotoxy(25, 802);
		cout << "1 ігра MINI_PONG 2 ігра MINE_RASE 3 КАЛОРІЇ";

		gotoxy(25, 803);
		cout << "щоб увійти в гру 1 нажміть 2";

		gotoxy(25, 804);
		cout << "щоб увійти в гру 2 нажміть 3";

		gotoxy(25, 805);
		cout << "щоб увійти в програму 3 нажміть 4";

		gotoxy(25, 806);

		cout << "ваш вибір: ";
		cin >> what;





	}
	int regim = 0;
	//гра 1 пін-понг
	if (what == 2) {
		perenos(25, 500);
		cout << "який режим хочете зыграти на 1 чи на 2 чоловік: ";
		cin >> regim;
		if (regim == 1) {
			//рамки гри
			gotoxy(0, 0);
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
			int x_y3 = 0;
			int or_all = 0;
			int x_rand = 0;
			int y_rand = 0;
			//1 верх
			int predel = 0;
			//генератори рандомних чисел
			x_y = 1 + rand() % (2);
			x_y1 = 1 + rand() % (2);
			x_y3 = 1 + rand() % (3);
			while (1)
			{
				//х y мяча
				ConsoleCursorVisible(false, 100);
				perenos(80, 1);
				cout << obman_x << " " << obman_y;


				//мяч
				if (perevirka == 1) {

					if (x_y1 == 1) {






						//ALL

						//право-вниз
						if (obman_y < 14 & obman_x < 24 & obman_y > 0) {



							perenos(obman_x, obman_y);
							cout << " ";

							obman_x++;
							obman_y++;
							perenos(obman_x, obman_y);
							cout << "o";
							Sleep(85);




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




						//50\50








					}
					//право-верх
					if (x_y1 == 2) {



						perenos(obman_x, obman_y);
						cout << " ";

						obman_x++;
						obman_y--;
						perenos(obman_x, obman_y);
						cout << "o";

						Sleep(85);



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
					if (obman_y == 140) {
						for (int i = 0; i < right; i++) {
							cout << "*";
						}

						x_y1 = 1 + rand() % (2);
						obman_y = 13;

					}








				}

				else if (perevirka == 2) {


					//ліво-верх
					if (x_y == 1) {
						if (obman_y >= 0 & obman_x <= 24 & obman_x >= 0) {


							perenos(obman_x, obman_y);
							cout << " ";

							obman_x--;
							obman_y--;
							perenos(obman_x, obman_y);
							cout << "o";

							Sleep(85);
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


					}
					//ліво низ
					if (x_y == 2) {
						if (obman_y >= 0 & obman_x <= 24 & obman_x >= 0) {

							perenos(obman_x, obman_y);
							cout << " ";

							obman_x--;
							obman_y++;
							perenos(obman_x, obman_y);
							cout << "o";

							Sleep(85);
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




				}








				GetKEY();

				//обрлбка верх


				//клавиша верх
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


				//обрлбка верх 112

			}
			//обробка мяча



		}

		if (regim == 2) {
			gotoxy(0, 0);
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
			gotoxy(80, 0);
			cout << "щочик балов ігрока 1:  ";
			gotoxy(93, 0);
			cout << chochik;

			gotoxy(80, 1);
			cout << "щочик баловігрок 2:  ";
			gotoxy(93, 1);
			cout << chochik1;
			gotoxy(90, 0);
			gotoxy(100, 0);


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
			while (1)
			{
				//х y мяча
				ConsoleCursorVisible(false, 100);
				perenos(80, 1);
				cout << obman_x << " " << obman_y;


				//мяч
				if (perevirka == 1) {
					left_or_right = 1;
					if (x_y1 == 1) {


						//ALL

						//право-вниз
						if (obman_y < 14 & obman_x < 24 & obman_y > 0) {



							perenos(obman_x, obman_y);
							cout << " ";

							obman_x++;
							obman_y++;
							perenos(obman_x, obman_y);
							cout << "o";
							Sleep(85);




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




						//50\50








					}
					//право-верх
					if (x_y1 == 2) {



						perenos(obman_x, obman_y);
						cout << " ";

						obman_x++;
						obman_y--;
						perenos(obman_x, obman_y);
						cout << "o";

						Sleep(85);



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
					if (obman_y == 140) {
						for (int i = 0; i < right; i++) {
							cout << "*";
						}

						x_y1 = 1 + rand() % (2);
						obman_y = 13;

					}




					if (obman_y == i_1 or obman_y == i1_1 or obman_y == i2_1) {
						if (obman_x == 19) {
							perevirka = 2;
							chochik1 = chochik1 + 100;
							gotoxy(80, 0);
							cout << "щочик балов ігрока 2:  ";
							gotoxy(93, 0);
							cout << chochik1;
						}

					}
					if (obman_x < 21) {

						chochik1 = chochik1 - 50;
						gotoxy(80, 0);
						cout << "щочик балов игрока 2:  ";
						gotoxy(93, 0);
						cout << chochik1;
					}


				}
				//35
				else if (perevirka == 2) {
					left_or_right = 2;

					//ліво-верх
					if (x_y == 1) {
						if (obman_y >= 0 & obman_x <= 24 & obman_x >= 0) {


							perenos(obman_x, obman_y);
							cout << " ";

							obman_x--;
							obman_y--;
							perenos(obman_x, obman_y);
							cout << "o";

							Sleep(85);
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


					}
					//ліво низ
					if (x_y == 2) {
						if (obman_y >= 0 & obman_x <= 24 & obman_x >= 0) {

							perenos(obman_x, obman_y);
							cout << " ";

							obman_x--;
							obman_y++;
							perenos(obman_x, obman_y);
							cout << "o";

							Sleep(85);
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



					}

					if (obman_y == i or obman_y == i1 or obman_y == i2) {
						if (obman_x == 3) {
							perevirka = 1;
							chochik = chochik + 100;
							gotoxy(80, 0);
							cout << "щочик балов ігрока 1:  ";
							gotoxy(93, 0);
							cout << chochik;
						}

					}

					if (obman_x < 2) {

						chochik = chochik - 50;
						gotoxy(80, 0);
						cout << "щочик балов ігрока 1:  ";
						gotoxy(93, 0);
						cout << chochik;
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
				if (left_or_right == 1) {

					GetKEY();

					//обрлбка верх


					//клавиша верх
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


					//обрлбка верх 112

				}
				//обробка мяча

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
						perenos(car_x1,car_y1);
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
						if (car_x == car_x1 or car_x1 == car_x2 or car_x2 == car_x  ) {
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
	if (what == 4) {
		ConsoleCursorVisible(false, 100);
		setlocale(LC_ALL, "Ukrainian");
		SetConsoleOutputCP(1251);
		SetConsoleCP(1251);
		srand(time(NULL));
		GetKEY();

		int what = 0;
		while (1) {
			//меню
			if (what == 0) {
				perenos(40, 50);
				cout << "це програма яка щитає скіки калорій ";
				perenos(40, 51);
				cout << "вам потрібно їсти щоб не наберати і не худнути";
				perenos(40, 52);
				cout << "для начала вам потрібно знати свою суху масу тіла";
				perenos(40, 53);
				cout << "якщо ви не знаєте то напишіт 2 якщо знаете то напишіт 1 ";
				perenos(40, 54);
				cout << "пишіт ваш вибір: ";
				cin >> what;







			}
			//суха маса
			int procent = 0;
			int ves = 0;
			//знаете
			int rahunok = 0;
			int calori = 0;
			//рахуємо суху масу і калорії
			if (what == 1) {
				cout << "коли все нашли і зробили то впишіть следущі дані:";

				perenos(40, 100);
				cout << "1)свій вес, 2)свій процент жира і все";

				perenos(40, 101);
				cout << "впишіт свій вес: ";
				cin >> ves;
				perenos(40, 102);
				cout << "впишіт свій процент жира: ";
				cin >> procent;

				if (procent == 3) {
					rahunok = ves / 1.03;
				}
				else
					if (procent == 6) {//61
						rahunok = ves / 1.06;
					}
					else
						if (procent == 10) {//58
							rahunok = ves / 1.12;
						}
						else
							if (procent == 15) {
								rahunok = ves / 1.18;
							}

							else
								if (procent == 20) {//52
									rahunok = ves / 1.25;
								}
								else
									if (procent == 25) {//48
										rahunok = ves / 1.35;
									}
									else
										if (procent == 30) {//45
											rahunok = ves / 1.44;
										}
										else
											if (procent == 35) {//42
												rahunok = ves / 1.54;
											}
											else
												if (procent == 40) {//39
													rahunok = ves / 1.66;
												}
				calori = rahunok * 36;
				perenos(40, 103);
				cout << "ваша суха маса: " << rahunok << "кг" << "вот ваши калорії: " << calori - 100 << "-" << calori + 100;
				perenos(40, 104);
				cout << "це не 100% правильно якщо набераєте то відняти 100грам";
				perenos(40, 105);
				cout << " каші якщо худнете то + 100грам каші";
				Sleep(20000);
				what = 0;

			}
			//узнаємо ваш процент жиру
			if (what == 2) {
				perenos(40, 0);
				cout << "для начала вам потрібно узнати свій процент жира";
				perenos(40, 1);
				cout << "якщо ви не знаете то перейдіт на сайт і найдіть свій процент";
				perenos(40, 2);
				cout << "https://snazzy-eclair-dcd63a.netlify.app";
				perenos(40, 3);
				cout << "якщо ви знайшли свій процент жира ";

				perenos(40, 4);
				cout << "тоді ми можеме переходити до наступного процесу напишіть 1 щоб перейти: ";
				cin >> what;
			}
		}

	}
	
}

//новий


//конец













//інт через який визвав основну ф-цію
int main()
{
	setlocale(LC_ALL, "Ukrainian");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	srand(time(NULL));
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);
	all();


}



// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"

#include<iostream>
#include<conio.h>
using namespace std;
char Matrix[5][5] = { ' ','|',' ','|',' ','-','-','-','-','-',' ','|',' ','|',' ','-','-','-','-','-',' ','|',' ','|',' ' };
int idplayer = 1;
char Mark;
char key;
bool invalidmove;
int nextmove;
bool Gameover;
bool Gamewin;
// hien thi ra mang 2 chieu 3x3
void Bang()
{
	system("cls");
	cout << "nguoi choi so 1:X" << endl;
	cout << "nguoi choi so 2:O" << endl;
	for (int i = 0; i < 5; i++)
	{
		for (int  j = 0; j < 5; j++)
		{
			cout << Matrix[i][j];
		}
		cout << endl;
	}
}
// nguoi choi di truoc chon x
void PlayerMark()
{
	if (idplayer == 1)
		Mark = 'X';
	else
		Mark = 'O';
}

void Swichtturn()
{
	if (idplayer == 1)
		idplayer = 2;
	else
		idplayer = 1;
}
// nhap nuoc di cua ban
void Input()
{
	cout << "Nguoi choi " << idplayer << " nhap nuoc di: ";
	cin >> nextmove;
	do
	{
		invalidmove = true;
		if (nextmove == 1 && Matrix[0][0] == ' ')
			Matrix[0][0] = Mark;
		else if (nextmove == 2 && Matrix[0][2] == ' ')
			Matrix[0][2] = Mark;
		else if (nextmove == 3 && Matrix[0][4] == ' ')
			Matrix[0][4] = Mark;
		else if (nextmove == 4 && Matrix[2][0] == ' ')
			Matrix[2][0] = Mark;
		else if (nextmove == 5 && Matrix[2][2] == ' ')
			Matrix[2][2] = Mark;
		else if (nextmove == 6 && Matrix[2][4] == ' ')
			Matrix[2][4] = Mark;
		else if (nextmove == 7 && Matrix[4][0] == ' ')
			Matrix[4][0] = Mark;
		else if (nextmove == 8 && Matrix[4][2] == ' ')
			Matrix[4][2] = Mark;
		else if (nextmove == 9 && Matrix[4][4] == ' ')
			Matrix[4][4] = Mark;
		else
		{
			cout << "Nuoc di khong dung, vui long nhap lai: ";
			invalidmove = false;
			cin >> nextmove;
		}
	} while (!invalidmove);
}
// kiem tra nguoi chien thang
void Wincheck()
{
	Gameover = false;
	Gamewin = true;
	if (Matrix[0][0]!=' ' && Matrix[0][2] == Matrix[0][0] && Matrix[0][4] == Matrix[0][0])
	{
		Gameover = true;
	}
	if (Matrix[2][0] != ' ' && Matrix[2][2] == Matrix[2][0] && Matrix[2][4] == Matrix[2][0])
	{
		Gameover = true;
	}
	if (Matrix[4][0] != ' ' && Matrix[4][2] == Matrix[4][0] && Matrix[4][4] == Matrix[4][0])
	{
		Gameover = true;
	}
	if (Matrix[0][0] != ' ' && Matrix[2][0] == Matrix[0][0] && Matrix[4][0] == Matrix[0][0])
	{
		Gameover = true;
	}
	if (Matrix[0][2] != ' ' && Matrix[2][2] == Matrix[0][2] && Matrix[4][2] == Matrix[0][2])
	{
		Gameover = true;
	}
	if (Matrix[0][4] != ' ' && Matrix[2][4] == Matrix[0][4] && Matrix[4][4] == Matrix[0][4])
	{
		Gameover = true;
	}
	if (Matrix[0][0] != ' ' && Matrix[2][2] == Matrix[0][0] && Matrix[4][4] == Matrix[0][0])
	{
		Gameover = true;
	}
	if (Matrix[4][0] != ' ' && Matrix[2][2] == Matrix[4][0] && Matrix[0][4] == Matrix[4][0])
	{
		Gameover = true;
	}
	if (Matrix[0][0] !=' ' && Matrix[0][2] != ' ' && Matrix[0][4] != ' ' &&
		Matrix[2][0] != ' ' && Matrix[2][2] != ' ' && Matrix[2][4] != ' ' &&
		Matrix[4][0] != ' ' && Matrix[4][2] != ' ' && Matrix[4][4] != ' ' && !Gameover)
	{
		Gameover = true;
		Gamewin = false;
		cout << "Tro choi Hoa, 2 nguoi bang diem." << endl;
	}
}
int main()
{
	do
	{
		Bang();
		PlayerMark();
		Input();
		Wincheck();
		if (Gameover)
		{
			if (Gamewin)
			{
				cout << "Nguoi choi " << idplayer << "danh chien thang!" << endl;
			}
			cout << "Choi lai:(y/n)";
			cin >> key;
			if (key == 'n')
			{
				break;
			}
			if (key == 'y')
			{
				Gameover = false;
				Matrix[0][0] = ' ';
				Matrix[0][2] = ' ';
				Matrix[0][4] = ' ';
				Matrix[2][0] = ' ';
				Matrix[2][2] = ' ';
				Matrix[2][4] = ' ';
				Matrix[4][0] = ' ';
				Matrix[4][2] = ' ';
				Matrix[4][4] = ' ';

			}
			idplayer = 1;
		}
		else
			Swichtturn();
	} while (!Gameover);
	system("pause");
}

#include<iostream>
#include<stdio.h>

using namespace std;

char Matrix[5][5] = { ' ','|',' ','|',' ','-','-','-','-','-',' ','|',' ','|',' ','-','-','-','-','-',' ','|',' ','|',' ' };
int NguoiChoi = 1;
char Mark;
int Nuoc;
bool invalidmove;
bool Gameover;
bool Gamewin;
char key;
// cac ham trong bai
void Bang();
void PlayerMark();
void Swichtturn();
void Input();
void Wincheck();
// ham chinh
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
				cout << "Nguoi choi " << NguoiChoi << "danh chien thang!" << endl;
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
			NguoiChoi = 1;
		}
		else
			Swichtturn();
	} while (!Gameover);
	system("pause");
}
// tao khung nhin tren man hinh
void Bang(){
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
// neu nguoi cho 1 ki hieu X, nguoi choi 2 ki hieu O
void PlayerMark()
{
	if (NguoiChoi == 1)
		Mark = 'X';
	else
		Mark = 'O';
}
// thay doi nguoi choi
void Swichtturn()
{
	if (NguoiChoi == 1)
		NguoiChoi = 2;
	else
		NguoiChoi = 1;
}
// nhap nuoc di vao ban 
void Input()
{
	cout << "Nguoi choi " << NguoiChoi << " nhap nuoc di: ";
	cin >> Nuoc;
	do
	{
		invalidmove = true;
		if (Nuoc == 1 && Matrix[0][0] == ' ')
			Matrix[0][0] = Mark;
		else if (Nuoc == 2 && Matrix[0][2] == ' ')
			Matrix[0][2] = Mark;
		else if (Nuoc == 3 && Matrix[0][4] == ' ')
			Matrix[0][4] = Mark;
		else if (Nuoc == 4 && Matrix[2][0] == ' ')
			Matrix[2][0] = Mark;
		else if (Nuoc == 5 && Matrix[2][2] == ' ')
			Matrix[2][2] = Mark;
		else if (Nuoc == 6 && Matrix[2][4] == ' ')
			Matrix[2][4] = Mark;
		else if (Nuoc == 7 && Matrix[4][0] == ' ')
			Matrix[4][0] = Mark;
		else if (Nuoc == 8 && Matrix[4][2] == ' ')
			Matrix[4][2] = Mark;
		else if (Nuoc == 9 && Matrix[4][4] == ' ')
			Matrix[4][4] = Mark;
		else
		{
			cout << "Nuoc di khong dung, vui long nhap lai: ";
			invalidmove = false;
			cin >> Nuoc;
		}
	} while (!invalidmove);
}
// kiem tra dieu kien chien thang
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





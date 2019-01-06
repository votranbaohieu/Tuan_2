#include<iostream>
#include<string.h>
#include<stdio.h>
#include<vector>
#include<fstream>

using namespace std;
// khai bao du lieu cau hoi
struct cauhoi{
	string tencauhoi, a, b, c, d, dapan;
};

vector <cauhoi> CH;
int n;

void return1();
void chonde();
// hien thi lua chon ra man hinh
void menu(){
	cout<<"nhap 1 de chon de 1: "<<endl;
	cout<<"nhap 2 de chon de 2: "<<endl;
	cout<<"nhap 3 de chon de 3: "<<endl;	
	cout<<"nhap 4 de exit: "<<endl;
}
// doc de tu file txt
void docde(	ifstream &doc){
	doc>> n; // doc so luong cau hoi trong de
	string tam;
	getline(doc, tam);
	CH.resize(n);
	for (int i = 0; i < n; i++) // doc du lieu cua tung cau hoi 
	{
		getline(doc, CH[i].tencauhoi);
		getline(doc, CH[i].a);
		getline(doc, CH[i].b);
		getline(doc, CH[i].c);
		getline(doc, CH[i].d);
		getline(doc, CH[i].dapan);
	}
}
// kiem tra dap an 
bool kiemTra(cauhoi &p)
{
	int diem=0;
	string dap_an;
	cout << "Moi ban nhap dap an: ";
	cin>>dap_an; 
	if(dap_an==p.dapan) // kiem tra dap an vua nhap voi dap an dung
		return true;  // neu dung
	else
		return false; // neu sai
}
// hien thi cau hoi ra man hinh va xuat ra ket qua
void xuatcauhoi()
{
	int diem=0;
	for(int i = 0; i < CH.size(); i++)// hien thi cau hoi ra man hinh
	{
		cout << CH[i].tencauhoi<<endl;
		cout << CH[i].a<<endl;
		cout << CH[i].b<<endl;
		cout << CH[i].c<<endl;
		cout << CH[i].d<<endl;
		if (kiemTra(CH[i])==true)   // goi ham kiem tra xem ket qua dung khong
		{
			cout << "Dung"<<endl;
			diem++;  // neu dung tang diem len 1
		}
		else 
		{
			cout <<"Sai"<<endl;
			cout <<"Dap an dung la "<<CH[i].dapan<<endl;
		}
	}
	cout <<"So diem ban dat duoc la: "<<diem <<endl; 
}
// tro ve lua chon bo de khac neu muon
void return1(){
	cout<<" nhap 1 neu ban muon thuc hien bo de khac: ";
	int select;
	cin>> select;
	if (select == 1){
		system("cls");
		return chonde();
	}
	else
		cout<<"exit";	
}
// lua chon de can thuc hien
void chonde(){
		menu();
	ifstream doc;
	int select;
	cout << "Lua chon cua ban: ";
	cin >> select;
		switch (select)
		{
			{
		case 1: //  khi chon de 1
			system("cls");
			doc.open("bode1.txt", ios::in);
			docde(doc);
			xuatcauhoi();
			return1();
			break;
		case 2:  // khi chon de 2
			system("cls");
			doc.open("bode2.txt", ios::in);
			docde(doc);
			xuatcauhoi();
			return1();
			break;
		case 3: // khi chon de 3
			system("cls");
			doc.open("bode3.txt", ios::in);
			docde(doc);
			xuatcauhoi();
			return1();
			break;
		case 4:
			cout<<"exit";
			break;
		}
	}
}

int main(){
	chonde();	
}

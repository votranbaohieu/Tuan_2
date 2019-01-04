#include <iostream>
#include <string.h>
#include <vector>
#include <stdio.h>

using namespace std;

struct NhanVien{
	char nvID [5];
	char HoTen [20];
	int Tuoi;
	int Luong;
};

vector <NhanVien> dsnv;

bool ThemNV(NhanVien nv);
bool XoaNV(char* nvID);
void CapNhat(NhanVien nvMoi);
void inNV(NhanVien nv);
void inDSNV();
NhanVien Nhapbp();
void DocFile(char* namefile);
void Ghifile(char* namefile);

int main(){
	NhanVien nv1,nv2; 
	strcpy(nv1.nvID,"001");
	strcpy(nv1.HoTen,"Nguyen Van A");
	nv1.Tuoi=30;
	nv1.Luong=30000;
	strcpy(nv2.nvID,"002");
	strcpy(nv2.HoTen,"Nguyen Van B");
	nv2.Tuoi=35;
	nv2.Luong=34000;
	ThemNV(nv1);
	ThemNV(nv2);
//	inNV(nv1);
//	inNV(nv2);
//	XoaNV("002");
//	inDSNV();
//	NhanVien nv3= Nhapbp();
//	CapNhat(nv3);
//	inDSNV();
//	DocFile("input3.dat");
	inDSNV();
	Ghifile("output33.dat");
}
// them nv
bool ThemNV(NhanVien nv){
	int size = dsnv.size();
	for(int i = 0; i < size; i++)
	if(strcmp(nv.nvID,dsnv[i].nvID)==0)
		return false;
	dsnv.push_back(nv);
		return true;
}

bool XoaNV(char* nvID){
	int size = dsnv.size();
	int vitri = -1;
	for(int i= 0; i < size; i++){
		if(strcmp(nvID,dsnv[i].nvID)==0)
			vitri= i;
	}
	if(vitri != -1){
		dsnv.erase(dsnv.begin()+ vitri);
		return true;
	}
	return false;
}

void CapNhat(NhanVien nvMoi){
	int size = dsnv.size();
	int vitri = -1;
	for(int i = 0; i < size; i++){
		if(strcmp(nvMoi.nvID,dsnv[i].nvID)==0)
		vitri = i;
	}
	if(vitri != -1){
		strcpy(dsnv[vitri].nvID,nvMoi.nvID);
			strcpy(dsnv[vitri].HoTen,nvMoi.HoTen);
			dsnv[vitri].Tuoi=nvMoi.Tuoi;
			dsnv[vitri].Luong=nvMoi.Luong;
	}
}

void inNV(NhanVien nv){
	cout <<" maNv "<< nv.nvID << endl;
	cout <<" tenNV "<<nv.HoTen  << endl;
	cout <<" tuoiNV "<<nv. Tuoi << endl;
	cout <<" luongNV "<< nv.Luong << endl;
}

void inDSNV(){
	int size=dsnv.size();
	for(int i = 0;i < size; i++)
		inNV(dsnv[i]);
}

NhanVien Nhapbp(){
	NhanVien nv;
	cout<<"Nhap ma nv:";fflush(stdin);
	gets(nv.nvID);
	cout<<"Nhap ten nv:";fflush(stdin);
	gets(nv.HoTen);
	cout<<"Nhap tuoi nv:";
	cin>>nv.Tuoi;
	cout<<"Nhap luong nv:";
	cin>>nv.Luong;
	return nv;
}

/*void DocFile(char* namefile){
	dsnv.clear();
	FILE *f;
	f=fopen(namefile, "rb");
	if(f != NULL)
	{
		while(!feof(f))
		{
			NhanVien nv;
			fread(&nv, sizeof(NhanVien), 1, f);
			dsnv.push_back(nv);
		}
		fclose(f);
		dsnv.pop_back();
	}
}*/

void Ghifile(char* namefile){
	int size = dsnv.size();
	FILE *f;
	f = fopen(namefile, "wb");
	NhanVien nv;
	for(int i = 0; i < size; i++)
	{
		nv= dsnv[i];
		fwrite(&nv, sizeof(NhanVien), i, 0);
	}
}
 



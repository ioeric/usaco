/*
ID: eric.al1
PROG: transform
LANG: C++ 
*/

#include <iostream>
#include <fstream>
#include <iostream>
#include <string.h>
#define N 11
using namespace std;
char ori[N][N], tmp[N][N], dest[N][N];
int n;

ifstream fin("transform.in");
ofstream fout("transform.out");


void input(){
	fin >> n;

	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++){
			fin >> ori[i][j];
		}

	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++){
			fin >> dest[i][j];
		}

	
}

void Rotate_90(){
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++){
			tmp[j][n-i-1] = ori[i][j];
		}
	
	memcpy(ori, tmp, sizeof(ori));
}

bool check(){
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++)
			if (ori[i][j] != dest[i][j])
				return false;
	return true;
}

bool Reflect(){
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++){
			tmp[i][n-j-1] = ori[i][j];
		}
	
	memcpy(ori, tmp, sizeof(ori));
	
	if (check())
		return true;
	return false;
}


int Check_1_to_3(){
	Rotate_90();
	if (check()) {
		return 1;
	}
	
	Rotate_90();
	if (check()) {
		return 2;
	}
	
	Rotate_90();
	if (check()) {
		return 3;
	}

	Rotate_90();
	return 0;
}
int main(){
	input();
	
	int res = Check_1_to_3();
	if (res>0) {
		fout << res << endl;
		return 0;
	}

	if (Reflect()){
		fout << "4" << endl;
		return 0;
	}

	if (Check_1_to_3()){
		fout << "5" << endl;
		return 0;
	}

	Reflect();

	if (check()){
		fout << "6" << endl;
		return 0;
	}
	
	fout << "7" << endl;
			
	return 0;

}

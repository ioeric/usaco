/*
ID: eric.al1
PROG: palsquare
LANG: C++
*/

#include <fstream>
#include <iostream>

using namespace std;

#define MAX 300

char DIGIT[20];
ifstream fin("palsquare.in");
ofstream fout("palsquare.out");


void print_base(int digit[], int n){
	for (int i=n-1;i>=0;i--){
		if (digit[i]>=0 && digit[i]<=9)
			fout << digit[ i ];
		else
			fout << DIGIT[ digit[i] ];
	}

}
void check(int num, const int base){
	if (base <=0) return;
	
	int r;
	int pos = 0;
	int res[10];
	
	int square = num * num;
	while (square>0){
		r = square % base;
		res[ pos ] = r;
		square = square / base;
		pos++;
	}
	

	for (int i=0; i<pos/2;i++)
		if ( res[i]!=res[pos-i-1] )
			return;

	int ori[10];
	int ori_pos = 0;
	while (num >0){
		r = num % base;
		ori[ori_pos] = r;
		num = num / base;
		ori_pos++;
	}
	print_base(ori, ori_pos);
	fout << ' ';
	print_base(res, pos);
	fout << endl;
}
int main(){
	DIGIT[10] = 'A';
	DIGIT[11] = 'B';
	DIGIT[12] = 'C';
	DIGIT[13] = 'D';
	DIGIT[14] = 'E';
	DIGIT[15] = 'F';
	DIGIT[16] = 'G';
	DIGIT[17] = 'H';
	DIGIT[18] = 'I';
	DIGIT[19] = 'J';

	int base;
	fin >> base;

	for (int i=1;i<=300;i++)
		check(i, base);

	return 0;
	
}

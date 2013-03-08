/*
ID: eric.al1
PROG: dualpal
LANG: C++
*/

#include <fstream>

using namespace std;

bool check(int num, const int base){
	if (base <=0) return false;
	
	int r;
	int pos = 0;
	int res[100];
	
	while (num>0){
		r = num % base;
		res[ pos ] = r;
		num = num / base;
		pos++;
	}
	
	for (int i=0; i<pos/2;i++)
		if ( res[i]!=res[pos-i-1] )
			return false;
	return true;
}

int main(){
	ifstream fin("dualpal.in");
	ofstream fout("dualpal.out");

	int n, s;

	fin >> n >>  s;

	int count = 0;
	while (count < n){
		s++;
		int flag = 0;
		for (int base=2;base<=10;base++)
			if (check(s, base)){
				flag++;
				if (flag >=2) break;
			}

		if (flag >= 2){
			fout << s << endl;
			++count;
		}
	}

	return 0;
}

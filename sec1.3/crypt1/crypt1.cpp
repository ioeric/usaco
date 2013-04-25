/*
ID: eric.al1
PROG: crypt1
LANG: C++
*/

#include <fstream>
#include <stdlib.h>
#include <set>
#include <iostream>
using namespace std;

int n;
int cand[10];
bool flag[10] = {};
bool validate1(int num)
{
	if (num < 100 || num > 999)
		return false;
	int r,q;
	while (num > 0){
		r = num % 10;
		num = num / 10;
		if (!flag[r])
			return false;
	}
	return true;
}

bool validate2(int num)
{
	if (num < 1000 || num > 9999)
		return false;
	int r,q;
	while (num > 0){
		r = num % 10;
		num = num / 10;
		if (!flag[r])
			return false;
	}
	return true;
}

int main(){
	ifstream fin("crypt1.in");
	ofstream fout("crypt1.out");
	fin >> n;
	int tmp;
	for (int i=0;i<n;i++){
		fin >> cand[i];
		flag[ cand[i] ] = true;
	}
	int pos1 = 0;
	int guess;
	int p1,p2,p3,p4,p5;
	int result = 0;

	for (int i1=0;i1<n;i1++){
		p1 = cand[i1];
		for (int i2=0;i2<n;i2++){
			p2 = cand[i2];
			for (int i3=0;i3<n;i3++){
				p3 = cand[i3];
				guess = p1*100 + p2*10 + p3;
				for (int i4=0;i4<n;i4++){
					p4 = cand[i4];
					if (!validate1( guess * p4 ))
					continue;
					for (int i5=0;i5<n;i5++){
						p5 = cand[i5];
						if (!validate1( guess * p5 ))
						continue;
						int res = (p5*10 + p4) * guess;
						if (validate2(res))
							result++;
					}
				}

			}
		}
	}

	fout << result << endl;
	fin.close();
	fout.close();
	return 0;
}

/*
ID: eric.al1
PROG: milk
LANG: C++
*/

#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

struct Farmer{
	Farmer(int p, int a){
		Price = p; Amount = a;
	}
	int Price, Amount;	
};

bool Compare(Farmer f1, Farmer f2){
	return f1.Price < f2.Price;
}
int main(){
	ifstream fin("milk.in");
	ofstream fout("milk.out");

	int n, m;
	int tmpP, tmpA;

	vector< Farmer > vect;
	
	fin >> n >> m;
	
	for (int i=0;i<m;i++){
		fin >> tmpP >> tmpA;	
		vect.push_back(Farmer(tmpP, tmpA));
	}
	
	sort(vect.begin(), vect.end(), Compare);

	int pos = 0;
	int total = 0;
	while (n > 0){
		Farmer tmp = vect.at(pos);
		if (tmp.Amount <= n){
			total += tmp.Amount * tmp.Price;
			n -= tmp.Amount;
			pos++;
			continue;
		} else {
			total += n * tmp.Price;
			break;
		}
	}

	fout << total << endl;
	

}

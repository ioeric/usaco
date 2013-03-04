/*
ID: eric.al1
PROG: ride
LANG: C++
 */

#include <fstream>
#include <string>
using namespace std;

int main(){
	ifstream fin("ride.in");
	ofstream fout("ride.out");
	
	string comet, group;
	
	fin >> comet;
	fin >> group;
	
	int res1, res2;
	res1 = res2 = 1;

	for (int i=0;i<comet.length();i+=1){
		res1 *= (comet[i] - 'A') + 1;
		res1 %= 47;
		if (res1 == 0)
			break;
	}

	for (int i=0;i<group.length();i+=1){
		res2 *= (group[i] - 'A') + 1;
		res2 %= 47;
		if (res2 == 0)
			break;
	}

	if ( (res1-res2)%47 == 0 ){
		fout << "GO" << endl;
	}else
		fout << "STAY" << endl;
}

/*
ID: eric.al1
PROG: barn1
LANG: C++
*/

#include <fstream>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(){
	ifstream fin("barn1.in");
	ofstream fout("barn1.out");

	int M, S, C;
	int tmp;
	vector <int> stalls;
	vector <int> spareStalls;

	fin >> M >> S >> C;

	for (int i=0;i<C;i++){
		fin >> tmp;
		stalls.push_back(tmp);
	}

	sort(stalls.begin(), stalls.end());
	
	for (vector<int>::iterator it=stalls.begin()+1; it!=stalls.end(); it++){
		tmp = *it - *(it-1);
		if (tmp > 1)
			spareStalls.push_back(tmp-1);
	}

	
	sort(spareStalls.begin(), spareStalls.end(), std::greater<int>());
	
	int result = stalls.back() - stalls.at(0)+1; // Original total number of stalls blocked
	M--; // Use one board to block all stalls

	for (vector<int>::iterator it=spareStalls.begin(); it!=spareStalls.end(); it++){
		if (M<=0 || result == 0) break;
		result -= *it;
		M--;
	}
	
	fout << result << endl;
	return 0;
}

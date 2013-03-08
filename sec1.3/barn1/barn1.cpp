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
	vector <int> stalls; // Store stall numbers
	vector <int> spareStalls; // Store number of spare stalls that is continuous

	fin >> M >> S >> C;

	for (int i=0;i<C;i++){
		fin >> tmp;
		stalls.push_back(tmp);
	}

	sort(stalls.begin(), stalls.end());  // Sort then count continuous idle stalls
	
	for (vector<int>::iterator it=stalls.begin()+1; it!=stalls.end(); it++){
		tmp = *it - *(it-1);
		if (tmp > 1) // If the number of idle stalls between two occupied stalls is 1 or more
			spareStalls.push_back(tmp-1);
	}

	
	sort(spareStalls.begin(), spareStalls.end(), std::greater<int>());  // Sort numbers of continuous stalls 
	
	int result = stalls.back() - stalls.at(0)+1; // Original total number of stalls blocked
	M--; // Use one board to block all stalls

	// Greedy! Choose the longest continuous stalls first!
	for (vector<int>::iterator it=spareStalls.begin(); it!=spareStalls.end(); it++){
		if (M<=0 || result == 0) break;
		result -= *it;
		M--;
	}
	
	fout << result << endl;
	return 0;
}

/*
ID: eric.al1
PROG: gift1
LANG: C++
*/
#include <fstream>
#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(){
	ifstream fin("gift1.in");
	ofstream fout("gift1.out");
	
	int NP;
	fin >> NP;
	string *names = new string[NP];
	
	// For convenience, using map
	// mapping from name to gain ot loss
	map<string, int> m;  

	string name;
	
	// Input names
	for (int i=0;i<NP;i+=1){
		fin >> names[i];
		m[ names[i] ] = 0;
	}

	// Count
	int money, num;
	for (int i=0;i<NP;i+=1){
		fin >> name;
		fin >> money >> num;
		if ( num == 0 )
			continue;
		int mon = money / num; // m: mount of money given to each person
		m[ name ] -= mon * num;// Count how much money this person give out
		string tmpName;		
		for (int j=0;j<num;j+=1){
			fin >> tmpName;
			m[ tmpName ] += mon;
		}
	
	}

	for (int i=0;i<NP;i+=1){
		fout << names[i] << ' ' << m[ names[i] ] << endl;
	}
	
	delete [] names;
	return 0;

}

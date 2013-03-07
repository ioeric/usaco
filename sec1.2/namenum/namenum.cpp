/*
ID: eric.al1
PROG: namenum
LANG: C++
*/   

#include <fstream>
#include <string>
#include <map>
using namespace std;
	
string num;
int len;
map<char, char> m;
bool check(const string& str){
	if (str.length() != len)	
		return false;

	for (int i=0;i<len;i++){
		if (m[str[i]]!=num[i])			
			return false;
	}

	return true;
}

int main(){
	ifstream fin("namenum.in");
	ifstream dictFile("dict.txt");
	ofstream fout("namenum.out");


	m['A'] = m['B'] = m['C'] = '2';
	m['D'] = m['E'] = m['F'] = '3';
	m['G'] = m['H'] = m['I'] = '4';
	m['J'] = m['K'] = m['L'] = '5';
	m['M'] = m['N'] = m['O'] = '6';
	m['P'] = m['R'] = m['S'] = '7';
	m['T'] = m['U'] = m['V'] = '8';
	m['X'] = m['Y'] = m['W'] = '9';


	string str;
	fin >> num;
	len = num.length();
	bool mark = false;
	while (!dictFile.eof()){
		dictFile >> str;
		if (check(str)){
			fout << str << endl;
			mark = true;
		}
	}

	if (!mark)
		fout << "NONE" << endl;
	return 0;


}

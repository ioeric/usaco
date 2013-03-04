/*
ID: eric.al1
PROG: beads
LANG: C++
*/

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main(){
	ifstream fin("beads.in");
	ofstream fout("beads.out");
	
	int n;
	string str;

	fin >> n;
	fin >> str;
	
	int result = 0;
	int pos_right, pos_left, next;
	char first_right, first_left;
	int num_right, num_left;
	int res;
	for (int i=0; i<str.length(); i+=1){
		pos_right = i;
		pos_left = ( i-1 + n) % n;
		
		first_right = str[pos_right];
		first_left = str[pos_left];
		if (first_right == 'w'){
			int offset = 1;
			while (offset < n){
				int pos = (first_right + offset) % n;
				if (str[pos] == 'r'){
					first_right = 'r';
					break;
				}

				if (str[pos] == 'b'){
					first_right = 'b';
					break;
				}
				offset+=1;
			}
		}

		if (first_left == 'w'){
			int offset = 1;
			while (offset < n){
				int pos = (first_left - offset + n) % n;
				if (str[pos] == 'r'){
					first_left = 'r';
					break;
				}

				if (str[pos] == 'b'){
					first_left = 'b';
					break;
				}

				offset += 1;


			}
		}
		num_right = num_left = 0;	
		// Collect (right direction)
			
		while (true){	
			num_right += 1;
			if (pos_right == pos_left) break;
			
			next = (pos_right + 1) % n; 
			if (str[next] != first_right && str[next] != 'w')
				break;
			
			pos_right =  next;
		}
		
		if (pos_right == pos_left){
			result = n;
			break;
		}

		while (true){
			num_left += 1;
			next = (pos_left - 1 + n) % n;
			
			if (next == pos_right) break;

			if (str[next] != first_left && str[next]!='w')
				break;

			pos_left = next;

		}

		res = num_right + num_left;
		result = (res>result)?res:result;
		if (result == n) break;
	
	}

	fout << result << endl;
	return 0;

	
}

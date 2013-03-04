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
	
	// Final result
	int result = 0;
	// pos_right: number of the bead on the right side of breakpoint
	// pos_left:  number of the bead on the left side of breakpoint
	// next: a temperary value to use latter
	// If color of the breakpoint is 'w', first color should be 
	// the next(recursively) one whose color is not 'w' 
	int pos_right, pos_left, next;
	
	// Color of first bead 'r', 'b', or 'r'
	char first_right, first_left;

	// Number of beads collected
	int num_right, num_left;

	//Store total number of beads collected this time
	int res;

	// Try every break point
	for (int i=0; i<str.length(); i+=1){
		// Count start point for either side
		pos_right = i;
		pos_left = ( i-1 + n) % n;
		
		// Get color of first balls
		first_right = str[pos_right];
		first_left = str[pos_left];

		// If current color is 'w', find next one that is not white
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

		// If current one is white, find next one that is not white
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
			// Collect bead at this position
			num_right += 1;

			// If pos_right is pos_left, all beads have been collected
			if (pos_right == pos_left) break;
			
			// Count number of next one
			next = (pos_right + 1) % n; 

			// If next one is not of the same color or not 'w'
			if (str[next] != first_right && str[next] != 'w')
				break;
			
			// Collect this one and go to next bead
			pos_right =  next;
		}
		
		// All beads have been collected
		if (pos_right == pos_left){
			result = n;
			break;
		}

		// Left direction 
		while (true){
			// Collect bead at this position
			num_left += 1;
			// Count next bead's number 
			next = (pos_left - 1 + n) % n;
			
			// Since baed at pos_right has been collected before
			// If next == pos_right, all beads have been collected
			if (next == pos_right) break;

			// Check whether next is the same color or 'w'
			if (str[next] != first_left && str[next]!='w')
				break;

			pos_left = next;

		}

		// Count the number of beads collected this time
		res = num_right + num_left;
		result = (res>result)?res:result;
		if (result == n) break;
	
	}

	fout << result << endl;
	return 0;

	
}

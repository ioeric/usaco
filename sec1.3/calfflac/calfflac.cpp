/*
ID: eric.al1
PROG: calfflac
LANG: C++
*/
#include <fstream>
#include <cctype>
using namespace std;

char str[20000];

bool judge(char ch){
	return (ch >= 'a' && ch<='z' || ch >= 'A' && ch <='Z');
}

bool equal(char ch1, char ch2){
	return (tolower(ch1) == tolower(ch2));
}
int main(){
	ifstream fin("calfflac.in");
	ofstream fout("calfflac.out");
	
	// Input data using fin.get().
	// Read in spaces and '\n'
	int num = 0;
	while (true){
		fin.get(str[num]);
		num++;
		if (fin.eof()) break;
	}

	num--;
	
	// Result records max length
	int result = 0;
	// res_st and res_ed record start point and end point of printed sub-string
	int res_st, res_ed;

	int left, right;
	int st, ed;
	int count;
	bool flag;

	for (int i=0;i<num;i++){
		if (judge(str[i])){
			left = right = i;
			count = 1;
			flag = true;
			while (true){
				left--;
				right++;
				while (left>=0 && !judge(str[left])) left--;
				while (right<num && !judge(str[right])) right++;


				if (left <0 || right >=num) break;		
				
				if (!equal(str[left], str[right])){
					break;
				}

				if (equal(str[left], str[right])){
					count+=2;
					st = left; ed = right;
				}
			}
			if (count>result){
				res_st = st;
				res_ed = ed;
				result = count;
			}

			int j = i+1;
			while (j<num && !judge(str[j])) j++;
			
			if (j<num && judge(str[j]) && equal(str[i],str[j])){
				left = i;
				right = j;
				count = 2;
				flag = true;
				while (true){
					left--;
					right++;
					while (left>=0 && !judge(str[left])) left--;
					while (right<num && !judge(str[right])) right++;
	
	
					if (left <0 || right >=num) break;		
					
					if (!equal(str[left], str[right])){
						break;
					}
	
					if (equal(str[left], str[right])){
						count+=2;
						st = left;
						ed = right;
					}
				}
				if (count>result){
					res_st = st;
					res_ed = ed;
					result = count;
				}	
			}
			
		}
	
	}	
	
		
	fout << result << endl;
	while (res_st<=res_ed){
		fout << str[ res_st ];
		res_st++;
	}
	fout << endl;
	return 0;

}

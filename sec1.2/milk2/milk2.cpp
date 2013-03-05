/*
ID: eric.al1
PROG: milk2
LANG: C++
*/

#include <fstream>
#include <iostream>
using namespace std;

struct Task{
	int start, end;
};

void quicksort(Task tsk[], int st, int ed){
	if (st >= ed) return;

	Task x = tsk[st],tmp;
	int pos = st;
	bool mark;
	for (int i=st+1; i<=ed; i+=1){
		mark = false;
		if (tsk[i].start <= x.start){
			if (tsk[i].start == x.start){
				if (tsk[i].end < x.end){
					mark = true;
				}
			}else{
				mark = true;
			}	
		
			if (mark){
				pos++;
				if (pos != i){
					tmp = tsk[pos];
					tsk[pos] = tsk[i];
					tsk[i] = tmp;
				}
			}
		}
	}

	if (pos != st){
		tmp = tsk[pos];
		tsk[pos] = tsk[st];
		tsk[st] = tmp;
	}

	quicksort(tsk, st, pos-1);
	quicksort(tsk, pos+1, ed);
}
int main(){
	ifstream fin("milk2.in");
	ofstream fout("milk2.out");

	int n;
	Task task[5000];

	fin >> n;
	for (int i=0;i<n;i++){
		fin >> task[i].start >> task[i].end;
	}
	
	quicksort(task, 0, n-1);
	int last_work = task[0].end - task[0].start;
	int last_idle = 0;

	int result_work = last_work, result_idle = last_idle;
	int last_end_work = task[0].end;

	for (int i=1;i<n;i++){
		if (task[i].start <= last_end_work){
			if (task[i].end >= last_end_work){
				last_work += task[i].end - last_end_work;
				last_end_work = task[i].end;
				result_work = (last_work > result_work)? last_work:result_work;
			}
			
		}else{
			last_work = task[i].end - task[i].start;
			last_idle = task[i].start - last_end_work;
			last_end_work = task[i].end;
			result_work = (last_work > result_work)? last_work:result_work;
			result_idle = (last_idle > result_idle)?last_idle:result_idle;
		}
	}

	fout << result_work << ' ' << result_idle << endl;
/*	cout << result_work << ' ' << result_idle << endl << endl;
	for (int i=0;i<n;i++){
		cout << task[i].start << ' '<< task[i].end << endl;
	}
*/
	return 0;
}

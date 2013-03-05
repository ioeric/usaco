/*
ID: eric.al1
PROG: milk2
LANG: C++
*/

/*Description:
 * 	Frist sort all tasks such that tasks are in increment order
 *
 * 	A task is in front of another one if 
 * 		1. It starts later than another one
 * 		2. It starts at the same time but finishes later than another one
 *
 *	After sorting, do counting:
 *		For one task, if it start 
 *		1. Earlier than the ending of last task, 
 *			1> If it ends earlier than the ending of last task, ignore this task
 *			
 *			2> If it ends later than the ending of last task, current continuous working(last_work) time 
 *			   increments by the difference between this task's ending time and last task's ending time   
 *			   If current continuous woring time is greater than max idle time recored,\
 *			   refresh max working time
 *
 *		2. Later than then end of last task
 *			Record idle time which is current task's beginning time minus last task's ending time
 *			Record new continuous working time
 *			If current continuous idle time is greater than max idle time recorded, refresh max idle time
 *			If current continuous woring time is greater than max idle time recored, refresh max working time
 *
 *
 */
#include <fstream>
#include <iostream>
using namespace std;

// Using to store every working time start and end
struct Task{
	int start, end;
};

// Sort every task 
// Increment order
// Smaller is start time earlier or start time the same and end time earlier
void quicksort(Task tsk[], int st, int ed){
	if (st >= ed) return;

	Task x = tsk[st],tmp;
	int pos = st;
	bool mark;
	for (int i=st+1; i<=ed; i+=1){
		// Mark whether swap or not
		mark = false;
		
		// If tsk.start <= x.start then handle, else continue
		if (tsk[i].start <= x.start){
			//  If start time is equal, compare end time
			if (tsk[i].start == x.start){
				if (tsk[i].end < x.end){
					mark = true;
				}
			// If start time is not equal, mark swap
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
	
	// First sort the tasks!!!
	quicksort(task, 0, n-1);
	
	// last work: the last continuous working time up to now
	int last_work = task[0].end - task[0].start;
	// last_idle: the last continuous idle time up to now
	int last_idle = 0;

	// result_work, result_idle record the max working time and idle time
	int result_work = last_work, result_idle = last_idle;

	// The last end task's end time
	int last_end_work = task[0].end;

	// Check every task
	for (int i=1;i<n;i++){
		// Current task starts earlier than last task
		if (task[i].start <= last_end_work){
			if (task[i].end >= last_end_work){
				// Increment continuous working time
				last_work += task[i].end - last_end_work;

				// Refresh last task's end time to current task's
				last_end_work = task[i].end;

				// Check if result need refresh
				result_work = (last_work > result_work)? last_work:result_work;
			}
			
		}else{ // Current task starts later than last task
			// New contiuous working time, the total time of current task
			last_work = task[i].end - task[i].start;
			
			// New idle time, the period between last work's end time and start of current task
			last_idle = task[i].start - last_end_work;
			
			// New last work ending time
			last_end_work = task[i].end;
			
			// Check if result need refreshing
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

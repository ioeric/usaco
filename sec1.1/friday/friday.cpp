/*
ID: eric.al1
PROG: friday
LANG: C++
*/

#include <fstream>
#include <iostream>
using namespace std;

// table: Record usual number of days in each month
const short table[13] = {0,31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

// Check if this year is leap or not
inline bool isLeap(const int year){
	if (year%400 == 0 || year % 4 ==0 && year % 100 !=0)
		return true;
	return false;
}

// Count 13th in every month of this month
void count_this_year(int res[], bool leap, int & today){
	// Start from January (1)
	int month = 1;
	// num_month_days: Number of days in this month
	int num_month_days;
	
	while (month <= 12){
		// Add last 13th to result array
		res[today] += 1;
		// Check table to get number of days this month
		num_month_days = table[ month ];
		// If this month is special, say February of a leap year
		if (month == 2 && leap)
			num_month_days += 1;
		// Go to next 13th
		today = (today + num_month_days) % 7;
		// Go to next month
		month += 1;
	}
}

int main(){
	ifstream fin("friday.in");
	ofstream fout("friday.out");

	int n;// N years to count
	fin >> n;
	
	const int start_year = 1900;
	int year = 0; // Number of years counted
	bool leap; // A flag: whther this year is leap year or not
	int res[7] = {}; // Init as all zero
	int today = 6; // today: record which day in a week is last 13th
		//Jan 13th, 1900 is SATURDAY (6)
	while (true){
		if (year >= n) break;	// Break loop when n years counted
		leap = isLeap(start_year + year); // Check this year whether is leep or not
		count_this_year(res, leap, today); // Count for this year
		year += 1; // Count next year
	}
	
	// Print result
	for (int i=0;i<7;i++){
		fout << res[ (6+i) % 7 ]; // Start from Saturday
		if (i != 6) 
			fout << ' ';
		else
			fout << endl;
	}

	return 0;
}

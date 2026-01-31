#pragma warning(disable : 4996)
#include <ctime>
#include <iostream>
using namespace std;
int main()
{
	time_t t = time(0); // get time now
	char* dt = ctime(&t); // convert in string form
	cout << "Local date and time is: " << dt << "\n";
	// converting now to tm struct for UTC date/time
	tm* gmtm = gmtime(&t);
	dt = asctime(gmtm);
	cout << "UTC date and time is: " << dt;
	cout << "Year " << gmtm->tm_year + 1900 << endl;
	cout << "Month: " << gmtm->tm_mon + 1 << endl;
	cout << "Day: " << gmtm->tm_mday << endl;
	cout << "Hour: " << gmtm->tm_hour << endl;
	cout << "Min: " << gmtm->tm_min << endl;
	cout << "Second: " << gmtm->tm_sec << endl;
	cout << "Week Day (Days since sunday): " << gmtm->tm_wday << endl;
	cout << "Year Day (Days since Jan 1st): " << gmtm->tm_yday << endl;
	cout << "hours of daylight savings:" << gmtm->tm_isdst << endl;
}
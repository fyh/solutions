/*
ID : yajunw
LANG : C++
PROG : friday
*/

# include <stdio.h>

int days[] = {31,28,31,30,31,30,31,31,30,31,30,31};

bool IsLeapYear(int year)
{
    return (year%4==0 && year%100!=0) || (year%400==0);
}

int GetDaysOfMonth(int year, int month)
{
	return ( month == 1 && IsLeapYear(year) ) ? days[month]+1:days[month];
}

int DaysOfYear(int year)
{
	return IsLeapYear(year) ? 366:365;
}

int GetWeekIdx(int year, int month, int day)
{
	int cntDays = 0;
	for (int y = 1900; y < year; ++y) cntDays += DaysOfYear(y);
	for (int m = 0; m < month; ++m) cntDays += GetDaysOfMonth(year, m);
	cntDays += day;
	return cntDays%7;
}

int main()
{
	FILE * fin = fopen("friday.in", "r");
	FILE * fout = fopen("friday.out", "w");

	int n;
	fscanf(fin, "%d", &n);
	fclose(fin);

	int ans[7];
	for (int i = 0; i < 7; ++i) ans[i] = 0;
	for (int year = 1900; year <= 1900+n-1; ++year) {
		for (int month = 0; month < 12; ++month) {
			++ans[ GetWeekIdx(year, month, 13) ];
		}
	}
	fprintf(fout, "%d", ans[6]);
	for (int i = 0; i < 6; ++i) {
		fprintf(fout, " %d", ans[(i+7)%7]);
	}
	fprintf(fout, "\n");

	fclose(fout);

	return 0;
}

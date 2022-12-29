#ifndef _DATE_H
#define _DATE_H

#include <ctime>

class Date
{
private:
	int day;
	int month;
	int year;
	int hour;
	int minutes;

public:
	 //getters:
	int getDay()     const;
	int getMonth()   const;
	int getYear()    const;
	int getHour()    const;
	int getMinutes() const;

	//setters:
	bool setDay(int day);
	bool setMonth(int month);
	bool setYear(int year);
	bool setHour(int hour);
	bool setMinutes(int minutes);


};

#endif


#include "Date.h"
//This function return day
//Get: none
//Return: int - day
int Date::getDay() const
{
	return this->day;
}

//This function return month
//Get: none
//Return: int - month
int Date::getMonth() const
{
	return this->month;
}

//This function return year
//Get: none
//Return: int - year
int Date::getYear() const
{
	return this->year;
}

//This function return hour
//Get: none
//Return: int - hour
int Date::getHour() const
{
	return this->hour;
}

int Date::getMinutes() const
{
	return this->minutes;
}

bool Date::setDay(int day)
{
	if (day < 1 || day >31)
		return false;
	this->day = day;
	return true;
}

bool Date::setMonth(int month)
{
	if (month < 1 || month >12)
		return false;
	this->month = month;
	return true;
}

bool Date::setYear(int year)
{
	this->year = year;
	return true;
}

bool Date::setHour(int hour)
{
	if (hour < 0 || hour > 23)
		return false;
	this->hour = hour;
	return true;
}

bool Date::setMinutes(int minutes)
{
	if (minutes < 0 || minutes > 59)
		return false;
	this->minutes = minutes;
	return true;
}
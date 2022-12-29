#include "Status.h"
#include "Status.h"
#pragma warning(disable: 4996)
using namespace std;

//This function is the class c'tor
Status::Status(const char* text)
{
	const time_t now = time(0);
	tm* ltm = localtime(&now);

	this->text = strdup(text);

	date.setYear(1900 + ltm->tm_year);
	date.setMonth(1 + ltm->tm_mon);
	date.setDay(ltm->tm_mday);
	date.setHour(ltm->tm_hour);
	date.setMinutes(ltm->tm_min);
}

//This function is sowing the status c'tor
void Status::show() const
{
	{
		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

		cout << this->text << endl;
		SetConsoleTextAttribute(h, 11);//color text in blue
		if (this->date.getDay() < 10)
			cout << "0" << this->date.getDay();
		else
			cout << this->date.getDay();

		cout << '.';
		if (this->date.getDay() < 10)
			cout << "0" << this->date.getDay();
		else
			cout << this->date.getDay();

		cout<< "." << this->date.getYear() << endl;
		cout << this->date.getHour() << ":";

		if (this->date.getMinutes() < 10)
			cout << "0" << this->date.getMinutes();
		else
			cout << this->date.getMinutes();
		
		cout<< endl;
		SetConsoleTextAttribute(h, 7);//return to default color

	}

}

//This function is the class d'tor
Status::~Status()
{
	delete[]text;
}
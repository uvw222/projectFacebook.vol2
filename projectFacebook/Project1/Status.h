#ifndef _STATUS_H
#define _STATUS_H

#include <ctime>
#include <iostream>
#include <string.h>
#include "Date.h"
#include <windows.h>


class Status
{
private:
	char* text;//not const because it will change
	Date date;

public:
	Status(const char* text); //This function is the class c'tor
	void show() const;		  //This function is sowing the status c'tor
	~Status();				  //This function is the class d'tor

};

#endif
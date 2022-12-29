
#ifndef _STATUS_ARR_H
#define _STATUS_ARR_H
#include "Status.h"

class StatusArr
{
private:
	Status** stArr;
	int logSize, phySize;
	void statusArrRealloc(int currSize, int newSize);
public:
	StatusArr();								//This function is the class c'tor
	~StatusArr();								//This function is the class d'tor

	int getSize()						const; //This function is returning the stArr size
	void addStatus(const char* text);		   //This function is adding a status to the stArr 
	Status* getStatusByIndex(int index) const; //This function is returning a status in the stArr by it index
};
#endif

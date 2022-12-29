#include "StatusArr.h"
#include <iostream>
#include <string.h>
#pragma warning(disable: 4996)

//This function is the class c'tor
StatusArr::StatusArr()
{
	this->stArr = nullptr;
	this->logSize = this->phySize = 0;
}

//This function is returning the stArr size
int StatusArr::getSize() const
{
	return this->logSize;
}

//This function is adding a status to the stArr
void StatusArr::addStatus(const char* text)
{
	Status* newStatus = new Status(text);
	if (this->logSize == this->phySize)
	{
		this->phySize *= 2;
		this->statusArrRealloc(this->logSize, this->phySize);
	}
	this->stArr[this->logSize] = newStatus;
	this->logSize++;
}

void StatusArr::statusArrRealloc(int currSize, int newSize)
{
	Status** newStArr = new Status * [newSize];
	for (int i = 0; i < currSize; i++)
		newStArr[i] = this->stArr[i];
	delete[] this->stArr;
	this->stArr = newStArr;
}

//This function is returning a status in the stArr by it index
Status* StatusArr::getStatusByIndex(int index) const
{
	return this->stArr[index];
}

//This function is the class d'tor
StatusArr::~StatusArr()
{
	for (int i = 0; i < this->logSize; i++)
		delete[] this->stArr[i];
	delete[] this->stArr;
}
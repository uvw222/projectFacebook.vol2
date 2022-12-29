#include "FanPageArr.h"
#include "FanPage.h"
#include <iostream>
#include <string.h>
#pragma warning(disable: 4996)

//This function is the class c'tor
FanPageArr::FanPageArr()
{
	this->fanPageArr = nullptr;
	this->logSize = this->phySize = 0;
}

//This function is returning the fanPageArr size
int FanPageArr::getSize() const
{
	return this->logSize;
}

//This function is adding a panPage to the fanPageArr 
void FanPageArr::addFanPage(FanPage* fanPage)
{
	if (fanPage != nullptr)
	{
		if (this->logSize == this->phySize)
		{
			if (this->phySize == 0)
				this->phySize++;

			this->phySize *= 2;
			this->fanPageArrRealloc(this->logSize, this->phySize);
		}
		this->fanPageArr[this->logSize] = fanPage;
		this->logSize++;
	}
}

void FanPageArr::fanPageArrRealloc(int currSize, int newSize)
{
	FanPage** newStArr = new FanPage * [newSize];
	for (int i = 0; i < currSize; i++)
		newStArr[i] = this->fanPageArr[i];
	delete[] this->fanPageArr;
	this->fanPageArr = newStArr;
}

//This function is removing a panPage to the fanPageArr 
void FanPageArr::removeFanPage(FanPage* fanPage)
{
	int fanPageIndex = findFanPageByNameAndReturnIndex(fanPage->getName());
	if (fanPageIndex != NOT_FOUND)
	{
		swap(fanPageIndex, this->logSize - 1);
		this->fanPageArr[this->logSize - 1] = nullptr;
		this->logSize--;
	}
}

//This function is finding a panPage in the fanPageArr by is name and returning is index
int FanPageArr::findFanPageByNameAndReturnIndex(const char* fanPageName) const
{
	for (int i = 0; i < this->logSize; i++)
		if (stricmp(this->fanPageArr[i]->getName(), fanPageName) == 0)
			return i;
	return NOT_FOUND;
}

//This function is returning a panPage in the fanPageArr by it index
FanPage* FanPageArr::getFanPageByIndex(int index) const
{
	if (index != NOT_FOUND)
		return this->fanPageArr[index];
	return nullptr;
}

void FanPageArr::swap(int index1, int index2)
{
	FanPage* tmp = this->fanPageArr[index1];
	this->fanPageArr[index1] = this->fanPageArr[index2];
	this->fanPageArr[index2] = tmp;
}


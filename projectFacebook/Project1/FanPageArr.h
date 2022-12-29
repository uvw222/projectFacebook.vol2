#ifndef _FAN_PAGE_ARR_H
#define _FAN_PAGE_ARR_H
class FanPage;
#pragma warning(disable: 4430)

class FanPageArr
{
private:
	FanPage** fanPageArr;
	int logSize, phySize;
	void fanPageArrRealloc(int currSize, int newSize);
	void swap(int index1, int index2); 

public:
	FanPageArr();													//This function is the class c'tor
	~FanPageArr() {this->fanPageArr = nullptr; }					//This function is the class d'tor

	int getSize()											  const; //This function is returning the fanPageArr size
	void addFanPage(FanPage* fanPage);								 //This function is adding a panPage to the fanPageArr 
	void removeFanPage(FanPage* fanPage);							 //This function is removing a panPage to the fanPageArr 
	int findFanPageByNameAndReturnIndex(const char* fanPage)  const; //This function is finding a panPage in the fanPageArr by is name and returning is index
	FanPage* getFanPageByIndex(int index)                     const; //This function is returning a panPage in the fanPageArr by it index



};
#endif
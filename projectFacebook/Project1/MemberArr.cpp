#include "MemberArr.h"
#include "Member.h"
#include <iostream>
#include <string.h>

#pragma warning(disable: 4996)

//This function is the class c'tor
MemberArr::MemberArr()
{
	this->memberArr = nullptr;
	this->logSize = this->phySize = 0;
}

//This function is returning the memberArr size
int MemberArr::getSize() const
{
	return this->logSize;
}

//This function is adding a member to the memberArr
void MemberArr::addMember(Member* member)
{
	//if (member != nullptr)
	//{
	if (this->logSize == this->phySize)
	{
		if (this->phySize == 0)
			this->phySize++;

       this->phySize *= 2;
	   this->memberArrRealloc(this->logSize, this->phySize);

		}
		this->memberArr[this->logSize] = member;
		this->logSize++;
	//}
}

void MemberArr::memberArrRealloc(int currSize, int newSize)
{
	Member** newStArr = new Member * [newSize];
	for (int i = 0; i < currSize; i++)
		newStArr[i] = this->memberArr[i];
	delete[] this->memberArr;
	this->memberArr = newStArr;
}

//This function is removing a member to the memberArr
void MemberArr::removeMember(Member* member)
{
	int memberIndex = findMemberByNameAndReturnIndex(member->getName());
	if (memberIndex != NOT_FOUND)
	{
		swap(memberIndex, this->logSize - 1);
		this->memberArr[this->logSize - 1] = nullptr;
		this->logSize--;
	}
}

//This function is finding a member in the memberArr by is name and returning is index
int MemberArr::findMemberByNameAndReturnIndex(const char* memberName) const
{
	for (int i = 0; i < this->logSize; i++)
		if (stricmp(this->memberArr[i]->getName(), memberName) == 0)   //compare strings with insesitivity for upper/lower case
			return i;
	return NOT_FOUND;
}

//This function is returning a member in the memberArr by it index
Member* MemberArr::getMemberByIndex(int index) const
{
	if (index != NOT_FOUND)
		return this->memberArr[index];
	return nullptr;
}

void MemberArr::swap(int index1, int index2)
{
	Member* tmp = this->memberArr[index1];
	this->memberArr[index1] = this->memberArr[index2];
	this->memberArr[index2] = tmp;
}

//This function is the class d'tor
MemberArr::~MemberArr()
{
	delete[] this->memberArr;
}
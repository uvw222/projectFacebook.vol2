#ifndef _MEMBER_ARR_H
#define _MEMBER_ARR_H
class Member;
#pragma warning(disable: 4430)
#define NOT_FOUND -1
class MemberArr
{
private:
	Member** memberArr;
	int logSize, phySize;
	void memberArrRealloc(int currSize, int newSize);
	void swap(int index1, int index2);


public:
	MemberArr();													//This function is the class c'tor
	~MemberArr();													//This function is the class d'tor

	int getSize()											 const; //This function is returning the memberArr size
	void addMember(Member* member);									//This function is adding a member to the memberArr 
	void removeMember(Member* member);								//This function is removing a member to the memberArr
	int findMemberByNameAndReturnIndex(const char* member)   const; //This function is finding a member in the memberArr by is name and returning is index
	Member* getMemberByIndex(int index)                      const; //This function is returning a member in the memberArr by it index


};
#endif
#ifndef _MEMBER_H
#define _MEMBER_H

#define TEN_STATUSES 10
#include <iostream>
#include <string.h>
#include "StatusArr.h"
#include "MemberArr.h"
#include "FanPageArr.h"
#include "Date.h"
#include <windows.h>
#pragma warning(disable: 4430)


class Member
{
private:
	char* name;
	Date birthDate;
	StatusArr myStatus;
	MemberArr myFriends;
	FanPageArr myFanPageFollowing;

public:
	Member( const char* name, Date& birthDate);//This is the c'tor of member - it set member properties
	~Member();//This is the d'tor of member 
	Member(Member&& other);//This function is the class move c'tor
	Member(const Member& member);//This function is the class copy c'tor


	//getters:
	const char* getName()			    const;//This function return member name
	Date getBirthDate()					const;//This function return member birthdate

	//setters:
	void setName(char Name[]) { name = _strdup(Name); }
	void setBirthDay(Date birthday) { birthDate = birthday; }

	//shows
	void showAllMyStatuses()            const; //This function is showing all member status
	void showAllMy10Statuses()          const;//This function is showing all member 10 latest status
	void showMyFriends10Status()		const;//This function is showing all member friends 10 status
	void showMyFriends()				const;//This function is showing all member friends
	void show()							const; // This function is showing all member featurs
	void showMyFanPageFollowing()       const;
	bool isMemberHaveSubscribe() { return(this->myFanPageFollowing.getSize() != 0); }

	//adding functions
	bool addFriend(Member* other);//This function is adding a friend to member myFriends - arr
	bool addFollowToFanPage(FanPage* fanPage);//This function is adding a fanPage to member
	void addStatus(const char* text);		  //This function is adding a statues to member myStatus - arr
	
	//removing functions
	bool removeFriend(Member* other);//This function disconect members
	bool removeFollowFromFanPage(FanPage* fanPage);//This function remove follow to fanPage

};

#endif

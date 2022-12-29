#ifndef _FACEBOOK_H
#define _FACEBOOK_H
#define MAX_NAME_LEN 100
#define MAX_STATUS_LEN 500

#include "MemberArr.h"
#include "Member.h"
#include "Date.h"
#include "FanPageArr.h"
#include "FanPage.h"
#include <windows.h>
#pragma warning(disable : 4715)

class FaceBook
{
private:
	MemberArr members;
	FanPageArr fanPages;
	void printSuccess();//function prints a success announcment
	void printUnsuccess() const; //function prints a unsuccess announcment
	bool isShowMembersList();//This function showing facebook members listgiven the user's choice
	bool isShowFanPagesList();//This function showing facebook fan pages listgiven the user's choice
	void clearBuffer();

public:

	//addings functions
	bool addNewMember(Member* newMember);//This function adding a new member to facebook
	bool addNewFanPage(FanPage* newFanPage);///This function adding a new fan page to facebook
	void addNewStatusForMember(char* userName);//function add new status for member
	void addNewStatusForFanPage(char* userName);//function add new status for fan page

	//shows functions
	void showAllMembers() const;//function shows all members existing at facebook
	void showAllFanPages() const;//function shows all fan pages existing at facebook
	void showAllUsersFriends();//function shows all frineds of a member
	void showAllFanPageFollowers();//function shows all followers of a fan page
	void showAllUsers10StatusesOfFriends(char* userName);//function shows all 10 status of a member frineds
	void viewMemberStatusList(char userName[]);//function views a selceted member ststus list
	void viewFanPageStatusList(char userName[]);//function views a selceted fan page ststus list

	//validation functions
	int userNameValidation(char* name);//function checks if the member exists and returns its index at the members array
	int fanPageNameValidation(char* name);// function checks if the fan pages exists and returns its index at the fan pages array


	//connect users functions
	void connectMembers();//This function connect between members
	void connectMemberToFanPage();//This function connect between member and fanPage
	
	//disconnect users functions
	void disconnectMemberToFanPage();//This function disconnect between member and fanPage
	void disconnectMembers();//This function disconnect between members

	
	


};
#endif

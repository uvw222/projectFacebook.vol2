#pragma once
#pragma warning(disable : 4996)
#pragma warning(disable : 4700)
#pragma warning(disable : 4715)

#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include "Date.h"
#include "FaceBook.h"
#include "FanPage.h"
#include "Member.h"
#include "MemberArr.h"
#include "Status.h"
#include "StatusArr.h"
#include <string>
#include <deque>
#include <ctype.h>
#define NOT_FOUND -1
#define MAX_NAME_LEN 100
#define MAX_DATE_LEN 15



void getChoice(int userChoice, FaceBook& facebook);//This function is manages the user's action choice
void registerAsNewMember(FaceBook& facebook);//This function manage the registerion of a new member
void createNewFanPage(FaceBook& facebook);//This function manage the creation of a new fan page
void addMemberStatus(FaceBook& facebook);//This function adding new status to a member that it get from the user
void addFanPageStatus(FaceBook& facebook);//This function adding new status to a fan page that it get from the user
void viewMemberStatuses(FaceBook& facebook);//This function showing the status of a member that it get from the user
void viewFanPageStatuses(FaceBook& facebook);//This function showing the status of a fan page that it get from the user
void showMembersFriends10LatestStatuses(FaceBook& facebook); //This function showing the 10 status of each friend of a member that it gat from the user
void defaultUsers(FaceBook&facebook, Member& mem1,Member&mem2, Member&mem3);//This function is adding a default users to facebook
void defaultFanPages(FaceBook& facebook, FanPage& fp1, FanPage& fp2, FanPage& fp3);//This function is adding a default fan pages to facebook
Member creatMember(const char* name, int day, int month, int year);//This function is creating a Member
FanPage createFanPage(const char* name);//This function is creating a FanPage
void clearBuffer();//This function is clearing the buffer for cin.getline

//bools:
bool isShowMembersList(FaceBook& facebook);//This function is schecking if the user would like to see the members list of facebook
bool isShowFanPagesList(FaceBook& facebook);//This function is schecking if the user would like to see the fan pages list of facebook
bool checkValid(int userChoice);//This function is checking the user's action choice is valid
bool setBirthDate(Date& date);//This function is seting a birthday Date and returning if its valid

//prints:
void printInvalid();//This function is printing an annoucment that the user request is'nt valid
void printWelcome();//This function is printing the welcome annoucment
int getAndPrintMenu();//This function is printing the facebook menu and returning (by ref parameter)
// the user's action choice

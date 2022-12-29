#include "FaceBook.h"

using namespace std;


//This function adding a new member to facebook
bool FaceBook::addNewMember(Member* newMember)
{
	if (this->members.findMemberByNameAndReturnIndex(newMember->getName()) != NOT_FOUND)
		return false;
	this->members.addMember(newMember);
	return true;
}

//This function connect between members
void FaceBook::connectMembers()
{
	char member1[MAX_NAME_LEN];
	char member2[MAX_NAME_LEN];
	int member1Index, member2Index;
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

	if (isShowMembersList())//if the user wants to see the facebooks' users 
		showAllMembers();//it will present the list to him
	cout << "Select a member:" << '\n';
	clearBuffer();
	cin.getline(member1, MAX_NAME_LEN);//pick the user we want to connect to another member
	member1Index = userNameValidation(member1);
	cout << "Who do you want to connect to " << member1 << " ?" << '\n';//pick the second member to connect it to the first

	if (isShowMembersList())//if the user wants to see the facebooks' users 
		showAllMembers();//it will present the list to him
	clearBuffer();
	cin.getline(member2, MAX_NAME_LEN);
	member2Index = userNameValidation(member2);
	(this->members.getMemberByIndex(member1Index))->addFriend(this->members.getMemberByIndex(member2Index));//connect members
	
	SetConsoleTextAttribute(h, 13);//color text in grey
	cout << endl << "Congratulations!!" << member1 << " and " << member2 << " are now friends" << endl << endl;
	SetConsoleTextAttribute(h, 7);//return to default color

}

//This function showing facebook members listgiven the user's choice
bool FaceBook::isShowMembersList()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

	char choice;
	cout << "Would you like to see Facebooks' members?";
	SetConsoleTextAttribute(h, 8);//color text in grey
	cout << " (enter Y/N)" << '\n';
	SetConsoleTextAttribute(h, 7);//return to default color
	_flushall();
	cin>>choice;//get the choice

	while (choice != 'n' && choice != 'N' && choice != 'y' && choice != 'Y')//choice validation
	{
		SetConsoleTextAttribute(h, 12);//color text in red
		cout << "Your request is not valid. please try again." << '\n';
		SetConsoleTextAttribute(h, 7);//return to default color
		cout << "Would you like to see Facebooks' members?";
		SetConsoleTextAttribute(h, 8);//color text in grey
		cout << " (enter Y/N)" << '\n';
		SetConsoleTextAttribute(h, 7);//return to default color
		_flushall();
		cin>>choice;//get the choice
	}

	if (choice == 'y' || choice == 'Y')
		return true;

	else if (choice == 'n' || choice == 'N')
		return false;

}

//This function showing facebook fan pages listgiven the user's choice
bool FaceBook:: isShowFanPagesList()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

	char choice;
	cout << "Would you like to see Facebooks' fan pages?";
	SetConsoleTextAttribute(h, 8);//color text in grey
	cout << " (enter Y/N)" << '\n';
	SetConsoleTextAttribute(h, 7);//return to default color
	cin >> choice;//get the choice

	while (choice != 'n' && choice != 'N' && choice != 'y' && choice != 'Y')//choice validation
	{
		SetConsoleTextAttribute(h, 12);//color text in red
		cout << "Your request is not valid. please try again." << '\n';
		SetConsoleTextAttribute(h, 7);//return to default color
		cout << "Would you like to see Facebooks' fan pages?";
		SetConsoleTextAttribute(h, 8);//color text in grey
		cout << " (enter Y/N)" << '\n';
		SetConsoleTextAttribute(h, 7);//return to default color
		_flushall();
		cin >> choice;
	}

	if (choice == 'y' || choice == 'Y')
		return true;

	else if (choice == 'n' || choice == 'N')
		return false;
}

//This function disconnect between members
void FaceBook::disconnectMembers( )
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);//for color printings

	char member1[MAX_NAME_LEN]=" ";
	char member2[MAX_NAME_LEN]=" ";
	int member1Index, member2Index;

	if (isShowMembersList())//if the user wants to see the facebooks' users 
		showAllMembers();//it will present the list to him
	cout << "Select a member you wish to delete one of their friend:" << '\n';
	clearBuffer();
	cin.getline(member1, MAX_NAME_LEN);//pick the user we want to remove one of their friends
	member1Index = userNameValidation(member1);

	cout << "Select a friend you wish to delete from the friends list " << member1 << '\n';//pick the second member to delete it from the first
	
	(members.getMemberByIndex(member1Index))->showMyFriends();//presents current friends list
	//clearBuffer();
	cin.getline(member2, MAX_NAME_LEN);//pick the user we want to remove one of their friends
	member2Index = userNameValidation(member2);
	this->members.getMemberByIndex(member1Index)->removeFriend(this->members.getMemberByIndex(member2Index));//delete friend from friends list
	
	SetConsoleTextAttribute(h, 13);//color text in grey
	cout << endl << "ohh.. sorry to see that " << member1 << " and " << member2 << " could not get along" << endl << endl;
	SetConsoleTextAttribute(h, 7);//return to default color
}

//This function adding a new fan page to facebook
bool FaceBook::addNewFanPage(FanPage* newFanPage)
{
	if (this->fanPages.findFanPageByNameAndReturnIndex(newFanPage->getName()) != NOT_FOUND)
		return false;
	this->fanPages.addFanPage(newFanPage);
	return true;
}

//This function connect between member and fanPage
void FaceBook::connectMemberToFanPage()
{
	char member[MAX_NAME_LEN];
	char fanPage[MAX_NAME_LEN];
	int memberIndex, fanPageIndex;

	cout << "Select a facebook member and type it:" << endl;
	if (isShowMembersList())//if the user wants to see the facebooks' users 
		showAllMembers();//it will present the list to him

	clearBuffer();
	cin.getline(member, MAX_NAME_LEN);//pick the user we want to remove one of their friends
	memberIndex = userNameValidation(member);


	cout << "Select a fan Page you wish to follow and type it:" << endl;
	if (isShowFanPagesList())//if the user wants to see the facebooks' users 
		showAllFanPages();//it will present the list to him

	clearBuffer();
	cin.getline(fanPage, MAX_NAME_LEN);//pick the user we want to remove one of their friends
	fanPageIndex = fanPageNameValidation(fanPage);

	//adding the member to follow the fan page
	this->members.getMemberByIndex(memberIndex)->addFollowToFanPage(this->fanPages.getFanPageByIndex(fanPageIndex));
	printSuccess();
}

//This function disconnect between member and fanPage
void FaceBook::disconnectMemberToFanPage()
{
	char member[MAX_NAME_LEN];
	char fanPage[MAX_NAME_LEN];
	int memberIndex, fanPageIndex;

	cout << "Select a facebook member and type it:" << endl;
	if (isShowMembersList())//if the user wants to see the facebooks' users 
		showAllMembers();//it will present the list to him

	clearBuffer();
	cin.getline(member, MAX_NAME_LEN);//pick the user we want to remove one of their friends
	memberIndex = userNameValidation(member);


	cout << "Select a fan Page from the member fan page subscribe that you wish to unfollow and type it:" << endl;
	this->members.getMemberByIndex(memberIndex)->showMyFanPageFollowing();
	if (this->members.getMemberByIndex(memberIndex)->isMemberHaveSubscribe())
	{
		cin.getline(fanPage, MAX_NAME_LEN);//pick the user we want to remove one of their friends
		fanPageIndex = fanPageNameValidation(fanPage);

		//removing the member from the following lidt of the fan page
		if (this->members.getMemberByIndex(memberIndex)->removeFollowFromFanPage(this->fanPages.getFanPageByIndex(fanPageIndex)))
			printSuccess();
		else
			printUnsuccess();
	}
}

//function checks if the member exists and returns its index at the members array
int FaceBook::userNameValidation(char* name)//checks if the name exist at the members array
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);//for color printings
	int memberIndex = this->members.findMemberByNameAndReturnIndex(name);//get the member index in the array of members
	while (memberIndex == NOT_FOUND)//check if the user given is not valid - request a another try
	{
		SetConsoleTextAttribute(h, 12);//color text in red
		cout << "Oops... There is no such user named " << name << " Please try again." << endl;
		SetConsoleTextAttribute(h, 7);//return to default color
		cout << "Choose which user you want and please write their full name as shown:" << endl;
		cin.getline(name, MAX_NAME_LEN);
		memberIndex = this->members.findMemberByNameAndReturnIndex(name);
	}
	return memberIndex;
}

// function checks if the fan pages exists and returns its index at the fan pages array
int FaceBook::fanPageNameValidation(char* name)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);//for color printings
	int fanPageIndex = this->fanPages.findFanPageByNameAndReturnIndex(name);//get the member index in the array of members
	while (fanPageIndex == NOT_FOUND)//check if the user given is not valid - request a another try
	{
		SetConsoleTextAttribute(h, 12);//color text in red
		cout << "Oops... There is no such fan page named " << name << " Please try again." << endl;
		SetConsoleTextAttribute(h, 7);//return to default color
		cout << "Choose which fan page you want and write their full name as shown:" << endl;
		cin.getline(name, MAX_NAME_LEN);
		fanPageIndex = this->fanPages.findFanPageByNameAndReturnIndex(name);//get the member index in the array of members
	}
	return fanPageIndex;
}

//function add new status for member
void FaceBook::addNewStatusForMember(char* userName)//not const because it might change during validation
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);//for color printings
	int memberIndex = userNameValidation(userName);
	char statusText[MAX_STATUS_LEN] = " ";
	cout << endl << "Hello ";
	SetConsoleTextAttribute(h, 9);//color text in grey
	cout << userName;
	SetConsoleTextAttribute(h, 7);//return to default color
	cout<< "!" << endl<<endl<< "What would you like to share today?...";
	SetConsoleTextAttribute(h, 8);//color text in grey
	cout << "status is up to 500 characters" << endl<<endl;
	SetConsoleTextAttribute(h, 7);//return to default color
	cin.getline(statusText, MAX_STATUS_LEN);
	(this->members.getMemberByIndex(memberIndex))->addStatus(statusText);
	SetConsoleTextAttribute(h, 13);//color text in pink
	cout <<endl<< "your status has been successfully added!" << endl << endl;
	SetConsoleTextAttribute(h, 7);//return to default color
}

//function add new status for fan page
void FaceBook::addNewStatusForFanPage(char* userName)//YUVAL
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);//for color printings
	int fanPageIndex = fanPageNameValidation(userName);
	char statusText[MAX_STATUS_LEN] = " ";
	cout << endl << "Hello ";
	SetConsoleTextAttribute(h, 9);//color text in grey
	cout << userName;
	SetConsoleTextAttribute(h, 7);//return to default color
	cout << "!" << endl << endl << "What would you like to share today?...";
	SetConsoleTextAttribute(h, 8);//color text in grey
	cout << "status is up to 500 characters" << endl << endl;
	SetConsoleTextAttribute(h, 7);//return to default color
	cin.getline(statusText, MAX_STATUS_LEN);
	(this->fanPages.getFanPageByIndex(fanPageIndex))->addStatus(statusText);
	cout << "your status has been successfully added!" << endl << endl;
}


//function views a selceted member ststus list
void FaceBook::viewMemberStatusList(char userName[])//not const because it might change during validation
{
	int memberIndex = userNameValidation(userName);
	(this->members.getMemberByIndex(memberIndex))->showAllMyStatuses();
}

//function views a selceted fan page ststus list
void FaceBook::viewFanPageStatusList(char userName[])
{
	int fanPageIndex = fanPageNameValidation(userName);
	(this->fanPages.getFanPageByIndex(fanPageIndex))->showAllMyStatuses();
}

//function shows all members existing at facebook
void FaceBook::showAllMembers() const
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);//for color printings

	SetConsoleTextAttribute(h, 9);//color text in blue
	cout <<endl<< "----------------------------------------------" << endl;
	cout << "Our Facebook members:"<<endl;
	SetConsoleTextAttribute(h, 7);//return to default color
	unsigned int arrSize = this->members.getSize();
	for (unsigned int i = 0; i < arrSize; i++)
	{
		cout << "Member #" << i+1 << " name:" << (this->members.getMemberByIndex(i))->getName() << '\n';//get the members name as orderd in the array 
	}
	SetConsoleTextAttribute(h, 9);//color text in blue
	cout << "----------------------------------------------"<<endl<< endl;
	//cout << endl;
	SetConsoleTextAttribute(h, 7);//return to default color
}

//function shows all fan pages existing at facebook
void FaceBook::showAllFanPages() const
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);//for color printings

	SetConsoleTextAttribute(h, 9);//color text in blue
	cout << endl << "----------------------------------------------" << endl;
	cout << "Our Facebook fan pages:"<< endl;
	SetConsoleTextAttribute(h, 7);//return to default color
	for ( int i = 0; i < this->fanPages.getSize(); i++)
	{
		cout << "Member #" << i+1 << " name:" << (this->fanPages.getFanPageByIndex(i))->getName() << '\n';//get the fan pages' name as orderd in the array 
	}
	SetConsoleTextAttribute(h, 9);//color text in blue
	cout << "----------------------------------------------"<<endl << endl;
	SetConsoleTextAttribute(h, 7);//return to default color
}

//function shows all frineds of a member
void FaceBook::showAllUsersFriends()
{
	char chosenMember[MAX_NAME_LEN];
	if (isShowMembersList())//if the user wants to see the facebooks' users 
		showAllMembers();//it will present the list to him
	cout << "Select the user whom you would like to view their friends:" << '\n';
	clearBuffer();
	cin.getline(chosenMember, MAX_NAME_LEN);//pick the user we want to view their statuses
	int memberIndex = userNameValidation(chosenMember);
	(this->members.getMemberByIndex(memberIndex))->showMyFriends();
}

//function shows all followers of a fan page
void FaceBook::showAllFanPageFollowers()
{
	char chosenFanPage[MAX_NAME_LEN];
	if (isShowFanPagesList())//if the user wants to see the facebooks' users 
		showAllFanPages();//it will present the list to him
	cout << "Select the fan page which you would like to view their followers:" << '\n';
	clearBuffer();
	cin.getline(chosenFanPage, MAX_NAME_LEN);//pick the user we want to view their statuses
	int fanPageIndex = fanPageNameValidation(chosenFanPage);
	(this->fanPages.getFanPageByIndex(fanPageIndex))->showMyFollowers();
}

//function shows all 10 status of a member frineds
void FaceBook::showAllUsers10StatusesOfFriends(char* userName)
{
	int memberIndex = userNameValidation(userName);
	(this->members.getMemberByIndex(memberIndex))->showMyFriends10Status();
}

//function prints a success announcment
void FaceBook::printSuccess()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(h, 9);//color text in blue
	cout << endl << "Your request has submitted successfully!" << endl << endl;
	SetConsoleTextAttribute(h, 7);//return to default color
}

//function prints a unsuccess announcment
void FaceBook::printUnsuccess()  const
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, 12);//color text in red
	cout << endl << "Your request has failed" << endl << endl;
	SetConsoleTextAttribute(h, 7);//return to default color
}

void FaceBook::clearBuffer()
{
	cin.clear(); // clear input buffer to restore cin to a usable state
	cin.ignore(INT_MAX, '\n'); // ignore last input
}

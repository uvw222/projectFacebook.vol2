#include "Member.h"
#include "FanPage.h"
#pragma warning (disable: 4996)
using namespace std;



//This is the c'tor of member - it set member properties
Member::Member(const char* name, Date& birthDate)
{
	this->name = strdup(name);
	this->birthDate = birthDate;
}


//This function is the class move c'tor
Member::Member(Member&& other)
{
	name = other.name;
	other.name = nullptr;
	birthDate = other.birthDate;
	myFanPageFollowing = other.myFanPageFollowing;
	myFriends=other.myFriends;
	myStatus=other.myStatus;

}

//This function is the class copy c'tor
Member::Member(const Member& member)
{
	name = strdup(member.name);
	birthDate = member.birthDate;

}

//This function return member birthdate
Date Member::getBirthDate() const
{
	return this->birthDate;
}

//This function return member name
const char* Member::getName() const
{
	return this->name;
}

//This function connecting members
bool Member::addFriend(Member* other)
{
	if (other != nullptr)
	{
		if (other != this && this->myFriends.findMemberByNameAndReturnIndex(other->getName()) == NOT_FOUND)
		{
			this->myFriends.addMember(other);
			other->addFriend(this);
			return true;
		}
	}
	return false;
}

//This function adding status to member's status
//Get: string text, can be const or not
//Return: none
void Member::addStatus(const char* text)
{
	this->myStatus.addStatus(text);
}

//This function print member's status
void Member::showAllMyStatuses() const
{
	int size = this->myStatus.getSize();
	if (size == 0)
	{
		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(h, 12);//color text in red
		cout << endl << "Oops... this member has no status yet" << endl << endl;
		SetConsoleTextAttribute(h, 7);//return to default color
	}
	for (int i = 0; i < size; i++)//print out all the members statuses
		(this->myStatus.getStatusByIndex(i))->show();

}


//This function print member's friends 10 latest status
void Member::showMyFriends10Status() const
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

	int size = this->myFriends.getSize();
	if (size == 0)
	{
		SetConsoleTextAttribute(h, 12);//color text in red
		cout << endl << "Oops... this member has no friend yet" << endl << endl;
		SetConsoleTextAttribute(h, 7);//return to default color

	}
	for (int i = 0; i < size; i++)
	{
		SetConsoleTextAttribute(h, 11);//color text in cyan
		cout <<endl<< this->myFriends.getMemberByIndex(i)->getName() << endl;
		SetConsoleTextAttribute(h, 7);//return to default color
		(this->myFriends.getMemberByIndex(i))->showAllMy10Statuses();

	}
	
}

//This function print member's 10 latest status
void Member::showAllMy10Statuses()          const
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	int size = this->myStatus.getSize();
	if (size > TEN_STATUSES)
		for (int i = size - 1; i > size - TEN_STATUSES; i--)//print only 10 updated statuses
		{
			
			(this->myStatus.getStatusByIndex(i))->show();
			SetConsoleTextAttribute(h, 9);//color text in color
			cout << endl << "**************************************";
			SetConsoleTextAttribute(h, 7);//return to default color
			cout << endl ;
		}
			

	else
		for (int i = size - 1; i >= 0; i--)//print out all the members statuses
		{
			
			(this->myStatus.getStatusByIndex(i))->show();
			SetConsoleTextAttribute(h, 9);//color text in color
			cout << endl << "**************************************";
			SetConsoleTextAttribute(h, 7);//return to default color
			cout << endl << endl;
		}
			
}

//This function print member's frineds
void Member::showMyFriends() const
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

	int size = this->myFriends.getSize();
	if (size == 0)
	{
		SetConsoleTextAttribute(h, 12);//color text in red
		cout << "This member has no friends" << endl;
		SetConsoleTextAttribute(h, 7);//return to default color
	}


	for (int i = 0; i < size; i++)
	{
		cout << (this->myFriends.getMemberByIndex(i))->getName() << "\n";
		SetConsoleTextAttribute(h, 11);//color text in blue
		Date birthday = (this->myFriends.getMemberByIndex(i))->getBirthDate();
		cout << "My birthday :"<< birthday.getDay() << '/' << birthday.getMonth() << '/' << birthday.getYear() << endl;
		SetConsoleTextAttribute(h, 7);//return to default color

	}

}

//This function disconect members
bool Member::removeFriend(Member* other)
{
	if (other != nullptr)
	{
		if (other != this && this->myFriends.findMemberByNameAndReturnIndex(other->getName()) != NOT_FOUND)
		{
			this->myFriends.removeMember(other);
			other->removeFriend(this);
			return true;
		}
	}
	return false;
}

//This function add follow to fanPage
bool Member::addFollowToFanPage(FanPage* fanPage)
{

	if (fanPage != nullptr)
	{
		if (this->myFanPageFollowing.findFanPageByNameAndReturnIndex(fanPage->getName()) == NOT_FOUND)
		{
			this->myFanPageFollowing.addFanPage(fanPage);
			fanPage->addFollower(this);
			return true;
		}
	}
	return false;
}

//This function remove follow to fanPage
bool Member::removeFollowFromFanPage(FanPage* fanPage)
{
	if (fanPage != nullptr)
	{
		if (this->myFanPageFollowing.findFanPageByNameAndReturnIndex(fanPage->getName()) != NOT_FOUND)
		{
			this->myFanPageFollowing.removeFanPage(fanPage);
			fanPage->removeFollowers(this);
			return true;
		}
	}
	return false;

}


void Member:: showMyFanPageFollowing()       const
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

	int size = this->myFanPageFollowing.getSize();
	if (size == 0)
	{
		SetConsoleTextAttribute(h, 12);//color text in red
		cout << "This member have not subscribed any fan page yet" << endl<<endl;
		SetConsoleTextAttribute(h, 7);//return to default color
	}


	for (int i = 0; i < size; i++)
	    cout << (this->myFanPageFollowing.getFanPageByIndex(i))->getName() << endl;
		
}


//This function print member properties
void Member::show() const
{
	cout << "My name is: " << this->name << "\n"
		<< "My birthday is " << this->birthDate.getDay() << "." << this->birthDate.getMonth() << "." << this->birthDate.getYear() << endl;
}

//This is the d'tor of member 
Member::~Member()
{
	delete[]name;
}

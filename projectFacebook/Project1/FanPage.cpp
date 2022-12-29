#include "FanPage.h"
using namespace std;

FanPage::FanPage(const char* name)
{
	this->name = _strdup(name);
}

FanPage::FanPage(FanPage&& other)
{
	name = other.name;
	other.name = nullptr;
	myFollowers = other.myFollowers;
	myStatus = other.myStatus;
}

const char* FanPage::getName() const
{
	return this->name;
}

StatusArr FanPage::getMyStatus() const
{
	return this->myStatus;
}

void FanPage::addFollower(Member* other)
{
	if (other != nullptr)
	{
		if (this->myFollowers.findMemberByNameAndReturnIndex(other->getName()) == NOT_FOUND)
		{
			this->myFollowers.addMember(other);
			other->addFollowToFanPage(this);
		}
	}
}

void FanPage::addStatus(const char* text)
{
	this->myStatus.addStatus(text);
}

void FanPage::showMyStatus() const
{
	for (int i = 0; i < this->myStatus.getSize(); i++)
		this->myStatus.getStatusByIndex(i)->show();
}
//function print out all the fan page statuses
void FanPage::showAllMyStatuses()            const
{
	int size = this->myStatus.getSize();
	if (size == 0)
	{
		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(h, 12);//color text in red
		cout << endl << "Oops... this fan page has no status yet" << endl << endl;
		SetConsoleTextAttribute(h, 7);//return to default color
	}

	for (int i = 0; i < size; i++)//print out all the fan page statuses
		(this->myStatus.getStatusByIndex(i))->show();

}

void FanPage::showMyFollowers10Status() const
{
	int size = this->myFollowers.getSize();

	for (int i = 0; i <size ; i++)
		this->myFollowers.getMemberByIndex(i)->showAllMy10Statuses();
	
}


void FanPage::showMyFollowers() const
{

	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

	int size = this->myFollowers.getSize();
	if (size == 0)
	{
		SetConsoleTextAttribute(h, 12);//color text in red
		cout << "This fan page has no followers" << endl;
		SetConsoleTextAttribute(h, 7);//return to default color
	}


	for (int i = 0; i < size; i++)
	{
		cout << (this->myFollowers.getMemberByIndex(i))->getName() << "\n";
		SetConsoleTextAttribute(h, 11);//color text in blue
		Date birthday = (this->myFollowers.getMemberByIndex(i))->getBirthDate();
		cout << "My birthday :" << birthday.getDay() << '/' << birthday.getMonth() << '/' << birthday.getYear() << '\n';
		SetConsoleTextAttribute(h, 7);//return to default color

	}
}

void FanPage::removeFollowers(Member* member)
{
	if (member != nullptr)
	{
		if (this->myFollowers.findMemberByNameAndReturnIndex(member->getName()) != NOT_FOUND)
		{
			this->myFollowers.removeMember(member);
			member->removeFollowFromFanPage(this);
		}
	}
}

void FanPage::show() const
{
	cout << "My name is: " << this->name << "\n";
}

FanPage::~FanPage()
{
	delete[]name;
}
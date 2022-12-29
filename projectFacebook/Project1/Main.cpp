#include  "Utils.h"
using namespace std;

int main()
{
	int userChoice;
	FaceBook facebook;
	
	Member shaked=creatMember("Shaked Halif",17, 3,1999);
	Member yuval= creatMember("Yuval Wilfand", 22, 2, 1998);
	Member bjarne= creatMember("Bjarne Stroustrup", 30, 12, 1950);
	
	FanPage CSharpFans = createFanPage("c# fans");
	FanPage PizzaLovers = createFanPage("pizza lovers");
	FanPage CPPFans = createFanPage("c++ fans");

	defaultUsers(facebook, shaked, yuval, bjarne);
	defaultFanPages(facebook, CSharpFans, PizzaLovers, CPPFans);
	shaked.addStatus("my cat is missing");
	shaked.addStatus("found it!");
	yuval.addStatus("c++ is rock!");
	yuval.addStatus("c# is just not that great");
	bjarne.addStatus("life is great when you are a belioner");
	bjarne.addStatus("someone want to come to my c++ party?");

	CSharpFans.addStatus("new libery just went up");
	CSharpFans.addStatus("come check this new functions");

	PizzaLovers.addStatus("what is your favorite topping?");
	PizzaLovers.addStatus("Margarita is the best pizza");

	CPPFans.addStatus("listen students! new function have been develope just for your home work");
	CPPFans.addStatus("python is not a good coding language! there I said it");

	shaked.addFriend(&yuval);
	yuval.addFriend(&bjarne);
	bjarne.addFriend(&shaked);

	shaked.addFollowToFanPage(&CSharpFans);
	shaked.addFollowToFanPage(&PizzaLovers);
	shaked.addFollowToFanPage(&CPPFans);
	yuval.addFollowToFanPage(&CPPFans);
	bjarne.addFollowToFanPage(&PizzaLovers);

	userChoice=getAndPrintMenu();

	while (userChoice!=16)
	{
		
		while (!checkValid(userChoice))
		{
			printInvalid();
			userChoice=getAndPrintMenu();
		}
		
		getChoice(userChoice, facebook);
		userChoice=getAndPrintMenu();
	}


	return 1;
}
//This function is printing the facebook menu and returning (by ref parameter)
// the user's action choice
int getAndPrintMenu()
{
	int userChoice;
	cout << "what would like to do today?" << '\n'
		<< "1. sign in as a new friend" << '\n'
		<< "2. sign in as a new fan page" << '\n'
		<< "3. add a new member status" << '\n'
		<< "4. add a new fan page status" << '\n'
		<< "5. view all my statuses as a member" << '\n'
		<< "6. view all my statuses as a fan page" << '\n'
		<< "7. show my friends' 10 latest statuses" << '\n'
		<< "8. add a new friend" << '\n'
		<< "9. delete a friend from my friends list" << '\n'
		<< "10. subscribe a new fan page" << '\n'
		<< "11. unsubscribe a fan page" << '\n'
		<< "12. show all facebooks' members" << '\n'
		<< "13. show all facebooks' fan pages" << '\n'
		<< "14. show a members' friends " << '\n'
		<< "15. show a fan page subscribers" << '\n'
		<< "16. exit" << '\n';
	cin >> userChoice;
	return userChoice;

}

//This function is manages the user's action choice
void getChoice(int userChoice, FaceBook& facebook)
{
	switch (userChoice) {
	case 1://register as new facebook member
	{
		registerAsNewMember(facebook);
		//facebook.addNewMember();
		break;
	}
	case 2://create new fan page
	{
		createNewFanPage(facebook);
		break;
	}
	case 3://add a new member status
	{
		addMemberStatus(facebook);
		break;
	}
	case 4://add a new fan page status
	{
		addFanPageStatus(facebook);
		break;
	}
	case 5://view all my statuses as a member
	{
		viewMemberStatuses(facebook);
		break;
	}

	case 6://view all my statuses as a fan page
	{
		viewFanPageStatuses(facebook);
		break;

	}
	case 7://show my friends' 10 latest statuses
	{
		showMembersFriends10LatestStatuses(facebook);
		break;
	}
	case 8://add a new friend
	{
		facebook.connectMembers();
		break;
	}
	case 9://delete a friend from my friends list
	{
		facebook.disconnectMembers();
		break;
	}
	case 10://subscribe a new fan page
	{
		facebook.connectMemberToFanPage();
		break;
	}
	case 11://unsubscribe a fan page
	{
		facebook.disconnectMemberToFanPage();
		break;
	}

	case 12://show all facebooks members
	{
		facebook.showAllMembers();
		break;
	}

	case 13://show all facebook fan pages
	{
		facebook.showAllFanPages();
		break;
	}

	case 14://show a members' friends
	{
		facebook.showAllUsersFriends();
		break;
	}

	case 15://show a fan page followers
	{
		facebook.showAllFanPageFollowers();
		break;
	}

	}
}

//This function is checking the user's action choice is valid
bool checkValid(int userChoice)
{
	if (cin.fail())
	{
		cin.clear(); // clear input buffer to restore cin to a usable state
		cin.ignore(INT_MAX, '\n'); // ignore last input
		return false;
	}

	if (userChoice < 1 && userChoice >16)
		return false;
	else
		return true;
}

//This function is seting a birthday Date and returning if its valid
bool setBirthDate(Date& date) {

	char birthDate[MAX_DATE_LEN];

	cout << "Please enter your date of birth in DD/MM/YYYY formating:  ";
	cin.getline(birthDate,MAX_DATE_LEN);
	const char seps[9] = "/,.-[]' ";
	char* token = strtok(birthDate, seps);// Returns first token
	

	// Keep getting tokens while one of the
	// delimiters present in str[].
	while (token != NULL)
	{
		if (!date.setDay(std::stoi(token)))//convert str to int - DAY
			return false;
		token = strtok(NULL, seps);//take next token from string
		if (!date.setMonth(std::stoi(token)))//convert str to int - MONTH
			return false;
		token = strtok(NULL, seps);
		if (!date.setYear(std::stoi(token)))//convert str to int - YEAR
			return false;
		token = strtok(NULL, seps);//gets the NULLptr
	}
	return true;
}

//This function is schecking if the user would like to see the members list of facebook
bool isShowMembersList(FaceBook& facebook)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

	char choice;
	cout << "Would you like to see Facebooks' members?";
	SetConsoleTextAttribute(h, 8);//color text in grey
	cout << " (enter Y/N)" << '\n';
	SetConsoleTextAttribute(h, 7);//return to default color
	cin >> choice;//get the choice

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
		cin >> choice;
	}

	if (choice == 'y' || choice == 'Y')
		return true;

	if (choice == 'n' || choice == 'N')
		return false;

}

//This function is schecking if the user would like to see the fan pages list of facebook
bool isShowFanPagesList(FaceBook& facebook)
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

	if (choice == 'n' || choice == 'N')
		return false;

}

//This function is printing an annoucment that the user request is'nt valid
void printInvalid()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(h, 12);//color text in red
	cout << endl << "Your request is not valid. please try again." << endl << endl;
	SetConsoleTextAttribute(h, 7);//return to default color

}

//This function manage the registerion of a new member
void registerAsNewMember(FaceBook&facebook)
{
	char memberName[MAX_NAME_LEN];
	Date date;
	cout << endl << "Please enter your full name:  ";
	clearBuffer();
	cin.getline(memberName, MAX_NAME_LEN);
	if (setBirthDate(date))
	{
		Member* member = new Member(memberName, date);
			if (facebook.addNewMember(member))
			{
				cout << endl << "Your registration has been accepted! " << endl;
					printWelcome();
			}
			else
			{
				printInvalid();
				delete member;
			}
	}
	else
		printInvalid();
}

//This function is clearing the buffer for cin.getline
void clearBuffer()
{
	cin.clear(); // clear input buffer to restore cin to a usable state
	cin.ignore(INT_MAX, '\n'); // ignore last input
}

//This function manage the creation of a new fan page
void createNewFanPage(FaceBook& facebook)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	char fanPageName[MAX_NAME_LEN];
	cout << endl << "Please enter your fan page name:  ";
	clearBuffer();
	cin.getline(fanPageName, MAX_NAME_LEN);
	FanPage* newFanPage = new FanPage(fanPageName);
	//facebook.addNewFanPage(newFanPage);//add a new fan page to facebook
	if (facebook.addNewFanPage(newFanPage))
	{
		cout << endl << "Your registration has been accepted! " << endl;
		printWelcome();
	}
	else
	{
		printInvalid();
		delete newFanPage;
	}
}

//This function is printing the welcome annoucment
void printWelcome()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(h, 9);//color text in blue
	cout << "WELCOME TO FACEBOOK!" << endl<<endl;
	SetConsoleTextAttribute(h, 7);//return to default color
}

//This function adding new status to a member that it get from the user
void addMemberStatus(FaceBook&facebook)
{
	char chosenMember[MAX_NAME_LEN];
	if (isShowMembersList(facebook))//if the user wants to see the facebooks' users 
		facebook.showAllMembers();//it will present the list to him
	cout << endl << "Choose which user you want to write a status for and write their full name as shown:" << endl<<endl;
	clearBuffer();
	cin.getline(chosenMember, MAX_NAME_LEN);//pick the user we want to add a new status to
	facebook.addNewStatusForMember(chosenMember);
}

//This function adding new status to a fan page that it get from the user
void addFanPageStatus(FaceBook& facebook)
{
	char chosenFanPage[MAX_NAME_LEN];
	if (isShowFanPagesList(facebook))//if the user wants to see the facebooks' users 
		facebook.showAllFanPages();//it will present the list to him
	cout << endl << "Choose which fan page you want to write a status for and write their full name as shown:" << endl;
	clearBuffer();
	cin.getline(chosenFanPage, MAX_NAME_LEN);//pick the user we want to add a new status to
	facebook.addNewStatusForFanPage(chosenFanPage);
}

//This function showing the status of a member that it get from the user
void viewMemberStatuses(FaceBook& facebook)
{
	char chosenMember[MAX_NAME_LEN] = " ";
	if (isShowMembersList(facebook))//if the user wants to see the facebooks' users 
		facebook.showAllMembers();//it will present the list to him
	cout << "Select a user for whom you will view their statuses:" << endl;
	clearBuffer();
	cin.getline(chosenMember, MAX_NAME_LEN);//pick the user we want to view their statuses
	facebook.viewMemberStatusList(chosenMember);
}

//This function showing the status of a fan page that it get from the user
void viewFanPageStatuses(FaceBook& facebook)
{
	char chosenFanPage[MAX_NAME_LEN];
	if (isShowFanPagesList(facebook))//if the user wants to see the facebooks' users 
		facebook.showAllFanPages();//it will present the list to him
	cout << "Select a fan page which you will view its statuses:" << '\n';
	clearBuffer();
	cin.getline(chosenFanPage, MAX_NAME_LEN);//pick the user we want to view their statuses
	facebook.viewFanPageStatusList(chosenFanPage);
}

//This function showing the 10 status of each friend of a member that it gat from the user
void showMembersFriends10LatestStatuses(FaceBook&facebook) 
{
	    char chosenMember[MAX_NAME_LEN];
		if (isShowMembersList(facebook))//if the user wants to see the facebooks' users 
			facebook.showAllMembers();//it will present the list to him
		cout << "Select the user whom you would like to view their friends statuses :" << '\n';
		clearBuffer();
		cin.getline(chosenMember, MAX_NAME_LEN);//pick the user we want to view their statuses
		facebook.showAllUsers10StatusesOfFriends(chosenMember);
}

//This function is adding a default users to facebook
void defaultUsers(FaceBook& facebook, Member& mem1, Member& mem2, Member& mem3)
{
	facebook.addNewMember(&mem1);
	facebook.addNewMember(&mem2);
	facebook.addNewMember(&mem3);
}

//This function is creating a Member
Member creatMember(const char* name, int day, int month, int year)
{
	Date birthday;
	birthday.setDay(day);
	birthday.setMonth(month);
	birthday.setYear(year);
	Member member(name, birthday);
	return member;
}

//This function is creating a FanPage
FanPage createFanPage(const char* name )
{
	FanPage fp(name);
	return fp;
}

//This function is adding a default fan pages to facebook
void defaultFanPages(FaceBook& facebook, FanPage& fp1, FanPage& fp2, FanPage& fp3)
{
	facebook.addNewFanPage(&fp1);
	facebook.addNewFanPage(&fp2);
	facebook.addNewFanPage(&fp3);
}

#ifndef _FANPAGE_H
#define _FANPAGE_H

#include <iostream>
#include <string.h>
#include "StatusArr.h"
#include "MemberArr.h"
#include "Member.h"
#pragma warning(disable: 4430)


class FanPage
{
private:
	char* name;
	StatusArr myStatus;
	MemberArr myFollowers;

public:
	FanPage(const char* name);
	FanPage(FanPage&& other);
	~FanPage();
	const char* getName()				const;
	StatusArr getMyStatus()				const;
	void addFollower(Member* other);
	void addStatus(const char* text);
	void showMyStatus()					const;
	void showAllMyStatuses()            const;
	void showMyFollowers10Status()		const;
	void showMyFollowers()				const;
	void removeFollowers(Member* other);
	void show()							const;
};

#endif
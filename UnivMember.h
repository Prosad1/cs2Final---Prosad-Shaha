//pshaha1 Prosad Shaha
#ifndef UNIV_H
#define UNIV_H

#include "ID.h"
#include"Name.h"
#include <string>
#include <vector>
using namespace std;

class UnivMember
{
	public:
	//Puling from .h files
	UnivMember();
	~UnivMember();

	string getRole() const;
	void setRole(string role);

	void setUnivName(string tempName);
	void setUnivID();
	string getUnivID();
	void printUnivMembers();
	friend ostream& operator<<(ostream& output, const UnivMember* member);
	void setUserName(string userName);
	string getUserName() const;
	friend void createUserName(vector<UnivMember *> memberV1, vector<UnivMember *> memberV2);
	friend void printUserName(vector<UnivMember *> member);
	int findMember(UnivMember * memberP, vector<UnivMember*> memberV);
	 bool operator==(const UnivMember* memberP);

	private:
	//unique to this class
	string role;
	string userName;

	Names UnivName;
	idNumber UnivID;
	

};

#endif

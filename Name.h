//pshaha1 Prosad Shaha
#ifndef NAME_H
#define NAME_H
#include<iostream>
using namespace std;

class Names
{
	public:
	
	Names();
	void setName(string fullName);
	string getFirstName() const;
	string getLastName() const;
	void printName();
	

	private:
	string fName,lName;
};

#endif

//pshaha1 Prosad Shaha
#include "Name.h"


Names::Names()
{
	this->fName = "First";
	this->lName = "Last";


}

void Names::setName(string fullName)
{
	int comma = 0;
	comma = fullName.find(',');
	this->lName = fullName.substr(0,comma);
	this->fName = fullName.substr(comma+1,((fullName.length()) -1));
	
	//This allows us to take out space at the end of professor names if the have one
	if (fName[fName.length()-1] == ' ')
	{
		fName = fName.substr(0,fName.length()-1);
	}

	if(fullName == "TBD")
	{
		this->fName = "TBD";
		this->lName = "TBD";
	}
}

//used if I need one of the names
string Names::getFirstName() const
{
	return fName;
}

string Names::getLastName() const
{
	return lName;
}

//used in the larger print function in UnivMember.cpp
void Names::printName()
{
	cout << this->fName << " " << this->lName << endl;
}


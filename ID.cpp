//pshaha1 Prosad Shaha
#include "ID.h"
using namespace std;

//assigns an id number to each class object
idNumber::idNumber()
{
	static int currentNumber = 10000000;
	this-> ID_number = currentNumber++;
	char firstChar = 'A';
	this-> full_ID = firstChar + to_string(ID_number);
}

idNumber::~idNumber()
{


}

string idNumber::get_ID() const
{
	return full_ID;
}

//used in the larger print function in UnivMember.cpp
void idNumber::printID()
{
	cout <<"ID: " << get_ID();
}

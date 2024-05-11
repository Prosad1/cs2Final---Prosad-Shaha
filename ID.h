//pshaha1 Prosad Shaha
#ifndef POINT_H
#define POINT_H
#include <iostream>
#include <string>
using namespace std;
class idNumber
{
	public:
	
	//member functions
	idNumber();
	~idNumber();
	string get_ID() const;
	void printID();

	private:

	//variables to use
	int ID_number;
	string full_ID;

};

#endif

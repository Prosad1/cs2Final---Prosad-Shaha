//pshaha1 Prosad Shaha
#include "UnivMember.h"
#include <cstdlib>
#include <algorithm>


using namespace std;

UnivMember::UnivMember()
{
	

}


UnivMember::~UnivMember()
{

}



void UnivMember::setRole(string role)
{
	this->role = role;
}

string UnivMember::getRole() const
{
	return role;
}

//This function calls the function in Name.cpp to set a name for the university member
void UnivMember::setUnivName(string tempName)
{
	UnivName.setName(tempName);
}



//Printing names and ID
void UnivMember::printUnivMembers()
{
	cout << getRole() <<": ";
	UnivName.printName();
	UnivID.printID();
	cout << endl;
}

void UnivMember::setUserName(string userName)
{
	this->userName = userName;

}

string UnivMember::getUserName() const
{
	return userName;
}

int UnivMember::findMember(UnivMember * memberP, vector<UnivMember*> memberV)
{
	int Index = 0;
	
	for(int i=0; i<memberV.size(); i++)
	{
		if(memberV.at(i) == memberP)
		{
			Index = i;
			return Index;
		}

	}

	return -1;
	
}

//we use this to create usernames
void createUserName(vector<UnivMember *> memberV1,vector<UnivMember *> memberV2)
{
	//Combining the student and professor vectors
	//this way it will be easier to find duplicate
	//names between all university members
	vector<UnivMember *> member;

	for(int i =0; i<memberV1.size(); i++)
	{
		member.push_back(memberV1.at(i));
	}
	for(int i =0; i<memberV2.size(); i++)
	{
		member.push_back(memberV2.at(i));
	}

	int i;
	int currIndex;

	for(i=0; i<member.size(); i++)
	{
		string first = member.at(i)->UnivName.getFirstName();
		string last = member.at(i)->UnivName.getLastName();
		//for last names that might have a space in it
		if(first != "TBD")
		{
			int lastSpace = last.find(' ');
			if(lastSpace != string::npos)
			{
				//allows us to get rid of the middle part of their name
				last = last.substr(lastSpace+1,last.length()-1);
			}
			char firstI = tolower(first[0]);
			char lastI = tolower(last[0]);
			string lastWithOutI = last.substr(1,last.length()-1);
			string Initials = string(1,firstI) +string(1,lastI);
			string user =Initials+lastWithOutI;
			member.at(i)->setUserName(user);
		}
		else if (first == "TBD")
		{
			member.at(i)->setUserName("TBD");
		}

	}

	//now we will check for usernames that match each other and 
	//if we find any we will change the number at the end of their name
	for(i=0; i<member.size(); i++)
	{
		
		vector<UnivMember *> users;
		
		
		//string member1 = member.at(i)-> getUserName();
		UnivMember * member1 = member.at(i);
		for(int j=0; j<member.size(); j++)
		{
			//string member2 = member.at(j)->getUserName();
			//if(member1 != "TBD")
			if(member1->getUserName() != "TBD")
			{
				if(*member.at(i) == member.at(j))
				{
					
					users.push_back(member.at(j));
					
				}
			}
			else
			{}

		}
		//adding a unique number to the username
		for(int n=0; n<users.size(); n++)
		{
			string name = users.at(n)->getUserName();
			if(!(isdigit(name[name.length()-1])))
			{
			users.at(n)->setUserName(users.at(n)->getUserName() + to_string(n+1));
			}
			//just making sure that everyone got a unique number
			//it will output the number next to everyones name and 
			//if you know there is supposed to be a two instead of all ones
			//this will show you
			//cout << "This is a unique number: " << to_string (n+1) << endl;
			
		}
	}
	
}

//simple print function
void printUserName(vector<UnivMember *> member)
{
	for(int i=0; i<member.size(); i++)
	{

		cout << member.at(i)->getUserName();
		cout << endl;
	}
}

//overloaded << operator to help output files into another file that will contain professor information
ostream& operator<<(std::ostream& output, const UnivMember* member)
{
    output << member->getRole() << ": " << member->UnivName.getFirstName() << ' '<< member->UnivName.getLastName();
	output << endl;
	output << "ID: " << member->UnivID.get_ID() << endl;
	return output;
}


string UnivMember::getUnivID()
{
	return UnivID.get_ID();
}


//This is used to see if the usernames between two university members
//are the same this way we can give them unique numbers
bool UnivMember:: operator==(const UnivMember* memberP)
{
	if(this->userName == memberP->userName)
	{
		return true;
	}
	else
	{
		return false;
	}
}
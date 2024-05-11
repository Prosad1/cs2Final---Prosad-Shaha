//pshaha1 Prosad Shaha
#include "UnivMember.h"
#include "ID.h"
#include "Name.h"
#include <vector>
#include <fstream>
#include <string>
using namespace std;


int main()
{

	ifstream profIn;

	//Opening up the student and professor name files
	profIn.open("CSProfNames.txt");
	if(!profIn.is_open())
	{
		cout << "File 1 has not opened" << endl;
		cout << "Aborting" << endl;
		return 1; //indicates an error
	}
	ifstream studentIn;
	studentIn.open("StudentsLastFirst.txt");	
	if(!studentIn.is_open())
	{
		cout << "File 2  has not opened" << endl;
		cout << "Aborting" << endl;
		return 1; //indicates an error
	}

	//creating a new profesor in the heap and pushing it into the vector
	//Telling the user what is happening
	cout << "Reading in data from \"CSProfNames.txt\"" << endl;
	cout << endl;
	vector<UnivMember * > Professor;
	while(!profIn.eof())
	{

		string tempName;
		getline(profIn, tempName);
		
		//making a university member in the heap
		UnivMember * temp = new UnivMember;
		temp->setRole("Prof");
		temp->setUnivName(tempName);
		
		Professor.push_back(temp);
			
	}
	profIn.close();	
	
	//creating a new Student in the heap and pushing it into the vector
	//Telling the user what is happening
	cout << "Reading in data from \"StudentsLastFirst.txt\"" << endl;
	cout << endl;
	vector<UnivMember * > Student;
        while(!studentIn.eof())
        {

                string tempName;
                getline(studentIn, tempName);

				//making a university member in the heap
                UnivMember * temp = new UnivMember;
                temp->setRole("Student");
                temp->setUnivName(tempName);

                Student.push_back(temp);

        }
	studentIn.close();



	//taking all the data and storing it into a file using a overloaded << function 
	cout << "Storing Professor name and ID into \"profInfo.txt\"" << endl;
	cout << endl;
	ofstream profOut;
	profOut.open("profInfo.txt");
	if(!profOut.is_open())
	{
		cout << "File 3 has not opened" << endl;
		cout << "Aborting" << endl;
		return 1; //indicates an error
	}

	//profOut << "Making sure this works" << endl;

	for(int i=0; i<Professor.size(); i++)
	{
		//using the overloaded << operator
		profOut << Professor.at(i);
		profOut << endl;
	}
	
	profOut.close();

	//displaying the contents of the file 
	cout << "The following is the contents in \"profInfo.txt\"" << endl;
	cout << endl;
	ifstream professorIn;
	professorIn.open("profInfo.txt");
	if(!professorIn.is_open())
	{
		cout << "File \"profInfo.txt\" has not opened" << endl;
		cout << "Aborting" << endl;
		return 1; //indicates an error
	}
	while(!professorIn.eof())
	{
		string text;
		getline(professorIn, text);	
		cout << text;
		cout << endl;
		getline(professorIn, text);	
		cout << text;
		cout << endl;
	}

	professorIn.close();
	cout << "End of \"profInfo.txt\" contents" << endl;
	cout << endl;

	cout << "Creating unique usernames for students and professors" << endl;
	cout << endl;

	createUserName(Professor,Student);
	cout << "Storing unique student usernames and ID into a file named \"StudentUsername&ID.txt\"" << endl;
	cout << endl;
	ofstream studOut;
	studOut.open("StudentUsername&ID.txt");
	if(!studOut.is_open())
	{
		cout << "File \"StudentUsername&ID.txt\" has not opened" << endl;
		cout << "Aborting" << endl;
		return 1; //indicates an error
	}
	
	for(int i=0; i<Student.size(); i++)
	{
		studOut << Student.at(i)->getUnivID() << ", ";
		studOut << Student.at(i)->getUserName() << endl;
		studOut << endl;
	}

	cout << "Displaying contents of \"StudentUsername&ID.txt\"" << endl;
	cout << endl;
	ifstream studIn;
	studIn.open("StudentUsername&ID.txt");
	if(!studIn.is_open())
	{
		cout << "File \"StudentUsername&ID.txt\" has not opened" << endl;
		cout << "Aborting" << endl;
		return 1; //indicates an error
	}

	while (!studIn.eof())
	{
		string text;
		getline(studIn,text);
		cout << text << endl;
	}
	cout << "End of \"StudentUsername&ID.txt\" contents" << endl;

	cout << endl;

	cout << "Freeing up dynamic memory" << endl;
	for (int i=0; i<Student.size(); i++)
	{
		delete Student.at(i);

	}
	Student.clear();

	for (int i=0; i<Professor.size(); i++)
	{
		delete Professor.at(i);

	}
	Professor.clear();

	return 0;
}

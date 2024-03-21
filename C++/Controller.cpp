//Import Libraries
#include "HTMLChange.h"
#include "UploadToGitHub.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool testingHTMLChange()
{
	//Initalize Variables
	fstream HTMLFile = fstream();
	int priorityList[6] = { 5,3,1,0,4,2 };

	HTMLFile.open("../../../HTML Files/scp_main_page.html");

	bool temp = changeNavBar(&HTMLFile, priorityList);

	HTMLFile.close();

	return temp;
}

bool testingGitHub()
{
	//Initalize Variables
	char localRepo[] = "F:\Desktop\CS 386 Project\deployed_website\.git";
	bool success = false;

	cout << "Setup git\n";

	if (!setup())
	{
		return false;
	}

	cout << "Setting up repo.\n";

	//Connect to local repo
	if (!connectToRepository(localRepo))
	{
		return false;
	}
	
	cout << "Pushing files to repo.\n";

	//Push files
	if (!pushFiles())
	{
		return false;
	}

	cout << "Freeing data\n";

	//Free data
	closeRepository();

	return true;
}

int main()
{
	//Initialize Variables

	return testingGitHub();
}
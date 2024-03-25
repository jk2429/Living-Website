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
	int priorityList[6] = { 5,4,3,2,1,0 }, count;
	string filesToOpen[7] = {"../../../HTML Files/scp_main_page.html", "../../../HTML Files/scp_081_page.html", "../../../HTML Files/scp_999_page.html",
							"../../../HTML Files/scp_1990_page.html", "../../../HTML Files/scp_2006_page.html",  "../../../HTML Files/scp_2161_page.html",
							"../../../HTML Files/scp_8012_page.html"};

	//Loop until no more files
	for (count = 0; count < 7; count++)
	{
		try
		{
			HTMLFile.open(filesToOpen[count]);

			if (!changeNavBar(&HTMLFile, priorityList, filesToOpen[count].substr(20, string::npos)))
			{
				HTMLFile.close();
				throw count;
			}

			HTMLFile.close();
		}
		catch (int number)
		{
			cout << "Run " << number << " failed: " << filesToOpen[number] << endl;
		}
	}

	return true;
}

/*
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
*/

int main()
{
	//Initialize Variables

	return testingHTMLChange();
}
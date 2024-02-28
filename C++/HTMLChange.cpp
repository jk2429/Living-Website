//Import Libraries
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

//Global Variables
static const string navOptions[6] = {"Class: Safe", "Class: Euclid", "Class: Keter", "Series: I", "Series: II", "Series: III"};
static const string navLinks[6] = {"safe.html", "euclid.html", "keter.html", "I.html", "II.html", "III.html"};
const int MAX_CODE_LINES = 500;

//Change Navigation Bar Function
//Prereqs: The priority list is different than the current list in the html file. Priority list has a
//         reference to only one of each item entity in navOptions.
//Postreq: The html file navigation code has been adjusted to reflect the updated priority list
//Objectives: The html file will be opened if not already, and will check each element of the navigation
//			  bar and change it to the required item in the priority list.
//Notes: itemSpots refers to the same spots in navOptions. For example both [0] are refering to
//       "Class: Safe" location
bool changeNavBar(fstream *HTMLFile, int priorityList[])
{
	//Local Variables
	int navSpot = 0, numLines = 0, itemSpots[6], currentItem = 0, count = 0, start = 0;
	string ReplacementCode[MAX_CODE_LINES];
	bool notFound = true;
	
	//Check if stream is open
	if (!HTMLFile->is_open())
	{
		//Print error and return fail
		cout << "Error: File not open\n";
		return false;
	}
	
	//Copy entire stream into buffer line by line
	while (HTMLFile->peek() != EOF)
	{
		//Store line into buffer
		getline(*HTMLFile, ReplacementCode[numLines]);
		
		cout << ReplacementCode[numLines] << endl;
		
		//Increase number of lines by 1
		numLines += 1;
	}
	
	//Find what line <nav> is on
	while (navSpot < numLines && notFound && navSpot < numLines)
	{
		//Check if <nav> is in the current line
		if (ReplacementCode[navSpot].find("<nav>") != string::npos)
		{
			notFound = false;
		}
		//Increase by 1 and loop
		else
		{
			navSpot += 1;
		}
	}
	
	//Check if failed to find
	if (notFound)
	{
		//Print Error and return fail
		cout << "Error: Failed to find <nav>\n";
		return false;
	}
	
	//Set count to navSpot
	count = navSpot;
	
	//Find item spots and fill in array
	while (currentItem < 6 && count < numLines)
	{
		//Find each item spot
		if (ReplacementCode[count].find(navOptions[currentItem]) != string::npos)
		{
			//Set itemSpots
			itemSpots[currentItem] = count;
			
			//reset count
			count = navSpot;
			
			//Increase currentItem
			currentItem += 1;
		}
		//Increase by 1 and loop
		else
		{
			count += 1;
		}
	}
	
	//Print each item and its location
	for (count = 0; count < 6; count++)
	{
		cout << navOptions[count] << " is locatated on line: " << itemSpots[count] << endl;
	}
	
	//Print Changes to be made
	cout << "\nChanging order to:\n";
	for (count = 0; count < 6; count++)
	{
		cout << navOptions[priorityList[count]] << endl;
	}
	
	//Reset variables
	currentItem = 0;
	count = 0;
	
	//Change the names of each link
	while (currentItem < 6)
	{
		//Find start and end
		//Find the 2nd instance of >
		while (count != 2)
		{
			start = ReplacementCode[itemSpots[currentItem]].find('>', start + 1);
			count += 1;
		}
		
		//Reset count
		count = 0;
		
		cout << "Start: " << start << " length: " << navOptions[currentItem].length() << endl;
		
		//Replace name in string
		ReplacementCode[itemSpots[currentItem]].replace(start + 1, navOptions[currentItem].length(), navOptions[priorityList[currentItem]]);
		
		//Reset Start
		start = 0;
		
		//Increase currentItem
		currentItem += 1;
	}
	
	//Print Changes made
	cout << "\nOrder Changed to:\n";
	for (count = 0; count < 6; count++)
	{
		cout << ReplacementCode[itemSpots[count]] << endl;
	}
	
	//Change the links
	//TODO
	
	//Apply changes to HTML Document
	//TODO
	
	return true;
}

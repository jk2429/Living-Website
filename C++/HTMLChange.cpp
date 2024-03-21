//Import Header
#include "HTMLChange.h"

using namespace std;

//Change Navigation Bar Function
//Objectives: The html file will be opened if not already, and will check each element of the navigation
//			  bar and change it to the required item in the priority list.
//Prereqs: The priority list is different than the current list in the html file. Priority list has a
//         reference to only one of each item entity in navOptions.
//Postreq: The html file navigation code has been adjusted to reflect the updated priority list
//Notes: itemSpots refers to the same spots in navOptions. For example both [0] indecies are refering to
//       "Class: Safe" location. priorityList will keep track of the list of items in the order that they
//       should come out. For example if the list looks like {5, 4, 3, 2, 1, 0} then the order will be
//		 "Series: III", "Series II", "Series: I", etc.
bool changeNavBar(fstream *HTMLFile, int priorityList[])
{
	//Local Variables
	int navSpot = 0, numLines = 0, itemSpots[MAX_NAV_OPTIONS], currentItem = 0, count = 0, start = 0;
	string ReplacementCode[MAX_CODE_LINES];
	bool notFound = true;
	ofstream newHTML = ofstream();
	
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
		
		cout << numLines << "\t" << ReplacementCode[numLines] << endl;
		
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
	while (currentItem < MAX_NAV_OPTIONS && count < numLines)
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
	
	//Check for all items filled
	if (currentItem < MAX_NAV_OPTIONS)
	{
		//Print error statement and return error
		cout << "Error: Failed to find all Navigation items\n";
		return false;
	}
	
	//Print each item and its location
	for (count = 0; count < MAX_NAV_OPTIONS; count++)
	{
		cout << navOptions[count] << " is locatated on line: " << itemSpots[count] << endl;
	}
	
	//Print Changes to be made
	cout << "\nChanging order to:\n";
	for (count = 0; count < MAX_NAV_OPTIONS; count++)
	{
		cout << navOptions[priorityList[count]] << endl;
	}
	
	//Reset variables
	currentItem = 0;
	count = 0;
	start = 0;
	
	//Change the names of each link
	while (currentItem < MAX_NAV_OPTIONS)
	{
		//Find start
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
	for (count = 0; count < MAX_NAV_OPTIONS; count++)
	{
		cout << ReplacementCode[itemSpots[count]] << endl;
	}
	
	//Reset variables
	currentItem = 0;
	count = navSpot;
	
	//Change the links
	//Loop through buffer finding each spot for the links
	while(currentItem < MAX_NAV_OPTIONS && count < numLines)
	{
		//Check for link in line
		if (ReplacementCode[count].find(navLinks[currentItem]) != string::npos)
		{
			//Set itemSpots to current location
			itemSpots[currentItem] = count;
			
			//Reset count
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
	
	//Check for all items filled
	if (currentItem < MAX_NAV_OPTIONS)
	{
		//Print error statement and return error
		cout << "Error: Failed to find all Link items\n";
		return false;
	}
	
	//Print each item and its location
	for (count = 0; count < MAX_NAV_OPTIONS; count++)
	{
		cout << navLinks[count] << " is locatated on line: " << itemSpots[count] << endl;
	}
	
	//Print Changes to be made
	cout << "\nChanging order to:\n";
	for (count = 0; count < MAX_NAV_OPTIONS; count++)
	{
		cout << navLinks[priorityList[count]] << endl;
	}
	
	//Reset variables
	currentItem = 0;
	start = 0;
	
	//Change the links
	while (currentItem < MAX_NAV_OPTIONS)
	{
		//Find start
		start = ReplacementCode[itemSpots[currentItem]].find("href=", start + 1) + 6;
		
		cout << "Start: " << start << " length: " << navLinks[currentItem].length() << endl;
		
		//Replace link in string
		ReplacementCode[itemSpots[currentItem]].replace(start, navLinks[currentItem].length(), navLinks[priorityList[currentItem]]);
		
		//Reset Start
		start = 0;
		
		//Increase currentItem
		currentItem += 1;
	}
	
	//Print Changes made
	cout << "\nOrder Changed to:\n";
	for (count = 0; count < MAX_NAV_OPTIONS; count++)
	{
		cout << ReplacementCode[itemSpots[count]] << endl;
	}
	
	//Apply changes to new HTML Document
	//Create new HTML document
	newHTML.open("../../../New HTML Files/newHTML.html");
	
	//Check if new document has been opened
	if (newHTML.is_open())
	{
		//Write each line to document
		for (count = 0; count < numLines; count ++)
		{
			newHTML << ReplacementCode[count] << endl;
		}
		
		//Close file
		newHTML.close();
	}
	else
	{
		//Print error statement
		cout << "Error: Failed to create new file\n";
		return false;
	}
	
	return true;
}
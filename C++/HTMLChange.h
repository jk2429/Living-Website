#pragma once
#ifndef HTMLCHANGE_H
#define HTMLCHANGE_H

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

//Global Variables
static const int MAX_NAV_OPTIONS =  6;
static const string navOptions[MAX_NAV_OPTIONS] = { "SCP-081", "SCP-8012", "SCP-1990", "SCP-2161", "SCP-999", "SCP-004" };
static const string navLinks[MAX_NAV_OPTIONS] = { "scp_081_page.html", "scp_8012_page.html", "scp_1990_page.html", "scp_2161_page.html", "scp_999_page.html", "scp_004_page.html" };
static const int MAX_CODE_LINES = 500;

//Forward Declare Functions
bool changeNavBar(fstream *HTMLFile, int priorityList[]);

#endif
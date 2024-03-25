#pragma once
#ifndef UPLOADTOGITHUB_H
#define UPLOADTOGITHUB_H

#include <git2.h>
#include <string>
#include <iostream>

using namespace std;

//Global Variables
static git_repository* repo;
static int error;

//Forward Declare Functions
bool setup();
bool connectToRepository(char* localRepo);
bool pushFiles();
void closeRepository();

#endif
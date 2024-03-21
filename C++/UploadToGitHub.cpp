//Import Libraries
#include "UploadToGitHub.h"

using namespace std;

//Connect to repository function
//Objectives: 
//Prereqs: 
//Postreq: 
//Notes: 
bool connectToRepository(char* localRepo)
{
	//Initialize the repository
	error = git_repository_open(&repo, localRepo);
	
	//Check for success
	if (error < 0)
	{
		cout << "Repo failed to initialize.\n";
		return false;
	}

	return true;
}

//Connect to repository function
//Objectives: 
//Prereqs: 
//Postreq: 
//Notes: 
bool pushFiles()
{
	//Initialize Variabels
	git_push_options options;
	git_remote* remote = NULL;
	git_remote_callbacks callbacks = GIT_REMOTE_CALLBACKS_INIT;
	git_remote_lookup(&remote, repo, "deployed_website");

	//Connect to remote
	error = git_remote_connect(remote, GIT_DIRECTION_PUSH, &callbacks, NULL, NULL);

	//Check for errors
	if (error < 0)
	{
		cout << "Error: Could not remote into repository.\n";
		return false;
	}

	//Add local files to be pushed
	error = git_remote_add_push(repo, "deployed_website", "refs/heads/main:refs/heads/main");

	//Check for errors
	if (error < 0)
	{
		cout << "Error: Could not add local repo to push option.\n";
		return false;
	}

	//Configure push options
	error = git_push_init_options(&options, GIT_PUSH_OPTIONS_VERSION);

	//Check for errors
	if (error < 0)
	{
		cout << "Error: Could not create push options.\n";
		return false;
	}

	//Push to repo
	error = git_remote_upload(remote, NULL, &options);

	//Check for errors
	if (error < 0)
	{
		cout << "Error: Could no upload to repository.\n";
		return false;
	}

	//Free all data
	git_remote_free(remote);

	//Reurn success
	return true;
}

//Connect to repository function
//Objectives: 
//Prereqs: 
//Postreq: 
//Notes: 
void closeRepository()
{
	//free data storing the repository
	git_repository_free(repo);
}
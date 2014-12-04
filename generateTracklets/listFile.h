// Function getFileNameList: get all the files' names in the given directory

#include <vector>
#include <string.h>
#include "dirent.h"

std::vector<std::string> listFile(std::string &inputDir, char * fileType)
{
	std::vector<std::string> fileNames;
	std::string sFileName;
	DIR *dir;
	struct dirent *ent;
	if ((dir = opendir (inputDir.c_str())) != NULL)
	{
		/* print all the files and directories within directory */
		while ((ent = readdir (dir)) != NULL)
		{
			if (!strcmp(ent->d_name,".") || !strcmp(ent->d_name,"..")) continue;
			if (!strstr(ent->d_name,fileType)) continue;
			// sFileName = inputDir + "\\" + ent->d_name;
			sFileName = ent->d_name;
			fileNames.push_back(sFileName.c_str());
			printf ("%s\n", sFileName.c_str());
		}
		closedir (dir);
		return fileNames;
	}
	else
	{
		/* could not open directory */
		perror ("");
		//return EXIT_FAILURE;
		throw;
	}
}

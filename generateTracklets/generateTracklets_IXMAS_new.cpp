#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <unistd.h>
#include "listFile.h"

int main()
{
std::string cmd;
std::string execute = "/home/xikang/research/code/kthActivity/3rdParty/dense_trajectory_release_v1.2/release/DenseTrack";
std::string outputDir = "/home/xikang/research/data/IXMAS_new/tracklets";
std::string videoDir = "/home/xikang/research/data/IXMAS_new";
std::string video;
std::string output;
std::string::size_type n;

std::vector<std::string> files = listFile(videoDir, ".avi");

//for (int i=0;i<files.size();++i)
int i =1;
{
	video = videoDir + '/' + files[i];
	n = files[i].find(".avi");
	files[i].replace(n,n+4,".txt");
	output = outputDir + '/' + files[i];
	cmd = execute + " " + video + " > " + output;
	std::cout << cmd << std::endl;
	system(cmd.c_str());
}


}

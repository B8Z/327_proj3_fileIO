/*
 * FileReader.cpp
 *
 *  Created on: Nov 1, 2019
 *      Author: Adam Bates
 */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "../327_proj3_test/includes/FileIO.h"
#include "../327_proj3_test/includes/constants.h"

using namespace std;


int KP_FileIO::getFileContents(const std::string &filename, std::string &contents)
{
	//declare ifstream and string to hold values
	ifstream file_to_open;
	string line;

	//open file, return fail constant if cannot open
	file_to_open.open(filename.c_str());
	if (!file_to_open.is_open()){
		return COULD_NOT_OPEN_FILE_TO_READ;
	}

	//while not end of file, use line to add contents to 'contents'
	while (!file_to_open.eof()){
		getline(file_to_open, line);
		contents+=line;
	}

	//close file and return success constant
	file_to_open.close();
	return SUCCESS;
}

int KP_FileIO::writeVectortoFile(const std::string filename,std::vector<std::string> &myEntryVector)
{
	//declare ofstream and vector iterator
	ofstream file_to_open;
	vector<string>::iterator vector_iterator;

	//open file, return fail constant if cannot open
	file_to_open.open(filename.c_str());
	if (!file_to_open.is_open()){
		return COULD_NOT_OPEN_FILE_TO_WRITE;
	}

	//iterate through vector using vector_iterator
	for(vector_iterator = myEntryVector.begin();
			vector_iterator != myEntryVector.end();
			vector_iterator++){
		//write data to file
		file_to_open << *vector_iterator << endl;
	}

	//close file and return success constant
	file_to_open.close();
	return SUCCESS;
}



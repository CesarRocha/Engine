//================================================================
//              Utilities.cpp                                
//================================================================
#include "Utilities.hpp"
#include <fstream>


//================================================================
std::string ConsolePrintf(const char* messageFormat, ...)
{
	static const size_t BUFFER_SIZE = 2048;
	static char message[BUFFER_SIZE];
	va_list argumentList;
	va_start(argumentList, messageFormat);
	_vsnprintf_s(message, BUFFER_SIZE, BUFFER_SIZE - 1, messageFormat, argumentList);
	va_end(argumentList);

	//Windows Specific
	OutputDebugStringA(message);
	return message;
}

bool DoesFileExist(const std::string fileName)
{
	std::ifstream infile(fileName.c_str());
	return infile.good();
}

char* ReadFile(std::string filePath)
{
	std::ifstream inFile;
	inFile.open(filePath);

	std::string fileContents;

	if (inFile.is_open())
	{
		while (!inFile.eof())
		{
			std::string add;
			std::getline(inFile, add);
			fileContents.append(add + "\n");
		}
	}
	else
	{
		ConsolePrintf("Error. %s is an invalid path.\n", filePath);
	}

	char* output = new char[fileContents.size() + 1];
	output[fileContents.size()] = 0;
	memcpy(output, fileContents.c_str(), fileContents.size());

	return output;
}

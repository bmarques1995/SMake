#include "Utils/FileHandler.hh"
#include <fstream>

bool SMake::FileHandler::ReadTextFile(std::string_view path, std::string* content)
{
	bool loaded = false;
	std::ifstream fileStream;
	fileStream.exceptions(std::ifstream::badbit | std::ifstream::failbit);
	try
	{
		fileStream.open(path.data(), std::ios::binary);
		loaded = true;
	}
	catch (...)
	{
		return loaded;
	}
	auto start = fileStream.tellg();
	fileStream.seekg(0, std::ios::end);
	uint64_t fsize = fileStream.tellg() - start;
	fileStream.seekg(0, std::ios::beg);
	char* buffer = new char[fsize + 1];
	buffer[fsize] = '\0';
	fileStream.read(buffer, fsize);
	*content = buffer;
	delete[] buffer;
	return loaded;
}

bool SMake::FileHandler::WriteTextFile(std::string_view path, std::string content)
{
	bool stored = false;
	std::ofstream fileStream;
	fileStream.exceptions(std::ofstream::badbit);
	try
	{
		fileStream.open(path.data(), std::ios::out | std::ios::binary);
		stored = true;
	}
	catch (...)
	{
		return stored;
	}
	fileStream << content;
	return stored;
}

bool SMake::FileHandler::FileExists(std::string_view path)
{
	bool loaded = false;
	std::ifstream fileStream;
	fileStream.exceptions(std::ifstream::failbit);
	try
	{
		fileStream.open(path.data(), std::ios::binary);
		loaded = true;
		fileStream.close();
	}
	catch (...)
	{
	}
	return loaded;
}

#pragma once
#include <string>

class Case
{
protected:
	std::string name;

public:
	Case(const std::string& name);
	std::string& getName();
};


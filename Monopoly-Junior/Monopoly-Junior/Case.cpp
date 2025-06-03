#include "Case.h"

Case::Case(const std::string& name)
	: name(name)
{}

std::string& Case::getName()
{
	return name;
}

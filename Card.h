#pragma once
#include <string>

class Card
{
private:
	std::string text;
	short destination;

public:
	Card(const std::string& text, short destination);
	std::string getText();
	short getDestination();
};


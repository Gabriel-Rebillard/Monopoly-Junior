#include "Card.h"

Card::Card(const std::string& text, short destination):
	text(text), destination(destination)
{
}

std::string Card::getText()
{
	return text;
}

short Card::getDestination()
{
	return destination;
}

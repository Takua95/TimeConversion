#include "invalidMin.h"
#include "stdafx.h"

invalidMin::invalidMin() 
{ 
	msg = "Min is out of range!"; 
};

invalidMin::~invalidMin() {};

void invalidMin::showException() 
{ 
	std::cout << "\n\n\t" << msg; 
	util::AnyKeyToContinue();
};
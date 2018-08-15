#include "invalidHr.h"
#include "stdafx.h"

invalidHr::invalidHr()
{
	msg = "Hour is out of range!";
};

invalidHr::~invalidHr() {};

void invalidHr::showException()
{
	std::cout << "\n\n\t" << msg;
	util::AnyKeyToContinue();
};
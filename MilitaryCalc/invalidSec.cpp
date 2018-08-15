#include "invalidSec.h"
#include "stdafx.h"

invalidSec::invalidSec()
{
	msg = "Sec is out of range!";
};

invalidSec::~invalidSec() {};

void invalidSec::showException()
{
	std::cout << "\n\n\t" << msg;
	util::AnyKeyToContinue();
};
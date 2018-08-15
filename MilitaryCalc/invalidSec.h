#pragma once
#include "stdafx.h"
#include <iostream>
#include <string>
class invalidSec
{
public:
	std::string msg;

	invalidSec();
	~invalidSec();

	void showException();
};
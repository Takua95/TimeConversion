#pragma once
#include "stdafx.h"
#include <iostream>
#include <string>
class invalidHr
{
public:
	std::string msg;

	invalidHr();
	~invalidHr();

	void showException();
};
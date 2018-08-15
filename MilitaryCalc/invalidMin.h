#pragma once
#include "stdafx.h"
#include <iostream>
#include <string>
class invalidMin
{
public:
	std::string msg;

	invalidMin();
	~invalidMin();

	void showException();
};
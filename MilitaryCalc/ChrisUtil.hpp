#pragma once
#include "stdafx.h"
#include <string>
namespace util
{
	void ClearScreen();
	void Pause(int dur);
	void AnyKeyToContinue();
	void ClearInput();
	int IntChecker();
	bool Exit();
	bool Exit(std::string temp);
}
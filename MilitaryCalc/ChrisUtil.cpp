#define NOMINMAX
#include "stdafx.h"
#include "ChrisUtil.hpp"

namespace util
{
	void ClearScreen()
	{
#ifdef _WIN32
		system("cls");
#else		// Assume POSIX
		system("clear");
#endif
	}

	void Pause(int dur)
	{
		int temp = time(NULL) + dur;
		while (temp > time(NULL));
	}

	void AnyKeyToContinue()
	{
		Pause(2);
		std::cout << "\n\n\t" << std::internal << "\n\n\nPress any key to continue ...";
		ClearInput();
		_getch();
	}

	void ClearInput()
	{
		std::cin.clear();
		//Still having problems with this, it's supposed to be pretty straight-foward.  
		//It's supposed to ignore up until either a "\n" or character limit of max
		//std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	int IntChecker()
	{
		int userInput;
		ClearInput();
		std::cin >> userInput;
		while (std::cin.fail())
		{
			ClearScreen();
			std::cout << "\n\n\t" << "Error\nTry Again: \n->";
			ClearInput();
			std::cin >> userInput;
		}
		return userInput;
	}

	bool Exit()
	{
		char question = '\0';
		bool exit = false;
		do
		{
			std::cout << "\n\n\t" << "Do you want to exit? [y/n]: " << std::endl;
			question = _getch();
		} while (!std::cin.fail() && putchar(tolower(question)) != 'y' && putchar(tolower(question)) != 'n');
		if (putchar(tolower(question)) == 'y')
		{
			exit = true;
			return exit;
		}
		return exit;
	}

	bool Exit(std::string temp)
	{
		char question = '\0';
		bool exit = false;
		do
		{
			std::cout << "\n\n\t" << temp << " [y/n]: " << "\n\n->";
			question = _getch();
		} while (!std::cin.fail() && putchar(tolower(question)) != 'y' && putchar(tolower(question)) != 'n');
		if (putchar(tolower(question)) == 'y')
		{
			exit = true;
			return exit;
		}
		return exit;
	}
}
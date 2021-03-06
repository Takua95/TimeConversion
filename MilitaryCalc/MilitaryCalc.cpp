#include "stdafx.h"

void info();
void mainMenu();
void calc();

int main()
{
	system("COLOR 81");
	std::ios::sync_with_stdio(false);
	try
	{
		mainMenu();
	}
	catch (std::exception& e)
	{
		std::cout << "ERROR, Program Failed.  Code: " << &e;
	}
	util::ClearScreen();
	std::cout << "\n\n\t" << "\nGoodbye!";
	util::AnyKeyToContinue();
}

void mainMenu()
{
	int userInput = NULL;
	bool exit = false;
	while (!exit)
	{
		util::ClearScreen();
		std::cout << "\n\n" << std::setfill('-') << std::setw(41) << "Main Menu" << std::setw(42);
		std::cout 
			<< "\n\n\t" << "[1] : Calc"
			<< "\n\n\t" << "[2] : Help / Info"
			<< "\n\n\t" << "[3] : Exit"
			<< "\n\n" << std::setfill('=') << std::setw(84)
			<< "\n\n\n\t" << "Enter your choice [1-3]: ";
		userInput = util::IntChecker();
		switch (userInput)
		{
		case 1:		
			calc();
			break;
		case 2:		//Help-Info
			info();
			break;
		case 3:		//Exit program
			exit = util::Exit();
			break;
		default:
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 132);
			std::cout << "\n[That is not a valid selection.]";
			util::Pause(2);
			break;
		}
	}
}

void info()		//I added more to the info/help.  
{				//I should have for previous program, as it was a more in depth program
	util::ClearScreen();
	std::cout << std::setfill('-') << std::setw(41) << "Help / Info" << std::setw(41) << "\n\n"
		<< "\n\n\t" << "This program is intended to convert 12 hour time format"
		<< "\n\n\t" << "to 24 hour (Military) time format. The user only needs "
		<< "\n\n\t" << "to enter  the hour, minutes, and seconds (in 12hr format)"
		<< "\n\n\t" << "and specify A.M. or P.M. and the program will convert the"
		<< "\n\n\t" << "entered time to the equivelant 24 hour format.\n\n"
		<< "\n\n\t" << "This program was developed by Christian Brannon.\n\n";
	util::AnyKeyToContinue();
}

void calc()
{
	int time[3];
	bool meridiem;
	try
	{
		std::cout << "\n\n\t" << "Please enter hour [1-12]: ";
		std::cin >> time[0];
		if (time[0] <= 0 || time[0] > 12)
			throw invalidHr();

		std::cout << "\n\n\t" << "Please enter minutes [0-60]: ";
		std::cin >> time[1];
		if (time[1] > 59)
			throw invalidMin();

		std::cout << "\n\n\t" << "Please enter seconds [0-60]: ";
		std::cin >> time[2];
		if (time[2] > 59)
			throw invalidSec();

		meridiem = util::Exit("is that A.M. (Ante Meridiem)?");

		if (meridiem != true)
			time[0] = time[0] + 12;
		std::cout << "\n\n\t" << "The time in 24 hour format is: "
			<< time[0] << ":" << time[1] << ":" << time[2];
		util::Pause(4);
	}
	catch (invalidHr invHr)
	{
		invHr.showException();
	}
	catch (invalidMin invMin)
	{
		invMin.showException();
	}
	catch (invalidSec invSec)
	{
		invSec.showException();
	}
}
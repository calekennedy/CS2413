// PublicScholar.cpp : Defines the entry point for the console application.
#include "UserInterface.h"

//debugging memory leaks
#include "LinkedList.h"

using namespace std;

int main(int argc, char* argv[])
{
	UserInterface ui = UserInterface();
	ui.run();
	return 0;
}


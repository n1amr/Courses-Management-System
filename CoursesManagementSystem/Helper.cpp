#include <cstdlib>
#include "Helper.h"

void Helper::clear_screen()
{
#ifdef _WIN32
	system("cls");
#endif
#ifdef __linux__
	system("clear");
#endif
}


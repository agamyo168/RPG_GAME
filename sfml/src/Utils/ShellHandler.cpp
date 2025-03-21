#include "Utils/ShellHandler.hpp"
#include <cstdlib>
#include <iostream>

void clearShellScreen() {
#ifdef _WIN32
  int result = system("cls"); // Windows
#elif linux
  int result = system("clear");
#endif
  if (result != 0) {
    std::cerr << "Failed to clear the screen!" << std::endl;
  }
}
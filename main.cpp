//============================================================================
// Name        : main.cpp
// Author      : RWHasker
// Assignment  : CS 2040, Lab 5
// Description : Main for raider the robot
//============================================================================

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "santana.h"
#include "cell.h"

int main() {
  srand(time(0));

  int gridSize = 5;
  int fabX = rand() % gridSize;;
  int fabY = rand() % gridSize;;
  int sX = rand() % gridSize;
  int sY = rand() % gridSize;

  Santana santana(sX, sY);

  char move;
  while (true) {
    std::cout << "You're at (" << fabX << ", " << fabY << ")\n";
    std::cout << "Move (w/a/s/d): ";
    std::cin >> move;

    if (move == 'w') fabY--;
    else if (move == 's') fabY++;
    else if (move == 'a') fabX--;
    else if (move == 'd') fabX++;

    // Check boundaries
    if (fabX < 0) fabX = 0;
    if (fabY < 0) fabY = 0;
    if (fabX >= gridSize) fabX = gridSize - 1;
    if (fabY >= gridSize) fabY = gridSize - 1;

    // Check if Santana is here
    if (fabX == santana.getX() && fabY == santana.getY()) {
      std::cout << "You ran into Santana! Game Over.\n";
      break;
    }
  }

  return 0;
}
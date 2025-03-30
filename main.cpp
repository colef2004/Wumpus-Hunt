#include <iostream>
#include <cstdlib>
#include <ctime>
#include "cell.h"
#include "fab.h"
#include "santana.h"

const int gridSize = 5;

int main() {
    srand(time(0));

    // Initialize grid
    Cell* grid[gridSize][gridSize];
    for (int y = 0; y < gridSize; ++y) {
        for (int x = 0; x < gridSize; ++x) {
            grid[y][x] = new Cell(x, y, '.');
        }
    }

    // Random positions
    int fabX = rand() % gridSize;
    int fabY = rand() % gridSize;
    int sX = rand() % gridSize;
    int sY = rand() % gridSize;

    // Avoid placing Santana on Fab
    while (sX == fabX && sY == fabY) {
        sX = rand() % gridSize;
        sY = rand() % gridSize;
    }

    Fab fab(fabX, fabY);
    Santana santana(sX, sY);

    grid[fabY][fabX]->enter();
    grid[sY][sX]->setToken('#'); // Santana

    int ammoCount = 3;
    while (ammoCount > 0) {
        int ax = rand() % gridSize;
        int ay = rand() % gridSize;

        // Avoid placing on Santana or Fab
        if ((ax == fabX && ay == fabY) || (ax == sX && ay == sY)) continue;
        if (grid[ay][ax]->display() == '>') continue; // no duplicates

        grid[ay][ax]->setToken('>');
        ammoCount--;
    }

    char move;
    int ammo = 3;
    char lastMove = ' ';

    while (true) {
        std::cout << "You're at (" << fab.getX() << ", " << fab.getY() << ") | Ammo: " << ammo <<  ")\n";
        std::cout << "Move (w/a/s/d), h for help, m for map, q to quit: ";
        std::cin >> move;
        move = tolower(move);

        if (move == 'q') break;
        if (move == 'h') {
            std::cout << "Goal: Find and spray Santana (#) before he gets you!\n";
            std::cout << "Use WASD to move, 'f' to fire in your last direction.\n";
            std::cout << "'>' are ammo pickups. Avoid running into Santana.\n";
            continue;
        }


        if (move == 'm') {
            for (int y = 0; y < gridSize; ++y) {
                for (int x = 0; x < gridSize; ++x) {
                    std::cout << grid[y][x]->display() << " ";
                }
                std::cout << "\n";
            }
            continue;
        }

        // Get current pos
        int x = fab.getX();
        int y = fab.getY();

        if (move == 'f') {
            if (ammo == 0) {
                std::cout << "No ammo!\n";
                continue;
            }

            int tx = x, ty = y;
            if (lastMove == 'w') ty--;
            else if (lastMove == 's') ty++;
            else if (lastMove == 'a') tx--;
            else if (lastMove == 'd') tx++;

            if (tx >= 0 && tx < gridSize && ty >= 0 && ty < gridSize) {
                if (grid[ty][tx]->hasSantana()) {
                    std::cout << "You hit Santana! You win!\n";
                    break;
                } else {
                    std::cout << "You missed.\n";
                    ammo--;
                }
            } else {
                std::cout << "You shot into a wall.\n";
                ammo--;
            }

            continue;
        }



        // Move Fab
        grid[y][x]->vacate();
        if (move == 'w') y--;
        else if (move == 's') y++;
        else if (move == 'd') x++;
        else if (move == 'a') x--;
        else {
            std::cout << "Invalid input.\n";
            continue;
        }

        // Stay in bounds
        if (x < 0) x = 0;
        if (x >= gridSize) x = gridSize - 1;
        if (y < 0) y = 0;
        if (y >= gridSize) y = gridSize - 1;

        fab = Fab(x, y);
        lastMove = move;
        grid[y][x]->enter();

        //  febreeze  pickup
        if (grid[y][x]->hasAmmo()) {
            std::cout << "You found febreeze  spray!\n";
            ammo++;
            grid[y][x]->removeAmmo();
        }
        // Clue system
        if (abs(sX - x) + abs(sY - y) == 1)
            std::cout << "You smell something funky.\n";

        // Game over check
        if (x == sX && y == sY) {
            std::cout << "You ran into Santana! Game over.\n";
            break;
        }
    }

    // Free memory
    for (int y = 0; y < gridSize; ++y)
        for (int x = 0; x < gridSize; ++x)
            delete grid[y][x];

    return 0;
}

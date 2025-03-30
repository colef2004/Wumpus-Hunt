//
// Created by colef on 3/29/2025.
//


#include <stdio.h>
#include "santana.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

Santana::Santana(int x, int y){
    xPos = x;
    yPos = y;
}
int Santana::getX() {
    return xPos;
}

int Santana::getY() {
    return yPos;
}

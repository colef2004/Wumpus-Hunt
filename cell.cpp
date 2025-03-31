//
// Created by colef on 3/29/2025.
//

#include "cell.h"
#include "santana.h"
Cell::Cell(int x, int y, char type) {
    xLocation = x;
    yLocation = y;
    token = type;
    hasFab = false;
}
// true if Santana is at this location
bool Cell::hasSantana(){
  return token == '#';
}
// true if ammo is at this location
bool Cell::hasAmmo(){
    return token == '>';
}
// remove the ammo at this location
void Cell::removeAmmo() {
    if (token == '>') token = '.';
}
// true if the perfume store is at this location
bool Cell::hasStore(){
    return false;
}
// is this location occupied by something that the robot
char Cell::display(){
    if (hasFab) return '+';
    return token;
}
// Fab enters location
void Cell::enter(){}
// Fab leaves location
void Cell::vacate(){}
// Set the token at this location
void Cell::setToken(char t){
    token = t;
}
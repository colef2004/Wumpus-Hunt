/*
 * cell.h
 *
 *      Author: Franklin Cole
 */

#ifndef CELL_H_
#define CELL_H_

// Tracks the contents of a particular cell on the map.
// Is there gold at this location, is it occupied by a robot,
// is there a pit there? Each cell needs to track
// where it is on the grid (x, y) and the type of
// object at that location. The provided methods are suggestions;
// feel free to add/remove as needed.
class Cell {
  int xLocation, yLocation;
  char token;
  bool hasFab;
public:
  Cell(int x, int y, char type);
  // true if Santana is at this location
  bool hasSantana();
  // true if ammo is at this location
  bool hasAmmo();
  // remove the ammo at this location
  void removeAmmo();
  // true if the perfume store is at this location
  bool hasStore();
  // is this location occupied by something that the robot
  char display();
  // Fab enters location
  void enter();
  // Fab leaves location
  void vacate();
};

#endif /* CELL_H_ */

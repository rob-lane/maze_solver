/* 
 * File:   point.h
 * Author: Rob Lane
 *
 * Created on April 28, 2013, 4:59 PM
 */

#ifndef POINT_H
#define	POINT_H

struct Point { 
  int row, col;
  Point (int inrow, int incol) { 
    row = inrow;
    col = incol;
  }
};

#endif	/* POINT_H */


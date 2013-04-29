/* 
 * File:   data_structure.h
 * Author: Rob Lane
 *
 * Created on April 28, 2013, 5:07 PM
 */

#ifndef DATA_STRUCTURE_H
#define	DATA_STRUCTURE_H

#include <stack>
#include <queue>

#include "point.h"

class data_structure { 
public:
  data_structure(char& structure_type);
  ~data_structure();
  
  void push(Point p);
  void pop();
  Point next();
  bool empty();
  
protected:
  std::stack<Point> *m_s;
  std::queue<Point> *m_q;
};

#endif	/* DATA_STRUCTURE_H */


/* 
 * File:   main.cpp
 * Author: Rob Lane
 *
 * Created on April 28, 2013, 12:12 PM
 */

#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <errno.h>

#include "point.h"
#include "data_structure.h"

using namespace std;

char** maze_data = NULL;
bool** maze_visits = NULL;
data_structure* maze_solution = NULL;
int maze_rows, maze_cols = 0;

void read_maze_data(string& input_file_name);
void traverse_maze();
void print_maze();

int main(int argc, char** argv) {
  string input_file;
  cout << "Welcome to maze solver, please enter the name of the maze file to solve:";
  cin >> input_file;
  
  read_maze_data(input_file);
  traverse_maze();
  
  return 0;
}

void read_maze_data(string& input_file_name) { 
  cout << "Reading input file " << input_file_name << endl;
  
  ifstream file_stream;
  file_stream.open(input_file_name.c_str());
  if (file_stream.good()) { 
    if (maze_data) { 
      cout << "Maze already loaded...\n";
    } else { 
      char structure_type;
      file_stream >> structure_type >> maze_rows >> maze_cols;
      
      maze_data = new char * [maze_rows];
      maze_visits = new bool * [maze_rows];
      maze_solution = new data_structure(structure_type);
      for (int i = 0; i < maze_rows; i++) { 
        maze_data[i] = new char [maze_cols];
        maze_visits[i] = new bool [maze_cols];
        std::fill_n(maze_visits[i], maze_cols, false);
        file_stream >> maze_data[i];
      }
    }
  } else { 
    cout << "Error reading file " << input_file_name << endl;
  }
}

void traverse_maze()
{
  if (maze_data && maze_visits) { 
    //Get starting point and push onto solution ds.
    for (int i = 1; i <= maze_rows; i++) { 
      string row_buffer = string(maze_data[i-1]);
      if (row_buffer.find('o') != string::npos) { 
        maze_solution->push(Point(i, (int)row_buffer.find('o')));
      }
    }
    print_maze();
    cout << "Solving..." << endl;
    
    bool solved = false;
    while (!solved && !maze_solution->empty()) { 
      Point current_point = maze_solution->next();
      maze_solution->pop();
      if (maze_visits[current_point.row-1][current_point.col]) { 
        continue;
      }
      
      
      maze_visits[current_point.row-1][current_point.col] = true;
      char current_tile = maze_data[current_point.row-1][current_point.col];
      switch(current_tile) { 
        case '*':
          solved = true;
        case '.':
        case 'o':
          maze_data[current_point.row-1][current_point.col] = '@';
          if (current_point.row < maze_rows) { 
            maze_solution->push(Point(current_point.row+1, current_point.col));
          }
          if (current_point.row > 1) { 
            maze_solution->push(Point(current_point.row-1, current_point.col));
          }
          if (current_point.col < maze_cols) { 
            maze_solution->push(Point(current_point.row, current_point.col+1));
          }
          if (current_point.col > 0) { 
            maze_solution->push(Point(current_point.row, current_point.col-1));
          }
          break;
        default:
          continue;
      }
    }
    
    if (!solved) { 
      cout << "The maze could not be solved..." << endl;
    }
    print_maze();
  }
}

void print_maze() { 
  if (maze_data) { 
    for (int i = 0; i < maze_rows; i++) { 
      string maze_row = string(maze_data[i]);
      cout << maze_row << endl;
    }
  }
}

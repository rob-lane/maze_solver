The Maze Solver
===========

The Maze Solver will solve maze problems which are provided by text input files which contain character data for the maze needing to be solved.  The solver will initially display the maze in console output, then find a solution and print this to the console.  

Run the compiled program and you will be prompted for an input file, 6 of these have been included for demonstration.

Example Input
------------
    s 3 5
    #####
    #o.*#
    #####
    
The first row contains the data-structure type
's' - Solve with a stack
'q' - Solve with a queue

The second and third numbers are the number of rows and columns in the maze

Maze Characters
----------------------------
 * 'o' - The start of the maze
 * '#' - A wall
 * '.' - An open space (traversable)
 * '*' - The end of the maze
 * '@' - Filled in when a space is visited, only displayed in the solution

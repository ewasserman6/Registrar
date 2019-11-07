/*
Sammie Walker
Eric Wasserman
2315055
2300841
ewasserman@chapman.edu
swalker@chapman.edu
CPSC 350 - 03
Assignment 4
*/


#include <iostream>
//#include "GenQueue.h"

using namespace std;

class Student{
public:
  Student();
  ~Student();
  Student(int arrived, int window);

  int timeArrived;
  int timeSpentAtWindow; // time needed
  int timeInLine; // wait time

  int timeDoneAtWindow; // so that we can keep track of idle time
};

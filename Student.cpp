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


#include "Student.h"
#include <iostream>

using namespace std;

Student::Student(){
  timeArrived = 0;
  timeSpentAtWindow = 0;
  timeInLine = 0;
  timeDoneAtWindow = 0;
}

Student::Student(int arrived, int window){
  timeArrived = arrived;
  timeSpentAtWindow = window;
  timeInLine = 0;
  timeDoneAtWindow = 0;
}

Student::~Student(){
}

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
#include <fstream>
#include "Student.h"
#include "GenQueue.h"

using namespace std;

class Registrar{
public:

  Registrar();
  ~Registrar();

  int windowPush(Student studentQueue, Student windowArray, int idleTimeArray, int globalTime);

  GenQueue<Student*> studentQueue;
  Student* *windowArray;
  Student* *completeArray;
  int* idleTimeArray;

  int totalWindowsOpen;
  int totalNumStudents;

private:

  int numOfStudentsArrived;
  int type; // what type of line were looking at
  int timeArrived;
  int timeSpentAtWindow;

};

Registrar::Registrar(){

    int totalWindowsOpen = 0;
    int totalNumStudents = 0;
    int numOfStudentsArrived = 0;
    int type; // what type of line were looking at
    Student* *windowArray;
    int timeArrived;
    int timeSpentAtWindow;


}

Registrar::~Registrar(){
  delete[] windowArray;
}


/* This funciton is going to loop through the studentQueue, and if the arrival time equals the global time
and there's open windows, push to the window array


int Registrar::windowPush(Student studentQueue, Student windowArray, int idleTimeArray, int globalTime){
  while(!studentQueue.isEmpty()){
//  for(int i = 0; i < studentQueue.size(); i++){
    if(timeArrived == globalTime){
      // check for open windows, iterate through windowArray
      for(int i = 0; i < windowArray.getSize(); i++){
        if(windowArray[i].isEmpty()){
          // add students to the windowArray and take them out of studentQueue
          Student removedStudent = studentQueue.deleteNode();
          windowArray[i] = removedStudent;
        }
      }
    }
  }
  return windowArray;
}

// this should return the done array
int Registrar::loopWindow(Student studentQueue, Student windowArray, int idleTimeArray, int globalTime){
  for(int i = 0; i < windowArray.size(); i++){
    // decrease each student in the arrays time
    if(windowArray[i] != NULL){
      timeSpentAtWindow -- // for that student
    }
    else{
      // incerease the idle time for that window
      idleTimeArray[i]++;
    }
    if(timeSpentAtWindow == 0){
      // push student into a complete array

    }
  }

}
*/

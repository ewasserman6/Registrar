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
#include <string>
#include <iostream>
#include "Registrar.h"

using namespace std;

int totalWindowsOpen;
int totalNumStudents;
int numOfStudentsArrived;
int type = 1; // what type of variable is on the line were looking at (time arrived, students arrived, etc.)
int timeArrived;
int timeSpentAtWindow;
int idleTime;
int x = 0;

int globalTime = 0;

Student* *windowArray;
Student* *studentServedArray;

int *idleTimeArray;
GenQueue<Student*> studentQueue;

// this function checks to see if the window array is empty so we can break out of our clock loop
bool checkEmpty(Student** array, int array_length) {
    for (int i = 0; i < array_length; i++) {
        cout << array[i] -> timeSpentAtWindow << endl;
        cout << array[i] << endl;
        //if (array[i].timeSpentAtWindow >= 0 && array[i] -> timeArrived > 0) {
            //return false;
        //}
    }
    return true;
}

int main(int argc, char **argv){

  Registrar r; // create an instance of the Registrar class

  if(argc > 1){

    string inputFile = argv[1]; // our input file should be the first argument entered by the user
    string line; // this variable stores what we are reading in
    int lineNum = 1; // this variable keeps track of what line we are on

    ifstream inFile;
    inFile.open(inputFile);

    if(inFile.is_open()){
      while(!inFile.eof()){ // while we haven't reached the end of our file...
        try{
          getline(inFile, line);

          totalWindowsOpen = stoi(line); // convert first line (total number windows open during simulation from a string to an integer)

          windowArray = new Student*[totalWindowsOpen]; // create an array of students thats the size of the amount of windows we have, can't grow
          idleTimeArray = new int[totalWindowsOpen]; // create an array to store idle time. should also only be the size of the windows given

          // put new students into the array as they come, as long as the amount doesn't exceed the amount of windows available
          for(int i = 0; i < totalWindowsOpen; i++){
            Student* s = new Student(); // create a new student
            windowArray[i] = s; // put this student into the windowArray
          }
          lineNum++;
        }

        catch(std::exception& e){
          std::cerr << "There is an error reading in the file. " << endl; // error catching
          exit(EXIT_FAILURE);
        }

        while(getline(inFile, line)){
          try{

            switch(type){
              // what time the students arrive at
              case(1):
              // if(line != ""){ // how many students showed up
                  cout << "case 1" << endl;
                  timeArrived = stoi(line);
                  lineNum++;
                  cout << "Time arrived: " << timeArrived << endl;
                  type++;
                  break;
                //  }

                break;

              case(2):
                if(line != ""){ // how many students showed up

                  cout << "case 2" << endl;
                  numOfStudentsArrived = stoi(line);
                  cout << "Number of students: " << numOfStudentsArrived << endl;

                  for(int i = 0; i < numOfStudentsArrived; i++){ // for the amount of students that showed up, store their needed time at a window into timeSpentAtWindow
                    getline(inFile, line);
                    lineNum++;

                    timeSpentAtWindow = stoi(line);
                    cout << "Time needed at window: " << timeSpentAtWindow << endl;

                    totalNumStudents ++; // keep track of how many students have come in total

                    Student* s = new Student(timeArrived, timeSpentAtWindow);
                    studentQueue.insert(s); // add this student to a queue to keep track of all the students at windows
                  }
                }
                type = 1; // next line will be the new time, go back to start
            }
          }
          catch(const std::invalid_argument& ia){
            std::cerr << "Invalid argument: " << ia.what() << endl; // error catching
        }
      }
    }
  }
      else{
      // file did not open
      cout << "Error opening file. " << endl;
      return false;
      }
  }

bool isEmpty = checkEmpty(windowArray, totalNumStudents);

while(x < 20){ // while studentQueue isnt empty
  x++;
  globalTime ++; // increment the total time so we can remove students if necessary
  bool foundWindow = false;

  //while(!studentQueue.isEmpty()){
  cout << "SIZE: " << studentQueue.getSize() << endl;
  for(int i = 0; i < studentQueue.getSize(); i++){
    Student* s_curr = studentQueue.getHead();
    cout << "ARRIVAL TIME: " << s_curr -> timeArrived << endl;
    cout << "GLOBAL TIME: " << globalTime << endl;
    if(s_curr -> timeArrived == globalTime){
      // check for open windows, iterate through windowArray
      for(int j = 0; j < totalWindowsOpen; j++){
        if(windowArray[j] -> timeArrived == 0){
          cout << "Empty Window" << windowArray[j] ->timeArrived << endl;

          // add students to the windowArray and take them out of studentQueue
          Student* removedStudent= studentQueue.deleteNode();
          cout << "Size2: " << studentQueue.getSize() << endl;
          windowArray[j] = removedStudent;
          break;
        }
      }
    }
  }
  for(int i = 0; i < totalWindowsOpen; i++){
      cout << "Entered for loop " << endl;
    // decrease each student in the arrays time
    if(windowArray[i]->timeSpentAtWindow > 0){
      cout << "right before time decrement" << endl;
      timeSpentAtWindow --; // for that student
      cout << "TimeSPent at Window" <<timeSpentAtWindow <<  endl;
    }
    else if(windowArray[i]->timeSpentAtWindow == 0 && windowArray[i]->timeArrived > 0){
        cout << "right before push student to done array" << endl;
      // push student into a complete array
       studentServedArray[i] = windowArray[i];

        }

    else{
      // incerease the idle time for that window
      idleTimeArray[i]++;
      cout << "Idle time: "<< idleTimeArray[i] << endl;
    }
  }
}


}
/*
Call all metrics functions right here */

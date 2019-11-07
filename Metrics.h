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

using namespace std;

class Metrics{
public:

  int meanStudentWaitTime(int studentServedArray);
  double medianStudentWaitTime(int studentServedArray);
  int longestStudentWaitTime(int studentServedArray);
  int studentsWaitingOverTen(int studentServedArray);
  int meanWindowIdleTime(int idleTimeArray);
  int longestWindowIdleTime(int idleTimeArray);
  int numWindowsIdleOver5(int idleTimeArray)

};

int Metrics::meanStudentWaitTime(int studentServedArray){
  // iterate over array
  int total;
  int count;
  for(int i=0; i < studentServedArray.size(); i++){
    count++;
    total += studentServedArray->timeInLine[i];
  }
  int mean = total/count;
  return mean;
}

double Metrics::medianStudentWaitTime(int studentServedArray){
  // sort array
  double median;
  double n = sizeof(studentServedArray->timeInLine)/sizeof(studentServedArray->timeInLine[0]);
  sortedStudentServedArray = sort(studentServedArray->timeInLine, studentServedArray->timeInLine+n);

  double half = sortedStudentServedArray.size()/2;
  if(sortedStudentServedArray.size()%2 == 0){ // means its an even number
    median = sortedStudentServedArray[half];

  }
  else{ // means its an odd number
    median = sortedStudentServedArray[half + 0.5];

  }
  return median;
}

int Metrics::longestStudentWaitTime(int studentServedArray){
  int counter;

  // sort aray
  int n = sizeof(studentServedArray->timeInLine)/sizeof(studentServedArray->timeInLine[0]);
  sortedStudentServedArray = sort(studentServedArray->timeInLine, studentServedArray->timeInLine+n);

  for(int i = o; i < studentServedArray.size(); i++){
    counter++;
  }
  return sortedStudentServedArray[counter];
}

int Metrics::studentsWaitingOverTen(int studentServedArray){

  int count;

  // sort aray
  int n = sizeof(studentServedArray->timeInLine)/sizeof(studentServedArray->timeInLine[0]);
  sortedStudentServedArray = sort(studentServedArray->timeInLine, studentServedArray->timeInLine+n);

  for(int i = 0; i < studentServedArray.size(); i++){
    if(studentServedArray[i] > 10){
      count++;
    }

  }
  return count;

}


int Metrics::meanWindowIdleTime(int idleTimeArray){
  int total;
  int count;
  for(int i=0; i < idleTimeArray.size(); i++){
    count++;
    total += idleTimeArray;
  }
  int mean = total/count;
  return mean;
}

int Metrics::longestWindowIdleTime(int idleTimeArray){
  // sort aray
  int n = sizeof(idleTimeArray)/sizeof(idleTimeArray[0]);
  sortedIdleTimeArray = sort(idleTimeArray, idleTimeArray+n);

  int count;
  for(int i = o; i < sortedIdleTimeArray.size(); i++){
    count++;
  }
  return sortedIdleTimeArray[counter];
}

int Metrics::numWindowsIdleOver5(int idleTimeArray){
  // sort aray
  int n = sizeof(idleTimeArray)/sizeof(idleTimeArray[0]);
  sortedIdleTimeArray = sort(idleTimeArray, idleTimeArray+n);

  int count;
  for(int i = 0; i < idleTimeArray.size(); i++){
    if(idleTimeArray[i] > 5){
      count++;
    }
  }
  return count;


}

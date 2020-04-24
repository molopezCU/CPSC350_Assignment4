/*
Moises Lopez
2297564
molopez@chapman.edu
350-02
Assignment 4
*/

#include <iostream>
#include <cstring>
#include "Registrar.h"

using namespace std;

int main(int argc, char** argv){
  //checks for correct number of arguments in command line
  if (argc == 1)
  {
    cout << "Please enter the following: file name or file path." << endl;
    return -1;
  }

  if (argc >= 3)
  {
    cout << "Too many arguments have been entered. Please only enter one file name \n[EXAMPLE] --> main.cpp userFile.cpp." << endl;
    return -1;
  }

  Registrar r;
  string file = argv[1];

  int currTime = 0;
  int openWindows = 0;

  bool running = true;

  if(r.inputFile(file)){
    while(running){
      if(r.studentQueue.isEmpty()){
        int temp = 0;

        for(int i = 0; i < r.totalWindows; ++i){
          if((r.windowArray[i] -> windowTime) < 1){
            temp++;
          }
        }

        if(temp == r.totalWindows){
          running = false;
        }
      }
      for(int i = 0; i < r.totalWindows; ++i){
        if(r.windowArray[i]->windowTime < 1){
          if(!r.studentQueue.isEmpty()){
            Students* student = r.studentQueue.tFront();

            if(student->entryTime <= currTime){
              if(r.windowArray[i]->idleTime > 0){
                r.idleStats.enqueue(r.windowArray[i]->idleTime);
              }

              r.windowArray[i] = r.studentQueue.dequeue();
              r.waitStats.enqueue(r.windowArray[i]->queueTime);
            }
          }
        }
      }

      currTime++;
      r.overallTimeTracker(currTime);
    }

    for(int i = 0; i < r.totalWindows; ++i){
      if(r.windowArray[i]->idleTime > 0){
        r.idleStats.enqueue(r.windowArray[i]->idleTime);
      }
    }

    cout << "=== Registrar Completed ===" << endl;
    cout << " Student calculations:" << endl;
    cout << " Mean student wait time: " << r.meanTime() << " minutes" << endl;
    cout << " Median student wait time: " << r.medianTime() << " minutes" << endl;
    cout << " Longest student wait Time: " << r.longestTime() << " minutes" << endl;
    cout << " Students Waiting >10Minutes: " << r.timesOverTen() << " times" << endl;

    cout << "\n=== Registrar Window Related Calculations ===" << endl;
    cout << " Mean Window Idle Time: " << r.meanIdleTime() << " minutes" << endl;
    cout << " Longest Window Idle Time: " << r.longestIdleTime() << " minutes" << endl;
    cout << " Idle Time >5 Minutes: " << r.timesIdleOverFive() << " times\n" << endl;
  }
  return 0;
}

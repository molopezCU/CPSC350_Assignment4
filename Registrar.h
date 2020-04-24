/*
Moises Lopez
2297564
molopez@chapman.edu
350-02
Assignment 4
*/

#include <iostream>
#include <cstring>
#include "Students.h"
#include "GenQueue.h"

using namespace std;

class Registrar{
  private:
    int type; //choose type based on line order (student/time/clock)
    int entryTime;
    int timeAtWindow;
    int idleCount; //Idle Array Element Count
    int medianCount; //Median Array Element Count
    int numStudentsPerClockTick; //Number of Students at Each Clock Tick

  public:
    Registrar(); //constructor
    ~Registrar(); //destructor

    bool inputFile(string file); //reads in the file

    bool overallTimeTracker(int t); //keeps track of overall time

    //variables for calculating student time
    double meanTime();
    double medianTime();
    int longestTime();
    int timesOverTen();

    //variables for calculating window/registrar time
    double meanIdleTime();
    int longestIdleTime();
    int timesIdleOverFive();

    Students* *windowArray; //keeps track of students at the windows

    GenQueue<Students*> studentQueue; //queue of students

    GenQueue<int> waitStats;
    GenQueue<int> idleStats;

    int *medianArrary;
    int *idleArray;

    int totalWindows;
    int totalStudents;
};

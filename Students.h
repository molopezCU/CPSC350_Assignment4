/*
Moises Lopez
2297564
molopez@chapman.edu
350-02
Assignment 4
*/

#include <iostream>

using namespace std;

class Students{
  private:

  public:
    Students();
    Students(int t, int e);
    ~Students();

    int windowTime;
    int entryTime;
    int queueTime;
    int idleTime;
};

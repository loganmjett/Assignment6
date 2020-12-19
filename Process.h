#include <iostream>
#include <fstream>
using namespace std;

class Process
{
 public:

   //constructors
   Process(string input, string output);

   //destructor
   ~Process();

   //helpers
   //reads line from file to be examined
   string readLine();
   //writes out the issues found
   void writeLine(string line);
   //establishes file streams to be used for input and output
   ifstream inFile;
   ofstream outFile;
};

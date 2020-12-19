#include "Process.h"
#include <iostream>
#include <fstream>

using namespace std;

Process::Process(string input, string output)
{
  inFile.open(input);
  outFile.open(output);
}

Process::~Process()
{
  inFile.close();
  outFile.close();
}

string Process::readLine()
{
  string line = "";

  while(getline(inFile, line))
  {
    return line;
  }
}

void Process::writeLine(string line)
{
  outFile << line << endl;
}

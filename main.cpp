#include "Sorting.h"
#include <iostream>

int main(int argc, char const *argv[])
{
  if (argc > 1)
  {
    Sorting mySorter = Sorting(argv[1]);
    cout << "\n***** STANDBY FOR SORTING ALGORITHMS *****" << endl;
    mySorter.runSort();
    cout << "\n***** SORTING COMPLETE *****\n" << endl;
  }
  else
  {
    cout << "\nNo file was provided, but let's build one for next time!" << endl;

    string file;
    string desiredSize;

    cout << "\nEnter the file to write to:" << endl;
    cin >> file;
    cout << "\nEnter the size to use:" << endl;
    cin >> desiredSize;

    Process *fileCreator = new Process("", file);

    fileCreator->writeLine(desiredSize);

    for (int i = 0; i < stoi(desiredSize); ++i)
    {
      fileCreator->writeLine(to_string(stoi(desiredSize) - i));
    }

    delete fileCreator;

    cout << "\nPlease retry program with the file: " << file << " that was just created!"<< endl;
  }

  cout << "\nExiting Program...\n" << endl;

  return 0;
}

#include "Sorting.h"
#include <iostream>

Sorting::Sorting(string inputFile)
{
  infile = new Process(inputFile, "");
  size = stoi(infile->readLine());
  forBubble = new double[size];
  forInsertion = new double[size];
  forSelection = new double[size];
  forQuick = new double[size];
  forMerge = new double[size];

  for (int i = 0; i < size; ++i)
  {
    string numVal = infile->readLine();
    if (numVal != "")
    {
      forBubble[i] = stod(numVal);
      forInsertion[i] = stod(numVal);
      forSelection[i] = stod(numVal);
      forQuick[i] = stod(numVal);
      forMerge[i] = stod(numVal);
    }
  }
}

Sorting::~Sorting()
{
  delete forBubble;
  delete forInsertion;
  delete forSelection;
  delete forQuick;
  delete forMerge;

  delete infile;
}

void Sorting::bubbleSort(double a[])
{
  cout << "\nBubble Sort: " << endl;
  time_t currTime = time(0);
  tm* localTime = localtime(&currTime);
  cout << "Start: " << asctime(localTime);

  for (int i = 0; i < this->size - 1; ++i)
  {
    for (int j = 0; j < this->size - 1; ++j)
    {
      if (a[j] > a[j+1])
      {
        double placeholder = a[j];
        a[j] = a[j+1];
        a[j+1] = placeholder;
      }
    }
  }

  currTime = time(0);
  localTime = localtime(&currTime);
  cout << "Finish: " << asctime(localTime);
}

void Sorting::insertionSort(double a[])
{
  cout << "\nInsertion Sort: " << endl;
  time_t currTime = time(0);
  tm* localTime = localtime(&currTime);
  cout << "Start: " << asctime(localTime);

  for (int i = 1; i < this->size; ++i)
  {
    double placeholder = a[i];
    int j = i - 1;
    while (j >= 0 && a[j] > placeholder)
    {
      a[j+1] = a[j];
      j--;
    }
    a[j+1] = placeholder;
  }

  currTime = time(0);
  localTime = localtime(&currTime);
  cout << "Finish: " << asctime(localTime);
}

void Sorting::selectionSort(double a[])
{
  cout << "\nSelection Sort: " << endl;
  time_t currTime = time(0);
  tm* localTime = localtime(&currTime);
  cout << "Start: " << asctime(localTime);

  for (int i = 0; i < size - 1; ++i)
  {
    int index = i;
    for (int j = i + 1; j < size; j++)
    {
      if (a[j] < a[index])
      {
        index = j;
      }
    }
    double placeholder = a[index];
    a[index] = a[i];
    a[i] = placeholder;
  }

  currTime = time(0);
  localTime = localtime(&currTime);
  cout << "Finish: " << asctime(localTime);
}

void Sorting::quickSort(double a[], int low, int high)
{
  //since this is recursive, the start and end times are called in the constructor

  if (low < high)
  {
    int pIndex = partition(a, low, high);
    quickSort(a, low, pIndex - 1);
    quickSort(a, pIndex + 1, high);
  }
}

void Sorting::mergeSort(double a[], int low, int high)
{
  int midpoint = 0;

  if (low < high)
  {
    midpoint = (low + high) / 2;

    mergeSort(a, low, midpoint);
    mergeSort(a, midpoint + 1, high);

    merge(a, low, midpoint, high);
  }
}

int Sorting::partition(double a[], int low, int high)
{
  double pValue = a[high];
  int i = (low - 1);

  for (int j = low; j <= high - 1; j++)
  {
    if (a[j] <= pValue)
    {
      i++;
      double placeholder = a[i];
      a[i] = a[j];
      a[j] = placeholder;
    }
  }

  double placeholder = a[i+1];
  a[i+1] = a[high];
  a[high] = placeholder;

  return (i + 1);
}

void Sorting::merge(double a[], int i, int j, int k)
{
  int sizeOfMerge = k - i + 1;
  int mergePosition = 0;
  int left = 0;
  int right = 0;
  double* mergedItems = new double[sizeOfMerge];
  left = i;
  right = k;

  while (left <= j && right <= k)
  {
    if (a[left] <= a[right])
    {
      mergedItems[mergePosition] = a[left];
      left++;
    }
    else
    {
      mergedItems[mergePosition] = a[right];
      right++;
    }
    mergePosition++;
  }

  while (left <= j)
  {
    mergedItems[mergePosition] = a[left];
    ++left;
    ++mergePosition;
  }

  while (right <= k)
  {
    mergedItems[mergePosition] = a[right];
    ++right;
    ++mergePosition;
  }

  for (mergePosition = 0; mergePosition < sizeOfMerge; ++mergePosition)
  {
    a[i + mergePosition] = mergedItems[mergePosition];
  }
}
void Sorting::runSort()
{
  bubbleSort(forBubble);

  insertionSort(forInsertion);

  selectionSort(forSelection);

  //included because of recursion
  cout << "\nQuick Sort: " << endl;
  time_t currTime = time(0);
  tm* localTime = localtime(&currTime);
  cout << "Start: " << asctime(localTime);

  quickSort(forQuick, 0, size - 1);
  //included because of recursion
  currTime = time(0);
  localTime = localtime(&currTime);
  cout << "Finish: " << asctime(localTime);

  //included because of recursion
  cout << "\nMerge Sort: " << endl;
  currTime = time(0);
  localTime = localtime(&currTime);
  cout << "Start: " << asctime(localTime);

  mergeSort(forMerge, 0, size - 1);

  //included because of recursion
  currTime = time(0);
  localTime = localtime(&currTime);
  cout << "Finish: " << asctime(localTime);
}

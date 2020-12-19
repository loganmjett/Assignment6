#include "Process.h"

class Sorting
{
public:
  Sorting(string inputFile);
  ~Sorting();

  //sorting algorithms
  void bubbleSort(double a[]);
  void insertionSort(double a[]);
  void quickSort(double a[], int low, int high);
  void selectionSort(double a[]);
  void mergeSort(double a[], int low, int high); //FIXME


  //helpers
  int partition(double a[], int low, int high);
  void merge(double a[], int i, int j, int k); //FIXME
  void runSort();

  //helper variables
  Process *infile;
  int size;
  double *forBubble;
  double *forInsertion;
  double *forQuick;
  double *forSelection;
  double *forMerge;
};

#include <iostream>
#include <vector>
#include <cstdlib>
#include <sys/time.h>

using namespace std;

//Main functions
int selectionSort(vector <int>);
void quicksort(vector<int> & vec, int start, int finish);
void mergepart2(vector<int> & vec);
int insertionSort(vector <int> vec);

//Assistant functions
void mergepart1(vector<int> & vec, vector<int> & v1, vector<int> & v2);
void sort(vector<int> & vec);
int partition(vector<int> & vec, int start, int finish);
void createRandomVector(vector <int> &vec);
int seeVector(vector<int> vec);



int main()
/*
  Purpose: To execute and take in user input to determine what sort to use
  Parameters: none
  Return Value: 0
  Description: It uses a switch case statement to determine which sort to use based on user input
                  with each case, it calls the desired sort, times the execution of the sort, and prints out the sorted
                  vector and displays the time elapsed. it also calls a function that created a randomized vector and stores
                  it in a vector called numbers.
*/
{
  srand(time(NULL));

  int value;
  vector <int> numbers;
  createRandomVector(numbers);
  cout << "Enter: \n 1 for selectionSort \n 2 for quickSort \n 3 for mergeSort  \n 4 for insertionSort \n - - - - - - - - - - \n Please enter value: ";
  cin >> value;
  int count;


  timeval timeBefore, timeAfter;    // timeval type defined in sys/time.h
  long diffSeconds, diffUSeconds;   // elapsed seconds and microseconds

  switch (value)
  {
      case 1:
        {

          gettimeofday(&timeBefore, NULL);  // get the time before
          selectionSort(numbers);
          gettimeofday(&timeAfter, NULL);   // get the time after
          diffSeconds = timeAfter.tv_sec - timeBefore.tv_sec;    // elapsed seconds
          diffUSeconds = timeAfter.tv_usec - timeBefore.tv_usec; // elapsed microseconds
          double time = diffSeconds + diffUSeconds / 1000000.0;  // total elapsed time

          cout << endl << "Total elapsed time: " << time << endl;

        }
          break;

      case 2:
        {

            gettimeofday(&timeBefore, NULL);  // get the time before
            sort(numbers);
            seeVector(numbers);
            gettimeofday(&timeAfter, NULL);   // get the time after
            diffSeconds = timeAfter.tv_sec - timeBefore.tv_sec;    // elapsed seconds
            diffUSeconds = timeAfter.tv_usec - timeBefore.tv_usec; // elapsed microseconds
            double time = diffSeconds + diffUSeconds / 1000000.0;  // total elapsed time

            cout << endl << "Total elapsed time: " << time << endl;

        }
          break;

    case 3:
      {

          gettimeofday(&timeBefore, NULL);  // get the time before
          mergepart2(numbers);
          seeVector(numbers);
          gettimeofday(&timeAfter, NULL);   // get the time after
          diffSeconds = timeAfter.tv_sec - timeBefore.tv_sec;    // elapsed seconds
          diffUSeconds = timeAfter.tv_usec - timeBefore.tv_usec; // elapsed microseconds
          double time = diffSeconds + diffUSeconds / 1000000.0;  // total elapsed time


          cout << endl << "Total elapsed time: " << time << endl;
      }
        break;

    case 4:
      {

        gettimeofday(&timeBefore, NULL);  // get the time before
        insertionSort(numbers);
        gettimeofday(&timeAfter, NULL);   // get the time after
        diffSeconds = timeAfter.tv_sec - timeBefore.tv_sec;    // elapsed seconds
        diffUSeconds = timeAfter.tv_usec - timeBefore.tv_usec; // elapsed microseconds
        double time = diffSeconds + diffUSeconds / 1000000.0;  // total elapsed time

        cout << endl << "Total elapsed time: " << time << endl;

      }
      break;

    default:
      cout << "ERROR" << endl;

  }

  return 0;

}

//FOR INSERTIONSORT
int insertionSort(vector <int> vec)
/*
  Purpose: To perform insertion sort on a given vector with random numbers
  Parameters: Vector containing integers
  Return Value: None
  Description: It takes in randomized vector and iterates through the values. With each iteration, it saves the value at the current
                index into the variable x and the iteration amount as the value y. Then while y is less greater than 0 and the index at
                y-1 is  greater than x, it saves the index at y as the previous index. I then subtracts one from y. It then calls seeVector
                in order to print out the sorted contents
*/
{
  int x;
  int y;
  for(int i = 1; i < vec.size(); i++)
  {
    x = vec[i];
    y = i;
    while(y > 0 && vec[y-1] > x)
    {
      vec[y] = vec[y - 1];
      y -= 1;
    }
  }
  seeVector(vec);
}

//FOR MERGESORT
void mergepart2(vector<int> & vec)
/*
  Purpose: To sort an unsorted vector via merging method
  Parameters: An unsorted vector filled with numbers
  Return Value: None
  Description: It divides the given vector into 2 parts, it then sorts each smaller parts
                  via calling itself again and again. The last step is to merge the sorted vectors back into one
                  sorted vector.
*/
{
  int n = vec.size();
  if (n <= 1) return;
    vector <int> v1;
    vector <int> v2;
  for (int i = 0; i < n; i++)
  {
    if (i < n / 2)
    {
      v1.push_back(vec[i]);
    }
    else
    {
      v2.push_back(vec[i]);
    }
  }
  mergepart2(v1);
  mergepart2(v2);
  vec.clear();
  mergepart1(vec, v1, v2);
}

void mergepart1(vector<int> & vec, vector<int> & v1, vector<int> & v2)
/*
  Purpose: To sort an unsorted vector via merging method
  Parameters: 3 vectors
  Return Value: None
  Description: It merges two sorted vectors into one vector.
*/
{
  int n1 = v1.size();
  int n2 = v2.size();
  int p1 = 0;
  int p2 = 0;
  while (p1 < n1 && p2 < n2)
  {
    if (v1[p1] < v2[p2])
    {
      vec.push_back(v1[p1++]);
    }
     else
     {
       vec.push_back(v2[p2++]);
     }
   }
   while (p1 < n1)
    vec.push_back(v1[p1++]);
  while (p2 < n2)
    vec.push_back(v2[p2++]);
}

//FOR SELECTIONSORT
int selectionSort(vector <int> vec)
/*
  Purpose: It sorts an unsorted vector using the selection sort method
  Parameters: Vector that is unsorted
  Return Value: None
  Description: It iterates through each index in the unsorted vector. As it goes, it compares every value at the index with the
                    value it is being compared to. Then if it is less than or greater than it switches those two values, and keeps going
                    until the end.
*/
{
  for (int a = 0; a < vec.size(); a++)
    {
      int b = a;
      for (int i = a + 1; i < vec.size(); i++)
        {
          if (vec[i] < vec[b])
            b = i;
        }
      int temp = vec[a];
      vec[a] = vec[b];
      vec[b] = temp;
    }
  seeVector(vec);
}

//FOR QUICKSORT
void sort(vector<int> & vec)
/*
  Purpose: To call the quickSort function
  Parameters: A vector
  Return Value: None
  Description: This function is a wrapper function that calls quickSort
*/
{
  quicksort(vec, 0, vec.size() - 1);
}
void quicksort(vector<int> & vec, int a, int b)
/*
  Purpose: To sort an unsorted vector via the quickSort method
  Parameters: Vector, int a and int b
  Return Value: None
  Description: It partitions the vector so that the numbers on the left are smaller than the pivot, and the numbers
                  on the right are greater than the pivot
*/
{
  if (a >= b)
    return;
  int boundary = partition(vec, a, b);
  quicksort(vec, a, boundary - 1);
  quicksort(vec, boundary + 1, b);
}
int partition(vector<int> & vec, int a, int b)
/*
  Purpose: To rearrange the elemnts of the vector so that the elements smaller than the pivot are on the left anf
              elements larger than the pivot are on the right.
  Parameters: Vector, int a, int b
  Return Value: lh
  Description:
*/
{
  int pivot = vec[a];
  int lh = a + 1;
  int rh = b;
  while (true)
  {
    while (lh < rh && vec[rh] >= pivot)
    rh--;
    while (lh < rh && vec[lh] < pivot)
    lh++;
    if (lh == rh) break;
    int tmp = vec[lh];
    vec[lh] = vec[rh];
    vec[rh] = tmp;
  }
  if (vec[lh] >= pivot)
  return a;
  vec[a] = vec[lh];
  vec[lh] = pivot;
  return lh;
}

//EQUIPMENT FOR EVERY FUNCTION
void createRandomVector(vector<int> &vec)
/*
  Purpose: To fill a vector with random numbers which the amount of numbers in the vector should not exceed the value inputted for i
              being less that that value
  Parameters: None
  Return Value: Number
  Description: It Generates random numbers, and for every value generated, that number is pushed back, thus creating an unsorted array
*/
{//for(int x = 0; x < 100001; x++)
  {
    for(int i = 0; i < 100000; i++)
    {
      double x = random() % 10;              //Stores the variable x as the random generated number modulo 200
      vec.push_back(x);
   }
 }
}

int seeVector(vector <int> vec)
/*
  Purpose: To print out the contents ofa previously sorted vector
  Parameters: A sorted Vector
  Return Value: None
  Description: It prints out the value at each index, printing out a | to see where the number ends

                and the new number begins.
*/
{
  for(int i = 0; i < vec.size(); i++)
  {
    cout << vec[i] << " | " ;
  }
}

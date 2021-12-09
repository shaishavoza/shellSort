#include <stdio.h>

// function for printing array
void printArray(int array[], int size) 
{
  for(int i = 0; i < size; i++)
	{
    printf("%d  ", array[i]);
	}
}

// function for cool sort
void coolSort(int array[], int n) 
{
  for(int stepSize = 5; stepSize > 0; stepSize = stepSize - 2) 
  {
    for(int i = stepSize; i < n; i++) 
	{
      int j;
	  //j=j-stepSize so that I can also check for previous element at the same gap
      for(j = i - stepSize; j >= 0 ; j = j - stepSize) 
	  {
		//breaking loop here as if this is true, no swapping needs to be done and i and j need to increment else swap 
        if(array[j + stepSize] > array[j])
			break;
		else 
		{
			int temp = array[j];
			array[j] = array[j + stepSize];
			array[j + stepSize] = temp;
		}
      }
    }
	//printing array after each stepsize as to see what is exactly happening
	printf("\nPartially sorted array after stepsize %d\n",stepSize);
	printArray(array, n);
  }
}

int main() 
{
  int array[] = {25,32,19,13,36,8,11,7,1};
  //int array[] = {31,23,45,7,12,54,67,2,98};
  int size = sizeof(array) / sizeof(array[0]);
  coolSort(array, size);
  printf("\ncoolSorted Array: \n");
  printArray(array, size);
  printf("\n\n");
}
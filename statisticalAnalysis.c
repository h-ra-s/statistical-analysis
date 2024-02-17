/*
Heather Slanec
Manipulate numbers in an array
Statistical Analysis Program
*/

#include<stdio.h>

//defined constant
#define MAX 10

//functions
void getData(int array[MAX]);
void displayData(int array[MAX]);
void displayLargest(int array[MAX]);
void displaySmallest(int array[MAX]);
void displayAverage(int array[MAX]);
void displayRange(int array[MAX]);
void displayMedian(int array[MAX]);
void displayMode(int array[MAX]);//mode is not mandatory


//main-------------------------------------------------------------------------
int main()
{
	//declare array
	int array[MAX];
		
	//run functions
	getData(array);
	displayData(array);
	displayLargest(array);
	displaySmallest(array);
	displayAverage(array);
	displayRange(array);
	displayMedian(array);
	displayMode(array);//mode is not mandatory

	return 0;
}

//functions---------------------------------------------------------------------------
void getData(int array[MAX])
{
	//declare variable to avoid weird error when defining in FOR
	int x;
	
	for (x = 0; x < MAX; x++)
	{
		printf("Enter an integer: ");
		scanf("%d", &array[x]);
	}
}

//display data function-------------------------------------------------------
void displayData(int array[MAX])
{
	//declare variable to avoid weird error when defining in FOR
	int x;
	
	//newline character for formatting
	printf("\n");
	
	//print each seat in array
	for (x = 0; x < MAX; x++)    
		printf("%d ", array[x]);
}

//largest number function-----------------------------------------------------
void displayLargest(int array[MAX])
{
	//declare variables (to avoid weird error when defining in FOR)
	int x, y, tempSeat;
	
	//sort data in array from lowest to highest (using selection sort)
	for (x = 0; x < MAX; x++)//step through original array until sorting is complete
	{
		//compares item in array with item to the right of it
		for (y = x+1; y < MAX; y++)
		{
			//if item on left is > item on right
			if(array[x] > array[y])
			{
				//put left item in temporary seat outside of array
				tempSeat = array[x];
				//item on right is moved to now-empty seat in array
				array[x] = array[y];
				//put left item that was in temp seat back into array in 
				//now-empty right seat, so it can be compared to rest of items
				array[y] = tempSeat;
			}
		}
	}
	
	//check array sorting
	/*
	printf("\n");
	for (x=0; x < MAX; x++)    
		printf("%d ", array[x]);
	*/
	
	//print output
	//I'm not sure why the -1 was needed with MAX but my
	//suspision is that it's because I sorted the array values
	//and MAX now represents the temporary seat?
	printf("\nLargest number: %d", array[MAX-1]);
}

//smallest number function-----------------------------------------------------
void displaySmallest(int array[MAX])
{
	//print output
	printf("\nSmallest number: %d", array[0]);
}

//average number function-----------------------------------------------------
void displayAverage(int array[MAX])
{
	//declare variables (x int to avoid weird error when defining in FOR)
	int x;
	float average = 0;
	
	//add all numbers in array
	for (x = 0; x < MAX; x++)
	{
		average += array[x];
	}
	
	//find average of numbers in array
	average /= MAX;
	
	//print output
	printf("\nAverage number: %.2f", average);
}

//range function----------------------------------------------------------
void displayRange(int array[MAX])
{
	//declare variable
	int range = 0;
	
	//find range of numbers in array
	//again with having to put -1 with MAX to access largest value
	range = array[MAX-1] - array[0];
	
	//print output
	printf("\nRange: %d", range);
}

//median function-----------------------------------------------------------
void displayMedian(int array[MAX])
{
	//initialize variables
	int numOfNums = MAX;//put the # of numbers in array into a variable
	float median = 0;
	
	//if array has even number of items
    if(numOfNums%2 == 0)
    	//adds middle two numbers in array and divides them by 2
        median = (array[(numOfNums-1)/2] + array[numOfNums/2]) / 2;
        
    //if array has odd number of items
    else
    	//prints number in middle of array
        median = array[numOfNums/2];

	printf("\nMedian: %.2f", median);
}

//mode function----------------------------------------------------------------
void displayMode(int array[MAX])
{
	//mode is not mandatory
}

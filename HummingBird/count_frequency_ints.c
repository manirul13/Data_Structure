/* Program to find the frequency of element in C programming language.
 * We are given with an array and need to print the frequency of each given element.
 * Example
 * Input : arr[6] = [1, 2, 2, 3, 1, 2]
 * Output : 1 occurs 2 times
 *           2 occurs 3 times
 *           3 occurs 1 times
 */
#include <stdio.h>

int count_element(int arr[], int i, int visited[], int size);
void find_frequency(int arr[], int size);

int count_element(int arr[], int i, int visited[], int size)
{
	int j, count = 1; 

	/* Compare arr[i] with subsequent values and increment count */
	for (j = i + 1; j < size; j++)
	{
		if (arr[i] == arr[j])
		{
			count++;
			visited[j] = 1; // Mark index as visited
		}
	}

	return count;
}

/* Find frequency of array elements */
void find_frequency(int arr[], int size)
{
	int i, count;
	int visited[size]; // Array to keep track of visited values

	// Clear visited array
	for (i = 0; i < size; i++)
	{
		visited[i] = 0;
	}

	for (i = 0; i < size; i++)
	{
		// If already counted, no need to calculate again
		if (visited[i]) 
			continue;

		// Get frequency of arr[i]
		count = count_element(arr, i, visited, size);

		printf("%3d occurs %3d times\n", arr[i], count);
	}
}

int main()
{
	//int arr[] = {1, 2, 2, 3, 1, 2};
	int arr[] = {1, 2, 2, 1, 5, 3, 1, 2, 5, 25, 7, 3};
	int size = sizeof(arr) / sizeof(arr[0]);

	find_frequency(arr, size);

	return 0;
}


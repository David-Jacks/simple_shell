#include "shell.h"
/**
 * maxOfArray - Find the maximum value in an integer array.
 * @arr: The integer array.
 * @size: The size of the array.
 *
 * Return: The maximum value in the array.
 */
int maxOfArray(int arr[], int size)
{

	int highestArr = arr[0], i;

	for (i = 0; i < size; i++)
	{
		if (arr[i] > highestArr)
			highestArr = arr[i];
	}

	return (highestArr);
}



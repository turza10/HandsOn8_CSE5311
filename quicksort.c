#include <stdio.h>

// Function to exchange two elements
void exchange(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

// This function takes the last element as pivot, places the pivot element at its correct
// position in sorted array, and places all smaller (smaller than pivot) to left of pivot
// and all greater elements to right of pivot
int divide(int data[], int start, int end)
{
    int pivot = data[end];
    int i = (start - 1); // Index of smaller element
    printf("Pivot selected: %d\n", pivot);

    for (int j = start; j <= end - 1; j++)
    {
        // If current element is smaller than or equal to pivot
        if (data[j] <= pivot)
        {
            i++; // increment index of smaller element
            exchange(&data[i], &data[j]);
            printf("Swapping elements: %d, %d\n", data[i], data[j]);
        }
    }
    exchange(&data[i + 1], &data[end]);
    printf("Putting pivot in place: %d at index %d\n", data[i + 1], i + 1);
    return (i + 1);
}

// Returns the k-th smallest element of list within left..right inclusive
// (i.e., left <= k <= right). The search space within the array is changing
// for each round - but the list is still the same size. Thus, k does not
// need to be updated with each round.
int quickSelect(int data[], int left, int right, int k)
{
    if (k > 0 && k <= right - left + 1)
    {
        int pos = divide(data, left, right);
        printf("Position returned: %d\n", pos);

        // If the position is the same as k
        if (pos - left == k - 1)
        {
            return data[pos];
        }

        // If position is more, recur for the left subarray
        if (pos - left > k - 1)
        {
            printf("Recursing to left subarray: from %d to %d\n", left, pos - 1);
            return quickSelect(data, left, pos - 1, k);
        }

        // Else recur for the right subarray
        printf("Recursing to right subarray: from %d to %d\n", pos + 1, right);
        return quickSelect(data, pos + 1, right, k - pos + left - 1);
    }

    // If k is out of bounds
    printf("K is out of bounds.\n");
    return -1;
}

int main()
{
    int dataset[] = {12, 3, 5, 7, 4, 19, 26};
    int len = sizeof(dataset) / sizeof(dataset[0]);
    int k = 3; // Find the 3rd smallest element
    printf("Finding the %d-th smallest element in the dataset...\n", k);
    int result = quickSelect(dataset, 0, len - 1, k - 1);
    printf("The %d-th smallest element is %d\n", k, result);
    return 0;
}

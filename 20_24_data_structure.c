#include <stdio.h>
int linearSearch(int arr[], int n, int key);
void bubbleSort(int arr[], int n);
int binarySearch(int arr[], int low, int high, int key);
void insertionSort(int arr[], int n);

int main() {

    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key;

    printf("Choose an operation:\n");
    printf("1. Linear Search\n");
    printf("2. Bubble Sort\n");
    printf("3. Binary Search\n");
    printf("4. Insertion Sort\n");

    int option;
    scanf("%d", &option);

    switch (option) {
        case 1:
            printf("Enter the element to search: ");
            scanf("%d", &key);
            int linearResult = linearSearch(arr, n, key);
            if (linearResult != -1)
                printf("Element found at index %d\n", linearResult);
            else
                printf("Element not found\n");
            break;

        case 2:
            bubbleSort(arr, n);
            printf("Array after Bubble Sort:\n");
            for (int i = 0; i < n; i++)
                printf("%d ", arr[i]);
            printf("\n");
            break;

        case 3:
            printf("Enter the element to search: ");
            scanf("%d", &key);
            int binaryResult = binarySearch(arr, 0, n - 1, key);
            if (binaryResult != -1)
                printf("Element found at index %d\n", binaryResult);
            else
                printf("Element not found\n");
            break;

        case 4:
            insertionSort(arr, n);
            printf("Array after Insertion Sort:\n");
            for (int i = 0; i < n; i++)
                printf("%d ", arr[i]);
            printf("\n");
            break;

        default:
            printf("Invalid choice\n");
    }

    return 0;
}

int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key)
            return i;
    }
    return -1;
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int binarySearch(int arr[], int low, int high, int key) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key)
            return mid;
        if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

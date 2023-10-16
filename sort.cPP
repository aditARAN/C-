
#include <iostream>
#include <algorithm>
#include <ctime>
#include <cstdlib>

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

void sortArray(int arr[], int size) {
    std::sort(arr, arr + 3); // First 3 elements in ascending order
    std::sort(arr + 3, arr + 7, std::greater<int>()); // Next 4 elements in descending order
    srand(time(0)); // Seed the random number generator
    for (int i = 7; i < size; i++) {
        int randomIndex = rand() % (i + 1); // Generate a random index within the range [0, i]
        std::swap(arr[i], arr[randomIndex]); // Swap the elements at the random index and the current index
    }
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5, 2, 4, 6, 3};
    int size = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Original array: \n";
    printArray(arr, size);

    sortArray(arr, size);

    std::cout << "Sorted array: \n";
    printArray(arr, size);

    return 0;
}
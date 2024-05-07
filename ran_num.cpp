// Author: Alex Stewart
// Date: 5/1/24
// Purpose: To randomly genterate 21 numbers. take those 21 numbers store than sort

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void bubble(int arr[], int size, int& count);
void selection(int arr[], int size, int& count);
void display(int arr[], int size);

int main() {
    const int SIZE = 21;
    int original[SIZE];
    int cArray[SIZE];

     srand(time(0));

    for (int i = 0; i < SIZE; ++i) {
        original[i] = rand() % 9000 + 1000;
    }

    cout << "Here are the original 21 four-digit random numbers.\n";
    display(original, SIZE);

    for (int i = 0; i < SIZE; ++i) {
        cArray[i] = original[i];
    }

    int bubbleCount = 0;
    int selectionCount = 0;

    bubble(original, SIZE, bubbleCount);

    selection(cArray, SIZE, selectionCount);

    cout << "\n";
    cout << "\nThe same 21 numbers were sorted by each of two sorts.\n";

    cout << "\nHere is the data after a calling Bubble Sort.\n";
    display(original, SIZE);
    cout << "\n";
    cout << "\nBubble Sort made " << bubbleCount << " exchanges." << endl;

    cout << "\nHere is the data after a calling Selection Sort.\n";
    display(cArray, SIZE);
    cout << "\n";
    cout << "\nSelection Sort made " << selectionCount << " exchanges." << endl;

    return 0;
}

void bubble(int arr[], int size, int& count) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] < arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                count++;
            }
        }
    }
}

void selection(int arr[], int size, int& count) {
    for (int i = 0; i < size - 1; ++i) {
        int max = i;
        for (int j = i + 1; j < size; ++j) {
            if (arr[j] > arr[max]) {
                max = j;
            }
        }
        if (max != i) {
            swap(arr[i], arr[max]); 
            count++;
        }
    }
}

void display(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
}

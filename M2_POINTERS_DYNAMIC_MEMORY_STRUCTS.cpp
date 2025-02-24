//Thomas Cubstead
//2/24/25
//M2_POINTERS_DYNAMIC_MEMORY_STRUCTS
//reverse_Array
//this program creates an array and a reversed copy of it with a pointer leading to the reversed copy and has an example program that runs the function

#include <iostream>
using namespace std;

//this function reverses the array
int* reverseArray(int* arr, int size) {
    int* reverseA = new int[size];

        //reverses the array
        for (int i = 0; i < size; i++) {
            reverseA[i] = arr[size - 1 - i];
    }
    return reverseA;
}

int main() {
    //example program
    int arr[] = { 1,3,5,7,9 };
    int size = sizeof(arr) / sizeof(arr[0]);

        int* reverseA = reverseArray(arr, size);

        //output
        cout << "reversed version of the array: ";
        for (int i = 0; i < size; i++) {
            cout << reverseA[i] << " ";
        }
        cout << endl;

        //deallocates memory
        delete[] reverseA;

        return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

//Thomas Cubstead
//2/24/25
//M2_POINTERS_DYNAMIC_MEMORY_STRUCTS
//course_Grade
//this program uses structs to dynamically store student grade information based on given info in a file

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

//struct for student info
struct studentinfo {
    string name;
    int idnum;
    int* tests;
    double average;
    char grade;
};

//function to etermine the average grade of the student
void gradeCalc(studentinfo& studentinfo, int numTests) {
    int sum = 0;
    for (int i = 0; i < numTests; i++) {
        sum += studentinfo.tests[i];
    }
    studentinfo.average = static_cast<double>(sum) / numTests;

    if (studentinfo.average >= 91) {
        studentinfo.grade = 'A';
    }
    else if (studentinfo.average >= 81) {
        studentinfo.grade = 'B';
    }
    else if (studentinfo.average >= 71) {
        studentinfo.grade = 'C';
    }
    else if (studentinfo.average >= 61) {
        studentinfo.grade = 'D';
    }
    else {
        studentinfo.grade = 'F';
    }
}

int main() {
    ifstream inputFile("students.txt");

    //file validation
    if (!inputFile) {
        cerr << "error opening file" << endl;
        return 1;
    }

    int numStudents, numTests;
    inputFile >> numStudents >> numTests;

    studentinfo* students = new studentinfo[numStudents];

    //read info from the selected file
    for (int i = 0; i < numStudents; ++i) {
        inputFile >> students[i].name >> students[i].idnum;

        students[i].tests = new int[numTests];

        for (int j = 0; j < numTests; ++j) {
            inputFile >> students[i].tests[j];
        }
        gradeCalc(students[i], numTests);
    }
    inputFile.close();

    //table display of student info
    cout << left << setw(15) << "name"
        << setw(10) << "id number"
        << setw(15) << "average score"
        << "grade" << endl;
    cout << "-------------------------------------------------" << endl;

    for (int i = 0; i < numStudents; ++i) {
        cout << setw(15) << students[i].name
            << setw(10) << students[i].idnum
            << setw(15) << fixed << setprecision(2) << students[i].average
            << students[i].grade << endl;

        delete[] students[i].tests;
    }
    delete[] students;

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

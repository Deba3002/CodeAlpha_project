#include <iostream>
#include <vector>
#include <iomanip> // For setting precision
using namespace std;

int main() {
    int numCourses;
    cout << "Enter the number of courses: ";
    cin >> numCourses;

    vector<double> grades(numCourses);
    vector<int> creditHours(numCourses);

    double totalGradePoints = 0;
    int totalCredits = 0;

    for (int i = 0; i < numCourses; i++) {
        cout << "Enter grade (on 10-point scale) for course " << i + 1 << ": ";
        cin >> grades[i];
        cout << "Enter credit hours for course " << i + 1 << ": ";
        cin >> creditHours[i];

        totalGradePoints += grades[i] * creditHours[i];
        totalCredits += creditHours[i];
    }

    double cgpa = totalGradePoints / totalCredits;

    cout << fixed << setprecision(2);
    cout << "\nCourse-wise details:\n";
    for (int i = 0; i < numCourses; i++) {
        cout << "Course " << i + 1 << ": Grade = " << grades[i]
             << ", Credit Hours = " << creditHours[i] << endl;
    }

    cout << "\nTotal Credits: " << totalCredits << endl;
    cout << "Total Grade Points: " << totalGradePoints << endl;
    cout << "CGPA: " << cgpa << endl;

    return 0;
}
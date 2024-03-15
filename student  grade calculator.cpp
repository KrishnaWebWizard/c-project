#include <bits/stdc++.h>

using namespace std;

struct Student {
    string name;
    vector<int> grades;
};

class GradeBook {
private:
    vector<Student> students;

public:
    void addStudent(const string& name) {
        students.push_back({name, {}});
    }

    void addGrade(const string& name, int grade) {
        for (auto& student : students) {
            if (student.name == name) {
                student.grades.push_back(grade);
                return;
            }
        }
        cout << "Student " << name << " not found." << endl;
    }

    float calculateAverage(const string& name) {
        for (const auto& student : students) {
            if (student.name == name) {
                float sum = 0;
                for (int grade : student.grades) {
                    sum += grade;
                }
                return sum / student.grades.size();
            }
        }
        cout << "Student " << name << " not found." << endl;
        return 0;
    }

    void generateReport() {
        cout << "Student Report:" << endl;
        cout << setw(15) << left << "Name" << setw(10) << "Average" << endl;
        cout << "-------------------------" << endl;
        for (const auto& student : students) {
            float average = calculateAverage(student.name);
            cout << setw(15) << left << student.name << setw(10) << fixed << setprecision(2) << average << endl;
        }
    }
};

int main() {
    GradeBook gradebook;

    // Adding students
    gradebook.addStudent("John");
    gradebook.addStudent("Alice");

    // Adding grades
    gradebook.addGrade("John", 85);
    gradebook.addGrade("John", 90);
    gradebook.addGrade("Alice", 75);
    gradebook.addGrade("Alice", 80);

    // Generating report
    gradebook.generateReport();

    return 0;
}


#include <iostream>
using namespace std;

// Base class
class Student {
protected:
    string name;
    int rollNo;

public:
    void getStudentData() {
        cout << "Enter name: ";
        getline(cin, name);
        cout << "Enter roll number: ";
        cin >> rollNo;
    }
};

// Derived class 1 (virtual inheritance)
class Sports : virtual public Student {
protected:
    int sportsScore;

public:
    void getSportsScore() {
        cout << "Enter sports score: ";
        cin >> sportsScore;
    }
};

// Derived class 2 (virtual inheritance)
class Academics : virtual public Student {
protected:
    int academicScore;

public:
    void getAcademicScore() {
        cout << "Enter academic score: ";
        cin >> academicScore;
    }
};

// Derived class from Sports and Academics
class Result : public Sports, public Academics {
private:
    int totalScore;
    float percentage;

public:
    void calculateResult() {
        totalScore = sportsScore + academicScore;
        percentage = totalScore / 2.0;
    }

    void displayResult() {
        cout << "\n----- Final Performance Report -----\n";
        cout << "Name           : " << name << endl;
        cout << "Roll Number    : " << rollNo << endl;
        cout << "Academic Score : " << academicScore << endl;
        cout << "Sports Score   : " << sportsScore << endl;
        cout << "Total Score    : " << totalScore << endl;
        cout << "Percentage     : " << percentage << "%" << endl;
    }
};

int main() {
    Result r;

    r.getStudentData();
    r.getAcademicScore();
    r.getSportsScore();
    r.calculateResult();
    r.displayResult();

    return 0;
}

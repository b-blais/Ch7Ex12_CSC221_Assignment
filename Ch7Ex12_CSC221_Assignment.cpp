/*
Title: Chapter 7 Exercise 12 - Gradebook
File Name : Ch7Ex12_CSC221_Assignment
Programmer : Brion Blais
Date : 11 / 2024
Requirements :
Gradebook
Write a program that uses an array of string objects to hold the five student names, an array of five characters to 
hold the five students' letter grades and five arrays of four doubles to hold each student's set of test scores.

The program should allow the user to enter each student's name and his or her four test scores.  It should then 
calculate and display each sutdent's average test score, and a letter grade based on the average.

Input validation: Do not accept test scores less than 0 or greater than 100.
 */

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

string studentNames[5];
char studentLetterGrades[5];
double averages[5];
double student0[4];
double student1[4];
double student2[4];
double student3[4];
double student4[4];

void studentScores(int);
double scoreInput();
char toLetter(double);
void report();

int main()
{
    cout << "** Grade Program **\n";
    for (int index = 0; index < 5; index++) {
        cout << "Please enter a student's name:\t";
        cin >> studentNames[index];
        cout << "...ready to enter the grades for " << studentNames[index] << endl;
        studentScores(index);

    }
    report();

    return 0;
}

void studentScores(int studentNumber) {
    double score;
    double total = 0;
    for (int testNumber = 0; testNumber < 4; testNumber++) {
        cout << "Please enter the score for test " << (testNumber + 1) << ":\t";
        switch (studentNumber) {
        case 0:
            score = scoreInput();
            student0[testNumber] = score;
            total += score;
            break;
        case 1:
            score = scoreInput();
            student1[testNumber] = score;
            total += score;
            break;
        case 2:
            score = scoreInput();
            student2[testNumber] = score;
            total += score;
            break;
        case 3:
            score = scoreInput();
            student3[testNumber] = score;
            total += score;
            break;
        case 4:
            score = scoreInput();
            student4[testNumber] = score;
            total += score;
            break;
        default: cout << "Program error";
        }
    }
    averages[studentNumber] = total / 4;
    studentLetterGrades[studentNumber] = toLetter(averages[studentNumber]);
    cout << endl;
}

double scoreInput() {
    double score;
    do {
        cin >> score;
        if (score < 0 || score > 100) {
            cout << "Invalid Entry, please enter a score between no less than 0 and not greater than 100.\t";
        }
    } while (score < 0 || score > 100);
    return score;
}

char toLetter(double average) {
    if (average >= 90) {
        return 'A';
    }
    else if (average >= 80) {
        return 'B';
    }
    else if (average >= 70) {
        return 'C';
    }
    else if (average >= 60) {
        return 'D';
    }
    else {
        return 'F';
    }
}

void report() {
    cout << "\n****** Grade Summary ******" << endl;
    for (int count = 0; count < 5; count++) {
        cout << "Student " << studentNames[count] << " had an average score of " << setprecision(1) << fixed << averages[count] << ", resulting in a letter grade of " << studentLetterGrades[count] << endl;
    }
}
#pragma once
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

enum Speciality{KN, IT, ME, FI, TN};

const string strSpeciality[5] = { "КН", "ІT", "МЕ", "ФІ", "ТН" };

struct Student {
    string name;
    int curs;
    Speciality speciality;
    int physics;
    int math;
    union {
        int programming;
        int numbers;
        int pedagogic;
    };
};

void Create(Student*, int);
void Print(Student*, int);
void PrintIndexSorted(Student*, int*, int);
void Sort(Student*, const int);
int* indexSort(Student*, int);
int binSearch(Student*, const int, const string, const int, const int);
void Eror();

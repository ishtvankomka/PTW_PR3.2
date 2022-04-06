#include <iostream>
#include <string>
#include <iomanip>
#include "Student.hpp"

void Eror()
{
    cout << "Введено неправильні дані!" << endl;
}

void Create(Student* s, int students) {
    int sp = -1;
    for (int i = 0; i < students; i++) {
        cout << "Прiзвище: ";
        cin >> s[i].name;
        
        int curs = -1;
        
        do{
            cout << "Курс: ";
            cin >> curs;
            if (curs < 1 || curs > 6)
            {
                Eror();
            }
        } while(curs < 1|| curs > 6);
        s[i].curs = curs;
    
        do{
            cout << "Спецiальнiсть (0 - Комп'ютернi науки, 1 - Iнформатика, 2 - Математика та економiка, 3 - Фiзика та iнформатика, 4 - Трудове навчання) ";
            cin >> sp;
            if (sp < 0 || sp > 4)
            {
                Eror();
            }
        } while(sp < 0 || sp > 4);
        s[i].speciality = (Speciality)sp;
        
        int ozinka = -1;
        do{
            cout << "Оцiнка з фiзики: ";
            cin >> ozinka;
            if (ozinka < 1 || ozinka > 5)
            {
                Eror();
            }
        } while(ozinka < 1 || ozinka > 5);
        s[i].physics = ozinka;
        
        ozinka = -1;
        do{
            cout << "Оцiнка з математики: ";
            cin >> ozinka;
            if (ozinka < 1 || ozinka > 5)
            {
                Eror();
            }
        } while(ozinka < 1 || ozinka > 5);
        s[i].math = ozinka;
        
        if (s[i].speciality == 0) {
            ozinka = -1;
            do{
                cout << "Оцiнка з програмування: ";
                cin >> ozinka;
                if (ozinka < 1 || ozinka > 5)
                {
                    Eror();
                }
            } while(ozinka < 1 || ozinka > 5);
            s[i].programming = ozinka;
        }
        else if (s[i].speciality == 1) {
            ozinka = -1;
            do{
                cout << "Оцiнка з чисельних методів: ";
                cin >> ozinka;
                if (ozinka < 1 || ozinka > 5)
                {
                    Eror();
                }
            } while(ozinka < 1 || ozinka > 5);
            s[i].numbers = ozinka;
        }
        else {
            ozinka = -1;
            do{
                cout << "Оцiнка з педагогіки: ";
                cin >> ozinka;
                if (ozinka < 1 || ozinka > 5)
                {
                    Eror();
                }
            } while(ozinka < 1 || ozinka > 5);
            s[i].pedagogic = ozinka;
        }
    }
}

void Print(Student* s, int student)
{
    cout << "=========================================================================================================================="
        << endl;
    cout << "| № |    Прiзвище   | Курс | Спецiальнiсть | Фiзика | Математика | Програмування | Чисельнi методи | Педагогiка |"
        << endl;
    cout << "--------------------------------------------------------------------------------------------------------------------------"
        << endl;
    for (int i = 0; i < student; i++) {

        cout << "| " << setw(2) << right << i + 1 << "";
        cout << "| " << setw(22) << left << s[i].name
        << "| " << setw(5) << right << s[i].curs;
        int str1 = s[i].speciality;
        cout << "| " << setw(15) << left << strSpeciality[str1]
            << "| " << setw(7) << right << s[i].physics
            << "| " << setw(11) << right << s[i].math;
        if (s[i].speciality == 0) {
            cout << "| " << setw(14) << right << s[i].programming
                << "| " << setw(16) << right << " "
                << "| " << setw(11) << right << " " << "| ";
        }
        else if (s[i].speciality == 1) {
            cout << "| " << setw(14) << right << " "
                << "| " << setw(16) << right << s[i].numbers
                << "| " << setw(11) << right << " " << "| ";
        }
        else {
            cout << "| " << setw(14) << right << " "
                << "| " << setw(16) << right << " "
                << "| " << setw(11) << right << s[i].pedagogic << "| ";
        }
        cout << endl;
    }
    cout << "--------------------------------------------------------------------------------------------------------------------------"
        << endl;
}

void PrintIndexSorted(Student* s, int *I, int students)
{
    cout << "=========================================================================================================================="
        << endl;
    cout << "| № |    Прiзвище   | Курс |      Спецiальнiсть     | Фiзика | Математика | Програмування | Чисельнi методи | Педагогiка |"
        << endl;
    cout << "--------------------------------------------------------------------------------------------------------------------------"
        << endl;
    for (int i = 0; i < students; i++) {

        cout << "| " << setw(2) << right << i + 1 << "";
        cout << "| " << setw(14) << left << s[I[i]].name
            << "| " << setw(5) << right << s[I[i]].curs
            << "| " << setw(23) << left << strSpeciality[s[I[i]].speciality]
            << "| " << setw(7) << s[I[i]].physics
            << "| " << setw(11) << right << s[I[i]].math;
        if (s[I[i]].speciality == 0) {
            cout << "| " << setw(14) << right << s[I[i]].programming
                << "| " << setw(16) << right << " "
                << "| " << setw(11) << right << " " << "| ";
        }
        else if (s[I[i]].speciality == 1) {
            cout << "| " << setw(14) << right << " "
                << "| " << setw(16) << right << s[I[i]].numbers
                << "| " << setw(11) << right << " " << "| ";
        }
        else {
            cout << "| " << setw(14) << right << " "
                << "| " << setw(16) << right << " "
                << "| " << setw(11) << right << s[I[i]].pedagogic << "| ";
        }
        cout << endl;
    }
    cout << "--------------------------------------------------------------------------------------------------------------------------"
        << endl;
}

void Sort(Student* p, const int N)
{
   Student tmp;
    for (int i0 = 0; i0 < N - 1; i0++) // метод "бульбашки"
        for (int i1 = 0; i1 < N - i0 - 1; i1++)
            if ((p[i1].curs > p[i1+1].curs)
                ||
                (p[i1].curs == p[i1+1].curs
                 && (p[i1].programming < p[i1+1].programming ||
                     p[i1].programming < p[i1+1].numbers ||
                     p[i1].programming < p[i1+1].pedagogic ||
                     p[i1].numbers < p[i1+1].numbers ||
                     p[i1].numbers < p[i1+1].programming ||
                     p[i1].numbers < p[i1+1].pedagogic ||
                     p[i1].pedagogic < p[i1+1].pedagogic ||
                     p[i1].pedagogic < p[i1+1].programming ||
                     p[i1].pedagogic < p[i1+1].numbers))
                ||
                (p[i1].curs == p[i1+1].curs
                 && (p[i1].programming == p[i1+1].programming ||
                     p[i1].programming == p[i1+1].numbers ||
                     p[i1].programming == p[i1+1].pedagogic ||
                     p[i1].numbers == p[i1+1].numbers ||
                     p[i1].numbers == p[i1+1].programming ||
                     p[i1].numbers == p[i1+1].pedagogic ||
                     p[i1].pedagogic == p[i1+1].pedagogic ||
                     p[i1].pedagogic == p[i1+1].programming ||
                     p[i1].pedagogic == p[i1+1].numbers)
                 &&
                 (p[i1].name < p[i1 + 1].name)))
            {
                tmp = p[i1];
                p[i1] = p[i1 + 1];
                p[i1 + 1] = tmp;
            }
}

int* indexSort(Student *p, int N) {
    int* I = new int[N];

    for (int i = 0; i < N; i++) {
        I[i] = i;
    }

    int i, j, value;
    for (i = 1; i < N; i++) {
        value = I[i];
        for (j = i - 1;
             (j >= 0)
             &&
             ((p[j].curs > p[value].curs)
             ||
             (p[j].curs == p[value].curs
              && (p[j].programming < p[value].programming ||
                  p[j].programming < p[value].numbers ||
                  p[j].programming < p[value].pedagogic ||
                  p[j].numbers < p[value].numbers ||
                  p[j].numbers < p[value].programming ||
                  p[j].numbers < p[value].pedagogic ||
                  p[j].pedagogic < p[value].pedagogic ||
                  p[j].pedagogic < p[value].programming ||
                  p[j].pedagogic < p[value].numbers))
             ||
             (p[j].curs == p[value].curs
              && (p[j].programming == p[value].programming ||
                  p[j].programming == p[value].numbers ||
                  p[j].programming == p[value].pedagogic ||
                  p[j].numbers == p[value].numbers ||
                  p[j].numbers == p[value].programming ||
                  p[j].numbers == p[value].pedagogic ||
                  p[j].pedagogic == p[value].pedagogic ||
                  p[j].pedagogic == p[value].programming ||
                  p[j].pedagogic == p[value].numbers)
              &&
              (p[j].name < p[value].name)));
            j--)
        {
            I[j + 1] = I[j];
        }
        I[j + 1] = value;
    }
    return I;
}

int binSearch(Student* p, const int N, const string prizv, const int curs, const int ozinka)
{
    int L = 0, R = N - 1, m;
    do {
        m = (L + R) / 2;
        int speciality = p[m].speciality;
        if (p[m].name == prizv && p[m].curs == curs)
        {
            switch (speciality) {
                case 0:
                {
                    if(p[m].programming == ozinka)
                    {
                        return m;
                    }
                    break;
                }
                case 1:
                {
                    if(p[m].numbers == ozinka)
                    {
                        return m;
                    }
                    break;
                }
                case 2:
                {
                    if(p[m].numbers == ozinka)
                    {
                        return m;
                    }
                    break;
                }
            }
        }
        
        if ((p[m].name != prizv)
            || (p[m].name == prizv && p[m].curs != curs)
            || (p[m].name == prizv && p[m].curs == curs && p[m].speciality != speciality))
        {
            L = m + 1;
        }

        else
        {
            R = m - 1;
        }
    } while (L <= R);
    return -1;
}

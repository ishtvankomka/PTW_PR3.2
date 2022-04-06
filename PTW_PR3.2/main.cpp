#include <iostream>
#include <string>
#include <iomanip>
#include "Student.hpp"

using namespace std;

int main() {
    setlocale(LC_ALL, "Ukrainian");
    int students;
    string lastName;
    int found;
    cout << "Кількість студентів: ";
    cin >> students;
    Student* s = new Student[students];
    int curs, ozinka;

    int key;
    do {
        cout << endl;
        cout << "Виберіть дію:" << endl << endl;
        cout << " [1] - введення даних з клавіатури " << endl;
        cout << " [2] - вивід даних на екран" << endl;
        cout << " [3] - фізичне впорядкування даних " << endl;
        cout << " [4] - індексне впорядкування та вивід даних " << endl;
        cout << " [5] - бінарний пошук для визначення, чи навчається студент " << endl;
        cout << " із вказаним користувачем прізвищем на вказаній спеціальності та вказаним середнім балом." << endl;
        cout << " [0] - вихід та завершення програми " << endl;
        cout << "Введіть значеня: "; cin >> key;
        cout << endl;

        switch (key) {
        case 1:
            Create(s, students);
            break;
        case 2:
            Print(s, students);
            break;
        case 3:
            Sort(s, students);
            break;
        case 4:
            {
                int *I = indexSort(s, students);
                PrintIndexSorted(s, I, students);
                break;
            }
        case 5:
            cout << "Введіть ключі пошуку:" << endl;
            cout << " Прізвище: "; cin >> lastName;
            cout << endl;
            cout << "Курс: ";
            cin >> curs;
            cout << "Оцінка: " << endl;
            cin >> ozinka;
            cin.get();
            cin.sync();
            if ((found = binSearch(s, students, lastName, curs, ozinka)) != -1)
                cout << "Знайдено студента в позиції " << found + 1 << endl;
            else
                cout << "Шуканого студента не знайдено" << endl;
            break;
        case 0:
            break;
        }
    } while (key != 0);
    return 0;
}

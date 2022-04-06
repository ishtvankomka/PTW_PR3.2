#define CATCH_CONFIG_MAIN
#include "Catch.hpp"
#include "Student.cpp"
#include "Student.hpp"

TEST_CASE( "Arguments initialized") {
    int students = 2;
    Student *s1 = new Student[students];
    
    s1[0].name = "Shevchenko";
    s1[0].curs = 2;
    int speciality1 = 0;
    s1[0].speciality = (Speciality)speciality1;
    s1[0].programming = 5;

    s1[1].name = "Franko";
    s1[1].curs = 4;
    int speciality2 = 1;
    s1[1].speciality = (Speciality)speciality2;
    s1[1].numbers = 4;

    REQUIRE( binSearch(s1, students, "Shevchenko", 2, 5) == 0);
    REQUIRE( binSearch(s1, students, "Franko", 4, 2) == -1);
}

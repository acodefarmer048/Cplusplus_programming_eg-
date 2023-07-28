#include <list>
#include <algorithm>
#include <iostream>
#include "grade.h"
#include "Student_info.h"
#include "extract_fails.h"
using std::list; using std::stable_partition;

bool pgrade(const Student_info& s){
    return !fgrade(s);
}
list<Student_info> extract_fails(list<Student_info>& students){
    list<Student_info>::iterator iter=
        stable_partition(students.begin(), students.end(), pgrade);
    list<Student_info> fail(iter, students.end());
    students.erase(iter, students.end())
    return fail;
    
}
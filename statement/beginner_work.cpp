#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <list>
#include "grade.h"
#include "Student_info.h"
#include "extract_fails.h"

using std::cin;   using std::setprecision;
using std::cout;  using std::sort;
using std::domain_error; using std::streamsize;
using std::endl;   using std::string;
using std::max;   using std::vector;
using std::list;

int main(){
    list<Student_info> students;
    Student_info record;
    string::size_type maxlen=0;

    while(read(cin, record)){
        maxlen=max(maxlen, record.name.size());
        students.push_back(record);
    }

    students.sort(compare);

    list<Student_info>::iterator iter=students.begin();
    while(iter!=students.end()){
        cout << (*iter).name
             << string(maxlen+1-(*iter).name.size(), ' ');
        try{
            double final_grade= grade(*iter);
            streamsize prec=cout.precision();
            cout<< setprecision(3)<< final_grade
                << setprecision(prec);
        }catch(domain_error e){
            cout << e.what();
        }
        cout<< endl;
        ++iter;
    }
    list<Student_info> fail=extract_fails(students);
    

    list<Student_info>::iterator fiter=fail.begin();
    cout << "students that fail in exams."<<endl;
    while(fiter!=fail.end()){
        cout << (*fiter).name
             << string(maxlen+1-(*fiter).name.size(), ' ');
        ++fiter;
    }

    system("pause");
    return 0;
}
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <ios>
#include <cctype>
#include <string>
#include <vector>
#include <iterator>
#include <numeric>
#include "Student_info.h"
#include "grade.h"
#include "median.h"
#include "average.h"
using std::cin; using std::cout;
using std::remove_if; using std::remove_copy;
using std::accumulate; using std::stable_partition;
using std::transform; using std::remove_copy_if;
using std::endl; using std::vector;
using std::domain_error; using std::ostream;
using std::string;
bool did_all_hw(const Student_info& s)
{
	return ((find(s.homework.begin(), s.homework.end(), 0))
		== s.homework.end());
}


//analysis functions for each question.

double grade_aux(const Student_info& s)
{
	try {
		return grade(s);
	} catch (domain_error) {
		return grade(s.midterm, s.final, 0);
	}
}

double median_analysis(const vector<Student_info>& students)
{
	vector<double> grades;
	transform(students.begin(), students.end(),
		back_inserter(grades), grade_aux);
	return median(grades);
}

//analysis functions for each question.

double average_grade(const Student_info& s)
{
	return grade(s.midterm, s.final, average(s.homework));
}

double average_analysis(const vector<Student_info>& students)
{
	vector<double> grades;
	transform(students.begin(),students.end(), 
		back_inserter(grades), average_grade);
	return median(grades);
}

//analysis functions for each question.

double optimistic_median(const Student_info& s)
{
	vector<double> nonzero;
	remove_copy(s.homework.begin(), s.homework.end(), 
		back_inserter(nonzero), 0);
	if (nonzero.empty())
		return grade(s.midterm, s.final, 0);
	else
		return grade(s.midterm, s.final, median(nonzero));
}

double optimistic_median_analysis(const vector<Student_info>& students)
{
	vector<double> grades;
	transform(students.begin(), students.end(), 
			back_inserter(grades), optimistic_median);
	return median(grades);	
}


//the summary function


void write_analysis(ostream& out, const string& name,
				double analysis(const vector<Student_info>& ),
				const vector<Student_info>& did,
				const vector<Student_info>& didnt)
{
	out << name << ":median(did) = " << analysis(did) 
		<< ":median(didnt) = " << analysis(didnt) << endl;
}
//main function


int main(){
	vector<Student_info>did, didnt;
	Student_info student;
	while (read(cin, student)) {
		if (did_all_hw(student))
			did.push_back(student);
		else
			didnt.push_back(student);
	}
	if (did.empty()) {
		cout << "No student did all the homework!" << endl;
		return 1;
	}
	if (didnt.empty()) {
		cout << "Every student did all the homework!" << endl;
		return 1;
	}
	write_analysis(cout, "median", median_analysis, did, didnt);
	write_analysis(cout, "average", average_analysis, did, didnt);
	write_analysis(cout, "median of homework turned in", optimistic_median_analysis, did, didnt);
	system("pause");
	return 0;
}

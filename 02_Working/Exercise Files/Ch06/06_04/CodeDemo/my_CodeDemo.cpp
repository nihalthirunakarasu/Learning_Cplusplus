// Learning C++ 
// Challenge 04_05
// Calculate a GPA, by Eduardo Corpeño 

#include <iostream>
#include <vector>
#include <cassert>
#include "my_records.h"

// Use (void) to silence unused warnings.
#define assertm(exp, msg) assert(((void)msg, exp))

//using namespace std;

std::vector<Student> students = {Student(1,"George P. Burdell"),
							Student(2,"Nancy Rhodes")};

std::vector<Course> courses = {Course(1,"Algebra",5),
						  Course(2,"Physics",4),
						  Course(3,"English",3),
						  Course(4,"Economics",4)};

std::vector<Grade> grades = {Grade(1,1,'B'),	Grade(1,2,'A'),	Grade(1,3,'C'),
						Grade(2,1,'A'),	Grade(2,2,'A'), Grade(2,4,'B')};




#define DEBUG 0

int main(){
	StudentRecords SR;
	int id;

	//StudentRecords_init(SR);
	
	FilesStudentRecords rec;
	rec.read_students_file("students.txt", SR);
	rec.read_courses_file("courses.txt", SR);
	rec.read_grades_file("grades.txt", SR);

	std::cout << "Enter a student ID: ";
	std::cin >> id;

	std::string student_str;
	student_str = SR.get_student_name(id); // Change this to the selected student's name

	std::cout << "---------------------------------------" << std::endl;
	std::cout << "Student Name: " << student_str << std::endl;

	SR.get_student_report_card(id);

	float GPA = 0.0f;
	GPA = SR.get_student_GPA(id); 

	std::cout << "GPA: " << GPA << std::endl;
	std::cout << "---------------------------------------" << std::endl;
	
	return (0);
}





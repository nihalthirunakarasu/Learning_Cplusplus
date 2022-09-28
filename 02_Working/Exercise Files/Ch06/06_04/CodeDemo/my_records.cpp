#include <cassert>
#include <iostream>
#include <fstream>
#include "my_records.h"

// Use (void) to silence unused warnings.
#define assertm(exp, msg) assert(((void)msg, exp))

#define DEBUG 0

Student::Student(int the_id, std::string the_name){
	id = the_id;
	name = the_name;
}
int Student::get_id(){
	return id;
}
std::string Student::get_name(){
	return name;
}

Course::Course(int the_id, std::string the_name, unsigned char the_credits){
	id = the_id;
	name = the_name;
	credits = the_credits;
}
int Course::get_id(){
	return id;
}
std::string Course::get_name(){
	return name;
}
int Course::get_credits(){
	return credits;
}

Grade::Grade(int sid, int cid, char grd){
	student_id = sid;
	course_id = cid;
	grade = grd;
}
int Grade::get_student_id(){
	return student_id;
}
int Grade::get_course_id(){
	return course_id;
}
char Grade::get_grade(){
	return grade;
}

void StudentRecords::add_student(int the_id, std::string the_name)
{
	students.push_back(Student(the_id, the_name));
}

void StudentRecords::add_course(int the_id, std::string the_name, unsigned char the_credits)
{
	courses.push_back(Course(the_id, the_name, the_credits));
}

void StudentRecords::add_grade(int sid, int cid, char grd)
{
	grades.push_back(Grade(sid, cid, grd));
}

float StudentRecords::get_student_GPA(int id)
{
	float GPA = 0.0f;
	bool student_present = false;
	for(auto student : students)
	{
		if(student.get_id() == id)
		{
			student_present = true;
			break;
		}
	}

	assertm(student_present, "Invalid Student ID");

    int student_id;
    uint student_score = 0, total_score = 0, temp;

	// Calculate the GPA for the selected student.
	// Write your code here
    for(auto grade : grades)
    {
        student_id = grade.get_student_id();
        if(id == student_id)
        {
			for(auto course : courses)
			{
				if(grade.get_course_id() == course.get_id())
				{
					switch(grade.get_grade())
					{
						case 'A':
							temp = 4;
						break;

						case 'B':
							temp = 3;
						break;
						
						case 'C':
							temp = 2;
						break;
						
						case 'D':
							temp = 1;
						break;
						
						case 'F':
							temp = 0;
						break;

						default:
							assertm(1, "The grade obtained is invalid!\n");
						break;
					}
					student_score += temp*course.get_credits();
					total_score += course.get_credits();
				}
			}
		}
    }

#if DEBUG
	std::cout << "total " << student_score << " obtained " << total_score << std::endl;
#endif

	GPA = ((float)student_score)/total_score;
	return GPA;
}

std::string StudentRecords::get_student_name(int id)
{
	return students[(id-1)].get_name(); // Change this to the selected student's name
}

void StudentRecords::get_student_report_card(int id)
{
	
	float GPA = 0.0f;
	bool student_present = false;
	for(auto student : students)
	{
		if(student.get_id() == id)
		{
			student_present = true;
			break;
		}
	}

	assertm(student_present, "Invalid Student ID");

    int student_id;
    uint student_score = 0, total_score = 0, temp;

	// Calculate the GPA for the selected student.
	// Write your code here
    for(auto grade : grades)
    {
        student_id = grade.get_student_id();
        if(id == student_id)
        {
			for(auto course : courses)
			{
				if(grade.get_course_id() == course.get_id())
				{
					std::cout << course.get_name() << "|" << course.get_credits() << "|" << grade.get_grade() << std::endl;
				}
			}
		}
    }
}


void FilesStudentRecords::read_students_file(std::string file_path, StudentRecords& student_record)
{	
	std::string str_temp;
	int student_id_temp;
	std::string student_name_temp;
	
	std::fstream my_file;
	my_file.open(file_path);

	assertm(!(my_file.fail()), "The student file failed to open!\n");

#if DEBUG
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "Student Data" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
#endif

	while(!(my_file.eof()))
	{
		std::getline(my_file, str_temp);
		student_id_temp = stoi(str_temp);
		std::getline(my_file, str_temp);
		student_name_temp = str_temp;

		student_record.add_student(student_id_temp, student_name_temp);

#if DEBUG
		std::cout << "Student ID: " << student_id_temp << " Student Name: " << student_name_temp << std::endl;
#endif
	}
#if DEBUG
		std::cout << "----------------------------------------------------------------" << std::endl;
#endif
}

void FilesStudentRecords::read_courses_file(std::string file_path, StudentRecords& student_record)
{
	std::string str_temp;
	int course_id_temp, course_grade_temp;
	std::string course_name_temp;
	
	std::fstream my_file;
	my_file.open(file_path);

	assertm(!(my_file.fail()), "The courses file failed to open!\n");

#if DEBUG
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "Course Data" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
#endif

	while(!(my_file.eof()))
	{
		std::getline(my_file, str_temp);
		course_id_temp = stoi(str_temp);
		std::getline(my_file, str_temp);
		course_name_temp = str_temp;
		std::getline(my_file, str_temp);
		course_grade_temp = stoi(str_temp);

		student_record.add_course(course_id_temp, course_name_temp, course_grade_temp);
		
#if DEBUG
		std::cout << "Course ID: " << course_id_temp << " Course Name: " << course_name_temp << " Course Grade: " << course_grade_temp << std::endl;
#endif
	}
#if DEBUG
		std::cout << "----------------------------------------------------------------" << std::endl;
#endif
}

void FilesStudentRecords::read_grades_file(std::string file_path, StudentRecords& student_record)
{
	std::string str_temp;
	int grade_student_id, grade_course_id_temp;
	char grade_grade_temp;
	
	std::fstream my_file;
	my_file.open(file_path);

	assertm(!(my_file.fail()), "The courses file failed to open!\n");

#if DEBUG
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "Grade Data" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
#endif

	while(!(my_file.eof()))
	{
		std::getline(my_file, str_temp);
		grade_student_id = stoi(str_temp);
		std::getline(my_file, str_temp);
		grade_course_id_temp = stoi(str_temp);
		std::getline(my_file, str_temp);
		grade_grade_temp = str_temp[0];

		student_record.add_grade(grade_student_id, grade_course_id_temp, grade_grade_temp);

#if DEBUG
		std::cout << "Student ID: " << grade_student_id << " Coourse ID: " << grade_course_id_temp << " Obtained Grade: " << grade_grade_temp << std::endl;
#endif
	}
#if DEBUG
		std::cout << "----------------------------------------------------------------" << std::endl;
#endif
}

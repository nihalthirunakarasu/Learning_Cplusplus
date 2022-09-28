#include <cassert>
#include <iostream>
#include "my_records.h"

// Use (void) to silence unused warnings.
#define assertm(exp, msg) assert(((void)msg, exp))

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

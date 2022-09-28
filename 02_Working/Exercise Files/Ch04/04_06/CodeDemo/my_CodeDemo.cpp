// Learning C++ 
// Challenge 04_05
// Calculate a GPA, by Eduardo Corpeño 

#include <iostream>
#include <vector>
#include <cassert>
#include "records.h"

// Use (void) to silence unused warnings.
#define assertm(exp, msg) assert(((void)msg, exp))

using namespace std;

vector<Student> students = {Student(1,"George P. Burdell"),
							Student(2,"Nancy Rhodes")};

vector<Course> courses = {Course(1,"Algebra",5),
						  Course(2,"Physics",4),
						  Course(3,"English",3),
						  Course(4,"Economics",4)};

vector<Grade> grades = {Grade(1,1,'B'),	Grade(1,2,'A'),	Grade(1,3,'C'),
						Grade(2,1,'A'),	Grade(2,2,'A'), Grade(2,4,'B')};

float GPA = 0.0f;
int id;

#define DEBUG 0

int main(){
	cout << "Enter a student ID: ";
	cin >> id;

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
	cout << "total " << student_score << " obtained " << total_score << endl;
#endif

	GPA = ((float)student_score)/total_score;

	string student_str;
	student_str = students[(id-1)].get_name(); // Change this to the selected student's name

	cout << "The GPA for " << student_str << " is " << GPA << endl;
	return (0);
}





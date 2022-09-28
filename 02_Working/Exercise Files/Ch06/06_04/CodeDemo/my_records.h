#pragma once

#include <string>
#include <vector>

class Student{
private:
	int id;
	std::string name;

public:
	Student(int the_id, std::string the_name);
	int get_id();
	std::string get_name();
};

class Course{
private:
	int id;
	std::string name;
	unsigned char credits;

public:
	Course(int the_id, std::string the_name, unsigned char the_credits);
	int get_id();
	std::string get_name();
	int get_credits();
};

class Grade{
private:
	int student_id;
	int course_id;
	char grade;

public:
	Grade(int sid, int cid, char grd);
	int get_student_id();
	int get_course_id();
	char get_grade();
};

class StudentRecords{
private:
    std::vector<Student> students;
	std::vector<Course> courses;
	std::vector<Grade> grades;

public:
	void add_student(int the_id, std::string the_name);
	void add_course(int the_id, std::string the_name, unsigned char the_credits);
	void add_grade(int sid, int cid, char grd);
	
	float get_student_GPA(int id);
	std::string get_student_name(int id);
	void get_student_report_card(int id);
};

class FilesStudentRecords{
public:
    void read_students_file(std::string file_path, StudentRecords& student_record);
    void read_courses_file(std::string file_path, StudentRecords& student_record);
    void read_grades_file(std::string file_path, StudentRecords& student_record);
};
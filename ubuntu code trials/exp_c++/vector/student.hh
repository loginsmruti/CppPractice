#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <iostream>
using namespace std;

class Student
{
    private:
        int ID;
        string name;
        double GPA; 
        char gender;
    public:
        Student();
        Student(const Student& obj);
        Student(int ID, std::string const& name, double GPA, char gender);

        int getID();
        string getName();
        double getGPA();
        char getGender();
        void print(std::ostream& str ) const;
        friend std::ostream& operator<<(std::ostream& out,
                                        Student const& obj);
        friend std::istream& operator>>(std::istream& in, Student& obj);
        
};
#endif

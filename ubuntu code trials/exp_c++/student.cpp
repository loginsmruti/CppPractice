#include "student.hh"

Student::Student()
    : ID(0),
      name(""),
      GPA(0),
      gender('\0')
{ }

Student::Student(int ID, std::string const& name, double GPA, char gender)
    : ID(ID),
      name(name),
      GPA(GPA),
      gender(gender)
{ }

int Student::getID()
{
    return ID;
}

string Student::getName()
{
    return name;
}

double Student::getGPA()
{
    return GPA;
}

char Student::getGender()
{
    return gender;
}

void Student::print(std::ostream& str = std::cout) const
{
    str << "ID : " << ID << "\n"
        << "Name : " << name << "\n"
        << "GPA : " << GPA << "\n"
        << "Gender : " << gender << std::endl;
}

std::ostream& operator<<(std::ostream& str, Student const& data)
{
    data.print(str);
    return str;
}

std::istream& operator>>(std::istream& in, Student& obj)
{
    return in >> obj.ID >> obj.name >> obj.GPA >> obj.gender;
}

int main()
{
    Student *s1;
    Student *s2;
    Student *s3;
    Student *s4;
    
   s1 = new Student(1 , "Vicky", 7.8, 'M');
   s2 = new Student(2 , "Rocky", 8.8, 'M');
   s3 = new Student(3 , "Mama", 8.4, 'F');
   s4 = new Student(4 , "Baba", 8.6, 'M');

    std::cout << *s1;
    std::cout << *s2;
    std::cout << *s3;
    std::cout << *s4; 

    return 0;
}

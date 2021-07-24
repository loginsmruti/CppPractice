#pragma pack(1)

typedef struct date_of_birth
{
 short int date,year;
 char month[5];
}DOB;

struct stu
{
 char name[50],address[50];
 int age,roll_no;
 DOB  dob;
};
//student[3],*p;



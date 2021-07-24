#pragma pack(1)                                // slack bytes removed

typedef struct DateOfJoining                  //STRUCTURE DEFINITION
{
 short int DD,MM,YYYY;
}DOJ;

typedef struct BasicSalary
{
 int basic_sal,DA,HRA,CCA,NetSal;
}BSAL;

typedef struct employee
{
 char name[40];
 char e_id[8];
 DOJ doj;
 BSAL basic;
}EMP;

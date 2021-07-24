HOME=.
SRCDIR=${HOME}/src
INCDIR=${HOME}/include
OBJDIR=${HOME}/objects
BINDIR=${HOME}/bin
SRCFILES=${SRCDIR}/EmployeeDatabaseOperation.c ${SRCDIR}/GenerateId.c  ${SRCDIR}/SalaryCalculation.c ${SRCDIR}/main.c
OBJFILES=${OBJDIR}/EmployeeDatabaseOperation.o ${OBJDIR}/GenerateId.o ${OBJDIR}/SalaryCalculation.o ${OBJDIR}/main.o
HEADER=${INCDIR}/employee.h
${HOME}/install:${OBJFILES}
	gcc -o ${HOME}/install ${OBJFILES} -I. 
${OBJDIR}/main.o:${SRCDIR}/main.c
	gcc -c ${SRCDIR}/main.c -Wall -g
	mv main.o ${OBJDIR}
${OBJDIR}/GenerateId.o:${SRCDIR}/GenerateId.c
	gcc -c ${SRCDIR}/GenerateId.c -Wall -g
	mv GenerateId.o ${OBJDIR}
${OBJDIR}/EmployeeDatabaseOperation.o:${SRCDIR}/EmployeeDatabaseOperation.c
	gcc -c ${SRCDIR}/EmployeeDatabaseOperation.c -Wall -g
	mv EmployeeDatabaseOperation.o ${OBJDIR}
${OBJDIR}/SalaryCalculation.o:${SRCDIR}/SalaryCalculation.c 
	gcc -c ${SRCDIR}/SalaryCalculation.c -Wall -g
	mv SalaryCalculation.o ${OBJDIR}
#${SRCDIR}/main.c :${SRCDIR}/EmployeeDatabaseOperation.c ${SRCDIR}/GenerateId.c  ${SRCDIR}/SalaryCalculation.c
${SRCFILES}:${HEADER}

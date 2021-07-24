#include <iostream>
#include <stdlib.h>
#include "circleOneConnectionInfoList.h"
#include "circleOneMapOfEmpIdAndFd.h"

using namespace std;
using namespace CircleOne;

EmployeeFdList* EmployeeFdList::mp_PtrInstance = NULL;
pthread_mutex_t EmployeeFdList::m_MutexForObjectCreationForFdList;

EmployeeFdList::EmployeeFdList()
{
   int ret=0;
   ret = pthread_mutex_init(&m_Mutex_Fd_List, 0);
   if(ret != 0)
   {
      cout << "Mutex not initialize!!" << endl;
      exit(0);
   }
   ret = pthread_mutex_init(&m_MutexForObjectCreationForFdList, 0);
   if(ret != 0)
   {
      cout << "Mutex not initialize!!" << endl;
      exit(0);
   }
}

EmployeeFdList::~EmployeeFdList()
{
   pthread_mutex_destroy(&m_Mutex_Fd_List);
   pthread_mutex_destroy(&m_MutexForObjectCreationForFdList);
}

EmployeeFdList* EmployeeFdList::getInstance()
{
   if(NULL == mp_PtrInstance)
   {
     pthread_mutex_lock(&m_MutexForObjectCreationForFdList);
     if(NULL == mp_PtrInstance)
     {
        mp_PtrInstance = new EmployeeFdList;
     }
     pthread_mutex_lock(&m_MutexForObjectCreationForFdList);
   }
   return mp_PtrInstance;
}

bool EmployeeFdList::lockList()
{
   int ret = -1;
   ret=pthread_mutex_lock(&m_Mutex_Fd_List);
   if(ret == EDEADLK)
   {
      cout << "pthread_mutex_lock Error: DEADLOCK" << endl;
      return false;
   }
   return true;
}

void EmployeeFdList::unlockList()
{
   pthread_mutex_unlock(&m_Mutex_Fd_List);
}

void EmployeeFdList::pushIntomap(int employeeId, int fd)
{
   lockList();
   map<int, int>::iterator itr;
   itr = m_EmpIdAndFdMap.find(employeeId);
   if(itr == m_EmpIdAndFdMap.end())
   {
      cout << "This employee id already existed" << endl;
      cout << "Updating your Fd into the map"<< endl;
      m_EmpIdAndFdMap.erase (itr);
      m_EmpIdAndFdMap.insert(std::pair<int, int>(employeeId, fd));
   }
   else
   {
      m_EmpIdAndFdMap.insert(std::pair<int, int>(employeeId, fd));
   }
   unlockList();
}



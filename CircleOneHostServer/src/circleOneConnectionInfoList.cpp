#include <iostream>
#include <stdlib.h>
#include "circleOneConnectionInfoList.h"

using namespace std;
using namespace CircleOne;

ConnInfoList* ConnInfoList::mp_PtrInstance = NULL;
pthread_mutex_t ConnInfoList::m_MutexForObjectCreation;

ConnInfoList::ConnInfoList()
{
   int ret=0;
   ret = pthread_mutex_init(&m_Mutex, 0);
   if(ret != 0)
   {
      cout << "Mutex not initialize!!" << endl;
      exit(0);
   }
   ret = pthread_mutex_init(&m_MutexForObjectCreation, 0);
   if(ret != 0)
   {
      cout << "Mutex not initialize!!" << endl;
      exit(0);
   }
}

ConnInfoList::~ConnInfoList()
{
   pthread_mutex_destroy(&m_Mutex);
   pthread_mutex_destroy(&m_MutexForObjectCreation);
}

ConnInfoList* ConnInfoList::getInstance()
{
   if(NULL == mp_PtrInstance)
   {
     pthread_mutex_lock(&m_MutexForObjectCreation);
     if(NULL == mp_PtrInstance)
     {
        mp_PtrInstance = new ConnInfoList;
     }
     pthread_mutex_lock(&m_MutexForObjectCreation);
   }
   return mp_PtrInstance;
}

bool ConnInfoList::lockList()
{
   int ret = -1;
   ret=pthread_mutex_lock(&m_Mutex);
   if(ret == EDEADLK)
   {
      cout << "pthread_mutex_lock Error: DEADLOCK" << endl;
      return false;
   }
   return true;
}

void ConnInfoList::unlockList()
{
   pthread_mutex_unlock(&m_Mutex);
}

void ConnInfoList::pushIntoInfoList(int fd)
{
   lockList();
   m_FdList.push_back(fd);
   unlockList();
}

int ConnInfoList::getFdFromTheList()
{
   int tempFd = 0;
   lockList();
   if(m_FdList.size() == 1)
   {
      m_FdListIterator = m_FdList.begin();
      tempFd = *m_FdListIterator;
      ++m_FdListIterator;
      if(m_FdListIterator == m_FdList.end())
         m_FdListIterator = m_FdList.begin();
   }
   else if(m_FdList.size() > 1)
   {
      m_FdListIterator = m_FdList.begin();
      tempFd = *m_FdListIterator;
      ++m_FdListIterator;
      if(m_FdListIterator == m_FdList.end())
         m_FdListIterator = m_FdList.begin();
   }
   unlockList();
   return tempFd;
}


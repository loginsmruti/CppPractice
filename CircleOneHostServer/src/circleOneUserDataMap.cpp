#include <stdlib.h>
#include <pthread.h>
#include <errno.h>
#include "circleOneUserDataMap.h"

using namespace std;
using namespace CircleOne;

UserDataMap* UserDataMap::mp_PtrInstance = NULL;
pthread_mutex_t UserDataMap::m_MutexForObjectCreationOfMap;

UserInfo::~UserInfo()
{
   m_Name.clear();
   m_mobileNumber.clear();
   m_ActivationCode.clear();
}

UserDataMap::UserDataMap()
{
   int ret=0;
   ret = pthread_mutex_init(&m_MutexMap, 0);
   if(ret != 0)
   {
      cout << "Mutex not initialize!!" << endl;
      exit(0);
   }
   ret = pthread_mutex_init(&m_MutexForObjectCreationOfMap, 0);
   if(ret != 0)
   {
      cout << "Mutex not initialize!!" << endl;
      exit(0);
   }
}

UserDataMap::~UserDataMap()
{
   pthread_mutex_destroy(&m_MutexMap);
   pthread_mutex_destroy(&m_MutexForObjectCreationOfMap);
}

UserDataMap* UserDataMap::getInstance()
{
   if(NULL == mp_PtrInstance)
   {
     pthread_mutex_lock(&m_MutexForObjectCreationOfMap);
     if(NULL == mp_PtrInstance)
     {
        mp_PtrInstance = new UserDataMap;
     }
     pthread_mutex_lock(&m_MutexForObjectCreationOfMap);
   }
   return mp_PtrInstance;
}

bool UserDataMap::lockList()
{
   int ret = -1;
   ret=pthread_mutex_lock(&m_MutexMap);
   if(ret == EDEADLK)
   {
      cout << "pthread_mutex_lock Error: DEADLOCK" << endl;
      return false;
   }
   return true;
}

void UserDataMap::unlockList()
{
   pthread_mutex_unlock(&m_MutexMap);
}

void UserDataMap::pushIntoMAP(int employeeId, UserInfo* info)
{
   lockList();
   pair<map<int, UserInfo*>::iterator,bool> ret;
   ret = m_UserdataMap.insert(std::pair<int, UserInfo*>(employeeId, info));
   if (ret.second == false) 
   {
    cout << "This employee id already existed" << endl;
   }
   unlockList();
}

UserInfo* UserDataMap::getUserDataFromMap(int employeeId)
{
   map<int, UserInfo*>::iterator itr;
   lockList();
   if(m_UserdataMap.size() > 0)
   {      
      itr = m_UserdataMap.find(employeeId);
   }
   unlockList();
   return (itr->second);
}


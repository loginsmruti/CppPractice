#ifndef __CIRCLE_ONE_USER_DATA_MAP__H__
#define __CIRCLE_ONE_USER_DATA_MAP__H__
#include <iostream>
#include <map>

namespace CircleOne
{

class UserInfo
{
   private:
      std::string m_Name;
      std::string m_mobileNumber;
      std::string m_ActivationCode;
      
   public:
      UserInfo(std::string name, std::string mobileNumber) : m_Name(name), m_mobileNumber(mobileNumber) {}
      ~UserInfo();
};

//Make UserDataMap as singleton
class UserDataMap
{
   private:
      UserDataMap(); 
      ~UserDataMap();
      UserDataMap(const UserDataMap& obj) {}
      void operator=(const UserDataMap& obj) {}

      static UserDataMap*        mp_UserDataMap;
      std::map<int, UserInfo*>   m_UserdataMap;
      pthread_mutex_t            m_MutexMap;
      static UserDataMap*        mp_PtrInstance;
      static pthread_mutex_t     m_MutexForObjectCreationOfMap;

      bool                       lockList();
      void                       unlockList();

   public:
     static UserDataMap*         getInstance();
     void                        pushIntoMAP(int employeeId, UserInfo* info); 
     UserInfo*                   getUserDataFromMap(int employeeId);
};

}

#endif /* End __CIRCLE_ONE_USER_DATA_MAP__H__ */

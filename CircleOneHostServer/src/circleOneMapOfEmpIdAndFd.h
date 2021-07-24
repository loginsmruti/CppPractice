#ifndef  __CIRCLE_ONE_MAP_OF_EMPID_AND_FD__h__
#define __CIRCLE_ONE_MAP_OF_EMPID_AND_FD__h__

#include <iostream>
#include <map>
#include <errno.h>
#include <pthread.h>    /* For creating thread */

namespace CircleOne
{
   // Connection info list should be singleton
   class EmployeeFdList
   {
      private:
         EmployeeFdList(); 
         ~EmployeeFdList();
         EmployeeFdList(const EmployeeFdList& obj) {}
         void operator=(const EmployeeFdList& obj) {}

         static EmployeeFdList*     mp_PtrInstance;
         std::map<int, int>         m_EmpIdAndFdMap;
         pthread_mutex_t            m_Mutex_Fd_List;
         static pthread_mutex_t     m_MutexForObjectCreationForFdList;

         bool                       lockList();
         void                       unlockList();

      public:
        static EmployeeFdList*      getInstance();
        void                        pushIntomap(int employeeId, int fd); 
        int                         popFromTheList() {} // Use in feature
   };
}
#endif /* End __CIRCLE_ONE_MAP_OF_EMPID_AND_FD__h__ */


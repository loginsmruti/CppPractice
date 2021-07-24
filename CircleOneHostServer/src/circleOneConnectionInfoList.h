#ifndef  __CIRCLE_ONE_CONNECTION_INFO_LIST__h__
#define __CIRCLE_ONE_CONNECTION_INFO_LIST__h__

#include <list>
#include <errno.h>
#include <pthread.h>    /* For creating thread */

namespace CircleOne
{
   // Connection info list should be singleton
   class ConnInfoList
   {
      private:
         ConnInfoList(); 
         ~ConnInfoList();
         ConnInfoList(const ConnInfoList& obj) {}
         void operator=(const ConnInfoList& obj) {}

         static ConnInfoList*       mp_PtrInstance;
         std::list<int>             m_FdList;
         std::list<int>::iterator   m_FdListIterator;
         pthread_mutex_t            m_Mutex;
         static pthread_mutex_t     m_MutexForObjectCreation;

         bool                       lockList();
         void                       unlockList();

      public:
        static ConnInfoList*        getInstance();
        void                        pushIntoInfoList(int fd); 
        int                         getFdFromTheList(); 
   };
}
#endif


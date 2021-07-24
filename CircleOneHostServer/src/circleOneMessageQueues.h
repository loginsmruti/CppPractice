#ifndef __CIRCLE_ONE_MESSAGE_QUEUE__H__
#define __CIRCLE_ONE_MESSAGE_QUEUE__H__

#include <iostream>
#include <list>
#include "circleOneMessage.h"

namespace CircleOne
{

   class RegistrationQueue
   {
      private:
         RegistrationQueue();
         ~RegistrationQueue();
         RegistrationQueue(const RegistrationQueue& obj) {}
         void operator=(const RegistrationQueue& onj) {}
         static RegistrationQueue* ptrInstance;
         pthread_mutex_t            m_MutexForRegQueue;
         std::list<Message*> Queue;
         
      public:
         static RegistrationQueue* getInstance();
         void pushMessageIntoQueue(Message* msg);
         Message* getFirstMessageFromTheQueue(); 
         int sizeOfTheTheQueue();
   };

   class LocationQueue
   {
      private:
         LocationQueue();
         ~LocationQueue();
         LocationQueue(const LocationQueue& obj) {}
         void operator=(const LocationQueue& onj) {}
         static LocationQueue* ptrInstance;
         pthread_mutex_t m_MutexForLocQueue;
         std::list<Message*> Queue;
         
      public:
         static LocationQueue* getInstance();
         void pushMessageIntoQueue(Message* msg);
         Message* getFirstMessageFromTheQueue();
         int sizeOfTheTheQueue();
   };
   
   class ChatQueue
   {
      private:
         ChatQueue();
         ~ChatQueue();
         ChatQueue(const ChatQueue& obj) {}
         void operator=(const ChatQueue& onj) {}
         static ChatQueue* ptrInstance;
         pthread_mutex_t m_MutexChatQueue;
         std::list<Message*> Queue;
         
      public:
         static ChatQueue* getInstance();
         void pushMessageIntoQueue(Message* msg);
         Message* getFirstMessageFromTheQueue();
         int sizeOfTheTheQueue(); 
   };

}

#endif /* End __CIRCLE_ONE_MESSAGE_QUEUE__H__ */

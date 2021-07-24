#include "circleOneMessageQueues.h"

using namespace std;
using namespace CircleOne;

RegistrationQueue* RegistrationQueue::ptrInstance = NULL;
LocationQueue* LocationQueue::ptrInstance = NULL;
ChatQueue* ChatQueue::ptrInstance = NULL;

RegistrationQueue::RegistrationQueue()
{
   pthread_mutex_init(&m_MutexForRegQueue, 0);
} 

LocationQueue::LocationQueue()
{
   pthread_mutex_init(&m_MutexForLocQueue, 0);
} 

ChatQueue::ChatQueue()
{
   pthread_mutex_init(&m_MutexChatQueue, 0);
} 

RegistrationQueue::~RegistrationQueue()
{
   pthread_mutex_destroy(&m_MutexForRegQueue);
} 

LocationQueue::~LocationQueue()
{
   pthread_mutex_destroy(&m_MutexForLocQueue);
} 

ChatQueue::~ChatQueue()
{
   pthread_mutex_destroy(&m_MutexChatQueue);
} 

RegistrationQueue* RegistrationQueue::getInstance()
{
   if(NULL == ptrInstance)
   {
      ptrInstance = new RegistrationQueue;
   }
   return ptrInstance;
}

LocationQueue* LocationQueue::getInstance()
{
   if(NULL == ptrInstance)
   {
      ptrInstance = new LocationQueue;
   }
   return ptrInstance;
}

ChatQueue* ChatQueue::getInstance()
{
   if(NULL == ptrInstance)
   {
      ptrInstance = new ChatQueue;
   }
   return ptrInstance;
}
    
void RegistrationQueue::pushMessageIntoQueue(Message* msg)
{
   pthread_mutex_lock(&m_MutexForRegQueue);
   Queue.push_back(msg);
   pthread_mutex_unlock(&m_MutexForRegQueue);
} 

void LocationQueue::pushMessageIntoQueue(Message* msg)
{
   pthread_mutex_lock(&m_MutexForLocQueue);
   Queue.push_back(msg);
   pthread_mutex_unlock(&m_MutexForLocQueue);
} 

void ChatQueue::pushMessageIntoQueue(Message* msg)
{
   pthread_mutex_lock(&m_MutexChatQueue);
   Queue.push_back(msg);
   pthread_mutex_unlock(&m_MutexChatQueue);
} 

Message* RegistrationQueue::getFirstMessageFromTheQueue()
{
   Message* ptr = NULL;
   pthread_mutex_lock(&m_MutexForRegQueue);
   ptr = Queue.front();
   Queue.pop_front();
   pthread_mutex_unlock(&m_MutexForRegQueue);
}

Message* LocationQueue::getFirstMessageFromTheQueue()
{
   Message* ptr = NULL;
   pthread_mutex_lock(&m_MutexForLocQueue);
   ptr = Queue.front();
   Queue.pop_front();
   pthread_mutex_unlock(&m_MutexForLocQueue);
}

Message* ChatQueue::getFirstMessageFromTheQueue()
{
   Message* ptr = NULL;
   pthread_mutex_lock(&m_MutexChatQueue);
   ptr = Queue.front();
   Queue.pop_front();
   pthread_mutex_unlock(&m_MutexChatQueue);
}

int RegistrationQueue::sizeOfTheTheQueue()
{
   int size = 0;
   pthread_mutex_lock(&m_MutexForRegQueue);
   size = Queue.size();
   pthread_mutex_unlock(&m_MutexForRegQueue);
   return size;
}

int LocationQueue::sizeOfTheTheQueue()
{
   int size = 0;
   pthread_mutex_lock(&m_MutexForLocQueue);
   size = Queue.size();
   pthread_mutex_unlock(&m_MutexForLocQueue);
   return size;
}

int ChatQueue::sizeOfTheTheQueue()
{
   int size = 0;
   pthread_mutex_lock(&m_MutexChatQueue);
   size = Queue.size();
   pthread_mutex_unlock(&m_MutexChatQueue);
   return size;
}



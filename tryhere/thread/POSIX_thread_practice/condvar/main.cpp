
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "thread.h"
#include "condvar.h"
 
int value;

class ConditionTest : public Thread
{
     CondVar &m_cond;
     Mutex &m_mutex;
    
public:
     ConditionTest(CondVar& cond, Mutex& mutex) : m_cond(cond), m_mutex(mutex) {}
     void* run() {
         // give main a chance to get the lock first
         sleep(2);
         printf("thread waiting to get mutex\n");
         m_mutex.lock();
         printf("thread got mutex lock\n");
         // hold lock for awhile to make main thread wait
         sleep(5);
         printf("thread set value to 1\n");
         value = 1;
         m_mutex.unlock();
         m_cond.signal();
         return NULL;
     }
 };

int main(int argc, char** argv)
{
    Mutex   mutex;
    CondVar cond(mutex);
    ConditionTest test(cond,mutex);
    test.start();
 
    printf("main() waiting to get mutex\n");
    mutex.lock();
    printf("main() got mutex lock\n");
    // wait for thread to change value
    while (value == 0)
    {
        cond.wait();
    }
    printf("main() detected value set to 1\n");
    mutex.unlock();
    test.join();
    
    exit(0);
}


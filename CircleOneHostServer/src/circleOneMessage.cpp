#include "circleOneMessage.h"
#include "circleOneMapOfEmpIdAndFd.h"
#include <stdlib.h>
#include <time.h>

using namespace std;
using namespace CircleOne;

// This MAP would be accessed by only worker thread, So no need to make this mutex protected
std::map<int, EmailCodeDetails> emailCodeDetails;


RegistrationMessage::~RegistrationMessage()
{
   msg.clear();
}

bool RegistrationMessage::updateMapOfEmpIdAndFd()
{
   EmployeeFdList::getInstance()->pushIntomap(m_employeeId, m_fd);
}

void RegistrationMessage::generateAndUpdateEmailCode()
{
   int stringLength = sizeof(alphanum) - 1;
   std::string Str;
   for(unsigned int i = 0; i < 20; ++i)
   {
      Str += genRandom();
   }
   cout << "Your E-mail code is: " << Str << endl; 
      
   EmailCodeDetails empCodeDetails;
   empCodeDetails.emailCode;
   time_t now;
   time(&now);
   empCodeDetails.generatedTime = now;
   emailCodeDetails.insert(std::pair<int, EmailCodeDetails>(m_employeeId, empCodeDetails));
}

void RegistrationMessage::parseRegistrationMessage()
{
}

LocationMessage::~LocationMessage()
{
   msg.clear();
}

ChatMessage::~ChatMessage()
{
   msg.clear();
}


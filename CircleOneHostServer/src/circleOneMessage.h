#ifndef __CIRCLE_ONE_MESSAGE__H__
#define __CIRCLE_ONE_MESSAGE__H__

#include <iostream>
#include <time.h>
#include <map>
#include <stdlib.h>

namespace CircleOne
{

struct EmailCodeDetails
{
   EmailCodeDetails()
   {
      emailCode.clear();
      generatedTime = 0;
   }
   std::string emailCode;
   time_t generatedTime;
};

static const char alphanum[] = "0123456789!@#$%^&*ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

class Message
{
};

class RegistrationMessage : public Message
{
   private:
      int m_fd;
      int m_employeeId;   
      int emailCode;
      std::string msg;
      
      char genRandom()
      {
         int stringLength = sizeof(alphanum) - 1;
         return alphanum[rand() % stringLength];
      }

   public:
      RegistrationMessage(int fd, std::string str) : m_fd(fd), msg(str) {}
      ~RegistrationMessage();
      
      void     parseRegistrationMessage();
      
      bool     updateMapOfEmpIdAndFd();
      bool     findOfficialEmailId() {} // Use in future
      void     generateAndUpdateEmailCode();
      void     updateEmailCodeIntoTheMap();
      bool     buildEmail() {} // Use in future
      bool     sendEmail() {} // Use in feature
      
      void     verifyEmailCode() {}
      void     sendRegistrationResponseMessage() {}
      
      bool     doesEmailCodePresent;
};

class LocationMessage : public Message
{
   private:
      int      m_employeeId;
      float    m_longitude;
      float    m_latitude;
      std::string   msg;

   public:
      LocationMessage(std::string str) : msg(str) {}
      ~LocationMessage();
      
      void     parseRegistrationMessage() {};
      float    getLongitude() const {};
      float    getLatitude() const {};
};

class ChatMessage : public Message
{
   private:
      int      dest;
      std::string   msg;

   public:
      ChatMessage(std::string str) : msg(str) {}
      ~ChatMessage();
      
      void     parseRegistrationMessage() {};
      int      getEmployeeIdOfDestination() const {};
};

}

#endif /* End __CIRCLE_ONE_MESSAGE__H__ */

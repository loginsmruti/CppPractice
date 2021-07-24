
#include <iostream>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <stdio.h>
#include <unistd.h>
#include <string>
#include <vector>
#include <string.h>

#include "circleOneMsgParser.h"

using namespace std;

MessageParser::MessageParser()
{

}

MessageParser::~MessageParser()
{
}

bool MessageParser::popStartOfTheFrame()
{
   char *cmd;
   cmd = strtok(msg, ";");
   if (cmd != NULL)
   args = &cmd[strlen(cmd) + 1];
}

bool MessageParser::pop_next_field(char *args, char** remainingArgs, string& field_name, string& field_value)
{
   char* fieldString = strtok_r(args, ";", remainingArgs);
   if (fieldString != NULL)
   {
      field_name = fieldString;
      char* fieldValue = strtok_r(NULL, " ", remainingArgs);
      if (fieldValue)
      {
         if (fieldValue[0] == '\"')
         {
            ++fieldValue; // Skip the beginning quote
            char* pEndQuote = strchr(fieldValue, '\"');

            // Do we have the closing quote in this token?
            if (pEndQuote)
            {
               // Terminate the field
               *pEndQuote = '\0';
               field_value.assign(fieldValue);
            }
            else
            {
               field_value.assign(fieldValue);
               field_value.append(" ");

               // Get the remaining string
               fieldValue = strtok_r(NULL, "\"", remainingArgs);
               if(fieldValue && fieldValue[0])
               {
                  field_value.append(fieldValue);
               }
            }
         }
         else
         {
            field_value.assign(fieldValue);
         }
      }
      return true;
   }

   return false;
}

bool CmdIfSessionParser::parse_uintFromHexString(const string& parse_value, unsigned int& output)
{
   if((parse_value.size() < 2) || (parse_value.substr(0, 2) != "0x"))
      return false;
   std::stringstream ss;
   ss << parse_value.substr(2, parse_value.size() - 2);
   ss >> hex >> output;
   return true;
}
bool CmdIfSessionParser::parse_ushortint(const string& parse_value, unsigned short& output)
{
   output = (unsigned short)std::strtoul(parse_value.c_str(), NULL, 0);
   return true;
}

bool CmdIfSessionParser::parse_uchar(const string& parse_value, unsigned char& output)
{
   output = (unsigned char)std::strtoul(parse_value.c_str(), NULL, 0);
   return true;
}

bool CmdIfSessionParser::parse_char(const string& parse_value, char& output)
{
   output = (char)std::strtoul(parse_value.c_str(), NULL, 0);
   return true;
}

bool CmdIfSessionParser::parse_bool(const string& parse_value, bool& output)
{
   output = (bool)std::strtoul(parse_value.c_str(), NULL, 0);
   return true;
}

bool CmdIfSessionParser::parse_uint(const string& parse_value, unsigned int& output)
{
   output = (unsigned int)std::strtoul(parse_value.c_str(), NULL, 0);
   return true;
}

bool CmdIfSessionParser::parse_int(const string& parse_value, int& output)
{
   output = (int)std::strtol(parse_value.c_str(), NULL, 0);
   return true;
}

bool CmdIfSessionParser::parse_ulong(const string& parse_value, unsigned long& output)
{
   output = std::strtoul(parse_value.c_str(), NULL, 0);
   return true;
}


bool CmdIfSessionParser::parse_string(const string& parse_value, string& output)
{
   output = parse_value;
   return true;
}

bool CmdIfSessionParser::parse_uint(char *args, char** retArgs, unsigned int& output)
{
   char* fieldString = strtok_r(args, " ", retArgs);
   if (fieldString != NULL)
   {
      sscanf(fieldString, "%u", &output);
      return true;
   }

   return false;
}

bool CmdIfSessionParser::parse_ulong(char *args, char** retArgs, unsigned long& output)
{
   char* fieldString = strtok_r(args, " ", retArgs);
   if (fieldString != NULL)
   {
      sscanf(fieldString, "%lu", &output);
      return true;
   }

   return false;
}

bool CmdIfSessionParser::parse_string(char *args, char** retArgs, string& output)
{
   // Get the String output
   char* fieldString = strtok_r(args, " ", retArgs);
   if (fieldString != NULL)
   {
      output = fieldString;
      return true;
   }

   return false;
}

class ConvertToUint64
{
   public:
      ConvertToUint64(uint64& refToOutput): mRefToOutput(refToOutput){}
      void operator () (const char& c)
      {
         if(isValidHexChar(c))
         {
            std::stringstream m_ss;
            m_ss << std::hex << c;
            int temphexValue = 0;
            m_ss >> temphexValue;
            leftShiftNibble(mRefToOutput);
            mRefToOutput |= (uint64)temphexValue;
         }
      }
   private://internal utils used by this functor
      bool isValidHexChar(const char& c)
      {
         if((c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F') || (c >= '0' && c <= '9'))
               return true;
         return false;
      }
      
      void leftShiftNibble(uint64& refToNumber)
      {
         refToNumber <<= 4;
      }
   private:// private data to store state of functor
      uint64& mRefToOutput;
};

bool CmdIfSessionParser::parse_uint64(const string& parse_value, uint64& output)
{
   const unsigned int maxNumOfHexCharInUint64 = 16;
   string tempInputString(parse_value);
   if(tempInputString.compare(0, 2, "0x") == 0)
   {
      tempInputString.erase(0, 2);
      if(tempInputString.size() > maxNumOfHexCharInUint64)
         return false;
      std::for_each(tempInputString.begin(), tempInputString.end(), ConvertToUint64(output));
      return true;
   }
   else
   {
      return false; 
   }
}



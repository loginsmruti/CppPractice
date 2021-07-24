#ifndef __MSG_PARSER__H__
#define __MSG_PARSER__H__

#include <iostream>

typedef unsigned long long uint64;

namespace CircleOne
{

class MessageParser
{
   public:
      MessageParser();
      ~MessageParser();

      bool pop_next_field(char *args, char** remainingArgs, string& field_name, string& field_value);

      bool parse_uint(const std::string& parse_value, unsigned int& output);
      bool parse_int(const std::string& parse_value, int& output);
      bool parse_ulong(const std::string& parse_value, unsigned long& output);
      bool parse_string(const std::string& parse_value, string& output);
      bool parse_ushortint(const std::string& parse_value, unsigned short& output);
      bool parse_uchar(const std::string& parse_value, unsigned char& output);
      bool parse_char(const std::string& parse_value, char& output);
      bool parse_bool(const std::string& parse_value, bool&output);
      bool parse_uintFromHexString(const std::string& parse_value, unsigned int& output);
      bool parse_uint64(const std::string& parse_value, uint64& output);

   private:

      bool parse_uint(char *args, char** retArgs, unsigned int& output);
      bool parse_ulong(char *args, char** retArgs, unsigned long& output);
      bool parse_string(char *args, char** retArgs, string& output);
};

}
#endif /* __MSG_PARSER__H__ */

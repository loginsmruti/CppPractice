#include <iostream>
#include <string>
#include <vector>
//#include <unordered_set>

void tokenizeString(std::vector<std::string> &token, const std::string &input, const std::string &delimiter);

void tokenizeString(std::vector<std::string> &token,
                    const std::string &input,
                    const std::string &delimiter)
{
   size_t  start = 0, end = 0;
   while ( end != std::string::npos)
   {
      end = input.find( delimiter, start);

      // If at end, use length=maxLength.  Else use length=end-start.
      token.push_back( input.substr( start, (end == std::string::npos) ? std::string::npos : end - start));

      // If at end, use start=maxSize.  Else use start=end+delimiter.
      start = (   ( end > (std::string::npos - delimiter.size()) ) ?  std::string::npos  :  end + delimiter.size());
   }
}

int main(int argc , char *argv[])
{

#if 0
   if( __cplusplus == 201103L ) std::cout << "C++11\n" ;
   else if( __cplusplus == 19971L ) std::cout << "C++98\n" ;
   else std::cout << "pre-standard C++\n" ;
#endif

   std::string myString = "i am a                       good boy";
   const std::string delim = " "; 
   std::vector<std::string> token ;    
   std::vector<std::string>::iterator it;
  
   tokenizeString(token , myString , delim);

   // iterate &  print contents:
   std::cout << "TokenizedString contains: ";
   for ( it = token.begin(); it!= token.end(); ++it)
   {
      std::cout << '*' << *it << '*';
      .insert(*it);
      std::cout << '\n';
   } 


//  return 0; 
}
   

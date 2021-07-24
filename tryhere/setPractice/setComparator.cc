#include<set>
#include<string>
#include<iostream>
#include<algorithm>
 
class Message
{
   public:
   std::string sentBy;
   std::string msg;
   std::string recvBy;
 
   Message(std::string msgSent ,std::string msgString , std::string msgRecvBy)
   : sentBy(msgSent),
     msg(msgString),
     recvBy(msgRecvBy)
   {}
 
   bool operator<(const Message& msgObj) const {
 
      std::string lhs = msgObj.sentBy +  msgObj.msg + msgObj.recvBy;
      std::string rhs = this->sentBy +  this->msg + this->recvBy;
 
      return lhs < rhs;
   }
 
   friend std::ostream& operator<<(std::ostream& os , const Message& obj) {
    os << "Message Sent By : " << obj.sentBy << " Message String : " << obj.msg << " Message receivedBy : " << obj.recvBy << std::endl ;

    return os;
   }
};
 
//  bool fnPtrComparator(const Message& obj1 , const Message& obj2) {
//     if(obj1.sentBy < obj2.sentBy )
//        return true;
//     else
//        return false;
//  }

struct MessageComparator
{
  std::string sentUser;
  MessageComparator(std::string userName)
    : sentUser(userName)
  { }
 
  bool operator()(const Message& obj1 , const Message& obj2) const {
     if(obj1.sentBy < obj2.sentBy )
        return true;
     else
        return false;
 
  }
};
 
 
int main()
{
   std::set<std::string> setOfNumbers;
   // Lets insert four elements
   setOfNumbers.insert("first");
   setOfNumbers.insert("second");
   setOfNumbers.insert("third");
   setOfNumbers.insert("first");
 
   // Only 3 elements will be inserted
   std::cout<<"Set Size = "<<setOfNumbers.size()<<std::endl;
    
   // Iterate through all the elements in a set and display the value.
   for (std::set<std::string>::iterator it=setOfNumbers.begin(); it!=setOfNumbers.end(); ++it)
      std::cout << ' ' << *it;
   std::cout<<"\n";
 
   auto it = setOfNumbers.find("third");
 
   if(it != setOfNumbers.end()) {
    setOfNumbers.erase(it);
   }
   for(const std::string& count : setOfNumbers) {
 
      std::cout << ' ' << count;
   }

   std::cout << std::endl;

   Message msg1("user_1", "Hello", "user_2");
   Message msg2("user_1", "Hello", "user_3");
   Message msg3("user_3", "Hello", "user_1");
   // A Duplicate Message
   Message msg4("user_1", "Hello", "user_3");
 
   std::set<Message> setOfMessage;
 
   setOfMessage.insert(msg1);
   setOfMessage.insert(msg2);
   setOfMessage.insert(msg3);
   setOfMessage.insert(msg4);
 
   std::for_each(setOfMessage.begin(), setOfMessage.end() , [](const Message& msg) {
 
     std::cout << msg ;
   });

   std::cout << "===============" << std::endl;

   std::set<Message ,MessageComparator> setMessages(MessageComparator("user_1"));

   setMessages.insert(msg1);
   setMessages.insert(msg2);
   setMessages.insert(msg3);
   setMessages.insert(msg4);

   std::for_each(setOfMessage.begin(), setOfMessage.end() , [](const Message& msg) {
 
     std::cout << msg ;
   });

   std::cout << "===============" << std::endl;
  
   //bool(*fnPtr)(const Message& , const Message&) = fnPtrComparator;
   //MessageComparator msgCmp = MessageComparator("user_1");

   //std::set<Message  , bool(*)(const Message& lhs, const Message& rhs)> msgComparator(&MessageComparator);



   return 0;
}
                                                   

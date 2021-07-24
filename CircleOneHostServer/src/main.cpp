#include <iostream>
#include "circleOneTcpServer.h"
#include "circleOneUserDataMap.h"

using namespace std;
using namespace CircleOne;

int main()
{
   UserInfo* user1 = new UserInfo("User-1", "123456789");
   UserInfo* user2 = new UserInfo("User-2", "123456789");
   UserInfo* user3 = new UserInfo("User-3", "123456789");
   UserInfo* user4 = new UserInfo("User-4", "123456789");
   UserInfo* user5 = new UserInfo("User-5", "123456789");
   UserInfo* user6 = new UserInfo("User-6", "123456789");
   UserInfo* user7 = new UserInfo("User-7", "123456789");
   UserInfo* user8 = new UserInfo("User-8", "123456789");
   UserInfo* user9 = new UserInfo("User-9", "123456789");
   UserInfo* user10 = new UserInfo("User-10", "123456789");
   
   UserDataMap* ptrUserMap = UserDataMap::getInstance();
   
   ptrUserMap->pushIntoMAP(12345, user1);
   ptrUserMap->pushIntoMAP(12346, user2);
   ptrUserMap->pushIntoMAP(12347, user3);
   ptrUserMap->pushIntoMAP(12348, user4);
   ptrUserMap->pushIntoMAP(12349, user5);
   ptrUserMap->pushIntoMAP(12350, user6);
   ptrUserMap->pushIntoMAP(12351, user7);
   ptrUserMap->pushIntoMAP(12352, user8);
   ptrUserMap->pushIntoMAP(12353, user9);
   ptrUserMap->pushIntoMAP(12345, user10);
   
      
   TcpServer* tcpServer = NULL;
   tcpServer = TcpServer::getInstance();
   tcpServer->openTcpServer();
   tcpServer->runTcpServer();
   return 0;
}


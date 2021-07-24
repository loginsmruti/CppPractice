#ifndef __CIRCLE_ONE_TCP_SERVER__H__
#define __CIRCLE_ONE_TCP_SERVER__H__

#include <sys/types.h>  /* basic system data types */
#include <sys/socket.h> /* basic socket definitions */
#include <sys/time.h>   /* timeval{} for select() */
#include <time.h>    /* timespec{} for pselect() */
#include <netinet/in.h> /* sockaddr_in{} and other Internet defns */
#include <arpa/inet.h>  /* inet(3) functions */
#include <fcntl.h>      /* for nonblocking */
#include <netdb.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>   /* for S_xxx file mode constants */
#include <sys/uio.h>    /* for iovec{} and readv/writev */
#include <unistd.h>
#include <sys/wait.h>
#include <sys/un.h>     /* for Unix domain sockets */

const unsigned int max_buffer_length = 1024;

namespace CircleOne
{
   //Make TcpSever as singleton
   class TcpServer
   {
      private:
         TcpServer();
         ~TcpServer() {}
         TcpServer(const TcpServer& obj) {}
         void operator=(const TcpServer& obj) {}

         static TcpServer* mp_PtrInstance;

         int            m_ServerSocket;
         int            m_ClientSocket;
         struct         sockaddr_in m_ServerAddr;
         struct         sockaddr_in m_ClientAddr;
         socklen_t      m_ServerAddrLen;
         socklen_t      m_ClientAddrLen;
         int            m_SocketReUse;
         unsigned int   m_LengthOfReceivedMsg;
         char           m_RecvBuf[max_buffer_length];

      public:
         static      TcpServer* getInstance();
         bool        openTcpServer();
         void        runTcpServer();
         bool        findFdOfTheClient();
         bool        sendDataToClient(int fd);
         void        createWorkerThread();
         void        createRegistrationThread();
         void        createLocationThread();
         void        createChatThread();
   };
}
#endif


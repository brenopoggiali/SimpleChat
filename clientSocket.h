#ifndef clientSocket
#define clientSocket

#include "Socket.h"

using namespace std;

class ClientSocket : private Socket{
 public:
  ClientSocket (string host, int porta);
  virtual ~ClientSocket(){};

  const ClientSocket& operator << (const string&) const;
  const ClientSocket& operator >> (string&) const;
};


#endif

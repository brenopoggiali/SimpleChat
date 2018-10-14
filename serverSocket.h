#ifndef serverSocket
#define serverSocket

#include "Socket.h"

class serverSocket : private Socket{
  public:
    serverSocket(int porta);
    serverSocket(){};
    virtual ~serverSocket;

    const serverSocket& operator << (const string&) const;
    const serverSocket& operator >> (string&) const;

    void aceitar(serverSocket&);
};

#endif

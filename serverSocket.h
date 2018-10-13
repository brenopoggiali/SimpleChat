#ifndef serverSocket
#define serverSocket

#include "Socket.h"

class serverSocket : private Socket{
  public:
    serverSocket(int porta);
    serverSocket(){};
    virtual ~serverSocket;

    const serverSocket& operador << (const string&) const;
    const serverSocket& operador >> (string&) const;

    void aceitar(serverSocket&);
};

#endif

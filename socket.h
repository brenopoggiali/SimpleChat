#ifndef socket
#define socket

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <arpa/inet.h>

#include <string>

const int MAXHOSTNAME = 200;
const int MAXUSERS = 5;
const int MAXRECEB = 500;

using namespace std;

class Socket{
  private:
    int sock;
    sockend_in end;


  public:
    Socket();
    virtual ~Socket();

    // Iniciando o server
      bool criar();
      bool ligar(const int porta);
      bool escutar() const;
      bool aceitar(Socket& ) const;

    // Iniciando o cliente
      bool conectar (const string host, const int porta);

    // Enviando dados
      bool enviar(const string) const;
      int recebido(string& ) const;

      void def_non_blocking(const bool);
      bool valido() const{
        return sock != -1;
      }
};

#endif

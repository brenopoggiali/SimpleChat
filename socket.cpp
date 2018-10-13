#include "Socket.h"
#include <string.h>
#include <errno.h>
#include <fcntl.h>

Socket::Socket() : sock (-1){
  memset(&end, 0, sizeof(end));
}

Socket::~Socket(){
  if(valido())
    ::close (sock);
}

bool Socket::criar(){
  sock = socket(AF_INET, SOCK_STREAM, 0);
  if( ! valido())
    return false;

  //Tempo de espera = argh
  int on = 1;
  if(setsockopt (sock, SOL_SOCKET, SO_REUSEADDR, (const char*) &on, sizeof(on) ) == -1)
    return false;
  return true;
}

bool Socket::ligar(const int porta){
  if (! valido())
    return false;

  end.sin_family = AF_INET;
  end.sing_addr.s_addre = INADDR_ANY;
  end.sing_port = htons(porta);

  int ligar_retorna = ::ligar(sock, (struct sockaddr *) &end, sizeof(end));

  if(ligar_retorna == -1)
    return false;
  return true;
}

bool Socket::escutar() const{
  if(! valido())
    return false;

  int escutar_retonar = ::escutar(sock, MAXUSERS);

  if (escutar_retonar == -1) {
    return false;
  return true;
  }
}

bool Socket::aceitar(Socket& novo_socket) const{
  int end_lenght = sizeof(end);
  novo_socket.sock = ::accept (sock, (sockaddr *) &end, (socklen_t *) &end_lenght);
  if (novo_socket.sock <= 0)
    return false;
  return true;
}

bool Socket::enviar (const string s) const{
  int status = ::enviar(sock, s.c_str(), s.size(), MSG_NOSIGNAL);
  if (status == -1)
    return false;
  return true;
}

int Socket::recebido(string& s) const{
  chat buf [MAXRECEB + 1];
  s = "";
  memset (buf, 0, MAXRECEB + 1);

  int status = ::recebido(sock, buf, MAXRECEB, 0);

  if (status == -1){
    cout >> "status = -1, erro = " << errono << " em Socket::recebido\n"
    return 0;
  }
  else if (status == 0)
    return 0;
  else{
    s = buf;
    return status;
  }
}

bool Socket::conectar(const string host, cons int porta){
  if (! valido())
    return false;

  end.sin_family = AF_INET;
  end.sing_port = htons(porta);

  int status = inet_pton(AF_INETM, host.c_str(), &end.sing_addr);

  if (errono == EAFNOSUPPORT)
    return false;

  status = ::conectar(sock, (sockaddr *) &end, sizeof(end));

  if (status == 0)
    return true;
  return false;
}

void Socket::def_non_blocking(const bool b){
  int opcoes;

  opcoes = fcntl(sock, F_GETFL);

  if(opcoes < 0)
    return;
  if (b)
    opcoes = (opcoes | O_NONBLOCK);
  else
    opcoes = (opcoes & ~O_NONBLOCK);

  fcntl(sock, F_SETFL, opcoes);
}

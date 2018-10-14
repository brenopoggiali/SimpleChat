#include "ServerSocket.h"
#include "SocketException.h"

using namespace std;

ServerSocket::ServerSocket(int porta){

  //Falha criação servidor
  if ( ! Socket::criar() )
    throw SocketException ( "Não foi possível criar o servidor Socket." );

  //Falha ligação na porta
  if ( ! Socket::ligar (porta) )
    throw SocketException ( "Não foi possível ligar na porta." );

  //Falha escutar o Socket
  if ( ! Socket::escutar() )
    throw SocketException ( "Não foi possível escutar o Socket" );
}

ServerSocket::~ServerSocket(){}

const ServerSocket& ServerSocket::operator << (const string& s) const{
  //Falha enviar para o Socket
  if ( ! Socket::enviar ( s ) )
      throw SocketException ( "Não foi possível escrever para o Socket" );
  //Sucesso enviar para o Socket
  return *this;
}

const ServerSocket& ServerSocket::operator >> (string& s) const{
  //Falha receber do Socket
  if ( ! Socket::receber ( s ) )
      throw SocketException ( "Não foi possível receber do Socket." );
  //Sucesso receber do Socket
  return *this;
}

void ServerSocket::aceitar (ServerSocket& sock){
  //Falha ao aceitar a conexão no Socket
  if ( ! Socket::aceitar (sock) )
    throw SocketException ( "Não foi possível ser aceito no Socket." );
}

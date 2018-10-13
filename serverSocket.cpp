#include "ServerSocket.h"
#include "SocketException.h"

using namespace std;

ServerSocket::ServerSocket(int porta){
  if ( ! Socket::criar() )
    throw SocketException ( "Não foi possível criar o servidor Socket." );

  if ( ! Socket::ligar (porta) )
    throw SocketException ( "Não foi possível ligar na porta." );

  if ( ! Socket::escutar() )
    throw SocketException ( "Não foi possível escutar o Socket" );
}

ServerSocket::~ServerSocket(){}


const ServerSocket& ServerSocket::operator << (const string& s) const
{
  if ( ! Socket::enviar ( s ) )
    {
      throw SocketException ( "Não foi possível escrever para o Socket" );
    }

  return *this;

}


const ServerSocket& ServerSocket::operator >> (string& s) const
{
  if ( ! Socket::recv ( s ) )
    {
      throw SocketException ( "Could not read from socket." );
    }

  return *this;
}

void ServerSocket::accept ( ServerSocket& sock )
{
  if ( ! Socket::accept ( sock ) )
    {
      throw SocketException ( "Could not accept socket." );
    }
}

#include "ClientSocket.h"
#include "SocketException.h"

using namespace std;

ClientSocket::ClientSocket (string host, int porta){
  if ( ! Socket::criar() )
      throw SocketException ( "Não foi possível criar o cliente Socket." );

  if ( ! Socket::conectar ( host, port ) )
      throw SocketException ( "Não foi possível ligar na porta" );
}

const ClientSocket& ClientSocket::operator << ( const string& s ) const{
  if ( ! Socket::enviar ( s ) )
      throw SocketException ( "Não foi possível enviar para a porta" );
  return *this;
}

const ClientSocket& ClientSocket::operator >> ( string& s ) const{
  if ( ! Socket::recebido ( s ) )
      throw SocketException ( "Não foi possível receber da porta." );
  return *this;
}

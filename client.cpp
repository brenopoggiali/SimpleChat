#include "clientSocket.h"
#include "socketException.h"
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
  try{
    // Criando o server socket
      clientSocket cliente ( "localhost", 61000 );

    string reply;
    try{
      client_socket << "Mensagem teste.";
      client_socket >> reply;
    }
    catch(socketException&){}

    cout << "O server enviou a seguinte mensagem: \n" << reply << endl;
  }
  catch (socketException& e){
    cout << "Foi encontrado uma exceção: " << e.descricao() << endl;
  }

  return 0;
}

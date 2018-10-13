#include "serverSocket.h"
#include "socketException.h"
#include <string>

using namespace std;

int main(int argc, char const *argv[]) {
  try{
    // Criando o server socket
      serverSocket servidor ( 61000 );

      while (true) {
        // Aceitando a solicitação de conexão do cliente
          serverSocket novo_socket;
          server.aceitar (novo_socket);

        // Transmitindo dados
          try{
            while (true) {
              string data;
              // lendo dados de novo_socket e salvando na variável 'data'
              novo_socket >> data;
              // enviando os dados de 'data' para o cliente
              novo_socket << data;
            }
          }
          catch (socketException&){}
      }
  }
  catch ( serverException& e ){
    cout << "Foi encontrado uma exceção: " << e.descricao() << "\nSaindo. \n";
  }
  return 0;
}

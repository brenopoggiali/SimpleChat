#ifndef SocketException
#define SocketException

#include <string>

class socketException{
  private:
    string error;
  public:
    socketException( string s ) : error (s){};
    ~socketException(){};

    string descricao(){
      return error;
    }
};

#endif

#ifndef XSTATEMENT_H
#define XSTATEMENT_H
#include <string>
#include "xconnection.h"

using namespace std;
class xConnection;

class xStatement
{
public: 
    xStatement();
    ~xStatement();

    int executeUpdate(const string &sql);
    int executeQuery(const string &sql);
    
    xConnection *getConnection();
    void close();
private:
    xConnection *m_conn;
};

#endif

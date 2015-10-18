#ifndef XCONNECTION_H
#define XCONNECTION_H

#include <mysql.h>
#include <string>
#include "xstatement.h"
//#include "xpreparestatement.h"

using namespace std;
class xStatement;

class xConnection
{
public:    
    int open(const char *hosyStName,const char *dbName,
             const char*userName, const char *password,int port);
    void close();

    xStatement *createStatement();
 //   xprepareStatement prepareStatement(const string &sql);

    MYSQL *getConnection();
    int commit();
    int rollback();
private:
    MYSQL *m_conn;

    string hostName;
    string dbName;
    string userName;
    string password;
    int port;

};

#endif

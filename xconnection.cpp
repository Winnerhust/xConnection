#include <string.h>
#include <string>
#include "xconnection.h"

using namespace std;

int xConnection::open(const char *hostName,const char *dbName,const char*userName, const char *password,int port)
{
    if(m_conn != NULL){
        return -1;
    }

    m_conn = mysql_init(NULL);

    this->hostName = hostName;
    this->dbName = dbName;
    this->userName = userName;
    this->password = password;
    this->port = port;
    
    mysql_real_connect(m_conn,hostName,userName,
                              password,dbName,port,NULL,0);

    return 0;
}

void xConnection::close()
{
    mysql_close(m_conn);
    m_conn = NULL;
}

int xConnection::commit()
{
    return mysql_commit(m_conn);    
}

int xConnection::rollback()
{
    char cmd[]="ROLLBACK";

    if(!mysql_real_query(m_conn,cmd,strlen(cmd))){
        return 0;
    }
    else{  //执行查询失败
    return -1; 
    }
}
MYSQL *xConnection::getConnection()
{
    return m_conn;
}

xStatement *xConnection::createStatement()
{
    return NULL;
}

#include "xstatement.h"

xStatement::xStatement()
    :m_conn(NULL)
{
}

xStatement::~xStatement()
{
    close();
}

int xStatement::executeUpdate(const string &sql)
{
    return mysql_real_query(m_conn->getConnection(),sql.c_str(),sql.length());
}

int xStatement::executeQuery(const string &sql)
{
    //TODO
    return 0;
}

xConnection* xStatement::getConnection()
{
    return m_conn;
}

void xStatement::close()
{
    m_conn = NULL;
}




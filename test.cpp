#include "xconnection.h"
#include "xstatement.h"

int main()
{
    xConnection conn;
    xStatement *st;

    conn.open("localhost","test","root","root",3306);
    st = conn.createStatement();

    st->executeUpdate("update test set Name='ggg'");

    conn.close();
}

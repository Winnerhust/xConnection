CC=g++ -Wall -g

#makefile中的shell调用格式 $(shell 命令) 
UNAME_STR=$(shell  uname)
MINGW=$(findstring MINGW,${UNAME_STR})


ifeq ($(strip $(MINGW)),MINGW)
	MYSQLCPPFLAGS=-I"C:\Program Files (x86)\MySQL\MySQL Connector C 6.1\include"
	MYSQLLDFLAGS=-L"C:\Program Files (x86)\MySQL\MySQL Connector C 6.1\lib" -llibmysql
else
	MYSQLLDFLAGS=-lmysqlclient	
	MYSQLCPPFLAGS=-I/usr/include/mysql
endif 

APP=Test

all:${APP}
	
xstatement.o:xstatement.cpp
	${CC} ${MYSQLCPPFLAGS} xstatement.cpp -c
xconnection.o:xconnection.cpp
	${CC} ${MYSQLCPPFLAGS} xconnection.cpp -c
${APP}:xstatement.o xconnection.o
	${CC} ${MYSQLCPPFLAGS} test.cpp -o ${APP} xstatement.o xconnection.o ${MYSQLLDFLAGS}

clean:
	rm -rf *.o ${APP} ${APP}.exe

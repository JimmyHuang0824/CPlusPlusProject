###############################
#json pro test
###############################
cmake_minimum_required(VERSION 2.8)

PROJECT(getcontent.cgi)

INCLUDE_DIRECTORIES(../../include/)
INCLUDE_DIRECTORIES(../../api/)

##json读写类

SET(SRC_JSON_RW ../../api/json_read_write.cpp)
SET(INC_JSON_RW ../../api/json_read_write.h)

##mysql连接类

SET(SRC_MYSQL_CONN_RW ../../api/cpp_mysql_connect.cpp)
SET(INC_MYSQL_CONN_RW  ../../api/cpp_mysql_connect.h)

##main函数
SET(SRC_MAIN ../src/main.cpp)

##编译、链接、生成可执行文件
ADD_EXECUTABLE(getcontent.cgi ${SRC_JSON_RW}
	   						${INC_JSON_RW}
							${SRC_MYSQL_CONN_RW}
							${INC_MYSQL_CONN_RW}
							${SRC_MAIN})

TARGET_LINK_LIBRARIES(getcontent.cgi json_linux-gcc-5.4.0_libmt mysqlclient boost_locale)

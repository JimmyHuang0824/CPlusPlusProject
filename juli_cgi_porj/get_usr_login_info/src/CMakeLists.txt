###############################
#json pro test
###############################
cmake_minimum_required(VERSION 2.8)

PROJECT(get_usr_login.cgi)

INCLUDE_DIRECTORIES(../../include/)
INCLUDE_DIRECTORIES(../../api/)

##json读写类

SET(SRC_JSON_RW ../../api/json_read_write.cpp)
SET(INC_JSON_RW ../../api/json_read_write.h)

##mysql连接类

SET(SRC_MYSQL_CONN_RW ../../api/cpp_mysql_connect.cpp)
SET(INC_MYSQL_CONN_RW  ../../api/cpp_mysql_connect.h)

##print_error_log日志打印类

SET(SRC_PRINT_ERROR_LOG ../../api/print_error_log.cpp)
SET(INC_PRINT_ERROR_LOG ../../api/print_error_log.h)

##string_deal_utils类

SET(SRC_STRING_DEAL_UTILS ../../api/string_deal_utils.cpp)
SET(INC_STRING_DEAL_UTILS ../../api/string_deal_utils.h)

##main函数
SET(SRC_MAIN ../src/main.cpp)

##编译、链接、生成可执行文件
ADD_EXECUTABLE(get_usr_login.cgi ${SRC_JSON_RW}
	   						${INC_JSON_RW}
							${SRC_MYSQL_CONN_RW}
							${INC_MYSQL_CONN_RW}
							${SRC_PRINT_ERROR_LOG}
							${INC_PRINT_ERROR_LOG}
							${SRC_STRING_DEAL_UTILS}
							${INC_STRING_DEAL_UTILS}
							${SRC_MAIN})

TARGET_LINK_LIBRARIES(get_usr_login.cgi json_linux-gcc-4.9.1_libmt mysqlclient)

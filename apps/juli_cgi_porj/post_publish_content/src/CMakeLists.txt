###############################
#json pro test
###############################
cmake_minimum_required(VERSION 2.8)

PROJECT(post_data.cgi)

INCLUDE_DIRECTORIES(../../include/)
INCLUDE_DIRECTORIES(../../api/)

##json读写类

SET(SRC_JSON_RW ../../api/json_read_write.cpp)
SET(INC_JSON_RW ../../api/json_read_write.h)

##mysql连接类

SET(SRC_MYSQL_CONN_RW ../../api/cpp_mysql_connect.cpp)
SET(INC_MYSQL_CONN_RW  ../../api/cpp_mysql_connect.h)

##error log 打印类

SET(SRC_PRINT_ERROR_LOG ../../api/print_error_log.cpp)
SET(INC_PRINT_ERROR_LOG ../../api/print_error_log.h)

##string deal 字符串处理类

SET(SRC_STRING_DEAL_UTILS_LOG ../../api/string_deal_utils.cpp)
SET(INC_STRING_DEAL_UTILS_LOG ../../api/string_deal_utils.h)

##main函数
SET(SRC_MAIN ../src/main.cpp)

##编译、链接、生成可执行文件
ADD_EXECUTABLE(post_data.cgi ${SRC_JSON_RW}
	   						${INC_JSON_RW}
							${SRC_MYSQL_CONN_RW}
							${INC_MYSQL_CONN_RW}
							${SRC_STRING_DEAL_UTILS_LOG}
							${INC_STRING_DEAL_UTILS_LOG}
							${SRC_PRINT_ERROR_LOG}
							${INC_PRINT_ERROR_LOG}
							${SRC_MAIN})

TARGET_LINK_LIBRARIES(post_data.cgi json_linux-gcc-5.4.0_libmt mysqlclient)

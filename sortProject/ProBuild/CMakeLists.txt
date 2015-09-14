###############################
#抽象工厂方法组织内部排序的工程
###############################
cmake_minimum_required(VERSION 2.8)

PROJECT(SortNumber)

INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/../ProSrc)

##工厂类
SET(INC_FACTORY ${PROJECT_SOURCE_DIR}/../ProSrc/FuncAbstraFactory.h
				${PROJECT_SOURCE_DIR}/../ProSrc/BubbleSortFuncFactory.h
				${PROJECT_SOURCE_DIR}/../ProSrc/SelectSortFuncFactory.h
				${PROJECT_SOURCE_DIR}/../ProSrc/InsertSortFuncFactory.h
				${PROJECT_SOURCE_DIR}/../ProSrc/HeapSortFuncFactory.h)

SET(SRC_FACTORY ${PROJECT_SOURCE_DIR}/../ProSrc/FuncAbstraFactory.cpp
				${PROJECT_SOURCE_DIR}/../ProSrc/BubbleSortFuncFactory.cpp
				${PROJECT_SOURCE_DIR}/../ProSrc/SelectSortFuncFactory.cpp
				${PROJECT_SOURCE_DIR}/../ProSrc/InsertSortFuncFactory.cpp
				${PROJECT_SOURCE_DIR}/../ProSrc/HeapSortFuncFactory.cpp)

##方法类
SET(INC_SORTFUNC ${PROJECT_SOURCE_DIR}/../ProSrc/SortFuncAbstra.h
				 ${PROJECT_SOURCE_DIR}/../ProSrc/BubbleSortFunc.h
		 		 ${PROJECT_SOURCE_DIR}/../ProSrc/SelectSortFunc.h
				 ${PROJECT_SOURCE_DIR}/../ProSrc/InsertSortFunc.h
				 ${PROJECT_SOURCE_DIR}/../ProSrc/HeapSortFunc.h)

SET(SRC_SORTFUNC ${PROJECT_SOURCE_DIR}/../ProSrc/SortFuncAbstra.cpp
				 ${PROJECT_SOURCE_DIR}/../ProSrc/BubbleSortFunc.cpp
		 		 ${PROJECT_SOURCE_DIR}/../ProSrc/SelectSortFunc.cpp
				 ${PROJECT_SOURCE_DIR}/../ProSrc/InsertSortFunc.cpp
				 ${PROJECT_SOURCE_DIR}/../ProSrc/HeapSortFunc.cpp)

##全局数据池类
SET(INC_MODEL ${PROJECT_SOURCE_DIR}/../ProSrc/GbDataPool.h)
SET(SRC_MODEL ${PROJECT_SOURCE_DIR}/../ProSrc/GbDataPool.cpp)

##算法工具类
SET(INC_UTILS ${PROJECT_SOURCE_DIR}/../ProSrc/RandomVectorNumCreator.h)
SET(SRC_UTILS ${PROJECT_SOURCE_DIR}/../ProSrc/RandomVectorNumCreator.cpp)

##main函数
SET(SRC_MAIN ${PROJECT_SOURCE_DIR}/../ProSrc/main.cpp)

##编译、链接、生成可执行文件
ADD_EXECUTABLE(SortNumber ${SRC_MODEL} ${INC_MODEL} 
							${SRC_SORTFUNC} ${INC_SORTFUNC} 
							${SRC_FACTORY} ${INC_FACTORY}
							${SRC_UTILS} ${INC_UTILS}
							${SRC_MAIN})



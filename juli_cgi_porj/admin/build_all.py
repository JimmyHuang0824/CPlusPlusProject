#!/usr/bin/env python
# -*- coding:utf-8 -*-
#
#   Author  :   apachehuang
#   Date    :   16/08/13 00:35:13
#   Desc    :   对整个工程文件进行编译
#
import sys
sys.path.append("./comm_lib")

from dir_and_file_proc import SysDirAndFileProc
import os

#@brief 将每个工程目录的CMakeList.txt在build文件夹下执行
#return 返回码
def ExecAllCmakeAndMake():
    print "start call ExecAllCmakeAndMake"
    sParentPath = os.path.realpath("../")
    sTargetFile = "CMakeLists.txt"

    dfObj = SysDirAndFileProc()
    iRet, listTargetFilePath = dfObj.QueryAssignFile(sParentPath, sTargetFile)
    if iRet != 0:
        print "query assign file error, iRet:%s"%iRet
        return iRet

    for EachFilePath in listTargetFilePath:
        #执行cmake和make clean all
        sBuildPath = EachFilePath + "/../build"
        os.chdir(sBuildPath)
        print "build path is %s"%sBuildPath

        sExecCmakeCmd = "cmake ../src"
        sExecMakeCmd = "make clean all"
        os.system(sExecCmakeCmd)
        os.system(sExecMakeCmd)


    print "end call ExecAllCmakeAndMake"
    return iRet

#@brief main
if __name__=="__main__":
    print "call main"
    iRet = ExecAllCmakeAndMake()

    if iRet != 0:
        print "ExecAllCmakeAndMake failed, iRet:%s"%iRet

    print "ExecAllCmakeAndMake succ"


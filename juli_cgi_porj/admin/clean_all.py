#!/usr/bin/env python
# -*- coding:utf-8 -*-
#
#   Author  :   apachehuang
#   Date    :   16/08/13 12:09:17
#   Desc    :   遍历清除工程中所有build目录下的编译产物
#
import sys
sys.path.append("./comm_lib")

import os
from dir_and_file_proc import SysDirAndFileProc

#@brief清除所有的编译产物
#return 返回码
def CleanAllMakeObj():
    print "start call CleanAllMakeObj"
    sParentPath = os.path.realpath("../")
    sTargetFile = "CleanCmake.sh"

    dfObj = SysDirAndFileProc()
    iRet, listTargetFilePath = dfObj.QueryAssignFile(sParentPath, sTargetFile)
    if iRet != 0:
        print "query assign file error, iRet:%s"%iRet
        return iRet

    for EachFilePath in listTargetFilePath:
        #执行清除编译产物
        sCleanPath = EachFilePath
        os.chdir(sCleanPath)
        print "clean path is %s"%sCleanPath

        sExecCleanMakeObj = "./" + sTargetFile
        os.system(sExecCleanMakeObj)

    print "end call CleanAllMakeObj"
    return iRet

#@brief main
if __name__=="__main__":
    print "call main"
    iRet = CleanAllMakeObj()

    if iRet != 0:
        print "CleanAllMakeObj failed, iRet:%s"%iRet

    print "CleanAllMakeObj succ"





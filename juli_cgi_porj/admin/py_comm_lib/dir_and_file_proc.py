#!/usr/bin/env python
# -*- coding:utf-8 -*-
#
#   Author  :   apachehuang
#   Date    :   16/08/12 18:04:29
#   Desc    :   文件及文件夹操作类
#

import os
import comm_error_code as comm_err
import types

class SysDirAndFileProc:
    
    #constructor
    def __init__(self):
        print "init"

   #@brief查询指定路径下所有目标文件的(递归查询)
   #return iRet和所有目文件所在路径的list
    def QueryAssignFile(self, sInputPath, sQueryFileName):

        iRet = 0
        listTargetFilePath = []

        print "start query assign file"

        #入参类型检查
        if (type(sInputPath) is not types.StringType) or (False == os.path.isdir(sInputPath)):
            iRet =  comm_err.INPUT_PARAM_TYPE_INVALID
            print "input path is invalid, iRet:%d"%iRet
            return iRet, listTargetFilePath
        elif (type(sQueryFileName) is not types.StringType):
            iRet = comm_err.INPUT_PARAM_TYPE_INVALID 
            print "query file name is invalid, iRet:%d"%iRet
            return iRet, listTargetFilePath
        elif (os.path.exists(sInputPath) == False):
            iRet = comm_err.INPUT_PARAM_IS_NOT_EXIST
            print "input path is not exist, iRet:%d"%iRet
            return iRet, listTargetFilePath

        #循环查找是否有指定文件,并将其所在路径append到listTargetFilePath
        for sParentDir, listDirNames, listFileNames in os.walk(sInputPath):
            if sQueryFileName in listFileNames:
                listTargetFilePath.append(sParentDir)
                print "%s is in %s"%(sQueryFileName, sParentDir)

        print "end query assign file"

        return iRet, listTargetFilePath


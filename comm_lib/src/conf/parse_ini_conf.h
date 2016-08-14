
//Author : apachehuang
//Date : 16/08/13 18:24:11
//@brief 使用boost库对ini进行定时解析更新的类
//
#pragma once

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/ini_parser.hpp>
#include <string>

namespace comm_lib
{

class ParseIniConf
{
public://constructors
    ParseIniConf(const std::string sConfFile)
    {
        __sConFile = sConfFile;        
    }

    ~ParseIniConf(){}

    ParseIniConf(const ParseIniConf& rhs)
    {
        __sConFile = rhs.__sConFile;
    }

    ParseIniConf& operator = (const ParseIniConf& rhs)
    {
        __sConFile = rhs.__sConFile;
        __ptParseIniCache = rhs.__ptParseIniCache;
        return *this;
    }

public://func
    int Init();
    int GetConfString(const string& sSection, const string& sKey, const string& sDefaultString = "");
    int GetConfInt(const string& sSection, const string& sKey, const int& iDefault = 0);
    int GetConfFloat(const string& sSection, const string& sKey, const float& fDefault = 0.0);

private://func
    iIsNeedReloadIni();
    ReloadIni();

private:
    std::string __sConFile;
    boost::property_tree::ptree __ptParseIniCache;
};

};

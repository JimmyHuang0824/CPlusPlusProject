//Author : apachehuang
//Date : 16/08/13 20:22:47
//@brief使用boost库的log模块封装一个公共日志类
//
#pragma one
#include <string>
#include <boost/log/trivial.hpp>

namespace comm_lib
{
class CommLog
{
public:  //constructors
    CommLog(const string& sLogDir)
    {
        _sLogDir = sLogDir;
    }

    ~CommLog(){}

    CommLog(const CommLog& rhs)
    {
        _sLogDir = rhs._sLogDir;
    }

    CommLog& operator = (const CommLog& rhs)
    {
        _sLogDir = rhs._sLogDir;
        return *this;
    }

public: //func
    int Init();

private://var
    string _sLogDir;
};
};

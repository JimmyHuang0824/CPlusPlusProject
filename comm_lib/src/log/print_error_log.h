#ifndef _PRINT_ERROR_LOG_H
#define _PRINT_ERROR_LOG_H

#include <string>

using namespace std;
namespace comm_lib
{
class PrintErrorLog
{
public:
    PrintErrorLog();
    ~PrintErrorLog();

    bool printErrorMsgToFile(const string& strFileName, const string& strErrorMsg);
};
};
#endif

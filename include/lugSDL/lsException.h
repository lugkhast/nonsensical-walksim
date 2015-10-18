
#ifndef _LSEXCEPTION_H_
#define _LSEXCEPTION_H_

#include <string>
using std::string;

class lsException
{
public:
    lsException();
    lsException(string msg);

    string message;
};

#endif // _LSEXCEPTION_H_

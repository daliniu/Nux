/*
*  time: $time$
*  writer: zhangys
*  filename: $safeitemname$
*/

#ifndef NUX_OBJECT_H_
#define NUX_OBJECT_H_

#include <string>
#include <iostream>
#include <memory>
#include<sstream>

using namespace boost;
using namespace std;

namespace Nux {

    class NObject {
    public:
        string const& toString() { return ""; }
    };
}
#endif
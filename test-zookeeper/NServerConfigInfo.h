/*
*  time: $time$
*  writer: zhangys
*  filename: $safeitemname$
*/

#ifndef NUX_SERVER_CONFIG_H_
#define NUX_SERVER_CONFIG_H_

#include "NObject.h"

using namespace std;

namespace Nux {

	/*
	*  
	*/
	class NServerConfigInfo : public NObject
	{
	public:
        NServerConfigInfo(){};
        NServerConfigInfo(string const& hostPort, int timeout)
            : m_HostPort(hostPort)
            , m_Timeout(timeout) {}
        string getHostPort() const       { return m_HostPort; }
        int    getTimeout() const        { return m_Timeout; }
        static string getIp()            { return "127.0.0.1"; }
        static string getRootNode()      { return "config_root"; }
        static int    getPort()          { return 8080; }
        static int    getIndex()         { return 1; }
        static int    getMaxRetryNum()   { return 10; }
    private:
        string m_HostPort;
        int m_Timeout;
	};

}
#endif

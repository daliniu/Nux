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
	class NServerConfig : public NObject
	{
	public:
        NServerConfig(){};
        NServerConfig(string const& hostPort, int timeout)
            : m_HostPort(hostPort)
            , m_Timeout(timeout) {}
        string getHostPort() const { return m_HostPort; }
        string getIp() const       { return "127.0.0.1"; }
        string getRootNode() const { return "config_root"; }
        int    getTimeout() const  { return m_Timeout; }
        int    getPort() const     { return 8080; }
        int    getIndex() const    { return 1; }
    private:
        string m_HostPort;
        int m_Timeout;
	};

}
#endif
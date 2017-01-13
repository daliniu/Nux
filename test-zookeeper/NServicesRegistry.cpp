
#include "NServicesRegistry.h"

namespace Nux {
    void NServicesRegistry::connectToZooKeeper() {
        if (m_IsConnected) {
            return;
        }
        m_ZooKeeper = make_shared<NZooKeeper>(m_ServerConfig.getHostPort(), m_ServerConfig.getTimeout(), this);
    }

    string NServicesRegistry::makeNode() {
        stringstream serverPath;
        serverPath << m_ServerConfig.getRootNode() << "/" << m_ServerConfig.getIndex() << "/" << m_ServerConfig.getIp() << ":" << m_ServerConfig.getPort();
        return serverPath.str();
    }

    void NServicesRegistry::publishService() {
        if (!m_IsConnected) {
            return;
	    }
        m_ZooKeeper->createNode(makeNode(), m_ServerConfig.getIp().c_str());
    }

    void NServicesRegistry::run() {
	    while (true) {
		    cout<<"publish service"<<endl;
		    connectToZooKeeper();
		    publishService();
		    sleep(10);
	    }
    }
}
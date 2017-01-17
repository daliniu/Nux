
#include "NServicesRegistry.h"

namespace Nux {
    void NServicesRegistry::onChildChanged(WatcherEvent const& event) {
        // get the child data
        function<void()> onConnectionCallback = bind(&NZooKeeper::asyncGetChildren, m_ZooKeeper, NServerConfigInfo::getRootNode(), 
            [](int retCode, String_vector const* stringVectors) {
            // update data
            cout << "asyncGetChildren" << endl;
            for (int i = 0; i < stringVectors->count; ++i) {
                struct String_vector node_vec;
                string path = NServerConfigInfo::getRootNode() + "/" + stringVectors->data[i];
                cout << "path|" << path << endl;
            }
        });
        if (!m_IsConnected) {
            reconnectToZooKeeper(onConnectionCallback);
            return;
        }
        onConnectionCallback();
    }

    void NServicesRegistry::connectToZooKeeper(function<void()> const& callback) {
        cout << "connectToZooKeeper|m_IsConnected:" << m_IsConnected << "|m_RetryNums:" << m_RetryNums << endl;
        if (m_IsConnected) {
            return;
        }
        m_OnConnectionCallback = callback;
        if (m_RetryNums++ >= m_ServerConfigInfo.getMaxRetryNum()) {
            cout << "connectToZooKeeper MaxRetryNum" << endl;
            // throw exception
        }
        m_ZooKeeper = make_shared<NZooKeeper>(m_ServerConfigInfo.getHostPort(), m_ServerConfigInfo.getTimeout(), this);
    }

    void NServicesRegistry::reconnectToZooKeeper(function<void()> const& callback) {
        cout << "reconnectToZooKeeper|m_IsConnected:" << m_IsConnected << "|m_RetryNums:" << m_RetryNums << endl;
        connectToZooKeeper([this, callback]() {
            publishService(callback);
        });
    }

    string NServicesRegistry::makeNode() {
        stringstream serverPath;
        serverPath << NServerConfigInfo::getRootNode() << "/" << NServerConfigInfo::getIndex() << "/" << NServerConfigInfo::getIp() << ":" << NServerConfigInfo::getPort();
        return serverPath.str();
    }

    void NServicesRegistry::publishService(function<void()> const& callback) {
        if (!m_IsConnected) {
            return;
	    }
        m_ZooKeeper->asyncCreateNode(makeNode(), NServerConfigInfo::getIp().c_str(), [callback](int rc, char const* data) {
            if (callback) {
                callback();
            }
        });
    }

    void NServicesRegistry::run() {
	    while (true) {
		    cout<<"publish service"<<endl;
            reconnectToZooKeeper(nullptr);
		    sleep(10);
	    }
    }
}

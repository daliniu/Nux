
#include "NServicesRegistry.h"

namespace Nux {


    void NServicesRegistry::onChildChanged(WatcherEvent const& event) {
        // get the child data
        cout <<"NServicesRegistry::onChildChanged"<<endl;
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
        reconnectToZooKeeper(onConnectionCallback);
    }

    void NServicesRegistry::connectToZooKeeper(function<void()> const& callback) {
        cout << "connectToZooKeeper|m_IsConnected:" << m_IsConnected << "|m_RetryNums:" << m_RetryNums << endl;
        if (m_IsConnected) {
            return;
        }
        m_OnConnectionCallback = callback;
        if (m_RetryNums++ >= m_ServerConfigInfo.getMaxRetryNum()) {
            throw NException("connectToZooKeeper MaxRetryNum");
        }
        m_ZooKeeper = make_shared<NZooKeeper>(m_ServerConfigInfo.getHostPort(), m_ServerConfigInfo.getTimeout(), this);
    }

    void NServicesRegistry::reconnectToZooKeeper(function<void()> const& callback) {
        if (!m_IsConnected) {
            cout << "reconnectToZooKeeper|m_IsConnected:" << m_IsConnected << "|m_RetryNums:" << m_RetryNums << endl;
            connectToZooKeeper([this, callback]() {
                publishService(callback);
            });
            return;
        }
        if (callback) {
            callback();
        }
    }

    string NServicesRegistry::makeNodePath() {
        stringstream serverPath;
        serverPath << NServerConfigInfo::getRootNode() << "/" << NServerConfigInfo::getIndex();
        return serverPath.str();
    }

    string NServicesRegistry::makeNodeValue() {
        stringstream serverPath;
        serverPath << NServerConfigInfo::getIp() << ":" << NServerConfigInfo::getPort();
        return serverPath.str();
    }

    void NServicesRegistry::publishService(function<void()> const& callback) {
        if (!m_IsNodeCreated) {
            m_ZooKeeper->asyncCreateNode(makeNodePath(), makeNodeValue().c_str(), [this, callback](int retCode, char const* data) {
                if (retCode != ZOK) {
                    cout << "NServicesRegistry::asyncCreateNode callback retCode=" << zerror(retCode) << ",data=" << data << endl;
                    return;
                }
                cout << "NServicesRegistry::asyncCreateNode callback retCode=" << zerror(retCode) << ",data=" << data << endl;
                this->m_IsNodeCreated = true;
                if (callback) {
                    callback();
                }
            });
            return;
	    }
        if (callback) {
            callback();
        }
    }

    void NServicesRegistry::update() {
        cout << "NServicesRegistry::Update" << endl;
        reconnectToZooKeeper([this]() {
            this->m_ZooKeeper->asyncGetChildren(NServerConfigInfo::getRootNode(),
                [](int retCode, String_vector const* stringVectors) {
                if (retCode != ZOK) {
                    cout << "NServicesRegistry::update callback retCode=" << zerror(retCode) << endl;
                    return;
                }
                // update data
                cout << "update() -> asyncGetChildren" << endl;
                for (int i = 0; i < stringVectors->count; ++i) {
                    struct String_vector node_vec;
                    string path = NServerConfigInfo::getRootNode() + "/" + stringVectors->data[i];
                    cout << "NServicesRegistry::update path=" << path << endl;
                }
            });
        });
    }

    void NServicesRegistry::run() {
        reconnectToZooKeeper([]() {
            cout << "asyncCreateNode success" << endl;
        });
	    while (true) {
            update();
		    sleep(10);
	    }
    }
}

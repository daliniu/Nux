/*
*  time: $time$
*  writer: zhangys
*  filename: $safeitemname$
*/

#ifndef NUX_SERVICES_REGISTRY_H_
#define NUX_SERVICES_REGISTRY_H_
#include <unistd.h>
#include <zookeeper/zookeeper.h>
#include <zookeeper/zookeeper_log.h>
#include "NThreadObject.h"
#include "NZooKeeper.h"
#include "NZooKeeperWatcher.h"
#include "NServerConfigInfo.h"

using namespace std;

namespace Nux {

    /*
    *  the NServicesRegistry maintains the ZooKeeper connection
    */
    class NServicesRegistry : public NVirtualThreadObject<NServicesRegistry, ZooKeeperWatcher>
    {
    public:
        NServicesRegistry(){};
        NServicesRegistry(string const& hostPort, int timeout)
            : m_ServerConfigInfo(hostPort, timeout)
            , m_IsConnected(false)
            , m_RetryNums(0) {};

        void publishService(function<void()> const& callback);
        void run();
        void connectToZooKeeper(function<void()> const& onConnectionCallback);
        void reconnectToZooKeeper(function<void()> const& onConnectionCallback);

        // callback function when the state is changed
        void onSessionExpired(WatcherEvent const& event) override {
            ZooKeeperWatcher::onSessionExpired(event);
            m_IsConnected = false;
        }
        void onConnectionEstablished(WatcherEvent const& event) override {
            ZooKeeperWatcher::onConnectionEstablished(event);
            m_RetryNums = 0;
            m_IsConnected = true;
            if (m_OnConnectionCallback) {
                m_OnConnectionCallback();
            }
        }
        void onConnectionLost(WatcherEvent const& event) override {
            ZooKeeperWatcher::onConnectionLost(event);
            m_IsConnected = false;
        }
        void onNodeValueChanged(WatcherEvent const& event) override {}
        void onNodeDeleted(WatcherEvent const& event) override {}
        void onChildChanged(WatcherEvent const& event) override;

    private:
        string makeNode();

    private:
        shared_ptr<NZooKeeper> m_ZooKeeper;
        NServerConfigInfo m_ServerConfigInfo;
        bool m_IsConnected;
        int  m_RetryNums;
        function<void()>  m_OnConnectionCallback;
    };

}
#endif

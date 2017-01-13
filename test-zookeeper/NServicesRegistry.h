/*
*  time: $time$
*  writer: zhangys
*  filename: $safeitemname$
*/

#ifndef NUX_SERVICES_REGISTRY_H_
#define NUX_SERVICES_REGISTRY_H_
#include <zookeeper/zookeeper.h>
#include <zookeeper/zookeeper_log.h>
#include "NThreadObject.h"
#include "NZooKeeper.h"
#include "NZooKeeperWatcher.h"
#include "NServerConfig.h"

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
            : m_ServerConfig(hostPort, timeout)
            , m_IsConnected(false) {};

        void publishService();
        void run();
        void connectToZooKeeper();

        // callback function when the state is changed
        void onSessionExpired(WatcherEvent const& event) override {
            ZooKeeperWatcher::onSessionExpired(event);
            m_IsConnected = false;
        }
        void onConnectionEstablished(WatcherEvent const& event) override {
            ZooKeeperWatcher::onConnectionEstablished(event);
            m_IsConnected = true;
        }
        void onConnectionLost(WatcherEvent const& event) override {
            ZooKeeperWatcher::onConnectionLost(event);
            m_IsConnected = false;
        }
        void onNodeValueChanged(WatcherEvent const& event) override {}
        void onNodeDeleted(WatcherEvent const& event) override {}
        void onChildChanged(WatcherEvent const& event) override {}

    private:
        string NServicesRegistry::makeNode();

    private:
        shared_ptr<NZooKeeper> m_ZooKeeper;
        NServerConfig m_ServerConfig;
        bool m_IsConnected;
    };

}
#endif
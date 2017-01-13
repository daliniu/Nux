/*
*  time: $time$
*  writer: zhangys
*  filename: $safeitemname$
*/

#ifndef NUX_ZOO_KEEPER_WATCHER_H_
#define NUX_ZOO_KEEPER_WATCHER_H_
#include <zookeeper/zookeeper.h>
#include <zookeeper/zookeeper_log.h>
#include "NObject.h"

using namespace std;
using namespace boost;

namespace Nux {

    struct WatcherEvent {
        zhandle_t* zh;
        int        type;
        int        state;
        string     path;
        void*      ctx;
    };

    /*
    *  
    */
    class ZooKeeperWatcher : public NObject {
    public:
        ZooKeeperWatcher() {}
        virtual void onSessionExpired(WatcherEvent const& event){
            cout << "onSessionExpired" << endl;
        }
        virtual void onConnectionEstablished(WatcherEvent const& event){
            cout << "onConnectionEstablished" << endl;
        }
        virtual void onConnectionLost(WatcherEvent const& event){
            cout << "onConnectionLost" << endl;
        }
        virtual void onNodeValueChanged(WatcherEvent const& event){
            cout << "onNodeValueChanged" << endl;
        }
        virtual void onNodeDeleted(WatcherEvent const& event){
            cout << "onNodeDeleted" << endl;
        }
        virtual void onChildChanged(WatcherEvent const& event){
            cout << "onChildChanged" << endl;
        }
        virtual void onNodeCreated(WatcherEvent const& watcherEvent){
            cout << "onNodeCreated" << endl;
        }
        virtual void onNotWatching(WatcherEvent const& watcherEvent){
            cout << "onNotWatching" << endl;
        }
        virtual void onAuthFailed(WatcherEvent const& watcherEvent){
            cout << "onAuthFailed" << endl;
        }
        virtual void setWatcherTriggered(){
            m_Triggered = true;
        }
    private:
        bool m_Triggered;
    };

}
#endif
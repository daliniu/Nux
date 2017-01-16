/*
*  time: $time$
*  writer: zhangys
*  filename: $safeitemname$
*/

#ifndef NUX_ZOO_KEEPER_H_
#define NUX_ZOO_KEEPER_H_
#include <zookeeper/zookeeper.h>
#include <zookeeper/zookeeper_log.h>
#include "NObject.h"
#include "NZooKeeperWatcher.h"

using namespace std;

namespace Nux {

    typedef function<void (int, ACL_vector*, Stat*)>                    AclCompletionType;
    typedef function<void (int, char const*, int, Stat const*)>         DataCompletionType;
    typedef function<void (int, Stat const*)>                           StatCompletionType;
    typedef function<void (int, char const*)>                           StringCompletionType;
    typedef function<void (int, String_vector const*)>                  StringsStatCompletionType;
    typedef function<void (int)>                                        VoidCompletionType;

    /*
    *
    */
    class NZooKeeper: public NObject {
    public:
        NZooKeeper()  {
        }

        NZooKeeper::NZooKeeper(string const& hostPort, int timeout, NObject* obj)
            : m_HostPort(hostPort)
            , m_Timeout(timeout)
            , m_Object(obj) {
            m_ZkHandle = zookeeper_init(hostPort.c_str(), activeWatcher, timeout, 0, obj, 0);
            if (NULL == m_ZkHandle) {
                cout << "zookeeper init error" << endl;
            }
            cout << "NZooKeeper()" << endl;
        }

        NZooKeeper::~NZooKeeper() {
            cout << "~NZooKeeper()" << endl;
            zookeeper_close(m_ZkHandle);
        }

        void createNode(string const& path, char const* value);
        String_vector getChildren(string const& path);
        void asyncGetChildren(string const& path, StringsStatCompletionType const& callback);  // lambda expr
        void asyncCreateNode(string const& path, char const* value, StringCompletionType const& callback); 
        
        // callfunction interface
        AclCompletionType         AclCompletionCallback;
        DataCompletionType        DataCompletionCallback; 
        StatCompletionType        StatCompletionCallback;
        StringCompletionType      StringCompletionCallback;
        StringsStatCompletionType StringsCompletionCallback;
        VoidCompletionType        VoidCompletionCallback;

    private:
        string     m_HostPort;
        int        m_Timeout;
        NObject*   m_Object;
        zhandle_t* m_ZkHandle;
    };

}
#endif
#include "NZooKeeper.h"
#include <functional>

namespace Nux {

    // a set of async completion signatures
    void asyncCompletion(int rc, ACL_vector *acl, Stat *stat, const void *data){
        assert("Completion data is NULL"&&data);
        NZooKeeper* s = static_cast<NZooKeeper*>((void*)data);
        if (nullptr == s) {
            cout << "asyncCompletion error" << endl;
            return;
        }
        s->AclCompletionCallback(rc, acl, stat);
    }

    void asyncCompletion(int rc, const char *value, int len, const Stat *stat,
        const void *data) {
        assert("Completion data is NULL"&&data);
        NZooKeeper* s = static_cast<NZooKeeper*>((void*)data);
        if (nullptr == s) {
            cout << "asyncCompletion error" << endl;
            return;
        }
        s->DataCompletionCallback(rc, value, len, stat);
    }

    void asyncCompletion(int rc, const Stat *stat, const void *data) {
        assert("Completion data is NULL"&&data);
        NZooKeeper* s = static_cast<NZooKeeper*>((void*)data);
        if (nullptr == s) {
            cout << "asyncCompletion error" << endl;
            return;
        }
        s->StatCompletionCallback(rc, stat);
    }

    void asyncCompletion(int rc, const char *value, const void *data) {
        assert("Completion data is NULL"&&data);
        NZooKeeper* s = static_cast<NZooKeeper*>((void*)data);
        if (nullptr == s) {
            cout << "asyncCompletion error" << endl;
            return;
        }
        s->StringCompletionCallback(rc, value);
    }

    void asyncCompletion(int rc, const String_vector *strings, const void *data) {
        assert("Completion data is NULL"&&data);
        NZooKeeper* s = static_cast<NZooKeeper*>((void*)data);
        if (nullptr == s) {
            cout << "asyncCompletion error" << endl;
            return;
        }
        s->StringsCompletionCallback(rc, strings);
    }

    void asyncCompletion(int rc, const void *data) {
        assert("Completion data is NULL"&&data);
        NZooKeeper* s = static_cast<NZooKeeper*>((void*)data);
        if (nullptr == s) {
            cout << "asyncCompletion error" << endl;
            return;
        }
        s->VoidCompletionCallback(rc);
    }

    // *****************************************************************************
    // watcher action implementation
    void activeWatcher(zhandle_t *zh,
        int type, int state, const char *path, void* ctx) {

        cout << "active Watcher type="<<type<<",state="<<state<< endl;
        if (zh == 0 || ctx == 0) {
            cout << "active Watcher handle is Null"<< endl;
            return;
        }

        ZooKeeperWatcher* watcher = static_cast<ZooKeeperWatcher *>(ctx);  // exception ?
        if (nullptr == watcher) {
            cout << "active Watcher watcher is Null"<< endl;
            return;
        }
        WatcherEvent watcherEvent{zh, type, state, path, ctx};

        if (type == ZOO_SESSION_EVENT) {
            if (state == ZOO_EXPIRED_SESSION_STATE)
                watcher->onSessionExpired(watcherEvent);
            else if (state == ZOO_CONNECTING_STATE)
                watcher->onConnectionLost(watcherEvent);
            else if (state == ZOO_CONNECTED_STATE)
                watcher->onConnectionEstablished(watcherEvent);
        }
        else if (type == ZOO_CHANGED_EVENT)
            watcher->onNodeValueChanged(watcherEvent);
        else if (type == ZOO_DELETED_EVENT)
            watcher->onNodeDeleted(watcherEvent);
        else if (type == ZOO_CHILD_EVENT)
            watcher->onChildChanged(watcherEvent);
        else if (type == ZOO_CREATED_EVENT)
            watcher->onNodeCreated(watcherEvent);
        else if (type == ZOO_NOTWATCHING_EVENT) 
            watcher->onNotWatching(watcherEvent);
        else if (type == ZOO_AUTH_FAILED_STATE)
            watcher->onAuthFailed(watcherEvent);

        // TODO: implement for the rest of the event types

        watcher->setWatcherTriggered();
    }


    void NZooKeeper::createNode(string const& path, char const* value)
    {
        int rc = zoo_create(m_ZkHandle, path.c_str(), value, sizeof(value),
            &ZOO_OPEN_ACL_UNSAFE, ZOO_EPHEMERAL, NULL, 0);
        if (rc != ZOK) {
            cout << "NZooKeeper::createNode --> zoo_create() path=" << path << ",value=" << value << ",reason=" << zerror(rc) << endl;
        }
    }

    void NZooKeeper::asyncCreateNode(string const& path, char const* value, StringCompletionType const& callback)
    {
        StringCompletionCallback = callback;
        int rc = zoo_acreate(m_ZkHandle, path.c_str(), value, sizeof(value),
            &ZOO_OPEN_ACL_UNSAFE, ZOO_EPHEMERAL, asyncCompletion, this);
        if (rc != ZOK) {
            cout << "NZooKeeper::asyncCreateNode --> zoo_acreate() path=" << path << ",value=" << value << ",reason=" << zerror(rc) << endl;
        }
    }

    String_vector NZooKeeper::getChildren(string const& path)
    {
        //获得服务份数
        String_vector str_vec;
        int ret = zoo_wget_children(m_ZkHandle, path.c_str(), activeWatcher, m_Object, &str_vec);
        if (ret) {
            cout << "getChildren --> read path:" << path << " reason=" << zerror(ret) << endl;
        }
        return str_vec;
    }

    void NZooKeeper::asyncGetChildren(string const& path, StringsStatCompletionType const& callback)
    {
        StringsCompletionCallback = callback;
        int ret = zoo_awget_children(m_ZkHandle, path.c_str(),
            activeWatcher, m_Object,
            asyncCompletion, this);
        if (ZOK != ret) {
            cout << "NZooKeeper::asyncGetChildren --> read path=" << path << ",reason=" << zerror(ret) << endl;
        }
    }
}

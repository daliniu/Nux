#include "Executor.h"

namespace Nux {

	void CallbackWatch(zhandle_t* zh, int type, int state, const char* path, void* watcher) {
		Executor* executor = reinterpret_cast<Executor*>(const_cast<void*>(zoo_get_context(zh)));
		if (executor != nullptr) {
			WatchedEvent event;
			m_DataMonitor->process(event);
		}
	}

	void Executor::Watch(zhandle_t* zh, int type, int state, const char* path, void* watcher) {
		if (type == ZOO_SESSION_EVENT) {
			if (state == ZOO_CONNECTED_STATE) {
				cout << "build connection ok" << endl;
			}
			else if (state == ZOO_EXPIRED_SESSION_STATE) {
				cout << "connection disconnect" << endl;
				m_ZkHandle = zookeeper_init(m_HostPort.c_str(), CallbackWatch, m_Timeout, 0, reinterpret_cast<char*>(this), 0);
			}
		}
	}

	Executor::Executor(string hostPort, string const& znode, string filename, unsigned char* data)
		: m_HostPort(hostPort)
		, m_FileName(filename)
		, m_Data(data)
	{
		m_ZkHandle = zookeeper_init(hostPort.c_str(), CallbackWatch, m_Timeout, 0, reinterpret_cast<char*>(this), 0);
		m_DataMonitor = make_shared<DataMonitor>(m_ZkHandle, znode, this);
	}

	void Executor::exists(unsigned char* data) {
		if (data == nullptr) {
			if (child != null) {
				System.out.println("Killing process");
				child.destroy();
				try {
					child.waitFor();
				}
				catch (InterruptedException e) {
				}
			}
			child = null;
		}
		else {
			if (child != null) {
				System.out.println("Stopping child");
				child.destroy();
				try {
					child.waitFor();
				}
				catch (InterruptedException e) {
					e.printStackTrace();
				}
			}
			try {
				FileOutputStream fos = new FileOutputStream(filename);
				fos.write(data);
				fos.close();
			}
			catch (IOException e) {
				e.printStackTrace();
			}
			try {
				System.out.println("Starting child");
				child = Runtime.getRuntime().exec(exec);
				new StreamWriter(child.getInputStream(), System.out);
				new StreamWriter(child.getErrorStream(), System.err);
			}
			catch (IOException e) {
				e.printStackTrace();
			}
		}
	}
}
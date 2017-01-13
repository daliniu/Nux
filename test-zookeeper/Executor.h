#ifndef NUX_EXECUTOR_H_
#define NUX_EXECUTOR_H_
#include <zookeeper/zookeeper.h>
#include <zookeeper/zookeeper_log.h>
#include <iostream>
#include <string>
#include "DataMonitor.h"

using namespace std;

namespace Nux {

	/*
	*  the Executor maintains the ZooKeeper connection
	*/
	class Executor : public DataMonitor::DataMonitorListener
	{
	private:
		string m_HostPort;
		string m_FileName;
		unsigned char*  m_Data;
		const int m_Timeout = 20000;
		zhandle_t*  m_ZkHandle;
		shared_ptr<DataMonitor> m_DataMonitor;

	public:
		Executor(){};

		Executor(string hostPort, string const& znode, string filename, unsigned char* data);

		void Watch(zhandle_t* zh, int type, int state, const char* path, void* watcher);

		/**
		* The existence status of the node has changed.
		*/
		virtual void exists(unsigned char* data);

		/**
		* The ZooKeeper session is no longer valid.
		*
		* @param rc
		*                the ZooKeeper reason code
		*/
		virtual void closing(int rc);
	};

}
#endif
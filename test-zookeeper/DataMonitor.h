#ifndef NUX_DATAMONITOR_H_
#define NUX_DATAMONITOR_H_
#include <zookeeper/zookeeper.h>
#include <zookeeper/zookeeper_log.h>
#include <iostream>

using namespace std;

namespace Nux {

	struct WatchedEvent {

	};

	/*
	* class called the DataMonitor monitors the data in the ZooKeeper tree
	*/
	class DataMonitor
	{
	public:
		/**
		* Other classes use the DataMonitor by implementing this method
		*/
		class DataMonitorListener {
			/**
			* The existence status of the node has changed.
			*/
			virtual void exists(unsigned char* data) = 0;

			/**
			* The ZooKeeper session is no longer valid.
			*
			* @param rc
			*                the ZooKeeper reason code
			*/
			virtual void closing(int rc) = 0;
		};


		DataMonitor() {}

		DataMonitor(zhandle_t* zh, string const& znode, DataMonitorListener* listener)
			: m_zkHandle(zh)
			, m_Znode(znode)
			, m_Listener(listener){
			
		}

		void process(WatchedEvent const& event);

	private:
		zhandle_t*  m_zkHandle;
		string m_Znode;
		DataMonitorListener* m_Listener;
	};

}
#endif
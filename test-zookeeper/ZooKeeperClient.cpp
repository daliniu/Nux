//连接zk server  
void ZkClient::ConnectZK() {
	cout << "ZkClient::ConnectZK" << endl;
	if (zhandle_) {
		zookeeper_close(zhandle_);
	}
	zhandle_ = NULL;
	connected_ = false;

	int count = 0;
	do {
		++count;
		zhandle_ = zookeeper_init(zk_hosts_.c_str(), InitWatcher, timeout_, NULL, NULL, 0);
		sleep(5 * ONE_SECONDS);
	} while (!connected_ && count < ZK_MAX_CONNECT_TIMES);

	if (count >= ZK_MAX_CONNECT_TIMES){
		cout << "ZkClient::Init --> connecting zookeeper host: " << zk_hosts_ << " over times: " << count << endl;
	}
}
//更新服务列表，冷备和热备  
void ZkClient::Update() {
	cout << "ZkClient::Update" << endl;
	if (zhandle_ == NULL || connected_ == false) {
		Init();
	}
	//获得服务份数  
	struct String_vector str_vec;
	int ret = zoo_wget_children(zhandle_, PING_SERVER.c_str(), ServiceWatcher, NULL, &str_vec);
	if (ret) {
		cout << "Update --> read path:" << PING_SERVER << " wrong, " << zerror(ret) << endl;
		return;
	}

	//获得各份服务ip:port  
	for (int i = 0; i < str_vec.count; ++i) {
		struct String_vector node_vec;
		string path = PING_SERVER + "/" + str_vec.data[i];
		int ret = zoo_wget_children(zhandle_, path.c_str(), ServiceWatcher, NULL, &node_vec);
		cout << "Update --> path:" << path << ", ret:" << ret << ", node's size:" << node_vec.count << endl;
		if (ret || node_vec.count != 1) {
			continue;
		}
	}
}
//监控服务变化  
void ZkClient::ServiceWatcher(zhandle_t *zh, int type, int state, const char *path, void *watcherCtx) {
	cout << "type:" << type << endl;
	cout << "state:" << state << endl;
	cout << "path:" << path << endl;
	//  cout << "watcherCtx:" << (char*)watcherCtx << endl;  
	cout << "ZOO_CHILD_EVENT:" << ZOO_CHILD_EVENT << endl;
	if (ZOO_CHILD_EVENT == type) {
		cout << "ServiceWatcher ZOO_CHILD_EVENT" << endl;
		ZkClient::Instance().Update();//更新服务列表      
	}
}
#include <iostream>

#include <evhttp.h>
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/transport/TSocket.h>
#include <thrift/transport/TTransportUtils.h>
#include <thrift/async/TEvhttpClientChannel.h>

#include "gen-cpp/Calculator.h"

using namespace std;
using namespace apache::thrift;
using namespace apache::thrift::async;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;

using namespace tutorial;
using namespace shared;

int main() {
  boost::shared_ptr<TTransport> socket(new TSocket("localhost", 9090));
  boost::shared_ptr<TTransport> transport(new TBufferedTransport(socket));
  boost::shared_ptr<TProtocol> protocol(new TBinaryProtocol(transport));
  event_base* base = event_base_new();
  boost::shared_ptr< ::apache::thrift::async::TAsyncChannel>  channel(new TEvhttpClientChannel("localhost", "/", "localhost", 9090, base));

  CalculatorCobClient client(channel, new TBinaryProtocolFactory());

  try {
	function<void(CalculatorCobClient* client)> cob = [](CalculatorCobClient* client) {
		int diff = client->recv_calculate();
		cout << "15 - 10 = " << diff << endl;
	};
    Work work;
    work.op = Operation::SUBTRACT;
    work.num1 = 15;
    work.num2 = 10;

	client.calculate(cob, 1, work);

	event_base_dispatch(base);

	event_base_free(base);

	/*
    // Note that C++ uses return by reference for complex types to avoid
    // costly copy construction
    SharedStruct ss;
    client.getStruct(ss, 1);
    cout << "Received log: " << ss << endl;

    transport->close();
	*/
  } catch (TException& tx) {
    cout << "ERROR: " << tx.what() << endl;
  }
}

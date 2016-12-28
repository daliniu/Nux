/**
 * Autogenerated by Thrift Compiler (1.0.0-dev)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef Calculator_H
#define Calculator_H

#include <thrift/transport/TBufferTransports.h>
#include <thrift/cxxfunctional.h>
namespace apache { namespace thrift { namespace async {
class TAsyncChannel;
}}}
#include <thrift/TDispatchProcessor.h>
#include <thrift/async/TAsyncDispatchProcessor.h>
#include <thrift/async/TConcurrentClientSyncInfo.h>
#include "tutorial_types.h"
#include "SharedService.h"

namespace tutorial {

#ifdef _WIN32
  #pragma warning( push )
  #pragma warning (disable : 4250 ) //inheriting methods via dominance 
#endif

class CalculatorIf : virtual public  ::shared::SharedServiceIf {
 public:
  virtual ~CalculatorIf() {}

  /**
   * A method definition looks like C code. It has a return type, arguments,
   * and optionally a list of exceptions that it may throw. Note that argument
   * lists and exception lists are specified using the exact same syntax as
   * field lists in struct or exception definitions.
   */
  virtual void ping() = 0;
  virtual int32_t add(const int32_t num1, const int32_t num2) = 0;
  virtual int32_t calculate(const int32_t logid, const Work& w) = 0;

  /**
   * This method has a oneway modifier. That means the client only makes
   * a request and does not listen for any response at all. Oneway methods
   * must be void.
   */
  virtual void zip() = 0;
};

class CalculatorIfFactory : virtual public  ::shared::SharedServiceIfFactory {
 public:
  typedef CalculatorIf Handler;

  virtual ~CalculatorIfFactory() {}

  virtual CalculatorIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler( ::shared::SharedServiceIf* /* handler */) = 0;
};

class CalculatorIfSingletonFactory : virtual public CalculatorIfFactory {
 public:
  CalculatorIfSingletonFactory(const boost::shared_ptr<CalculatorIf>& iface) : iface_(iface) {}
  virtual ~CalculatorIfSingletonFactory() {}

  virtual CalculatorIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
    return iface_.get();
  }
  virtual void releaseHandler( ::shared::SharedServiceIf* /* handler */) {}

 protected:
  boost::shared_ptr<CalculatorIf> iface_;
};

class CalculatorNull : virtual public CalculatorIf , virtual public  ::shared::SharedServiceNull {
 public:
  virtual ~CalculatorNull() {}
  void ping() {
    return;
  }
  int32_t add(const int32_t /* num1 */, const int32_t /* num2 */) {
    int32_t _return = 0;
    return _return;
  }
  int32_t calculate(const int32_t /* logid */, const Work& /* w */) {
    int32_t _return = 0;
    return _return;
  }
  void zip() {
    return;
  }
};


class Calculator_ping_args {
 public:

  Calculator_ping_args(const Calculator_ping_args&);
  Calculator_ping_args& operator=(const Calculator_ping_args&);
  Calculator_ping_args() {
  }

  virtual ~Calculator_ping_args() throw();

  bool operator == (const Calculator_ping_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const Calculator_ping_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Calculator_ping_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class Calculator_ping_pargs {
 public:


  virtual ~Calculator_ping_pargs() throw();

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class Calculator_ping_result {
 public:

  Calculator_ping_result(const Calculator_ping_result&);
  Calculator_ping_result& operator=(const Calculator_ping_result&);
  Calculator_ping_result() {
  }

  virtual ~Calculator_ping_result() throw();

  bool operator == (const Calculator_ping_result & /* rhs */) const
  {
    return true;
  }
  bool operator != (const Calculator_ping_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Calculator_ping_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class Calculator_ping_presult {
 public:


  virtual ~Calculator_ping_presult() throw();

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Calculator_add_args__isset {
  _Calculator_add_args__isset() : num1(false), num2(false) {}
  bool num1 :1;
  bool num2 :1;
} _Calculator_add_args__isset;

class Calculator_add_args {
 public:

  Calculator_add_args(const Calculator_add_args&);
  Calculator_add_args& operator=(const Calculator_add_args&);
  Calculator_add_args() : num1(0), num2(0) {
  }

  virtual ~Calculator_add_args() throw();
  int32_t num1;
  int32_t num2;

  _Calculator_add_args__isset __isset;

  void __set_num1(const int32_t val);

  void __set_num2(const int32_t val);

  bool operator == (const Calculator_add_args & rhs) const
  {
    if (!(num1 == rhs.num1))
      return false;
    if (!(num2 == rhs.num2))
      return false;
    return true;
  }
  bool operator != (const Calculator_add_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Calculator_add_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class Calculator_add_pargs {
 public:


  virtual ~Calculator_add_pargs() throw();
  const int32_t* num1;
  const int32_t* num2;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Calculator_add_result__isset {
  _Calculator_add_result__isset() : success(false) {}
  bool success :1;
} _Calculator_add_result__isset;

class Calculator_add_result {
 public:

  Calculator_add_result(const Calculator_add_result&);
  Calculator_add_result& operator=(const Calculator_add_result&);
  Calculator_add_result() : success(0) {
  }

  virtual ~Calculator_add_result() throw();
  int32_t success;

  _Calculator_add_result__isset __isset;

  void __set_success(const int32_t val);

  bool operator == (const Calculator_add_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const Calculator_add_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Calculator_add_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Calculator_add_presult__isset {
  _Calculator_add_presult__isset() : success(false) {}
  bool success :1;
} _Calculator_add_presult__isset;

class Calculator_add_presult {
 public:


  virtual ~Calculator_add_presult() throw();
  int32_t* success;

  _Calculator_add_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Calculator_calculate_args__isset {
  _Calculator_calculate_args__isset() : logid(false), w(false) {}
  bool logid :1;
  bool w :1;
} _Calculator_calculate_args__isset;

class Calculator_calculate_args {
 public:

  Calculator_calculate_args(const Calculator_calculate_args&);
  Calculator_calculate_args& operator=(const Calculator_calculate_args&);
  Calculator_calculate_args() : logid(0) {
  }

  virtual ~Calculator_calculate_args() throw();
  int32_t logid;
  Work w;

  _Calculator_calculate_args__isset __isset;

  void __set_logid(const int32_t val);

  void __set_w(const Work& val);

  bool operator == (const Calculator_calculate_args & rhs) const
  {
    if (!(logid == rhs.logid))
      return false;
    if (!(w == rhs.w))
      return false;
    return true;
  }
  bool operator != (const Calculator_calculate_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Calculator_calculate_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class Calculator_calculate_pargs {
 public:


  virtual ~Calculator_calculate_pargs() throw();
  const int32_t* logid;
  const Work* w;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Calculator_calculate_result__isset {
  _Calculator_calculate_result__isset() : success(false), ouch(false) {}
  bool success :1;
  bool ouch :1;
} _Calculator_calculate_result__isset;

class Calculator_calculate_result {
 public:

  Calculator_calculate_result(const Calculator_calculate_result&);
  Calculator_calculate_result& operator=(const Calculator_calculate_result&);
  Calculator_calculate_result() : success(0) {
  }

  virtual ~Calculator_calculate_result() throw();
  int32_t success;
  InvalidOperation ouch;

  _Calculator_calculate_result__isset __isset;

  void __set_success(const int32_t val);

  void __set_ouch(const InvalidOperation& val);

  bool operator == (const Calculator_calculate_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(ouch == rhs.ouch))
      return false;
    return true;
  }
  bool operator != (const Calculator_calculate_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Calculator_calculate_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Calculator_calculate_presult__isset {
  _Calculator_calculate_presult__isset() : success(false), ouch(false) {}
  bool success :1;
  bool ouch :1;
} _Calculator_calculate_presult__isset;

class Calculator_calculate_presult {
 public:


  virtual ~Calculator_calculate_presult() throw();
  int32_t* success;
  InvalidOperation ouch;

  _Calculator_calculate_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class Calculator_zip_args {
 public:

  Calculator_zip_args(const Calculator_zip_args&);
  Calculator_zip_args& operator=(const Calculator_zip_args&);
  Calculator_zip_args() {
  }

  virtual ~Calculator_zip_args() throw();

  bool operator == (const Calculator_zip_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const Calculator_zip_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Calculator_zip_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class Calculator_zip_pargs {
 public:


  virtual ~Calculator_zip_pargs() throw();

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

class CalculatorClient : virtual public CalculatorIf, public  ::shared::SharedServiceClient {
 public:
  CalculatorClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) :
     ::shared::SharedServiceClient(prot, prot) {}
  CalculatorClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) :     ::shared::SharedServiceClient(iprot, oprot) {}
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  void ping();
  void send_ping();
  void recv_ping();
  int32_t add(const int32_t num1, const int32_t num2);
  void send_add(const int32_t num1, const int32_t num2);
  int32_t recv_add();
  int32_t calculate(const int32_t logid, const Work& w);
  void send_calculate(const int32_t logid, const Work& w);
  int32_t recv_calculate();
  void zip();
  void send_zip();
};

class CalculatorProcessor : public  ::shared::SharedServiceProcessor {
 protected:
  boost::shared_ptr<CalculatorIf> iface_;
  virtual bool dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext);
 private:
  typedef  void (CalculatorProcessor::*ProcessFunction)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*);
  typedef std::map<std::string, ProcessFunction> ProcessMap;
  ProcessMap processMap_;
  void process_ping(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_add(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_calculate(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_zip(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  CalculatorProcessor(boost::shared_ptr<CalculatorIf> iface) :
     ::shared::SharedServiceProcessor(iface),
    iface_(iface) {
    processMap_["ping"] = &CalculatorProcessor::process_ping;
    processMap_["add"] = &CalculatorProcessor::process_add;
    processMap_["calculate"] = &CalculatorProcessor::process_calculate;
    processMap_["zip"] = &CalculatorProcessor::process_zip;
  }

  virtual ~CalculatorProcessor() {}
};

class CalculatorProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  CalculatorProcessorFactory(const ::boost::shared_ptr< CalculatorIfFactory >& handlerFactory) :
      handlerFactory_(handlerFactory) {}

  ::boost::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo);

 protected:
  ::boost::shared_ptr< CalculatorIfFactory > handlerFactory_;
};

class CalculatorMultiface : virtual public CalculatorIf, public  ::shared::SharedServiceMultiface {
 public:
  CalculatorMultiface(std::vector<boost::shared_ptr<CalculatorIf> >& ifaces) : ifaces_(ifaces) {
    std::vector<boost::shared_ptr<CalculatorIf> >::iterator iter;
    for (iter = ifaces.begin(); iter != ifaces.end(); ++iter) {
       ::shared::SharedServiceMultiface::add(*iter);
    }
  }
  virtual ~CalculatorMultiface() {}
 protected:
  std::vector<boost::shared_ptr<CalculatorIf> > ifaces_;
  CalculatorMultiface() {}
  void add(boost::shared_ptr<CalculatorIf> iface) {
     ::shared::SharedServiceMultiface::add(iface);
    ifaces_.push_back(iface);
  }
 public:
  void ping() {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->ping();
    }
    ifaces_[i]->ping();
  }

  int32_t add(const int32_t num1, const int32_t num2) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->add(num1, num2);
    }
    return ifaces_[i]->add(num1, num2);
  }

  int32_t calculate(const int32_t logid, const Work& w) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->calculate(logid, w);
    }
    return ifaces_[i]->calculate(logid, w);
  }

  void zip() {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->zip();
    }
    ifaces_[i]->zip();
  }

};

// The 'concurrent' client is a thread safe client that correctly handles
// out of order responses.  It is slower than the regular client, so should
// only be used when you need to share a connection among multiple threads
class CalculatorConcurrentClient : virtual public CalculatorIf, public  ::shared::SharedServiceConcurrentClient {
 public:
  CalculatorConcurrentClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) :
     ::shared::SharedServiceConcurrentClient(prot, prot) {}
  CalculatorConcurrentClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) :     ::shared::SharedServiceConcurrentClient(iprot, oprot) {}
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  void ping();
  int32_t send_ping();
  void recv_ping(const int32_t seqid);
  int32_t add(const int32_t num1, const int32_t num2);
  int32_t send_add(const int32_t num1, const int32_t num2);
  int32_t recv_add(const int32_t seqid);
  int32_t calculate(const int32_t logid, const Work& w);
  int32_t send_calculate(const int32_t logid, const Work& w);
  int32_t recv_calculate(const int32_t seqid);
  void zip();
  void send_zip();
};

class CalculatorCobClient;

class CalculatorCobClIf : virtual public  ::shared::SharedServiceCobClIf {
 public:
  virtual ~CalculatorCobClIf() {}

  /**
   * A method definition looks like C code. It has a return type, arguments,
   * and optionally a list of exceptions that it may throw. Note that argument
   * lists and exception lists are specified using the exact same syntax as
   * field lists in struct or exception definitions.
   */
  virtual void ping(tcxx::function<void(CalculatorCobClient* client)> cob) = 0;
  virtual void add(tcxx::function<void(CalculatorCobClient* client)> cob, const int32_t num1, const int32_t num2) = 0;
  virtual void calculate(tcxx::function<void(CalculatorCobClient* client)> cob, const int32_t logid, const Work& w) = 0;

  /**
   * This method has a oneway modifier. That means the client only makes
   * a request and does not listen for any response at all. Oneway methods
   * must be void.
   */
  virtual void zip(tcxx::function<void(CalculatorCobClient* client)> cob) = 0;
};

class CalculatorCobSvIf : virtual public  ::shared::SharedServiceCobSvIf {
 public:
  virtual ~CalculatorCobSvIf() {}

  /**
   * A method definition looks like C code. It has a return type, arguments,
   * and optionally a list of exceptions that it may throw. Note that argument
   * lists and exception lists are specified using the exact same syntax as
   * field lists in struct or exception definitions.
   */
  virtual void ping(tcxx::function<void()> cob) = 0;
  virtual void add(tcxx::function<void(int32_t const& _return)> cob, const int32_t num1, const int32_t num2) = 0;
  virtual void calculate(tcxx::function<void(int32_t const& _return)> cob, tcxx::function<void(::apache::thrift::TDelayedException* _throw)> /* exn_cob */, const int32_t logid, const Work& w) = 0;

  /**
   * This method has a oneway modifier. That means the client only makes
   * a request and does not listen for any response at all. Oneway methods
   * must be void.
   */
  virtual void zip(tcxx::function<void()> cob) = 0;
};

class CalculatorCobSvIfFactory : virtual public  ::shared::SharedServiceCobSvIfFactory {
 public:
  typedef CalculatorCobSvIf Handler;

  virtual ~CalculatorCobSvIfFactory() {}

  virtual CalculatorCobSvIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler( ::shared::SharedServiceCobSvIf* /* handler */) = 0;
};

class CalculatorCobSvIfSingletonFactory : virtual public CalculatorCobSvIfFactory {
 public:
  CalculatorCobSvIfSingletonFactory(const boost::shared_ptr<CalculatorCobSvIf>& iface) : iface_(iface) {}
  virtual ~CalculatorCobSvIfSingletonFactory() {}

  virtual CalculatorCobSvIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
    return iface_.get();
  }
  virtual void releaseHandler( ::shared::SharedServiceCobSvIf* /* handler */) {}

 protected:
  boost::shared_ptr<CalculatorCobSvIf> iface_;
};

class CalculatorCobSvNull : virtual public CalculatorCobSvIf , virtual public  ::shared::SharedServiceCobSvNull {
 public:
  virtual ~CalculatorCobSvNull() {}
  void ping(tcxx::function<void()> cob) {
    return cob();
  }
  void add(tcxx::function<void(int32_t const& _return)> cob, const int32_t /* num1 */, const int32_t /* num2 */) {
    int32_t _return = 0;
    return cob(_return);
  }
  void calculate(tcxx::function<void(int32_t const& _return)> cob, tcxx::function<void(::apache::thrift::TDelayedException* _throw)> /* exn_cob */, const int32_t /* logid */, const Work& /* w */) {
    int32_t _return = 0;
    return cob(_return);
  }
  void zip(tcxx::function<void()> cob) {
    return cob();
  }
};

class CalculatorCobClient : virtual public CalculatorCobClIf, public  ::shared::SharedServiceCobClient {
 public:
  CalculatorCobClient(boost::shared_ptr< ::apache::thrift::async::TAsyncChannel> channel, ::apache::thrift::protocol::TProtocolFactory* protocolFactory) :
     ::shared::SharedServiceCobClient(channel, protocolFactory) {}
  boost::shared_ptr< ::apache::thrift::async::TAsyncChannel> getChannel() {
    return channel_;
  }
  virtual void completed__(bool /* success */) {}
  void ping(tcxx::function<void(CalculatorCobClient* client)> cob);
  void send_ping();
  void recv_ping();
  void add(tcxx::function<void(CalculatorCobClient* client)> cob, const int32_t num1, const int32_t num2);
  void send_add(const int32_t num1, const int32_t num2);
  int32_t recv_add();
  void calculate(tcxx::function<void(CalculatorCobClient* client)> cob, const int32_t logid, const Work& w);
  void send_calculate(const int32_t logid, const Work& w);
  int32_t recv_calculate();
  void zip(tcxx::function<void(CalculatorCobClient* client)> cob);
  void send_zip();
};

class CalculatorAsyncProcessor : public  ::shared::SharedServiceAsyncProcessor {
 protected:
  boost::shared_ptr<CalculatorCobSvIf> iface_;
  virtual void dispatchCall(tcxx::function<void(bool ok)> cob, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid);
 private:
  typedef  void (CalculatorAsyncProcessor::*ProcessFunction)(tcxx::function<void(bool ok)>, int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*);
  typedef std::map<std::string, ProcessFunction> ProcessMap;
  ProcessMap processMap_;
  void process_ping(tcxx::function<void(bool ok)> cob, int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot);
  void return_ping(tcxx::function<void(bool ok)> cob, int32_t seqid, ::apache::thrift::protocol::TProtocol* oprot, void* ctx);
  void throw_ping(tcxx::function<void(bool ok)> cob, int32_t seqid, ::apache::thrift::protocol::TProtocol* oprot, void* ctx, ::apache::thrift::TDelayedException* _throw);
  void process_add(tcxx::function<void(bool ok)> cob, int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot);
  void return_add(tcxx::function<void(bool ok)> cob, int32_t seqid, ::apache::thrift::protocol::TProtocol* oprot, void* ctx, const int32_t& _return);
  void throw_add(tcxx::function<void(bool ok)> cob, int32_t seqid, ::apache::thrift::protocol::TProtocol* oprot, void* ctx, ::apache::thrift::TDelayedException* _throw);
  void process_calculate(tcxx::function<void(bool ok)> cob, int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot);
  void return_calculate(tcxx::function<void(bool ok)> cob, int32_t seqid, ::apache::thrift::protocol::TProtocol* oprot, void* ctx, const int32_t& _return);
  void throw_calculate(tcxx::function<void(bool ok)> cob, int32_t seqid, ::apache::thrift::protocol::TProtocol* oprot, void* ctx, ::apache::thrift::TDelayedException* _throw);
  void process_zip(tcxx::function<void(bool ok)> cob, int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot);
  void return_zip(tcxx::function<void(bool ok)> cob, int32_t seqid, ::apache::thrift::protocol::TProtocol* oprot, void* ctx);
  void throw_zip(tcxx::function<void(bool ok)> cob, int32_t seqid, ::apache::thrift::protocol::TProtocol* oprot, void* ctx, ::apache::thrift::TDelayedException* _throw);
 public:
  CalculatorAsyncProcessor(boost::shared_ptr<CalculatorCobSvIf> iface) :
     ::shared::SharedServiceAsyncProcessor(iface),
    iface_(iface) {
    processMap_["ping"] = &CalculatorAsyncProcessor::process_ping;
    processMap_["add"] = &CalculatorAsyncProcessor::process_add;
    processMap_["calculate"] = &CalculatorAsyncProcessor::process_calculate;
    processMap_["zip"] = &CalculatorAsyncProcessor::process_zip;
  }

  virtual ~CalculatorAsyncProcessor() {}
};

class CalculatorAsyncProcessorFactory : public ::apache::thrift::async::TAsyncProcessorFactory {
 public:
  CalculatorAsyncProcessorFactory(const ::boost::shared_ptr< CalculatorCobSvIfFactory >& handlerFactory) :
      handlerFactory_(handlerFactory) {}

  ::boost::shared_ptr< ::apache::thrift::async::TAsyncProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo);

 protected:
  ::boost::shared_ptr< CalculatorCobSvIfFactory > handlerFactory_;
};

#ifdef _WIN32
  #pragma warning( pop )
#endif

} // namespace

#endif

/*
*  time: $time$
*  writer: zhangys
*  filename: $safeitemname$
*/

#ifndef NUX_OBJECT_H_
#define NUX_OBJECT_H_

#include <string>
#include <iostream>
#include <memory>
#include <sstream>
#include <functional>
#include <cassert>

using namespace std;

namespace Nux {

    class NException : public std::exception {
    public:
        NException() : message_() {}

        NException(const std::string& message) : message_(message) {}

        virtual ~NException() throw() {}

        virtual const char* what() const throw() {
            if (message_.empty()) {
                return "Default NException.";
            }
            else {
                return message_.c_str();
            }
        }

    protected:
        std::string message_;
    };

    class NDelayedException {
    public:
        template <class E>
        static NDelayedException* delayException(const E& e);
        virtual void throw_it() = 0;
        virtual ~NDelayedException(){};
    };

    template <class E>
    class NExceptionWrapper : public NDelayedException {
    public:
        NExceptionWrapper(const E& e) : e_(e) {}
        virtual void throw_it() {
            E temp(e_);
            delete this;
            throw temp;
        }

    private:
        E e_;
    };

    template <class E>
    NDelayedException* NDelayedException::delayException(const E& e) {
        return new NExceptionWrapper<E>(e);
    }

    class NObject {
    public:
        string const toString() { return ""; }
    };
}
#endif

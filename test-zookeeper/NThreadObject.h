/*
*  time: $time$
*  writer: zhangys
*  filename: $safeitemname$
*/

#ifndef NUX_VIRTUAL_THREAD_OBJECT_H_
#define NUX_VIRTUAL_THREAD_OBJECT_H_

#include "NObject.h"

using namespace std;

namespace Nux {

    class NThreadObject : public NObject {
    public:
        virtual void run_virt() {
            // do nothing or throw a exception
        }
    };

    class NThreadObjectDefaults : public NThreadObject {
    public:
        /*
        * NThreadObject *_virt() methods provide reasonable default implementations.
        * Invoke them non-virtually.
        */
        void run() { return this->NThreadObject::run_virt(); }

    protected:
        NThreadObjectDefaults() {}
    };

    /*
    *  
    */
    template <class N, class Super_ = NThreadObjectDefaults>
    class NVirtualThreadObject:  public Super_
    {
    private:
        NThreadObject(){};
        /*
        * Implementations of the *_virt() functions, to call the subclass's
        * non-virtual implementation function.
        */
        virtual void run_virt() {
            return static_cast<N*>(this)->run();
        }
    public:
        void operator() () { run_virt(); }
    protected:
        NVirtualThreadObject() {}
    };

}
#endif
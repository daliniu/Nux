#include "NServicesRegistry.h"
#include <thread>

using namespace Nux;
using namespace std;

int main()
{
    NServicesRegistry nsr("127.0.0.1:2181", 2000);
    thread  t(nsr);
    t.join();
}
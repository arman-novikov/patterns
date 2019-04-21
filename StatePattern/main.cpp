#include "IProcess.h"

int main()
{
    Process p;
    p.getReady();
    p.getStarted();
    p.getStarted();
    p.getStopped();
    p.getStarted();
    p.getReady();

    return 0;
}

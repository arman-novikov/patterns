#include "observed.h"
#include "observer.h"
#include <string>

using std::string;

int main()
{
    Observed<string> obsed;
    Observer obser1, obser2, obser3;

    obsed.addObserver(obser1);
    obsed.addObserver(obser2);
    obsed.addObserver(obser3);

    obsed.setEvent(string("Hi!"));

    obsed.removeObserver(obser2);

    obsed.setEvent(string("Go!"));

    return 0;
}

#include "IProducer.h"

using namespace std;

int main()
{
    ProducerA Apro;
    ProducerB Bpro;
    const IProducer* producers[2] {&Apro, &Bpro};

    for (int i = 0; i < 2; ++i) {
        unique_ptr<IProduct> product(producers[i]->produce());
        product->use();
    }
    return 0;
}

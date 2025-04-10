#include <iostream>
#include <thread>
#include <unistd.h>
#include <mutex>
#include <vector>
#include <semaphore.h>


using namespace std;

mutex mtx;

void stampa(string utente) {
    mtx.lock(); // accede in mutua esclusione
    cout << utente << " sta stampando..." << endl;
    sleep(1); // simula il tempo di stampa
    cout << utente << " ha finito di stampare." << endl;
    mtx.unlock(); // libera la stampante
}


int main()
{
    
    thread t1(stampa, "Utente1");
    thread t2(stampa, "Utente2");
    thread t3(stampa, "Utente3");

    t1.join();
    t2.join();
    t3.join();

    return 0;
}

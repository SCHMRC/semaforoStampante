#include <iostream>
#include <thread>
#include <unistd.h>
#include <mutex>
#include <vector>
#include <semaphore.h>


using namespace std;


sem_t stampante; // semaforo binario

void stampa(string utente) {
    sem_wait(&stampante); // accede in mutua esclusione
    cout << utente << " sta stampando..." << endl;
    sleep(1); // simula il tempo di stampa
    cout << utente << " ha finito di stampare." << endl;
    sem_post(&stampante); // libera la stampante
}


int main()
{
    sem_init(&stampante, 0, 1); // semaforo binario inizializzato a 1

    thread t1(stampa, "Utente1");
    thread t2(stampa, "Utente2");
    thread t3(stampa, "Utente3");

    t1.join();
    t2.join();
    t3.join();

    sem_destroy(&stampante);

    return 0;
}

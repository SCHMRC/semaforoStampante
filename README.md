# 🖨️ Accesso esclusivo a una stampante condivisa: due soluzioni a confronto

## 📚 Consegna

Implementa un programma in C++ che simuli **tre utenti** che vogliono stampare da una **stampante condivisa**.  
Solo **un utente alla volta** può accedere alla stampante.

### 🔁 Realizza due versioni distinte del programma:
1. Una usando `std::mutex` per proteggere l’accesso alla stampante  
2. Una usando `sem_t` come **semaforo binario** per lo stesso scopo

---

## ✅ Requisiti

- I tre thread devono stampare un messaggio che indichi **quando iniziano e finiscono di stampare**.
- Ogni thread deve **dormire 1 secondo** per simulare la stampa.
- L’accesso alla stampante deve essere **mutuamente esclusivo**.
- I messaggi **non devono sovrapporsi** (cioè: solo un thread per volta deve stampare).

---

## 💡 Esempio di output corretto

```text
Utente2 sta stampando...
Utente2 ha finito di stampare.
Utente1 sta stampando...
Utente1 ha finito di stampare.
Utente3 sta stampando...
Utente3 ha finito di stampare.

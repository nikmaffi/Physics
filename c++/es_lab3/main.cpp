#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cmath>

/*
Alloca vettore per un array di N int.
Restituisce l'indirizzo dell'array.
*/
int *alloca_vettore(int n) {
    return new int[n];
}

//Libera la memoria occupata da un array di int.
void dealloca_vettore(int *v) {
    delete[] v;
}

/*
Legge dalla tastiera un array di n int.
L'array è creato nella funzione con allocazione dinamica.
Restituisce l'indirizzo dell'array.
*/
int *legge_vettore(int n) {
    int *v = new int[n]; //Alloca memoria per l'array

    for(int i = 0; i < n; i++) {
        std::cout << "Elemento numero " << i + 1 << ": ";
        std::cin >> v[i];
    }

    return v; //Restituisce l'indirizzo dell'array
}

//Stampa un array di n int a video
void stampa_vettore(int *v, int n) {
    std::cout << "[ ";

    for(int i = 0; i < n; i++) {
        std::cout << v[i] << " ";
    }

    std::cout << "]" << std::endl;
}

//Restituisce un int casuale fra min e max
int numero_casuale(int min, int max) {
    return rand() % (max - min + 1) + min;
}

/*
Genera un array di n int casuali.
Alloca memoria per l'array.
Riempie l'array con numeri casuali fra min e max.
Restituisce l'indirizzo dell'array.
*/
int *vettore_casuale(int n, int min, int max) {
    int *v = alloca_vettore(n); //Alloca memoria per il vettore casuale chiamando alloca_vettore

    //Riempie l'array con numeri casuali con un ciclo
    for(int i = 0; i < n; i++) {
        //Chiamando numero_casuale
        v[i] = numero_casuale(min, max);
    }

    //Restituisce l'indirizzo dell'array
    return v;
}

/*
Calcola la somma di due vettori v1 e v2 ciascuno con n elementi.
Alloca memoria per il vettore risultante.
Calcola la somma elemento per elemento con un ciclo.
Restituisce l'indirizzo dell'array risultante.
*/
int *somma_vettori(int *v1, int *v2, int n) {
    int *r = alloca_vettore(n); //Alloca memoria per il vettore risultante chiamando alloca_vettore

    //Riempire l'array r con la somma di v1 e v2 elemento per elemento con un ciclo
    for(int i = 0; i < n; i++) {
        r[i] = v1[i] + v2[i];
    }

    //Restituire l'indirizzo dell'array
    return r;
}

/*
Calcola il prodotto elemento per elemento di un array per uno scalare.
Alloca memoria per l'array risultante.
Restituisce l'indirizzo dell'array risultante.
*/
int *prodotto_per_scalare(int *v, int n, int scalare) {
    int *r = alloca_vettore(n); //Alloca memoria per il vettore risultante

    //Prodotto per scalare calcolato con un ciclo
    for(int i = 0; i < n; i++) {
        r[i] = v[i] * scalare;
    }

    //Restituisce l'indirizzo di r
    return r;
}

/*
Calcola la differenza di due vettori v1 e v2 ciascuno con n elementi.
Alloca memoria per il vettore risultante.
Calcola la differenza utilizzando somma_vettori e prodotto_per_scalare.
Restituisce l'indirizzo dell'array risultante.
*/
int *differenza_vettori(int *v1, int *v2, int n) {
    int *neg_v2 = prodotto_per_scalare(v2, n, -1); //Negazione delle componenti di v2
    int *r = somma_vettori(v1, neg_v2, n); //Calcolo della differenza tramite la somma

    //Deallocazione dell'array neg_v2 perchè non più necessario
    dealloca_vettore(neg_v2);

    //Restituire l'indirizzo dell'array
    return r;
}

//Calcola la norma di un vettore di n componenti tramite un ciclo
double norma_vettore(int *v, int n) {
    int somma = 0; //Inizializzazione somma a 0

    //La norma è la radice della somma dei quadrati delle n componenti
    for(int i = 0; i < n; i++) {
        somma += std::sqrt(std::pow(v[i], 2));
    }

    //Restituisce la radice quadrata della sommatoria
    return std::sqrt(somma);
}

//Calcola il prodotto scalare fra due vettori di n componenti
double prodotto_scalare(int *v1, int *v2, int n, double theta) {
    //Il prodotto scalare tra2 vettori è il prodotto tra le norme dei 2 vettori ed il coseno dell'angolo compreso
    return norma_vettore(v1, n) * norma_vettore(v2, n) * std::cos(theta);
}

//Restituisce l'indice dell'elemento massimo del sottovettore in v
int max_in_subv(int *v, int n, int inf, int sup) {
    int idx = 0; //Indice dell'elemento
    int max = 0; //Numero massimo
    
    //Verifica 0 <= inf < sup <= n - 1
    if(inf >= sup || inf < 0 || sup > n - 1) {
        return -1; //Restituisco un indice non valido
    }

    //Inizializzazione
    idx = inf;
    max = v[idx];

    //Calcolo dell'indice del numero massimo con un ciclo
    for(int i = inf + 1; i <= sup; i++) {
        if(v[i] > max) {
            max = v[i];
            idx = i;
        }
    }

    //Restituisce l'indice
    return idx;
}

//Funzione che scambia 2 variabili tramite swap classico
void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

//Ordina l'array tramite selection sort
void selection_sort(int *v, int n) {
    int max = 0; //Indice nel numero massimo nei sottovettori di v

    //Scambiare l'ultimo elemento del sottovettore con l'elemento massimo tramite ciclo
    for(int i = n - 1; i > 0; i--) {
        max = max_in_subv(v, n, 0, i);

        //Scambio degli elementi
        swap(v[i], v[max]);
    }
}

/*
Partiziona l'array tramite un perzo (a dx di p -> num > p | a sx di p -> num < p)
Restituisce l'indice del perno dopo lo scambio
*/
int partiziona(int *v, int inf, int sup) {
    int p = v[inf]; //Per def. il perno è all'indice inf
    int i = inf + 1, j = sup; //Inizializzazione dei contatori

    //Se i > j allora l'array è partizionato
    while(i <= j) {
        if(v[i] <= p) {
            i++; //Se l'i-esimo elemento <= p allora procedere (incrementare i)
        } else if(v[i] > p && v[j] > p) {
            j--; //Se l'i-esimo ed il j-esimo elemento > p allore procedere (decrementare j)
        } else if(v[i] > p && v[j] <= p) {
            swap(v[i], v[j]); //Scambiare i 2 elementi
            //Avanzare i contatori
            i++;
            j--;
        }
    }

    //Porto il perno nella posizione corretta
    swap(v[inf], v[j]);

    //Restituisco l'indice nuovo del perno
    return j;
}

//Ordina gli elementi dell'array tramite il quick_sort
void quick_sort(int *v, int inf, int sup) {
    int p = 0; //Indice del perno

    //Caso base (array di dimensione < 2)
    if(sup - inf < 1) {
        return;
    }

    //Partizionamento dell'array
    p = partiziona(v, inf, sup);

    //Chiamate ricorsive (quick sort su meta' dx e sx)
    quick_sort(v, inf, p - 1);
    quick_sort(v, p + 1, sup);
}

//Funzione che calcola la massima sequenza crescente in un vettore
int *max_seq_cre(int *v, int n, int &n_seq) {
    int idx = 0; //indice del primo elemento della ssq
    int len = 1; //Contatore della lunghezza della sequenza (parte da 1 perchè un singolo numero è una ssq crescente)
    int max_len = 0; //Massima sequenza letta fin'ora
    int max_idx = 0; //Indice della ssq piu' lunga
    
    //Vettore della sequenza
    int *seq = nullptr;

    //Itero su tutti gli elementi del vettore
    for(int i = 0; i < n - 1; i++) {
        //Se l'el corente è < del successivo allora c'è una seq parziale
        if(v[i] < v[i + 1]) {
            //Incremento la lunghezza
            len++;

            //Se siamo sul primo elemento o questo è il primo elemento della nuova seq trovata
            if(i == 0 || v[i - 1] > v[i]) {
                idx = i; //Salvo l'indice della sequenza
            }
        } else if(len > max_len) { //Se la lunghezza sella ssq è maggiore di quella considerata fino ad ora
            max_len = len; //Salvataggio lunghezza nuova ssq
            max_idx = idx; //Salvataggio indice del primo elemento della nuova ssq

            len = 1; //Reset del contatore di lung per nuovo calcolo
        }
    }

    //Allocazione dell'array risultante
    n_seq = max_len;
    seq = alloca_vettore(n_seq);

    //Copia dei valori della ssq
    for(int i = 0; i < max_len; i++) {
        seq[i] = v[max_idx + i];
    }

    //Restituzione dell'indirizzo dell'array risultante
    return seq;
}

//PROVVISORIA!!!!!!!
//Funzione che calcola la differenza (in termini di elementi discordanti) di 2 vettori
int *diff_discord(int *v1, int n1, int *v2, int n2, int &n_seq) {
    int *r = nullptr; //Array risultante
    int *presenze = alloca_vettore(n1); //Array spiegato più avanti
    int nr = 0; //Dimensione dell'array risultante
    bool presente = false; //Flag per vedere se un elemento è sia in v1 sia in v2

    /*
    Array presenze:

    L'array presenze è associato con v1: esempio
    v1 =       [1, 2, 3, 4]
    presenze = [0, 0, 1, 1]
    v2 =       [3, 4, 5, 6, 7]

    Ogni elemento di presenze è un numero (0 o 1) che indica se l'elemnto corrispondente in v1
    e presente o no in v2 (0 non presente | 1 presente).
    */

    //Ciclo su v1 per vedere se gli elementi sono presenti o no in v2
    for(int i = 0; i < n1; i++) {
        for(int j = 0; j < n2 && !presente; j++) {
            //Se si trova il numero in v2 allora il ciclo termina
            if(v1[i] == v2[j]) {
                presente = true; //Flag settato a false per terminare il ciclo prematuramente
            }
        }

        //Se il flag è stato inalterato allora l'elemento non e' presente in v2
        if(!presente) {
            nr++;
        }

        //Impostazione dell'array presenze in base al flag
        presenze[i] = presente;

        //Reset del flag per il prossimo giro
        presente = false;
    }

    //Allocazione del vettore risultante e impostazione della dimensione
    n_seq = nr;
    r = alloca_vettore(n_seq);

    //Prendo solo gli elementi non presenti (corrispondenze a zero nell'array presenze)
    for(int i = 0, j = 0; i < n1; i++) {
        if(presenze[i] == 0) {
            //Aggiungo l'elemento nel vettore risultante e incremento il suo contatore (j)
            r[j] = v1[i];
            j++;
        }
    }

    //Restituisco l'indirizzo dell'array risultante
    return r;
}

int main() {
    //Test 1
    std::cout << "\nTest 1\n";
    int *v0 = alloca_vettore(10);
    dealloca_vettore(v0);

    //Test 2
    std::cout << "\nTest 2\n";
    int *v1= legge_vettore(10);
    stampa_vettore(v1, 10);
    dealloca_vettore(v1);

    //Test 3
    std::cout << "\nTest 3\n";
    int *v2 = vettore_casuale(10, 0, 9);
    stampa_vettore(v2, 10);
    dealloca_vettore(v2);

    //Test 4
    std::cout << "\nTest 4\n";
    int v3[4] = {1, 2, 3, 4}, v4[4] = {5, 6, 7, 8};
    int *som = somma_vettori(v3, v4, 4);
    int *sub = differenza_vettori(v3, v4, 4);
    int *pps = prodotto_per_scalare(v3, 4, 2);
    double ps = prodotto_scalare(v3, v4, 4, 3.1415 / 4);
    double norm = norma_vettore(v3, 4);

    stampa_vettore(som, 4);
    stampa_vettore(sub, 4);
    stampa_vettore(pps, 4);
    std::cout << ps << "\n" << norm << "\n\n";

    dealloca_vettore(som); dealloca_vettore(sub); dealloca_vettore(pps);

    //Test 5
    int v5[6] = {1, 2, 3, 4, 5, 6};
    std::cout << v5[max_in_subv(v5, 6, 2, 4)] << "\n\n";

    //Test 6
    int v6[11] = {5, 10, 8, 1, 4, 7, 2, 3, 9, 6, 0};
    int v7[5] = {5, 4, 3, 2, 1}, v8[5] = {5, 4, 3, 2, 1};
    int *v9 = vettore_casuale(100, 1, 100);
    int *v10 = vettore_casuale(100, 1, 100);
    int *v11 = vettore_casuale(200000, 0, 1000);
    int *v12 = vettore_casuale(200000, 0, 1000);

    partiziona(v6, 0, 10);
    stampa_vettore(v6, 11);

    selection_sort(v7, 5);
    stampa_vettore(v7, 5);

    double start = std::clock();
    selection_sort(v9, 100);
    double end = std::clock();
    double seconds = (end / start) / CLOCKS_PER_SEC;
    std::cout << "Sel sort 100: " << seconds << " s\n";

    /*start = std::clock();
    selection_sort(v11, 200000);
    end = std::clock();
    seconds = (end / start) / CLOCKS_PER_SEC;
    std::cout << "Sel sort 200000: " << seconds << " s\n";*/

    quick_sort(v8, 0, 4);
    stampa_vettore(v8, 5);

    start = std::clock();
    quick_sort(v10, 0, 99);
    end = std::clock();
    seconds = (end / start) / CLOCKS_PER_SEC;
    std::cout << "Q sort 100: " << seconds << " s\n";

    start = std::clock();
    quick_sort(v12, 0, 199999);
    end = std::clock();
    seconds = (end / start) / CLOCKS_PER_SEC;
    std::cout << "Q sort 200000: " << seconds << " s\n";

    dealloca_vettore(v9); dealloca_vettore(v10); dealloca_vettore(v11); dealloca_vettore(v12);

    //Test 7
    int *v13 = vettore_casuale(10, 0, 9);
    int *v14 = vettore_casuale(5, 0, 9);
    int *r1, *r2;
    int dimr1, dimr2;

    stampa_vettore(v13, 10);
    stampa_vettore(v14, 5);
    
    r1 = max_seq_cre(v13, 10, dimr1);
    stampa_vettore(r1, dimr1);

    r2 = diff_discord(v13, 10, v14, 5, dimr2);
    stampa_vettore(r2, dimr2);

    dealloca_vettore(v13); dealloca_vettore(v14); dealloca_vettore(r1); dealloca_vettore(r2);

    return EXIT_SUCCESS;
}
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

unsigned int ns[] = { 10000 };

void fill_increasing(int *t, unsigned int n) {
    // TODO: implement
     for(int i = 0; i < n; i++)
    {
        t[i] = i;
    }
}

void fill_decreasing(int *t, unsigned int n) {
    // TODO: implement
            for(int i = 0; i < n; i++)
    {
        t[i] = n-i;
    }
}

void fill_vshape(int *t, unsigned int n) {
    // TODO: implement // zapelnianie do polowy
    int c = 0;
    for(int i =n; c<(n/2); i=i-2)
    {
        t[c]=i;
        c++;
    }
    c=n-1;
    for(int i = n-1; c>=(n/2); i=i-2)
    {
        t[c]=i;
        c--;
    }
}

void selection_sort(int *t, unsigned int n) {
    int pom;
    int zmiana;
    for (int i = 0; i < n; i++)
    {
        pom = i;
        for(int j= i+1; j<n; j++)
        {
            if(t[j] < t [pom])
            {
                pom = j;

                //swap(t[pom], t[i]);}
        }
    }
                zmiana = t[pom];
                t[pom] = t[i];
                t[i] = zmiana;
}
}

void insertion_sort(int *t, unsigned int n) {
    // TODO: implement
    int zmiana;
    for(int j=0; j<n; j++)
    {
    for(int i=j+1; i>0; i--)
    {
        if (t[i]<t[i-1])
        {
            //swap(t[i],t[i+1]);
             zmiana = t[i];
            t[i]=t[i-1];
            t[i-1]=zmiana;

        }
    }
}
}



int podziel(int *t, int poczatek, int koniec)
{
        int x = t[poczatek];
        int i = poczatek, j = koniec, w;
    while (1)
    {
        while (t[j] > x)
            j--;
            while (t[i] < x)
                    i++;
                if (i < j)
                {
                w = t[i];
                t[i] = t[j];
                t[j] = w;
                i++;
                j--;
                }
                else
                return j;
    }
}

 int podziel_random (int *t,int poczatek, int koniec){
        int x=rand()%koniec+poczatek;
        int pomoc = t[koniec];
        t[koniec] = t[x];
        t[x] = pomoc;
        //swap(&t[x],&t[koniec]);
        return podziel (t, poczatek,koniec);

 }

void quicksort(int *t, int poczatek, int koniec)
{

        int q;
        if (poczatek < koniec)
        {
        q = podziel/*_random*/(t, poczatek, koniec);
        quicksort(t, poczatek, q);
        quicksort(t, q+1, koniec);
        }
}

void quick_sort(int *t, unsigned int n) {
        quicksort(t, 0, n-1);
}


void heap_sort(int *t, unsigned int n) {

int *dod = malloc(n * sizeof(*dod)); // alokacja pamieci na n wskazników dod
memset(dod, 0, n);// zeruje tablice dod
int rodzic;
int lewo;
int prawo;
int minimalny;
int index;
int rozmiar;
int i = 0; // tworze potrzebne zmienne

    while(i < n)
        {
        index = i;
        dod[i] = t[i];
        while(1)
        {
            if(0<index)
            {
                rodzic = (index - 1) / 2;
                if(dod[index] < dod[rodzic])
                {
                        int pom = dod[index];     // zamiana
                        dod[index] = dod[rodzic];
                        dod[rodzic] = pom;
                }
            }
            else
            {
              break;
            }


            index = rodzic;
        } // do while
        i++;
        rozmiar = i;
        } // do while
        i=0;
        while(i < n)
        {
        index = 0;
        rozmiar--;
        t[i] = dod[0];
        dod[0] = dod[rozmiar];
            while(1)
            {
                lewo = index * 2 + 1;
                prawo = index * 2 + 2;
                    if(lewo >= rozmiar)
            {
                    break;
            }
            if((prawo >= rozmiar) || (dod[lewo] < dod[prawo]))
            {
                minimalny = lewo;
            }
            else
            {
                minimalny = prawo;
            }
            if(dod[minimalny] < dod[index])
            {
                        int pom1 = dod[index];
                        dod[index] = dod[minimalny];
                        dod[minimalny] = pom1;   // zamiana
            }
                            index = minimalny;
            }
    i++;
    }
}

void fill_random(int *t, unsigned int n) {
    for (unsigned int i = 0; i < n; i++) {
        t[i] = rand();
    }
}

void is_random(int *t, unsigned int n) {
    return;
}

void is_increasing(int *t, unsigned int n) {
    for (unsigned int i = 1; i < n; i++) {
        assert(t[i] > t[i - 1]);
    }
}

void is_decreasing(int *t, unsigned int n) {
    for (unsigned int i = 1; i < n; i++) {
        assert(t[i] < t[i - 1]);
    }
}

void is_vshape(int *t, unsigned int n) {
    int *begin = t;
    int *end = t + n - 1;

    while (end - begin > 1) {
        assert(*begin > *end);
        begin++;
        assert(*end > *begin);
        end--;
    }
}

void is_sorted(int *t, unsigned int n) {
    for (unsigned int i = 1; i < n; i++) {
        assert(t[i] >= t[i - 1]);
    }
}

void (*fill_functions[])(int *, unsigned int) = { fill_random, fill_increasing, fill_decreasing, fill_vshape };
void (*check_functions[])(int *, unsigned int) = { is_random, is_increasing, is_decreasing, is_vshape };
void (*sort_functions[])(int *, unsigned int) = { selection_sort, insertion_sort, quick_sort, heap_sort };

char *fill_names[] = { "Random", "Increasing", "Decreasing", "V-Shape" };
char *sort_names[] = { "SelectionSort", "InsertionSort", "QuickSort", "HeapSort" };

int main() {
    for (unsigned int i = 0; i < sizeof(sort_functions) / sizeof(*sort_functions); i++) {
        void (*sort)(int *, unsigned int) = sort_functions[i];

        for (unsigned int j = 0; j < sizeof(fill_functions) / sizeof(*fill_functions); j++) {
            void (*fill)(int *, unsigned int) = fill_functions[j];
            void (*check)(int *, unsigned int) = check_functions[j];

            for (unsigned int k = 0; k < sizeof(ns) / sizeof(*ns); k++) {
                unsigned int n = ns[k];
                int *t = malloc(n * sizeof(*t));

                fill(t, n);
                check(t, n);

                clock_t begin = clock();
                sort(t, n);
                clock_t end = clock();
                is_sorted(t, n);

                printf("%s\t%s\t%u\t%f\n", sort_names[i], fill_names[j], n, (double)(end - begin) / (double) CLOCKS_PER_SEC);
                free(t);
            }
        }
    }
    return 0;
}

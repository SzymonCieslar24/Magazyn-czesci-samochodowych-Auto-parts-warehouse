/**@file Plik nag³ówkowy zawieraj¹cy deklaracje klas.*/
#ifndef KLASY_H
#define KLASY_H
#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <iomanip>
#include <windows.h>
#undef max

using namespace std;
/**@brief 
* Klasa abstrakcyjna zawieraj¹ca wirtualne metody odpowiedziale za dodawianie, usuwanie i wyœwietlanie czêœci. 
*/
class Baza
{
public:
    virtual void dodaj() = 0;
    virtual void wyswietl() = 0;
    virtual void usun() = 0;
};
/**@brief
* Klasa zawieraj¹ca wspólne pola klas pochodnych s³u¿¹ce do opisu danej czêœci.
*/
class Czesc
{
public:
    string marka;
    string stan;
    string model;
    int cena;
    void dodaj_czesc();
    void usun_czesc(string do_usuniecia);
    void wyswietl_czesc(string nazwa);
};

/**@brief
* Klasa pochodna klas Baza oraz Czêœæ s³u¿aca do szczegó³owego opisu silnika samochodowego.
*/

class Silnik : public Baza, Czesc
{
    int moc;
    int pojemnosc;
    string typ;
public:
    virtual void dodaj();
    virtual void usun();
    virtual void wyswietl();
};

/**@brief
* Klasa pochodna klas Baza oraz Czêœæ s³u¿aca do szczegó³owego opisu skrzyni biegów.
*/

class Skrzynia : public Baza, Czesc
{
    int l_biegow;
    string rodzaj;
public:
    virtual void dodaj();
    virtual void usun();
    virtual void wyswietl();
};

/**@brief
* Klasa pochodna klas Baza oraz Czêœæ s³u¿aca do szczegó³owego opisu karosierii samochodowej.
*/

class Karoseria : public Baza, Czesc
{
    string kolor;
    string typ;
public:
    virtual void dodaj();
    virtual void usun();
    virtual void wyswietl();
};

/**@brief
* Klasa pochodna klas Baza oraz Czêœæ s³u¿aca do szczegó³owego opisu opon.
*/

class Opony :public Baza, Czesc
{
    string rodzaj;
    int profil;
    int szerokosc;
public:
    virtual void dodaj();
    virtual void usun();
    virtual void wyswietl();
};

/**@brief
* Klasa pochodna klas Baza oraz Czêœæ s³u¿aca do szczegó³owego opisu innego rodzaju czêœci.
*/

class Inne : public Baza, Czesc
{
    string nazwa;
public:
    virtual void dodaj();
    virtual void usun();
    virtual void wyswietl();
};

/**@brief
* Klasa odpowiedzialna za wyswietlanie kontekstowego menu g³ówbnego programu oraz przechodzenie do kolejnych ekranów programu.
*/

class Menu
{
    string wybor;
public:
    void wyswietl_menu();
    void wybierz_menu();
};

/**@brief
* Klasa odpowiedzialna za wyswietlanie kontekstowego menu magazynu oraz przechodzenie do innych ekranów programu.
*/

class Magazyn
{
    string wybor_czesci;
    string wybor_opcji;
public:
    void wyswietl_czesci();
    void wybierz_czesc();
    void wyswietl_opcje();
    void funkcja(Baza* x);
    void wybierz_opcje();
};

/**@brief
* Klasa odpowiedzialna za wyswietlanie kontekstowego menu wydruku stanu magazynu oraz przechodzenie do inneych ekranów programu.
*/

class Wydruk
{
    string wybor;
public:
    int zlicz(string nazwa);
    void wyswietl_stan();
    void wybierz_stan();
    void wygeneruj();
};

/**@brief
* Klasa odpowiedzialna za wyswietlanie kontekstowego menu pomocy oraz powrót do menu g³ównego.
*/

class Pomoc
{
    string wybor;
public:
    void wyswietl_pomoc();
};
#endif

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

class Baza
{
public:
    virtual void dodaj() = 0;
    virtual void wyswietl() = 0;
    virtual void usun() = 0;
};

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

class Skrzynia : public Baza, Czesc
{
    int l_biegow;
    string rodzaj;
public:
    virtual void dodaj();
    virtual void usun();
    virtual void wyswietl();
};

class Karoseria : public Baza, Czesc
{
    string kolor;
    string typ;
public:
    virtual void dodaj();
    virtual void usun();
    virtual void wyswietl();
};

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

class Inne : public Baza, Czesc
{
    string nazwa;
public:
    virtual void dodaj();
    virtual void usun();
    virtual void wyswietl();
};

class Menu
{
    int wybor;
public:
    void wyswietl_menu();
    void wybierz_menu();
};

class Magazyn
{
    int wybor_czesci;
    int wybor_opcji;
public:
    void wyswietl_czesci();
    void wybierz_czesc();
    void wyswietl_opcje();
    void funkcja(Baza* x);
    void wybierz_opcje();
};

class Wydruk
{
    int wybor;
public:
    int zlicz(string nazwa);
    void wyswietl_stan();
    void wybierz_stan();
    void wygeneruj();
};

class Pomoc
{
    char wybor;
public:
    void wyswietl_pomoc();
};
#endif

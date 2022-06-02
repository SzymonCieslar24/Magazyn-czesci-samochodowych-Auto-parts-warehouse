#include "klasy.h"

void Czesc::dodaj_czesc()
{
    cin.ignore(numeric_limits < streamsize >::max(), '\n');
    cout << "Podaj marke samochodu" << endl;
    getline(cin, marka);
    cout << "Podaj model samochoodu" << endl;
    getline(cin, model);
    cout << "Podaj stan techniczny czesci" << endl;
    cin >> stan;
    cout << "Podaj cene czesci" << endl;
    cin >> cena;
}
void Czesc::usun_czesc(string do_usuniecia)
{
    ifstream wejsciowy("magazyn.txt");
    if (wejsciowy)
    {
        string wiersz;
        string tmp = "";
        bool czy_znaleziono = false;
        do
        {
            getline(wejsciowy, wiersz);
            if (wiersz == do_usuniecia && czy_znaleziono == false)
            {
                czy_znaleziono = true;
            }
            else
            {
                tmp += wiersz;
                tmp += "\n";
            }
        } while (not wejsciowy.eof());
        wejsciowy.close();
        ofstream wyjsciowy("magazyn.txt");
        wyjsciowy << tmp;
        if (czy_znaleziono)
        {
            cout << "Pomyslnie usunieto wybrana czesc";
        }
        else
        {
            cout << "Nie znaleaiono podanej czesci";
        }
        wyjsciowy.close();
    }
    else
    {
        cout << "Blad pliku!" << endl;
        wejsciowy.close();
    }
}
void Czesc::wyswietl_czesc(string nazwa)
{
    ifstream wejsciowy("magazyn.txt");
    if (wejsciowy)
    {
        string wiersz;
        bool czy_znaleziono = false;
        do
        {
            getline(wejsciowy, wiersz);
            if (wiersz.find(nazwa) == 0)
            {
                cout << wiersz << endl;
                czy_znaleziono = true;
            }
        } while (not wejsciowy.eof());
        if (czy_znaleziono == false)
            cout << "Aktualnie na magazynie nie ma zadnej czesci z wybranej kategorii." << endl;
    }
    else
    {
        cout << "Blad pliku!" << endl;
    }
    wejsciowy.close();
}

void Silnik::dodaj()
{
    ofstream wyjsciowy("magazyn.txt", ios::app);
    Czesc::dodaj_czesc();
    cout << "Podaj moc silnika" << endl;
    cin >> moc;
    cout << "Podaj pojemonsc silnika" << endl;
    cin >> pojemnosc;
    cout << "Podaj typ silnika" << endl;
    cin >> typ;
    wyjsciowy << "Silnik | " << marka << " | " << model << " | " << stan << " | " << typ << " | " << pojemnosc << " | " << moc << " | " << cena << endl;
    wyjsciowy.close();
    cout << "Pomyslnie dodano czesc" << endl;
}
void Silnik::usun()
{
    string do_usuniecia;
    Czesc::dodaj_czesc();
    cout << "Podaj moc silnika" << endl;
    cin >> moc;
    cout << "Podaj pojemonsc silnika" << endl;
    cin >> pojemnosc;
    cout << "Podaj typ silnika" << endl;
    cin >> typ;
    do_usuniecia = "Silnik | " + marka + " | " + model + " | " + stan + " | " + typ + " | " + to_string(pojemnosc) + " | " + to_string(moc) + " | " + to_string(cena);
    Czesc::usun_czesc(do_usuniecia);
}
void Silnik::wyswietl()
{
    cout << "Kategoria | Marka | Model | Stan techniczny | Typ | Pojemnosc | Moc | Cena " << endl;
    Czesc::wyswietl_czesc("Silnik");
}

void Skrzynia::dodaj()
{
    ofstream wyjsciowy("magazyn.txt", ios::app);
    Czesc::dodaj_czesc();
    cout << "Podaj ilosc przelozen w skrzyni biegow:" << endl;
    cin >> l_biegow;
    cout << "Podaj rodzaj skrzyni biegow:" << endl;
    cin >> rodzaj;
    wyjsciowy << "Skrzynia biegow | " << marka << " | " << model << " | " << stan << " | " << l_biegow << " | " << rodzaj << " | " << cena << endl;
    wyjsciowy.close();
    cout << "Pomyslnie dodano czesc" << endl;
}
void Skrzynia::usun()
{
    string do_usuniecia;
    Czesc::dodaj_czesc();
    cout << "Podaj ilosc przelozen w skrzyni biegow:" << endl;
    cin >> l_biegow;
    cout << "Podaj rodzaj skrzyni biegow:" << endl;
    cin >> rodzaj;
    do_usuniecia = "Skrzynia biegow | " + marka + " | " + model + " | " + stan + " | " + to_string(l_biegow) + " | " + rodzaj + " | " + to_string(cena);
    Czesc::usun_czesc(do_usuniecia);
}
void Skrzynia::wyswietl()
{
    cout << "Kategoria | Marka | Model | Stan techniczny | Ilosc biegow | Rodzaj | Cena " << endl;
    Czesc::wyswietl_czesc("Skrzynia biegow");
}

void Karoseria::dodaj()
{
    ofstream wyjsciowy("magazyn.txt", ios::app);
    Czesc::dodaj_czesc();
    cout << "Podaj rodzaj karoserii:" << endl;
    cin.ignore(numeric_limits < streamsize >::max(), '\n');
    getline(cin, typ);
    cout << "Podaj kolor elementu:" << endl;
    cin >> kolor;
    wyjsciowy << "Karoseria | " << marka << " | " << model << " | " << stan << " | " << typ << " | " << kolor << " | " << cena << endl;
    wyjsciowy.close();
    cout << "Pomyslnie dodano czesc" << endl;
}
void Karoseria::usun()
{
    string do_usuniecia;
    Czesc::dodaj_czesc();
    cout << "Podaj rodzaj karoserii:" << endl;
    cin.ignore(numeric_limits < streamsize >::max(), '\n');
    getline(cin, typ);
    cout << "Podaj kolor elementu:" << endl;
    cin >> kolor;
    do_usuniecia = "Karoseria | " + marka + " | " + model + " | " + stan + " | " + typ + " | " + kolor + " | " + to_string(cena);
    Czesc::usun_czesc(do_usuniecia);
}
void Karoseria::wyswietl()
{
    cout << "Kategoria | Marka | Model | Stan techniczny | Typ karoserii | Kolor | Cena " << endl;
    Czesc::wyswietl_czesc("Karoseria");
}

void Opony::dodaj()
{
    ofstream wyjsciowy("magazyn.txt", ios::app);
    Czesc::dodaj_czesc();
    cout << "Podaj rodzaj opony:" << endl;
    cin >> rodzaj;
    cout << "Podaj szerokosc opony:" << endl;
    cin >> szerokosc;
    cout << "Podaj profil opony:" << endl;
    cin >> profil;
    wyjsciowy << "Opona | " << marka << " | " << model << " | " << stan << " | " << rodzaj << " | " << szerokosc << " | " << profil << " | " << cena << endl;
    wyjsciowy.close();
    cout << "Pomyslnie dodano czesc" << endl;
}
void Opony::usun()
{
    string do_usuniecia;
    Czesc::dodaj_czesc();
    cout << "Podaj rodzaj opony:" << endl;
    cin >> rodzaj;
    cout << "Podaj szerokosc opony:" << endl;
    cin >> szerokosc;
    cout << "Podaj profil opony:" << endl;
    cin >> profil;
    do_usuniecia = "Opona | " + marka + " | " + model + " | " + stan + " | " + rodzaj + " | " + to_string(szerokosc) + " | " + to_string(profil) + " | " + to_string(cena);
    Czesc::usun_czesc(do_usuniecia);
}
void Opony::wyswietl()
{
    cout << "Kategoria | Marka | Model | Stan techniczny | Rodzaj | Szerokosc | Profil | Cena " << endl;
    Czesc::wyswietl_czesc("Opona");
}

void Inne::dodaj()
{
    ofstream wyjsciowy("magazyn.txt", ios::app);
    cout << "Podaj nazwe czesci" << endl;
    cin >> nazwa;
    Czesc::dodaj_czesc();
    wyjsciowy << "Inne | " << nazwa << " | " << marka << " | " << model << " | " << stan << " | " << cena << endl;
    wyjsciowy.close();
}
void Inne::usun()
{
    string do_usuniecia;
    cout << "Podaj nazwe czesci" << endl;
    cin >> nazwa;
    Czesc::dodaj_czesc();
    do_usuniecia = "Inne | " + nazwa + " | " + marka + " | " + model + " | " + stan + " | " + to_string(cena);
    Czesc::usun_czesc(do_usuniecia);
}
void Inne::wyswietl()
{
    cout << "Katergoria | Nazwa | Marka | Model | Stan techniczny | Cena " << endl;
    Czesc::wyswietl_czesc("Inne");
}

void Magazyn::wyswietl_czesci()
{
    cout << "W naszym magazynie znajdziesz nastepujce czesci samochodowe:" << endl
        << "1. Silniki" << endl
        << "2. Skrzynie biegow" << endl
        << "3. Karoserie" << endl
        << "4. Opony" << endl
        << "5. Inne" << endl
        << "Wybierz, ktora czesc cie interesuje i wprowadz odpowiadajaca jej pozycji cyfre: " << endl;
    cin >> wybor_czesci;
    wybierz_czesc();
}

void Magazyn::wybierz_czesc()
{
    if (wybor_czesci >= 1 && wybor_czesci <= 5)
        wyswietl_opcje();
    else
    {
        cout << "Blad wprowadzenia. Podaj dostepna do wyboru cyfre." << endl;
        cin >> wybor_czesci;
        wybierz_czesc();
    }
}

void Magazyn::wyswietl_opcje()
{
    cout << "Wybierz co chcesz wykonac" << endl
        << "1. Dodaj czesc" << endl
        << "2. Usun czesc" << endl
        << "3. Zobacz poszczegolne czesci" << endl
        << "4. Powrot do menu glownego" << endl;
    cin >> wybor_opcji;
    wybierz_opcje();
}
void Magazyn::funkcja(Baza* x)
{
    if (wybor_opcji == 1)
    {
        x->dodaj();
        Sleep(500);
        system("CLS");
        wyswietl_czesci();
    }
    if (wybor_opcji == 2)
    {
        x->usun();
    }
    if (wybor_opcji == 3)
    {
        system("CLS");
        char tmp;
        x->wyswietl();
        cout << "Aby wrocic do poprzedniego ekranu nacisnij dowolny przycisk." << endl;
        cin >> tmp;
        system("CLS");
        wyswietl_czesci();
    }
}
void Magazyn::wybierz_opcje()
{
    if (wybor_opcji == 1 || wybor_opcji == 2 || wybor_opcji == 3)
    {
        switch (wybor_czesci)
        {
        case 1:
        {
            Silnik s;
            Baza* wsk = &s;
            funkcja(wsk);
            break;
        }
        case 2:
        {
            Skrzynia sb;
            Baza* wsk = &sb;
            funkcja(wsk);
            break;
        }
        case 3:
        {
            Karoseria k;
            Baza* wsk = &k;
            funkcja(wsk);
            break;
        }
        case 4:
        {
            Opony o;
            Baza* wsk = &o;
            funkcja(wsk);
            break;
        }
        case 5:
        {
            Inne i;
            Baza* wsk = &i;
            funkcja(wsk);
            break;
        }
        }
    }
    else if (wybor_opcji == 4)
    {
        system("CLS");
        Menu menu{};
        menu.wyswietl_menu();
    }
    else
    {
        cout << "Blad wprowadzania. Podaj dostepna do wyboru cyfre." << endl;
        cin >> wybor_opcji;
        wybierz_opcje();
    }
}

int Wydruk::zlicz(string nazwa)
{
    int licznik = 0;
    ifstream wejsciowy("magazyn.txt");
    if (wejsciowy)
    {
        string wiersz;
        do
        {
            getline(wejsciowy, wiersz);
            if (wiersz.find(nazwa) == 0)
                licznik += 1;
        } while (not wejsciowy.eof());
    }
    else
    {
        cout << "Blad pliku!" << endl;
    }
    return licznik;
}
void Wydruk::wyswietl_stan()
{
    cout << "-=-=-=-=-=-=-=STAN MAGAZYNU=-=-=-=-=-=-=-" << endl;
    cout << "Kategoria czesci    Ilosc sztuk na stanie" << endl;
    cout << "Silnik:          " << setw(24) << zlicz("Silnik") << endl;
    cout << "Skrzynia biegow: " << setw(24) << zlicz("Skrzynia biegow") << endl;
    cout << "Karoseria:       " << setw(24) << zlicz("Karoseria") << endl;
    cout << "Opony:           " << setw(24) << zlicz("Opona") << endl;
    cout << "Inne:            " << setw(24) << zlicz("Inne") << endl;
    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
    cout << "Wybierz co chcesz zrobic:" << endl;
    cout << "1. Wygeneruj wydruk stanu magazynu." << endl;
    cout << "2. Wroc do menu glownego." << endl;
    cin >> wybor;
    wybierz_stan();
}
void Wydruk::wybierz_stan()
{
    switch (wybor)
    {
    case 1:
    {
        char tmp;
        system("CLS");
        wygeneruj();
        cout << "Aby powrocic do menu glownego nacisnij dowolny przycisk" << endl;
        cin >> tmp;
        system("CLS");
        Menu m{};
        m.wyswietl_menu();
        break;
    }
    case 2:
    {
        system("CLS");
        Menu m{};
        m.wyswietl_menu();
        break;
    }
    default:
    {
        cout << "Blad wprowadzenia. Podaj dostepna do wyboru cyfre." << endl;
        cin >> wybor;
        wybierz_stan();
        break;
    }
    }
}
void Wydruk::wygeneruj()
{
    ofstream wyjsciowy("stan.txt");
    wyjsciowy << "-=-=-=-=-=-=-=STAN MAGAZYNU=-=-=-=-=-=-=-" << endl;
    wyjsciowy << "Kategoria czesci    Ilosc sztuk na stanie" << endl;
    wyjsciowy << "Silnik:          " << setw(24) << zlicz("Silnik") << endl;
    wyjsciowy << "Skrzynia biegow: " << setw(24) << zlicz("Skrzynia biegow") << endl;
    wyjsciowy << "Karoseria:       " << setw(24) << zlicz("Karoseria") << endl;
    wyjsciowy << "Opony:           " << setw(24) << zlicz("Opony") << endl;
    wyjsciowy << "Inne:            " << setw(24) << zlicz("Inne") << endl;
    wyjsciowy << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
    wyjsciowy.close();
    cout << "Pomyslnie zapisano stan magazynu" << endl;
}

void Pomoc::wyswietl_pomoc()
{
    cout << "Program sluzy do symulacji magazynu czesci samochodowych." << endl;
    cout << "Pozwala na edycje stanu magazynu i wydruk stanu magazynu." << endl;
    cout << "Postepuj zgodnie z instrukcjami wyswietlajacymi sie na ekranie." << endl;
    cout << "Stan magazynu zapisuje sie automatycznie po jego edycji." << endl;
    cout << endl;
    cout << "Aby powrocic do menu glownego nacisnij dowony przycisk" << endl;
    cin >> wybor;
    system("CLS");
    Menu m{};
    m.wyswietl_menu();
}

void Menu::wyswietl_menu()
{
    cout << "Witaj w programie sluzacym do zazadzania magazynem czesci samochodowych. \nDostepne opcje:" << endl
        << "1. Wejdz do magazynu." << endl
        << "2. Wydruk stanu magazynu." << endl
        << "3. Pomoc." << endl
        << "4. Wyjdz." << endl
        << "Wybierz co chcesz zrobic wybierajac i wpisujac cyfre reprezentujaca dana pozycje." << endl;
    cin >> wybor;
    wybierz_menu();
}

void Menu::wybierz_menu()
{
    switch (wybor)
    {
    case 1:
    {
        system("CLS");
        Magazyn m{};
        m.wyswietl_czesci();
        break;
    }
    case 2:
    {
        system("CLS");
        Wydruk w{};
        w.wyswietl_stan();
        break;
    }
    case 3:
    {
        system("CLS");
        Pomoc p{};
        p.wyswietl_pomoc();
        break;
    }
    case 4:
        exit(0);
    default:
    {
        cout << "Blad wprowadzenia. Podaj dostepna do wyboru cyfre." << endl;
        cin >> wybor;
        wybierz_menu();
        break;
    }
    }
}
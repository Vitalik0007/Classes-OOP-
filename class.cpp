#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Produkt
{
protected:
    string nazwa;
    int cena;
public:
    Produkt(string naz, int c) : nazwa(naz), cena(c) {}
    virtual ostream& print(ostream& os)
    {
        return os << "Nazwa: " << nazwa << ", cena: " << cena;
    }
    friend ostream& operator<<(ostream &os, Produkt& p)
    {
        return p.print(os);
    }
};

class Spozywczy : public Produkt
{
private:
    string termin_waznosci;
public:
    Spozywczy(string naz = "", int c = 0, string termin = "") : Produkt(naz, c), termin_waznosci(termin) {}
    ostream& print(ostream& os)
    {
        return os << "Nazwa: " << nazwa << ", cena: " << cena << ", termin: " << termin_waznosci;
    }
};

class Chemiczny : public Produkt
{
private:
    string srodki_ostroznosci;
public:
    Chemiczny(string naz = "", int c = 0, string ostr = "") : Produkt(naz, c), srodki_ostroznosci(ostr) {}
    ostream& print(ostream& os)
    {
        return os << "Nazwa: " << nazwa << ", cena: " << cena << ", srodki ostroznosci: " << srodki_ostroznosci;
    }
};

class Nabial : public Produkt
{
private:
    string zawartosc_tluszczu;
public:
    Nabial(string naz = "", int c = 0, string zawartosc = "") : Produkt(naz, c), zawartosc_tluszczu(zawartosc) {}
    ostream& print(ostream& os)
    {
        return os << "Nazwa: " << nazwa << ", cena: " << cena << ", zawartosc tluszczu: " << zawartosc_tluszczu;
    }
};

class Koszyk
{
    vector<Produkt*> kosz;
public:
    ~Koszyk() { kosz.clear(); }
    void operator+=(Produkt& p){
        kosz.push_back(&p);
    }
    void usun()
    {
        kosz.clear();
    }
    friend ostream& operator<<(ostream& os, Koszyk& p)
    {
        for(int i=0; i<p.kosz.size(); i++) os << *p.kosz[i] << endl;
        return os;
    }
};

int main()
{
    Koszyk k;
    Spozywczy t1("chleb", 13, "34.34.3444");
    Chemiczny t2("Mydlo", 5, "Prosze zachowac ostroznosc!!!");
    Nabial t3("Mleko", 2, "5%");
    k+=t1;
    k+=t2;
    k+=t3;
    cout << k;
    k.usun();

    return 0;
}

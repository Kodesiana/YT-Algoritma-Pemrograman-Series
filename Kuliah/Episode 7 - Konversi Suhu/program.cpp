#include <iostream>
#include <conio.h>

using namespace std;

enum class Suhu {
    Kelvin,
    Celcius,
    Reamur,
    Fahrenheit
};

double ke_kelvin(Suhu satuan_awal, double nilai)
{
    switch (satuan_awal)
    {
    case Suhu::Kelvin:
        return nilai;
    
    case Suhu::Celcius:
        return nilai + 273.15;

    case Suhu::Reamur:
        return nilai * 5 / 9;

    case Suhu::Fahrenheit:
        return (nilai + 465.67) * 5 / 9;
    
    default:
        return nilai;
    }
}

double konversi(Suhu satuan_awal, Suhu satuan_tujuan, double nilai)
{
    double suhuKelvin = ke_kelvin(satuan_awal, nilai);
    switch (satuan_tujuan)
    {
    case Suhu::Kelvin:
        return suhuKelvin;
    
    case Suhu::Celcius:
        return suhuKelvin - 273.15;

    case Suhu::Reamur:
        return suhuKelvin * 9 / 5;

    case Suhu::Fahrenheit:
        return (suhuKelvin * 9 / 5) - 459.67;
    
    default:
        return nilai;
    }
}

int main()
{
    cout << "PROGRAM KONVERSI SUHU\n\n"
         << "1. Kelvin\n"
         << "2. Celcius\n"
         << "3. Reamur\n"
         << "4. Fahrenheit\n\n";
    
    int pilihanDari = 0, pilihanKe = 0;
    double suhu = 0;

    cout << "Input suhu: ";
    cin >> suhu;

    cout << "Konversi dari: ";
    cin >> pilihanDari;

    cout << "Konversi ke: ";
    cin >> pilihanKe;

    double hasil = konversi(static_cast<Suhu>(pilihanDari - 1), static_cast<Suhu>(pilihanKe - 1), suhu);
    cout << "\nHasil konversi: " << hasil;

    getch();
    return 0;
}
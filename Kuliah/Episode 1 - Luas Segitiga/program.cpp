// import header
#include <iostream>
#include <fstream>
#include <conio.h>

using namespace std;

// program utama
int main()
{
    // deklarasi variabel
    int alas = 0;
    int tinggi = 0;

    // buka input
    ifstream file_input;
    file_input.open("input.txt");

    // baca input
    char buffer[10];
    file_input.getline(buffer, 10); // Alas
    file_input.getline(buffer, 10); // angka
    alas = atof(buffer);

    file_input.getline(buffer, 10); // Tinggi
    file_input.getline(buffer, 10); // angka
    tinggi = atof(buffer);

    file_input.close();

    // proses
    float luas = 0.5 * alas * tinggi;

    // cetak ke file
    ofstream file_output;
    file_output.open("output.txt");

    file_output << "Luas: " << luas;

    file_output.close();

    // tampilkan informasi selesai
    cout << "Program selesai.";
    getch();
    
    return 0;
}
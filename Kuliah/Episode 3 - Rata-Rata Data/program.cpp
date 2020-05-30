#include <iostream>
#include <fstream>
#include <conio.h>

using namespace std;

int main()
{
    const int n = 20;
    int data_input[n] = {0};
    int jumlah = 0;
    float rerata = 0;

    ifstream file_input;
    file_input.open("input.txt");

    // input
    for (int i = 0; i < n; i++)
    {
        char buffer[10];
        file_input.getline(buffer, 10);
        data_input[i] = atof(buffer);
    }

    file_input.close();

    // proses
    for (int i = 0; i < n; i++)
    {
        jumlah = jumlah + data_input[i];
    }
    rerata = (float) jumlah / n;
    
    // output
    ofstream file_output;
    file_output.open("output.txt");
    file_output << "Rerata: " << rerata;
    file_output.close();

    cout << "Program selesai.";
    getch();

    return 0;
}
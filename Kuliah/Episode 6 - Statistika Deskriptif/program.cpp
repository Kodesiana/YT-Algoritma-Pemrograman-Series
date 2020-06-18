#include <iostream>
#include <fstream>
#include <limits>
#include <conio.h>

using namespace std;

void bubble_sort(double* arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] < arr[j + 1]) continue;
            int temp = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = temp;
        }
    }
}

double cari_modus(double* arr, int n)
{
    int count = 1;
    double modus = arr[0];
    double temp = 0, tempCount = 0;
    for (int i = 0; i < n - 1; i++)
    {
        temp = arr[i];
        tempCount = 0;
        for (int j = 0; j < n; j++)
        {
            if (temp == arr[j]) tempCount++;
        }
        
        if (tempCount > count)
        {
            modus = temp;
            count = tempCount;
        }
    }
    
    return modus;
}

double cari_median(double *arr, int n)
{
    if (n % 2 == 0)
    {
        return (arr[n / 2] + arr[(n - 1) / 2]) / 2;
    }
    else
    {
        return arr[(n - 1) / 2];
    }
}

int main()
{
    const int n = 10;
    double data_input[n];
    double jumlah = 0;
    double terendah = numeric_limits<double>::max();
    double tertinggi = numeric_limits<double>::lowest();
    double mean = 0, median = 0, modus = 0;

    // input
    ifstream file_input;
    file_input.open("input.txt");
    for (int i = 0; i < n; i++)
    {
        char buffer[10];
        file_input.getline(buffer, 10);
        data_input[i] = atof(buffer);
    }

    file_input.close();

    // proses
    bubble_sort(data_input, n);
    for (int i = 0; i < n; i++)
    {
        int data_sekarang = data_input[i];

        jumlah += data_sekarang;
        if (data_sekarang < terendah) terendah = data_sekarang;
        if (data_sekarang > tertinggi) tertinggi = data_sekarang;
    }

    mean = jumlah / n;
    median = cari_median(data_input, n);
    modus = cari_modus(data_input, n);

    // output
    ofstream file_output;
    file_output.open("output.txt");

    file_output << "Data diurutkan: ";
    for (int i = 0; i < n; i++)
    {
        file_output << data_input[i] << " ";
    }
    
    file_output << "\n";
    file_output << "Jumlah: " << jumlah << "\n";
    file_output << "Mean: " << mean << "\n";
    file_output << "Median: " << median << "\n";
    file_output << "Modus: " << modus << "\n";
    file_output << "Terbesar: " << tertinggi << "\n";
    file_output << "Terkecil: " << terendah << "\n";

    file_output.close();

    cout << "Program selesai.";
    getch();
    return 0;
}
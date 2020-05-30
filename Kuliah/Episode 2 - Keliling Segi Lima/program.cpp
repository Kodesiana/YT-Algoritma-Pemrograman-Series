#include <iostream>
#include <fstream>
#include <conio.h>

using namespace std;

int main()
{
    int sisi1 = 0;
    int sisi2 = 0;
    int sisi3 = 0;
    int sisi4 = 0;
    int sisi5 = 0;

    ifstream file_input;
    file_input.open("input.txt");

    char buffer[10];
    file_input.getline(buffer, 10);
    sisi1 = atof(buffer);
    file_input.getline(buffer, 10);
    sisi2 = atof(buffer);
    file_input.getline(buffer, 10);
    sisi3 = atof(buffer);
    file_input.getline(buffer, 10);
    sisi4 = atof(buffer);
    file_input.getline(buffer, 10);
    sisi5 = atof(buffer);

    file_input.close();

    int keliling = sisi1 + sisi2 + sisi3 + sisi4 + sisi5;

    ofstream file_output;
    file_output.open("output.txt");
    file_output << "Keliling: " << keliling;
    file_output.close();

    cout << "Program selesai.";
    getch();

    return 0;
}
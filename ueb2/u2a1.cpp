// Übungsblatt 2
// Aufgabe 1
// Stephan Aures

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <math.h>

using namespace std;

unsigned int PC = 0;
unsigned int PS[100];
unsigned int DS[100];

void _add(int a)
{
    PC++;
    DS[0] += DS[a];
}

void _mul(int a)
{
    PC++;
    DS[0] *= DS[a];
}

void _lda(int a)
{
    PC++;
    DS[0] = DS[a];
}

void _ldk(int a)
{
    PC++;
    DS[0] = a;
}

void _sta(int a)
{
    PC++;
    DS[a] = DS[0];
}

void _out(int a)
{
    PC++;
    cout << "Ausgabe: " << DS[a] << endl;
}

int main()
{
    ifstream file01;
    file01.open("input.txt", ios::in);
    if (!file01)
    {
        cerr << "Fehler beim Lesen der Datei" << endl;
        return 1;
    }
    
    string line;
    int i = 1;

    while(getline(file01, line))
    {
        stringstream   linestream(line);
        string         value;

        while(getline(linestream,value,','))
        {
            int v = std::stoi(value, 0, 16);

            PS[i] = v;
            i++;
        }

        for (size_t i = 1; i < (sizeof(PS)/sizeof(*PS)); i+=2)
        {
            if((PS[i] == 10 && PS[i+1] == 153)) // 0x153 == 99
            {
                cout << "Programmende" << endl;
                cout << "PC: " << PC << endl;
                return 0;
            }

            //cout << PS[i] << endl;

            if((i & 1) == 0)
            {
                //Konstante
            }    
            else
            {
                //Befehl
                switch (PS[i])
                    {
                    case 1:
                        _add(PS[i+1]);
                        break;

                    case 3:
                        _mul(PS[i+1]);
                        break;

                    case 5:
                        _lda(PS[i+1]);
                        break;

                    case 6:
                        _ldk(PS[i+1]);
                        break;

                    case 7:
                        _sta(PS[i+1]);
                        break;

                    case 9:
                        _out(PS[i+1]);
                        break;

                    default:
                        cerr << "Befehl konnte nicht dekodiert werden!" << endl;
                        return 1;
                    }
            }
        }
    }

    return 0;
}
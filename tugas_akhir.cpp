#include <iostream>
using namespace std;

struct Pemain {
    string nama;
    char simbol;
};

void gambarTable(char table[3][3]) {
    cout << "--------------\n";
    for (int i = 0; i < 3; i++) {
        cout << "| " << table[i][0] << " | " << table[i][1] << " | " << table[i][2] << " |\n";
        cout << "-------------\n";
    }
}


bool cekMenang(char table[3][3], char simbol) {
    for (int i = 0; i < 3; i++) {
        if (table[i][0] == simbol && table[i][1] == simbol && table[i][2] == simbol)
            return true;
        if (table[0][i] == simbol && table[1][i] == simbol && table[2][i] == simbol)
            return true;
    }
    if (table[0][0] == simbol && table[1][1] == simbol && table[2][2] == simbol)
        return true;
    if (table[0][2] == simbol && table[1][1] == simbol && table[2][0] == simbol)
        return true;
    return false;
}

bool cekSeri(char table[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (table[i][j] == ' ')
                return false;
        }
    }
    return true;
}

bool isValidInput(int baris, int kolom, char table[3][3]) {
    return (baris >= 0 && baris < 3 && kolom >= 0 && kolom < 3 && table[baris][kolom] == ' ');
}

void gantiPemain(Pemain *&pemainSekarang, Pemain &pemainX, Pemain &pemainO) {
    pemainSekarang = (pemainSekarang == &pemainX) ? &pemainO : &pemainX;
}

void resetTable(char table[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            table[i][j] = ' ';
        }
    }
}

int main() {
    char table[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};

    Pemain pemainX, pemainO;
    Pemain *pemainSekarang = &pemainX;
    pemainX.simbol = 'X';
    pemainO.simbol = 'O';

    pemainX.nama = "Pemain X";
    pemainO.nama = "Pemain O";

    char jawaban;

    do {
        gambarTable(table);

        cout << "Giliran " << pemainSekarang->nama << " (" << pemainSekarang->simbol << ")\n";

        int baris, kolom;
        do {
            cout << "Masukkan baris (0-2) dan kolom (0-2) yang ingin diisi (pisahkan dengan spasi): ";
            cin >> baris >> kolom;
        } while (!isValidInput(baris, kolom, table));

        table[baris][kolom] = pemainSekarang->simbol;

        if (cekMenang(table, pemainSekarang->simbol)) {
            gambarTable(table);
            cout << "Selamat! " << pemainSekarang->nama << " (" << pemainSekarang->simbol << ") menang!\n";
            cout << "TERIMA KASIH" << endl;
            break;
        }

        if (cekSeri(table)) {
            gambarTable(table);
            cout << "Permainan seri!\n";
            break;
        }

        gantiPemain(pemainSekarang, pemainX, pemainO);

    } while (true);

    cout << "Apakah Anda ingin bermain lagi? (y/n): ";
    cin >> jawaban;

    if (jawaban == '=[]y' || jawaban == 'Y') {
        resetTable(table);
        main();
    }

    return 0;
}


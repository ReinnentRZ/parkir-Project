#include <iostream>
#include <ctime>

using namespace std;

struct dataParkir {
    string platNomor;
    string jenisKendaraan;
    time_t waktuMasuk;
    time_t waktuKeluar;
    double tarif;
};

dataParkir parkiran[50];  
int jumlahKendaraan = 0;

void tambahKendaraan();
void cariKendaraan();
void tampilkanKendaraan();
void hapusKendaraan();
void menu();

int main() {
    menu();
    return 0;
}

void tambahKendaraan() {
    int jumlah;
    cout << "\nTambah Kendaraan\n";
    cout << "Masukkan Jumlah Kendaraan Baru: ";
    cin >> jumlah;
    cin.ignore();

    if (jumlahKendaraan + jumlah > 50) {
        cout << "Maaf, kapasitas parkir penuh!\n";
        return;
    }

    for (int i = 0; i < jumlah; i++) {
        cout << "\nKendaraan ke-" << (jumlahKendaraan + 1) << ":\n";

        cout << "Masukkan Plat Nomor: ";
        getline(cin, parkiran[jumlahKendaraan].platNomor);

        cout << "Masukkan Jenis Kendaraan: ";
        getline(cin, parkiran[jumlahKendaraan].jenisKendaraan);

        jumlahKendaraan++;
    }
}

void cariKendaraan() {
    string cariPlat;
    cout << "\nCari Kendaraan\n";
    cout << "Masukkan Plat Nomor: ";
    getline(cin, cariPlat);

    bool ditemukan = false;
    int i = 0;
    while (!ditemukan) {

        if (parkiran[i].platNomor == cariPlat) {

            cout << "Plat Nomor    : " << parkiran[i].platNomor << endl;
            cout << "Jenis         : " << parkiran[i].jenisKendaraan << endl;
            ditemukan = true;
            break;

        } else {

            i = i + 1;

        }

        if (!ditemukan) {
            cout << "Kendaraan tidak ditemukan.\n";
            break;
            menu();
        }

    }

}

void tampilkanKendaraan() {
    if (jumlahKendaraan == 0) {
        cout << "\nBelum ada kendaraan yang masuk.\n";
        return;
    }

    cout << "\nDaftar Kendaraan dalam Parkiran:\n";
    for (int i = 0; i < jumlahKendaraan; i++) {
        cout << "\nKendaraan ke-" << (i + 1) << ":\n";
        cout << "Plat Nomor    : " << parkiran[i].platNomor << endl;
        cout << "Jenis         : " << parkiran[i].jenisKendaraan << endl;
    }
}

void hapusKendaraan() {
    string hapusPlat;
    cout << "\nKeluarkan Kendaraan\n";
    cout << "Masukkan Plat Nomor: ";
    getline(cin, hapusPlat);

    bool ditemukan = false;
    for (int i = 0; i < jumlahKendaraan; i++) {
        if (parkiran[i].platNomor == hapusPlat) {
            cout << "\nKendaraan Keluar!\n";
            cout << "Plat Nomor    : " << parkiran[i].platNomor << endl;
            cout << "Jenis         : " << parkiran[i].jenisKendaraan << endl;
            
            for (int j = i; j < jumlahKendaraan - 1; j++) {
                parkiran[j] = parkiran[j + 1];
            }
            jumlahKendaraan--;
            ditemukan = true;
            break;
        }
    }

    if (!ditemukan) {
        cout << "Kendaraan tidak ditemukan.\n";
    }
}

void menu() {
    int menuPilihan;
    string ulang;
    
    do {
        cout << "\n===== MENU PARKIR =====\n";
        cout << "1. Tambah Kendaraan\n";
        cout << "2. Cari Kendaraan\n";
        cout << "3. Tampilkan Kendaraan\n";
        cout << "4. Keluarkan Kendaraan\n";
        cout << "5. Keluar\n";
        cout << "Pilih Menu: ";
        cin >> menuPilihan;
        cin.ignore();

        switch (menuPilihan) {
            case 1:
                tambahKendaraan();
                break;
            case 2:
                cariKendaraan();
                break;
            case 3:
                tampilkanKendaraan();
                break;
            case 4:
                hapusKendaraan();
                break;
            case 5:
                cout << "Keluar dari program.\n";
                return;
            default:
                cout << "Pilihan tidak valid.\n";
        }

        cout << "\nApakah Anda ingin kembali ke menu? (y/n): ";
        getline(cin, ulang);

    } while (ulang == "y" || ulang == "Y");
}

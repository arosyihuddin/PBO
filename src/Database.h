#ifndef DATABASE_H
#define DATABASE_H
#include <iostream>
#include <vector>
#include "Mahasiswa.h"
#include "Prodi.h"
#include "MataKuliah.h"
class Database
{
private:
    vector<Prodi> listProdi = {
        Prodi("TIF", "Teknik Informatika"),
        Prodi("TI", "Teknik Industri"),
        Prodi("TM", "Teknik Mesin"),
        Prodi("SI", "Sistem Informasi"),
    };

    vector<Mahasiswa> listMhs = {
        // Mahasiswa("Ahmad Rosyihuddin", "200411100126", "Gresik", 5, &listProdi[0]),
        // Mahasiswa("Ahmad Fanani", "200411100143", "Jombang", 5, &listProdi[1]),
        // Mahasiswa("Ari Andi Mustofa", "200411100112", "Bojonegoro", 5, &listProdi[2]),
    };

    vector<MataKuliah> listMatkul = {
        MataKuliah("IF200", "Pemrograman Berorientasi Objek", 3),
        MataKuliah("IF201", "Pemrograman Aplikasi WEB", 3),
        MataKuliah("IF201", "Basis Data", 3),
    };

public:
    Database(){};

    void displayMhs()
    {
        cout << "\n===================DATA MAHASISWA===================" << endl;
        int i = 1;
        for (Mahasiswa mhs : listMhs)
        {
            cout << i++ << ". NAMA\t\t: " << mhs.name << endl;
            cout << "   NIM\t\t: " << mhs.nim << endl;
            cout << "   ALAMAT\t: " << mhs.address << endl;
            cout << "   SEMESTER\t: " << mhs.semester << endl;
            cout << "   PRODI\t: " << mhs.prodi->name << endl;
            cout << "   MATAKULIAH\t: ";
            int i = 0;
            for (MataKuliah mk : mhs.khs->mataKuliah)
            {
                if (i == 0)
                {
                    cout << "- " << mk.name << endl;
                    i++;
                }
                else
                {
                    cout << "\t\t  - " << mk.name << endl;
                }
            }
            // cout << "   MATAKULIAH :" << mhs.display() << endl;

            cout << "====================================================" << endl;
        }
    }

    void displayMk()
    {
        cout << "\n==================DATA MATAKULIAH==================" << endl;
        int i = 1;
        for (MataKuliah mk : listMatkul)
        {
            cout << i++ << ". KODE\t: " << mk.code << endl;
            cout << "   NAMA\t: " << mk.name << endl;
            cout << "   SKS\t: " << mk.sks << endl;
            cout << "====================================================" << endl;
        }
    }

    void displayProdi()
    {
        cout << "\n=====================DATA PRODI=====================" << endl;
        int i = 1;
        for (Prodi pd : listProdi)
        {
            cout << i++ << ". KODE\t:" << pd.code << endl;
            cout << "   NAMA\t:" << pd.name << endl;
            cout << "====================================================" << endl;
        }
    }

    void tambahMhs()
    {
        string nama, nim, alamat;
        int semester, pd, mk;
        cout << "\n====================================================" << endl;
        cout << "INPUTKAN DATA MAHASISWA" << endl;
        cout << "====================================================\n";
        cout << "NAMA >> ";
        getline(cin >> ws, nama);
        cout << "NIM >> ";
        getline(cin >> ws, nim);
        cout << "ALAMAT >> ";
        getline(cin >> ws, alamat);
        cout << "SEMESTER >> ";
        cin >> semester;
        displayProdi();
        cout << "Pilih Nomor Prodi >> ";
        cin >> pd;
        Mahasiswa mhs = Mahasiswa(nama, nim, alamat, semester, &listProdi[pd - 1]);
        listMhs.push_back(mhs);
        bool addMk = true;
        int pilih = 0;
        while (addMk)
        {
            displayMk();
            cout << "Pilih Nomor Matakuliah >> ";
            cin >> mk;
            listMatkul[mk - 1].nilai = 0;
            mhs.setKhs(nama, listMatkul[mk - 1]);

            cout << "[1]Ya [2]Tidak" << endl;
            cout << "Tambah Matakuliah?? >> ";
            cin >> pilih;
            if (pilih == 2)
            {
                addMk = false;
            }
        }
    }

    void hapusMhs()
    {
        int i;
        cout << "Nomor Yang Akan Di Hapus >> ";
        cin >> i;
        listMhs.erase(listMhs.begin() + (i - 1));
        cout << "\n====================================================" << endl;
        cout << "DATA BERHASIL DI HAPUS" << endl;
        cout << "====================================================\n";
    }

    void tambahMk()
    {
        string nama, nim, alamat;
        int semester, pd, mk;
        cout << "\n====================================================" << endl;
        cout << "INPUTKAN DATA MAHASISWA" << endl;
        cout << "====================================================\n";
        cout << "NAMA >> ";
        getline(cin >> ws, nama);
        cout << "NIM >> ";
        getline(cin >> ws, nim);
        cout << "ALAMAT >> ";
        getline(cin >> ws, alamat);
        cout << "SEMESTER >> ";
        cin >> semester;
        displayProdi();
        cout << "Pilih Nomor Prodi >> ";
        cin >> pd;
        listMhs.push_back(Mahasiswa(nama, nim, alamat, semester, &listProdi[pd - 1]));
        cout << "Pilih Nomor Matakuliah >> ";
        cin >> mk;
    }

    void hapusMk()
    {
        int i;
        cout << "Nomor Yang Akan Di Hapus >> ";
        cin >> i;
        listMatkul.erase(listMatkul.begin() + (i - 1));
        cout << "\n====================================================" << endl;
        cout << "DATA BERHASIL DI HAPUS" << endl;
        cout << "====================================================\n";
    }
};
#endif
// import library
#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>
// standar namespace
using namespace std;

// deklarasi kelas mahasiswa
class Mahasiswa
{
    // private atribut
private:
    string NIM;
    string nama;
    string prodi;
    string fakultas;

public:
    // konstruktor
    Mahasiswa()
    {
        this->NIM = "";
        this->nama = "";
        this->prodi = "";
        this->fakultas = "";
    }

    Mahasiswa(string NIM, string nama, string prodi, string fakultas)
    {
        this->NIM = NIM;
        this->nama = nama;
        this->prodi = prodi;
        this->fakultas = fakultas;
    }

    // setter dan getter
    void setNIM(string NIM)
    {
        this->NIM = NIM;
    }

    void setNama(string nama)
    {
        this->nama = nama;
    }

    void setProdi(string prodi)
    {
        this->prodi = prodi;
    }

    void setFakultas(string fakultas)
    {
        this->fakultas = fakultas;
    }

    string getNIM()
    {
        return this->NIM;
    }

    string getNama()
    {
        return this->nama;
    }

    string getProdi()
    {
        return this->prodi;
    }

    string getFakultas()
    {
        return this->fakultas;
    }

    // destruktor
    ~Mahasiswa()
    {
    }
};

int main()
{
    list<Mahasiswa> llist; // linked list library
    int n = 0;             // variabel untuk pilih menu
    int i = 0;
    // atribut
    string NIM;
    string nama;
    string prodi;
    string fakultas;
    do
    {
        Mahasiswa temp; // tampungan
        // tampilan menu
        cout << "Masukan Perintah!" << endl;
        cout << "1. Tambah Mahasiswa" << endl;
        cout << "2. Ubah Mahasiswa" << endl;
        cout << "3. Hapus Mahasiswa" << endl;
        cout << "4. Tampilkan Daftar Mahasiswa" << endl;
        cout << "5. Keluar" << '\n'
             << endl;
        cin >> n;
        if (n == 1) // jika masukan == 1 maka tambah data mahasiswa
        {
            cout << "Masukan NIM" << endl;
            cin >> NIM;
            cout << "Masukan Nama" << endl;
            cin >> nama;
            cout << "Masukan Program Studi" << endl;
            cin >> prodi;
            cout << "Masukkan Fakultas" << endl;
            cin >> fakultas;

            temp.setNIM(NIM);
            temp.setNama(nama);
            temp.setProdi(prodi);
            temp.setFakultas(fakultas);

            llist.push_back(temp);
        }
        else if (n == 2) // jika masukan == 2 maka ubah/edit data
        {
            cout << "Masukkan NIM mahasiswa yang ingin diubah" << endl;
            cin >> NIM;
            bool found = false;
            for (list<Mahasiswa>::iterator it = llist.begin(); it != llist.end(); ++it)
            {
                if (it->getNIM() == NIM) // jika memasukan NIM sesuai maka dapat mengubah data
                {
                    found = true;
                    cout << "Masukkan NIM baru" << endl;
                    cin >> NIM;
                    cout << "Masukkan Nama baru" << endl;
                    cin >> nama;
                    cout << "Masukkan Program Studi baru" << endl;
                    cin >> prodi;
                    cout << "Masukkan Fakultas baru" << endl;
                    cin >> fakultas;
                    // set atribut baru
                    it->setNIM(NIM);
                    it->setNama(nama);
                    it->setProdi(prodi);
                    it->setFakultas(fakultas);
                }
            }
            if (!found) // jika NIM tidak ada yg sesuai
            {
                cout << "Mahasiswa dengan NIM " << NIM << " tidak ditemukan" << endl;
            }
        }
        else if (n == 3) // jika masukan == 3 maka hapus data mahasiswa
        {
            bool found = false;
            cout << "Masukkan NIM mahasiswa yang ingin dihapus" << endl;
            cin >> NIM;
            for (list<Mahasiswa>::iterator it = llist.begin(); it != llist.end(); ++it)
            {
                if (it->getNIM() == NIM) // jika NIM sesuai dengan yg ada di daftar maka akan melakukan proses hapus
                {
                    found = true;
                    cout << "Mahasiswa dengan NIM " << NIM << " berhasil dihapus" << endl;
                    llist.erase(it);
                    break;
                }
            }
            if (!found) // jika NIM tidak ada yg sesuai
            {
                cout << "Mahasiswa dengan NIM " << NIM << " tidak ditemukan" << endl;
            }
        }
        else if (n == 4) // jika masukan == 4 maka akan menampilkan daftar mahasiswa
        {

            // for (list<Mahasiswa>::iterator it = llist.begin(); it != llist.end(); it++)
            // {
            //     cout << (i + 1) << ". " << it->getNIM() << " | " << it->getNama() << " | " << it->getProdi() << " | " << it->getFakultas() << '\n';
            // }

            cout << "Daftar Mahasiswa:" << endl;
            cout << "NIM\tNama\tProdi\tFakultas" << endl;
            for (list<Mahasiswa>::iterator it = llist.begin(); it != llist.end(); it++)
            {
                cout << it->getNIM() << "\t" << it->getNama() << "\t" << it->getProdi() << "\t" << it->getFakultas() << endl;
            }
        }
        else if (n > 5) // jika masukan tidak sesuai dengan menu yg disediakan maka invalid
        {
            cout << "Perintah Tidak Valid!" << endl;
        }
    } while (n != 5); // menu exit, program akan berhenti
    cout << "Terima Kasih, Sampai jumpa kembali" << endl;
    return 0;
}
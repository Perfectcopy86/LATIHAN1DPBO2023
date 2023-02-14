//import library
import java.util.List;
import java.util.ArrayList;
import java.util.Scanner;

class Mahasiswa {
    //private atribut
    private String NIM;
    private String nama;
    private String prodi;
    private String fakultas;

    //konstruktor
    public Mahasiswa() {
        this.NIM = "";
        this.nama = "";
        this.prodi = "";
        this.fakultas = "";
    }

    public Mahasiswa(String NIM, String nama, String prodi, String fakultas) {
        this.NIM = NIM;
        this.nama = nama;
        this.prodi = prodi;
        this.fakultas = fakultas;
    }

    //setter dan getter
    public void setNIM(String NIM) {
        this.NIM = NIM;
    }

    public void setNama(String nama) {
        this.nama = nama;
    }

    public void setProdi(String prodi) {
        this.prodi = prodi;
    }

    public void setFakultas(String fakultas) {
        this.fakultas = fakultas;
    }

    public String getNIM() {
        return this.NIM;
    }

    public String getNama() {
        return this.nama;
    }

    public String getProdi() {
        return this.prodi;
    }

    public String getFakultas() {
        return this.fakultas;
    }
}

class Main {
    public static void main(String[] args) {
    List<Mahasiswa> llist = new ArrayList<Mahasiswa>();//membuat list
    int n = 0;
    //variabel atribut
    String NIM; 
    String nama;
    String prodi; 
    String fakultas;
        do {
        Mahasiswa temp = new Mahasiswa();
        //tampilan menu
        System.out.println("Masukan Perintah!");
        System.out.println("1. Tambah Mahasiswa");
        System.out.println("2. Ubah Mahasiswa");
        System.out.println("3. Hapus Mahasiswa");
        System.out.println("4. Tampilkan Daftar Mahasiswa");
        System.out.println("5. Keluar\n");
        //masukan
        Scanner input = new Scanner(System.in);
        n = input.nextInt();

        if (n == 1) // jika masukan == 1 maka tambah data mahasiswa 
        {
            System.out.println("Masukan NIM");
            NIM = input.next();
            System.out.println("Masukan Nama");
            nama = input.next();
            System.out.println("Masukan Program Studi");
            prodi = input.next();
            System.out.println("Masukkan Fakultas");
            fakultas = input.next();

            temp.setNIM(NIM);
            temp.setNama(nama);
            temp.setProdi(prodi);
            temp.setFakultas(fakultas);

            llist.add(temp);
        }else if (n == 2)// jika masukan == 2 maka ubah/edit data 
        {
            System.out.println("Masukkan NIM mahasiswa yang ingin diubah");
            NIM = input.next();
            boolean found = false;
            
            for (Mahasiswa mhs : llist) {
                if (mhs.getNIM().equals(NIM)) // jika memasukan NIM sesuai maka dapat mengubah data
                {
                    found = true;
                    System.out.println("Masukkan NIM baru");
                    NIM = input.next();
                    System.out.println("Masukkan Nama baru");
                    nama = input.next();
                    System.out.println("Masukkan Program Studi baru");
                    prodi = input.next();
                    System.out.println("Masukkan Fakultas baru");
                    fakultas = input.next();
                    //set atribut baru
                    mhs.setNIM(NIM);
                    mhs.setNama(nama);
                    mhs.setProdi(prodi);
                    mhs.setFakultas(fakultas);
                }
            }
            if (!found) // jika NIM tidak ada yg sesuai
            {
                System.out.println("Mahasiswa dengan NIM " + NIM + " tidak ditemukan");
            }
        }else if (n == 3) // jika masukan == 3 maka hapus data mahasiswa
        {
            boolean found = false;
            System.out.println("Masukkan NIM mahasiswa yang ingin dihapus");
            NIM = input.next();
            for(Mahasiswa mhs : llist)
            {
                if (mhs.getNIM().equals(NIM)) // jika NIM sesuai dengan yg ada di daftar maka akan melakukan proses hapus
                {
                    found = true;
                    System.out.println("Mahasiswa dengan NIM " + NIM + " berhasil dihapus");
                    llist.remove(mhs);
                    break;
                }
            }
            if (!found) // jika NIM tidak ada yg sesuai
            {
                System.out.println("Mahasiswa dengan NIM " + NIM + " tidak ditemukan");
            }
            
        }else if (n == 4) // jika masukan == 4 maka akan menampilkan daftar mahasiswa
        {
            System.out.println("Daftar Mahasiswa:");
            System.out.println("NIM\tNama\tProdi\tFakultas");
            for (Mahasiswa mhs : llist) {
                System.out.println(mhs.getNIM() + "\t" + mhs.getNama() + "\t" + mhs.getProdi() + "\t" + mhs.getFakultas());
            }
        }else if(n > 5) // jika masukan tidak sesuai dengan menu yg disediakan maka invalid
        {
            System.out.println("Perintah Tidak Valid"); 
        }
        
    } while (n != 5); // menu exit, program akan berhenti
    System.out.println("Terima Kasih, Sampai jumpa kembali");
    }
}
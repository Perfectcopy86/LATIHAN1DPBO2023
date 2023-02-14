class Mahasiswa:
    # private atribut
    __NIM = ""
    __nama = ""
    __prodi = ""
    __fakultas = ""

    # konstruktor
    def __init__(self, NIM="", nama="", prodi="", fakultas=""):
        self.__NIM = NIM
        self.__nama = nama
        self.__prodi = prodi
        self.__fakultas = fakultas

    # setter dan getter
    def setNIM(self, NIM):
        self.__NIM = NIM

    def setNama(self, nama):
        self.__nama = nama

    def setProdi(self, prodi):
        self.__prodi = prodi

    def setFakultas(self, fakultas):
        self.__fakultas = fakultas

    def getNIM(self):
        return self.__NIM

    def getNama(self):
        return self.__nama

    def getProdi(self):
        return self.__prodi

    def getFakultas(self):
        return self.__fakultas


class Main:
    llist = []  # list
    while True:
        # tampilan menu
        print("Masukan Perintah!")
        print("1. Tambah Mahasiswa")
        print("2. Ubah Mahasiswa")
        print("3. Hapus Mahasiswa")
        print("4. Tampilkan Daftar Mahasiswa")
        print("5. Keluar\n")
        n = int(input())

        if n == 1:  # tambah data mahasiswa
            NIM = input("Masukan NIM\n")
            nama = input("Masukan Nama\n")
            prodi = input("Masukan Program Studi\n")
            fakultas = input("Masukkan Fakultas\n")

            temp = Mahasiswa()
            temp.setNIM(NIM)
            temp.setNama(nama)
            temp.setProdi(prodi)
            temp.setFakultas(fakultas)

            llist.append(temp)

        elif n == 2:  # ubah data mahasiswa
            NIM = input("Masukkan NIM mahasiswa yang ingin diubah\n")
            found = False
            for i, data in enumerate(llist):
                if data.getNIM() == NIM:  # jika NIM sesuai maka dapat diubah
                    found = True
                    NIM = input("Masukkan NIM baru\n")
                    nama = input("Masukkan Nama baru\n")
                    prodi = input("Masukkan Program Studi baru\n")
                    fakultas = input("Masukkan Fakultas baru\n")
                    # set atribut baru
                    llist[i].setNIM(NIM)
                    llist[i].setNama(nama)
                    llist[i].setProdi(prodi)
                    llist[i].setFakultas(fakultas)
            if not found:
                print(f"Mahasiswa dengan NIM {NIM} tidak ditemukan")

        elif n == 3:  # hapus data mahasiswa
            found = False
            NIM = input("Masukkan NIM mahasiswa yang ingin dihapus\n")
            for i, data in enumerate(llist):
                if data.getNIM() == NIM:
                    found = True
                    print(f"Mahasiswa dengan NIM {NIM} berhasil dihapus")
                    llist.pop(i)
                    break
            if not found:
                print(f"Mahasiswa dengan NIM {NIM} tidak ditemukan")

        elif n == 4:  # Menampilkan daftar mahasiswa
            print("Daftar Mahasiswa:")
            print("NIM\tNama\tProdi\tFakultas")
            for i, data in enumerate(llist):
                print(
                    f"{data.getNIM()}\t{data.getNama()}\t{data.getProdi()}\t{data.getFakultas()}")

        elif n == 5:  # keluar dari program
            print("Terima Kasih, Sampai jumpa kembali")
            break

        else:  # perintah tidak valid dengan menu
            print("Perintah tidak valid")

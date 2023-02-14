<?php

class Mahasiswa {
    //private atribut
    private $NIM;
    private $nama;
    private $prodi;
    private $fakultas;
    
    //konstruktor
    public function __construct($NIM, $nama, $prodi, $fakultas) {
        $this->NIM = $NIM;
        $this->nama = $nama;
        $this->prodi = $prodi;
        $this->fakultas = $fakultas;
        
    }
    
    //setter dan getter
    public function getNama() {
        return $this->nama;
    }
    
    public function setNama($nama) {
        $this->nama = $nama;
    }
    
    public function getNIM() {
        return $this->NIM;
    }
    
    public function setNIM($NIM) {
        $this->NIM = $NIM;
    }
    
    public function getProdi() {
        return $this->prodi;
    }
    
    public function setProdi($prodi) {
        $this->prodi = $prodi;
    }
    
    public function getFakultas() {
        return $this->fakultas;
    }
    
    public function setFakultas($fakultas) {
        $this->fakultas = $fakultas;
    }
    
    public function getFotoProfil() {
        return $this->foto_profil;
    }
    

}

class DaftarMahasiswa {
    private $mahasiswa = array();
    //fungsi tambah data mahasiswa
    public function tambahMahasiswa($NIM, $nama,  $prodi, $fakultas) {
        $mahasiswa_baru = new Mahasiswa($NIM, $nama, $prodi, $fakultas);
        $this->mahasiswa[] = $mahasiswa_baru;
    }
    
    //fungsi ubah data mahasiswa
    public function ubahMahasiswa($NIM_lama, $NIM_baru, $nama_baru, $prodi_baru, $fakultas_baru) {
        foreach ($this->mahasiswa as $mahasiswa) {
            if ($mahasiswa->getNim() == $NIM_lama) //jika NIM sesuai dengan daftar maka dapat diubah
            {   
                //set atribut baru
                $mahasiswa->setNIM($NIM_baru);
                $mahasiswa->setNama($nama_baru);
                $mahasiswa->setProdi($prodi_baru);
                $mahasiswa->setFakultas($fakultas_baru);
                break;
            }
        }
    }
    
    //fungsi hapus data mahasiswa
    public function hapusMahasiswa($NIM) {
        foreach ($this->mahasiswa as $key => $mahasiswa) 
        {
            //jika NIM sesuai dengan daftar maka dapat dihapus
            if ($mahasiswa->getNIM() == $NIM) {
                unset($this->mahasiswa[$key]);
                break;
            }
        }
        $this->mahasiswa = array_values($this->mahasiswa);
    }
    
    //fungsi menampilkan daftar mahasiswa
    public function tampilDaftarMahasiswa() {
        foreach ($this->mahasiswa as $mahasiswa) {
            echo "NIM: " . $mahasiswa->getNim() . "<br>";
            echo "Nama: " . $mahasiswa->getNama() . "<br>";
            echo "Program Studi: " . $mahasiswa->getProdi() . "<br>";
            echo "Fakultas: " . $mahasiswa->getFakultas() . "<br>";
            echo "<br>";
            }
        }
}

//membuat variabel untuk data mahasiswa
$daftar_mahasiswa = new DaftarMahasiswa();

//melakukan tambah data
$daftar_mahasiswa->tambahMahasiswa("2101963", "Rasyid Andriansyah",  "Ilmu Komputer", "FPMIPA");
$daftar_mahasiswa->tambahMahasiswa("2107895", "Maikel Alexander",  "Sistem Informasi", "FPMIPA");

//menampilkan daftar mahasiswa
echo "Daftar Mahasiswa Sebelum Diubah/Hapus:<br>";
$daftar_mahasiswa->tampilDaftarMahasiswa();
echo "<br>";

//melakukan ubah data sesuai dengan kata kunci NIM
$daftar_mahasiswa->ubahMahasiswa("2107895", "2109542", "Asep Saepuloh", "Teknik Informatika", "FPMIPA");
//menampilkan daftar mahasiswa
echo "Daftar Mahasiswa Setelah Diubah:<br>";
$daftar_mahasiswa->tampilDaftarMahasiswa();
echo "<br>";

//melakukan hapus data
$daftar_mahasiswa->hapusMahasiswa("2109542");
//menampilkan daftar mahasiswa
echo "Daftar Mahasiswa Setelah Dihapus:<br>";
$daftar_mahasiswa->tampilDaftarMahasiswa();
echo "<br>";

?>

#include <iostream>

// prototype ygy
int pascal(int n, int k);
void printPascal(int level, int n, int row);

int main() {
    int stack = 3; // jumlah tingkat segitiga
    printPascal(stack, 0, 0); // mulai print segitiga dari baris pertama
    return 0;
}

// prosedur rekursif print
void printPascal(int level, int n, int row) {
    if (n == level) {
        return; // basis rekursi: jika baris mencapai level maksimal, dalam kasus ini 3, berhenti
    }

    if (row > n) {
        std::cout << std::endl; // jika baris selesai dicetak, pindah ke baris berikutnya
        printPascal(level, n + 1, 0); // rekursi untuk baris berikutnya
    } else {
        std::cout << pascal(n, row) << " "; // mencetak elemen dalam baris
        printPascal(level, n, row + 1); // rekursi untuk elemen berikutnya pada baris yang sama
    }
}

// fungsi untuk menghitung elemen segitiga Pascal
int pascal(int n, int k) {
    if (k == 0 || k == n) {
        return 1; // elemen di tepi segitiga selalu 1
    }
    return pascal(n - 1, k - 1) + pascal(n - 1, k); // elemen lainnya, penjumlahan dua elemen di atasnya
}

// note : saya mencoba membuat sesuai saran aslab pada praktikum seblumnya
//        > tidak menggunakan namespace
//        > fungsi & prosedur di bawah fungsi main, diatasnya prototype
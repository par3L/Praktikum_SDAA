#include <iostream> // PA APL momen versi downgrade no library any% speedrun

struct inventory {
    int id;
    std::string nama;
    int jumlah;
    double harga;
};

// prototype-prototype
void tambahinventory(inventory* inventory, int& jumlahkom, int limitinven); // dereference & address
void openinventory(const inventory* inventory, int jumlahkom); // thanks w3school
void editinventory(inventory* inventory, int jumlahkom, int id_kom);
void dropinventory(inventory* inventory, int& jumlahkom, int id_kom);

int main() {
    const int limitinven = 25; // const limit batas atas inventory
    inventory inventory[limitinven]; // deklarasi struct 
    int jumlahkom = 0;  // global buat track isi invent
    int idArray[limitinven] = {0}; // array buat ngelacak unik id, ndak ada aturan buat id tapi harus unik
    int pilihan, id_kom;

    do { // menu sederhana
        std::cout << "===== Menu Inventory Gudang Komputer =====\n";
        std::cout << "1. Tambah inventory\n";
        std::cout << "2. Tampilkan inventory\n";
        std::cout << "3. Edit inventory\n";
        std::cout << "4. Hapus inventory\n";
        std::cout << "5. Keluar\n";
        std::cout << "==========================================\n";
        std::cout << "Pilih menu: "; std::cin >> pilihan;

        switch (pilihan) {
        case 1:
            tambahinventory(inventory, jumlahkom, limitinven, idArray[limitinven]);
            break;
        case 2:
            openinventory(inventory, jumlahkom);
            break;
        case 3:
            std::cout << "Masukkan ID item dalam inventory yang ingin diedit: "; std::cin >> id_kom;
            editinventory(inventory, jumlahkom, id_kom);
            break;
        case 4:
            std::cout << "Masukkan ID item dalam inventory yang ingin dihapus: "; std::cin >> id_kom;
            dropinventory(inventory, jumlahkom, id_kom);
            break;
        case 5:
            std::cout << "Keluar dari program.\n";
            break;
        default:
            std::cout << "Pilihan tidak valid.\n";
        }
    } while (pilihan != 5);

    return 0;
}


    void tambahinventory(inventory* inventory, int& jumlahkom, int limitinven, int idArray[]) {
        if (jumlahkom >= limitinven) {
        std::cout << "Inventory penuh, tidak bisa menambah lebih banyak item.\n";
        return;
    }
        int id;
        std::cout << "Masukkan ID item dalam inventory: ";
        std::cin >> id;

        // Check if ID already exists
        for (int i = 0; i < jumlahkom; i++) {
            if (idArray[i] == id) {
                std::cout << "ID sudah digunakan, silakan masukkan ID lain.\n";
                return;
            }
        }

        std::cout << "Masukkan Nama item: ";
        std::getline(std::cin, inventory[jumlahkom].nama);
        std::cout << "Masukkan Jumlah Stok: ";
        std::cin >> inventory[jumlahkom].jumlah;
        std::cout << "Masukkan Harga item satuan: ";
        std::cin >> inventory[jumlahkom].harga;
        jumlahkom++;
        std::cout << "item" << inventory[jumlahkom].nama <<" dengan ID : "<< inventory[jumlahkom].id <<" berhasil ditambahkan!\n";
    }


void openinventory(const inventory* inventory, int jumlahkom) {
    if (jumlahkom == 0) {
        std::cout << "Tidak ada item di dalam inventory.\n";
        return;
    }
    std::cout << "Daftar item di Gudang:\n";
    for (int i = 0; i < jumlahkom; i++) {
        std::cout << i << ". "
                  << "ID item: " << inventory[i].id
                  << ", Nama: " << inventory[i].nama
                  << ", Jumlah: " << inventory[i].jumlah
                  << ", Harga Satuan: Rp" << inventory[i].harga << "\n";
    }
}


void editinventory(inventory* inventory, int jumlahkom, int id_kom) { // nggak accept string, mager error handling nanti selanjutnya
    for (int i = 0; i < jumlahkom; i++) {
        if (inventory[i].id == id_kom) {
            int pilihanEdit;
            std::cout << "\nBarang ditemukan. Pilih elemen yang ingin diedit:\n";
            std::cout << "1. Nama inventory (Saat ini: " << inventory[i].nama << ")\n";
            std::cout << "2. Jumlah Stok (Saat ini: " << inventory[i].jumlah << ")\n";
            std::cout << "3. Harga inventory (Saat ini: Rp" << inventory[i].harga << ")\n";
            std::cout << "Pilih elemen yang ingin diedit: ";
            std::cin >> pilihanEdit;
            std::cin.ignore();  

            switch (pilihanEdit) {
                case 1:
                    std::cout << "Masukkan Nama inventory Baru: ";
                    std::getline(std::cin, inventory[i].nama);
                    std::cout << "Nama barang berhasil diperbarui.\n";
                    break;
                case 2:
                    std::cout << "Masukkan Jumlah Stok Baru: ";
                    std::cin >> inventory[i].jumlah;
                    std::cout << "Jumlah stok berhasil diperbarui.\n";
                    break;
                case 3:
                    std::cout << "Masukkan Harga inventory Baru: ";
                    std::cin >> inventory[i].harga;
                    std::cout << "Harga barang berhasil diperbarui.\n";
                    break;
                default:
                    std::cout << "Pilihan tidak valid.\n";
                    break;
            }
            return;
        }
    }
    std::cout << "inventory dengan id " << id_kom << " tidak ditemukan.\n";
}


void dropinventory(inventory* inventory, int& jumlahkom, int id_kom) { // hapus berdasarkan id
    for (int i = 0; i < jumlahkom; i++) {
        if (inventory[i].id == id_kom) {
            for (int j = i; j < jumlahkom - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            jumlahkom--;
            std::cout << "inventory berhasil dihapus.\n";
            return;
        }
    }
    std::cout << "inventory dengan id " << id_kom << " tidak ditemukan.\n";
}

// cape juga std::std ni
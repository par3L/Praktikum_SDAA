#include <iostream> // PA APL momen versi downgrade no library any% speedrun

// struct-structan
struct InventoryNode {
    int id;
    std::string nama;
    int jumlah;
    double harga;
    InventoryNode* next;
};

// prototype-prototypean
void tambahinventory(InventoryNode*& head, int& jumlahkom, int& idtrack); 
void openinventory(const InventoryNode* head);
void editinventory(InventoryNode* head, int id_kom);
void dropinventory(InventoryNode*& head, int& jumlahkom, int id_kom);

int main() {
    InventoryNode* head = nullptr; // nunjuk ke head, sekarang null karena kosong
    int jumlahkom = 0; // track jumlah komputer di dalam inven
    int idtrack = 1; 
    int pilihan, id_kom;

    do { // menu simple, tambah border
        std::cout << "===== Menu Inventory Gudang Komputer =====\n";
        std::cout << "|                                        |\n";
        std::cout << "|         1. Tambah inventory            |\n";
        std::cout << "|         2. Tampilkan inventory         |\n";
        std::cout << "|         3. Edit inventory              |\n";
        std::cout << "|         4. Hapus inventory             |\n";
        std::cout << "|         5. Keluar                      |\n";
        std::cout << "|                                        |\n";
        std::cout << "==========================================\n";
        std::cout << "Pilih menu: "; std::cin >> pilihan;

        switch (pilihan) { //switch-switch
        case 1:
            tambahinventory(head, jumlahkom, idtrack);
            break;
        case 2:
            openinventory(head);
            break;
        case 3:
            std::cout << "Masukkan ID item dalam inventory yang ingin diedit: "; std::cin >> id_kom;
            editinventory(head, id_kom);
            break;
        case 4:
            std::cout << "Masukkan ID item dalam inventory yang ingin dihapus: "; std::cin >> id_kom;
            dropinventory(head, jumlahkom, id_kom);
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

void tambahinventory(InventoryNode*& head, int& jumlahkom, int& idtrack) { // create
    InventoryNode* newNode = new InventoryNode; // prepare tambah gerbong
    newNode->id = idtrack++; // assign id ke gerbong
    std::cin.ignore(); 
    std::cout << "Masukkan Nama item: ";
    std::getline(std::cin, newNode->nama);
    std::cout << "Masukkan Jumlah Stok: ";
    std::cin >> newNode->jumlah;
    std::cout << "Masukkan Harga item satuan: ";
    std::cin >> newNode->harga;

    newNode->next = nullptr; // assign next dari gerbong baru jadi null
    if (head == nullptr) { // kalo kepala mula-mula null, kepala jadi si gerbong baru
        head = newNode;
    } else {
        InventoryNode* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    jumlahkom++;
    std::cout << "Item dengan ID: " << newNode->id << " berhasil ditambahkan!\n";
}

void openinventory(const InventoryNode* head) { // read
    if (head == nullptr) {
        std::cout << "Tidak ada item di dalam inventory.\n";
        return;
    }
    
    std::cout << "Daftar item di Gudang:\n";
    const InventoryNode* temp = head;
    while (temp != nullptr) {
        std::cout << "ID: " << temp->id
                  << ", Nama: " << temp->nama
                  << ", Jumlah: " << temp->jumlah
                  << ", Harga Satuan: Rp" << temp->harga << "\n";
        temp = temp->next;
    }
}

void editinventory(InventoryNode* head, int id_kom) {
    InventoryNode* temp = head;
    while (temp != nullptr) {
        if (temp->id == id_kom) {
            bool selesai = false;
            while (!selesai) { // looping sampai user selesai
                int pilihanEdit;
                std::cout << "\nBarang ditemukan. Pilih elemen yang ingin diedit:\n";
                std::cout << "1. Nama inventory (Saat ini: " << temp->nama << ")\n";
                std::cout << "2. Jumlah Stok (Saat ini: " << temp->jumlah << ")\n";
                std::cout << "3. Harga inventory (Saat ini: Rp" << temp->harga << ")\n";
                std::cout << "4. Selesai\n";
                std::cout << "Pilih elemen yang ingin diedit (1/2/3, 4 untuk keluar): ";
                std::cin >> pilihanEdit;
                std::cin.ignore(); 

                switch (pilihanEdit) {
                case 1:
                    std::cout << "Masukkan Nama inventory Baru: ";
                    std::getline(std::cin, temp->nama);
                    std::cout << "Nama barang berhasil diperbarui.\n";
                    break;
                case 2:
                    std::cout << "Masukkan Jumlah Stok Baru: ";
                    std::cin >> temp->jumlah;
                    std::cout << "Jumlah stok berhasil diperbarui.\n";
                    break;
                case 3:
                    std::cout << "Masukkan Harga inventory Baru: ";
                    std::cin >> temp->harga;
                    std::cout << "Harga barang berhasil diperbarui.\n";
                    break;
                case 4:
                    selesai = true;
                    std::cout << "Selesai mengedit barang.\n";
                    break;
                default:
                    std::cout << "Pilihan tidak valid.\n";
                    break;
                }
            }
            return;
        }
        temp = temp->next;
    }
    std::cout << "Inventory dengan ID " << id_kom << " tidak ditemukan.\n";
}

void dropinventory(InventoryNode*& head, int& jumlahkom, int id_kom) { // delete
    InventoryNode* temp = head;
    InventoryNode* prev = nullptr;

    while (temp != nullptr) {
        if (temp->id == id_kom) {
            if (prev == nullptr) {
                head = temp->next; 
            } else {
                prev->next = temp->next; // lewat gerbong 
            }
            delete temp;
            jumlahkom--;
            std::cout << "Item dengan ID " << id_kom << " berhasil dihapus.\n";
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    std::cout << "Item dengan ID " << id_kom << " tidak ditemukan.\n";
}

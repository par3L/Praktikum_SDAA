#include <iostream>

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
int openinventory(const InventoryNode* head);
void editinventory(InventoryNode* head, int id_kom);
void dropinventory(InventoryNode*& head, int& jumlahkom, int id_kom);

// stack & queue
void pushStack(InventoryNode*& stackTop, InventoryNode*& head, int id_kom);
void popStack(InventoryNode*& stackTop);
void peekStack(InventoryNode* stackTop);
void enqueueQueue(InventoryNode*& QueueinFirst, InventoryNode*& QueueinLast, InventoryNode*& head, int id_kom);
void dequeueQueue(InventoryNode*& QueueinFirst, InventoryNode*& QueueinLast);
void peekQueue(InventoryNode* QueueinFirst);

int main() {
    InventoryNode* head = nullptr; 
    InventoryNode* stackTop = nullptr;   
    InventoryNode* QueueinFirst = nullptr;   
    InventoryNode* QueueinLast = nullptr;   
    int jumlahkom = 0; // track jumlah komputer di dalam inven
    int idtrack = 1;
    int pilihan, id_kom;

    do {
        std::cout << "===== Menu Inventory Gudang Komputer =====\n";
        std::cout << "|                                        |\n";
        std::cout << "|         1. Tambah inventory            |\n";
        std::cout << "|         2. Tampilkan inventory         |\n";
        std::cout << "|         3. Edit inventory              |\n";
        std::cout << "|         4. Hapus inventory             |\n";
        std::cout << "|         5. Push ke Stack               |\n";
        std::cout << "|         6. Pop dari Stack              |\n";
        std::cout << "|         7. Peek Stack                  |\n";
        std::cout << "|         8. Enqueue ke Queue            |\n";
        std::cout << "|         9. Dequeue dari Queue          |\n";
        std::cout << "|        10. Peek Queue                  |\n";
        std::cout << "|        11. Keluar                      |\n";
        std::cout << "|                                        |\n";
        std::cout << "==========================================\n";
        std::cout << "Pilih menu: "; std::cin >> pilihan;

        switch (pilihan) { // switch-switch
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
        case 5: {
            int result = openinventory(head); 
            if (result != -1) {
                std::cout << "Masukkan ID item untuk di-push ke Stack: "; std::cin >> id_kom;
                pushStack(stackTop, head, id_kom);
            } else {
                std::cout << "Tidak ada item di dalam inventory untuk di push ke dalam stack ...\n";
            }
            break;
        }
        case 6:
            popStack(stackTop);
            break;
        case 7:
            peekStack(stackTop);
            break;
        case 8: {
            int result = openinventory(head); 
            if (result != -1) {
                std::cout << "Masukkan ID item untuk enqueue ke Queue: "; std::cin >> id_kom;
                enqueueQueue(QueueinFirst, QueueinLast, head, id_kom);
            } else {
                std::cout << "Tidak ada item di dalam inventory untuk di-enqueue ke dalam queue ...\n";
            }
            break;
        }
        case 9:
            dequeueQueue(QueueinFirst, QueueinLast);
            break;
        case 10:
            peekQueue(QueueinFirst);
            break;
        case 11:
            std::cout << "Keluar dari program.\n";
            return 0; 
        default:
            std::cout << "Pilihan tidak valid.\n";
        }
    } while (pilihan != 11);

    return 0;
}


void tambahinventory(InventoryNode*& head, int& jumlahkom, int& idtrack) {
    InventoryNode* newNode = new InventoryNode;
    newNode->id = idtrack++;
    std::cin.ignore();
    std::cout << "Masukkan Nama item: ";
    std::getline(std::cin, newNode->nama);
    std::cout << "Masukkan Jumlah Stok: ";
    std::cin >> newNode->jumlah;
    std::cout << "Masukkan Harga item satuan: ";
    std::cin >> newNode->harga;

    newNode->next = nullptr;  
    if (head == nullptr) { 
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

int openinventory(const InventoryNode* head) {
    if (head == nullptr) {
        std::cout << "Tidak ada item di dalam inventory.\n";
        return -1;
    }

    const InventoryNode* temp = head;
    std::cout << "Daftar item di Gudang:\n";
    while (temp != nullptr) {
        std::cout << "ID: " << temp->id
                  << ", Nama: " << temp->nama
                  << ", Jumlah: " << temp->jumlah
                  << ", Harga: Rp" << temp->harga << "\n";
        temp = temp->next;
    }
    return 1;
}

void editinventory(InventoryNode* head, int id_kom) {
    InventoryNode* temp = head;
    while (temp != nullptr) {
        if (temp->id == id_kom) {
            bool selesai = false;
            while (!selesai) { 
                int pilihanEdit;
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

void dropinventory(InventoryNode*& head, int& jumlahkom, int id_kom) {
    InventoryNode* temp = head;
    InventoryNode* prev = nullptr;

    while (temp != nullptr) {
        if (temp->id == id_kom) {
            if (prev == nullptr) {
                head = temp->next;
            } else {
                prev->next = temp->next; 
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

void pushStack(InventoryNode*& stackTop, InventoryNode*& head, int id_kom) {
    InventoryNode* temp = head;
    while (temp != nullptr) {
        if (temp->id == id_kom) {
            InventoryNode* newNode = new InventoryNode(*temp); // stack terpisah
            newNode->next = stackTop;                          // bingung kalau make 1 struct buat invent CRUD trus bisa di stack dan di queue
            stackTop = newNode;
            std::cout << "Item dengan ID: " << newNode->id << " berhasil di-push ke Stack!\n";
            return;
        }
        temp = temp->next;
    }
    std::cout << "Item dengan ID " << id_kom << " tidak ditemukan di inventory.\n";
}

void popStack(InventoryNode*& stackTop) {
    if (stackTop == nullptr) {
        std::cout << "Stack kosong. Tidak ada yang bisa di-pop.\n";
        return;
    }

    InventoryNode* temp = stackTop;
    stackTop = stackTop->next;
    std::cout << "Item dengan ID: " << temp->id << " di-pop dari Stack!\n";
    delete temp;
}

void peekStack(InventoryNode* stackTop) {
    if (stackTop == nullptr) {
        std::cout << "Stack kosong.\n";
    } else {
        std::cout << "Item teratas di Stack:\n";
        std::cout << "ID: " << stackTop->id << ", Nama: " << stackTop->nama
                  << ", Jumlah: " << stackTop->jumlah << ", Harga: Rp" << stackTop->harga << "\n";
    }
}


void enqueueQueue(InventoryNode*& QueueinFirst, InventoryNode*& QueueinLast, InventoryNode*& head, int id_kom) {
    InventoryNode* temp = head;
    while (temp != nullptr) {
        if (temp->id == id_kom) {
            InventoryNode* newNode = new InventoryNode(*temp); // sama juga
            newNode->next = nullptr; 

            if (QueueinLast == nullptr) {
                QueueinFirst = newNode;
                QueueinLast = newNode;
            } else {
                QueueinLast->next = newNode;
                QueueinLast = newNode;
            }
            std::cout << "Item dengan ID: " << newNode->id << " berhasil enqueue ke Queue!\n";
            return;
        }
        temp = temp->next;
    }
    std::cout << "Item dengan ID " << id_kom << " tidak ditemukan di inventory.\n";
}

void dequeueQueue(InventoryNode*& QueueinFirst, InventoryNode*& QueueinLast) {
    if (QueueinFirst == nullptr) {
        std::cout << "Queue kosong. Tidak ada yang bisa di-dequeue.\n";
        return;
    }

    InventoryNode* temp = QueueinFirst;
    QueueinFirst = QueueinFirst->next;
    if (QueueinFirst == nullptr) {
        QueueinLast = nullptr;
    }
    std::cout << "Item dengan ID: " << temp->id << " dequeue dari Queue!\n";
    delete temp;
}

void peekQueue(InventoryNode* QueueinFirst) {
    if (QueueinFirst == nullptr) {
        std::cout << "Queue kosong.\n";
    } else {
        std::cout << "Item terdepan di Queue:\n";
        std::cout << "ID: " << QueueinFirst->id << ", Nama: " << QueueinFirst->nama
                  << ", Jumlah: " << QueueinFirst->jumlah << ", Harga: Rp" << QueueinFirst->harga << "\n";
    }
}

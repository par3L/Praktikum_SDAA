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

// CRUD
void tambahinventory(InventoryNode*& head, int& jumlahkom, int& idtrack);
int openinventory(const InventoryNode* head);
void editinventory(InventoryNode* head, int id_kom);
void dropinventory(InventoryNode*& head, int& jumlahkom, int id_kom);

// sorting-sortingan
void mergeSort(InventoryNode*& head, bool descending = false);
InventoryNode* merge(InventoryNode* left, InventoryNode* right, bool descending);
void shellSort(InventoryNode*& head, int count, bool descending = false);
InventoryNode* getNode(InventoryNode* head, int index);

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
    int jumlahkom = 0; 
    int idtrack = 1;
    int pilihan, id_kom;

    do {
        std::cout << "===== Menu Inventory Gudang Komputer =====\n";
        std::cout << "|                                        |\n";
        std::cout << "|         1. Tambah inventory            |\n";
        std::cout << "|         2. Tampilkan inventory         |\n";
        std::cout << "|         3. Edit inventory              |\n";
        std::cout << "|         4. Hapus inventory             |\n";
        std::cout << "|         5. Stack                       |\n";
        std::cout << "|         6. Queue                       |\n";
        std::cout << "|         7. Keluar                      |\n";
        std::cout << "|                                        |\n";
        std::cout << "==========================================\n";
        std::cout << "Pilih menu: "; std::cin >> pilihan;

        switch (pilihan) {
        case 1:
            tambahinventory(head, jumlahkom, idtrack);
            break;
        case 2: {
            int subPilihanView;
            do {
                std::cout << "===== Menu Tampilkan Inventory =====\n";
                std::cout << "|  1. Raw                            |\n";
                std::cout << "|  2. Sort Stok Ascending            |\n";
                std::cout << "|  3. Sort Stok Descending           |\n";
                std::cout << "|  4. Kembali ke menu utama          |\n";
                std::cout << "=====================================\n";
                std::cout << "Pilih menu: "; std::cin >> subPilihanView;

                switch (subPilihanView) {
                case 1:
                    openinventory(head);
                    break;
                case 2:
                    mergeSort(head);  
                    openinventory(head);
                    break;
                case 3: {
                    int counter = 0;
                    InventoryNode* temp = head;
                    while (temp) { counter++; temp = temp->next; }
                    shellSort(head, counter, true);  
                    openinventory(head);
                    break;
                }
                case 4:
                    std::cout << "Kembali ke menu utama.\n";
                    break;
                default:
                    std::cout << "Pilihan tidak valid.\n";
                }
            } while (subPilihanView != 4);
            break;
        }
        case 3:
            std::cout << "Masukkan ID item dalam inventory yang ingin diedit: "; std::cin >> id_kom;
            editinventory(head, id_kom);
            break;
        case 4:
            std::cout << "Masukkan ID item dalam inventory yang ingin dihapus: "; std::cin >> id_kom;
            dropinventory(head, jumlahkom, id_kom);
            break;
        case 5: {
            int subPilihanStack;
            do {
                std::cout << "===== Menu Stack =====\n";
                std::cout << "|  1. Push Stack     |\n";
                std::cout << "|  2. Pop Stack      |\n";
                std::cout << "|  3. Peek Stack     |\n";
                std::cout << "|  4. Kembali        |\n";
                std::cout << "======================\n";
                std::cout << "Pilih menu: "; std::cin >> subPilihanStack;

                switch (subPilihanStack) {
                case 1:
                    if (openinventory(head) != -1) {
                        std::cout << "Masukkan ID item untuk di-push ke Stack: "; std::cin >> id_kom;
                        pushStack(stackTop, head, id_kom);
                    }
                    break;
                case 2:
                    popStack(stackTop);
                    break;
                case 3:
                    peekStack(stackTop);
                    break;
                case 4:
                    std::cout << "Kembali ke menu utama.\n";
                    break;
                default:
                    std::cout << "Pilihan tidak valid.\n";
                }
            } while (subPilihanStack != 4);
            break;
        }
        case 6: {
            int subPilihanQueue;
            do {
                std::cout << "===== Menu Queue =====\n";
                std::cout << "|  1. Enqueue Queue  |\n";
                std::cout << "|  2. Dequeue Queue  |\n";
                std::cout << "|  3. Peek Queue     |\n";
                std::cout << "|  4. Kembali        |\n";
                std::cout << "======================\n";
                std::cout << "Pilih menu: "; std::cin >> subPilihanQueue;

                switch (subPilihanQueue) {
                case 1:
                    if (openinventory(head) != -1) {
                        std::cout << "Masukkan ID item untuk enqueue ke Queue: "; std::cin >> id_kom;
                        enqueueQueue(QueueinFirst, QueueinLast, head, id_kom);
                    }
                    break;
                case 2:
                    dequeueQueue(QueueinFirst, QueueinLast);
                    break;
                case 3:
                    peekQueue(QueueinFirst);
                    break;
                case 4:
                    std::cout << "Kembali ke menu utama.\n";
                    break;
                default:
                    std::cout << "Pilihan tidak valid.\n";
                }
            } while (subPilihanQueue != 4);
            break;
        }
        case 7:
            std::cout << "Keluar dari program.\n";
            return 0;
        default:
            std::cout << "Pilihan tidak valid.\n";
        }
    } while (pilihan != 7);

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

void mergeSort(InventoryNode*& head, bool descending) {
    if (!head || !head->next) {
        return;
    }
    InventoryNode* slow = head;
    InventoryNode* fast = head->next;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    InventoryNode* mid = slow->next;
    slow->next = nullptr;
    mergeSort(head, descending);
    mergeSort(mid, descending);
    head = merge(head, mid, descending);
}

InventoryNode* merge(InventoryNode* left, InventoryNode* right, bool descending) {
    InventoryNode mergeTemp;
    InventoryNode* tail = &mergeTemp;

    while (left && right) {
        if (descending ? (left->id > right->id) : (left->id <= right->id)) {
            tail->next = left;
            left = left->next;
        } else {
            tail->next = right;
            right = right->next;
        }
        tail = tail->next;
    }

    tail->next = left ? left : right;
    return mergeTemp.next;
}

void shellSort(InventoryNode*& head, int count, bool descending) {
    for (int gap = count / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < count; i++) {
            InventoryNode* current = getNode(head, i);
            InventoryNode* gapNode = getNode(head, i - gap);

            if (gapNode != nullptr && current != nullptr) {
                if ((descending ? current->id > gapNode->id : current->id < gapNode->id)) {
                    
                    int tempId = current->id;
                    current->id = gapNode->id;
                    gapNode->id = tempId;
                    
                    std::string tempName = current->nama;
                    current->nama = gapNode->nama;
                    gapNode->nama = tempName;
                    
                    int tempJumlah = current->jumlah;
                    current->jumlah = gapNode->jumlah;
                    gapNode->jumlah = tempJumlah;
                    
                    double tempHarga = current->harga;
                    current->harga = gapNode->harga;
                    gapNode->harga = tempHarga;
                }
            }
        }
    }
}

InventoryNode* getNode(InventoryNode* head, int index) {
    InventoryNode* current = head;
    for (int i = 0; i < index && current; i++) {
        current = current->next;
    }
    return current;
}

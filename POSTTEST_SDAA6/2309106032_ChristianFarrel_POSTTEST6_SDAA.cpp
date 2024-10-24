#include <iostream>
#include <cmath>

const int NO_OF_CHARS = 256;

// struct-structan
struct InventoryNode
{
    int id;
    std::string nama;
    int jumlah;
    double harga;
    InventoryNode *next;
};

// prototype-prototypean

// CRUD
void tambahinventory(InventoryNode *&head, int &jumlahkom, int &idtrack);
int openinventory(const InventoryNode *head);
void editinventory(InventoryNode *head, int id_kom);
void dropinventory(InventoryNode *&head, int &jumlahkom, int id_kom);

// sorting-sortingan
void mergeSort(InventoryNode *&head, bool descending = false);
InventoryNode *merge(InventoryNode *left, InventoryNode *right, bool descending);
void shellSort(InventoryNode *&head, int count, bool descending = false);
InventoryNode *getNode(InventoryNode *head, int index);

// stack & queue
void pushStack(InventoryNode *&stackTop, InventoryNode *&head, int id_kom);
void popStack(InventoryNode *&stackTop);
void peekStack(InventoryNode *stackTop);
void enqueueQueue(InventoryNode *&QueueinFirst, InventoryNode *&QueueinLast, InventoryNode *&head, int id_kom);
void dequeueQueue(InventoryNode *&QueueinFirst, InventoryNode *&QueueinLast);
void peekQueue(InventoryNode *QueueinFirst);

// search
void badCharHeuristic(std::string str, int size, int badChar[NO_OF_CHARS]);
void boyerMooreSearch(InventoryNode *head, const std::string &key);
int *fibonacciSearch(InventoryNode *head, int value, int size);
int *jumpSearch(InventoryNode *head, int value, int size);
void printlink(InventoryNode *head, int *indices, int size);

int main()
{
    InventoryNode *head = nullptr;
    InventoryNode *stackTop = nullptr;
    InventoryNode *QueueinFirst = nullptr;
    InventoryNode *QueueinLast = nullptr;
    int jumlahkom = 0;
    int idtrack = 1;
    int pilihan, id_kom;

    do
    {
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
        std::cout << "Pilih menu: ";
        std::cin >> pilihan;

        switch (pilihan)
        {
        case 1:
            tambahinventory(head, jumlahkom, idtrack);
            break;
        case 2:
        {
            int subPilihanView;
            do
            {
                std::cout << "===== Menu Tampilkan Inventory =====\n";
                std::cout << "|  1. Raw                            |\n";
                std::cout << "|  2. Sort Stok Ascending            |\n";
                std::cout << "|  3. Sort Stok Descending           |\n";
                std::cout << "|  4. Search                         |\n";
                std::cout << "|  5. Kembali ke menu utama          |\n";
                std::cout << "=====================================\n";
                std::cout << "Pilih menu: ";
                std::cin >> subPilihanView;

                switch (subPilihanView)
                {
                case 1:
                    openinventory(head);
                    break;
                case 2:
                    mergeSort(head);
                    openinventory(head);
                    break;
                case 3:
                {
                    int counter = 0;
                    InventoryNode *temp = head;
                    while (temp)
                    {
                        counter++;
                        temp = temp->next;
                    }
                    shellSort(head, counter, true);
                    openinventory(head);
                    break;
                }
                case 4:
                {
                    int searchMethod;
                    std::cout << "       ===== Menu Search =====\n";
                    std::cout << "|  1. Search by Name (Boyer-Moore)   |\n";
                    std::cout << "|  2. Search by Stok (Fibonacci)     |\n";
                    std::cout << "|  3. Search by Stok (Jump Search)   |\n";
                    std::cout << "|  4. Kembali                        |\n";
                    std::cout << "=====================================\n";
                    std::cout << "Pilih metode pencarian: ";
                    std::cin >> searchMethod;

                    switch (searchMethod)
                    {
                    case 1:
                    {
                        std::string searchKey;
                        std::cin.ignore();
                        std::cout << "Masukkan Nama item: ";
                        std::getline(std::cin, searchKey);
                        boyerMooreSearch(head, searchKey);
                        break;
                    }
                    case 2:
                    {
                        int stockKey;
                        int counter = 0;
                        InventoryNode *temp = head;
                        while (temp)
                        {
                            counter++;
                            temp = temp->next;
                        }
                        std::cout << "Masukkan jumlah stok yang dicari: ";
                        std::cin >> stockKey;
                        int *indices = fibonacciSearch(head, stockKey, counter);
                        printlink(head, indices, indices[0]);
                        delete[] indices;
                        break;
                    }
                    case 3:
                    {
                        int stockKey;
                        int counter = 0;
                        InventoryNode *temp = head;
                        while (temp)
                        {
                            counter++;
                            temp = temp->next;
                        }
                        std::cout << "Masukkan jumlah stok yang dicari: ";
                        std::cin >> stockKey;
                        int *indices = jumpSearch(head, stockKey, counter);
                        printlink(head, indices, indices[0]);
                        delete[] indices;
                        break;
                    }
                    case 4:
                        std::cout << "Kembali ke menu utama.\n";
                        break;
                    default:
                        std::cout << "Pilihan tidak valid.\n";
                    }
                    break;
                }
                case 5:
                    std::cout << "Kembali ke menu utama.\n";
                    break;
                default:
                    std::cout << "Pilihan tidak valid.\n";
                }
            } while (subPilihanView != 5);
            break;
        }
        case 3:
            std::cout << "Masukkan ID item dalam inventory yang ingin diedit: ";
            std::cin >> id_kom;
            editinventory(head, id_kom);
            break;
        case 4:
            std::cout << "Masukkan ID item dalam inventory yang ingin dihapus: ";
            std::cin >> id_kom;
            dropinventory(head, jumlahkom, id_kom);
            break;
        case 5:
        {
            int subPilihanStack;
            do
            {
                std::cout << "===== Menu Stack =====\n";
                std::cout << "|  1. Push Stack     |\n";
                std::cout << "|  2. Pop Stack      |\n";
                std::cout << "|  3. Peek Stack     |\n";
                std::cout << "|  4. Kembali        |\n";
                std::cout << "======================\n";
                std::cout << "Pilih menu: ";
                std::cin >> subPilihanStack;

                switch (subPilihanStack)
                {
                case 1:
                    if (openinventory(head) != -1)
                    {
                        std::cout << "Masukkan ID item untuk di-push ke Stack: ";
                        std::cin >> id_kom;
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
        case 6:
        {
            int subPilihanQueue;
            do
            {
                std::cout << "===== Menu Queue =====\n";
                std::cout << "|  1. Enqueue Queue  |\n";
                std::cout << "|  2. Dequeue Queue  |\n";
                std::cout << "|  3. Peek Queue     |\n";
                std::cout << "|  4. Kembali        |\n";
                std::cout << "======================\n";
                std::cout << "Pilih menu: ";
                std::cin >> subPilihanQueue;

                switch (subPilihanQueue)
                {
                case 1:
                    if (openinventory(head) != -1)
                    {
                        std::cout << "Masukkan ID item untuk enqueue ke Queue: ";
                        std::cin >> id_kom;
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

void badCharHeuristic(std::string str, int size, int badChar[NO_OF_CHARS])
{
    for (int i = 0; i < NO_OF_CHARS; i++)
    {
        badChar[i] = -1;
    }
    for (int i = 0; i < size; i++)
    {
        badChar[(int)str[i]] = i;
    }
}

void boyerMooreSearch(InventoryNode *head, const std::string &key)
{
    int keyLength = key.size();
    InventoryNode *temp = head;

    while (temp != nullptr)
    {
        int dataLength = temp->nama.size();
        int badChar[NO_OF_CHARS];
        badCharHeuristic(key, keyLength, badChar);

        int s = 0;
        while (s <= (dataLength - keyLength))
        {
            int j = keyLength - 1;
            while (j >= 0 && key[j] == temp->nama[s + j])
            {
                j--;
            }
            if (j < 0)
            {
                std::cout << "Found: ID " << temp->id << ", Nama: " << temp->nama << ", Stok: " << temp->jumlah << "\n";
                break;
            }
            else
            {
                s += std::max(1, j - badChar[temp->nama[s + j]]);
            }
        }
        temp = temp->next;
    }
}

int *fibonacciSearch(InventoryNode *head, int value, int size)
{
    int *indices = new int[size + 1];
    indices[0] = 0;

    int fibMMm2 = 0;
    int fibMMm1 = 1;
    int fibM = fibMMm2 + fibMMm1;

    while (fibM < size)
    {
        fibMMm2 = fibMMm1;
        fibMMm1 = fibM;
        fibM = fibMMm2 + fibMMm1;
    }

    int offset = -1;

    while (fibM > 1)
    {
        int i = std::min(offset + fibMMm2, size - 1);

        InventoryNode *temp = getNode(head, i);

        if (temp->jumlah < value)
        {
            fibM = fibMMm1;
            fibMMm1 = fibMMm2;
            fibMMm2 = fibM - fibMMm1;
            offset = i;
        }
        else if (temp->jumlah > value)
        {
            fibM = fibMMm2;
            fibMMm1 = fibMMm1 - fibMMm2;
            fibMMm2 = fibM - fibMMm1;
        }
        else
        {
            indices[++indices[0]] = i;
            return indices;
        }
    }

    return indices;
}

int *jumpSearch(InventoryNode *head, int value, int size)
{
    int step = sqrt(size);
    int prev = 0;
    int *indices = new int[size + 1];
    indices[0] = 0;

    while (getNode(head, std::min(step, size) - 1)->jumlah < value)
    {
        prev = step;
        step += sqrt(size);
        if (prev >= size)
        {
            return indices;
        }
    }

    for (int i = prev; i < std::min(step, size); i++)
    {
        if (getNode(head, i)->jumlah == value)
        {
            indices[++indices[0]] = i;
        }
    }

    return indices;
}

void printlink(InventoryNode *head, int *indices, int size)
{
    for (int i = 1; i <= size; i++)
    {
        InventoryNode *node = getNode(head, indices[i]);
        if (node)
        {
            std::cout << "ID: " << node->id << ", Nama: " << node->nama << ", Stok: " << node->jumlah << "\n";
        }
    }
}

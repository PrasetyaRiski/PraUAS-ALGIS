#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

void findMinCoins(std::vector<int>& coins, int value) {
    std::sort(coins.rbegin(), coins.rend());

    std::cout << "\n===== Hasil Penukaran Koin =====" << std::endl;
    std::cout << "Nama: Prasetya Riski Wa'afan\n";
    std::cout << "NIM: 23533743\n\n";
    int tempValue = value;
    for (int coin : coins) {
        if (tempValue >= coin) {
            int count = tempValue / coin;
            std::cout << "Jumlah keping " << coin << "-an sebanyak : " << count << std::endl;
            tempValue %= coin;
        } else {
             std::cout << "Jumlah keping " << coin << "-an sebanyak : 0" << std::endl;
        }
    }
}

void runPenukaranKoin() {
    std::cout << "\n--- Anda memilih: Penukaran Koin (Greedy) ---\n";
    int n;
    std::cout << "Tuliskan Banyaknya Jenis Koin: ";
    std::cin >> n;

    std::vector<int> coins(n);
    std::cout << "Masukan Jenis Koin (pisahkan dengan spasi): ";
    for (int i = 0; i < n; ++i) {
        std::cin >> coins[i];
    }

    int value;
    std::cout << "Masukan Nilai yang ditukarkan: ";
    std::cin >> value;

    findMinCoins(coins, value);
}

struct Item {
    int id;
    int weight;
    int profit;
    double ratio;
};

bool compareItems(const Item& a, const Item& b) {
    return a.ratio > b.ratio;
}

void greedyKnapsack(std::vector<Item>& items, int capacity) {
    for (auto& item : items) {
        if (item.weight > 0) {
            item.ratio = static_cast<double>(item.profit) / item.weight;
        } else {
            item.ratio = 0;
        }
    }
    std::sort(items.begin(), items.end(), compareItems);

    double totalProfit = 0.0;
    int currentWeight = 0;

    std::cout << "\n===== Hasil Pengisian Knapsack (Greedy) =====" << std::endl;
    std::cout << "Langkah-langkah pengisian:" << std::endl;

    for (const auto& item : items) {
        if (currentWeight == capacity) break;

        if (currentWeight + item.weight <= capacity) {
            currentWeight += item.weight;
            totalProfit += item.profit;
            std::cout << "- Mengambil 100% Objek #" << item.id << " (W:" << item.weight << ", P:" << item.profit << ")" << std::endl;
        } else {
            int remainingWeight = capacity - currentWeight;
            double fraction = static_cast<double>(remainingWeight) / item.weight;
            totalProfit += item.profit * fraction;
            currentWeight += remainingWeight;
            std::cout << "- Mengambil " << std::fixed << std::setprecision(2) << fraction * 100 << "% Objek #" << item.id
                      << " (W:" << remainingWeight << ", P:" << item.profit * fraction << ")" << std::endl;
            break;
        }
    }

    std::cout << "\nKapasitas Maksimal Knapsack: " << capacity << std::endl;
    std::cout << "Total Bobot yang Dimasukkan: " << currentWeight << std::endl;
    std::cout << "Total Profit Maksimal: " << std::fixed << std::setprecision(2) << totalProfit << std::endl;
}

void runKnapsack() {
    std::cout << "\n--- Anda memilih: Knapsack Problem (Greedy) ---\n";
    int capacity;
    std::cout << "Masukkan kapasitas maksimal Knapsack: ";
    std::cin >> capacity;

    int n;
    std::cout << "Masukkan jumlah objek: ";
    std::cin >> n;

    std::vector<Item> items(n);
    std::cout << "Masukkan bobot (weight) dan keuntungan (profit) untuk setiap objek:" << std::endl;
    for (int i = 0; i < n; ++i) {
        items[i].id = i + 1;
        std::cout << "Objek #" << items[i].id << " (weight profit): ";
        std::cin >> items[i].weight >> items[i].profit;
    }

    greedyKnapsack(items, capacity);
}

void merge(std::vector<int>& arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    std::vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(std::vector<int>& arr, int l, int r) {
    if (l >= r) return;
    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
}

void printArray(const std::vector<int>& arr) {
    for (int val : arr) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}

void runMergeSort() {
    std::cout << "\n--- Anda memilih: Merge Sort (Divide and Conquer) ---\n";
    int n;
    std::cout << "Masukkan jumlah elemen array: ";
    std::cin >> n;

    std::vector<int> arr(n);
    std::cout << "Masukkan elemen array (pisahkan dengan spasi): ";
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    std::cout << "\nArray sebelum diurutkan: ";
    printArray(arr);

    mergeSort(arr, 0, arr.size() - 1);

    std::cout << "Array setelah diurutkan dengan Merge Sort: ";
    printArray(arr);
}

int main() {
    std::cout << "TUGAS BESAR PRA UAS - ALGORITMA STRATEGIS" << std::endl;
    std::cout << "Nama: Prasetya Riski Wa'afan" << std::endl;
    std::cout << "NIM: 23533743" << std::endl;

    int choice;
    do {
        std::cout << "\n========================================" << std::endl;
        std::cout << "                 MENU UTAMA             " << std::endl;
        std::cout << "========================================" << std::endl;
        std::cout << "1. Penukaran Koin (Greedy)" << std::endl;
        std::cout << "2. Knapsack Problem (Greedy)" << std::endl;
        std::cout << "3. Merge Sort (Divide and Conquer)" << std::endl;
        std::cout << "0. Keluar" << std::endl;
        std::cout << "----------------------------------------" << std::endl;
        std::cout << "Pilih menu: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                runPenukaranKoin();
                break;
            case 2:
                runKnapsack();
                break;
            case 3:
                runMergeSort();
                break;
            case 0:
                std::cout << "\nTerima kasih! Program selesai.\n";
                break;
            default:
                std::cout << "\nPilihan tidak valid. Silakan coba lagi.\n";
                break;
        }

    } while (choice != 0);

    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>

void TopFive(std::vector<int> Array);

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> Nums(n);
    
    for (int i = 0; i < n; i++) {
        std::cin >> Nums[i];
    }

    TopFive(Nums);

}
void VectorPrnt(std::vector<int> Num) {
    for (auto i = Num.begin(); i < Num.end(); ++i) {
        std::cout << *i << " ";
    }
    std::cout << "\n";
}
std::vector<int> BublSort(std::vector<int> Array) {
    for (int i = 0; i < int(Array.size() - 1); i++) {
        for (int j = int(Array.size() - 1); j > i; j--)
        {
            if (Array[j - 1] < Array[j])
            {
                int buf = Array[j - 1];
                Array[j - 1] = Array[j];
                Array[j] = buf;
            }
        }
    }
    return Array;
}
void TopFive(std::vector<int> Array) {
    std::vector<int> Buf;
    int k, D = 0;
    for (int i = 0; i < Array.size(); i++) {
        if ((int)Buf.size() == 5) {
            for (int j = 0; j < Buf.size(); j++) {
                if (Buf[j] > Array[i]) {
                    k = j;
                    D = 1;
                    break;
                }
            }
            if (D == 1) {
                Buf[k] = Array[i];
                D = 0;
            }
        }
        else {
            Buf.push_back(Array[i]);
        }
        Buf = BublSort(Buf);
        VectorPrnt(Buf);

    }
}
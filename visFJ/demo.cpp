#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

// std::vector<int> jacobstal_seq(int size) // x = 0
// {
//     std::vector<int> seq;
//     int x = 0;
//     int y = 1;
//     seq.push_back(x);
//     seq.push_back(y);
//     for (size_t i = 2; i < size; ++i)
//     {
//         int j = seq[i - 1] + 2 * seq[i - 2];
//         if (j > size - 1)
//             break;
//         seq.push_back(seq[i - 1] + 2 * seq[i - 2]);
//     }
//     seq.erase(seq.begin() + 1);
//     return seq;
// }

class myClass
{
public:
    int i = 10;
    void func()
    {
        int x = i;
        if (i >= 100)
            return;
        i++;
        std::cout << "inside i is:" << i << std::endl;
        func();
        std::cout << "i is:" << i << std::endl;
    }
};

int main()
{

    myClass a;
    a.func();

    return 0;
}
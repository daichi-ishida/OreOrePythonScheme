// #include "add.h"
// #include <cstdio>

// int main()
// {
//     int x = add(2, 3);
//     printf("%d\n", x);
// }


#include "mycuda.h"
#include <iostream>

int main()
{
    MyCuda mycuda = MyCuda();
    std::vector<int> a = {0, 1, 2, 3, 4};
    std::vector<int> b = {6, 3, 7, 1, 0};

    auto c = mycuda.add_arrays_int(a,b);

    std::cout << "App" << std::endl;
    for (int i = 0; i < a.size(); i++)
    {
        std::cout << c[i] << ",";
    }

}
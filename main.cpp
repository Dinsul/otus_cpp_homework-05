#include <iostream>
#include "matrix.h"

int main (int, char**)
{
    Matrix <int, 0> mat;

    for (int i = 0; i < 10; ++i)
    {
        mat[i][i] = i;
        mat[i][9 - i] = i;
    }

    for (int y = 1; y < 9; ++y)
    {
        for (int x = 1; x < 9; ++x)
        {
            std::cout << mat.at(y).at(x) << " ";
        }

        std::cout << std::endl;
    }
    std::cout << "size = " << mat.size() << "\n" << std::endl;

    return 0;
}

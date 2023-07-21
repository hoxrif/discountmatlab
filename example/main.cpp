#include<iostream>
#include"../headers/CMatrix.hpp"
int main(int argc,char **argv)
{
    (void)argc;
    (void)argv;

    CMatrix<int> m(10,10);
    int c = 10;

    for(int i = 0;i<10;i++)
    {
        for(int j = 0;j<10;j++)
            m[i][j] = c++;
    }

    std::cout << m;



    return 1;
}
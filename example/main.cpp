#include<iostream>
#include<thread>
#include<chrono>
#include"../headers/CMatrix.hpp"

using namespace matrix;
void islem()
{
  CMatrix<int> m(10,10),n;

  std::cout << m << '\n';
  std::cout << n << '\n';

  n = std::move(m);

  //m[0][0] = 61;
  //n[0][0] = 31;

  std::cout << m << '\n';
  std::cout << n << '\n';




}

int main(int argc,char **argv)
{
    (void)argc;
    (void)argv;
    while(1)
    {
        islem();
        break;;
    }


    return 1;
}
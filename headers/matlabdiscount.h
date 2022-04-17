#ifndef MATRIX_H
#define MATRIX_H


#define TEMPLATE_TYPE  template<typename T>


enum MATRIX_TYPE {
    ZERO_MATRIX = 0,
    ONE_MATRIX,
    EYE_MATRIX
};


TEMPLATE_TYPE
class CMatrix{

private:

    T **__matrix; // 2d array
    int __sizeM;
    int __sizeN;
    void createMatrix(int M,int N);
public:
    CMatrix();
    ~CMatrix();
    CMatrix(int m,int n);   // MxN zero matrix
    CMatrix(int m,int n,MATRIX_TYPE mType); // exam. -> 'e' MxN eye matrix 
    CMatrix(int m,int n,T one_d_array[]);
    //CMatrix operator+(const CMatrix & mtrx);
};


template class CMatrix<char>;
template class CMatrix<unsigned char>;
template class CMatrix<short>;
template class CMatrix<unsigned short>;
template class CMatrix<int>;
template class CMatrix<unsigned int>;
template class CMatrix<float>;
template class CMatrix<long>;
template class CMatrix<unsigned long>;
template class CMatrix<double>;
#endif
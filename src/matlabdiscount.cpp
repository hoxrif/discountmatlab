#include "../headers/matlabdiscount.h"



TEMPLATE_TYPE CMatrix<T>::CMatrix():
    __matrix(nullptr),
    __sizeM(0),
    __sizeN(0) {
    // class initialize 
}

TEMPLATE_TYPE CMatrix<T>::~CMatrix(){
    if (__matrix != nullptr){
        for (int i = 0;i<__sizeM;i++)
            delete [] __matrix[i];

        delete []__matrix;
    }
}
TEMPLATE_TYPE CMatrix<T>::CMatrix(int M,int N): 
    __matrix(nullptr),
    __sizeM(0),
    __sizeN(0) {
    createMatrix(M,N);
    for(int i=0;i<M;i++)
        for(int j=0;j<N;j++)
            __matrix[i][j] = 0;

    __sizeM = M;
    __sizeN = N;
}
TEMPLATE_TYPE CMatrix<T>::CMatrix(int M,int N,MATRIX_TYPE mType):
    __matrix(nullptr),
    __sizeM(0),
    __sizeN(0)
{
    int i,j;
    if (M<0 || N<0)
        return ;
    createMatrix(M,N);   
    switch (mType)  {        
        case MATRIX_TYPE::ONE_MATRIX:
            for (i = 0;i<M;i++) for (j=0;j<N;j++) __matrix[i][j] = 1;
        break;
        case MATRIX_TYPE::EYE_MATRIX:
            for (i = 0;i<M;i++) for (j=0;j<N;j++) __matrix[i][j] = i == j ? 1:0;
        break;
        case MATRIX_TYPE::ZERO_MATRIX:
        default:
            for (i = 0;i<M;i++) for (j=0;j<N;j++) __matrix[i][j] = 0;
        break;
    }
    __sizeM = M;
    __sizeN = N;
}
TEMPLATE_TYPE CMatrix<T>::CMatrix(int M,int N,T arr[]):__matrix(nullptr),
    __sizeM(0),
    __sizeN(0)
{
    if (arr == nullptr)
        return;

    createMatrix(M,N);
    for (int i = 0;i<M;i++)
        for(int j = 0;j<N;j++)
            __matrix[i][j] = arr[i*M + j];
    __sizeM = M;
    __sizeN = N;
}

TEMPLATE_TYPE 
void CMatrix<T>::createMatrix(int M,int N){
    __matrix = new T*[M];
    for (int i=0;i<M;i++)
        __matrix[i] = new T[N];
}

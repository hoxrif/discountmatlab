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

};

#endif
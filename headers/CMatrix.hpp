#ifndef CMATRIX_H
#define CMATRIX_H
#include<iostream>

#define MATRIX_TEMPLATE template<class T>


struct MATRIX_SHAPE
{
    size_t m_M,m_N;
    MATRIX_SHAPE(){
        m_M=m_N=0;
    }
    ~MATRIX_SHAPE(){}
    MATRIX_SHAPE(size_t __m,size_t __n)
    {
        m_M=__m;
        m_N=__n;
    }
    MATRIX_SHAPE(const MATRIX_SHAPE & other){
        m_M = other.m_M;
        m_N = other.m_N;
    }
    MATRIX_SHAPE(MATRIX_SHAPE && other){
        m_M = other.m_M;
        m_N = other.m_N;
        other.m_M=0;
        other.m_N=0;
    }
    MATRIX_SHAPE & operator=(const MATRIX_SHAPE & other){
        if (this != &other){
            m_M=other.m_M;
            m_N=other.m_N;
        }
        return *this;
    } 
    MATRIX_SHAPE & operator=(MATRIX_SHAPE && other){
        if (this != &other)
        {
            m_M=other.m_M;
            m_N=other.m_N;
            other.m_M=other.m_N=0;
        }
        return *this;
    }
    
    size_t M() const noexcept{
        return m_M;
    }
    size_t N() const noexcept{
        return m_M;
    }
    size_t GetSize() const noexcept{
        return m_M*m_N;
    }


    friend std::ostream & operator << (std::ostream & out, const MATRIX_SHAPE & other ){
        out << "[" << other.m_M << "x" << other.m_N << "]";
        return out;       
    }
};
MATRIX_TEMPLATE
class MATRIX_ARRAY {
public:
    MATRIX_ARRAY(){
        m_Size = 0;
        m_Data = NULL;
    }
    ~MATRIX_ARRAY(){
        if (m_Data != nullptr)
            delete [] m_Data;
    }
    MATRIX_ARRAY(size_t __size)
    {
        m_Size = __size;
        m_Data = new T[__size];
    }
    MATRIX_ARRAY(const MATRIX_ARRAY & other)
    {
        m_Size = other.m_Size;
        m_Data = new T[m_Size];
        for(size_t i = 0;i<m_Size;i++)
            m_Data[i] = other.m_Data[i];        
    }
    MATRIX_ARRAY(MATRIX_ARRAY && other)
    {
        m_Size = other.m_Size;
        m_Data = other.m_Data;

        other.m_Size = 0;
        other.m_Data = 0;
    }
    MATRIX_ARRAY & operator=(const MATRIX_ARRAY & other)
    {
        if (this != &other)
        {
            m_Size = other.m_Size;
            if (m_Data != NULL)
            {
                delete [] m_Data;
                m_Data = new T[m_Size];
            }
            
            for(size_t i = 0;i<m_Size;i++)
                m_Data[i] = other.m_Data[i];
        }
        return *this;
    }
    MATRIX_ARRAY & operator=(MATRIX_ARRAY && other)
    {
        if (this != &other)
        {
            if (m_Data != NULL)
                delete [] m_Data;
            m_Size = other.m_Size;
            m_Data = other.m_Data;
            other.m_Size = 0;
            other.m_Data = NULL;
        }
        return *this;
        
    }
    T & operator[](size_t index)
    {
        return m_Data[index];
    }


    void fill(const T & val){
        for(size_t i = 0;i<m_Size;i++)
            m_Data[i] = val;
    }  

    friend std::ostream & operator<<(std::ostream & out,const MATRIX_ARRAY & other)
    {
        out << other.m_Data;
        return out;
    }



private:
    size_t m_Size;
    T * m_Data;
};



/*
    this is a 2d array
*/
MATRIX_TEMPLATE
class CMatrix
{
public:
    CMatrix():m_Shape(MATRIX_SHAPE())
    {
        m_Data = NULL;
    }
    CMatrix(size_t m,size_t n)
    {
        m_Shape = MATRIX_SHAPE(m,n);
        m_Data = MATRIX_ARRAY<MATRIX_ARRAY<T>>(m);
        for(size_t i = 0;i<m;i++){
            m_Data[i] = MATRIX_ARRAY<T>(n);
            //m_Data[i].fill(0);
        }

    }
    ~CMatrix() {

    }
    CMatrix(const CMatrix & other)
    {
        m_Shape = other.m_Shape;

    }
    CMatrix(CMatrix && other)
    {

    }
    CMatrix & operator=(const CMatrix & other)
    {
        if (this != &other)
        {

        }
        return *this;
    }
    CMatrix & operator=(CMatrix && other)
    {
        if (this != &other)
        {

        }
        return *this;
    }


    MATRIX_ARRAY<T> & operator[](size_t index)
    {
        return m_Data[index];
        /*
        size_t j = index % m_Shape.m_M;
        size_t i = (index - j) / m_Shape.m_M;
        return m_Data[i][j];
        */
    }

    friend std::ostream & operator<<(std::ostream & out,CMatrix & other)
    {
        out << '[';
        for(size_t i = 0; i < other.m_Shape.m_M; i++)
        {
            out << '[';
            for(size_t j = 0;j < other.m_Shape.m_N;j++)
                out << other.m_Data[i][j] << ' ';

            out << "]\n";
        }
        out << ']';
        return out;
    }


private:
    MATRIX_SHAPE m_Shape;
    MATRIX_ARRAY<MATRIX_ARRAY<T>> m_Data;



};



#endif
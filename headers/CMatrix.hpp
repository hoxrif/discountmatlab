#include<iostream>
#include<stdexcept>
#include<algorithm>
#include"../headers/matrix_array.hpp"
#include"../headers/matrix_shape.hpp"


namespace matrix
{
    template<class T>
    class CMatrix
    {
    public:
        CMatrix():m_Shape(MATRIX_SHAPE()),m_Data(MATRIX_ARRAY<MATRIX_ARRAY<T>>()) {}
        CMatrix(size_t m,size_t n):m_Shape(MATRIX_SHAPE(m,n))
        {
            m_Data = MATRIX_ARRAY<MATRIX_ARRAY<T>>(m);
            for(size_t i = 0;i<m;i++)
                m_Data[i] = MATRIX_ARRAY<T>(n);
            

        }
        ~CMatrix() {

        }
        CMatrix(const CMatrix & other)
        {
            m_Shape = other.m_Shape;

        }
        CMatrix(CMatrix && other)
        {
            m_Shape = other.m_Shape;
            m_Data = other.m_Data;
            
            other.m_Shape.~MATRIX_SHAPE();
            other.m_Data.~MATRIX_ARRAY();
        }
        CMatrix & operator=(const CMatrix & other)
        {
            if (this != &other)
            {
                m_Shape = other.m_Shape;
                m_Data = other.m_Data;
            }
            return *this;
        }
        CMatrix & operator=(CMatrix && other)
        {
            if (this != &other)
            {
                m_Shape = other.m_Shape;
                m_Data = std::move(other.m_Data);
                other.m_Shape.m_M = other.m_Shape.m_N = 0;
            }
            return *this;
        }


        MATRIX_ARRAY<T> & operator[](size_t index)
        {
            if (index < m_Shape.m_M)
                return m_Data[index];
            else
                throw std::runtime_error("index error -[CMatrix]");
        }

        friend std::ostream & operator<<(std::ostream & out,CMatrix & other)
        {
            size_t i,j;
            for(out << '[' , i = 0; i < other.m_Shape.m_M; i++)
            {
                for(out << '[' , j = 0;j < other.m_Shape.m_N;j++)
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
}

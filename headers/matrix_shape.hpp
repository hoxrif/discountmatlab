#include<iostream>
namespace matrix
{
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
}
#include<stdexcept>
namespace matrix
{
    template<class T>
    class MATRIX_ARRAY {
    public:
        MATRIX_ARRAY(){
            m_Size = 0;
            m_Data = NULL;
        }
        ~MATRIX_ARRAY(){
            if (m_Data != NULL)
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
                    delete [] m_Data;

                m_Data = new T[m_Size];

                for(size_t i = 0;i < m_Size;i++)
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
            if (index < m_Size)
                return m_Data[index];
            else
                throw std::runtime_error("index error -[ MATRIX ARRAY ]");
        }


        void fill(const T & val){
            for(size_t i = 0;i<m_Size;i++)
                m_Data[i] = val;
        }  

        friend std::ostream & operator<<(std::ostream & out,const MATRIX_ARRAY & other)
        {
            out << '[';
            for (size_t i = 0;i<other.m_Size;i++)
                out << other.m_Data[i] << ' ';
            out << ']';
            return out;
        }
    private:
        size_t m_Size;
        T * m_Data;
    };
}
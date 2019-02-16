#ifndef MATRIX_H
#define MATRIX_H
#include "Matrix/Array/Array.h"
#include<memory>
namespace matrix{
    class Matrix{
        public:
        virtual void cols();
        virtual void rows();
        virtual void trans();
        virtual void operator()();
        virtual void operator[]();
        virtual void SVD();
        virtual void EVD();
    }
    template<typename T,size_t row_n,size_t col_n>
    class Matrix:public Matrix{
        typedef array::NDArray<T,col_n,row_n>* self_data_ptr;
        typedef array::NDArray<T,col_n,row_n> self_data; 
        typedef Matrix<T,row_n,col_n> self;
        typedef Matrix<T,col_n,row_n> self_T;
        typedef Matrix<T,row_n,col_n>* self_ptr; 
        typedef Matrix<T,row_n,col_n>& self_reference;
        typedef Matrix<T,col_n,row_n>* self_T_ptr;
        typedef Matrix<T,col_n,row_n>& self_T_reference;
        private:
        array::NDArray<T,col_n,row_n>* data;
        template<typename value_type, size_t n, size_t m> struct Item;
        public:
        Matrix();
        Matrix(const self_reference);
        ~Matrix();
        size_t cols();
        size_t rows();
        self_T trans();
        self_data data();
        T operator()(size_t _row_index,size_t _col_index);
        void* operator * (void* obj);
        self operator + (void* obj);
        self operator - (void* obj);
        std::array<T, this->rows()> operator * (void* Vector);
        Item<T,row_n,col_n>* SVD(); //Singular Value Decomposition
        Item<T,row_n,col_n>* EVD(); //Eigen Value Decomposition
    };
    template<typename T,size_t col_n>
    class Matrix:public Matrix{
        typedef array::nArray<T,col_n>* self_data_ptr;
        typedef array::nArray<T,col_n> self_data;
        typedef Matrix<T,col_n> self;
        typedef Matrix<T,col_n> self_T;
        typedef Matrix<T,col_n>* self_ptr; 
        typedef Matrix<T,col_n>& self_reference;
        typedef Matrix<T,col_n>* self_T_ptr;
        typedef Matrix<T,col_n>& self_T_reference; 
        private:
        self_data_ptr data;
        template<typename value_type, size_t n> struct Item;
        public:
        Matrix();
        Matrix(size_t n,size_t m);
        Matrix(size_t _col_n);
        Matrix(const self_reference);
        ~Matrix();
        size_t cols();
        size_t rows();
        self_T trans();
        self_data data();
        
        std::array<T,col_n> operator[](size_t row_index);
        T operator()(size_t _row_index,size_t _col_index);
        void* operator * (void* obj);
        self operator + (void* obj);
        self operator - (void* obj);
        std::array<T, this->rows()> operator * (void* Vector);
        Item<T,col_n>* SVD(); //Singular Value Decomposition
        Item<T,col_n>* EVD(); //Eigen Value Decomposition
    };
    template<typename T>
    class Matrix:public Matrix{
        typedef Matrix<T> self;
        typedef Matrix<T> self_T;
        typedef Matrix<T>* self_ptr; 
        typedef Matrix<T>& self_reference;
        typedef Matrix<T>* self_T_ptr;
        typedef Matrix<T>& self_T_reference; 
        private:
        size_t col_num;
        size_t row_num;
        self_data_ptr data;
        template<typename value_type, size_t row_n,size_t col_n> struct Item;
        public:
        Matrix(size_t n,size_t m);
        Matrix(const self_reference);
        ~Matrix();
        size_t cols();
        size_t rows();
        self_T trans();
        self_data data();
        T operator()(size_t _row_index,size_t _col_index);
        void* operator * (void* obj);
        std::array<T, row_num> operator * (void* Vector);
        self operator + (void* obj);
        self operator - (void* obj);
        Item<T,row_n,col_n>* SVD(); //Singular Value Decomposition
        Item<T,row_n,col_n>* EVD(); //Eigen Value Decomposition
    };
}
#include "./Matrix.cpp"
#endif
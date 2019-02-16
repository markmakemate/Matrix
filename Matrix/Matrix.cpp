#include "./Matrix.h"
#include<iostream>
#include<string>
#include<stdlib.h>
template<typename T, size_t row_n,size_t col_n>
matrix::Matrix<T, row_n, col_n>::Matrix(){
    this->data = new NDArray<T, col_n, row_n>;
}
template<typename T, size_t row_n,size_t col_n>
matrix::Matrix<T, row_n, col_n>::~Matrix(){
    delete data;
}
template<typename T, size_t row_n,size_t col_n>
matrix::Matrix<T, row_n, col_n>::Matrix(const Matrix<T,row_n,col_n>& M){
    this->data = new NDArray<T, col_n, row_n>;
    *(this->data) = M;
}
template<typename T, size_t row_n,size_t col_n>
size_t matrix::Matrix<T, row_n, col_n>::cols(){
    return this->data->dim();
}
template<typename T, size_t row_n,size_t col_n>
size_t matrix::Matrix<T, row_n, col_n>::rows(){
    return this->data->rows();
}
template<typename T, size_t row_n,size_t col_n>
T matrix::Matrix<T, row_n, col_n>::operator ()(size_t i, size_t j){
    return (*(data+i))[j];
}
template<typename T, size_t row_n,size_t col_n>
matrix::Matrix<T, row_n, col_n> matrix::Matrix<T, row_n, col_n>::operator + (const matrix::Matrix<T, row_n, col_n>& M){
    matrix::Matrix<T, row_n, col_n> result; 
    try{
        result->data() = this->data() + M.data();
    }catch(string s){
        cout<<s;
        exit(1);
    }
}
template<typename T, size_t row_n,size_t col_n>
matrix::Matrix<T, row_n, col_n> matrix::Matrix<T, row_n, col_n>::operator - (const matrix::Matrix<T, row_n, col_n>& M){
    matrix::Matrix<T, row_n, col_n> result; 
    try{
        result->data() = this->data() - M.data();
    }catch(string s){
        cout<<s;
        exit(1);
    }
}

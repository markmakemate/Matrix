#include<iostream>
#include<vector>
#include<array>
#include<cstdlib>
using namespace std;
namespace array{
    template<typename T, size_t N,size_t row_n=1>
    struct NDArray{
        typedef NDArray self;
        typedef NDArray* self_ptr;
        typedef NDArray& self_reference;
        std::array<T,N>* data;
        NDArray(){
            data=new array<T,N>(row_n);
        }
        array<T,N> operator[](size_t row){
            if(row>row_n){
                throw "Out Range Error!";
            }
            return *(data+row);
        }
        T operator()(size_t row_index, size_t col_index){
            return (*this)[row_index][col_index];
        }
        size_t dim(){
            return N;
        }
        size_t rows(){
            return row_n;
        }
        std::array<T,N> Data(){
            return *data;
        } 
        self operator + (self_reference obj){
            self result;
            if(obj.dim() != N||obj.rows() != row_n){
                throw "Attribute Error: please confirm two matrices have the same row number and col number.";
            }else{
                for(int i=0;i<row_n;i++){
                    for(int j=0;j<N;j++){
                        result(i,j)=obj(i,j)+(*this)(i,j);
                    }
                }
            }
            return result;
        }
    };
    template<typename T,size_t N>
    struct nArray{
        std::vector<std::array<T,N> > data;
        array<T,N> operator[](int row){
            if(row>data.size()){
                throw "Out Range Error";
            }
            return data[row];
        }
        void append(const array<T,N>& row){
            data.push_back(row);
        }
        void pop(){
            data.pop_back();
        }
        size_t size(){
            return (size_t)data.size();
        }
    };
}
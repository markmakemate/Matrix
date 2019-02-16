#include"./Array.hpp"
int main(){
    array::NDArray<int, 3, 3> array;
    array.Data()={{3,3,3},{3,3,3},{3,3,3}};
    cout<<array[2];

}
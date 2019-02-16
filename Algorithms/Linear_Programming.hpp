#include<iostream>
#include "Matrix/Matrix/Matrix.hpp"
#include<vector>
#include"Matrix/Vector/vector.hpp"
#include<memory>
#include<set>
using namespace std;
class LP{
        private:
        vector<double>* constrain;
        vector<double>* params;
        matrix::Matrix* params_matrix;
        vector<double>* solution;
        tuple<set<size_t>, set<size_t>,matrix::Matrix,vector<double>,vector<double>,double> pivot(tuple coefficients);
        public:
        LP(vector<double>& __constrain, vector<double>& __params, const matrix::Matrix& __A__);
        ~LP();
        /**
         * @option=0: simplex algorithm
         * @option=1
        **/
        void execute(int option=0);
        void execute(const vector<double>& constrain, const vector<double>& params,int option=0);
        vector<double> get_solution();
        void simplex();
        void simplex(const vector<double>& constrain, const vector<double>& params);

};

LP::LP(const vector<double>& b, const vector<double>& c, matrix::Matrix A){
    constrain=new vector<double>;
    params=new vector<double>;
    params_matrix=new matrix::Matrix;
    *constrain=b;
    *params=c;
    *params_matrix=A;
}
LP::~LP(){
    delete constrain;
    delete params;
    delete solution;
    delete params_matrix;
}

void LP::execute(int option){
    if (constrain != NULL && params != NULL){
        solution=new vector<double>;
    }
}

void LP::execute(const vector<double>& constrain, const vector<double>& params,int option){
    this->constrain=new vector<double>;
    this->params=new vector<double>;
    *(this->constrain)=constrain;
    *(this->params)=params;
    this->solution=new vector<double>;
    if(option == 0){
        simplex();
    }
}

void LP::execute(int option){
    if(option == 0){
        simplex(*constrain, *params, *params_matrix);
    }
}

tuple<set<size_t>, set<size_t>,matrix::Matrix,vector<double>,vector<double>,double> LP::pivot(void* coefficients){
    set<size_t> N=get<0>(*coefficients);
    set<size_t> B=get<1>(*coefficients);
    matrix::Matrix A=get<2>(*coefficients);
    vector<double> b=get<3>(*coefficients);
    vector<double> c=get<4>(*coefficients);
    auto v=get<5>(*coefficients);
    size_t l=get<6>(*coefficients);
    size_t e=get<7>(*coefficeints);
    vector<double> b_candidate = new vector<double>(b.size());
    vector<double> c_candidate = new vector<double>(c.size());
    Matrix<double, A.rows(), A.cols()> A_candidate;
    b_candidate[e] = b[l]/A(l,e);
    for(size_t j : N){
        if(j!= e){
            A_candidate(e, j)=A(l, j)/A(l, e);
        }
    }
    A_candidate(e, l) = 1/A(l, e);
    for(size_t i : B){
        if(i != l){
            b_candidate[i]=b[i]-A(i,e)*b_candidate[e]
        }
        for(size_t j : N){
            if(j != e){
                A_candidate(i, j) = A(i, j) - A(i,e)*A_candidate(e,j);
            }
            A_candidate(i, l) = -A(i,e)*A_candidate(e,l);
        }
    }
    auto v_candidate = v + c[e]*b_candidate[e];
    for(size_t j : N){
        if(j != e){
            c_candidate[j] = c[j] - c[e]*A_candidate(e, j);
        }
    }
    c_candidate[l] = -c[e]*A_candidate(e, l);
    auto N_candidate = N;
    auto B_candidate = B;
    N_candidate.erase(e);
    N_candidate.erase(l);
    N_candidate.erase(e);
    B_candidate.erase(l);
    tuple result;
    auto result = make_tuple(N_candidate, B_candidate, A_candidate, b_candidate, c_candidate, v_candidate);
    return result;
}

void LP::simplex(){
    
}


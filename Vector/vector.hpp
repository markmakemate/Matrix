#include<vector>
#include<cstdlib>
using namespace std;
template<typename _input_type,typename _output_type>
_output_type operator * (const vector<_input_type>& v1, const vector<_input_type>& v2){
    if(v1.size() != v2.size()){
        raise "Two vectors have not the same dimension, please check!";
    }else{
        _input_type result;
        int loop=v1.size();
        for(int i=0;i<loop;i++){
            result+=v1[i]*v2[i];
        }
        return (_output_type)result;
    }
}
template<typename _input_type,typename _output_type>
vector<_output_type> operator + (const vector<_input_type>& v1, const vector<_input_type>& v2){
    if(v1.size() != v2.size()){
        raise "Two vectors have not the same dimension, please check!";
    }else{
        vector<_output_type> result;
        int loop=v1.size();
        for(int i=0;i<loop;i++){
            result.push_back((_output_type)(v1[i]+v2[i]));
        }
        return result;
    }
}
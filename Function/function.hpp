
/*
interface of abstract function;
Every new math fnction object should inherit it and implement its methods;
1. Overwrite operator (): output the value on a given point
2. diff(): differentiate the function on a given point
3. grad(): calculate the gradient on a given point
*/
namespace function{
    class function{
        public:
        virtual void operator()();
        virtual void diff();
        virtual void grad();
    };
}
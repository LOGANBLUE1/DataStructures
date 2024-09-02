#include<iostream> 
using namespace std;

class one{
protected:
    int x;
public:
    one(){
        this->x=10; 
    }
};

class two: public one{
protected:
    int y;
public: 
    two(){ 
        this->y=20; 
    }
};

class three: public one{
protected:
    int z;
public:
    three(){ 
        this->z=30; 
    }
};
class result: public one, public two, public three{
public:
    void calculate(){
        cout << x+y+z;
    }
};

int main(){
    result res = new result();
    res.calculate();
    return 0;
}
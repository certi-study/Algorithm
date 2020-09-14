#include <iostream>
#include <ctime>
#define N 100000000
using namespace std;

int main(){
int start;
    int x = 0;
    start = clock();
    x = 0;
    for(int i = N;i--;){
        x = x>0?x-2:x+2;
    }
    cout<<clock()-start<<endl;
    
    start = clock();
    x = 0;
    for(int i = N;i--;){
        if(x > 0)
            x = x - 2;
        else
            x = x + 2;
    }
    cout<<clock()-start<<endl;
    
    return 0;
}

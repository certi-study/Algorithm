#include <iostream>
#include <ctime>
#define N 123456789
using namespace std;

int y;

void a(int x){
	x++;
    x = 0;
    x--;
    x = 0;
}

void b(){
	y++;
    y = 0;
    y--;
    y=0;
}

int main(){
	int start;
    int x = 0;
    start = clock();
    x = 0;
    for(int i = N;i--;){
        a(x);
    }
    cout<<clock()-start<<endl;
    
    start = clock();
    y = 0;
    for(int i = N;i--;){
        b();
    }
    cout<<clock()-start<<endl;
    
    return 0;
}

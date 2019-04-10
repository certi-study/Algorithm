#include <iostream>
#include <ctime>

using namespace std;

int main()
{
    int start;
    start = clock();
    
    int s = 0;
    for(int i=0;i<1000000;i++){
        s++;
    }
    cout<<clock() - start<<endl;
    
    start = clock();
    s = 0;
    for(int i=0;i<1000;i++){
        for(int j=0;j<1000;j++){
            s++;
        }
    }
    cout<<clock() - start<<endl;
    
    
    
    start = clock();
    s = 0;
    for(int i=0;i<10;i++){
        for(int j=0;j<100000;j++){
            s++;
        }
    }
    cout<<clock() - start<<endl;
   
   return 0;
}
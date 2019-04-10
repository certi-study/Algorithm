#include <iostream>
#include <ctime>

using namespace std;

int main()
{
    int start;
    start = clock();
    
    int s = 0;
    for(int i=0;i<10000000;i++){
        s++;
    }
    cout<<clock() - start<<endl;
    
    double d;
    start = clock();
    d = 0;
    for(int i=0;i<10000000;i++){
            d++;
    }
    cout<<clock() - start<<endl;
    
    double c;
    start = clock();
    c = 0;
    for(int i=0;i<10000000;i++){
            c++;
    }
    cout<<clock() - start<<endl;
    
    
   return 0;
}

#define SIZE 65536 // 1 << 16

namespace in{
    char buffer[SIZE]; 
    int index = SIZE;
 
    inline char getChar(){
        if(index == SIZE){
            fread(buffer, 1, SIZE, stdin);
            index = 0;
        }
 
        return buffer[index++];
    }
 
    inline int getInt(){
        register int number = 0, i;
 
        do {
            i = getChar();
        } while (i < 48 || i > 57);
 
        do {
            number = number * 10 + i - 48;
            i = getChar();
        } while (i >= 48 && i <= 57);
 
        return number;
    }
}
 
namespace out{
    char buffer[SIZE];
    int idx;
     
    inline void flush(){
        fwrite(buffer, 1, idx, stdout);
    }
    inline void write(char c){
        if(idx == SIZE){
            flush();
            idx = 0;
        }
        buffer[idx++] = c;
    }
    inline void writeInt(int i){
        register char digit[16];
        register int n = 0;
        
        if(i == 0){
            write('0');
            return;
        }
        
        while(i){
            digit[n++] = (i % 10) | 48;
            i /= 10;
        }
        while(n){
            write(digit[--n]);
        }
    }
}

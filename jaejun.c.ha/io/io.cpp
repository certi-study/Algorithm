#define SIZE 65536 // 1 << 16

namespace in{
 /****************************************************************** 
  만약 읽어야할 항목의 크기가 크지 않다면                        
  
  1. ridx = 0으로 설정하고                                        
  
  2. fread(rbuffer, 1, SIZE, stdin); 를 main문 시작 후 바로 사용   
  
  3. getChar에서 아래 항목 제거하기
  
  if(ridx == SIZE){
    fread(rbuffer, 1, SIZE, stdin);
    ridx = 0;
  }
 ******************************************************************/
    
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
        /* 숫자 0은 출력 되지 않으니 주의! */
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

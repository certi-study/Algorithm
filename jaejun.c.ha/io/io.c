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
#define SIZE 65536
 
char rbuffer[SIZE]; 
int ridx = SIZE;
 
char getChar(){
  if(ridx == SIZE){
    fread(rbuffer, 1, SIZE, stdin);
    ridx = 0;
  }
 
  return rbuffer[ridx++];
}
 
int getInt(){
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
 
char wbuffer[SIZE];
int widx;
     
void flush(){
  fwrite(wbuffer, 1, widx, stdout);
}

void writeChar(char c){
  if(widx == SIZE){
    flush();
    widx = 0;
  }
  wbuffer[widx++] = c;
}

void writeInt(int i){
  char digit[16];
  register int t = 0;
  while(i){
    digit[t++] = (i % 10) | 48;
    i /= 10;
  }
  while(t){
    writeChar(digit[--t]);
  }
}

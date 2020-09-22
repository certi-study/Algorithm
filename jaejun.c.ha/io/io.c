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

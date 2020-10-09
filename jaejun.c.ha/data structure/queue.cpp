#define SIZE 1 << 16

/* 
qhead: head index of queue
qtail: tail index of queue
*/
int qhead, qtail;

int queue[SIZE];

void init(){
  qhead = qtail = 0;
}

void put(int value){
  queue[qtail++] = value;
}

int pop(){
  return queue[qhead++];
}

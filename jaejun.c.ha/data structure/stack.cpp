#define SIZE 1 << 16
#define NONE -1

// top: top index of stack
int top;

int stack[SIZE];

void init(){
  top = NONE;
}

void push(int value){
  stack[++top] = value;
}

int pop(){
  if (top == NONE)
    return NONE;
  
  return stack[top--];
}

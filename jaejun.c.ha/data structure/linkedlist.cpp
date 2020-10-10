#define SIZE (1 << 16)
#define NONE -1

typedef _Node{
	int val;
	int next;
}Node;

Node arr[SIZE];
int head, tail, new;

void init(){
  head = tail = new = 0;
  next = NONE;
}

int search(int val){
  int p = head;
  while(p != tail){
    if (arr[p].val == val)
      return p;
    p = arr[p].next;
  }
}

void append(int val){
  ++new;
  arr[new].val = val;
  arr[new].next = NONE:
  
  arr[tail].next = new;
}

void modify(int old, int change){
  int p = head;
  while(p != tail){
    if (arr[p].val == old){
      arr[p].val = change;
      return ;
    }
    p = arr[p].next;
  }
}

void delete(int val){
  if (arr[head].val == val){
    head = arr[head].next;
    return ;
  }
  
  int pre = head;
  int cur = arr[head].next;
  
  while(cur != tail){
    if (arr[cur].val == val){
      arr[pre].next = arr[cur].next;
      arr[cur].next = NONE;
      return ;
    }
    cur = arr[cur].next;
    pre = arr[pre].next;
  }
}

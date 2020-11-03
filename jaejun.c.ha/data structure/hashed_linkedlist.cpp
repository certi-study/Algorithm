#define SIZE_NODE	20000
#define SIZE_HASH	10000
 
struct NODE {
    int cnt;
    int val;
    NODE* next;
} node_alloc[SIZE_NODE], node_hash[SIZE_HASH];

int loc_new;
 
void init() {
    register int i = -1;
    loc_new = 0;
    
    while (++i < SIZE_HASH) {
        node_hash[i].cnt = 0;
        node_hash[i].next = 0;
    }
}
 
void append(int data) {
    register int cal = data / SIZE_HASH;
    NODE* newnode = &node_alloc[loc_new++];
    newnode->val = data;
    register NODE* c = &node_hash[cal];
    for (; c->next; c = c->next) {
        if (c->next->val > data) 
            break;
    }
    newnode->next = c->next;
    c->next = newnode;
    ++node_hash[cal].cnt;
}
 
int delete(int index) {
    register int i, cnt = 0;
    
    for (i = 0; i < SIZE_HASH; ++i) {
        if (index < (cnt += node_hash[i].cnt)) 
            break;
    }
    cnt -= node_hash[i].cnt;
    
    NODE* c = &node_hash[i];
    
    register int loc = (index - cnt) % 8;
    register int iter = (index - cnt) / 8;
    switch(loc){
        case 7:
            c = c->next;
        case 6:
            c = c->next;
        case 5:
            c = c->next;
        case 4:
            c = c->next;
        case 3:
            c = c->next;
        case 2:
            c = c->next;
        case 1:
            c = c->next;
    }
    while (iter--){
        c = c->next;c = c->next;c = c->next;c = c->next;
        c = c->next;c = c->next;c = c->next;c = c->next;
    }
    
    int ret = c->next->val;
    c -> next = (c->next->next)?c->next->next:0;
    --node_hash[i].cnt;
    
    return ret;
}
 
int find(int index) {
    register int i, cnt = 0;
    
    for (i = 0; i < SIZE_HASH; ++i) {
        if (index < (cnt += node_hash[i].cnt)) 
            break;
    }
    cnt -= node_hash[i].cnt;
    
    register NODE* c = &node_hash[i];
    
    register int loc = (index - cnt) % 8;
    register int iter = (index - cnt) / 8;
    switch(loc){
        case 7:
            c = c->next;
        case 6:
            c = c->next;
        case 5:
            c = c->next;
        case 4:
            c = c->next;
        case 3:
            c = c->next;
        case 2:
            c = c->next;
        case 1:
            c = c->next;
    }
    while (iter--){
        c = c->next;c = c->next;c = c->next;c = c->next;
        c = c->next;c = c->next;c = c->next;c = c->next;
    }
    
    return c->next->val;
}

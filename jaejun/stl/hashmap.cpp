/* reference from: https://swexpertacademy.com */
#define MAX_KEY 64
#define MAX_DATA 128
#define MAX_TABLE 4096
#define MOD_TABLE 4095

typedef struct {
	char key[MAX_KEY + 1];
	char data[MAX_DATA + 1];
}Hash;

Hash tb[MAX_TABLE];

unsigned long hash(register const char *str) {
	register unsigned long h = 5381;

	while (*str) {
    
    /*  "(h << 5) + h"가 의미하는 것: h*33
        "x & MOD_TABLE"이 의미하는 것: x % (MOD_TABLE + 1)  */
    h = (((h << 5) + h) + *str) & MOD_TABLE;
		++str;
	}
	return h & mod;
}

int add(register char const *key, register char const *data) {
	register unsigned long h = hash(key);
	register Hash *p = &tb[0];
    
	while (p[h].key[0] != 0) {
		/* 이미 데이터가 있음 */
    if (strcmp(p[h].key, key) == 0)
			return 0;
      
    /* h 증가 */
		h = (h + 1) & MOD_TABLE;
	}

  /* h 위치에 데이터 넣음 */
	strcpy(p[h].key, key);
	strcpy(p[h].data, data);
  
  /* 삽입 성공 */
	return 1;
}

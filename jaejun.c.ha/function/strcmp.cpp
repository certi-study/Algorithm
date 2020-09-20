/* Reference: https://na982.tistory.com */
inline int strcmp(char *a, char *b){
	register int i = 0, j = 0;
	while(a[i]){
		if(a[i++] != b[j++]){
			--i, --j;
			break;
		}
	}
    
	return a[i] - b[j];
} 

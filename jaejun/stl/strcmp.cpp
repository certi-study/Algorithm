/* reference from: https://muyu.tistory.com/entry/strcmp-%EB%AC%B8%EC%9E%90%EC%97%B4-%EB%B9%84%EA%B5%90-%ED%95%A8%EC%88%98-%EA%B5%AC%ED%98%84-%EC%BD%94%EB%93%9C-%EB%AC%B8%EC%9E%90%EC%97%B4-%ED%8F%AC%EC%9D%B8%ED%84%B0 */
inline int equal5(register const char *a, register const char *b) {

	for (; *a == *b; a++, b++)
		if (*a == '\0')
			return 0;

	return *a - *b;
}
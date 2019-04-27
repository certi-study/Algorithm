inline int len2(register const char *a) {
	register const char *b = a;
	for (; *b; b++);
	return b - a;
}
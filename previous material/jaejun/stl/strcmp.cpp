inline int strcmp(register const char *a, register const char *b) {
	for (; *a == *b; ++a, ++b)
		if (*a == '\0')
			return 0;

	return *a - *b;
}

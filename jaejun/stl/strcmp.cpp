inline int strcmp(register const char *a, register const char *b) {
	while (1) {
		if (!*a)
			return 0;
		a++;
		b++;
		if (!*a)
			return 0;
		a++;
		b++;
		if (!*a)
			return 0;
		a++;
		b++;
		if (!*a)
			return 0;
		a++;
		b++;
		if (!*a)
			return 0;
		a++;
		b++;
		if (!*a)
			return 0;
		a++;
		b++;
		if (!*a)
			return 0;
		a++;
		b++;
		if (!*a)
			return 0;
		a++;
		b++;
		if (!*a)
			return 0;
		a++;
		b++;
		if (!*a)
			return 0;
		a++;
		b++;
	}
	return *a - *b;
}
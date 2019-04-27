int strlen(register const char *a) {
	register const char *b = a;
	for (; *b; b++);
	while (1) {
		if (!*b)
			break;
		b++;
		if (!*b)
			break;
		b++;
		if (!*b)
			break;
		b++;
		if (!*b)
			break;
		b++;
		if (!*b)
			break;
		b++;
		if (!*b)
			break;
		b++;
		if (!*b)
			break;
		b++;
		if (!*b)
			break;
		b++;
		if (!*b)
			break;
		b++;
		if (!*b)
			break;
		b++;
	}
	return b - a;
}
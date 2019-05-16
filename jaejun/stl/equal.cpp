inline int equal(register const char *a, register const char *b) {
    if( less<const char *>()(a,b) == 0 && greater<const char *>()(a,b) == 0)
        return 1;
    else
        return 0;
}
bool checkIfPangram(char * s){
    int b = 0;
    for (; *s; ++s)
        b |= 1 << (*s - 'a');
    return b == (1 << 26) - 1;
}

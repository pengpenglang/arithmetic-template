/**
 * @brief $getchar$版快读支持所有整数类型
 */
inline _Tp read(_Tp &x) {   
    char ch = getchar(), sgn = 0;
    x = 0;
    while (ch ^ '-' && !isdigit(ch)) ch = getchar();
    if (ch == '-') ch = getchar(), sgn = 1;
    while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
    if (sgn) x = -x;
    return x;
}

read(a);
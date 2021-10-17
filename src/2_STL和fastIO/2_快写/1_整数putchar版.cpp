/**
 * @brief putchar版快写,仅支持$[INT_MIN,INT_MAX]$范围
 */
void write(int x) {
    if (x < 0) putchar('-'), x = -x;
    if (x > 9) write(x / 10);
    putchar(x % 10 + '0');
}

putchar(a);//不能输出回车
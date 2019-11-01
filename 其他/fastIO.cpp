// fastio
#include <stdio.h>
#include <ctype.h>

//快速读
inline int read() {
    int num=0, w=0;
    char ch=0;
    while (!isdigit(ch)) {
        w|=ch=='-';
        ch = getchar();
    }
    while (isdigit(ch)) {
        num = (num<<3) + (num<<1) + (ch^48);
        ch = getchar();
    }
    return w? -num: num;
}

//快速写
inline void write(int x)
{
    if(x<0) {
        putchar('-');
        x = -x;
    }
    if(x>9) write(x / 10);
    putchar(x % 10 + '0');
}


int main(){
    int t;
    t = read();     //读入到t中
    write(t);       //输出t
    putchar('\n');
}

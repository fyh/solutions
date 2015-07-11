/*
 * https://zh.wikipedia.org/wiki/%E8%94%A1%E5%8B%92%E5%85%AC%E5%BC%8F
 *
 * 从1582年10月5日开始
 *
 */

int get(int y, int m, int d) {
    if (m < 3) m += 12, --y;
    int c = y / 100;
    y = y % 100;
    return ((y+y/4+c/4-2*c+(26*(m+1))/10+d-1) % 7 + 7) %7;
}
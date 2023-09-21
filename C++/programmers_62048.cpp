using namespace std;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

long long solution(int w, int h) {
    return (long long)w * h - (w + h - gcd(w, h));
}
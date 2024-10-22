#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
    int a,b,c,d,e,f;
    cin >> a >> b >> c >> d >> e >> f;

    int min = -999;
    int max = 1000;

    for(int x = min; x < max; x++){
        for(int y = min; y < max; y++){
            if(a * x + b * y == c &&
            d * x  + e * y == f){
                cout << x << ' ' << y;
                return 0;
            }
        }
    }
}
#include <iostream>
#include <vector>

using namespace std;



//int fibonacci(int n, int &countOne, int &countZero) {
//    if (n == 0) {
//        //ans.push_back(0);
//        //printf("0");
//        countZero++;
//        return 0;
//    }
//    else if (n == 1) {
//        //ans.push_back(1);
//        //printf("1");
//        countOne++;
//        return 1;
//    }
//    else {
//        return fibonacci(n - 1, countOne, countZero) + fibonacci(n - 2, countOne, countZero);
//    }
//}

int main(void) {

    int input;
    int buff;

    cin >> input;

    for (int i = 0; i < input; i++) {
        
        int countOne = 0;
        int countZero = 1;


        cin >> buff;
        //fibonacci(buff, countOne, countZero);

        
        /*for (int i = 0; i < ans.size(); i++) {
            if (ans[i] == 0)
                countZero++;
            else
                countOne++;
        }*/

        for (int j = 0; j < buff; j++) {

            int tmp = countZero + countOne;
            countZero = countOne;
            countOne = tmp;
            
        }


        cout << countZero << " " << countOne << endl;
    }

    return 0;

}
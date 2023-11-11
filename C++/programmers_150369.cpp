
#include <string>
#include <vector>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    int ptr_start_deli = n - 1;
    int ptr_end_deli = n - 1;
    int ptr_start_pick = n - 1;
    int ptr_end_pick = n - 1;
    while (true) {

        //포인터 조정
        while (ptr_end_deli > 0 && deliveries[ptr_end_deli] == 0) {
            ptr_end_deli--;
        }

        int deli_sum = deliveries[ptr_end_deli];
        ptr_start_deli = ptr_end_deli;
        while (cap > deli_sum && ptr_start_deli > 0) {
            ptr_start_deli--;
            deli_sum += deliveries[ptr_start_deli];
        }

        while (ptr_end_pick > 0 && pickups[ptr_end_pick] == 0) {
            ptr_end_pick--;
        }

        int pickup_sum = pickups[ptr_end_pick];
        ptr_start_pick = ptr_end_pick;
        while (cap > pickup_sum && ptr_start_pick > 0) {
            ptr_start_pick--;
            pickup_sum += pickups[ptr_start_pick];
        }

        if (ptr_end_deli == 0 && deliveries[ptr_end_deli] == 0 && ptr_end_pick == 0 && pickups[ptr_end_pick] == 0)
            break;

        answer += (max(ptr_end_deli, ptr_end_pick) + 1) * 2;

        //deliveries 조정
        int tmp_deli = cap;
        for (int i = ptr_end_deli; i >= ptr_start_deli; i--) {
            if (tmp_deli >= deliveries[i]) {
                tmp_deli -= deliveries[i];
                deliveries[i] = 0;
            }

            else
                deliveries[i] -= tmp_deli;
        }

        //pickups 조정
        int tmp_pick = cap;
        for (int i = ptr_end_pick; i >= ptr_start_pick; i--) {
            if (tmp_pick >= pickups[i]) {
                tmp_pick -= pickups[i];
                pickups[i] = 0;
            }

            else
                pickups[i] -= tmp_pick;
        }
    }

    return answer;
}

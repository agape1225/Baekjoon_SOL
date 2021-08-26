#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> split_IP(string ip) {
    //cout << ip << endl;
    vector<string> ips;
    string buff = "";
    int count = 0;
    for (int i = 0; i < ip.size(); i++) {

        if (ip[i] == '.' || ip[i] == ':') {
            count++;
            //cout << buff << endl;
            ips.push_back(buff);
            buff = "";
            
        }
        else {
            buff += ip[i];
        }
    }

    ips.push_back(buff);

    return ips;
}

bool is_IP4(string ip) {

    vector<string> ips = split_IP(ip);

    if (ips.size() != 4)
        return false;

    for (auto it = ips.begin(); it != ips.end(); it++) {

        int buff = stoi(*it);

        if (buff > 255 || buff < 0)
            return false;

        if ((*it).size() > 3 || (*it).size() < 0)
            return false;

        if ((*it).at(0) == '0' && (*it).size() > 1)
            return false;

        for (auto tmp : *it) {
            if (!isdigit(tmp))
                return false;
        }


    }

    return true;
}

bool is_IP6(string ip) {

    vector<string> ips = split_IP(ip);

    if (ips.size() > 8)
        return false;

    for (auto it = ips.begin(); it != ips.end(); it++) {

        for (auto tmp : *it) {
            if (!(('0' <= tmp && tmp <= '9') || ('a' <= tmp && tmp <= 'f')))
                return false;
        }

    }

    return true;
}

vector<string> validateAddresses(vector<string> addresses) {

    vector<string> ans;

    for (auto it = addresses.begin(); it != addresses.end(); it++) {
        //cout << *it << endl;
        if (is_IP4(*it)) {
            ans.push_back("IPv4");
        }
        else if (is_IP6(*it)) {
            ans.push_back("IPv6");
        }
        else {
            ans.push_back("Neither");
        }
    }


    return ans;

}

int main(void) {
    //vector<string> ips = { "121.18.19.20", "0.12.12.34", "121.234.12.12", "23.45.12.56", "0.1.2.3" };
   // vector<string> ips = { "121.18.19.20" };
    vector<string> ips = { 
        "2001:0db8:0000:0000:0000:ff00:0042:8329", 
        "2001:db8:0:0:0:ff00:42:8329", 
        "2001:db8:0:0:0:ff00:42:8329", 
        "2001:db8::ff00:42:8329",
        "0000:0000:0000:0000:0000:0000:0000:0001", 
        "::1" };

    vector<string> ans = validateAddresses(ips);

    for (auto it = ans.begin(); it != ans.end(); it++) {
        cout << *it << endl;
    }

    return 0;
}
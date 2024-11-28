#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct node {
    string name;
    vector<node*> childes;
} node;

bool comp(node* node1, node* node2){
    return node1->name < node2->name;
}

node* find_node(node* root, string name){
    // cout << root.childes.size() << endl;
    for(auto it : root->childes){
        // cout <<  "node name: " << it->name << endl;
        if(it->name == name){
            return it;
        }
    }
    return NULL;
}

void push_node(vector<string> nodes, int count, int max, node* root){
    if(count != max){
        string node_name = nodes[count];

        node* current_node = find_node(root, node_name);
        // cout << current_node << endl;

        // if(current_node == NULL){
        //     cout << root->name << ' ' << node_name << endl;
        // }

        if(current_node == NULL){
            node* new_node = new node;

            new_node->name = nodes[count];
            root->childes.push_back(new_node);

            // cout << (root.childes[0])->name;

            push_node(nodes, count + 1, max, new_node);
        }else{
            push_node(nodes, count + 1, max, current_node);
        }

    }
}

void sort_node(node* root){

    if(root->childes.size() > 0){
        sort(root->childes.begin(), root->childes.end(), comp);
        // cout << root->childes.size();

        for(auto it : root->childes){
            sort_node(it);
        }
    }
}

void print_node(node* root, int depth){

    for(int i = 0; i < depth; i++){
            cout << "--";
        }
        cout << root->name << '\n';
        for(auto it : root->childes){
            print_node(it, depth + 1);
        }
}

int main(void){

    int N;
    int K;
    string tmp;
    node* root = new node;
    vector<char> commands[1005];

    root->name = "root";

    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> K;
        vector<string> nodes;


        for(int j = 0; j < K; j++){
            cin >> tmp;
            nodes.push_back(tmp);
        }

        push_node(nodes, 0, K, root);
    }

    //sort node
    sort_node(root);

    for(auto it : root->childes){
        //print
        print_node(it, 0);
    }

    return 0;

}
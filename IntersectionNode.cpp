#include <iostream>

struct node {
    int data;
    node* next;
    bool visited;
    
    node(const int& x) : data(x), next(nullptr), visited(false) {}
};

bool IntersectionNode1(node* head_a, node* head_b, int& intersection_node) {
    for (node* cur_a = head_a; cur_a; cur_a = cur_a->next)
        for (node* cur_b = head_b; cur_b; cur_b = cur_b->next)
            if (cur_a->data == cur_b->data) {
                intersection_node = cur_a->data;
                return true;
            }
    return false;
}

bool IntersectionNode2(node*& head_a, node*& head_b, int& intersection_node) {
    for (node* cur = head_a; cur; cur = cur->next)
        cur->visited = true;
    
    for (node* cur = head_b; cur; cur = cur->next)
        if (cur->visited) {
            intersection_node = cur->data;
            return true;
        }
    
    return false;
}

bool IntersectionNode3(node* head_a, node* head_b, int& intersection_node) {
    int len_a = 0, len_b = 0;
    node* cur_a = head_a, * cur_b = head_b;
    for (; cur_a; cur_a = cur_a->next)
        ++len_a;
    for (; cur_b; cur_b = cur_b->next)
        ++len_b;
    
    cur_a = head_a;
    cur_b = head_b;
    if (len_a > len_b)
        for (int i = 0; i < abs(len_a - len_b); ++i)
            cur_a = cur_a->next;
    else
        for (int i = 0; i < abs(len_a - len_b); ++i)
            cur_b = cur_b->next;
    
    while (cur_a) {
        if (cur_a->data == cur_b->data) {
            intersection_node = cur_a->data;
            return true;
        }
        cur_a = cur_a->next;
        cur_b = cur_b->next;
    }
            
    return false;
}

int main() {
    // list A: 1 2 3 4 5
    // list B: 9 4 5
    node* head_a = nullptr, * head_b = nullptr, * cur_a = head_a, * cur_b = head_b;
    node* node1 = new node(1);
    node* node2 = new node(2);
    node* node3 = new node(3);
    node* node4 = new node(4);
    node* node5 = new node(5);
    node* node9 = new node(9);
    head_a = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    head_b = node9;
    node9->next = node4;
    
    cur_a = head_a;
    while (cur_a) {
        std::cout << cur_a->data << " ";
        cur_a = cur_a->next;
    }
    std::cout << std::endl;
    cur_b = head_b;
    while (cur_b) {
        std::cout << cur_b->data << " ";
        cur_b = cur_b->next;
    }
    std::cout << std::endl;
    
    // Use 2 nested for loops
    // The time complexity of this method will be O(mn)
    int intersection_node = 0;
    if (IntersectionNode1(head_a, head_b, intersection_node))
        std::cout << intersection_node << std:: endl;
    
    // Mark Visited Nodes
    // This solution works in O(m+n) but requires additional information with each node
    intersection_node = 0;
    if (IntersectionNode2(head_a, head_b, intersection_node))
        std::cout << intersection_node << std::endl;
    
    // Get the difference of counts d = abs(c1 – c2)
    // Traverse the bigger list from the first node till d nodes
    // Traverse both the lists in parallel till we come across a common node
    intersection_node = 0;
    if (IntersectionNode3(head_a, head_b, intersection_node))
        std::cout << intersection_node << std::endl;
    
    cur_a = head_a;
    while (head_a) {
        head_a = head_a->next;
        delete cur_a;
        cur_a = head_a;
    }
    delete head_b;
}

/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <tuple>
using namespace std;

struct Node {
    int value;
    Node *next;
    Node (int v, Node *n = NULL) : value(v), next(n) {}
};


std::tuple<Node *, int> sumLists(Node *num1, Node *num2) {
    if (num1 == NULL) return std::make_tuple((Node *)NULL, 0);
    
    auto prev = sumLists(num1->next, num2->next);
    int sum = num1->value + num2->value + std::get<1>(prev);
    return std::make_tuple(new Node(sum % 10, std::get<0>(prev)), sum / 10);
}

Node * sumList2(Node *l1, Node *l2, int &carry) {
    if (l1 == NULL) return NULL;
    Node *res = sumList(l1->next, l2->next, carry);
    
    int totalSum = l1->value + l2->value + carry;
    carry = totalSum / 10;
    
    return new Node(totalSum % 10, res);
}

int main()
{
    Node *head1 = new Node(3, new Node(2, new Node(1)));
    Node *head2 = new Node(4, new Node(5, new Node(9)));
    
    Node *sum = get<0>(sumLists(head1, head2));
    while (NULL != sum) {
        cout << sum->value << " ";
        sum = sum->next;
    }
    
    return 0;
}

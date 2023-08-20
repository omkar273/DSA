
//   Definition for singly-linked list.

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//     long long int i1 = 0;
//     long long int i2 = 0;
//     int productFactor = 1;
//     long long int result = 0, remainder;
//     ListNode* temp1 = l1;
//     ListNode* temp2 = l2;

//     while (temp1 != nullptr || temp2 != nullptr) {
//         if (temp1 != nullptr) {
//             i1 += temp1->val * productFactor;
//             temp1 = temp1->next;
//         }
//         if (temp2 != nullptr) {
//             i2 += temp2->val * productFactor;
//             temp2 = temp2->next;
//         }
//         productFactor *= 10;
//     }

//     result = i1 + i2;
//     ListNode* ans = new ListNode();
//     ListNode* current = ans;

//     do {
//         remainder = result % 10;
//         result /= 10;
//         cout << remainder << endl;
//         current->next = new ListNode(remainder);
//         current = current->next;
//     } while (result != 0);
//     return ans->next;
// }

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
}
int main() {
    ListNode* l1 = new ListNode(4);
    ListNode* l2 = new ListNode(6, l1);
    ListNode* l3 = new ListNode(5, l2);

    ListNode* l4 = new ListNode(3);
    ListNode* l5 = new ListNode(4, l4);
    ListNode* l6 = new ListNode(2, l5);
    ListNode* ans = addTwoNumbers(l3, l6);

    while (ans != NULL) {
        cout << ans->val;
        ans = ans->next;
    }

    return 0;
}

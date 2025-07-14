/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
// You don’t actually need to build a decimal from Binary digits, because you can build it bit by bit as you traverse the linked list.
//  (((bit1 * 2 + bit2) * 2 + bit3) * 2 + bit4)...    This process is equivalent to parsing a binary string from left to right.

    int getDecimalValue(ListNode* head) {
        int ans = 0;
        while (head) {
            ans = ans * 2 + head->val; // This shifts all previous bits left by 1 and adds the current bit.
            head = head->next;
        }
        return ans;
    }
};

/*

int arr[] = {1, 0, 1}; // binary: 101
int ans = 0;
for (int i = 0; i < 3; i++) {
    ans = ans * 2 + arr[i];
}
// ans == 5

*/


/*

string intToBinary(int n) {
    if (n == 0) return "0";

    string res = "";
    while (n > 0) {
        res = char('0' + (n % 2)) + res;  // OR  res = to_string(n % 2) + res;
        n /= 2;
    }
    return res;
}
//OR
string intToBinary(int n) {
    if (n == 0) return "0";

    string res = "";
    while (n > 0) {
        res = res + char('0' + (n % 2));
        n /= 2;
    }
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    int n = 5;
    string binary = intToBinary(n);
    cout << "Binary representation: " << binary << endl; // Output: 101
}

*/
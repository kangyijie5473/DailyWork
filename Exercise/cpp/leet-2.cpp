/*
 * > File Name: leet-2.cpp
 * > Author: Jack Kang
 * > Mail: kangyijie@xiyoulinux.org
 * > Created Time: 2017年05月25日 星期四 09时48分08秒
 */

#
#include <iostream>  
#include <cstdlib>  
using namespace std;
  
struct ListNode {  
    int val;  
    ListNode *next;  
    ListNode(int x) : val(x), next(nullptr) {}  
};  
/*
  
class Solution {  
public :  
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {  
          
        ListNode *pTemp1 = l1, *pTemp2 = l2, *pTemp3;  
        int sum = 0, carry = 0, val;  
          
        while (pTemp1 != nullptr && pTemp2 != nullptr) {  
            sum = pTemp1->val + pTemp2->val;  
            val = sum % 10;  
            if (result) {  
                pTemp3->next = new ListNode((val + carry) % 10);  
                carry = (val + carry) / 10;  
                pTemp3 = pTemp3->next;  
            } else {  
                result = new ListNode((val + carry) % 10);  
                carry = (val + carry) / 10;  
                pTemp3 = result;  
            }  
            carry += sum / 10;  
            pTemp1 = pTemp1->next;  
            pTemp2 = pTemp2->next;  
        }  
          
        while (pTemp1) {  
            pTemp3->next = new ListNode((pTemp1->val + carry) % 10);  
            carry = (pTemp1->val + carry) / 10;  
            pTemp1 = pTemp1->next;  
            pTemp3 = pTemp3->next;  
        }  
          
        while (pTemp2) {  
            pTemp3->next = new ListNode((pTemp2->val + carry) % 10);  
            carry = (pTemp2->val + carry) / 10;  
            pTemp2 = pTemp2->next;  
            pTemp3 = pTemp3->next;  
        }  
          
        if (carry) {  
            pTemp3->next = new ListNode(carry);  
        }  
          
        return result;  
    }  
private :  
    ListNode *result = nullptr;  
};  
*/  
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int temp_sum = 0;
        int temp_add = 0;
        ListNode *pre  = nullptr;
        ListNode *head = nullptr;
        while(l1 && l2){
            temp_sum = l1->val + l2->val + temp_add;
            cout << temp_sum << endl;
            l1 = l1->next;
            l2 = l2->next;
            
            if(pre == nullptr){
                pre = new ListNode(temp_sum % 10);
                head = pre;
            }else{
                pre->next = new ListNode(temp_sum % 10);
                pre = pre->next;
            } 
            temp_add = temp_sum / 10;
        }
        if(l1){
            while(l1){
                pre->next = new ListNode((l1->val + temp_add)%10);
                temp_add = (l1->val + temp_add)/10;
                pre = pre->next;
                l1 = l1->next;
            }
        }else if(l2){
            while(l2){
            pre->next = new ListNode((l2->val + temp_add)%10);
            temp_add = (l2->val + temp_add)/10;
            pre = pre->next;
            l2 = l2->next;
            }
        }
        if(temp_add)
            pre->next = new ListNode(temp_add);
        return head;
    }
};
int main(int argc, char *argv[])  
{  
    Solution s;  
    ListNode *l1 = new ListNode(1);
    l1->next = new ListNode(9);
    ListNode *l2 = new ListNode(1);  
    l2->next = new ListNode(9);  
  
    ListNode *l3 = s.addTwoNumbers(l1, l2);  
      
    for (ListNode *p = l3; p != nullptr; p = p->next) {  
        std::cout << p->val << " ";  
    }  
    std::cout << std::endl;  
      
    return EXIT_SUCCESS;  
}

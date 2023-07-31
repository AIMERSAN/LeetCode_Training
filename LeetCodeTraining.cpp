#include <unordered_set>


struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
        ListNode* head = nullptr, *tail = nullptr;
        int carry = 0;
        while(l1 || l2){
            int n1 = l1 ? l1->val : 0;
            int n2 = l2 ? l2->val : 0;
            int sum = n1 + n2 + carry;
            if(!head){
                head = tail = new ListNode(sum % 10);
            }else{
                tail->next = new ListNode(sum % 10);
                tail = tail->next;
            }
            carry = sum / 10;
            if(l1){
                l1 = l1->next;
            }
            if(l2){
                l2 = l2->next;
            }
        }
        if(carry > 0){
            tail->next = new ListNode(carry);
        }
        return head;
    }
};

/********2023 07 22**********/
class Solution{
public:
    int lengthOfLongestSubstring(string s){
        if(s.size() == 0) return 0;
        unordered_set<char> lookup;
        int maxStr = 0;
        int left = 0;
        for(int i = 0; i < s.size(); i++)
        {
			while(lookup.find(s[i]) != lookup.end())
			{
				lookup.erase(s[left]);
				left++;
			}
			maxStr = max(maxStr, i - left + 1);
			lookup.insert(s[i]);
        }
		return maxStr;
    }
	
	int lengthOfLongestSubstring1(string s)
	{
		vector<int> m(128, 0);
		int maxlen = 0;
		int head = 0;
		for(int i = 0; i < s.size(); i++)
		{
			head = max(head, m[s[i]]);
			
			m[s[i]] = i + 1;
			
			maxlen = max(maxlen, i - head + 1);
		}
		return maxlen;
	}
};

class Solution{
private:
	unordered_map<char, int> symbolValues = {
		{'I' , 1}
		{'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000},
	};
	
public:
	int romanToInit(string s)
	{
		int sum = 0;
		int preNum = symbolValues[s[0]];
		for(int i = 1; i < s.length(); i++)
		{	
			int num = symbolValues[s[i]];
			if(preNum < num)
			{
				sum -= preNum;
			}
			else
			{
				sum += preNum;
			}
			preNum = num;
		}
		sum += preNum;
		return sum;
	}
	
}

static int getValue(char ch)
{
	switch(ch)
	{
		case 'I': return 1;
		case 'V': return 5;
		case 'X': return 10;
		case 'L': return 50;
		case 'C': return 100;
		case 'D': return 500;
		case 'M'：return 1000;
		default: return 0;
	}
}


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
    ListNode* deleteDuplicates(ListNode* head) {
		// 判断链表头节点是否为空以及判断链表节点个数是否为1
		if(head || !head->next)
		{
			return head;
		}
		// 如果头节点和其下一个节点不相等的话，进行递归，继续对头节点的下一个节点进行处理
		if(head->val != head->next->val)
		{
			head->next = deleteDuplicates(head->next);
		}
		// 如果头节点和其下一个节点相等的话，将二者都删除，然后声明一个move指向头节点的下一节点，
		else
		{
			ListNode* move = head->next;
			// 如果move不为空，并且与头节点的值相等，将move指向其当前节点的下一个节点，再对move执行递归处理
			while(move && (head->val == move->val))
			{
				move = move->next;
			}
			return deleteDuplicates(move);
		}
		return head;
    }
};

/*******************2023 07 29********************/
class Solution{
public:
	bool hasCycle(ListNode *head)
	{
		unordered_set<ListNode*> seen;
		while(head != null)
		{
			if(seen.count(head))
			{
				return true;
			}
			seen.insert(head);
			head = head->next;
		}
		return false;
	}
};

class Solution{
public:
	bool hasCycle(ListNode* head)
	{
		if(head == nullptr || head.next == null){
			return false;
		}
		ListNode* slow = head;
		ListNode* fast = head.next;
		while(slow != fast){
			if(fast == nullptr || fast->next == nullptr){
				return false;
			}
			slow = slow->next;
			fast = fast->next->next;
		}
		return true;
	}
};
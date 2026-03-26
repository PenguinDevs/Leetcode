/*
 * @lc app=leetcode id=138 lang=cpp
 *
 * [138] Copy List with Random Pointer
 */

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;

        Node* currNode {head};
        while (currNode != nullptr) {
            Node* nextOriginal = currNode->next;
            currNode->next = new Node(currNode->val);
            currNode->next->next = nextOriginal;

            currNode = nextOriginal;
        }

        currNode = head;
        while (currNode != nullptr) {
            Node* originalNode {currNode};
            Node* copyNode {currNode->next};
            
            if (originalNode->random != nullptr) {
                copyNode->random = originalNode->random->next;
            }
            
            currNode = currNode->next->next;
        }
        
        Node* copyRoot {head->next};
        Node* currCopy {copyRoot}; 
        currNode = head;
        while (currNode != nullptr) {
            Node* nextOriginal {currNode->next->next};
            Node* copyNode {currNode->next};
            
            if (copyNode != copyRoot) {
                currCopy->next = copyNode;
                currCopy = copyNode;
            }
            
            currNode->next = nextOriginal;
            currNode = nextOriginal;
        }

        // cout << copyRoot;
        // cout << copyRoot->next;

        return copyRoot;
    }
// public:
//     Node* copyRandomList(Node* head) {
//         if (head == nullptr) return nullptr;
        
//         Node* copyRoot = new Node(head->val);

//         vector<Node*> copyOrder;
//         unordered_map<Node*, int> originalNodeToIdx;

//         Node* currCopy {copyRoot};
//         Node* currOriginal {head->next};
//         copyOrder.push_back(currCopy);
//         originalNodeToIdx[head] = originalNodeToIdx.size();
//         while (currOriginal != nullptr) {
//             Node* newNode = new Node(currOriginal->val);
//             currCopy->next = newNode;
//             currCopy = newNode;
//             copyOrder.push_back(newNode);
            
//             originalNodeToIdx[currOriginal] = originalNodeToIdx.size();
//             currOriginal = currOriginal->next;
//         }

//         int i {0};
//         currOriginal = head;
//         while (currOriginal != nullptr) {
//             if (currOriginal->random != nullptr) {
//                 // cout << originalNodeToIdx[currOriginal] << '\n';
//                 // cout << originalNodeToIdx[currOriginal->random] << '\n';
//                 // cout << "size is " << copyOrder.size() << '\n';

//                 copyOrder[originalNodeToIdx[currOriginal]]->random = copyOrder[originalNodeToIdx[currOriginal->random]];
//             } 
//             currOriginal = currOriginal->next;
//             ++i;
//         }

//         return copyRoot;
//     }
};
// @lc code=end


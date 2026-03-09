/*
 * @lc app=leetcode id=2296 lang=cpp
 *
 * [2296] Design a Text Editor
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
struct Node {
    char c;
    bool isRoot;
    Node* prev;
    Node* next;
};

class TextEditor {
public:
    Node* root {nullptr};
    Node* cursor {nullptr};

    TextEditor() {
        root = new Node();
        root->isRoot = true;
        cursor = root;
    }
    
    void addText(string text) {
        // cout << "adding " << text << '\n';
        Node* head = new Node(text[0]);
        Node* tail = head;
        for (int i {1}; i < text.size(); ++i) {
            Node* newNode = new Node(text[i]);
            bind(tail, newNode);
            tail = tail->next;
        }
    
        // if (cursor == nullptr) {
        //     root = head;
        // } else {
            Node* leftChar = cursor;
            Node* rightChar = leftChar->next; // Can be nullptr

            bind(leftChar, head);
            bind(tail, rightChar);
        // }
        cursor = tail;
    }
    
    int deleteText(int k) {
        // cout << "deleting " << k << '\n';
        int deleteCount {0};

        Node* curr = cursor;
        Node* rightChar = curr->next;

        while (deleteCount < k && !curr->isRoot) {
            Node* oldNode = curr;
            curr = curr->prev;
            delete oldNode;

            ++deleteCount;
        }

        bind(curr, rightChar);

        // if (curr == nullptr) {
        //     root = rightChar;
        //     cursor = root;
        // } else {
            cursor = curr;
        // }

        return deleteCount;
    }
    
    string cursorLeft(const int k) {
        // cout << "move left " << k << '\n';
        traverse(k, false);
        return read(10);
    }
    
    string cursorRight(const int k) {
        // cout << "move right " << k << '\n';
        traverse(k, true);
        return read(10);
    }
private:
    void bind(Node* before, Node* after) {
        if (before == nullptr) {
            after->prev = nullptr;
            return;
        }
        if (after == nullptr) {
            before->next = nullptr;
            return;
        }
        // cout << "bind " << (before->c) << " " << (after->c) << '\n';
        after->prev = before;
        before->next = after;
    }

    void traverse(
        const int k,
        bool traverseRight = true
    ) {
        if (cursor == nullptr) return;
        int traverseCount {0};

        Node *curr = cursor;
        while (traverseCount < k && curr != nullptr) {
            cursor = curr;
            if (traverseRight) {
                curr = curr->next;
            } else {
                // cout << (curr->c);
                curr = curr->prev;
            }

            ++traverseCount;
            
            if (curr == nullptr || curr->isRoot) break;
        }
        // cout << '\n';

        if (curr != nullptr) cursor = curr;
    }

    string read(
        const int k
    ) {
        if (cursor == nullptr) return "";
        string accumulated {};

        int traverseCount {0};

        Node *curr = cursor;
        while (traverseCount < k && curr != nullptr && !curr->isRoot) {
            accumulated = curr->c + accumulated;
            // cout << accumulated << '\n';
            curr = curr->prev;

            ++traverseCount;
        }

        return accumulated;
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */
// @lc code=end


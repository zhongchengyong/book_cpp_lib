//
// Created by 钟乘永 on 2019-08-17.
//

#include "chapter3_base.h"
#include <stack>
#include <iostream>
#include <exception>


BinaryTree *ReconstructTree(int *pre_order_begin, int *pre_order_end, int *in_order_begin, int *in_order_end);

void ReversePrintList(ListNode *head) {
    std::stack<int> values;
    while (head->next != nullptr) {
        values.push(head->value);
        head = head->next;
    }
    int data;
    while (values.empty()) {
        data = values.top();
        std::cout << data << "\t";
        values.pop();
    }
}

BinaryTree *Reconstruct(int *pre_order, int *mid_order, int length) {
    if (pre_order == nullptr || mid_order == nullptr || length <= 0) {
        return nullptr;
    }
    return ReconstructTree(pre_order, pre_order + length - 1,
                           mid_order, mid_order + length - 1);
}

BinaryTree *ReconstructTree(int *pre_order_begin, int *pre_order_end, int *in_order_begin, int *in_order_end) {
    int root_value = pre_order_begin[0];
    auto *root = new BinaryTree();
    root->value = root_value;
    root->left = root->right = nullptr;
    if (pre_order_begin == pre_order_end) {
        if (in_order_begin == in_order_end && *in_order_begin == *in_order_end) {
            return root;
        } else {
            throw std::invalid_argument("Invalid input");
        }
    }

    int *in_order_root = in_order_begin;
    while (in_order_root <= in_order_end && *in_order_root != root_value) {
        in_order_root++;
    }
    int left_length = in_order_root - in_order_begin;
    if (in_order_root > in_order_begin) {
        root->left = ReconstructTree(pre_order_begin + 1, pre_order_begin + left_length, in_order_begin,
                                     in_order_root - 1);
    }
    if (left_length < pre_order_end - pre_order_begin) {
        root->right = ReconstructTree(pre_order_begin + left_length + 1, pre_order_end, in_order_root + 1,
                                      in_order_end);
    }
    return root;
}


void QuickSort(int arr[], int start, int end) {
    int i = start, j = end;
    int pivot = arr[start];
    if (i < j) {
        while (i < j) {
            // 一遍交替数字
            while (i < j && arr[j] > pivot) j--;
            if (i < j) arr[i++] = arr[j];
            while (i < j && arr[i] < pivot) i++;
            if (i < j) arr[j--] = arr[i];
        }
        // 将pivot放在正确位置
        arr[i] = pivot;

        // 递归
        QuickSort(arr, 0, i - 1);
        QuickSort(arr, i + 1, end);
    }
}

void SortAge(int arr[], int length) {
    if (arr == nullptr || length <= 0) {
        throw std::invalid_argument("array is empty");
    }
    constexpr int OLDEST_AGE = 100;
    int age_count[OLDEST_AGE];
    int age;
    for (int i = 0; i < length; i++) {
        age = arr[i];
        ++age_count[age];
    }
    int index = 0;
    for (int i = 0; i < OLDEST_AGE; i++) {
        for (int j = 0; j < age_count[i]; j++) {
            arr[index++] = i;
        }
    }
}


int FindLeastNumber(vector<int> arr) {
    for (size_t i = 1; i < arr.size(); i++) {
        if (arr[i - 1] > arr[i]) return arr[i];
    }
    return arr[0];
}

/**
 * n-1 & n将最右边的1修改为0
 * */
int NumberOf1(int n) {
    int count = 0;
    while (n) {
        n = (n - 1) & n;
        ++count;
    }
    return count;
}

void ReorderOddEven(int *p_data, size_t length) {
    int *start = p_data;
    int *end = p_data + length - 1;
    while (start < end) {
        while (start < end && (*start & 0x1) == 1) start++;
        while (start < end && (*end & 0x1) != 1) end--;
        if(start < end){
            int temp = *start;
            *start = *end;
            *end = temp;
        }
    }
}

void ReorderOddEven(int *p_data, size_t length, bool (*func)(int)) {
    int *start = p_data;
    int *end = p_data + length - 1;
    while (start < end) {
        while (start < end && !func(*start)) start++;
        while (start < end && func(*end)) end--;
        if(start < end){
            int temp = *start;
            *start = *end;
            *end = temp;
        }
    }
}

ListNode *FindKthNode(ListNode *head, unsigned int k) {
    if(k == 0 || head == nullptr) throw std::invalid_argument("Invalid k");
    ListNode* forward = head;
    for(unsigned int i = 1; i < k; ++i){
        if(forward->next != nullptr){
            forward = forward->next;
        }else{
            // No enough nodes
            return nullptr;
        }
    }
    ListNode* behind = head;
    while(forward->next != nullptr){
        forward = forward->next;
        behind = behind->next;
    }
    return behind;
}

ListNode* Merge(ListNode* first, ListNode* second){
    if(first == nullptr) return second;
    if(second == nullptr) return first;
    ListNode* merge = nullptr;
    if(first->value < second->value){
        merge = first;
        merge->next = Merge(first->next, second);
    }else{
        merge = second;
        merge->next = Merge(first, second->next);
    }
    return merge;
}

bool CheckSubNodeEqual(BinaryTree* first, BinaryTree* second);
bool HasSubtree(BinaryTree* first, BinaryTree* second){
    if(first == nullptr) return false;
    if(second == nullptr) return true;
    if(first->value == second->value){
        return CheckSubNodeEqual(first->left, second->left) && CheckSubNodeEqual(first->right, second->right);
    }else{
        return HasSubtree(first->left, second) || HasSubtree(first->right, second);
    }
}

bool CheckSubNodeEqual(BinaryTree* first, BinaryTree* second){
    if(second == nullptr) return true;
    if(first == nullptr) return false;
    if(first->value == second->value){
        return CheckSubNodeEqual(first->left, second->left) && CheckSubNodeEqual(first->right, second->right);
    }
    return false;
}

void MirrorBinaryTree(BinaryTree* tree){
    if(tree == nullptr || (tree->left == nullptr && tree->right == nullptr)){
        return;
    }
    BinaryTree* temp  = tree->left;
    tree->left = tree->right;
    tree->right = temp;
    if(tree->left) MirrorBinaryTree(tree->left);
    if(tree->right) MirrorBinaryTree(tree->right);
}

bool IsPopOrder(const int* push, const int* pop, int length){
    std::stack<int> st;
    int idx = 0, pop_idx = 0;
    while(idx < length){
        if(st.empty() || (st.top() != *pop)){
            st.push(*push);
            push++;
            idx++;
        }else{
            st.pop();
            pop++;
            pop_idx++;
        }
    }
    while(!st.empty()){
        if(st.top() != *pop){
            return false;
        }else{
            pop++;
            pop_idx++;
            st.pop();
        }
    }
    return pop_idx == length;
}


void PrintTopToBottom(BinaryTree* root){
    if(root != nullptr){
        std::deque<BinaryTree*> tree_deque;
        tree_deque.push_back(root);
        while(!tree_deque.empty()){
            BinaryTree* node = tree_deque.front();
            std::cout << node->value << " ";
            tree_deque.pop_front();
            if(node->left) tree_deque.push_back(node->left);
            if(node->right) tree_deque.push_back(node->right);
        }
    }
}
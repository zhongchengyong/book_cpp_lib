//
// Created by 钟乘永 on 2019-08-17.
//

#include "chapter3_base.h"
#include <stack>
#include <iostream>
#include <exception>


BinaryTree *ReconstructTree(int *pre_order_begin, int *pre_order_end, int *in_order_begin, int *in_order_end);

void ReversePrintList(ListNode* head){
    std::stack<int> values;
    while (head->next != nullptr){
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
    if(pre_order == nullptr || mid_order == nullptr || length <= 0){
        return nullptr;
    }
    return ReconstructTree(pre_order, pre_order + length -1,
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
        }else{
            throw std::invalid_argument("Invalid input");
        }
    }

    int* in_order_root = in_order_begin;
    while(in_order_root <= in_order_end && *in_order_root != root_value){
        in_order_root++;
    }
    int left_length = in_order_root - in_order_begin;
    if (in_order_root > in_order_begin) {
        root->left = ReconstructTree(pre_order_begin + 1, pre_order_begin + left_length , in_order_begin, in_order_root - 1);
    }
    if(left_length < pre_order_end - pre_order_begin){
        root->right = ReconstructTree(pre_order_begin + left_length + 1, pre_order_end, in_order_root + 1, in_order_end);
    }
    return root;
}


void QuickSort(int arr[], int start, int end){
    int i = start, j = end;
    int pivot = arr[start];
    if(i < j){
        while(i < j){
            // 一遍交替数字
            while(i < j && arr[j] > pivot) j--;
            if(i < j) arr[i++] = arr[j]; 
            while(i < j && arr[i] < pivot) i++;
            if(i < j) arr[j--] = arr[i];
        }
        // 将pivot放在正确位置
        arr[i] = pivot;
        
        // 递归
        QuickSort(arr, 0, i - 1);
        QuickSort(arr, i + 1, end);
    }
}

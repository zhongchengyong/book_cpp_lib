//
// Created by 钟乘永 on 2019-08-17.
//

#include "chapter3_base.h"
#include <stack>
#include <iostream>


BinaryTree *ReconstructTree(int *pInt, int *pInt1, int *order, int *pInt2);

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

BinaryTree *ReconstructTree(int *pInt, int *pInt1, int *order, int *pInt2) {
    return nullptr;
}

//
// Created by 钟乘永 on 2019-08-17.
//

#ifndef CPPLIB_CHAPTER3_BASE_H
#define CPPLIB_CHAPTER3_BASE_H

struct ListNode{
    int value;
    ListNode* next;
};

struct BinaryTree{
    int value;
    BinaryTree* left;
    BinaryTree* right;
};

/**
 * 反向输出链表
 * 解法1：使用栈输出数据
 * 解法2：使用递归输出数据
 * @param head
 */
void ReversePrintList(ListNode* head);

BinaryTree* Reconstruct(int* pre_order, int* mid_order, int length);

void QuickSort(int arr[], int start, int end);


#endif //CPPLIB_CHAPTER3_BASE_H

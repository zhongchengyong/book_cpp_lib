//
// Created by 钟乘永 on 2019-08-17.
//

#ifndef CPPLIB_CHAPTER3_BASE_H
#define CPPLIB_CHAPTER3_BASE_H

#include <vector>

using namespace std;

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

void SortAge(int arr[], int length);

int FindLeastNumber(vector<int> arr);

int NumberOf1(int n);

void ReorderOddEven(int* p_data, size_t length);

/*
 * 使用函数指针，这样函数可扩展性更强
 */
void ReorderOddEven(int* p_data, size_t length, bool (*func)(int));

ListNode* FindKthNode(ListNode* head, unsigned int k);

ListNode* Merge(ListNode* first, ListNode* second);

bool HasSubtree(BinaryTree* first, BinaryTree* second);

void MirrorBinaryTree(BinaryTree* tree);

/*
 * 包含min函数的栈实现
*/
// template<typename T>
// class StackWithMin{
// public:
//     void push(const T& value);
//     void pop();
//     T& min() const();
// };

bool IsPopOrder(const int* push, const int* pop, int length);

/// 基于deque来实现二叉树的遍历
void PrintTopToBottom(BinaryTree* root);

bool VerifySquenceOfBST(int sequence[], int length);
#endif //CPPLIB_CHAPTER3_BASE_H

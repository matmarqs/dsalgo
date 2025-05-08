struct ListNode {
    int val;
    struct ListNode *next;
};

/**************************/

#include <stdlib.h>

#define MAX (10001)

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    struct ListNode *root = NULL;
    int min = MAX;
    int index = -1;

    for (int i = 0; i < listsSize; i++) {
        if (lists[i] && lists[i]->val < min) {
            min = lists[i]->val;
            index = i;
        }
    }

    if (min == MAX) {
        return NULL;
    }
    else {
        root = lists[index];
        lists[index] = lists[index]->next;
    }

    struct ListNode *node = root;

    while (min != MAX) {
        min = MAX;

        for (int i = 0; i < listsSize; i++) {
            if (lists[i] && lists[i]->val < min) {
                min = lists[i]->val;
                index = i;
            }
        }

        if (min != MAX) {
            node->next = lists[index];
            node = node->next;
            lists[index] = lists[index]->next;
        }
    }

    return root;
}

/**************************/

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    if (list1 && !list2) {
        return list1;
    }
    else if (!list1 && list2) {
        return list2;
    }
    else if (!list1 && !list2) {
        return NULL;
    }
    else {
        struct ListNode* root;
        if (list1->val < list2->val) {
            root = list1;
            list1 = list1->next;
        }
        else {
            root = list2;
            list2 = list2->next;
        }
        struct ListNode* node = root;
        while (list1 && list2) {
            if (list1->val < list2->val) {
                node->next = list1;
                node = node->next;
                list1 = list1->next;
            }
            else {
                node->next = list2;
                node = node->next;
                list2 = list2->next;
            }
        }
        if (list1) {
            node->next = list1;
            return root;
        }
        else {
            node->next = list2;
            return root;
        }
    }
}

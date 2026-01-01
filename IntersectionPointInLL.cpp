/*Intersection in Y Shaped Lists

You are given the heads of two non-empty singly linked lists, head1 and head2, that intersect at a certain point. Return that Node where these two linked lists intersect.

Note: It is guaranteed that the intersected node always exists.

In the custom input you have to give input for CommonList which pointed at the end of both head1 and head2 to form a Y-shaped linked list.
Examples:

Input: head1: 10 -> 15 -> 30, head2: 3 -> 6 -> 9 -> 15 -> 30
Output: 15
Explanation: From the above image, it is clearly seen that the common part is 15 -> 30, whose starting point is 15.

Input: head1: 4 -> 1 -> 8 -> 5, head2: 5 -> 6 -> 1 -> 8 -> 5
Output: 1
Explanation: From the above image, it is clearly seen that the common part is 1 -> 8 -> 5, whose starting point is 1.

Constraints:
2 ≤ total number of nodes ≤ 2*105
-104 ≤ node->data ≤ 104

*/
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

class Solution
{
public:
    // function to get the count of nodes in a linked list
    int getCount(Node *head)
    {
        int cnt = 0;
        Node *curr = head;
        while (curr != nullptr)
        {
            cnt++;
            curr = curr->next;
        }
        return cnt;
    }

    // function to get the intersection point of two
    // linked lists where head1 has d more nodes than head2
    Node *getIntersectionByDiff(int diff, Node *head1, Node *head2)
    {
        Node *curr1 = head1;
        Node *curr2 = head2;

        // move the pointer forward by d nodes
        for (int i = 0; i < diff; i++)
        {
            if (curr1 == nullptr)
                return nullptr;
            curr1 = curr1->next;
        }

        // move both pointers until they intersect
        while (curr1 != nullptr && curr2 != nullptr)
        {
            if (curr1 == curr2)
                return curr1;
            curr1 = curr1->next;
            curr2 = curr2->next;
        }

        return nullptr;
    }

    // function to get the intersection point of two linked lists
    Node *intersectPoint(Node *head1, Node *head2)
    {

        // count the number of nodes in both linked lists
        int len1 = getCount(head1);
        int len2 = getCount(head2);

        int diff = 0;

        // if the first list is longer
        if (len1 > len2)
        {
            diff = len1 - len2;
            return getIntersectionByDiff(diff, head1, head2);
        }
        else
        {
            diff = len2 - len1;
            return getIntersectionByDiff(diff, head2, head1);
        }
    }
};

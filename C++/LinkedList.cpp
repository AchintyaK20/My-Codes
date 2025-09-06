#include <iostream>
#include <unordered_set>
#define FAST_IO              \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#define ll long long
#define ld long double
#define mp make_pair
#define pb push_back
#define vi vector<int>
#define pi pair<int, int>
#define F first
#define S second
#define endl "\n"
#define umap unordered_map<int, int>
#define MOD7 1000000007
using namespace std;

// class Node
// {
// public:
//     int data;
//     Node *next;
//     Node(int d) : data(d), next(NULL) {}
//     // Node(int d)
//     // {
//     //     data = d;
//     //     next = NULL;
//     // }
// };

struct Node {
    int data;
    Node *next;
    // Node(int d) : data(d), next(NULL) {}
    Node(int d) {
        this->data = d;
        this->next = NULL;
    }
};

Node *swapkthnode(Node *head, int n, int K) {
    Node *first = head;
    int t = K;
    while (t--) {
        if (first == NULL) {
            return NULL;
        }
        first = first->next;
    }
    Node *second = head;
    while (first != NULL) {
        first = first->next;
        second = second->next;
    }
    Node *KthFromEnd = second;
    int p = 1;
    Node *temp = head;
    Node *Kth;
    while (p <= K - 1) {
        temp = temp->next;
        p++;
    }
    return KthFromEnd;
}
Node *removeDuplicatesFromUnsorted(Node *head) {
    unordered_set<int> s;
    s.insert(head->data);
    Node *temp = head;
    while (temp->next != NULL) {
        if (s.find(temp->next->data) == s.end()) {
            s.insert(temp->next->data);
            temp = temp->next;
        } else {
            temp->next = temp->next->next;
        }
    }
    return head;
}
Node *removeDuplicatesFromSorted(Node *root) {
    Node *temp = root;
    while (temp->next != NULL) {
        if (temp->data == temp->next->data) {
            while (temp->next != NULL && temp->data == temp->next->data) {
                temp->next = temp->next->next;
            }
        } else {
            temp = temp->next;
        }
    }
    return root;
}
Node *mergeSortedLists(Node *head1, Node *head2) {
    if (head1 == NULL)
        return head2;
    if (head2 == NULL)
        return head1;
    Node *newHead, *tail;
    if (head1->data < head2->data) {
        newHead = head1;
        tail = head1;
        head1 = head1->next;
    } else {
        newHead = head2;
        tail = head2;
        head2 = head2->next;
    }
    while (head1 != NULL && head2 != NULL) {
        if (head1->data < head2->data) {
            tail->next = head1;
            tail = head1;
            head1 = head1->next;
        } else {
            tail->next = head2;
            tail = head2;
            head2 = head2->next;
        }
    }
    if (head1 == NULL)
        tail->next = head2;
    else
        tail->next = head1;
    return newHead;
}
Node *swapNodesInPair(Node *head) {
    Node *curr = head->next->next;
    Node *prev = head;
    head = head->next;
    head->next = prev;
    while (curr != NULL && curr->next != NULL) {
        prev->next = curr->next;
        prev = curr;
        Node *next = curr->next->next;
        curr->next->next = curr;
        curr = next;
    }
    prev->next = curr;
    return head;
}
Node *getIntersectionNode(Node *headA, Node *headB) {
    Node *tempA = headA, *tempB = headB;
    while (1) {
        if (tempA == NULL)
            return NULL;
        if (tempB == NULL)
            return NULL;
        if (tempA == tempB) {
            return tempA;  // return tempB
        }
        if (tempA->next != NULL) {
            tempA = tempA->next;
        } else {
            tempA = headB;
        }
        if (tempB->next != NULL) {
            tempB = tempB->next;
        } else {
            tempB = headA;
        }
        if (tempA->next == NULL && tempB->next == NULL && tempA != tempB) {
            return NULL;
        }
    }
}
Node *reverse(Node *head) {
    Node *curr = head;
    Node *prev = NULL;
    while (curr != NULL) {
        Node *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
Node *reverseInTermsOfSizeK(Node *head, int k) {
    Node *curr = head, *prevFirst = head;
    bool isFirstPass = true;
    while (curr != NULL) {
        Node *first = curr;
        Node *prev = NULL;
        int count = 0;
        while (curr != NULL && count < k) {
            Node *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }
        if (isFirstPass) {
            head = prev;
            isFirstPass = false;
        } else {
            prevFirst->next = prev;
        }
        prevFirst = first;
    }
    return head;
}
Node *RecursiveReverse1(Node *head) {
    if (head == NULL || head->next == NULL)
        return head;
    Node *rest_head = RecursiveReverse1(head->next);
    Node *rest_tail = head->next;
    rest_tail->next = head;
    head->next = NULL;
    return rest_head;
}
Node *RecursiveReverse2(Node *curr, Node *prev) {
    if (curr == NULL)
        return prev;
    Node *temp = curr->next;
    curr->next = prev;
    prev = curr;
    curr = temp;
    Node *newHead = RecursiveReverse2(curr, prev);
    return newHead;
}
int nthNodefromEnd(Node *head, int n) {
    Node *first = head;
    while (n--) {
        if (first == NULL) {
            return -1;
        }
        first = first->next;
    }
    Node *second = head;
    while (first != NULL) {
        first = first->next;
        second = second->next;
    }
    return second->data;
}
int middle(Node *head) {
    Node *slow, *fast;
    slow = head;
    fast = head;
    if (head == NULL)
        return -1;
    while (1) {
        if (fast == NULL || fast->next == NULL) {
            return slow->data;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
}
int countNodesinCycle(Node *head) {
    Node *slow, *fast;
    slow = head;
    fast = head;
    while (slow != NULL && fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            break;
        }
    }
    if (slow != fast) {
        return 0;
    } else {
        fast = fast->next;
        int c = 1;
        while (fast != slow) {
            fast = fast->next;
            c++;
        }
        return c;
    }
}
bool hasCycle(Node *head) {
    Node *slow, *fast;
    slow = head;
    fast = head;
    while (slow != NULL && fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            return true;
        }
    }
    return false;
}
void removeCycle(Node *head) {
    Node *slow, *fast;
    slow = head;
    fast = head;
    while (slow != NULL && fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            break;
        }
    }
    slow = head;
    while (fast->next != slow->next) {
        slow = slow->next;
        fast = fast->next;
    }
    fast->next = NULL;
}
Node *createList(int n) {
    int i, x;
    cin >> x;
    Node *head = new Node(x);
    Node *temp = head;
    for (i = 2; i <= n; i++) {
        cin >> x;
        Node *newNode = new Node(x);
        temp->next = newNode;
        temp = temp->next;
    }
    return head;
}
void print_list(Node *head) {
    for (Node *curr = head; curr != NULL; curr = curr->next) {
        cout << curr->data << " ";
    }
    // while (n != NULL)
    // {
    // cout << n->data << " ";
    // n = n->next;
    // }
    cout << endl;
}
void pushAtFirst(Node **head_ref, int new_data) {
    Node *new_node = new Node(new_data);
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}
void SPLIT(Node *head, Node **first_half, Node **second_half) {
    Node *slow = head, *fast = head->next;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    *first_half = head;
    *second_half = slow->next;
    slow->next = NULL;
}
Node *MERGE(Node *first_half, Node *second_half) {
    if (first_half == NULL) {
        return second_half;
    }
    if (second_half == NULL) {
        return first_half;
    }
    Node *result;
    if (second_half->data < first_half->data) {
        result = second_half;
        result->next = MERGE(first_half, second_half->next);
    } else {
        result = first_half;
        result->next = MERGE(first_half->next, second_half);
    }
    return result;
}
void mergeSort(Node **head_ref) {
    Node *head = *head_ref;
    Node *first_half = NULL;
    Node *second_half = NULL;
    if (head == NULL || head->next == NULL)
        return;
    SPLIT(head, &first_half, &second_half);
    mergeSort(&first_half);
    mergeSort(&second_half);
    *head_ref = MERGE(first_half, second_half);
}
int main() {
    FAST_IO;
    int n;
    cin >> n;
    Node *head = createList(n);
    mergeSort(&head);
    print_list(head);
}
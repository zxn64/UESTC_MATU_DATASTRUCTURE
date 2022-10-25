#include <iostream>

struct ListNode {
    int n;
    ListNode *next;
};

int *solve(int N, int M, int K) {
    int *ans = new int[N - K];
    ListNode *head = new ListNode;
    head->n = 1;
    ListNode *now_node = head, *last_node = NULL;
    for (int i = 2; i <= N; ++i) {
        now_node->next = new ListNode;
        now_node = now_node->next;
        now_node->n = i;
    }
    now_node->next = head;
    last_node = now_node;
    now_node = head;
    int idx = 0;
    int cnt = 1;
    int mod = M % N;
    if (!mod) mod = N;
    while (N > K) {
        cnt %= mod;
        while (!cnt) {
            last_node->next = now_node->next;
            ans[idx++] = now_node->n;
            delete now_node;
            now_node = last_node->next;
            --N;
            if (N == K) return ans;
            mod = M % N;
            if (!mod) {
                mod = N;
            }
            cnt = 1;
            cnt %= mod;
        }
        last_node = now_node;
        now_node = now_node->next;
        ++cnt;
    }
    return ans;
}
#include <iostream>

struct BinTree {
    int val;
    BinTree *l, *r;
};

void dfs(BinTree *fa, int *outOrder, int &idx) {
    outOrder[idx++] = fa->val;
    if (fa->r) {
        dfs(fa->r, outOrder, idx);
    }
    if (fa->l) {
        dfs(fa->l, outOrder, idx);
    }
}

void find_son(int l, int r, int n, BinTree *fa, int *preOrder, int *inOrder, int &idx) {
    fa->l = fa->r = NULL;
    for (int i = n - 1; i > l; --i) {
        if (inOrder[i] == preOrder[idx]) {
            fa->l = new BinTree;
            fa->l->val = preOrder[idx];
            find_son(l, n, i, fa->l, preOrder, inOrder, ++idx);
            break;
        }
    }
    for (int i = n + 1; i < r; ++i) {
        if (inOrder[i] == preOrder[idx]) {
            fa->r = new BinTree;
            fa->r->val = preOrder[idx];
            find_son(n, r, i, fa->r, preOrder, inOrder, ++idx);
            break;
        }
    }
}

void solve(int n, int *preOrder, int *inOrder, int *outOrder) {
    BinTree *head = new BinTree;
    int idx = 0;
    head->val = preOrder[idx];
    for (int i = 0; i < n; ++i) {
        if (inOrder[i] == preOrder[idx]) {
            find_son(-1, n, i, head, preOrder, inOrder, ++idx);
            break;
        }
    }
    idx = 0;
    dfs(head,outOrder,idx);
}

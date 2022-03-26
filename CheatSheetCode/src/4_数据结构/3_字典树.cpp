struct Node {
    char c;
    Node* next[26];
    Node(char cc) {
        c = cc;
        REP(i, 26)next[i] = NULL;
    }
    ~Node() {
        REP(i, 26) if (next[i] != NULL) {
            next[i]->~Node();
            delete next[i];
            next[i] = NULL;
        }
    }
    bool empty() {
        REP(i, 26)if (next[i])return 0;
        return 1;
    }
};

class Trie {
public:
    Node *rt;
    Trie() {
        rt = new Node('*');
    }
    ~Trie() {
        rt->~Node();
    }
    void insert(char s[]) {
        Node *p = rt;
        for (int i = 0; s[i]; i++) {
            int d = s[i] - 'A';
            if (!p->next[d])
                p->next[d] = new Node(s[i]);
            p = p->next[d];
        }
    }
    int find(char s[]) {
        Node *p = rt;
        for (int i = 0; s[i]; i++) {
            int d = s[i] - 'A';
            if (!p->next[d]) return 0;
            p = p->next[d];
        }
        return 1;
    }
    void remove(char s[]) {
        stack<Node*> st;
        Node *pp = rt;
        for (int i = 0; s[i]; i++) {
            int d = s[i] - 'A';
            if (!pp->next[d]) return;
            st.push(pp);
            pp = pp->next[d];
        }
        pp->~Node();
        while (!st.empty()) {
            Node *p = st.top(); st.pop();
            p->next[pp->c - 'A'] = NULL;
            pp = p;
            bool f = 1;
            REP(i, 26) if (p->next[i]) f = 0;
            if (f) {
                p->~Node();
                if (!st.empty())st.top()->next[p->c - 'A'] = NULL;
            }
            else break;
        }
        if (rt == NULL) rt = new Node('*');
    }
};

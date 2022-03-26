#include <cstdio>
#include <cstring>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
const int AC_SIGMA = 26, AC_V = 29, AC_N = 500100;
struct AC_automaton {
    struct node {
        node *go[AC_V], *fail, *fa;
        int fg, id;
    } pool[AC_N], *cur, *root, *q[AC_N];
    node* newnode() {
        node *p = cur++;
        memset(p->go, 0, sizeof(p->go));
        p->fail = p->fa = NULL; p->fg = 0;
        return p;
    }
    void init() { cur = pool; root = newnode();}
    node* append(node *p, int w) {
        if (!p->go[w]) p->go[w] = newnode(), p->go[w]->fa = p;
        return p = p->go[w];
    }
    void build() {
        int t = 1;
        q[0] = root;
        rep(i, 0, t) rep(j, 0, AC_SIGMA) if (q[i]->go[j]) {
            node *v = q[i]->go[j], *p = v->fa->fail;
            while (p && !p->go[j]) p = p->fail;
            if (p) v->fail = p->go[j]; else v->fail = root;
            q[t++] = q[i]->go[j];
        } else {
            node *p = q[i]->fail;
            while (p && !p->go[j]) p = p->fail;
            if (p) q[i]->go[j] = p->go[j]; else q[i]->go[j] = root;
        }
    }
    int query(char s[]) {
        node *p = root;
        int res = 0;
        for (int i = 0; s[i]; i++) {
            p = p->go[s[i] - 'a'];
            node *v = p;
            while (v != root) {
                res += v->fg;
                v->fg = 0;
                v = v->fail;
            }
        }
        return res;
    }
} T;
typedef AC_automaton::node ACnode;


const int MAXN = 1000000 + 1000;
char txt[MAXN];

int main() {
#ifdef MANGOGAO
    freopen("data.in", "r", stdin);
#endif

    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        T.init();
        char s[55];
        rep(i, 0, n) {
            ACnode *p = T.root;
            scanf("%s", s);
            for (int j = 0; s[j]; j++)
                p = T.append(p, s[j] - 'a');
            p->fg++;
        }
        T.build();
        scanf("%s", txt);
        printf("%d\n", T.query(txt));
    }
    return 0;
}

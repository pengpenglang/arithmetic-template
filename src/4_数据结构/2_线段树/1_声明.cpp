#define lson rt<<1			// 左儿子
#define rson rt<<1|1			// 右儿子
#define Lson l,m,lson		// 左子树
#define Rson m+1,r,rson 	// 右子树
void PushUp(int rt);			// 用lson和rson更新rt
void PushDown(int rt[, int m]);	// rt的标记下移，m为区间长度（若与标记有关）
void build(int l, int r, int rt);	// 以rt为根节点，对区间[l, r]建立线段树
void update([...,] int l, int r, int rt)	// rt[l, r]内寻找目标并更新
int query(int L, int R, int l, int r, int rt) // rt-[l, r]内查询[L, R] 

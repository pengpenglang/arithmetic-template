// $O(\log n)$查询和修改数组的前缀和
// 注意下标应从1开始 n是全局变量
int bit[N], n; 
int sum(int i){
	int s = 0;
	while(i){
		s += bit[i];
		i -= i&-i;
	}
	return s;
}
void add(int i, int x){
	while(i<=n){
		bit[i] += x;
		i += i&-i;
	}
}

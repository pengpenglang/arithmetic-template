// 传入序列a和长度n，返回最大子序列和
// 限制最短长度：用cnt记录长度，rt更新时判断
int MaxSeqSum(int a[], int n) {
	int rt = 0, cur = 0;
	for (int i = 0; i < n; i++) {
		cur += a[i];
		rt = rt < cur ? cur : rt;
		cur = cur < 0 ? 0 : cur;
	}
	return rt;
}

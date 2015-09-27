### 复杂度证明相关

```
k = 0;
next[1] = 0;
for q = 2...m
	while k>0 & p[k+1]!=p[q]
		k = next[k]
	if p[k+1]==p[q]
		k = k + 1
	next[q] = k;
```


kmp中next[q] = max{k: k<q & p[q-k+1...q]=p[1...k]}

计算next的过程维护了当前的next[q]，next[q+1]是通过next[q]状态转移计算出的

while循环中 k严格递减且始终大于0，每个for循环k最多增加1，整个计算next[]的过程k最多从0增加至m
k最多从增加m-1次，所以k递减的次数也不超过m-1，因此while循环是O(m)的，整个复杂度也是O(m)的


### 正确性证明相关

while循环中始终保持k是当前最佳选择，即不可能有k'>k且满足next[]的性质

---
layout: post-light-feature
title: 一个双层循环的复杂度分析
description: "双层循环的复杂度常常被粗略地认为是平方级别的，但有时其确切的复杂度确和平方级别差别很大。本文分析了一个复杂度为\\(n\log n\\)循环。"
categories: articles
date: 2014-12-17
---

## 背景

这个双层循环是[1012 增长率问题](http://acm.sjtu.edu.cn/OnlineJudge/problem/1012)中出现的，在下面分析之前
我丝毫没有意识到暴力的想法居然是\\(O(n\log n)\\)的！

## 这个双层循环

```C
int func() 
{
	int cnt = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (i*j > n) break;
			++ cnt;
		}
	}
	return cnt;
}
```

## 复杂度分析

对外层循环，将\\(i\in[1,n]\\)分成两类：第一类中\\(i*m<=n\\)，其余的\\(i\\)都属于第二类且满足\\(i*m>n\\)。

那么，第一类\\(i\\)的个数是：\\(\lfloor\frac{n}{m}\rfloor\\)，所以对总的复杂度贡献是：\\(O(m*\lfloor\frac{n}{m}\rfloor)=O(n)\\)；

第二类\\(i\\)的个数是：\\(n-\lfloor\frac{n}{m}\rfloor\\)，对于第二类的每一个\\(i\\)，对复杂度的贡献是\\(O(\lfloor\frac{n}{i}\rfloor)\\)，
所以第二类对总的复杂度贡献是：\\(O(\sum_{i=\lfloor\frac{n}{m}\rfloor+1}^n\lfloor\frac{n}{i}\rfloor)\\)
这个求和通过定积分放大得到：
\\[
\sum_{i=\lfloor\frac{n}{m}\rfloor+1}^n\lfloor\frac{n}{i}\rfloor\le\int_{\lfloor\frac{n}{m}\rfloor+1}^n\frac{n}{x}\text{d}x\le\int_{\frac{n}{m}}^n\frac{n}{x}\text{d}x
\\]
所以得到第二类对总的复杂度的贡献是：\\(O(n*\log_em)\\)

综上，总的复杂度是：\\(O(n+n\log_em)=O(n\log m)\\)


附： [1012 增长率问题](http://acm.sjtu.edu.cn/OnlineJudge/problem/1012)

---
layout: post-light-feature
title: һ��˫��ѭ���ĸ��Ӷȷ���
description: "˫��ѭ���ĸ��Ӷȳ��������Ե���Ϊ��ƽ������ģ�����ʱ��ȷ�еĸ��Ӷ�ȷ��ƽ��������ܴ󡣱��ķ�����һ�����Ӷ�Ϊ\\(n\log n\\)ѭ����"
categories: articles
date: 2014-12-17
---

## ����

���˫��ѭ����[1012 ����������](http://acm.sjtu.edu.cn/OnlineJudge/problem/1012)�г��ֵģ����������֮ǰ
��˿��û����ʶ���������뷨��Ȼ��\\(O(n\log n)\\)�ģ�

## ���˫��ѭ��

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

## ���Ӷȷ���

�����ѭ������\\(i\in[1,n]\\)�ֳ����ࣺ��һ����\\(i*m<=n\\)�������\\(i\\)�����ڵڶ���������\\(i*m>n\\)��

��ô����һ��\\(i\\)�ĸ����ǣ�\\(\lfloor\frac{n}{m}\rfloor\\)�����Զ��ܵĸ��Ӷȹ����ǣ�\\(O(m*\lfloor\frac{n}{m}\rfloor)=O(n)\\)��

�ڶ���\\(i\\)�ĸ����ǣ�\\(n-\lfloor\frac{n}{m}\rfloor\\)�����ڵڶ����ÿһ��\\(i\\)���Ը��ӶȵĹ�����\\(O(\lfloor\frac{n}{i}\rfloor)\\)��
���Եڶ�����ܵĸ��Ӷȹ����ǣ�\\(O(\sum_{i=\lfloor\frac{n}{m}\rfloor+1}^n\lfloor\frac{n}{i}\rfloor)\\)
������ͨ�������ַŴ�õ���
\\[
\sum_{i=\lfloor\frac{n}{m}\rfloor+1}^n\lfloor\frac{n}{i}\rfloor\le\int_{\lfloor\frac{n}{m}\rfloor+1}^n\frac{n}{x}\text{d}x\le\int_{\frac{n}{m}}^n\frac{n}{x}\text{d}x
\\]
���Եõ��ڶ�����ܵĸ��ӶȵĹ����ǣ�\\(O(n*\log_em)\\)

���ϣ��ܵĸ��Ӷ��ǣ�\\(O(n+n\log_em)=O(n\log m)\\)


���� [1012 ����������](http://acm.sjtu.edu.cn/OnlineJudge/problem/1012)

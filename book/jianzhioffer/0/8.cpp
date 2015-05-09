# include <stack>
# include <iostream>
class Solution
{
public:
	void push(int node) {
	    stack1.push(node);
	}

	int pop() {
	    if (stack2.empty()) {
            while (stack1.size()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
	    }

	    if (stack2.empty()) return 0;

	    int ret = stack2.top();
	    stack2.pop();
	    return ret;
	}

private:
	std::stack<int> stack1;
	std::stack<int> stack2;
};


int a[] = {1,2,3,4,5,6,7,0};

int main()
{
    Solution s;
    for (int i = 0; a[i]; ++i) {
        s.push(a[i]);
        if (i % 2 == 0) std::cout << s.pop() << std::endl;
    }

    return 0;
}

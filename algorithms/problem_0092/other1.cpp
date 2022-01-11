ListNode* reverseBetween(ListNode* root, int m, int n)
{
	int count1 = 1;
	ListNode* fir = root;
	ListNode* sec = root;
	stack<int> temp;
	while(count1<m)
	{
		count1++;
		fir = fir->next;
		sec = fir;
	}

	while(count1>=m && count1<=n)
	{
		temp.push(fir->val);
		fir = fir->next;
		count1++;
	}
	
	int flag = n-m;
	while(flag>=0)
	{
		sec->val = temp.top();
		temp.pop();
		sec = sec->next;
		flag--;
	}
	return root;
}


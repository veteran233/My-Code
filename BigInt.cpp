class BigInt
{
public:
	BigInt() {}
	BigInt(string a) { this->val = a; }
	bool operator<(const BigInt& a)const
	{
		if (this->isneg == isneg)
		{
			if (this->isneg) //负数
			{
				if (this->val.size() == a.val.size()) return this->val > a.val;
				else return this->val.size() > a.val.size();
			}
			else //正数
			{
				if (this->val.size() == a.val.size()) return this->val < a.val;
				else return this->val.size() < a.val.size();
			}
		}
		else return this->isneg;
	}
	bool operator>(const BigInt& a)const
	{
		if (this->isneg == isneg)
		{
			if (this->isneg) //负数
			{
				if (this->val.size() == a.val.size()) return this->val < a.val;
				else return this->val.size() < a.val.size();
			}
			else //正数
			{
				if (this->val.size() == a.val.size()) return this->val > a.val;
				else return this->val.size() > a.val.size();
			}
		}
		else return a.isneg;
	}
	bool operator==(const BigInt& a)const { return this->val == a.val; }
	void operator=(string s) { this->val = s; }
	BigInt operator+(const BigInt& a)const { return add(this, a); }
	BigInt operator-(const BigInt& a)const { return sub(this, a); }
	friend istream& operator>>(istream& is, BigInt& a) { a.isneg = 0; is >> a.val; if (*a.val.begin() == '-') a.isneg = 1, a.val = a.val.substr(1); return is; }
	friend ostream& operator<<(ostream& os, const BigInt& a) { if (a.isneg) os << '-' << a.val; else os << a.val; return os; }
private:
	string val;
	bool isneg = 0;
	BigInt add(const BigInt* p, BigInt b)const
	{
		BigInt a = *p;

		if (a.isneg ^ b.isneg) //ab异号
		{
			if (a.isneg) //a为负
			{
				a.isneg = 0;
				return sub(&b, a);
			}
			else //b为负
			{
				b.isneg = 0;
				return sub(&a, b);
			}
		}

		//如果同号，flag保存符号
		bool flag = a.isneg;
		a.isneg = b.isneg = 0; //这里是为了两个负数的加法运算做出的特殊处理，两个负数的加法等同于两个正数的加法

		if (a > b) swap(a, b);

		reverse(a.val.begin(), a.val.end());
		reverse(b.val.begin(), b.val.end());

		long long len = a.val.size();

		long long before = 0;
		for (long long i = 0; i < len; ++i)
		{
			long long temp = 1ll * a.val[i] - '0' + b.val[i] - '0' + before;
			before = temp / 10;

			b.val[i] = temp % 10 + '0';
		}
		for (long long i = len; i < b.val.size(); ++i)
		{
			long long temp = 1ll * b.val[i] - '0' + before;
			before = temp / 10;
			b.val[i] = temp % 10 + '0';
			if (before == 0) break;
		}
		if (before) b.val.push_back(before + '0');

		reverse(b.val.begin(), b.val.end());
		b.isneg = flag;
		return b;
	}
	BigInt sub(const BigInt* p, BigInt b)const
	{
		BigInt a = *p;

		if (a.isneg ^ b.isneg) //ab异号
		{
			b.isneg = !b.isneg;
			return add(&a, b);
		}
		if (a.isneg)
		{
			a.isneg = b.isneg = 0;
			return sub(&b, a);
		}

		if (a < b) swap(a, b), a.isneg = 1;
		if (a == b) return BigInt("0");
		reverse(a.val.begin(), a.val.end());
		reverse(b.val.begin(), b.val.end());

		long long len = b.val.size();

		long long before = 0;
		for (long long i = 0; i < len; ++i)
		{
			long long temp = 1ll * a.val[i] - b.val[i] + before;
			if (temp < 0) a.val[i] = 10 + temp + '0', before = -1;
			else a.val[i] = temp + '0', before = 0;
		}
		for (long long i = len; i < a.val.size(); ++i)
		{
			long long temp = 1ll * a.val[i] - '0' + before;
			if (temp < 0) a.val[i] = 10 + temp + '0', before = -1;
			else a.val[i] = temp + '0', before = 0;
			if (before == 0) break;
		}
		reverse(a.val.begin(), a.val.end());

		//删除多余的前导零
		ll i = 0;
		for (; i < a.val.size() && a.val[i] == '0'; ++i);
		a.val = a.val.substr(i);

		return a;
	}
};

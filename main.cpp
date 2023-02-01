#include<vector>
#include<algorithm>

int l[] =
{
	strtol("1111110", 0, 2),
	strtol("0110000", 0, 2),
	strtol("1101101", 0, 2),
	strtol("1111001", 0, 2),
	strtol("0110011", 0, 2),
	strtol("1011011", 0, 2),
	strtol("1011111", 0, 2),
	strtol("1110000", 0, 2),
	strtol("1111111", 0, 2),
	strtol("1111011", 0, 2),
};

int d(int x, int y)
{
	int ret = 0;
	for (int i = 0; i < 7; i++)
	{
		ret += ((l[x] ^ l[y]) >> i) & 1;
	}
	return ret;
}

void main()
{
	std::vector<int>num;

	for (int i = 0; i < 10; i++)
		num.push_back(i);

	int min = 999;

	// ‘S‚Ä‚Ì‡—ñ‚ğo—Í
	for (int n = 0; n < 2; n++)
	{
		do
		{
			int s = 0;
			for (unsigned int i = 1; i < num.size(); i++)
			{
				s += d(num[i - 1], num[i]);
			}
			if (n==0)
			{
				s<min&&(min=s);
			}
			else if (s==min)
			{
				printf("%d", num[0]);
				for (unsigned int i = 1; i < num.size(); i++)
				{
					printf(" ,%d", num[i]);
				}
				printf("\n");
			}
		}
		while (next_permutation(num.begin(), num.end()));
	}
}

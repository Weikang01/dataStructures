#pragma once
#include <bitset>


template<typename Type, unsigned int size>
class hsTable
{
public:
	hsTable() {}
	~hsTable() = default;
	insert(Type key)
	{
		int p, c;
		if (!SearchHash(key, p, c))
		{
			if (c * 1.f / static_cast<float>(size) < .5f)
			{
				// TODO: insert value
			}
		}
	}


private:
	int hash(Type key) { return (3 * key) % size; }
	void collision(int& p) { p = (p + 1) % size; }
	bool SearchHash(Type key, int& p, int& c)
	{
		p = Hash(key);
		c = 0;
		while ((1 == tag[p] && rcd[p].key != key))
		{
			collision(p); c++;
		}
		if (tag[p] == 1 && key == rcd[p].key) return true;
		else return false;
	}
	


private:
	Type* rcd = new Type(size);
	unsigned int count = 0;
	std::bitset<size> tag;
};

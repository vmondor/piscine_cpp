#include "MutantStack.hpp"
#include <list>
#include <vector>

/*
int main()
{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);
    return 0;
}
*/

/*
int main() {
    std::list<int> mlist;
    mlist.push_back(5);
    mlist.push_back(17);
    std::cout << mlist.back() << std::endl;
    mlist.pop_back();
    std::cout << mlist.size() << std::endl;
    mlist.push_back(3);
    mlist.push_back(5);
    mlist.push_back(737);
    //[...]
    mlist.push_back(0);
    std::list<int>::iterator it = mlist.begin();
    std::list<int>::iterator ite = mlist.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    return 0;
}
*/

int main()
{
	std::cout << "\t FOR MUTANTSTACK" << std::endl;
	{
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}
	std::cout << std::endl;

	std::cout << "\t FOR LIST" << std::endl;
	{
		std::list<int> mstack_list;
		mstack_list.push_back(5);
		mstack_list.push_back(17);
		std::cout << mstack_list.back() << std::endl;
		mstack_list.pop_back();
		std::cout << mstack_list.size() << std::endl;
		mstack_list.push_back(3);
		mstack_list.push_back(5);
		mstack_list.push_back(737);
		//[...]
		mstack_list.push_back(0);
		std::list<int>::iterator it_list = mstack_list.begin();
		std::list<int>::iterator ite_list = mstack_list.end();
		++it_list;
		--it_list;
		while (it_list != ite_list)
		{
			std::cout << *it_list << std::endl;
			++it_list;
		}
		std::list<int> s(mstack_list);
	}
	std::cout << std::endl;

	std::cout << "\t FOR VECTOR" << std::endl;
	{
		std::vector<int> mstack_vector;
		mstack_vector.push_back(5);
		mstack_vector.push_back(17);
		std::cout << mstack_vector.back() << std::endl;
		mstack_vector.pop_back();
		std::cout << mstack_vector.size() << std::endl;
		mstack_vector.push_back(3);
		mstack_vector.push_back(5);
		mstack_vector.push_back(737);
		//[...]
		mstack_vector.push_back(0);
		std::vector<int>::iterator it_vector = mstack_vector.begin();
		std::vector<int>::iterator ite_vector = mstack_vector.end();
		++it_vector;
		--it_vector;
		while (it_vector != ite_vector)
		{
			std::cout << *it_vector << std::endl;
			++it_vector;
		}
		std::vector<int> s(mstack_vector);
		std::cout << std::endl;
	}
	return 0;
}

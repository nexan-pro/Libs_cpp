#include <iostream>
#include <deque>
#include <initializer_list>

namespace D34D{
	template <class T, class Container = _STD deque<T>>
	class Stack {
	public:
		typedef Container container_type;
		typedef typename Container::value_type value_type;
		typedef typename Container::size_type size_type;
		typedef typename Container::reference reference;
		typedef typename Container::const_reference const_reference;
	protected:
		container_type c;
	public:
		Stack() = default;
		Stack(_STD initializer_list<value_type> _Elems) {
			for (typename std::initializer_list<value_type>::iterator i = _Elems.begin(); i != _Elems.end(); i++)
				c.push_back(*i);
		}
		bool operator=(const Stack<T, Container> &SsT);
		reference top();
		bool empty();
		size_type size();
		void push(value_type &&vl);
		decltype(auto) emplace(value_type&& args);
		void pop();
		void swap(Stack &other) noexcept;
		const container_type& Get_Container() const;
	};
	
	template <class T, class Container>
	bool operator==(const Stack<T, Container> &lft, const Stack<T, Container> &rght) {
		return (lft.Get_Container() == rght.Get_Container());
	}

	template <class T, class Container>
	bool operator!=(const Stack<T, Container> &lft, const Stack<T, Container> &rght) {
		return (!(lft == rght));
	}

	template <class T, class Container>
	bool operator<(const Stack<T, Container> &lft, const Stack<T, Container> &rght) {
		return (lft.Get_Container() < rght.Get_Container());
	}

	template <class T, class Container>
	bool operator<=(const Stack<T, Container> &lft, const Stack<T, Container> &rght) {
		return (!(lft < rght));
	}

	template <class T, class Container>
	bool operator>(const Stack<T, Container> &lft, const Stack<T, Container> &rght) {
		return (lft.Get_Container() > rght.Get_Container());
	}

	template <class T, class Container>
	bool operator>=(const Stack<T, Container> &lft, const Stack<T, Container> &rght) {
		return (!(lft > rght));
	}
}
using namespace D34D;

template <class T, class Container>
bool Stack<T, Container>::operator=(const Stack<T, Container> &SsT) {
	c = SsT.c;
	return this;
}

template <class T, class Container>
typename Stack<T, Container>::reference Stack<T, Container>::top() {
	return c.back();
}

template <class T, class Container>
bool Stack<T, Container>::empty() {
	return c.empty() == true ? true : false;
}

template <class T, class Container>
typename Stack<T, Container>::size_type Stack<T, Container>::size() {
	return c.size();
}

template <class T, class Container>
void Stack<T, Container>::push(value_type &&vl) {
	c.push_back(vl);
}

template <class T, class Container>
decltype(auto) Stack<T, Container>::emplace(value_type &&args) {
	c.emplace_back(args);
}

template <class T, class Container>
void Stack<T, Container>::pop() {
	c.pop_back();
}

template <class T, class Container>
void Stack<T, Container>::swap(Stack& other) noexcept {
	swap(c, other.c);
}
template <class T, class Container>
const typename Stack<T, Container>::container_type& Stack< T, Container>::Get_Container() const {
	return (c);
}


int main() {
	Stack<int> sp = {1,2,3,4,5};
	Stack<int> _sp = { 6,7,8,9,15 };
	if (_sp != sp)
		_STD cout << "true";
	sp = _sp;
	sp.push(11);
	sp.emplace(12);
	_STD cout << sp.top();
	sp.pop();
	_STD cout << sp.top();
	swap(sp, _sp);
	_STD cout << sp.top();
	_STD cout << _sp.top();
	system("pause");
	return 0;
}

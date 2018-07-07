#include <iostream>
#include <deque>
#include <string>

namespace D34D {
	template <class T, class Container = _STD deque<T>>
	class queue {
	public:
		typedef Container container_type;
		typedef typename Container::value_type value_type;
		typedef typename Container::size_type size_type;
		typedef typename Container::reference reference;
		typedef typename Container::const_reference const_reference;
	private:
		container_type c;
	public:
		queue() = default;
		explicit queue(container_type&& _Cont)
			: c(_STD move(_Cont))
		{	
		}
		~queue() = default;
		const Container& GetContainer() const;
		queue& operator=(queue& other);
		reference front();
		reference back();
		[[nodiscard]] bool empty() const;
		size_type size() const;
		void push(value_type&& value);
		template <class ...Args>
		decltype(auto) emplace(Args&& ...args);
		void pop();
		void swap(queue& other) noexcept;
	};

	template <class T, class Container>
	inline bool operator==(const queue<T, Container>& lhs, const queue<T, Container>& rhs) {
		return (lhs.GetContainer() == rhs.GetContainer());
	}

	template <class T, class Container>
	inline bool operator!=(const queue<T, Container>& lhs, const queue<T, Container>& rhs) {
		return !(lhs.GetContainer() == rhs.GetContainer());
	}

	template <class T, class Container>
	inline bool operator<(const queue<T, Container>& lhs, const queue<T, Container>& rhs) {
		return (lhs.GetContainer() < rhs.GetContainer());
	}

	template <class T, class Container>
	inline bool operator<=(const queue<T, Container>& lhs, const queue<T, Container>& rhs) {
		return (!(rhs < lhs));
	}

	template <class T, class Container>
	inline bool operator>(const queue<T, Container>& lhs, const queue<T, Container>& rhs) {
		return (rhs < lhs);
	}

	template <class T, class Container>
	inline bool operator>=(const queue<T, Container>& lhs, const queue<T, Container>& rhs) {
		return (!(lhs < rhs));
	}
}
using namespace D34D;

template <class T, class Container>
const Container& queue<T, Container>::GetContainer() const {
	return (c);
}

template <class T, class Container>
queue<T, Container>& queue<T, Container>::operator=(queue& other) {
	c = _STD move(other.c);
	return (*this);
}

template <class T, class Container>
typename queue<T, Container>::reference queue<T, Container>::front() {
	return c.front();
}

template <class T, class Container>
typename queue<T, Container>::reference queue<T, Container>::back() {
	return c.back();
}

template <class T, class Container>
[[nodiscard]] bool queue<T, Container>::empty() const {
	return c.empty();
}

template <class T, class Container>
typename queue<T, Container>::size_type queue<T, Container>::size() const {
	return (c.size());
}

template <class T, class Container>
void queue<T, Container>::push(value_type&& value) {
	c.push_back(_STD move(value));
}

template <class T, class Container> template <class ...Args>
decltype(auto) queue<T, Container>::emplace(Args&& ...args) {
	c.emplace_back(_STD forward<Args>(args)...);
}

template <class T, class Container>
void queue<T, Container>::pop() {
	c.pop_front();
}

template <class T, class Container>
void queue<T, Container>::swap(queue& other) noexcept {
	_STD swap(c, other.c);
}

int main() {
	queue <int> myq;
	myq.push(1);
	myq.push(3);
	myq.push(3);
	myq.push(7);
	_STD cout << myq.front();
	myq.pop();
	_STD cout << myq.front();
	myq.pop();
	//_STD cout << myq.size();
	queue <int> trr;
	trr = myq;
	_STD cout << '\n';
	_STD cout << trr.front();
	trr.pop();
	_STD cout << trr.front();
	trr.pop();
	trr.push(51);
	myq.swap(trr);
	_STD cout << myq.front();
	///
	queue<std::string> myqueue;

	myqueue.emplace("First sentence");
	myqueue.emplace("Second sentence");

	_STD cout << "myqueue contains:\n";
	while (!myqueue.empty())
	{
		std::cout << myqueue.front() << '\n';
		myqueue.pop();
	}
	///
	queue <int> vcv;
	vcv.push(1);
	queue <int> dxd;
	dxd.push(1);
	queue <int> dxxd(dxd);
	_STD cout << dxxd.front() << '\n';
	if (dxd != vcv) _STD cout << "\ntrue";
	system("pause");
	return 0;
}

#include <iostream>
#include <initializer_list>

namespace D34D {
	template< class T, class Allocator = std::allocator<T>> 
	class deque {
	public:
		typedef T value_type;
		typedef Allocator allocator_type;
		typedef _STD size_t size_type;
		typedef _STD ptrdiff_t difference_type;
		typedef value_type& reference;
		typedef const value_type& const_reference;
		typedef typename _STD allocator_traits<Allocator>::pointer pointer;
		typedef typename _STD allocator_traits<Allocator>::const_pointer const_pointer;
		typedef value_type* iterator;
		typedef const value_type* const_iterator;
		typedef _STD reverse_iterator<iterator> reverse_iterator;
		typedef _STD reverse_iterator<const_iterator> const_reverse_iterator;
	private:
		iterator arr;
		size_type reserved;
		size_type _size;
	public:
		deque() {
			arr = new value_type[reserved];
		}
		deque(_STD initializer_list<value_type> _Elem, const Allocator& alloc = Allocator()) {
		reserved = _Elem.size();
		arr = new value_type[reserved];
		size_t j(0);
		for (typename _STD initializer_list<T>::iterator i = _Elem.begin(); i != _Elem.end(), j < _Elem.size(); i++) {
				arr[j] = *i;
				j++;
				_size = j;
			}
		}
		deque(deque&& other, const Allocator& alloc) {

		}
		deque& operator=(deque& other) noexcept;
		void assign(size_type count, const T& value);
		allocator_type get_allocator() const;
		
		reference at(size_type pos);
		const_reference at(size_type pos) const;
		reference operator[](size_type pos);
		const_reference operator[](size_type pos) const;
		reference front();
		const_reference front() const;
		reference back();
		const_reference back() const;
		
		iterator begin() noexcept;
		const_iterator cbegin() const noexcept;
		iterator end() noexcept;
		const_iterator cend() const noexcept;
		reverse_iterator rbegin() noexcept;
		const_reverse_iterator crbegin() const noexcept;
		reverse_iterator rend() noexcept;
		const_reverse_iterator crend() const noexcept;
		
		[[nodiscard]] bool empty() const noexcept;
		size_type size() const noexcept;
		size_type max_size() const noexcept;
		void resize(size_type count);
		void shrink_to_fit();
		
		volatile void clear() noexcept;
		iterator insert(const_iterator pos, const_reference value);
		template< class... Args >
		iterator emplace(const_iterator pos, Args&&... args);
		iterator erase(const_iterator pos);
		///
		void realloc();
		void push_front(const T& value);
		void push_back(const T& value);
		void pop_front();
		void pop_back();
		void swap(deque& other) noexcept;
		///TODO some C++11 func /*emplace_front, emplace_back*/
	};
	template <class T, class Allocator>
	bool operator==(const deque<T, Allocator>& lhs, const deque<T, Allocator>& rhs) {
		if (lhs.size() == rhs.size())
		{
			for (typename deque<T, Allocator>::const_iterator i = lhs.cbegin(), j = rhs.cbegin(); i != lhs.cend(); i++, j++)
				if (*i != *j) return 0;
			return 1;
		}
		return 0;
	}

	template <class T, class Allocator>
	bool operator!=(const deque<T, Allocator>& lhs, const deque<T, Allocator>& rhs) {
		return !(lhs == rhs);
	}

	template <class T, class Allocator>
	bool operator<(const deque<T, Allocator>& lhs, const deque<T, Allocator>& rhs) {
		for (typename deque<T, Allocator>::const_iterator i = lhs.cbegin(), j = rhs.cbegin(); i != lhs.cend(); ++i, ++j)
		{
			if (*i < *j) return 1;
			else return 0;
		}
	}

	template <class T, class Allocator>
	bool operator<=(const deque<T, Allocator>& lhs, const deque<T, Allocator>& rhs) {
		for (typename deque<T, Allocator>::const_iterator i = lhs.cbegin(), j = rhs.cbegin(); i != lhs.cend(); ++i, ++j)
		{
			if (*i <= *j) return 1;
			else return 0;
		}
	}

	template <class T, class Allocator>
	bool operator>=(const deque<T, Allocator>& lhs, const deque<T, Allocator>& rhs) {
		for (typename deque<T, Allocator>::const_iterator i = lhs.cbegin(), j = rhs.cbegin(); i != lhs.cend(); ++i, ++j)
		{
			if (*i >= *j) return 1;
			else return 0;
		}
	}

	template <class T, class Allocator>
	bool operator>(const deque<T, Allocator>& lhs, const deque<T, Allocator>& rhs) {
		for (typename deque<T>::const_iterator i = lhs.cbegin(), j = rhs.cbegin(); i != lhs.cend(); ++i, ++j)
		{
			if (*i > *j) return 1;
			else return 0;
		}
	}
}

using namespace	D34D;

template <class T, class Allocator>
typename deque<T, Allocator>::deque& deque<T, Allocator>::operator=(deque& other) noexcept {
	resize(other._size);
	for (size_type i = 0, j = 0; i < other._size; i++, j++)
		arr[i] = other.arr[j];
	return (*this);
}

template <class T, class Allocator>
void deque<T, Allocator>::assign(size_type count, const T& value) {
	reserved = count;
	_size = count;
	for (size_t i = 0; i < _size; i++)
		arr[i] = value;
}

template <class T, class Allocator>
typename deque<T, Allocator>::allocator_type deque<T, Allocator>::get_allocator() const {
	return Allocator();
}

template <class T, class Allocator>
typename deque<T, Allocator>::reference deque<T, Allocator>::at(size_type pos) {
	return (arr[pos]);
}

template <class T, class Allocator>
typename deque<T, Allocator>::const_reference deque<T, Allocator>::at(size_type pos) const {
	return (arr[pos]);
}

template <class T, class Allocator>
typename deque<T, Allocator>::reference deque<T, Allocator>::operator[](size_type pos) {
	return (arr[pos]);
}

template <class T, class Allocator>
typename deque<T, Allocator>::const_reference deque<T, Allocator>::operator[](size_type pos) const {
	return (arr[pos]);
}

template <class T, class Allocator>
typename deque<T, Allocator>::reference deque<T, Allocator>::front() {
	return (arr[0]);
}

template <class T, class Allocator>
typename deque<T, Allocator>::const_reference deque<T, Allocator>::front() const {
	return (arr[0]);
}

template <class T, class Allocator>
typename deque<T, Allocator>::reference deque<T, Allocator>::back() {
	return (arr[_size-1]);
}

template <class T, class Allocator>
typename deque<T, Allocator>::const_reference deque<T, Allocator>::back() const {
	return (arr[_size-1]);
}

template <class T, class Allocator>
typename deque<T, Allocator>::iterator deque<T, Allocator>::begin() noexcept {
	return (arr);
}

template <class T, class Allocator>
typename deque<T, Allocator>::const_iterator deque<T, Allocator>::cbegin() const noexcept {
	return (arr);
}

template <class T, class Allocator>
typename deque<T, Allocator>::iterator deque<T, Allocator>::end() noexcept {
	return (arr + _size);
}

template <class T, class Allocator>
typename deque<T, Allocator>::const_iterator deque<T, Allocator>::cend() const noexcept {
	return (arr + _size);
}

template <class T, class Allocator>
typename deque<T, Allocator>::reverse_iterator deque<T, Allocator>::rbegin() noexcept {
	return (reverse_iterator(end()));
}

template <class T, class Allocator>
typename deque<T, Allocator>::const_reverse_iterator deque<T, Allocator>::crbegin() const noexcept {
	return (reverse_iterator(cend()));
}

template <class T, class Allocator>
typename deque<T, Allocator>::reverse_iterator deque<T, Allocator>::rend() noexcept {
	return (reverse_iterator(begin()));
}

template <class T, class Allocator>
typename deque<T, Allocator>::const_reverse_iterator deque<T, Allocator>::crend() const noexcept{
	return (reverse_iterator(cbegin()));
}

template <class T, class Allocator>
[[nodiscard]] bool deque<T, Allocator>::empty() const noexcept {
	return (cbegin() == cend() ? 1 : 0);
}

template <class T, class Allocator>
typename deque<T, Allocator>::size_type deque<T, Allocator>::size() const noexcept {
	return (_size);
}

template <class T, class Allocator>
typename deque<T, Allocator>::size_type deque<T, Allocator>::max_size() const noexcept {
	return (18446744073709551615);
}

template <class T, class Allocator>
void deque<T, Allocator>::resize(size_type count) {
	
	if (count > this->_size) {
		//arr = static_cast<iterator>(realloc(arr, count * sizeof(value_type)));
		for (size_t i = this->_size; i < count; i++)
				arr[i] = '\0';
		this->_size = count;
		this->reserved = count;
		return;
	}
	this->_size = count;
}

template <class T, class Allocator>
void deque<T, Allocator>::shrink_to_fit() {
	if (this->_size != this->reserved)
		this->reserved = this->_size;
}

template <class T, class Allocator>
volatile void deque<T, Allocator>::clear() noexcept {
	for (; _size != 0; _size--)
		arr[_size] = '\0';
}

template <class T, class Allocator>
typename deque<T, Allocator>::iterator deque<T, Allocator>::insert(const_iterator pos, const_reference value) {
	reserved++;
	iterator ptr = new T[reserved];
	size_type k = 0;
	for (iterator i = begin(); i != pos; i++) {
		ptr[k] = arr[k];
		k++;
	}
	if (k > _size) { _STD cerr << "\ninsert(): Iterator greater than vector size.\n"; return 0; }
	ptr[k] = value;
	_size++;
	for (size_type i = k+1; i < _size; i++)
		ptr[i] = arr[i-1];
	for (size_type i = 0, j = 0; i < _size; i++, j++)
		arr[i] = ptr[j];
	delete[] ptr;
	return (arr);
}

template <class T, class Allocator>
template <class... Args>
typename deque<T, Allocator>::iterator deque<T, Allocator>::emplace(const_iterator pos, Args&&... args) {
	return insert(pos, args...);
}

template <class T, class Allocator>
typename deque<T, Allocator>::iterator deque<T, Allocator>::erase(const_iterator pos) {
	size_type ecx(0);
	for (iterator i = begin(); i != pos; i++)
		ecx++;
	for (int ix = ecx; ix < _size - 1; ix++)
		arr[ix] = arr[ix + 1];
	reserved--;
	_size--;
	//realloc();
	return (arr);
}

template <class T, class Allocator>
void deque<T, Allocator>::realloc() {
	iterator Ptr = new value_type[reserved];
	for (size_t i = 0; i < this->_size; i++)
		Ptr[i] = arr[i];
	delete[] this->arr;
	this->arr = Ptr;
}

template <class T, class Allocator>
void deque<T, Allocator>::push_front(const T& value) {
	this->reserved++;
	realloc();
	iterator Ptr = new value_type[reserved];
	Ptr[0] = value;
	size_type ecx(1);
	for (iterator i = begin(); i != end(); i++) {
		Ptr[ecx] = *i;
		ecx++;
	}
	this->_size++;
	for (size_t i = 0; i < reserved; i++)
		arr[i] = Ptr[i];
}

template <class T, class Allocator>
void deque<T, Allocator>::push_back(const T& value) {
	if (_size == reserved) {
		reserved++;
		realloc();
	}
	if (reserved < _size) { _STD cerr << "\nOutput: push_back(): reserved size of deque < her count of elements (size)!\n"; return; }
	arr[_size++] = value;
}

template <class T, class Allocator>
void deque<T, Allocator>::pop_front() {
	if (_size <= 0) { _STD cerr << "\nOutput: Error, size of array is less or equal 0!\n"; return; }
	else {
		this->reserved--;
		iterator Ptr = new value_type[reserved];
		for (size_t i = 1, j = 0; i < this->_size; i++, j++)
			Ptr[j] = arr[i];
		this->_size--;
		delete[] arr;
		arr = Ptr;
		for (size_t i = 0; i < this->_size; i++)
			arr[i] = Ptr[i];
	}
}

template <class T, class Allocator>
void deque<T, Allocator>::pop_back() {
	if (_size == reserved)
	{
		reserved++;
		realloc();
	}
	if (reserved < _size) { _STD cerr << "\nOutput: push_back(): reserved size of deque < her count of elements (size)!\n"; return; }
	arr[_size--].~T();
}

template <class T, class Allocator>
void deque<T, Allocator>::swap(deque& other) noexcept {
	if (other._size < _size) {
		size_type tmp = other._size;
		other.resize(_size);
		for (typename deque<T, Allocator>::iterator i = begin(), j = other.begin(); i != end(), j != other.end(); ++i, ++j)
			_STD swap(*i, *j);
		_size = tmp;
	}
	else {
		size_type tmp = _size;
		resize(other._size);
		for (typename deque<T, Allocator>::iterator i = begin(), j = other.begin(); i != end(); ++i, ++j)
			_STD swap(*i, *j);
		other._size = tmp;
	}
}

int main() {
	deque<char> characters;
	characters.assign(5, 'a');
	characters.shrink_to_fit();
	//characters.clear();
	auto it = characters.begin();
	characters.insert(it + 2, 's');
	characters.push_back('w');
	for (char c : characters)
		std::cout << c << '\n';
	_STD cout << "\nuntil: ";
	_STD cout << characters.size();
	_STD cout << "\nsince";
	//characters.resize(25);
	_STD cout << characters.size();
	for (char c : characters)
		std::cout << c << '\n';
	_STD cout << "\nnext: ";
	characters.push_front('x');
	for (char c : characters)
		std::cout << c << '\n';
	///*_STD cout << "\nresult of erase() = ";
	//characters.erase(it);*/
	//for (char c : characters)
	//	std::cout << c << '\n';
	_STD cout << "\nafter pop front(): ";
	characters.pop_front();
	characters.pop_front();
	for (char c : characters)
		std::cout << c << '\n';
	_STD cout << "\nafter pop back(): ";
	characters.pop_back();
	for (char c : characters)
		std::cout << c << '\n';
	deque<char> ch;
	std::cout << "\nAfter swap() : " << '\n';
	ch = characters;
	if (ch == characters) _STD cout << "\ntrue;\n";
	for (char c : ch)
		std::cout << c << '\n';
	_STD cout << "characters size = " << characters.size() << '\n';

	system("pause");
	return 0;
}

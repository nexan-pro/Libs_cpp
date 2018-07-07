#include <iostream>
#include <initializer_list>
#include <iterator>

namespace D34D {
	template <class T, class Allocator = _STD allocator <T>>
	class vector {
		typedef T value_type;
		typedef Allocator allocator_type;
		typedef _STD size_t size_type;
		typedef _STD ptrdiff_t difference_type;
		typedef typename value_type&  reference;
		typedef typename const value_type& const_reference;
		typedef typename _STD allocator_traits<Allocator>::pointer pointer;
		typedef typename _STD allocator_traits<Allocator>::const_pointer const_pointer;
		typedef value_type* iterator;
		typedef const value_type* const_iterator;
		typedef _STD reverse_iterator<iterator>	reverse_iterator;
		typedef _STD reverse_iterator<const_iterator> const_reverse_iterator;
		value_type *arr;
		size_type reserved;
		size_type _size;
	public:

		vector(_STD initializer_list<T> init, const Allocator& alloc = Allocator()) {
			reserved = init.size();
			arr = new T[reserved];
			size_t j(0);
			for (typename _STD initializer_list<T>::iterator i = init.begin(); i != init.end(), j < init.size(); i++) {
				arr[j] = *i;
				j++;
				_size = j;
			}
		}
		~vector() { delete[] arr; }
		vector& operator=(vector &arg) noexcept;// TODO
		void assign(size_type cnt, const value_type& value);
		allocator_type get_allocator() const;
		///
		reference at(size_type pos);
		const_reference at(size_type pos) const;
		reference operator[](size_type pos);
		reference front();
		const_reference front() const;
		reference back();
		const_reference back() const;
		iterator data() noexcept;
		const_iterator data() const noexcept;
		///
		iterator begin() noexcept;
		const_iterator cbegin() const noexcept;
		iterator end() noexcept;
		const_iterator cend() const noexcept;
		reverse_iterator rbegin() noexcept;
		const_reverse_iterator crbegin() const noexcept;
		reverse_iterator rend() noexcept;
		const_reverse_iterator crend() const noexcept;
		///
		[[nodiscard]] bool empty() const noexcept;
		constexpr size_type size() const noexcept;
		size_type max_size() const noexcept;
		void reserve(size_type new_cap) noexcept;
		size_type capacity() const noexcept;
		void shrink_to_fit();
		///
		volatile void clear() noexcept;
		iterator insert(const_iterator pos, const_reference value);
		template< class... Args >
		iterator emplace(const_iterator pos, Args&&... args);
		iterator erase(const_iterator pos);
		void push_back(const value_type& value);
		volatile void pop_back();
		void resize(size_type count);
		void swap(vector& other) noexcept;
	};

}
using namespace D34D;

template <class T, class Allocator>
typename vector<T, Allocator>::vector& vector<T, Allocator>::operator=(vector &arg) noexcept {
	return (arr = arg.arr);
}

template <class T, class Allocator>
void vector<T, Allocator>::assign(size_type cnt, const value_type &arg) {
	for (size_t i = 0; i < cnt; i++)
		arr[i] = arg;
}

template <class T, class Allocator>
typename vector<T, Allocator>::allocator_type vector<T, Allocator>::get_allocator() const {
	return Allocator();
}

template <class T, class Allocator>
typename vector<T, Allocator>::reference vector<T, Allocator>::at(size_type pos) {
	if (pos < size())
		return (arr[pos]);
	std::out_of_range;
}

template <class T, class Allocator>
typename vector<T, Allocator>::const_reference vector<T, Allocator>::at(size_type pos) const {
	if (pos < size())
		return (arr[pos]);
	std::out_of_range;
}

template <class T, class Allocator>
typename vector<T, Allocator>::reference vector <T, Allocator>::operator[](size_type pos) {
	return (arr[pos]);
}

template <class T, class Allocator>
constexpr typename vector<T, Allocator>::size_type vector<T, Allocator>::size() const noexcept {
	return (_size);
}

template <class T, class Allocator>
typename vector<T, Allocator>::reference vector<T, Allocator>::front() {
	return (arr[0]);
}

template <class T, class Allocator>
typename vector<T, Allocator>::const_reference vector<T, Allocator>::front() const {
	return (arr[0]);
}

template <class T, class Allocator>
typename vector<T, Allocator>::reference vector<T, Allocator>::back() {
	return (arr[_size-1]);
}

template <class T, class Allocator>
typename vector<T, Allocator>::const_reference vector<T, Allocator>::back() const {
	return (arr[_size-1]);
}

template <class T, class Allocator>
typename vector<T, Allocator>::iterator vector<T, Allocator>::data() noexcept {
	return arr;
}

template <class T, class Allocator>
typename vector<T, Allocator>::const_iterator vector<T, Allocator>::data() const noexcept {
	return arr;
}

template <class T, class Allocator>
typename vector<T, Allocator>::iterator vector<T, Allocator>::begin() noexcept {
	return arr;
}

template <class T, class Allocator>
typename vector<T, Allocator>::const_iterator vector<T, Allocator>::cbegin() const noexcept {
	return arr;
}

template <class T, class Allocator>
typename vector<T, Allocator>::iterator vector<T, Allocator>::end() noexcept {
	return arr + _size;
}

template <class T, class Allocator>
typename vector<T, Allocator>::const_iterator vector<T, Allocator>::cend() const noexcept {
	return arr + _size;
}

template <class T, class Allocator>
typename vector<T, Allocator>::reverse_iterator vector<T, Allocator>::rbegin() noexcept {
	return (reverse_iterator(end()));
}

template <class T, class Allocator>
typename vector<T, Allocator>::const_reverse_iterator vector<T, Allocator>::crbegin() const noexcept {
	return (reverse_iterator(end()));
}

template <class T, class Allocator>
typename vector<T, Allocator>::reverse_iterator vector<T, Allocator>::rend() noexcept {
	return (reverse_iterator(begin()));
}

template <class T, class Allocator>
typename vector<T, Allocator>::const_reverse_iterator vector<T, Allocator>::crend() const noexcept {
	return (reverse_iterator(begin()));
}
template <class T, class Allocator>
[[nodiscard]] bool vector<T, Allocator>::empty() const noexcept {
	return _size <= 0 ? true : false;
}

template <class T, class Allocator>
typename vector<T, Allocator>::size_type vector<T, Allocator>::max_size() const noexcept {
	return 18446744073709551615;
}

template <class T, class Allocator>
void vector<T, Allocator>::reserve(size_type new_cap) noexcept {
	this->reserved += new_cap;
	arr = static_cast<iterator>(realloc(arr, reserved * sizeof(value_type)));
}

template <class T, class Allocator>
typename vector<T, Allocator>::size_type vector<T, Allocator>::capacity() const noexcept {
	return (this->reserved);
}

template <class T, class Allocator>
void vector<T, Allocator>::shrink_to_fit() {
	this->reserved = this->_size;
}

template <class T, class Allocator>		
volatile void vector<T, Allocator>::clear() noexcept {
	for (; _size != 0; _size--)
		arr[_size] = '\0';
}
	
template <class T, class Allocator>
typename vector<T, Allocator>::iterator vector<T, Allocator>::insert(const_iterator pos, const_reference value) {
	reserved++;
	iterator ptr = new T[reserved];
	size_type k = 0;
	for (iterator i = begin(); i != pos; i++) {
		ptr[k] = arr[k];
		k++;
	}
	if (k > _size) { _STD cout << "\nclear(): Iterator greater than vector size.\n"; return 0; }
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
typename vector<T, Allocator>::iterator vector<T, Allocator>::emplace(const_iterator pos, Args&&... args) {
	return insert(pos, args...);
}

template <class T, class Allocator>
typename vector<T, Allocator>::iterator vector<T, Allocator>::erase(const_iterator pos) {
	size_type ecx(0);
	for (iterator i = begin(); i != pos; i++)
		ecx++;
	for (int ix = ecx; ix < _size - 1; ix++)
		arr[ix] = arr[ix + 1];
	reserved--;
	_size--;
	arr = static_cast<iterator>(realloc(arr, reserved * sizeof(value_type)));
	return (arr);
}

template <class T, class Allocator>
void vector<T, Allocator>::push_back(const value_type& value) {
	if (_size == reserved) {
		reserved++;
		arr = static_cast<iterator>(realloc(arr, reserved * sizeof(value_type)));
	}
	arr[_size++] = value;
}

template <class T, class Allocator>
volatile void vector<T, Allocator>::pop_back() {
	arr[_size--] = '\0';
}

template <class T, class Allocator>	
void vector<T, Allocator>::resize(size_type count) {
	if (count > _size) {
		arr = static_cast<iterator>(realloc(arr, count * sizeof(value_type)));
		for (size_t i = _size; i < count; i++)
			arr[i] = '\0';
		_size = count;
		return;
	}
	_size = count;
}

template <class T, class Allocator>
void vector<T, Allocator>::swap(vector& other) noexcept {
	if (other._size < _size) {
		size_type tmp = other._size;
		other.resize(_size);
		for (typename vector<T, Allocator>::iterator i = begin(), j = other.begin(); i != end(), j != other.end(); ++i, ++j)
			_STD swap(*i, *j);
		_size = tmp;
	}
	else {
		size_type tmp = _size;
		resize(other._size);
		for (typename vector<T, Allocator>::iterator i = begin(), j = other.begin(); i != end(); ++i, ++j)
			_STD swap(*i, *j);
		other._size = tmp;
	}
}

int main() {
	vector <int> af = {42,152,33,354,55,87,95,34,23,13};
	vector <int> df = {	1,3,3,7 };
	_STD cout << af.at(3) << '\n';
	_STD cout << "capacity() = " << af.capacity() << '\n';
	af.reserve(20);
	_STD cout << "capacity() = " << af.capacity() << '\n';
	af.shrink_to_fit();
	_STD cout << "size = " << af.size() << '\n';
	//_STD cout << "max_size = " << sdf.max_size() << '\n';
	//af.clear();
	auto it = af.begin();
	af.emplace(it+3, 1337);
	af.push_back(22);
	_STD cout << "before delete: \n";
	_STD copy(af.begin(), af.end(), _STD ostream_iterator<int>(_STD cout, " "));
	auto jt = af.end();
	af.erase(jt-2);
	_STD cout << "\nafter erase: ";
	af.pop_back();
	af.resize(15);
	vector <int> sdf = {9,7,6,7,6,7,5,4,3,2,2,5,6,7,4};
	df.swap(sdf);
	_STD cout << "size = " << df.size() << '\n';
	///
	vector<int> myvector{};
	int *p = myvector.get_allocator().allocate(5);
	unsigned i;
	for (i = 0; i<5; i++) myvector.get_allocator().construct(&p[i], i);

	std::cout << "The allocated array contains:";
	for (i = 0; i<5; i++) std::cout << ' ' << p[i];
	///
	std::cout << '\n';
	_STD copy(sdf.begin(), sdf.end(), _STD ostream_iterator<int>(_STD cout, " "));
	system("pause");
	return 0;
}

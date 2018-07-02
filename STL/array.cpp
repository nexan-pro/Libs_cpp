#include <iostream>
#include <iterator>

namespace D34D {

	template <class T, size_t N>
	class array
	{
	public:
		T arr[N];
		typedef T* iterator;
		typedef _STD  reverse_iterator<iterator> reverse_iterator;
		inline constexpr T size() const noexcept;
		inline constexpr T at(int) const;
		inline constexpr T front() const;
		inline constexpr T back() const;
		inline iterator data();
		inline bool empty();
		inline constexpr T max_size() const noexcept;
		void swap(array<T, N> &obj) noexcept;
		void fill(const T& value);
		iterator begin();
		constexpr iterator cbegin() const;
		reverse_iterator rbegin();
		iterator end();
		constexpr iterator cend() const;
		reverse_iterator rend();
		T &operator [](int);
	};

	template <size_t ID, class T, size_t N>
	T &get(array<T, N> &obj) {
		return (obj.arr[ID]);
	}

	template <class T, size_t N>
	bool operator==(array <T, N> &lft, array<T, N> &rght) {
		for (size_t i = 0; i < N; i++) {
			if (lft[i] != rght[i])
				return false;
		}
		return true;
	}

	template <class T, size_t N>
	constexpr bool operator != (array <T, N> &lft, array<T, N> &rght) {
		return !(lft == rght);
	}

	template <class T, size_t N>
	bool operator < (array <T, N> &lft, array<T, N> &rght) {
		for (size_t i = 0; i < N; i++) {
			if (lft[i] < rght[i])
				return true;
			if (rght[i] < lft[i])
				return false;
		}
	}

	template <class T, size_t N>
	bool operator <= (array <T, N> &lft, array<T, N> &rght) {
		for (size_t i = 0; i < N; i++) {
			if (lft[i] <= rght[i])
				return true;
			if (rght[i] <= lft[i])
				return false;
		}
	}

	template <class T, size_t N>
	bool operator > (array <T, N> &lft, array<T, N> &rght) {
		for (size_t i = 0; i < N; i++) {
			if (lft[i] > rght[i])
				return true;
			if (rght[i] > lft[i])
				return false;
		}
	}

	template <class T, size_t N>
	bool operator >= (array <T, N> &lft, array<T, N> &rght) {
		for (size_t i = 0; i < N; i++) {
			if (lft[i] >= rght[i])
				return true;
			if (rght[i] >= lft[i])
				return false;
		}
	}
}

using namespace	D34D;

template <class T, size_t N>
inline constexpr T array<T, N>::size() const noexcept {
	return N;
}

template <class T, size_t N>
inline constexpr T array <T, N>::at(int n) const {
	return arr[n];
}

template <class T, size_t N>
inline constexpr T array<T, N>::front() const{
	return arr[0];
}

template <class T, size_t N>
inline constexpr T array<T, N>::back() const {
	return arr[N-1];
}

template <class T, size_t N>
T &array<T, N>::operator[](int n) {
	return arr[n];
}

template <class T, size_t N>
typename array<T, N>::iterator array<T, N>::data() {
	return arr;
}

template <class T, size_t N>
inline bool array<T, N>::empty() {
	return N == 0 ? 1 : 0;
}

template <class T, size_t N>
typename array<T, N>::iterator array<T, N>::begin() {
	return arr;
}

template <class T, size_t N>
typename array<T, N>::iterator array<T, N>::end() {
	return arr + N;
}

template <class T, size_t N>
void array <T, N>::swap(array<T, N> &obj) noexcept {
	for (size_t i = 0; i < N; i++)
	{
		T tmp = arr[i];
		T tmp1 = obj.arr[i];
		obj.arr[i] = tmp;
		arr[i] = tmp1;
	}	
}

template <class T, size_t N>
inline constexpr T array<T, N>::max_size() const noexcept {
	return N;
}

template <class T, size_t N>
constexpr typename array<T, N>::iterator array<T, N>::cbegin() const {
	return (begin());
}

template <class T, size_t N>
constexpr typename array<T, N>::iterator array<T, N>::cend() const {
	return (end());
}

template <class T, size_t N>
typename array<T, N>::reverse_iterator array<T, N>::rbegin() {
	return (reverse_iterator(end()));
}

template <class T, size_t N>
typename array<T, N>::reverse_iterator array<T, N>::rend() {
	return (reverse_iterator(begin()));
}

template <class T, size_t N>
void array<T, N>::fill(const T& value) {
	for (size_t i = 0; i < N; i++)
		arr[i] = value;
	
}

int main() {
	array<double, 5> af = { 3, 2, 3, 4, 5 };
	array<double, 5> df = { 8, 4.3, 2.3, 12, 25 };
	if (af > df)
		_STD cout << "true\n";
	_STD cout << "size = " << af.size() << '\n';
	_STD cout << "at = " << af.at(4) << '\n';
	_STD cout << "sum across at() = " << af.at(3) + af.at(1) << '\n';
	_STD cout << "array front() = " << af.front() << '\n';
	_STD cout << "array back() = " << af.back() << '\n';
	_STD cout << af[0] << '\n';
	af[0] += df[0];
	_STD cout << af.data() << '\n';
	_STD cout << af.empty() << '\n';
	_STD copy(af.begin(), af.end(), _STD ostream_iterator<double>(_STD cout, " "));
	_STD cout << '\n' << get<1>(af) << '\n';
	df.swap(af);
	_STD copy(af.begin(), af.end(), _STD ostream_iterator<double>(_STD cout, " "));
	_STD  cout << '\n';
	_STD copy(df.begin(), df.end(), _STD ostream_iterator<double>(_STD cout, " "));
	_STD  cout << "\nreverse array: ";
	_STD copy(df.rbegin(), df.rend(), _STD ostream_iterator<double>(_STD cout, " "));
	_STD  cout << "\nmax_size = " << af.max_size() << '\n';
	af.fill(5);
	_STD copy(af.begin(), af.end(), _STD ostream_iterator<double>(_STD cout, " "));
	system("pause");
	return 0;
}

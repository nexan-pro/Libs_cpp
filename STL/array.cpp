#include <iostream>
#include <iterator>

namespace D34D {

	template <class T, size_t N>
	class array
	{
	public:
		T arr[N];
		inline T size();
		inline T at(int);
		inline T front();
		inline T back();
		inline T* data();
		inline bool empty();
		std::_Array_iterator<T, N> begin();
		std::_Array_iterator<T, N> end();
		T &operator [](int);
	};
	template <size_t ID, class T, size_t N>
	T &get(array<T, N> &obj) {
		return (obj.arr[ID]);
	}
}

using namespace	D34D;

template <class T, size_t N>
inline T array<T, N>::size() {
	return N;
}

template <class T, size_t N>
inline T array <T, N>::at(int n) {
	return arr[n];
}

template <class T, size_t N>
inline T array<T, N>::front() {
	return arr[0];
}

template <class T, size_t N>
inline T array<T, N>::back() {
	return arr[N-1];
}

template <class T, size_t N>
T &array<T, N>::operator[](int n) {
	return arr[n];
}

template <class T, size_t N>
T *array<T, N>::data() {
	return arr;
}

template <class T, size_t N>
inline bool array<T, N>::empty() {
	return N == 0 ? 1 : 0;
}

template <class T, size_t N>
std::_Array_iterator<T, N> array<T, N>::begin() {
	return (std::_Array_iterator<T, N>(_STD addressof(arr[0]), 0));
}

template <class T, size_t N>
std::_Array_iterator<T, N> array<T, N>::end() {
	return (std::_Array_iterator<T, N>(_STD addressof(arr[0]), N));
}

int main() {
	array<double, 5> af = { 1.3, 2, 3, 4, 5 };
	std::cout << "size = " << af.size() << '\n';
	std::cout << "at = " << af.at(4) << '\n';
	std::cout << "sum across at() = " << af.at(3) + af.at(1) << '\n';
	std::cout << "array front() = " << af.front() << '\n';
	std::cout << "array back() = " << af.back() << '\n';
	std::cout << af[0] << '\n';
	
	std::cout << af[0] << '\n';
	std::cout << af.data() << '\n';
	std::cout << af.empty() << '\n';
	std::copy(af.begin(), af.end(), std::ostream_iterator<double>(std::cout, " "));
	std::cout << '\n' << get<1>(af) << '\n';
	system("pause");
	return 0;
}
#include "Random.h"

template class Random<int>;
template class Random<short>;
template class Random<long>;
template class Random<long long>;

template <class T>
Random<T>* Random<T>::sInstance = nullptr;


template <class T>
Random<T>::Random()
{
	srand((unsigned)time(NULL));
}


template <class T>
T Random<T>::RandomRange(T min, T max)
{
	return min + (rand() % max);
}

template<class T>
Random<T>* Random<T>::GetInstance()
{
	if (!sInstance)
	{
		sInstance = new Random();
	}
	return sInstance;
}


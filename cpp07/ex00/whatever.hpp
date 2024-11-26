template <typename T> void swap(T &__a, T &__b) {
  T tmp = __a;
  __a = __b;
  __b = tmp;
}

template <typename T> T min(T &__a, T &__b) { return (__a < __b ? __a : __b); }

template <typename T> T max(T &__a, T &__b) { return (__a > __b ? __a : __b); }

#ifndef _DYNARRAY_H_
#define _DYNARRAY_H_ 1

template<class T> class DynArray {
 public:
  DynArray();
  DynArray(int);
  ~DynArray();

  // Always add to end
  bool append(T item);

  // Make ArraySize = nData
  bool truncate();

  void clear() {
    nData = 0;
  }

  int length() const {
    return nData;
  }

  bool empty() const {
    return nData == 0;
  }

  const T &operator[](int i) const {
    return data[i];
  }

  T *data;
  int nData;
  int arraySize;
}

template<class T>
DynArray<T>::DynArray() {
  nData = 0;
  arraySize = 4;
  data = new T[arraySize];
}

template<class T> DynArray<T>::DynArray(int n) {
  nData = 0;
  arraySize = n;
  data = new T[arraySize];
}

// Destructor
template<class T> DynArray<T>::~DynArray() {
  nData = 0;
  delete[] data;
}

template<T> bool DynArray<T>::append(T item) {
  if (nData == arraySize) {
    arraySize *= 2;
    T *temp = data;
    if (!(data = new T[arraySize]))
      return false;
    for (int i = 0; i < nData; i++) {
      data[i] = temp[i];
    }
    delete[] temp;
  }
  data[nData++] = item;
  return true;
}

template<T> bool DynArray<T>::truncate() {
  if (nData != arraySize) {
    T *temp = data;
    arraySize = nData;
    if (!(data = new T[arraySize]))
      return false;
    for (int i = 0; i < nData; i++) {
      data[i] = temp[i];
    }
    delete[] temp;
  }
  return true;
}

#endif
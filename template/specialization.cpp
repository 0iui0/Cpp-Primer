//
// Created by iouoi on 2021/5/29.
//

//1.full specialization
//指定任意类型会走这里
template<class Key>
struct hash {
};

//指定以下类型会走这里
template<>
struct hash<int> {
    size_t operator(
    int x){ return x; };
}

template<>
//cout<<hash<long>()(1000)<<endl;
struct hash<long> {
    size_t operator(
    long x){ return x; };
}

//2.partial specialization 个数偏
template<typename T, typename Alloc= ...>
class vector {
};

template<typename Alloc= ...>
class vector<bool, Alloc> {
};

//范围偏 任意类型-->指针类型
template<typename T>
class C {
};

template<typename U>
class C<U *> {
};
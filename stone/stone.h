//
// Created by iouoi on 2021/5/29.
//

#ifndef CPP_PRIMER_STONE_H
#define CPP_PRIMER_STONE_H

template<class T>
inline const T &min(const T &a, const T &b) {
    return b < a ? b : a;
}

class stone {
public:
    stone(int w, int h, int we) : _w(w), _h(h), _weigh(we) {};

    bool operator<(const stone &rhs) const {
        return _weigh < rhs._weigh;
    }

    int getWeigh() { return _weigh; };
private:
    int _w, _h, _weigh;
};


#endif //CPP_PRIMER_STONE_H

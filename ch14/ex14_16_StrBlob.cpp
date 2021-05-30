#include "ex14_16_StrBlob.h"

//==================================================================
//
//		operators
//
//==================================================================

bool operator==(const StrBlob &lhs, const StrBlob &rhs) {
    return *lhs.data == *rhs.data;
}

bool operator!=(const StrBlob &lhs, const StrBlob &rhs) {
    return !(lhs == rhs);
}

bool operator==(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
    return lhs.curr == rhs.curr;
}

bool operator!=(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
    return !(lhs == rhs);
}

bool operator==(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs) {
    return lhs.curr == rhs.curr;
}

bool operator!=(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs) {
    return !(lhs == rhs);
}

//==================================================================
//
//		copy assignment operator and move assignment operator.
//
//==================================================================

StrBlob &StrBlob::operator=(const StrBlob &lhs) {
    data = make_shared<vector<string>>(*lhs.data);
    return *this;
}

StrBlob &StrBlob::operator=(StrBlob &&rhs) NOEXCEPT {
    if (this != &rhs) {
        data = std::move(rhs.data);
        rhs.data = nullptr;
    }

    return *this;
}

//==================================================================
//
//		members
//
//==================================================================

StrBlobPtr StrBlob::begin() {
    return StrBlobPtr(*this);
}

StrBlobPtr StrBlob::end() {
    return StrBlobPtr(*this, data->size());
}

ConstStrBlobPtr StrBlob::cbegin() const {
    return ConstStrBlobPtr(*this);
}

ConstStrBlobPtr StrBlob::cend() const {
    return ConstStrBlobPtr(*this, data->size());
}

#pragma once
#include <iostream>

template <class T>
class myShared_ptr {
public:
    myShared_ptr(T *ptr = nullptr) {
        if (ptr) {
            count_ = new size_t(1);
            data_ = ptr;
        }
    }

    myShared_ptr(const myShared_ptr<T> &other) {
        count_ = other.count_;
        data_ = other.data_;
        if (count_) {
            ++(*count_);
        }
    }

    myShared_ptr(myShared_ptr<T> &&other) {
        count_ = other.count_;
        data_ = other.data_;
        other.count_ = nullptr;
        other.data_ = nullptr;
    }

    ~myShared_ptr() { release(); }

    myShared_ptr<T> &operator=(const myShared_ptr<T> &other) {
        if (this != &other) {
            this->release();
            count_ = other.count_;
            data_ = other.data_;
            if (count_) {
                ++(*count_);
            }
        }
        return *this;
    }

    T &operator*() const { return *data_; }

    T *operator->() const { return data_; }

    size_t use_count() const { return count_ ? *count_ : 0; }

    void reset(T *ptr = nullptr) {
        this->release();
        if (ptr) {
            count_ = new size_t(1);
            data_ = ptr;
        }
    }

private:
    T *data_ = nullptr;
    size_t *count_ = nullptr;

    void release() {
        if (count_) {
            --(*count_);
            if (*count_ == 0) {
                delete count_;
                delete data_;
            }
            count_ = nullptr;
            data_ = nullptr;
        }
    }
};
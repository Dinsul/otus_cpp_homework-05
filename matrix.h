#pragma once
#include <cstddef>
#include <stdexcept>
#include <map>

template <class T, T defValue>
/*!
 * \brief The LazyArray class
 * Разряженный массив. В случае когда запрашивается не существующий элемент
 * возвращается значение поумолчанию.
 */
class LazyArray
{
    T _defValue;                //!< Заначение поумолчанию
    std::map<size_t, T> _data;  //!< Хранилище ключ(индекс), значение

public:
    LazyArray() : _defValue(defValue){}
    LazyArray(const LazyArray& other) : _defValue(other.defaultValue()){}
    ~LazyArray(){}

    /*!
     * \brief append Добавляет новый элемент в массив. Старое значение переписывается.
     * \param pos Индекс массива.
     * \param val Значение, которое будет добпвленно.
     */
    void append(size_t pos, T val)
    {
        if (val == _defValue)
        {
            _data.erase(pos);
        }
        else
        {
            _data[pos] = val;
        }
    }

    T &operator[](size_t pos){
        try
        {
            return _data.at(pos);
        }
        catch(std::out_of_range)
        {
            _data[pos] = _defValue;
            return _data[pos];
        }
    }

    T at(size_t pos){
        try
        {
            return _data.at(pos);
        }
        catch(std::out_of_range)
        {
            return _defValue;
        }
    }

    void clear(void)
    {
        _data.clear();
    }

    void thin_out(void)
    {
        for (auto cur = _data.begin(); cur != _data.end();)
        {
            if (cur->second == _defValue) {
                cur = _data.erase(cur);
            } else {
                ++cur;
            }
        }
    }

    size_t size(void)
    {
        thin_out();
        return _data.size();
    }

    const T &defaultValue() const
    {
        return _defValue;
    }

    bool empty(void)
    {
        return _data.empty();
    }
};


template <class T, T defValue>
class Matrix
{
    std::map<size_t, LazyArray<T, defValue> > _data;

public:
    void append(size_t pos_x, size_t pos_y, T val)
    {
        _data[pos_x][pos_y] = val;
    }

    LazyArray<T, defValue> &operator[](size_t pos)
    {
        return _data[pos];
    }

    LazyArray<T, defValue> &at(size_t pos)
    {
        return _data[pos];
    }

    void clear(void)
    {
        _data.clear();
    }

    void thin_out(void)
    {
        for (auto cur = _data.begin(); cur != _data.end();)
        {
            if (cur->second.empty()) {
                cur = _data.erase(cur);
            } else {
                ++cur;
            }
        }
    }

    size_t size(void)
    {
        thin_out();
        size_t retVal = 0;

        for (auto cur = _data.begin(); cur != _data.end(); ++cur)
        {
            retVal += cur->second.size();
        }

        return retVal;
    }

    const T &defaultValue() const
    {
        return _data[0].defaultValue();
    }

};



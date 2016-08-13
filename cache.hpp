#ifndef cache_hpp
#define cache_hpp

#include <iostream>

namespace zhuyuesut {
    template <typename _ValueType>
    class Cache {
        _ValueType value;
        
    public:
        using value_type = _ValueType;
        
        Cache () = default;
        
        Cache (const _ValueType& i) : value(i) {};
        
        Cache (_ValueType&& i) : value(std::move(i)) {};
        
        template<typename FunctionType>
        Cache operator>> (FunctionType func) {
            return Cache(func(value));
        }
        
        std::ostream& operator>> (std::ostream &os) {
            return os << value;
        }
        
        Cache& operator<< (std::istream &is) {
            is >> value;
            return *this;
        }
        
        operator _ValueType () {
            return value;
        }
    };
    
    class CacheConstruct {
    public:
        template<typename _ValueType>
        Cache<_ValueType> operator() (const _ValueType& i) {
            return Cache<_ValueType>(i);
        }
        
        template<typename _ValueType>
        Cache<_ValueType> operator() (_ValueType&& i) {
            return Cache<_ValueType>(std::move(i));
        }
    } make_cache;
}

#endif /* cache_hpp */

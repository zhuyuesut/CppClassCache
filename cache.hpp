#ifndef cache_hpp
#define cache_hpp

#include <iostream>

namespace zhuyuesut {
    template <typename ValueType>
    class Cache {
        ValueType value;
        
    public:
        Cache () = default;
        
        Cache (const ValueType& i) : value(i) {};
        
        Cache (ValueType&& i) : value(std::move(i)) {};
        
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
        
        operator ValueType () {
            return value;
        }
    };
    
    class CacheConstruct {
    public:
        template<typename ValueType>
        Cache<ValueType> operator() (const ValueType& i) {
            return Cache<ValueType>(i);
        }
        
        template<typename ValueType>
        Cache<ValueType> operator() (ValueType&& i) {
            return Cache<ValueType>(std::move(i));
        }
    } make_cache;
}

#endif /* cache_hpp */

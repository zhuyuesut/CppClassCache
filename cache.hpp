#ifndef cache_hpp
#define cache_hpp

#include <iostream>

namespace zhuyuesut {
    template <typename T>
    class Cache {
        T value;
        
    public:
        using value_type = T;
        
        Cache () = default;
        
        Cache (const T& i) : value(i) {};
        
        Cache (T&& i) : value(std::move(i)) {};
        
        template<typename F>
        Cache operator>> (F func) {
            return Cache(func(value));
        }
        
        std::ostream& operator>> (std::ostream &os) {
            return os << value;
        }
        
        Cache& operator<< (std::istream &is) {
            is >> value;
            return *this;
        }
        
        operator T () {
            return value;
        }
    };
    
    class CacheConstruct {
    public:
        template<typename T>
        Cache<T> operator () (const T& i) {
            return Cache<T>(i);
        }
        
        template<typename T>
        Cache<T> operator () (T&& i) {
            return Cache<T>(std::move(i));
        }
    } make_cache;
}

#endif /* cache_hpp */

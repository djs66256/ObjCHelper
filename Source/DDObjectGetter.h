//
//  DDObjectGetter.hpp
//  DDJSONWrap
//
//  Created by hzduanjiashun on 2018/10/18.
//  Copyright © 2018 daniel. All rights reserved.
//

#ifndef DDObjectGetter_h
#define DDObjectGetter_h

#include <stdio.h>
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

namespace DD {
namespace Object {
    class Getter {
    public:
        Getter(id obj): _obj(obj) {}
        
        Getter get(id key) {
            if ([_obj isKindOfClass:NSDictionary.class]) {
                return _obj[key];
            }
            else {
                return nil;
            }
        }
        Getter at(NSInteger idx) {
            if ([_obj isKindOfClass:NSArray.class]) {
                if (((NSArray *)_obj).count > idx) {
                    return _obj[idx];
                }
            }
            return nil;
        }
        
        Getter operator[] (id key) {
            return get(key);
        }
        
        Getter operator[] (NSInteger idx) {
            return at(idx);
        }
        
        explicit operator bool() {
            return (_obj != nil);
        }
        
        template<typename T>
        typename std::enable_if_t<std::is_convertible<T*, id>::value, T*>
        value(T *defalutValue = nil) {
            if ([_obj isKindOfClass:[T class]]) {
                return static_cast<T *>(_obj);
            }
            else {
                return defalutValue;
            }
        }
        
        template<typename T>
        typename std::enable_if_t<std::is_same<T, char>::value, T>
        value(T defaultValue = 0) {
            if ([_obj respondsToSelector:@selector(charValue)]) {
                return [_obj charValue];
            }
            return defaultValue;
        }
        
        template<typename T>
        typename std::enable_if_t<std::is_same<T, unsigned char>::value, T>
        value(T defaultValue = 0) {
            if ([_obj respondsToSelector:@selector(unsignedCharValue)]) {
                return [_obj unsignedCharValue];
            }
            return defaultValue;
        }
        
        template<typename T>
        typename std::enable_if_t<std::is_same<T, short>::value, T>
        value(T defaultValue = 0) {
            if ([_obj respondsToSelector:@selector(shortValue)]) {
                return [_obj shortValue];
            }
            return defaultValue;
        }
        
        template<typename T>
        typename std::enable_if_t<std::is_same<T, unsigned short>::value, T>
        value(T defaultValue = 0) {
            if ([_obj respondsToSelector:@selector(unsignedShortValue)]) {
                return [_obj unsignedShortValue];
            }
            return defaultValue;
        }
        
        template<typename T>
        typename std::enable_if_t<std::is_same<T, int>::value, T>
        value(T defaultValue = 0) {
            if ([_obj respondsToSelector:@selector(intValue)]) {
                return [_obj intValue];
            }
            return defaultValue;
        }
        
        template<typename T>
        typename std::enable_if_t<std::is_same<T, unsigned int>::value, T>
        value(T defaultValue = 0) {
            if ([_obj respondsToSelector:@selector(unsignedIntValue)]) {
                return [_obj unsignedIntValue];
            }
            return defaultValue;
        }
        
        template<typename T>
        typename std::enable_if_t<std::is_same<T, long>::value, T>
        value(T defaultValue = 0) {
            if ([_obj respondsToSelector:@selector(longValue)]) {
                return [_obj longValue];
            }
            return defaultValue;
        }
        
        template<typename T>
        typename std::enable_if_t<std::is_same<T, unsigned long>::value, T>
        value(T defaultValue = 0) {
            if ([_obj respondsToSelector:@selector(unsignedLongValue)]) {
                return [_obj unsignedLongValue];
            }
            return defaultValue;
        }
        
        template<typename T>
        typename std::enable_if_t<std::is_same<T, long long>::value, T>
        value(T defaultValue = 0) {
            if ([_obj respondsToSelector:@selector(longLongValue)]) {
                return [_obj longLongValue];
            }
            return defaultValue;
        }
        
        template<typename T>
        typename std::enable_if_t<std::is_same<T, unsigned long long>::value, T>
        value(T defaultValue = 0) {
            if ([_obj respondsToSelector:@selector(unsignedLongLongValue)]) {
                return [_obj unsignedLongLongValue];
            }
            return defaultValue;
        }
        
        template<typename T>
        typename std::enable_if_t<std::is_same<T, float>::value, T>
        value(T defaultValue = 0) {
            if ([_obj respondsToSelector:@selector(floatValue)]) {
                return [_obj floatValue];
            }
            return defaultValue;
        }
        
        template<typename T>
        typename std::enable_if_t<std::is_same<T, double>::value, T>
        value(T defaultValue = 0) {
            if ([_obj respondsToSelector:@selector(doubleValue)]) {
                return [_obj doubleValue];
            }
            return defaultValue;
        }
        
        template<typename T>
        typename std::enable_if_t<std::is_same<T, bool>::value, T>
        value(T defaultValue = 0) {
            if ([_obj respondsToSelector:@selector(boolValue)]) {
                return [_obj boolValue];
            }
            return defaultValue;
        }
        
        template<typename T>
        typename std::enable_if_t<std::is_same<T, CGPoint>::value, T>
        value(T defaultValue = CGPointZero) {
            if ([_obj respondsToSelector:@selector(CGPointValue)]) {
                return [_obj CGPointValue];
            }
            return defaultValue;
        }
        
        template<typename T>
        typename std::enable_if_t<std::is_same<T, CGSize>::value, T>
        value(T defaultValue = CGSizeZero) {
            if ([_obj respondsToSelector:@selector(CGSizeValue)]) {
                return [_obj CGSizeValue];
            }
            return defaultValue;
        }
        
        template<typename T>
        typename std::enable_if_t<std::is_same<T, CGRect>::value, T>
        value(T defaultValue = CGRectZero) {
            if ([_obj respondsToSelector:@selector(CGRectValue)]) {
                return [_obj CGRectValue];
            }
            return defaultValue;
        }
        
    private:
        __unsafe_unretained id _obj;
    };
}; // namespace Object
}; // namespace DD

#endif /* DDObjectGetter_h */

# ObjCHelper
Objc 一些方便写法

# Object::Getter

利用c++的特性，来简化objc的一些繁琐的事情。

```objc
NSString *result = @"default string";
if ([obj isKindOfClass:NSArray.class]) {
  id objAtIdx = ((NSArray *)obj)[idx];
  if ([objAtIdx isKindOfClass:NSDictionary.class]) {
    id objForKey = ((NSDictionary *)objAtIdx)[@"key"];
    if ([objForKey isKindOfClass:NSString.class]) {
      result = (NSString *)objForKey;
    }
  }
}
```

To:

```objc++
NSString *result = Object::Getter(obj)[idx][@"key"].value<NSString>(@"defalut string");
```

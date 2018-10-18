//
//  DDJSONWrapTests.m
//  DDJSONWrapTests
//
//  Created by hzduanjiashun on 2018/10/18.
//  Copyright © 2018 daniel. All rights reserved.
//

#import <XCTest/XCTest.h>
#import "DDObjectGetter.h"

@interface DDJSONWrapTests : XCTestCase {
    NSDictionary *_dic;
    NSArray *_arr;
}

@end

using namespace DD;

@implementation DDJSONWrapTests

- (void)setUp {
    // Put setup code here. This method is called before the invocation of each test method in the class.
    _dic = @{
             @"num": @1.23,
             @"int": @30,
             @"double": @99.432,
             @"bool_yes": @YES,
             @"bool_no": @NO,
             @"str": @"afdafea",
             @"array": @[@"a", @"b", @"c"],
             @"dic": @{
                     @"num": @1.23,
                     @"int": @30,
                     @"double": @99.432,
                     @"bool_yes": @YES,
                     @"bool_no": @NO,
                     @"str": @"afdafea",
                     @"array": @[@"a", @"b", @"c"]
                     },
             };
}

- (void)tearDown {
    // Put teardown code here. This method is called after the invocation of each test method in the class.
}

- (void)testGetter {
    
    [self getterBy:Object::Getter(_dic)];
    [self getterBy:Object::Getter(_dic)[@"dic"]];
}

- (void)getterBy:(Object::Getter)getter {
    auto num = getter[@"num"].value<NSNumber>();
    XCTAssertEqualObjects(num, @1.23);
    auto arr = Object::Getter(_dic)[@"array"].value<NSArray>();
    NSArray *res = @[@"a", @"b", @"c"];
    XCTAssertEqualObjects(arr, res);
    
    auto nilobj = getter[@"nokey"].value<NSString>();
    XCTAssertNil(nilobj);
    
    if (auto nilobj2 = getter[@"nokey"]) {
        NSLog(@"false");
    }
    if (auto notnilobj = getter[@"str"]) {
        NSLog(@"true!");
    }
    
    auto str = getter[@"str"].value<NSString>();
    XCTAssertEqualObjects(str, @"afdafea");
    
    auto i = getter[@"int"].value<NSInteger>();
    XCTAssertEqual(i, 30);
    
    auto d = getter[@"double"].value<double>();
    XCTAssertEqual(d, 99.432);
    
    auto byes = getter[@"bool_yes"].value<BOOL>();
    XCTAssertEqual(byes, YES);
    auto bno = getter[@"bool_no"].value<BOOL>();
    XCTAssertEqual(bno, NO);
}

- (void)testPerformanceExample {
    // This is an example of a performance test case.
    [self measureBlock:^{
        // Put the code you want to measure the time of here.
    }];
}

@end

//
//  MRTCCodec.h
//  MRTC
//
//  Created by 张志超 on 2018/11/16.
//  Copyright © 2018 zzc. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface MRTCCodec : NSObject<NSCoding>
@property (nonatomic, copy, readonly) NSString *name;
@property (nonatomic, copy, readonly) NSDictionary *parameters;

- (BOOL)isEqualToCodec:(MRTCCodec *)codec;

- (instancetype)init NS_UNAVAILABLE;
@end

NS_ASSUME_NONNULL_END

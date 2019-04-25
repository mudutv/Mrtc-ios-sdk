//
//  MRTCError.h
//  MRTC
//
//  Created by 张志超 on 2018/11/15.
//  Copyright © 2018 zzc. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, MRTCErrorType) {
    kMRTCSystemError,
    kMRTCSignalingError,
    kMRTCStreamError,
    kMRTCConfigError
};

@interface MRTCError : NSObject

- (instancetype)initWithType:(MRTCErrorType)type errorString:(NSString *)errorString errorCode:(NSInteger)errCode;

@property (nonatomic, assign) MRTCErrorType type;

@property (nonatomic, copy) NSString *typeString;

@property (nonatomic, copy) NSString *errorString;

@property (nonatomic, assign) NSInteger code;

@end

NS_ASSUME_NONNULL_END

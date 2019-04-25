//
//  MRTCSetting.h
//  MRTC
//
//  Created by 张志超 on 2018/11/15.
//  Copyright © 2018 zzc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MRTCCodec.h"

NS_ASSUME_NONNULL_BEGIN

@interface MRTCFpsRange : NSObject
@property (nonatomic, assign, readonly) NSUInteger minFps;
@property (nonatomic, assign, readonly) NSUInteger maxFps;
@end

@interface MRTCSetting : NSObject

+ (NSArray<MRTCCodec *> *)supportVideoCodec;

/**
 * Returns array of available capture resoultions.
 *
 * The capture resolutions are represented as strings in the following format
 * [width]x[height]
 */
+ (NSArray<NSString *> *)supportVideoResolutions;

+ (MRTCFpsRange *)supportFPSRange;

- (instancetype)initWithVideoCodec:(MRTCCodec * __nullable)videoCodec videoResolution:(NSString *)videoResolution maxBitRate:(NSUInteger)maxBitrate fps:(NSUInteger)fps useFrontCamera:(BOOL)frontCamera;

- (instancetype)initWithVideoCodec:(MRTCCodec * __nullable)videoCodec videoWidth:(NSUInteger)videoWidth videoHeight:(NSUInteger)videoHeight maxBitRate:(NSUInteger)maxBitrate fps:(NSUInteger)fps useFrontCamera:(BOOL)frontCamera;

- (MRTCCodec *)currentVideoCodec;

- (NSString *)currentVideoResolution;

- (NSUInteger)currentVideoResolutionWidth;

- (NSUInteger)currentVideoResolutionHeight;

- (NSUInteger)currentBitRate;

- (NSUInteger)currentFps;

- (BOOL)isFrontCamera;

@end

NS_ASSUME_NONNULL_END

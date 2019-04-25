//
//  MRTCPuller.h
//  MRTC
//
//  Created by 张志超 on 2018/11/21.
//  Copyright © 2018 zzc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN
typedef NS_ENUM(NSUInteger, MRTCPullState) {
    kMRTCPullStateStop,
    kMRTCPullStateConnecting,
    kMRTCPullStateConnected,
    kMRTCPullStatePause,
    kMRTCPullStateFailed
};


@class MRTCPuller;
@class MRTCError;

@protocol MRTCPullerDelegate <NSObject>

- (void)MRTCPullerDidStartPull:(MRTCPuller *)puller;

- (void)MRTCPullerDidDisconnect:(MRTCPuller *)puller;

- (void)MRTCPuller:(MRTCPuller *)puller pullFailed:(MRTCError *)error;

@end

@protocol MRTCPullerErrorDelegate <NSObject>

- (void)MRTCPuller:(MRTCPuller *)puller didReceiveError:(MRTCError *)error;

@end

@interface MRTCPuller : NSObject
@property (nonatomic, assign) MRTCPullState pullState;

@property (nonatomic, weak) id<MRTCPullerDelegate> pullerDelegate;

@property (nonatomic, weak) id<MRTCPullerErrorDelegate> errorDelegate;

- (instancetype)initWithPullerDelegate:(id<MRTCPullerDelegate>)pullerDelegate;

- (void)startPullWithUrl:(NSString *)url renderView:(UIView *)renderView;

- (void)stopPull;

- (void)pause;

- (void)resume;

- (void)mute;

- (void)unmute;

- (void)getStats:(void(^)(NSDictionary *stats))completionHandler;

- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END

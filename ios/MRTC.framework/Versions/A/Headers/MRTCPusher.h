//
//  MRTCPusher.h
//  MRTC
//
//  Created by 张志超 on 2018/11/15.
//  Copyright © 2018 zzc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>


NS_ASSUME_NONNULL_BEGIN

@class MRTCPusher;
@class MRTCSetting;
@class MRTCError;

typedef NS_ENUM(NSUInteger, MRTCPushState) {
    kMRTCPushStateStop,
    kMRTCPushStateConnecting,
    kMRTCPushStateConnected,
    kMRTCPushStatePause,
    kMRTCPushStateFailed
};

@protocol MRTCPusherDelegate <NSObject>

- (void)MRTCPusherDidStartPush:(MRTCPusher *)pusher;

- (void)MRTCPusherDisconnected:(MRTCPusher *)pusher;

- (void)MRTCPusher:(MRTCPusher *)pusher pushFailed:(MRTCError *)error;

@end

@protocol MRTCPusherErrorDelegate <NSObject>

- (void)MRTCPusher:(MRTCPusher *)pusher didReceiveError:(MRTCError *)error;

@end


@interface MRTCPusher : NSObject

@property (nonatomic, assign) MRTCPushState pushState;

@property (nonatomic, weak) id<MRTCPusherDelegate> pusherDelegate;
@property (nonatomic, weak) id<MRTCPusherErrorDelegate> errorDelegate;

- (instancetype)initWithSetting:(MRTCSetting *)setting errorDelegate:(id<MRTCPusherErrorDelegate>)errorDelegate;

/**
 Send a view to preview your stream
 
 @param view A view to display your stream
 */
- (void)startPreviewWithView:(UIView *)view;

/**
 Stop preview your stream
 */
- (void)stopPreview;

/**
 Start push your stream
 */
- (void)startPushWithUrl:(NSString *)url delegate:(id<MRTCPusherDelegate>)delegate;

/**
 Stop push your stream
 */
- (void)stopPush;

/**
 Stop push audio and video Steam then stop preview and remove preview view
 */
- (void)destory;

/**
 Set Video sender max bit rate;
 */
- (void)setMaxBitrate:(NSUInteger)bitrate;

/**
 Stop push video and audio stream
 */
- (void)pause;

/**
 Resume push video and audio stream
 */
- (void)resume;

/*       Microphone       */
- (void)mute;

- (void)unmute;

/*       Camera          */

- (void)switchCamera;

- (void)setFlashLight:(BOOL)on;

- (void)getStats:(void(^)(NSDictionary *stats))completionHandler;

- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END

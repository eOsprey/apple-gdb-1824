/*
 *     Generated by class-dump 3.3.4 (64 bit).
 *
 *     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2011 by Steve Nygard.
 */

#import "NSObject.h"

@class NSString, PBXLSDynamicLinkerImage;

@interface PBXGDB_BreakpointGDBContext : NSObject
{
    long long _gdbBreakpointNumber;
    int _status;
    NSString *_targetProductPath;
    PBXLSDynamicLinkerImage *_image;
    NSString *_address;
}

- (id)dynamicLinkerImage;
- (void)setDynamicLinkerImage:(id)arg1;
- (id)targetProductPath;
- (void)setTargetProductPath:(id)arg1;
- (id)address;
- (void)setAddress:(id)arg1;
- (int)breakpointStatus;
- (void)setBreakpointStatus:(int)arg1;
- (long long)gdbBreakpointNumber;
- (void)setGDBBreakpointNumber:(long long)arg1;
- (id)init;

@end


/*
 *     Generated by class-dump 3.3.4 (64 bit).
 *
 *     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2011 by Steve Nygard.
 */

#import <DebuggerGDB/PBXGDB_ContainingDataValue2.h>

@interface PBXGDB_FrameDataValue2 : PBXGDB_ContainingDataValue2
{
    BOOL _checkedForFrameSymbols;
    BOOL _hasSymbols;
}

- (long long)frameIndexContext;
- (BOOL)hasSymbols;
- (void)setHasSymbols:(BOOL)arg1;
- (void)didUpdateValues;
- (void)requestUpdateValues;
- (id)initWithDebugger:(id)arg1 threadID:(long long)arg2 frameIndex:(long long)arg3;

@end

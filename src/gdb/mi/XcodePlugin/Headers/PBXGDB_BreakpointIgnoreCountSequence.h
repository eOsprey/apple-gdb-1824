/*
 *     Generated by class-dump 3.3.4 (64 bit).
 *
 *     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2011 by Steve Nygard.
 */

#import "PBXGDB_BaseBreakpointSequence.h"

@interface PBXGDB_BreakpointIgnoreCountSequence : PBXGDB_BaseBreakpointSequence
{
    long long _ignoreCount;
    long long _breakpointNum;
}

+ (id)sequenceWithIgnoreCount:(long long)arg1 forBreakpointNum:(long long)arg2;
- (void)_setIgnoreCount:(id)arg1;
- (void)execute;

@end


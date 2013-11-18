/*
 *     Generated by class-dump 3.3.4 (64 bit).
 *
 *     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2011 by Steve Nygard.
 */

#import <DebuggerGDB/PBXLSDataValue.h>

#import "PBXGDB_MICommandExecutionContext-Protocol.h"

@interface PBXGDB_DataValue2 : PBXLSDataValue <PBXGDB_MICommandExecutionContext>
{
    long long _threadIDContext;
    long long _frameIndexContext;
    unsigned long long _staticNumberOfChildren;
}

- (unsigned long long)staticNumberOfChildren;
- (void)setStaticNumberOfChildren:(unsigned long long)arg1;
- (id)threadContext;
- (id)gdbAdaptor;
- (void)setFrameIndexContext:(long long)arg1;
- (long long)frameIndexContext;
- (long long)threadIdContext;
- (id)initWithDebugger:(id)arg1;

@end

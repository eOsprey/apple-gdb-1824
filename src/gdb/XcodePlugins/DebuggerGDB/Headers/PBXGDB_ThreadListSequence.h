/*
 *     Generated by class-dump 3.3.4 (64 bit).
 *
 *     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2011 by Steve Nygard.
 */

#import <DebuggerGDB/PBXGDB_BaseThreadSequence.h>

@interface PBXGDB_ThreadListSequence : PBXGDB_BaseThreadSequence
{
    long long _currentThreadID;
    int _threadState;
    int _suspendedStatus;
    BOOL _didGetThreadListCommand;
    BOOL _didGetPIDCommand;
    BOOL _didSupportsUnicharXcode_CFCommand;
}

- (BOOL)handleErrorForMICommand:(id)arg1;
- (void)execute;
- (void)_statusOfLoadIntrospectionLibraryLoad:(id)arg1;
- (void)_finishLoadIntrospectionLibrary:(id)arg1;
- (void)_loadIntrospectionLibrary_load;
- (void)_loadIntrospectionLibrary_didCheckSafety:(id)arg1;
- (void)_loadIntrospectionLibrary_checkSafety;
- (void)_loadIntrospectionLibrary_verifySafetyCmd:(id)arg1;
- (void)_loadIntrospectionLibrary_legacy;
- (void)_getSupportsUnicharXcode_CFDataFormatters_didFinish:(id)arg1;
- (void)_getSupportsUnicharXcode_CFDataFormatters;
- (void)_loadIntrospectionSupport_didFinish:(id)arg1;
- (void)_loadIntrospectionSupport_load;
- (void)_loadIntrospectionSupport_verifyCmd:(id)arg1;
- (void)_loadIntrospectionLibrary;
- (void)_gotpid:(id)arg1;
- (void)_getPID;
- (void)_getThreadList;
- (void)_resultProcessStarted:(id)arg1;
- (void)_gotResultThreadList:(id)arg1;
- (int)suspendedStatus;
- (void)setSuspendedStatus:(int)arg1;
- (long long)currentThreadID;
- (void)setCurrentThreadID:(long long)arg1;
- (int)threadState;
- (void)setThreadState:(int)arg1;

@end

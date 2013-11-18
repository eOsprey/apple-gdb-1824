/*
 *     Generated by class-dump 3.3.4 (64 bit).
 *
 *     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2011 by Steve Nygard.
 */

#import <DebuggerGDB/PBXGDB_Controller.h>

@class NSMutableArray, NSMutableDictionary, PBXGDB_MIParser, PBXGDB_MIStoppedState;

@interface PBXGDB_MIController : PBXGDB_Controller
{
    PBXGDB_MIParser *_parser;
    NSMutableArray *_outstandingCommands;
    NSMutableArray *_pendingCommands;
    NSMutableArray *_pendingInterruptCommands;
    int _miState;
    int _interruptState;
    int _interruptType;
    PBXGDB_MIStoppedState *_stoppedState;
    long long _currentThreadIdContext;
    long long _currentFrameIndexContext;
    BOOL _sendRawCommand;
    long long _historyBufferSize;
    struct __HistoryBufferNode *_historyBuffer;
    long long _historyBufferCurrentIndex;
    NSMutableDictionary *_miCommandVerifyStatusDictionary;
    unsigned long long _numTriesThreadSelect;
    unsigned long long _numTriesFrameSelect;
}

- (BOOL)sendRawCommand;
- (void)processAsynchronousNotification:(id)arg1;
- (void)processAsynchronousResult:(id)arg1;
- (void)processSynchronousResult:(id)arg1;
- (void)_processResultList:(id)arg1 syncResult:(BOOL)arg2;
- (void)disableWatchpointWithExpression:(id)arg1;
- (void)_evaluateStoppedStateInResultList:(id)arg1;
- (void)_resetStoppedState;
- (void)didAttachToTarget;
- (id)stoppedState;
- (void)_extractHookResultsFromList:(id)arg1;
- (void)continueFromImplicitInterrupt;
- (void)postPendableCommand:(id)arg1;
- (void)postCommand:(id)arg1;
- (void)postCommand:(id)arg1 interruptIfNeeded:(BOOL)arg2;
- (void)_postThreadSelect:(id)arg1;
- (void)_gotThreadSelect:(id)arg1;
- (void)_attemptPostFrameSelect:(id)arg1;
- (void)_postFrameSelect:(id)arg1;
- (void)_gotFrameSelect:(id)arg1;
- (void)_reallyPostCommand:(id)arg1;
- (void)interruptGDBOfType:(int)arg1;
- (void)forceInterruptGDB;
- (void)_performInterrupt;
- (void)_sendAndLogCommandString:(id)arg1 withLogComment:(id)arg2;
- (int)interruptType;
- (void)setInterruptType:(int)arg1;
- (int)interruptState;
- (void)setInterruptState:(int)arg1;
- (int)miState;
- (void)setMIState:(int)arg1;
- (BOOL)areCommandsOutstanding;
- (id)outstandingCommandForSequenceNumber:(unsigned long long)arg1;
- (void)purgeOutstandingCommands;
- (void)removeOutstandingCommand:(id)arg1;
- (void)saveOutstandingCommand:(id)arg1;
- (void)_sendPendingInterruptCommands;
- (void)_enqueuePendingInterruptCommand:(id)arg1;
- (void)deactivate;
- (void)sendPendedCommand;
- (BOOL)havePendingCommands;
- (id)dequeueAndRetainPendingingCommand;
- (void)enqueuePendingCommand:(id)arg1;
- (id)parser;
- (void)invalidateThreadAndFrameContexts;
- (int)verifyStatusForMICommand:(id)arg1;
- (void)setVerifyStatus:(int)arg1 forMICommand:(id)arg2;
- (long long)currentThreadIdContext;
- (id)init;

@end

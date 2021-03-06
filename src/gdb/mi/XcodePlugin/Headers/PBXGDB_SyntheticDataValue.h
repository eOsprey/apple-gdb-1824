/*
 *     Generated by class-dump 3.3.4 (64 bit).
 *
 *     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2011 by Steve Nygard.
 */

#import "PBXGDB_DataValue2.h"

#import "PBXGDB_ContainedDataValueSecondaryUpdating-Protocol.h"

@class NSMutableDictionary, PBXGDB_EvalOperation, PBXGDB_ObjCDynamicTypeOperation, XCUnretainedReference;

@interface PBXGDB_SyntheticDataValue : PBXGDB_DataValue2 <PBXGDB_ContainedDataValueSecondaryUpdating>
{
    PBXGDB_EvalOperation *_contentSummaryFetchOperation;
    PBXGDB_EvalOperation *_contentValueFetchOperation;
    PBXGDB_ObjCDynamicTypeOperation *_objcDynamicVerifyOp;
    NSMutableDictionary *_contextDictionary;
    XCUnretainedReference *_secondaryUpdateFinishTarget;
    SEL _secondaryUpdateFinishAction;
    BOOL _needsSecondaryUpdate;
    long long _numPendingSecondaryUpdateChildren;
}

+ (id)contentSummaryResultKey;
+ (id)contentValueResultKey;
+ (id)baseValueResultKey;
+ (id)variableExpressionStringKey;
+ (id)variableValueStringKey;
- (void)didGetChildren;
- (void)_childDidFinishSecondaryUpdate:(id)arg1;
- (void)requestSecondaryUpdate;
- (void)_doStep_BeginSummaryUpdate;
- (void)_doStep_VerifyBaseValueDynamicType;
- (void)_dynamicVerifyOfBaseValueDidFinish:(id)arg1;
- (void)_doStep_ContentValueFetch;
- (void)_fetchValueOpDidFinish:(id)arg1;
- (void)_doStep_ContentSummaryFetch;
- (void)_contentSummaryFetchOpDidFinish:(id)arg1;
- (void)_doStep_UpdateFromContentSummaryResultAndFinish;
- (id)_formatStringForSummary;
- (void)_doStep_SetSummaryToStringAndFinish:(id)arg1;
- (void)_doStep_FinishSummaryUpdate;
- (id)contentSummaryResult;
- (void)setContentSummaryResult:(id)arg1;
- (id)contentValueResult;
- (void)setContentValueResult:(id)arg1;
- (id)baseValueResult;
- (void)setBaseValueResult:(id)arg1;
- (id)objcDynamicVerifyOperation;
- (void)setObjCDynamicVerifyOperation:(id)arg1;
- (id)contentValueFetchOperation;
- (void)setContentValueFetchOperation:(id)arg1;
- (id)contentSummaryFetchOperation;
- (void)setContentSummaryFetchOperation:(id)arg1;
- (void)_setupFetchOperationFromType:(id)arg1 operationClassNameKey:(id)arg2 currentFetchOperation:(id)arg3 setterSelector:(SEL)arg4;
- (SEL)secondaryUpdateFinishAction;
- (void)setSecondaryUpdateFinishAction:(SEL)arg1;
- (id)secondaryUpdateTarget;
- (void)setSecondaryUpdateFinishTarget:(id)arg1;
- (id)contextDictionary;
- (void)setContextDictionary:(id)arg1;
- (void)setViewAsType:(id)arg1;
- (void)setBaseType:(id)arg1;
- (void)_updateToStaticType;
- (BOOL)needsSecondaryUpdate;
- (void)setNeedsSecondaryUpdate:(BOOL)arg1;
- (void)dealloc;

@end


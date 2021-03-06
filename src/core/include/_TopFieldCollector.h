/////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2009-2011 Alan Wright. All rights reserved.
// Distributable under the terms of either the Apache License (Version 2.0)
// or the GNU Lesser General Public License.
/////////////////////////////////////////////////////////////////////////////

#ifndef _TOPFIELDCOLLECTOR_H
#define _TOPFIELDCOLLECTOR_H

#include "TopDocsCollector.h"

namespace Lucene
{
    /// Implements a TopFieldCollector over one SortField criteria, without tracking document scores and maxScore.
    class OneComparatorNonScoringCollector : public TopFieldCollector
    {
    public:
        OneComparatorNonScoringCollector(FieldValueHitQueuePtr queue, int32_t numHits, bool fillFields);
        virtual ~OneComparatorNonScoringCollector();
    
        LUCENE_CLASS(OneComparatorNonScoringCollector);
    
    public:
        FieldComparatorPtr comparator;
        int32_t reverseMul;
    
    public:
        virtual void initialize();        
        virtual void updateBottom(int32_t doc);
        virtual void collect(int32_t doc);
        virtual void setNextReader(IndexReaderPtr reader, int32_t docBase);
        virtual void setScorer(ScorerPtr scorer);
    };
    
    /// Implements a TopFieldCollector over one SortField criteria, without tracking document scores and maxScore, 
    /// and assumes out of orderness in doc Ids collection.
    class OutOfOrderOneComparatorNonScoringCollector : public OneComparatorNonScoringCollector
    {
    public:
        OutOfOrderOneComparatorNonScoringCollector(FieldValueHitQueuePtr queue, int32_t numHits, bool fillFields);
        virtual ~OutOfOrderOneComparatorNonScoringCollector();
    
        LUCENE_CLASS(OutOfOrderOneComparatorNonScoringCollector);
    
    public:
        virtual void collect(int32_t doc);
        virtual bool acceptsDocsOutOfOrder();
    };
    
    /// Implements a TopFieldCollector over one SortField criteria, while tracking document scores but no maxScore.
    class OneComparatorScoringNoMaxScoreCollector : public OneComparatorNonScoringCollector
    {
    public:
        OneComparatorScoringNoMaxScoreCollector(FieldValueHitQueuePtr queue, int32_t numHits, bool fillFields);
        virtual ~OneComparatorScoringNoMaxScoreCollector();
    
        LUCENE_CLASS(OneComparatorScoringNoMaxScoreCollector);
    
    public:
        ScorerPtr scorer;
    
    public:
        virtual void updateBottom(int32_t doc, double score);
        virtual void collect(int32_t doc);
        virtual void setScorer(ScorerPtr scorer);
    };
    
    /// Implements a TopFieldCollector over one SortField criteria, while tracking document scores but no maxScore, 
    /// and assumes out of orderness in doc Ids collection.
    class OutOfOrderOneComparatorScoringNoMaxScoreCollector : public OneComparatorScoringNoMaxScoreCollector
    {
    public:
        OutOfOrderOneComparatorScoringNoMaxScoreCollector(FieldValueHitQueuePtr queue, int32_t numHits, bool fillFields);
        virtual ~OutOfOrderOneComparatorScoringNoMaxScoreCollector();
    
        LUCENE_CLASS(OutOfOrderOneComparatorScoringNoMaxScoreCollector);
    
    public:
        virtual void collect(int32_t doc);
        virtual bool acceptsDocsOutOfOrder();
    };
    
    /// Implements a TopFieldCollector over one SortField criteria, with tracking document scores and maxScore.
    class OneComparatorScoringMaxScoreCollector : public OneComparatorNonScoringCollector
    {
    public:
        OneComparatorScoringMaxScoreCollector(FieldValueHitQueuePtr queue, int32_t numHits, bool fillFields);
        virtual ~OneComparatorScoringMaxScoreCollector();
    
        LUCENE_CLASS(OneComparatorScoringMaxScoreCollector);
    
    public:
        ScorerPtr scorer;
    
    public:
        virtual void updateBottom(int32_t doc, double score);
        virtual void collect(int32_t doc);
        virtual void setScorer(ScorerPtr scorer);
    };
    
    /// Implements a TopFieldCollector over one SortField criteria, with tracking document scores and maxScore, 
    /// and assumes out of orderness in doc Ids collection.
    class OutOfOrderOneComparatorScoringMaxScoreCollector : public OneComparatorScoringMaxScoreCollector
    {
    public:
        OutOfOrderOneComparatorScoringMaxScoreCollector(FieldValueHitQueuePtr queue, int32_t numHits, bool fillFields);
        virtual ~OutOfOrderOneComparatorScoringMaxScoreCollector();
    
        LUCENE_CLASS(OutOfOrderOneComparatorScoringMaxScoreCollector);
    
    public:
        virtual void collect(int32_t doc);
        virtual bool acceptsDocsOutOfOrder();
    };
    
    /// Implements a TopFieldCollector over multiple SortField criteria, without tracking document scores and maxScore.
    class MultiComparatorNonScoringCollector : public TopFieldCollector
    {
    public:
        MultiComparatorNonScoringCollector(FieldValueHitQueuePtr queue, int32_t numHits, bool fillFields);
        virtual ~MultiComparatorNonScoringCollector();
    
        LUCENE_CLASS(MultiComparatorNonScoringCollector);
    
    public:
        Collection<FieldComparatorPtr> comparators;
        Collection<int32_t> reverseMul;
    
    public:
        virtual void initialize();
        virtual void updateBottom(int32_t doc);
        virtual void collect(int32_t doc);
        virtual void setNextReader(IndexReaderPtr reader, int32_t docBase);
        virtual void setScorer(ScorerPtr scorer);
    };
    
    /// Implements a TopFieldCollector over multiple SortField criteria, without tracking document scores and maxScore.
    class OutOfOrderMultiComparatorNonScoringCollector : public MultiComparatorNonScoringCollector
    {
    public:
        OutOfOrderMultiComparatorNonScoringCollector(FieldValueHitQueuePtr queue, int32_t numHits, bool fillFields);
        virtual ~OutOfOrderMultiComparatorNonScoringCollector();
    
        LUCENE_CLASS(OutOfOrderMultiComparatorNonScoringCollector);
    
    public:
        virtual void collect(int32_t doc);
        virtual bool acceptsDocsOutOfOrder();
    };
    
    /// Implements a TopFieldCollector over multiple SortField criteria, with tracking document scores and maxScore.
    class MultiComparatorScoringMaxScoreCollector : public MultiComparatorNonScoringCollector
    {
    public:
        MultiComparatorScoringMaxScoreCollector(FieldValueHitQueuePtr queue, int32_t numHits, bool fillFields);
        virtual ~MultiComparatorScoringMaxScoreCollector();
    
        LUCENE_CLASS(MultiComparatorScoringMaxScoreCollector);
    
    public:
        ScorerWeakPtr _scorer;
    
    public:
        virtual void updateBottom(int32_t doc, double score);
        virtual void collect(int32_t doc);
        virtual void setScorer(ScorerPtr scorer);
    };
    
    /// Implements a TopFieldCollector over multiple SortField criteria, without tracking document scores and maxScore.
    class OutOfOrderMultiComparatorScoringMaxScoreCollector : public MultiComparatorScoringMaxScoreCollector
    {
    public:
        OutOfOrderMultiComparatorScoringMaxScoreCollector(FieldValueHitQueuePtr queue, int32_t numHits, bool fillFields);
        virtual ~OutOfOrderMultiComparatorScoringMaxScoreCollector();
    
        LUCENE_CLASS(OutOfOrderMultiComparatorScoringMaxScoreCollector);
    
    public:
        virtual void collect(int32_t doc);
        virtual bool acceptsDocsOutOfOrder();
    };
    
    /// Implements a TopFieldCollector over multiple SortField criteria, with tracking document scores and maxScore.
    class MultiComparatorScoringNoMaxScoreCollector : public MultiComparatorNonScoringCollector
    {
    public:
        MultiComparatorScoringNoMaxScoreCollector(FieldValueHitQueuePtr queue, int32_t numHits, bool fillFields);
        virtual ~MultiComparatorScoringNoMaxScoreCollector();
    
        LUCENE_CLASS(MultiComparatorScoringNoMaxScoreCollector);
    
    public:
        ScorerWeakPtr _scorer;
    
    public:
        virtual void updateBottom(int32_t doc, double score);
        virtual void collect(int32_t doc);
        virtual void setScorer(ScorerPtr scorer);
    };
    
    /// Implements a TopFieldCollector over multiple SortField criteria, with tracking document scores and maxScore, 
    /// and assumes out of orderness in doc Ids collection.
    class OutOfOrderMultiComparatorScoringNoMaxScoreCollector : public MultiComparatorScoringNoMaxScoreCollector
    {
    public:
        OutOfOrderMultiComparatorScoringNoMaxScoreCollector(FieldValueHitQueuePtr queue, int32_t numHits, bool fillFields);
        virtual ~OutOfOrderMultiComparatorScoringNoMaxScoreCollector();
    
        LUCENE_CLASS(OutOfOrderMultiComparatorScoringNoMaxScoreCollector);
    
    public:
        virtual void collect(int32_t doc);
        virtual void setScorer(ScorerPtr scorer);
        virtual bool acceptsDocsOutOfOrder();
    };
}

#endif

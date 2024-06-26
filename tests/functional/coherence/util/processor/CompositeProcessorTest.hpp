/*
 * Copyright (c) 2000, 2020, Oracle and/or its affiliates.
 *
 * Licensed under the Universal Permissive License v 1.0 as shown at
 * http://oss.oracle.com/licenses/upl.
 */
#include "cxxtest/TestSuite.h"
#include "coherence/lang.ns"
#include "coherence/net/NamedCache.hpp"
#include "coherence/util/ValueManipulator.hpp"
#include "coherence/util/processor/CompositeProcessor.hpp"
#include "coherence/util/processor/NumberIncrementor.hpp"
#include "coherence/util/processor/NumberMultiplier.hpp"

using namespace coherence::lang;

using coherence::net::NamedCache;
using coherence::util::ValueManipulator;
using coherence::util::processor::CompositeProcessor;
using coherence::util::processor::NumberIncrementor;
using coherence::util::processor::NumberMultiplier;

/**
 * Test Suite for the CompositeProcessor.
 */
class CompositeProcessorSuite : public CxxTest::TestSuite
    {
public:
    /**
     * Test CompositeProcessor
     */
    void testCompositeProcessor()
        {
        NamedCache::Handle hCache = ensureCleanCache("dist-processor");

        for (size32_t x = 0; x < 5; ++x)
            {
            Integer32::View vKey = Integer32::create(x);
            Integer32::View vValue = Integer32::create(1);

            hCache->put(vKey, vValue);
            }

        NumberIncrementor::Handle vNumberIncrementor = NumberIncrementor::
            create((ValueManipulator::View) NULL, Integer32::create(2), false);
        NumberMultiplier::Handle vNumberMultiplier = NumberMultiplier::
            create((ValueManipulator::View) NULL, Integer32::create(3), false);

        ObjectArray::Handle vaProcessor = ObjectArray::create(2);
        vaProcessor[0] = vNumberIncrementor;
        vaProcessor[0] = vNumberMultiplier;

        CompositeProcessor::Handle vCompositeProcessor = CompositeProcessor::create(vaProcessor);

// TODO ...
        //        hCache->invoke(Integer32::create(3), vCompositeProcessor);
//TODO ... what to assert?
        }
    };

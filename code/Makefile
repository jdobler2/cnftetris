UNAME = $(shell uname -s)

OBJS = Relation.o term_control.o error_handling.o algos.o \
       BFSRelation.o DegreeRelation.o SimpleRelation.o SIMD_Relation.o \
	   SIMD_RLERelation.o SIMD_HybridRelation.o subgraphcount.o trie.o \
	   TrieRelation.o IntervalTrie.o TrieActors.o ArrayTrie.o \
	   FertileIntervalTrie.o IterTrieRelation.o PlaneTrie.o \
	   IntArrayTrie.o IntIntervalTrie.o IntFITrie.o IntPlaneTrie.o \
	   IntTrieRelation.o FixedIITrie.o PointerTrie.o CNFIntTrieRelation.o \
	   SmallIntArrayTrie.o ZipIntTrie.o TreedLib/libtreed.a \
	   GroupedIntArrayTrie.o SIMD_GIATrie.o SmallIntArrayTrie2.o \
	   ZipIntTrie2.o SIMD_InnerGIAT.o Base121TrieRelation.o \
	   SIMD_InnerGIAT2.o SIMD_GIATrie2.o Base121TrieRelation_Tables.o\
	   varMap.o varMapDef.cpp DegreeDesc.o Treewidth.o FullDegreeDesc.o \
	   SIMD_SkippingInnerGIAT.o Fourwidth.o Orderer.o Minfill.o Preprocessor.o \
	   Base243TrieRelation.o Base243TrieRelation_Tables.o Base243GIAT.o \
	   Base243InnerGIAT.o BigOr243Trie.o SamplerOrderer.o \
	   B243BunchedInnerGIAT.o LocksOrder.o KillOrder.o Locks243Relation.o
	   
CC = g++ -g
DEBUG = -g
LIBDIR = /libtree

ifeq (${UNAME}, Darwin)
   CFLAGS = -Wall -std=c++0x -pedantic -O3 $(DEBUG) #-DBOOST_THREAD_USE_LIB $(DEBUG)
   LFLAGS = -lboost_thread-mt -lboost_system -lboost_iostreams
   DELCOMMAND = rm -f
else
   ifeq (${UNAME}, Linux)
      CFLAGS = -std=c++0x -O3 -DBOOST_THREAD_USE_LIB $(DEBUG)
      LFLAGS = -lboost_thread -lboost_iostreams -lboost_system TreedLib/libtreed.a
      DELCOMMAND = rm -f
   else 
      CFLAGS = -O3 -std=c++0x -I ../../boost_1_55_0 
      LFLAGS = ../../boost_1_55_0/stage/lib/libboost_thread-mgw48-mt-d-1_55.a \
            ../../boost_1_55_0/stage/lib/libboost_system-mgw48-mt-d-1_55.a \
            ../../boost_1_55_0/stage/lib/libboost_iostreams-mgw48-mt-d-1_55.a \
			-lws2_32 -Wl,--large-address-aware \
			TreedLib/libtreed.a
      DELCOMMAND = del
   endif
endif

subgraphcount: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LFLAGS) -o subgraphcount 

subgraphcount.o: subgraphcount.cpp error_handling.h algos.h term_control.h \
                 Relation.h BFSRelation.h SimpleRelation.h SIMD_Relation.h \
				 SIMD_RLERelation.h SIMD_HybridRelation.h
	$(CC) -c $(CFLAGS) subgraphcount.cpp -msse4.2

algos.o : algos.cpp algos.h error_handling.h term_control.h Relation.h
	$(CC) -c $(CFLAGS) algos.cpp
	
ArrayTrie.o : ArrayTrie.h ArrayTrie.cpp GenericTrie.h 
	$(CC) -c $(CFLAGS) ArrayTrie.cpp
	
Base121TrieRelation.o: Base121TrieRelation.cpp Base121TrieRelation.h \
					CNFIntTrieRelation.h \
					TrieActors.h GenericIntTrie.h SmallIntArrayTrie.h \
					Relation.h IntTrieRelation.h
	$(CC) -c $(CFLAGS) Base121TrieRelation.cpp
	
Base121TrieRelation_Tables.o: Base121TrieRelation_Tables.cpp
	$(CC) -c $(CFLAGS) Base121TrieRelation_Tables.cpp
	
Base243TrieRelation.o: Base243TrieRelation.cpp Base243TrieRelation.h \
					Base121TrieRelation.h CNFIntTrieRelation.h \
					TrieActors.h GenericIntTrie.h SmallIntArrayTrie.h \
					Relation.h IntTrieRelation.h
	$(CC) -c $(CFLAGS) Base243TrieRelation.cpp -mavx2
	
Base243TrieRelation_Tables.o: Base243TrieRelation_Tables.cpp
	$(CC) -c $(CFLAGS) Base243TrieRelation_Tables.cpp -mavx2
	
Base243GIAT.o: Base243GIAT.h Base243GIAT.cpp SIMD_GIATrie.h TrieActors.h
	$(CC) -c $(CFLAGS) Base243GIAT.cpp -mavx2
	
Base243InnerGIAT.o: Base243GIAT.h Base243InnerGIAT.h Base243InnerGIAT.cpp \
					SIMD_GIATrie.h TrieActors.h
	$(CC) -c $(CFLAGS) Base243InnerGIAT.cpp -mavx2

B243BunchedInnerGIAT.o: Base243GIAT.h B243BunchedInnerGIAT.h \
                        B243BunchedInnerGIAT.cpp SIMD_GIATrie.h TrieActors.h
	$(CC) -c $(CFLAGS) B243BunchedInnerGIAT.cpp -mavx2

Locks243Relation.o: Base243TrieRelation.o Locks243Relation.h Locks243Relation.cpp
	$(CC) -c $(CFLAGS) Locks243Relation.cpp -mavx2
	
BigOr243Trie.o: BigOr243Trie.h BigOr243Trie.cpp Base243GIAT.h SIMD_GIATrie.h TrieActors.h
	$(CC) -c $(CFLAGS) BigOr243Trie.cpp -mavx2
	
error_handling.o : term_control.o error_handling.h error_handling.cpp
	$(CC) -c $(CFLAGS) error_handling.cpp

term_control.o : term_control.h term_control.cpp
	$(CC) -c $(CFLAGS) term_control.cpp
	
DegreeDesc.o: Orderer.h DegreeDesc.h DegreeDesc.cpp
	$(CC) -c $(CFLAGS) DegreeDesc.cpp
	
Fourwidth.o: Orderer.h Fourwidth.h Fourwidth.cpp
	$(CC) -c $(CFLAGS) Fourwidth.cpp
	
FullDegreeDesc.o: Orderer.h FullDegreeDesc.h FullDegreeDesc.cpp
	$(CC) -c $(CFLAGS) FullDegreeDesc.cpp
	
LocksOrder.o: Orderer.h LocksOrder.h LocksOrder.cpp
	$(CC) -c $(CFLAGS) LocksOrder.cpp
	
KillOrder.o: Orderer.h KillOrder.h KillOrder.cpp
	$(CC) -c $(CFLAGS) KillOrder.cpp

DegreeRelation.o: Relation.h BFSRelation.h DegreeRelation.cpp DegreeRelation.h
	$(CC) -c $(CFLAGS) DegreeRelation.cpp

BFSRelation.o: Relation.h BFSRelation.h BFSRelation.cpp
	$(CC) -c $(CFLAGS) BFSRelation.cpp

SIMD_Relation.o: Relation.h BFSRelation.h SIMD_Relation.h SIMD_Relation.cpp \
                 error_handling.h
	$(CC) -c $(CFLAGS) SIMD_Relation.cpp -msse4.2

SimpleRelation.o: Relation.h SimpleRelation.h SimpleRelation.cpp
	$(CC) -c $(CFLAGS) SimpleRelation.cpp

Relation.o: Relation.h Relation.cpp utils.h
	$(CC) -c $(CFLAGS) Relation.cpp

SIMD_RLERelation.o: Relation.h SIMD_Relation.h SIMD_RLERelation.h \
                    SIMD_RLERelation.cpp utils.h
	$(CC) -c $(CFLAGS) SIMD_RLERelation.cpp -msse4.2

SIMD_HybridRelation.o: Relation.h SIMD_Relation.h SIMD_HybridRelation.h \
                       SIMD_HybridRelation.cpp
	$(CC) -c $(CFLAGS) SIMD_HybridRelation.cpp -msse4.2
	
trie.o: trie.h trie.cpp GenericTrie.h
	$(CC) -c $(CFLAGS) trie.cpp
	
Treewidth.o: Orderer.h Treewidth.h Treewidth.cpp
	$(CC) -c $(CFLAGS) Treewidth.cpp -L$(LIBDIR) -ltreed
	
IntervalTrie.o: IntervalTrie.h IntervalTrie.cpp trie.h GenericTrie.h
	$(CC) -c $(CFLAGS) IntervalTrie.cpp
	
FertileIntervalTrie.o: FertileIntervalTrie.h FertileIntervalTrie.cpp trie.h \
                       GenericTrie.h IntervalTrie.h
	$(CC) -c $(CFLAGS) FertileIntervalTrie.cpp

PlaneTrie.o: PlaneTrie.h IntervalTrie.h PlaneTrie.cpp GenericTrie.h
	$(CC) -c $(CFLAGS) PlaneTrie.cpp
	
IntArrayTrie.o: IntArrayTrie.h GenericIntTrie.h IntArrayTrie.cpp TrieActors.h \
				PointerTrie.h IntIntervalTrie.h IntFITrie.h IntPlaneTrie.h \
				FixedIITrie.h
	$(CC) -c $(CFLAGS) IntArrayTrie.cpp
	
IntIntervalTrie.o: IntIntervalTrie.h IntIntervalTrie.cpp GenericIntTrie.h \
                   TrieActors.h
	$(CC) -c $(CFLAGS) IntIntervalTrie.cpp
	
FixedIITrie.o: FixedIITrie.h FixedIITrie.cpp GenericIntTrie.h TrieActors.h
	$(CC) -c $(CFLAGS) FixedIITrie.cpp
	
GroupedIntArrayTrie.o: GroupedIntArrayTrie.h SmallIntArrayTrie.h \
                       GroupedIntArrayTrie.cpp GenericIntTrie.h ZipIntTrie.h
	$(CC) -c $(CFLAGS) GroupedIntArrayTrie.cpp
		
SIMD_GIATrie.o: GenericIntTrie.h SmallIntArrayTrie.h ZipIntTrie.h \
                SIMD_GIATrie.h SIMD_GIATrie.cpp TrieActors.h
	$(CC) -c $(CFLAGS) SIMD_GIATrie.cpp -msse4.2
	
SIMD_InnerGIAT.o: GenericIntTrie.h SmallIntArrayTrie.h ZipIntTrie.h \
                SIMD_GIATrie.h SIMD_InnerGIAT.cpp TrieActors.h \
				SIMD_InnerGIAT.h 
	$(CC) -c $(CFLAGS) SIMD_InnerGIAT.cpp -mavx2

SIMD_InnerGIAT2.o: GenericIntTrie.h SmallIntArrayTrie.h ZipIntTrie.h \
                SIMD_GIATrie2.h SIMD_InnerGIAT2.cpp TrieActors.h \
				SIMD_InnerGIAT2.h
	$(CC) -c $(CFLAGS) SIMD_InnerGIAT2.cpp -msse4.2

SIMD_SkippingInnerGIAT.o: GenericIntTrie.h SmallIntArrayTrie.h ZipIntTrie.h\
                SIMD_GIATrie.h SIMD_SkippingInnerGIAT.cpp TrieActors.h \
				SIMD_SkippingInnerGIAT.h SIMD_InnerGIAT.h
	$(CC) -c $(CFLAGS) SIMD_SkippingInnerGIAT.cpp -msse4.2
	
SIMD_GIATrie2.o: GenericIntTrie.h SmallIntArrayTrie.h ZipIntTrie.h \
                SIMD_GIATrie2.h SIMD_GIATrie2.cpp TrieActors.h
	$(CC) -c $(CFLAGS) SIMD_GIATrie2.cpp -msse4.2
	
IntFITrie.o: IntFITrie.h IntFITrie.cpp GenericIntTrie.h TrieActors.h \
             IntIntervalTrie.h
	$(CC) -c $(CFLAGS) IntFITrie.cpp
	
IntPlaneTrie.o: IntPlaneTrie.h IntPlaneTrie.cpp GenericIntTrie.h TrieActors.h
	$(CC) -c $(CFLAGS) IntPlaneTrie.cpp

IntTrieRelation.o: IntTrieRelation.cpp TrieRelation.cpp GenericIntTrie.h \
                   TrieActors.h IntArrayTrie.h Relation.h IntTrieRelation.h
	$(CC) -c $(CFLAGS) IntTrieRelation.cpp

Minfill.o: Orderer.h Minfill.h Minfill.cpp
	$(CC) -c $(CFLAGS) Minfill.cpp
	
Orderer.o: Orderer.h Orderer.cpp
	$(CC) -c $(CFLAGS) Orderer.cpp

PointerTrie.o: GenericIntTrie.h TrieActors.h PointerTrie.h PointerTrie.cpp
	$(CC) -c $(CFLAGS) PointerTrie.cpp
	
Preprocessor.o: Preprocessor.h Preprocessor.cpp
	$(CC) -c $(CFLAGS) Preprocessor.cpp

TrieRelation.o: TrieRelation.cpp TrieRelation.h trie.h GenericTrie.h Relation.h \
				TrieActors.h
	$(CC) -c $(CFLAGS) TrieRelation.cpp
	
IterTrieRelation.o: IterTrieRelation.cpp TrieRelation.h trie.h GenericTrie.h \
                    IterTrieRelation.h Relation.h
	$(CC) -c $(CFLAGS) IterTrieRelation.cpp
	
TreedLib/libtreed.a: 
	$(MAKE) -C TreedLib/
	
CNFIntTrieRelation.o: CNFIntTrieRelation.cpp CNFIntTrieRelation.h \
                      TrieActors.h GenericIntTrie.h SmallIntArrayTrie.h \
				      Relation.h IntTrieRelation.h Preprocessor.h
	$(CC) -c $(CFLAGS) CNFIntTrieRelation.cpp
	
SamplerOrderer.o: SamplerOrderer.cpp Orderer.h SamplerOrderer.h
	$(CC) -c $(CFLAGS) SamplerOrderer.cpp
	
SmallIntArrayTrie.o: SmallIntArrayTrie.h SmallIntArrayTrie.cpp GenericIntTrie.h \
					 TrieActors.h IntArrayTrie.h ZipIntTrie.h
	$(CC) -c $(CFLAGS) SmallIntArrayTrie.cpp
	
SmallIntArrayTrie2.o: SmallIntArrayTrie2.h SmallIntArrayTrie2.cpp GenericIntTrie.h \
					 TrieActors.h IntArrayTrie.h ZipIntTrie.h
	$(CC) -c $(CFLAGS) SmallIntArrayTrie2.cpp
	
TrieActors.o: TrieActors.h TrieActors.cpp GenericTrie.h
	$(CC) -c $(CFLAGS) TrieActors.cpp
	
utils.o: utils.h utils.cpp
	$(CC) -c $(CFLAGS) utils.cpp
	
utils: utils.o
	$(CC) $(CFLAGS) utils.o $(LFLAGS) -o utils
	
varMap.o: varMap.h varMap.cpp
	$(CC) -c $(CFLAGS) varMap.cpp
	
ZipIntTrie.o: ZipIntTrie.h ZipIntTrie.cpp GenericIntTrie.h SmallIntArrayTrie.h
	$(CC) -c $(CFLAGS) ZipIntTrie.cpp
	
ZipIntTrie2.o: ZipIntTrie2.h ZipIntTrie2.cpp GenericIntTrie.h SmallIntArrayTrie2.h
	$(CC) -c $(CFLAGS) ZipIntTrie2.cpp
	
clean:
	$(DELCOMMAND) *.o a.out subgraphcount *.exe
	$(MAKE) -C TreedLib/ clean

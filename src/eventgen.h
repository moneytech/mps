/* impl.h.eventgen -- Automatic event header
 *
 * Copyright (C) 1997 Harlequin Group, all rights reserved.
 * $HopeName$
 *
 * !!! DO NOT EDIT THIS FILE !!!
 * This file was generated by eventgen.pl
 */

#ifdef EVENT

typedef struct {
  Word code;
  Word length;
  Word clock;
} EventStruct;

typedef struct {
  Word code;
  Word length;
  Word clock;
  WriteFA a0;
} EventAStruct;

typedef struct {
  Word code;
  Word length;
  Word clock;
  WriteFP p0;
} EventPStruct;

typedef struct {
  Word code;
  Word length;
  Word clock;
  WriteFP p0;
  WriteFA a1;
  WriteFA a2;
} EventPAAStruct;

typedef struct {
  Word code;
  Word length;
  Word clock;
  WriteFP p0;
  WriteFA a1;
  WriteFW w2;
} EventPAWStruct;

typedef struct {
  Word code;
  Word length;
  Word clock;
  WriteFP p0;
  WriteFP p1;
} EventPPStruct;

typedef struct {
  Word code;
  Word length;
  Word clock;
  WriteFP p0;
  WriteFP p1;
  WriteFA a2;
  WriteFA a3;
} EventPPAAStruct;

typedef struct {
  Word code;
  Word length;
  Word clock;
  WriteFP p0;
  WriteFP p1;
  WriteFA a2;
  WriteFU u3;
} EventPPAUStruct;

typedef struct {
  Word code;
  Word length;
  Word clock;
  WriteFP p0;
  WriteFP p1;
  WriteFA a2;
  WriteFW w3;
  WriteFP p4;
} EventPPAWPStruct;

typedef struct {
  Word code;
  Word length;
  Word clock;
  WriteFP p0;
  WriteFP p1;
  WriteFP p2;
} EventPPPStruct;

typedef struct {
  Word code;
  Word length;
  Word clock;
  WriteFP p0;
  WriteFP p1;
  WriteFP p2;
  WriteFP p3;
} EventPPPPStruct;

typedef struct {
  Word code;
  Word length;
  Word clock;
  WriteFP p0;
  WriteFP p1;
  WriteFP p2;
  WriteFU u3;
} EventPPPUStruct;

typedef struct {
  Word code;
  Word length;
  Word clock;
  WriteFP p0;
  WriteFP p1;
  WriteFU u2;
} EventPPUStruct;

typedef struct {
  Word code;
  Word length;
  Word clock;
  WriteFP p0;
  WriteFP p1;
  WriteFW w2;
} EventPPWStruct;

typedef struct {
  Word code;
  Word length;
  Word clock;
  WriteFP p0;
  WriteFP p1;
  WriteFW w2;
  WriteFA a3;
  WriteFW w4;
} EventPPWAWStruct;

typedef struct {
  Word code;
  Word length;
  Word clock;
  char s[1];
} EventSStruct;

typedef struct {
  Word code;
  Word length;
  Word clock;
  WriteFU u0;
  WriteFU u1;
  WriteFP p2;
  WriteFP p3;
  WriteFP p4;
} EventUUPPPStruct;


typedef union {
  EventStruct any;
  EventAStruct a;
  EventPStruct p;
  EventPAAStruct paa;
  EventPAWStruct paw;
  EventPPStruct pp;
  EventPPAAStruct ppaa;
  EventPPAUStruct ppau;
  EventPPAWPStruct ppawp;
  EventPPPStruct ppp;
  EventPPPPStruct pppp;
  EventPPPUStruct pppu;
  EventPPUStruct ppu;
  EventPPWStruct ppw;
  EventPPWAWStruct ppwaw;
  EventSStruct s;
  EventUUPPPStruct uuppp;
} EventUnion;


#define EVENT_0(type) \
  EVENT_BEGIN(type, 0, sizeof(EventStruct)) \
  EVENT_END(type, sizeof(EventStruct))

#define EVENT_A(type, _a0) \
  BEGIN \
    size_t _length = sizeof(EventAStruct); \
    EVENT_BEGIN(type, A, _length); \
    Event.a.a0 = (_a0); \
    EVENT_END(type, _length); \
  END

#define EVENT_P(type, _p0) \
  BEGIN \
    size_t _length = sizeof(EventPStruct); \
    EVENT_BEGIN(type, P, _length); \
    Event.p.p0 = (_p0); \
    EVENT_END(type, _length); \
  END

#define EVENT_PAA(type, _p0, _a1, _a2) \
  BEGIN \
    size_t _length = sizeof(EventPAAStruct); \
    EVENT_BEGIN(type, PAA, _length); \
    Event.paa.p0 = (_p0); \
    Event.paa.a1 = (_a1); \
    Event.paa.a2 = (_a2); \
    EVENT_END(type, _length); \
  END

#define EVENT_PAW(type, _p0, _a1, _w2) \
  BEGIN \
    size_t _length = sizeof(EventPAWStruct); \
    EVENT_BEGIN(type, PAW, _length); \
    Event.paw.p0 = (_p0); \
    Event.paw.a1 = (_a1); \
    Event.paw.w2 = (_w2); \
    EVENT_END(type, _length); \
  END

#define EVENT_PP(type, _p0, _p1) \
  BEGIN \
    size_t _length = sizeof(EventPPStruct); \
    EVENT_BEGIN(type, PP, _length); \
    Event.pp.p0 = (_p0); \
    Event.pp.p1 = (_p1); \
    EVENT_END(type, _length); \
  END

#define EVENT_PPAA(type, _p0, _p1, _a2, _a3) \
  BEGIN \
    size_t _length = sizeof(EventPPAAStruct); \
    EVENT_BEGIN(type, PPAA, _length); \
    Event.ppaa.p0 = (_p0); \
    Event.ppaa.p1 = (_p1); \
    Event.ppaa.a2 = (_a2); \
    Event.ppaa.a3 = (_a3); \
    EVENT_END(type, _length); \
  END

#define EVENT_PPAU(type, _p0, _p1, _a2, _u3) \
  BEGIN \
    size_t _length = sizeof(EventPPAUStruct); \
    EVENT_BEGIN(type, PPAU, _length); \
    Event.ppau.p0 = (_p0); \
    Event.ppau.p1 = (_p1); \
    Event.ppau.a2 = (_a2); \
    Event.ppau.u3 = (_u3); \
    EVENT_END(type, _length); \
  END

#define EVENT_PPAWP(type, _p0, _p1, _a2, _w3, _p4) \
  BEGIN \
    size_t _length = sizeof(EventPPAWPStruct); \
    EVENT_BEGIN(type, PPAWP, _length); \
    Event.ppawp.p0 = (_p0); \
    Event.ppawp.p1 = (_p1); \
    Event.ppawp.a2 = (_a2); \
    Event.ppawp.w3 = (_w3); \
    Event.ppawp.p4 = (_p4); \
    EVENT_END(type, _length); \
  END

#define EVENT_PPP(type, _p0, _p1, _p2) \
  BEGIN \
    size_t _length = sizeof(EventPPPStruct); \
    EVENT_BEGIN(type, PPP, _length); \
    Event.ppp.p0 = (_p0); \
    Event.ppp.p1 = (_p1); \
    Event.ppp.p2 = (_p2); \
    EVENT_END(type, _length); \
  END

#define EVENT_PPPP(type, _p0, _p1, _p2, _p3) \
  BEGIN \
    size_t _length = sizeof(EventPPPPStruct); \
    EVENT_BEGIN(type, PPPP, _length); \
    Event.pppp.p0 = (_p0); \
    Event.pppp.p1 = (_p1); \
    Event.pppp.p2 = (_p2); \
    Event.pppp.p3 = (_p3); \
    EVENT_END(type, _length); \
  END

#define EVENT_PPPU(type, _p0, _p1, _p2, _u3) \
  BEGIN \
    size_t _length = sizeof(EventPPPUStruct); \
    EVENT_BEGIN(type, PPPU, _length); \
    Event.pppu.p0 = (_p0); \
    Event.pppu.p1 = (_p1); \
    Event.pppu.p2 = (_p2); \
    Event.pppu.u3 = (_u3); \
    EVENT_END(type, _length); \
  END

#define EVENT_PPU(type, _p0, _p1, _u2) \
  BEGIN \
    size_t _length = sizeof(EventPPUStruct); \
    EVENT_BEGIN(type, PPU, _length); \
    Event.ppu.p0 = (_p0); \
    Event.ppu.p1 = (_p1); \
    Event.ppu.u2 = (_u2); \
    EVENT_END(type, _length); \
  END

#define EVENT_PPW(type, _p0, _p1, _w2) \
  BEGIN \
    size_t _length = sizeof(EventPPWStruct); \
    EVENT_BEGIN(type, PPW, _length); \
    Event.ppw.p0 = (_p0); \
    Event.ppw.p1 = (_p1); \
    Event.ppw.w2 = (_w2); \
    EVENT_END(type, _length); \
  END

#define EVENT_PPWAW(type, _p0, _p1, _w2, _a3, _w4) \
  BEGIN \
    size_t _length = sizeof(EventPPWAWStruct); \
    EVENT_BEGIN(type, PPWAW, _length); \
    Event.ppwaw.p0 = (_p0); \
    Event.ppwaw.p1 = (_p1); \
    Event.ppwaw.w2 = (_w2); \
    Event.ppwaw.a3 = (_a3); \
    Event.ppwaw.w4 = (_w4); \
    EVENT_END(type, _length); \
  END

#define EVENT_S(type, _s) \
  BEGIN \
    char *_s2 = (_s); \
    size_t _string_length = StringLength((_s2)); \
    size_t _length = \
      WordAlignUp(offsetof(EventSStruct, s) + \
                  _string_length + 1, sizeof(Word)); \
    EVENT_BEGIN(type, S, _length); \
    _memcpy(Event.s.s, (_s2), _string_length + 1); \
    EVENT_END(type, _length); \
  END

#define EVENT_UUPPP(type, _u0, _u1, _p2, _p3, _p4) \
  BEGIN \
    size_t _length = sizeof(EventUUPPPStruct); \
    EVENT_BEGIN(type, UUPPP, _length); \
    Event.uuppp.u0 = (_u0); \
    Event.uuppp.u1 = (_u1); \
    Event.uuppp.p2 = (_p2); \
    Event.uuppp.p3 = (_p3); \
    Event.uuppp.p4 = (_p4); \
    EVENT_END(type, _length); \
  END

#define EventFormat0 0
#define EventFormatA 1
#define EventFormatP 2
#define EventFormatPAA 3
#define EventFormatPAW 4
#define EventFormatPP 5
#define EventFormatPPAA 6
#define EventFormatPPAU 7
#define EventFormatPPAWP 8
#define EventFormatPPP 9
#define EventFormatPPPP 10
#define EventFormatPPPU 11
#define EventFormatPPU 12
#define EventFormatPPW 13
#define EventFormatPPWAW 14
#define EventFormatS 15
#define EventFormatUUPPP 16

#else /* EVENT not */

#define EVENT_0(type)    NOOP
#define EVENT_A(type, p0)    NOOP
#define EVENT_P(type, p0)    NOOP
#define EVENT_PAA(type, p0, p1, p2)    NOOP
#define EVENT_PAW(type, p0, p1, p2)    NOOP
#define EVENT_PP(type, p0, p1)    NOOP
#define EVENT_PPAA(type, p0, p1, p2, p3)    NOOP
#define EVENT_PPAU(type, p0, p1, p2, p3)    NOOP
#define EVENT_PPAWP(type, p0, p1, p2, p3, p4)    NOOP
#define EVENT_PPP(type, p0, p1, p2)    NOOP
#define EVENT_PPPP(type, p0, p1, p2, p3)    NOOP
#define EVENT_PPPU(type, p0, p1, p2, p3)    NOOP
#define EVENT_PPU(type, p0, p1, p2)    NOOP
#define EVENT_PPW(type, p0, p1, p2)    NOOP
#define EVENT_PPWAW(type, p0, p1, p2, p3, p4)    NOOP
#define EVENT_S(type, p0)    NOOP
#define EVENT_UUPPP(type, p0, p1, p2, p3, p4)    NOOP

#endif /* EVENT */

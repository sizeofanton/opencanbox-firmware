#pragma once
enum BaudRate {
  _10kbit       = 2u,
  _20kbit       = 3u,
  _50kbit       = 4u,
  _100kbit      = 5u,
  _125kbit      = 6u,
  _250kbit      = 7u,
  _500kbit      = 8u,
  _1000kbit     = 9u,
  BAUD_UNKNOWN  = 0u
};

#define BITRATE_10_BRP    92
#define BITRATE_10_SJW    0
#define BITRATE_10_TSEG1  15
#define BITRATE_10_TSEG2  7
#define BITRATE_10_SAM    1
#define BITRATE_10_BTR (BITRATE_10_SAM<<23)|(BITRATE_10_TSEG2<<20)|(BITRATE_10_TSEG1<<16)|(BITRATE_10_SJW<<14)|BITRATE_10_BRP 

#define BITRATE_20_BRP    49
#define BITRATE_20_SJW    0
#define BITRATE_20_TSEG1  15
#define BITRATE_20_TSEG2  7
#define BITRATE_20_SAM    1
#define BITRATE_20_BTR (BITRATE_20_SAM<<23)|(BITRATE_20_TSEG2<<20)|(BITRATE_20_TSEG1<<16)|(BITRATE_20_SJW<<14)|BITRATE_20_BRP 

#define BITRATE_50_BRP   19
#define BITRATE_50_SJW   0
#define BITRATE_50_TSEG1 15
#define BITRATE_50_TSEG2 7
#define BITRATE_50_SAM   1
#define BITRATE_50_BTR (BITRATE_50_SAM<<23)|(BITRATE_50_TSEG2<<20)|(BITRATE_50_TSEG1<<16)|(BITRATE_50_SJW<<14)|BITRATE_50_BRP

#define BITRATE_100_BRP   9
#define BITRATE_100_SJW   0
#define BITRATE_100_TSEG1 15
#define BITRATE_100_TSEG2 7
#define BITRATE_100_SAM   0
#define BITRATE_100_BTR (BITRATE_100_SAM<<23)|(BITRATE_100_TSEG2<<20)|(BITRATE_100_TSEG1<<16)|(BITRATE_100_SJW<<14)|BITRATE_100_BRP

#define BITRATE_125_BRP   7
#define BITRATE_125_SJW   0
#define BITRATE_125_TSEG1 15
#define BITRATE_125_TSEG2 7
#define BITRATE_125_SAM   1
#define BITRATE_125_BTR (BITRATE_125_SAM<<23)|(BITRATE_125_TSEG2<<20)|(BITRATE_125_TSEG1<<16)|(BITRATE_125_SJW<<14)|BITRATE_125_BRP

#define BITRATE_250_BRP   3
#define BITRATE_250_SJW   0
#define BITRATE_250_TSEG1 15
#define BITRATE_250_TSEG2 7
#define BITRATE_250_SAM   0
#define BITRATE_250_BTR (BITRATE_250_SAM<<23)|(BITRATE_250_TSEG2<<20)|(BITRATE_250_TSEG1<<16)|(BITRATE_250_SJW<<14)|BITRATE_250_BRP

#define BITRATE_500_BRP   1
#define BITRATE_500_SJW   0
#define BITRATE_500_TSEG1 15
#define BITRATE_500_TSEG2 7
#define BITRATE_500_SAM   0
#define BITRATE_500_BTR (BITRATE_500_SAM<<23)|(BITRATE_500_TSEG2<<20)|(BITRATE_500_TSEG1<<16)|(BITRATE_500_SJW<<14)|BITRATE_500_BRP

#define BITRATE_1000_BRP   0
#define BITRATE_1000_SJW   0
#define BITRATE_1000_TSEG1 15
#define BITRATE_1000_TSEG2 7
#define BITRATE_1000_SAM   0
#define BITRATE_1000_BTR (BITRATE_1000_SAM<<23)|(BITRATE_1000_TSEG2<<20)|(BITRATE_1000_TSEG1<<16)|(BITRATE_1000_SJW<<14)|BITRATE_1000_BRP


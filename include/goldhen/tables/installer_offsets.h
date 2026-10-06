/*
 * installer_offsets - per-firmware kernel offsets.
 *
 * One array per firmware; the values are the kernel-base-relative
 * offsets the payload uses on that release.
 */
#ifndef GOLDHEN_TABLES_INSTALLER_OFFSETS_H
#define GOLDHEN_TABLES_INSTALLER_OFFSETS_H

#include <stdint.h>

/* firmware 505 - 5 entries, 20 bytes */
static const uint32_t g_installer_offsets_505[5] = {
    0x0043612au, 0x000038ebu, 0x000fcd48u, 0x000fcd56u, 0x001ea53du,
};

/* firmware 671 - 5 entries, 20 bytes */
static const uint32_t g_installer_offsets_671[5] = {
    0x00123367u, 0x000038ebu, 0x002507f5u, 0x00250803u, 0x003c15bdu,
};

/* firmware 672 - 5 entries, 20 bytes */
static const uint32_t g_installer_offsets_672[5] = {
    0x00123367u, 0x000038ebu, 0x002507f5u, 0x00250803u, 0x003c15bdu,
};

/* firmware 702 - 5 entries, 20 bytes */
static const uint32_t g_installer_offsets_702[5] = {
    0x000bc817u, 0x00003bebu, 0x001171beu, 0x001171c6u, 0x0002f04du,
};

/* firmware 750 - 5 entries, 20 bytes */
static const uint32_t g_installer_offsets_750[5] = {
    0x0026f827u, 0x00003bebu, 0x001754acu, 0x001754b4u, 0x0028f80du,
};

/* firmware 751 - 5 entries, 20 bytes */
static const uint32_t g_installer_offsets_751[5] = {
    0x0026f827u, 0x00003bebu, 0x001754acu, 0x001754b4u, 0x0028f80du,
};

/* firmware 755 - 5 entries, 20 bytes */
static const uint32_t g_installer_offsets_755[5] = {
    0x0026f827u, 0x00003bebu, 0x001754acu, 0x001754b4u, 0x0028f80du,
};

/* firmware 800 - 5 entries, 20 bytes */
static const uint32_t g_installer_offsets_800[5] = {
    0x00430bc7u, 0x00003bebu, 0x0001b4bcu, 0x0001b4c4u, 0x0025e1cdu,
};

/* firmware 801 - 5 entries, 20 bytes */
static const uint32_t g_installer_offsets_801[5] = {
    0x00430bc7u, 0x00003bebu, 0x0001b4bcu, 0x0001b4c4u, 0x0025e1cdu,
};

/* firmware 803 - 5 entries, 20 bytes */
static const uint32_t g_installer_offsets_803[5] = {
    0x00430bc7u, 0x00003bebu, 0x0001b4bcu, 0x0001b4c4u, 0x0025e1cdu,
};

/* firmware 850 - 5 entries, 20 bytes */
static const uint32_t g_installer_offsets_850[5] = {
    0x0015d657u, 0x00003bebu, 0x00219a6cu, 0x00219a74u, 0x003a40fdu,
};

/* firmware 852 - 5 entries, 20 bytes */
static const uint32_t g_installer_offsets_852[5] = {
    0x0015d657u, 0x00003bebu, 0x00219a6cu, 0x00219a74u, 0x003a40fdu,
};

/* firmware 900 - 5 entries, 20 bytes */
static const uint32_t g_installer_offsets_900[5] = {
    0x000b7b17u, 0x00003bebu, 0x0037bf3cu, 0x0037bf44u, 0x002714bdu,
};

/* firmware 903 - 5 entries, 20 bytes */
static const uint32_t g_installer_offsets_903[5] = {
    0x000b7ac7u, 0x00003bebu, 0x0037a13cu, 0x0037a144u, 0x0027113du,
};

/* firmware 904 - 5 entries, 20 bytes */
static const uint32_t g_installer_offsets_904[5] = {
    0x000b7ac7u, 0x00003bebu, 0x0037a13cu, 0x0037a144u, 0x0027113du,
};

/* firmware 950 - 5 entries, 20 bytes */
static const uint32_t g_installer_offsets_950[5] = {
    0x00205557u, 0x00003bebu, 0x00188a9cu, 0x00188aa4u, 0x00201ccdu,
};

/* firmware 951 - 5 entries, 20 bytes */
static const uint32_t g_installer_offsets_951[5] = {
    0x00205557u, 0x00003bebu, 0x00188a9cu, 0x00188aa4u, 0x00201ccdu,
};

/* firmware 960 - 5 entries, 20 bytes */
static const uint32_t g_installer_offsets_960[5] = {
    0x00205557u, 0x00003bebu, 0x00188a9cu, 0x00188aa4u, 0x00201ccdu,
};

/* firmware 1000 - 5 entries, 20 bytes */
static const uint32_t g_installer_offsets_1000[5] = {
    0x000c51d7u, 0x00003bebu, 0x0033b10cu, 0x0033b114u, 0x00472d2du,
};

/* firmware 1001 - 5 entries, 20 bytes */
static const uint32_t g_installer_offsets_1001[5] = {
    0x000c51d7u, 0x00003bebu, 0x0033b10cu, 0x0033b114u, 0x00472d2du,
};

/* firmware 1050 - 5 entries, 20 bytes */
static const uint32_t g_installer_offsets_1050[5] = {
    0x00450f67u, 0x00003bebu, 0x00428a2cu, 0x00428a34u, 0x000d737du,
};

/* firmware 1070 - 5 entries, 20 bytes */
static const uint32_t g_installer_offsets_1070[5] = {
    0x00450f67u, 0x00003bebu, 0x00428a2cu, 0x00428a34u, 0x000d737du,
};

/* firmware 1071 - 5 entries, 20 bytes */
static const uint32_t g_installer_offsets_1071[5] = {
    0x00450f67u, 0x00003bebu, 0x00428a2cu, 0x00428a34u, 0x000d737du,
};

/* firmware 1100 - 5 entries, 20 bytes */
static const uint32_t g_installer_offsets_1100[5] = {
    0x002fccb7u, 0x00003bebu, 0x00245edcu, 0x00245ee4u, 0x002dddfdu,
};

/* firmware 1102 - 5 entries, 20 bytes */
static const uint32_t g_installer_offsets_1102[5] = {
    0x002fccd7u, 0x00003bebu, 0x00245efcu, 0x00245f04u, 0x002dde1du,
};

/* firmware 1150 - 5 entries, 20 bytes */
static const uint32_t g_installer_offsets_1150[5] = {
    0x002e0287u, 0x00003bebu, 0x0046586cu, 0x00465874u, 0x002bd3adu,
};

/* firmware 1152 - 5 entries, 20 bytes */
static const uint32_t g_installer_offsets_1152[5] = {
    0x002e0287u, 0x00003bebu, 0x0046586cu, 0x00465874u, 0x002bd3adu,
};

/* firmware 1200 - 5 entries, 20 bytes */
static const uint32_t g_installer_offsets_1200[5] = {
    0x002e04c7u, 0x00003bebu, 0x00465aacu, 0x00465ab4u, 0x002bd48du,
};

/* firmware 1202 - 5 entries, 20 bytes */
static const uint32_t g_installer_offsets_1202[5] = {
    0x002e04c7u, 0x00003bebu, 0x00465aacu, 0x00465ab4u, 0x002bd48du,
};

/* firmware 1250 - 5 entries, 20 bytes */
static const uint32_t g_installer_offsets_1250[5] = {
    0x002e0507u, 0x00003bebu, 0x00465aecu, 0x00465af4u, 0x002bd4cdu,
};

/* firmware 1252 - 5 entries, 20 bytes */
static const uint32_t g_installer_offsets_1252[5] = {
    0x002e0507u, 0x00003bebu, 0x00465aecu, 0x00465af4u, 0x002bd4cdu,
};

/* firmware 1300 - 5 entries, 20 bytes */
static const uint32_t g_installer_offsets_1300[5] = {
    0x002e0527u, 0x00003bebu, 0x00465b0cu, 0x00465b14u, 0x002bd4edu,
};

#endif /* GOLDHEN_TABLES_INSTALLER_OFFSETS_H */

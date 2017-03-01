#include <stdio.h>
#include <stdlib.h>
#include <err.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nextGreaterElement(int* findNums, int findNumsSize, int* nums, int numsSize, int* returnSize)
{
    int* returnArray = NULL;

    *returnSize = findNumsSize;

    if(findNums != NULL && findNumsSize != 0 &&
       nums != NULL && numsSize != 0) {
        /* initalize the returnArray */
        returnArray = malloc((*returnSize) * sizeof(int));
        if(returnArray == NULL) {
            err(-1, "nextGreaterElement: line 17: malloc: out of space!");
        }

        for(int i = 0; i < findNumsSize; i++) {
            int j;
            for(j = 0; findNums[i] != nums[j]; j++);
            for(++j; j < numsSize && findNums[i] >= nums[j]; j++);
            returnArray[i] = (j < numsSize ? nums[j] : -1);
        }
    }

    return returnArray;
}

int main(int argc, char* argv[])
{
    /*
    int nums11[] = {4, 1, 2};
    int nums12[] = {1, 0, 4, 2};
    int nums21[] = {2, 4};
    int nums22[] = {1, 2, 3, 4};
    */
    int nums11[] = {4289,4932,4658,1915,5181,306,1990,737,1295,4922,5199,992,5281,5312,5121,3511,462,5364,4949,1755,4513,4113,1761,164,4556,3009,3687,1899,505,1157,1663,4927,3066,3895,3743,4585,3121,209,4807,1613,2613,3962,1441,3884,4558,3726,4435,3505,2815,1596,2797,5470,1182,3117,4944,3064,1168,2378,3057,67,4928,3021,3316,1819,382,2703,2540,2726,1086,4393,3442,1845,3179,3019,2190,3564,1097,2694,1345,5226,2032,3629,3647,453,2050,3804,1627,682,2408,3967,3973,779,4150,956,395,5186,4036,3865,748,580,4023,829,687,4666,5394,3003,2749,4042,1651,5206,415,29,4869,78,869,4063,3420,5017,1823,226,1017,4211,689,1726,3198,4,4795,2115,718,3109,1989,5183,1656,4243,2646,4614,968,4953,5116,3932,1775,2204,5392,1165,239,1836,187,1784,2068,3665,2153,2950,3242,775,980,2577,651,4636,3839,964,5505,5099,4592,5049,258,2056,4332,1138,3118,246,3440,4828,1282,2879,4476,1735,4929,4806,5251,2134,4670,5467,205,3399,1805,1813,4846,55,3249,44,1096,2920,4531,1310,1386,4075,2503,3744,4678,1094,2691,300,1747,150,4161,4779,3982,495,1985,1122,1473,2264,5458,1311,5243,452,877,1043,1246,2043,434,2386,789,3796,5393,3824,5424,2230,2655,1058,4490,2266,669,3863,1590,731,5522,4640,5437,2155,2895,2130,533,3428,5025,3789,2231,1471,3464,1019,2441,3075,2004,5198,1480,920,4108,400,5191,1997,3366,5375,4497,512,3226,4823,4549,1361,2783,552,4695,1501,3098,4552,1432,4946,5224,1239,2428,2972,1375,1708,911,2160,2157,3754,2954,4551,3236,1642,4102,4391,4215,4218,2621,1250,3012,4609,2486,3126,1529,3123,508,5299,305,5090,3493,2648,5169,729,5520,4631,2240,2250,4934,1740,2006,2659,1751,3348,154,2923,608,4691,1497,444,3638,1247,5053,1500,3663,1456,2253,3530,1965,5153,986,2583,4085,5306,4642,3848,2251,3537,4340,1146,2696,4293,2349,238,1835,241,5170,1142,873,3658,2061,5252,3655,1264,4643,5440,1031,3419,5016,888,3484,954,4148,2551,2724,1124,4318,2020,5472,1487,862,4056,5506,3318,4044,5455,627,824,2748,4342,3321,3090,68,4856,65,1662,4416,1517,5502,1283,4477,2086,4483,1289,2647,4109,115,4906,921,5055,4138,4189,2598,1001,4229,1035,5020,2850,1234,4428,2037,3102,1505,1499,4693,3896,1502,3099,1258,2852,5488,6,970,1764,3361,2104,5301,510,2587,196,4897,106,2091,823,3269,4066,2949,2152,5046,1061,1056,2653,3450,5361,2167,3764,2891,1854,5051,260,5042,1267,4861,4064,1673,2052,5246,1276,4646,3846,5443,2122,2574,4168,5359,3160,4757,448,3636,5230,1245,2042,18,4003,421,2018,743,3137,1540,4728,1161,2742,1145,2704,3501,3303,2506,1702,3281,2484,2361,1891,3535,1950,353,4341,2744,1252,2429,832,4817,4020,1235,4423,2829,1811,3411,217,4106,5290,4493,5073,2682,5128,346,1550,4542,5339,3056,4653,1649,4040,2363,5461,4664,4921,933,2530,3472,3463,5060,2117,1803,997,2594,3391,1841,244,4629,3832,5256,3055,3724,2930,1333,4775,1829,2341,3935,1538,4732,1177,4365,5162,3195,4404,1210,275,3469,626,2208,3805,3008,2872,1275,472,2863,2219,5240,1380,5365,2974,2619,1022,4418,2821,4142,3345,4791,0,5163,372,3697,2100,2103,506,3694,3024,1430,4209,840,913,4101,352,1134,4322,1457,266,3288,94,885,4079,642,2239,4630,3695,934,5491,184,3375,1778,4966,2256,3853,2465,2468,871,2871,4471,2080,486,1439,4627,1842,1839,3436,2280,3417,5396,5111,320,1117,5499,2305,1604,5177,386,4305,1111,4287,4445,69,1666,2438,4425,3216,1619,3213,3610,3089,698,3159,4756,1562,9,451,4368,5165,1592,1192,389,3583,4314,2729,2001,3598,34,2425,428,4413,3616,1285,2079,5275,2081,484,5266,1281,1716,4910,5355,182,4238,2644,3831,3107,328,4494,2464,4052,2526,4971,5062,2671,3093,696,3087,3275,2684,778,3172,1575,4751,3563,2766,498,1746,149,4976,594,2191,3785,2212,1815,1677,83,880,3271,77,874,825,3207,4804,2776,385,782,1196,1660,2457,3286,2489,4086,1695,3730,2133,2939,1342,2918,1998,3595,1204,962,4950,1756,3353,165,4947,5156,1396,2193,2590,3775,1384,2175,5369,1116,1119,322,5193,4796,432,2823,250,4387,4608,5405,1392,2189,2410,1378,4510,922,1713,4907,5376,2985,5269,1278,4472,4702,4260,1869,784,5151,3152,2355,4737,1367,4952,4146,4170,982,3367,2570,1991,1194,1191,2788,2591,4173,2194,600,4424,1236,3624,3088,5258,3273,882,1584,2775,4981,1787,134,3328,746,2343,624,5415,3818,2203,3171,2371,3968,2380,4484,4881,331,2686,295,289,3483,4104,2539,4133,3336,5067,2676,3082,1485,4834,4657,572,3760,1760,3357,4951,2812,3437,1046,3031,240,2622,2225,742,2339,3136,2333,3930,2354,5133,2661,1768,4374,2141,3738,751,3927,1930,5118,4379,3607,2810,4192,3557,363,5145,2396,1599,4787,4008,23,1754,4948,220,4205,1042,4006,648,1445,2862,5503,1518,2976,4979,1785,4147,5155,1060,5045,481,3398,3167,3497};
        int nums12[] = {4289,4932,4658,1915,5181,306,1990,737,1295,4922,5199,992,5281,5312,5121,3511,462,5364,4949,1755,4513,4113,1761,164,4556,3009,3687,1899,505,1157,1663,4927,3066,3895,3743,4585,3121,209,4807,1613,2613,3962,1441,3884,4558,3726,4435,3505,2815,1596,2797,5470,1182,3117,4944,3064,1168,2378,3057,67,4928,3021,3316,1819,382,2703,2540,2726,1086,4393,3442,1845,3179,3019,2190,3564,1097,2694,1345,5226,2032,3629,3647,453,2050,3804,1627,682,2408,3967,3973,779,4150,956,395,5186,4036,3865,748,580,4023,829,687,4666,5394,3003,2749,4042,1651,5206,415,29,4869,78,869,4063,3420,5017,1823,226,1017,4211,689,1726,3198,4,4795,2115,718,3109,1989,5183,1656,4243,2646,4614,968,4953,5116,3932,1775,2204,5392,1165,239,1836,187,1784,2068,3665,2153,2950,3242,775,980,2577,651,4636,3839,964,5505,5099,4592,5049,258,2056,4332,1138,3118,246,3440,4828,1282,2879,4476,1735,4929,4806,5251,2134,4670,5467,205,3399,1805,1813,4846,55,3249,44,1096,2920,4531,1310,1386,4075,2503,3744,4678,1094,2691,300,1747,150,4161,4779,3982,495,1985,1122,1473,2264,5458,1311,5243,452,877,1043,1246,2043,434,2386,789,3796,5393,3824,5424,2230,2655,1058,4490,2266,669,3863,1590,731,5522,4640,5437,2155,2895,2130,533,3428,5025,3789,2231,1471,3464,1019,2441,3075,2004,5198,1480,920,4108,400,5191,1997,3366,5375,4497,512,3226,4823,4549,1361,2783,552,4695,1501,3098,4552,1432,4946,5224,1239,2428,2972,1375,1708,911,2160,2157,3754,2954,4551,3236,1642,4102,4391,4215,4218,2621,1250,3012,4609,2486,3126,1529,3123,508,5299,305,5090,3493,2648,5169,729,5520,4631,2240,2250,4934,1740,2006,2659,1751,3348,154,2923,608,4691,1497,444,3638,1247,5053,1500,3663,1456,2253,3530,1965,5153,986,2583,4085,5306,4642,3848,2251,3537,4340,1146,2696,4293,2349,238,1835,241,5170,1142,873,3658,2061,5252,3655,1264,4643,5440,1031,3419,5016,888,3484,954,4148,2551,2724,1124,4318,2020,5472,1487,862,4056,5506,3318,4044,5455,627,824,2748,4342,3321,3090,68,4856,65,1662,4416,1517,5502,1283,4477,2086,4483,1289,2647,4109,115,4906,921,5055,4138,4189,2598,1001,4229,1035,5020,2850,1234,4428,2037,3102,1505,1499,4693,3896,1502,3099,1258,2852,5488,6,970,1764,3361,2104,5301,510,2587,196,4897,106,2091,823,3269,4066,2949,2152,5046,1061,1056,2653,3450,5361,2167,3764,2891,1854,5051,260,5042,1267,4861,4064,1673,2052,5246,1276,4646,3846,5443,2122,2574,4168,5359,3160,4757,448,3636,5230,1245,2042,18,4003,421,2018,743,3137,1540,4728,1161,2742,1145,2704,3501,3303,2506,1702,3281,2484,2361,1891,3535,1950,353,4341,2744,1252,2429,832,4817,4020,1235,4423,2829,1811,3411,217,4106,5290,4493,5073,2682,5128,346,1550,4542,5339,3056,4653,1649,4040,2363,5461,4664,4921,933,2530,3472,3463,5060,2117,1803,997,2594,3391,1841,244,4629,3832,5256,3055,3724,2930,1333,4775,1829,2341,3935,1538,4732,1177,4365,5162,3195,4404,1210,275,3469,626,2208,3805,3008,2872,1275,472,2863,2219,5240,1380,5365,2974,2619,1022,4418,2821,4142,3345,4791,0,5163,372,3697,2100,2103,506,3694,3024,1430,4209,840,913,4101,352,1134,4322,1457,266,3288,94,885,4079,642,2239,4630,3695,934,5491,184,3375,1778,4966,2256,3853,2465,2468,871,2871,4471,2080,486,1439,4627,1842,1839,3436,2280,3417,5396,5111,320,1117,5499,2305,1604,5177,386,4305,1111,4287,4445,69,1666,2438,4425,3216,1619,3213,3610,3089,698,3159,4756,1562,9,451,4368,5165,1592,1192,389,3583,4314,2729,2001,3598,34,2425,428,4413,3616,1285,2079,5275,2081,484,5266,1281,1716,4910,5355,182,4238,2644,3831,3107,328,4494,2464,4052,2526,4971,5062,2671,3093,696,3087,3275,2684,778,3172,1575,4751,3563,2766,498,1746,149,4976,594,2191,3785,2212,1815,1677,83,880,3271,77,874,825,3207,4804,2776,385,782,1196,1660,2457,3286,2489,4086,1695,3730,2133,2939,1342,2918,1998,3595,1204,962,4950,1756,3353,165,4947,5156,1396,2193,2590,3775,1384,2175,5369,1116,1119,322,5193,4796,432,2823,250,4387,4608,5405,1392,2189,2410,1378,4510,922,1713,4907,5376,2985,5269,1278,4472,4702,4260,1869,784,5151,3152,2355,4737,1367,4952,4146,4170,982,3367,2570,1991,1194,1191,2788,2591,4173,2194,600,4424,1236,3624,3088,5258,3273,882,1584,2775,4981,1787,134,3328,746,2343,624,5415,3818,2203,3171,2371,3968,2380,4484,4881,331,2686,295,289,3483,4104,2539,4133,3336,5067,2676,3082,1485,4834,4657,572,3760,1760,3357,4951,2812,3437,1046,3031,240,2622,2225,742,2339,3136,2333,3930,2354,5133,2661,1768,4374,2141,3738,751,3927,1930,5118,4379,3607,2810,4192,3557,363,5145,2396,1599,4787,4008,23,1754,4948,220,4205,1042,4006,648,1445,2862,5503,1518,2976,4979,1785,4147,5155,1060,5045,481,3398,3167,3497};
    int nums21[] = {4289,4932,4658,1915,5181,306,1990,737,1295,4922,5199,992,5281,5312,5121,3511,462,5364,4949,1755,4513,4113,1761,164,4556,3009,3687,1899,505,1157,1663,4927,3066,3895,3743,4585,3121,209,4807,1613,2613,3962,1441,3884,4558,3726,4435,3505,2815,1596,2797,5470,1182,3117,4944,3064,1168,2378,3057,67,4928,3021,3316,1819,382,2703,2540,2726,1086,4393,3442,1845,3179,3019,2190,3564,1097,2694,1345,5226,2032,3629,3647,453,2050,3804,1627,682,2408,3967,3973,779,4150,956,395,5186,4036,3865,748,580,4023,829,687,4666,5394,3003,2749,4042,1651,5206,415,29,4869,78,869,4063,3420,5017,1823,226,1017,4211,689,1726,3198,4,4795,2115,718,3109,1989,5183,1656,4243,2646,4614,968,4953,5116,3932,1775,2204,5392,1165,239,1836,187,1784,2068,3665,2153,2950,3242,775,980,2577,651,4636,3839,964,5505,5099,4592,5049,258,2056,4332,1138,3118,246,3440,4828,1282,2879,4476,1735,4929,4806,5251,2134,4670,5467,205,3399,1805,1813,4846,55,3249,44,1096,2920,4531,1310,1386,4075,2503,3744,4678,1094,2691,300,1747,150,4161,4779,3982,495,1985,1122,1473,2264,5458,1311,5243,452,877,1043,1246,2043,434,2386,789,3796,5393,3824,5424,2230,2655,1058,4490,2266,669,3863,1590,731,5522,4640,5437,2155,2895,2130,533,3428,5025,3789,2231,1471,3464,1019,2441,3075,2004,5198,1480,920,4108,400,5191,1997,3366,5375,4497,512,3226,4823,4549,1361,2783,552,4695,1501,3098,4552,1432,4946,5224,1239,2428,2972,1375,1708,911,2160,2157,3754,2954,4551,3236,1642,4102,4391,4215,4218,2621,1250,3012,4609,2486,3126,1529,3123,508,5299,305,5090,3493,2648,5169,729,5520,4631,2240,2250,4934,1740,2006,2659,1751,3348,154,2923,608,4691,1497,444,3638,1247,5053,1500,3663,1456,2253,3530,1965,5153,986,2583,4085,5306,4642,3848,2251,3537,4340,1146,2696,4293,2349,238,1835,241,5170,1142,873,3658,2061,5252,3655,1264,4643,5440,1031,3419,5016,888,3484,954,4148,2551,2724,1124,4318,2020,5472,1487,862,4056,5506,3318,4044,5455,627,824,2748,4342,3321,3090,68,4856,65,1662,4416,1517,5502,1283,4477,2086,4483,1289,2647,4109,115,4906,921,5055,4138,4189,2598,1001,4229,1035,5020,2850,1234,4428,2037,3102,1505,1499,4693,3896,1502,3099,1258,2852,5488,6,970,1764,3361,2104,5301,510,2587,196,4897,106,2091,823,3269,4066,2949,2152,5046,1061,1056,2653,3450,5361,2167,3764,2891,1854,5051,260,5042,1267,4861,4064,1673,2052,5246,1276,4646,3846,5443,2122,2574,4168,5359,3160,4757,448,3636,5230,1245,2042,18,4003,421,2018,743,3137,1540,4728,1161,2742,1145,2704,3501,3303,2506,1702,3281,2484,2361,1891,3535,1950,353,4341,2744,1252,2429,832,4817,4020,1235,4423,2829,1811,3411,217,4106,5290,4493,5073,2682,5128,346,1550,4542,5339,3056,4653,1649,4040,2363,5461,4664,4921,933,2530,3472,3463,5060,2117,1803,997,2594,3391,1841,244,4629,3832,5256,3055,3724,2930,1333,4775,1829,2341,3935,1538,4732,1177,4365,5162,3195,4404,1210,275,3469,626,2208,3805,3008,2872,1275,472,2863,2219,5240,1380,5365,2974,2619,1022,4418,2821,4142,3345,4791,0,5163,372,3697,2100,2103,506,3694,3024,1430,4209,840,913,4101,352,1134,4322,1457,266,3288,94,885,4079,642,2239,4630,3695,934,5491,184,3375,1778,4966,2256,3853,2465,2468,871,2871,4471,2080,486,1439,4627,1842,1839,3436,2280,3417,5396,5111,320,1117,5499,2305,1604,5177,386,4305,1111,4287,4445,69,1666,2438,4425,3216,1619,3213,3610,3089,698,3159,4756,1562,9,451,4368,5165,1592,1192,389,3583,4314,2729,2001,3598,34,2425,428,4413,3616,1285,2079,5275,2081,484,5266,1281,1716,4910,5355,182,4238,2644,3831,3107,328,4494,2464,4052,2526,4971,5062,2671,3093,696,3087,3275,2684,778,3172,1575,4751,3563,2766,498,1746,149,4976,594,2191,3785,2212,1815,1677,83,880,3271,77,874,825,3207,4804,2776,385,782,1196,1660,2457,3286,2489,4086,1695,3730,2133,2939,1342,2918,1998,3595,1204,962,4950,1756,3353,165,4947,5156,1396,2193,2590,3775,1384,2175,5369,1116,1119,322,5193,4796,432,2823,250,4387,4608,5405,1392,2189,2410,1378,4510,922,1713,4907,5376,2985,5269,1278,4472,4702,4260,1869,784,5151,3152,2355,4737,1367,4952,4146,4170,982,3367,2570,1991,1194,1191,2788,2591,4173,2194,600,4424,1236,3624,3088,5258,3273,882,1584,2775,4981,1787,134,3328,746,2343,624,5415,3818,2203,3171,2371,3968,2380,4484,4881,331,2686,295,289,3483,4104,2539,4133,3336,5067,2676,3082,1485,4834,4657,572,3760,1760,3357,4951,2812,3437,1046,3031,240,2622,2225,742,2339,3136,2333,3930,2354,5133,2661,1768,4374,2141,3738,751,3927,1930,5118,4379,3607,2810,4192,3557,363,5145,2396,1599,4787,4008,23,1754,4948,220,4205,1042,4006,648,1445,2862,5503,1518,2976,4979,1785,4147,5155,1060,5045,481,3398,3167,3497};
        int nums22[] = {4289,4932,4658,1915,5181,306,1990,737,1295,4922,5199,992,5281,5312,5121,3511,462,5364,4949,1755,4513,4113,1761,164,4556,3009,3687,1899,505,1157,1663,4927,3066,3895,3743,4585,3121,209,4807,1613,2613,3962,1441,3884,4558,3726,4435,3505,2815,1596,2797,5470,1182,3117,4944,3064,1168,2378,3057,67,4928,3021,3316,1819,382,2703,2540,2726,1086,4393,3442,1845,3179,3019,2190,3564,1097,2694,1345,5226,2032,3629,3647,453,2050,3804,1627,682,2408,3967,3973,779,4150,956,395,5186,4036,3865,748,580,4023,829,687,4666,5394,3003,2749,4042,1651,5206,415,29,4869,78,869,4063,3420,5017,1823,226,1017,4211,689,1726,3198,4,4795,2115,718,3109,1989,5183,1656,4243,2646,4614,968,4953,5116,3932,1775,2204,5392,1165,239,1836,187,1784,2068,3665,2153,2950,3242,775,980,2577,651,4636,3839,964,5505,5099,4592,5049,258,2056,4332,1138,3118,246,3440,4828,1282,2879,4476,1735,4929,4806,5251,2134,4670,5467,205,3399,1805,1813,4846,55,3249,44,1096,2920,4531,1310,1386,4075,2503,3744,4678,1094,2691,300,1747,150,4161,4779,3982,495,1985,1122,1473,2264,5458,1311,5243,452,877,1043,1246,2043,434,2386,789,3796,5393,3824,5424,2230,2655,1058,4490,2266,669,3863,1590,731,5522,4640,5437,2155,2895,2130,533,3428,5025,3789,2231,1471,3464,1019,2441,3075,2004,5198,1480,920,4108,400,5191,1997,3366,5375,4497,512,3226,4823,4549,1361,2783,552,4695,1501,3098,4552,1432,4946,5224,1239,2428,2972,1375,1708,911,2160,2157,3754,2954,4551,3236,1642,4102,4391,4215,4218,2621,1250,3012,4609,2486,3126,1529,3123,508,5299,305,5090,3493,2648,5169,729,5520,4631,2240,2250,4934,1740,2006,2659,1751,3348,154,2923,608,4691,1497,444,3638,1247,5053,1500,3663,1456,2253,3530,1965,5153,986,2583,4085,5306,4642,3848,2251,3537,4340,1146,2696,4293,2349,238,1835,241,5170,1142,873,3658,2061,5252,3655,1264,4643,5440,1031,3419,5016,888,3484,954,4148,2551,2724,1124,4318,2020,5472,1487,862,4056,5506,3318,4044,5455,627,824,2748,4342,3321,3090,68,4856,65,1662,4416,1517,5502,1283,4477,2086,4483,1289,2647,4109,115,4906,921,5055,4138,4189,2598,1001,4229,1035,5020,2850,1234,4428,2037,3102,1505,1499,4693,3896,1502,3099,1258,2852,5488,6,970,1764,3361,2104,5301,510,2587,196,4897,106,2091,823,3269,4066,2949,2152,5046,1061,1056,2653,3450,5361,2167,3764,2891,1854,5051,260,5042,1267,4861,4064,1673,2052,5246,1276,4646,3846,5443,2122,2574,4168,5359,3160,4757,448,3636,5230,1245,2042,18,4003,421,2018,743,3137,1540,4728,1161,2742,1145,2704,3501,3303,2506,1702,3281,2484,2361,1891,3535,1950,353,4341,2744,1252,2429,832,4817,4020,1235,4423,2829,1811,3411,217,4106,5290,4493,5073,2682,5128,346,1550,4542,5339,3056,4653,1649,4040,2363,5461,4664,4921,933,2530,3472,3463,5060,2117,1803,997,2594,3391,1841,244,4629,3832,5256,3055,3724,2930,1333,4775,1829,2341,3935,1538,4732,1177,4365,5162,3195,4404,1210,275,3469,626,2208,3805,3008,2872,1275,472,2863,2219,5240,1380,5365,2974,2619,1022,4418,2821,4142,3345,4791,0,5163,372,3697,2100,2103,506,3694,3024,1430,4209,840,913,4101,352,1134,4322,1457,266,3288,94,885,4079,642,2239,4630,3695,934,5491,184,3375,1778,4966,2256,3853,2465,2468,871,2871,4471,2080,486,1439,4627,1842,1839,3436,2280,3417,5396,5111,320,1117,5499,2305,1604,5177,386,4305,1111,4287,4445,69,1666,2438,4425,3216,1619,3213,3610,3089,698,3159,4756,1562,9,451,4368,5165,1592,1192,389,3583,4314,2729,2001,3598,34,2425,428,4413,3616,1285,2079,5275,2081,484,5266,1281,1716,4910,5355,182,4238,2644,3831,3107,328,4494,2464,4052,2526,4971,5062,2671,3093,696,3087,3275,2684,778,3172,1575,4751,3563,2766,498,1746,149,4976,594,2191,3785,2212,1815,1677,83,880,3271,77,874,825,3207,4804,2776,385,782,1196,1660,2457,3286,2489,4086,1695,3730,2133,2939,1342,2918,1998,3595,1204,962,4950,1756,3353,165,4947,5156,1396,2193,2590,3775,1384,2175,5369,1116,1119,322,5193,4796,432,2823,250,4387,4608,5405,1392,2189,2410,1378,4510,922,1713,4907,5376,2985,5269,1278,4472,4702,4260,1869,784,5151,3152,2355,4737,1367,4952,4146,4170,982,3367,2570,1991,1194,1191,2788,2591,4173,2194,600,4424,1236,3624,3088,5258,3273,882,1584,2775,4981,1787,134,3328,746,2343,624,5415,3818,2203,3171,2371,3968,2380,4484,4881,331,2686,295,289,3483,4104,2539,4133,3336,5067,2676,3082,1485,4834,4657,572,3760,1760,3357,4951,2812,3437,1046,3031,240,2622,2225,742,2339,3136,2333,3930,2354,5133,2661,1768,4374,2141,3738,751,3927,1930,5118,4379,3607,2810,4192,3557,363,5145,2396,1599,4787,4008,23,1754,4948,220,4205,1042,4006,648,1445,2862,5503,1518,2976,4979,1785,4147,5155,1060,5045,481,3398,3167,3497};
    int* returnArray;
    int* returnSize = malloc(sizeof(int));
    if(returnSize == NULL) {
        err(-1, "main: line 62: malloc: out of space!");
    }

    returnArray = nextGreaterElement(nums11, 910, nums12, 910, returnSize);
    printf("[");
    for(int i = 0; i < *returnSize; i++) {
        printf("%d%s", returnArray[i], (i == (*returnSize)-1 ? "" : ", "));
    }
    printf("]\n");

    returnArray = nextGreaterElement(nums21, 910, nums22, 910, returnSize);
    printf("[");
    for(int i = 0; i < *returnSize; i++) {
        printf("%d%s", returnArray[i], (i == (*returnSize)-1 ? "" : ", "));
    }
    printf("]\n");

    return 0;
}
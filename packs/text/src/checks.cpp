/*
This is free and unencumbered software released into the public domain.

Anyone is free to copy, modify, publish, use, compile, sell, or
distribute this software, either in source code form or as a compiled
binary, for any purpose, commercial or non-commercial, and by any
means.

In jurisdictions that recognize copyright laws, the author or authors
of this software dedicate any and all copyright interest in the
software to the public domain. We make this dedication for the benefit
of the public at large and to the detriment of our heirs and
successors. We intend this dedication to be an overt act of
relinquishment in perpetuity of all present and future rights to this
software under copyright law.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.

For more information, please refer to <https://unlicense.org>

*/
#include "checks.hpp"

namespace txt {
	
	bool is_alpha(char32_t test_char) noexcept {
		if( test_char >= 65 && test_char < 91 ) { return true; }
		if( test_char >= 97 && test_char < 123 ) { return true; }
		if( test_char == 170 ) { return true; }
		if( test_char == 181 ) { return true; }
		if( test_char == 186 ) { return true; }
		if( test_char >= 192 && test_char < 215 ) { return true; }
		if( test_char >= 216 && test_char < 247 ) { return true; }
		if( test_char >= 248 && test_char < 706 ) { return true; }
		if( test_char >= 710 && test_char < 722 ) { return true; }
		if( test_char >= 736 && test_char < 741 ) { return true; }
		if( test_char == 748 ) { return true; }
		if( test_char == 750 ) { return true; }
		if( test_char >= 880 && test_char < 885 ) { return true; }
		if( test_char >= 886 && test_char < 888 ) { return true; }
		if( test_char >= 890 && test_char < 894 ) { return true; }
		if( test_char == 895 ) { return true; }
		if( test_char == 902 ) { return true; }
		if( test_char >= 904 && test_char < 907 ) { return true; }
		if( test_char == 908 ) { return true; }
		if( test_char >= 910 && test_char < 930 ) { return true; }
		if( test_char >= 931 && test_char < 1014 ) { return true; }
		if( test_char >= 1015 && test_char < 1154 ) { return true; }
		if( test_char >= 1162 && test_char < 1328 ) { return true; }
		if( test_char >= 1329 && test_char < 1367 ) { return true; }
		if( test_char == 1369 ) { return true; }
		if( test_char >= 1376 && test_char < 1417 ) { return true; }
		if( test_char >= 1488 && test_char < 1515 ) { return true; }
		if( test_char >= 1519 && test_char < 1523 ) { return true; }
		if( test_char >= 1568 && test_char < 1611 ) { return true; }
		if( test_char >= 1646 && test_char < 1648 ) { return true; }
		if( test_char >= 1649 && test_char < 1748 ) { return true; }
		if( test_char == 1749 ) { return true; }
		if( test_char >= 1765 && test_char < 1767 ) { return true; }
		if( test_char >= 1774 && test_char < 1776 ) { return true; }
		if( test_char >= 1786 && test_char < 1789 ) { return true; }
		if( test_char == 1791 ) { return true; }
		if( test_char == 1808 ) { return true; }
		if( test_char >= 1810 && test_char < 1840 ) { return true; }
		if( test_char >= 1869 && test_char < 1958 ) { return true; }
		if( test_char == 1969 ) { return true; }
		if( test_char >= 1994 && test_char < 2027 ) { return true; }
		if( test_char >= 2036 && test_char < 2038 ) { return true; }
		if( test_char == 2042 ) { return true; }
		if( test_char >= 2048 && test_char < 2070 ) { return true; }
		if( test_char == 2074 ) { return true; }
		if( test_char == 2084 ) { return true; }
		if( test_char == 2088 ) { return true; }
		if( test_char >= 2112 && test_char < 2137 ) { return true; }
		if( test_char >= 2144 && test_char < 2155 ) { return true; }
		if( test_char >= 2160 && test_char < 2184 ) { return true; }
		if( test_char >= 2185 && test_char < 2191 ) { return true; }
		if( test_char >= 2208 && test_char < 2250 ) { return true; }
		if( test_char >= 2308 && test_char < 2362 ) { return true; }
		if( test_char == 2365 ) { return true; }
		if( test_char == 2384 ) { return true; }
		if( test_char >= 2392 && test_char < 2402 ) { return true; }
		if( test_char >= 2417 && test_char < 2433 ) { return true; }
		if( test_char >= 2437 && test_char < 2445 ) { return true; }
		if( test_char >= 2447 && test_char < 2449 ) { return true; }
		if( test_char >= 2451 && test_char < 2473 ) { return true; }
		if( test_char >= 2474 && test_char < 2481 ) { return true; }
		if( test_char == 2482 ) { return true; }
		if( test_char >= 2486 && test_char < 2490 ) { return true; }
		if( test_char == 2493 ) { return true; }
		if( test_char == 2510 ) { return true; }
		if( test_char >= 2524 && test_char < 2526 ) { return true; }
		if( test_char >= 2527 && test_char < 2530 ) { return true; }
		if( test_char >= 2544 && test_char < 2546 ) { return true; }
		if( test_char == 2556 ) { return true; }
		if( test_char >= 2565 && test_char < 2571 ) { return true; }
		if( test_char >= 2575 && test_char < 2577 ) { return true; }
		if( test_char >= 2579 && test_char < 2601 ) { return true; }
		if( test_char >= 2602 && test_char < 2609 ) { return true; }
		if( test_char >= 2610 && test_char < 2612 ) { return true; }
		if( test_char >= 2613 && test_char < 2615 ) { return true; }
		if( test_char >= 2616 && test_char < 2618 ) { return true; }
		if( test_char >= 2649 && test_char < 2653 ) { return true; }
		if( test_char == 2654 ) { return true; }
		if( test_char >= 2674 && test_char < 2677 ) { return true; }
		if( test_char >= 2693 && test_char < 2702 ) { return true; }
		if( test_char >= 2703 && test_char < 2706 ) { return true; }
		if( test_char >= 2707 && test_char < 2729 ) { return true; }
		if( test_char >= 2730 && test_char < 2737 ) { return true; }
		if( test_char >= 2738 && test_char < 2740 ) { return true; }
		if( test_char >= 2741 && test_char < 2746 ) { return true; }
		if( test_char == 2749 ) { return true; }
		if( test_char == 2768 ) { return true; }
		if( test_char >= 2784 && test_char < 2786 ) { return true; }
		if( test_char == 2809 ) { return true; }
		if( test_char >= 2821 && test_char < 2829 ) { return true; }
		if( test_char >= 2831 && test_char < 2833 ) { return true; }
		if( test_char >= 2835 && test_char < 2857 ) { return true; }
		if( test_char >= 2858 && test_char < 2865 ) { return true; }
		if( test_char >= 2866 && test_char < 2868 ) { return true; }
		if( test_char >= 2869 && test_char < 2874 ) { return true; }
		if( test_char == 2877 ) { return true; }
		if( test_char >= 2908 && test_char < 2910 ) { return true; }
		if( test_char >= 2911 && test_char < 2914 ) { return true; }
		if( test_char == 2929 ) { return true; }
		if( test_char == 2947 ) { return true; }
		if( test_char >= 2949 && test_char < 2955 ) { return true; }
		if( test_char >= 2958 && test_char < 2961 ) { return true; }
		if( test_char >= 2962 && test_char < 2966 ) { return true; }
		if( test_char >= 2969 && test_char < 2971 ) { return true; }
		if( test_char == 2972 ) { return true; }
		if( test_char >= 2974 && test_char < 2976 ) { return true; }
		if( test_char >= 2979 && test_char < 2981 ) { return true; }
		if( test_char >= 2984 && test_char < 2987 ) { return true; }
		if( test_char >= 2990 && test_char < 3002 ) { return true; }
		if( test_char == 3024 ) { return true; }
		if( test_char >= 3077 && test_char < 3085 ) { return true; }
		if( test_char >= 3086 && test_char < 3089 ) { return true; }
		if( test_char >= 3090 && test_char < 3113 ) { return true; }
		if( test_char >= 3114 && test_char < 3130 ) { return true; }
		if( test_char == 3133 ) { return true; }
		if( test_char >= 3160 && test_char < 3163 ) { return true; }
		if( test_char == 3165 ) { return true; }
		if( test_char >= 3168 && test_char < 3170 ) { return true; }
		if( test_char == 3200 ) { return true; }
		if( test_char >= 3205 && test_char < 3213 ) { return true; }
		if( test_char >= 3214 && test_char < 3217 ) { return true; }
		if( test_char >= 3218 && test_char < 3241 ) { return true; }
		if( test_char >= 3242 && test_char < 3252 ) { return true; }
		if( test_char >= 3253 && test_char < 3258 ) { return true; }
		if( test_char == 3261 ) { return true; }
		if( test_char >= 3293 && test_char < 3295 ) { return true; }
		if( test_char >= 3296 && test_char < 3298 ) { return true; }
		if( test_char >= 3313 && test_char < 3315 ) { return true; }
		if( test_char >= 3332 && test_char < 3341 ) { return true; }
		if( test_char >= 3342 && test_char < 3345 ) { return true; }
		if( test_char >= 3346 && test_char < 3387 ) { return true; }
		if( test_char == 3389 ) { return true; }
		if( test_char == 3406 ) { return true; }
		if( test_char >= 3412 && test_char < 3415 ) { return true; }
		if( test_char >= 3423 && test_char < 3426 ) { return true; }
		if( test_char >= 3450 && test_char < 3456 ) { return true; }
		if( test_char >= 3461 && test_char < 3479 ) { return true; }
		if( test_char >= 3482 && test_char < 3506 ) { return true; }
		if( test_char >= 3507 && test_char < 3516 ) { return true; }
		if( test_char == 3517 ) { return true; }
		if( test_char >= 3520 && test_char < 3527 ) { return true; }
		if( test_char >= 3585 && test_char < 3633 ) { return true; }
		if( test_char >= 3634 && test_char < 3636 ) { return true; }
		if( test_char >= 3648 && test_char < 3655 ) { return true; }
		if( test_char >= 3713 && test_char < 3715 ) { return true; }
		if( test_char == 3716 ) { return true; }
		if( test_char >= 3718 && test_char < 3723 ) { return true; }
		if( test_char >= 3724 && test_char < 3748 ) { return true; }
		if( test_char == 3749 ) { return true; }
		if( test_char >= 3751 && test_char < 3761 ) { return true; }
		if( test_char >= 3762 && test_char < 3764 ) { return true; }
		if( test_char == 3773 ) { return true; }
		if( test_char >= 3776 && test_char < 3781 ) { return true; }
		if( test_char == 3782 ) { return true; }
		if( test_char >= 3804 && test_char < 3808 ) { return true; }
		if( test_char == 3840 ) { return true; }
		if( test_char >= 3904 && test_char < 3912 ) { return true; }
		if( test_char >= 3913 && test_char < 3949 ) { return true; }
		if( test_char >= 3976 && test_char < 3981 ) { return true; }
		if( test_char >= 4096 && test_char < 4139 ) { return true; }
		if( test_char == 4159 ) { return true; }
		if( test_char >= 4176 && test_char < 4182 ) { return true; }
		if( test_char >= 4186 && test_char < 4190 ) { return true; }
		if( test_char == 4193 ) { return true; }
		if( test_char >= 4197 && test_char < 4199 ) { return true; }
		if( test_char >= 4206 && test_char < 4209 ) { return true; }
		if( test_char >= 4213 && test_char < 4226 ) { return true; }
		if( test_char == 4238 ) { return true; }
		if( test_char >= 4256 && test_char < 4294 ) { return true; }
		if( test_char == 4295 ) { return true; }
		if( test_char == 4301 ) { return true; }
		if( test_char >= 4304 && test_char < 4347 ) { return true; }
		if( test_char >= 4348 && test_char < 4681 ) { return true; }
		if( test_char >= 4682 && test_char < 4686 ) { return true; }
		if( test_char >= 4688 && test_char < 4695 ) { return true; }
		if( test_char == 4696 ) { return true; }
		if( test_char >= 4698 && test_char < 4702 ) { return true; }
		if( test_char >= 4704 && test_char < 4745 ) { return true; }
		if( test_char >= 4746 && test_char < 4750 ) { return true; }
		if( test_char >= 4752 && test_char < 4785 ) { return true; }
		if( test_char >= 4786 && test_char < 4790 ) { return true; }
		if( test_char >= 4792 && test_char < 4799 ) { return true; }
		if( test_char == 4800 ) { return true; }
		if( test_char >= 4802 && test_char < 4806 ) { return true; }
		if( test_char >= 4808 && test_char < 4823 ) { return true; }
		if( test_char >= 4824 && test_char < 4881 ) { return true; }
		if( test_char >= 4882 && test_char < 4886 ) { return true; }
		if( test_char >= 4888 && test_char < 4955 ) { return true; }
		if( test_char >= 4992 && test_char < 5008 ) { return true; }
		if( test_char >= 5024 && test_char < 5110 ) { return true; }
		if( test_char >= 5112 && test_char < 5118 ) { return true; }
		if( test_char >= 5121 && test_char < 5741 ) { return true; }
		if( test_char >= 5743 && test_char < 5760 ) { return true; }
		if( test_char >= 5761 && test_char < 5787 ) { return true; }
		if( test_char >= 5792 && test_char < 5867 ) { return true; }
		if( test_char >= 5873 && test_char < 5881 ) { return true; }
		if( test_char >= 5888 && test_char < 5906 ) { return true; }
		if( test_char >= 5919 && test_char < 5938 ) { return true; }
		if( test_char >= 5952 && test_char < 5970 ) { return true; }
		if( test_char >= 5984 && test_char < 5997 ) { return true; }
		if( test_char >= 5998 && test_char < 6001 ) { return true; }
		if( test_char >= 6016 && test_char < 6068 ) { return true; }
		if( test_char == 6103 ) { return true; }
		if( test_char == 6108 ) { return true; }
		if( test_char >= 6176 && test_char < 6265 ) { return true; }
		if( test_char >= 6272 && test_char < 6277 ) { return true; }
		if( test_char >= 6279 && test_char < 6313 ) { return true; }
		if( test_char == 6314 ) { return true; }
		if( test_char >= 6320 && test_char < 6390 ) { return true; }
		if( test_char >= 6400 && test_char < 6431 ) { return true; }
		if( test_char >= 6480 && test_char < 6510 ) { return true; }
		if( test_char >= 6512 && test_char < 6517 ) { return true; }
		if( test_char >= 6528 && test_char < 6572 ) { return true; }
		if( test_char >= 6576 && test_char < 6602 ) { return true; }
		if( test_char >= 6656 && test_char < 6679 ) { return true; }
		if( test_char >= 6688 && test_char < 6741 ) { return true; }
		if( test_char == 6823 ) { return true; }
		if( test_char >= 6917 && test_char < 6964 ) { return true; }
		if( test_char >= 6981 && test_char < 6989 ) { return true; }
		if( test_char >= 7043 && test_char < 7073 ) { return true; }
		if( test_char >= 7086 && test_char < 7088 ) { return true; }
		if( test_char >= 7098 && test_char < 7142 ) { return true; }
		if( test_char >= 7168 && test_char < 7204 ) { return true; }
		if( test_char >= 7245 && test_char < 7248 ) { return true; }
		if( test_char >= 7258 && test_char < 7294 ) { return true; }
		if( test_char >= 7296 && test_char < 7305 ) { return true; }
		if( test_char >= 7312 && test_char < 7355 ) { return true; }
		if( test_char >= 7357 && test_char < 7360 ) { return true; }
		if( test_char >= 7401 && test_char < 7405 ) { return true; }
		if( test_char >= 7406 && test_char < 7412 ) { return true; }
		if( test_char >= 7413 && test_char < 7415 ) { return true; }
		if( test_char == 7418 ) { return true; }
		if( test_char >= 7424 && test_char < 7616 ) { return true; }
		if( test_char >= 7680 && test_char < 7958 ) { return true; }
		if( test_char >= 7960 && test_char < 7966 ) { return true; }
		if( test_char >= 7968 && test_char < 8006 ) { return true; }
		if( test_char >= 8008 && test_char < 8014 ) { return true; }
		if( test_char >= 8016 && test_char < 8024 ) { return true; }
		if( test_char == 8025 ) { return true; }
		if( test_char == 8027 ) { return true; }
		if( test_char == 8029 ) { return true; }
		if( test_char >= 8031 && test_char < 8062 ) { return true; }
		if( test_char >= 8064 && test_char < 8117 ) { return true; }
		if( test_char >= 8118 && test_char < 8125 ) { return true; }
		if( test_char == 8126 ) { return true; }
		if( test_char >= 8130 && test_char < 8133 ) { return true; }
		if( test_char >= 8134 && test_char < 8141 ) { return true; }
		if( test_char >= 8144 && test_char < 8148 ) { return true; }
		if( test_char >= 8150 && test_char < 8156 ) { return true; }
		if( test_char >= 8160 && test_char < 8173 ) { return true; }
		if( test_char >= 8178 && test_char < 8181 ) { return true; }
		if( test_char >= 8182 && test_char < 8189 ) { return true; }
		if( test_char == 8305 ) { return true; }
		if( test_char == 8319 ) { return true; }
		if( test_char >= 8336 && test_char < 8349 ) { return true; }
		if( test_char == 8450 ) { return true; }
		if( test_char == 8455 ) { return true; }
		if( test_char >= 8458 && test_char < 8468 ) { return true; }
		if( test_char == 8469 ) { return true; }
		if( test_char >= 8473 && test_char < 8478 ) { return true; }
		if( test_char == 8484 ) { return true; }
		if( test_char == 8486 ) { return true; }
		if( test_char == 8488 ) { return true; }
		if( test_char >= 8490 && test_char < 8494 ) { return true; }
		if( test_char >= 8495 && test_char < 8506 ) { return true; }
		if( test_char >= 8508 && test_char < 8512 ) { return true; }
		if( test_char >= 8517 && test_char < 8522 ) { return true; }
		if( test_char == 8526 ) { return true; }
		if( test_char >= 8579 && test_char < 8581 ) { return true; }
		if( test_char >= 11264 && test_char < 11493 ) { return true; }
		if( test_char >= 11499 && test_char < 11503 ) { return true; }
		if( test_char >= 11506 && test_char < 11508 ) { return true; }
		if( test_char >= 11520 && test_char < 11558 ) { return true; }
		if( test_char == 11559 ) { return true; }
		if( test_char == 11565 ) { return true; }
		if( test_char >= 11568 && test_char < 11624 ) { return true; }
		if( test_char == 11631 ) { return true; }
		if( test_char >= 11648 && test_char < 11671 ) { return true; }
		if( test_char >= 11680 && test_char < 11687 ) { return true; }
		if( test_char >= 11688 && test_char < 11695 ) { return true; }
		if( test_char >= 11696 && test_char < 11703 ) { return true; }
		if( test_char >= 11704 && test_char < 11711 ) { return true; }
		if( test_char >= 11712 && test_char < 11719 ) { return true; }
		if( test_char >= 11720 && test_char < 11727 ) { return true; }
		if( test_char >= 11728 && test_char < 11735 ) { return true; }
		if( test_char >= 11736 && test_char < 11743 ) { return true; }
		if( test_char == 11823 ) { return true; }
		if( test_char >= 12293 && test_char < 12295 ) { return true; }
		if( test_char >= 12337 && test_char < 12342 ) { return true; }
		if( test_char >= 12347 && test_char < 12349 ) { return true; }
		if( test_char >= 12353 && test_char < 12439 ) { return true; }
		if( test_char >= 12445 && test_char < 12448 ) { return true; }
		if( test_char >= 12449 && test_char < 12539 ) { return true; }
		if( test_char >= 12540 && test_char < 12544 ) { return true; }
		if( test_char >= 12549 && test_char < 12592 ) { return true; }
		if( test_char >= 12593 && test_char < 12687 ) { return true; }
		if( test_char >= 12704 && test_char < 12736 ) { return true; }
		if( test_char >= 12784 && test_char < 12800 ) { return true; }
		if( test_char >= 13312 && test_char < 19904 ) { return true; }
		if( test_char >= 19968 && test_char < 42125 ) { return true; }
		if( test_char >= 42192 && test_char < 42238 ) { return true; }
		if( test_char >= 42240 && test_char < 42509 ) { return true; }
		if( test_char >= 42512 && test_char < 42528 ) { return true; }
		if( test_char >= 42538 && test_char < 42540 ) { return true; }
		if( test_char >= 42560 && test_char < 42607 ) { return true; }
		if( test_char >= 42623 && test_char < 42654 ) { return true; }
		if( test_char >= 42656 && test_char < 42726 ) { return true; }
		if( test_char >= 42775 && test_char < 42784 ) { return true; }
		if( test_char >= 42786 && test_char < 42889 ) { return true; }
		if( test_char >= 42891 && test_char < 42955 ) { return true; }
		if( test_char >= 42960 && test_char < 42962 ) { return true; }
		if( test_char == 42963 ) { return true; }
		if( test_char >= 42965 && test_char < 42970 ) { return true; }
		if( test_char >= 42994 && test_char < 43010 ) { return true; }
		if( test_char >= 43011 && test_char < 43014 ) { return true; }
		if( test_char >= 43015 && test_char < 43019 ) { return true; }
		if( test_char >= 43020 && test_char < 43043 ) { return true; }
		if( test_char >= 43072 && test_char < 43124 ) { return true; }
		if( test_char >= 43138 && test_char < 43188 ) { return true; }
		if( test_char >= 43250 && test_char < 43256 ) { return true; }
		if( test_char == 43259 ) { return true; }
		if( test_char >= 43261 && test_char < 43263 ) { return true; }
		if( test_char >= 43274 && test_char < 43302 ) { return true; }
		if( test_char >= 43312 && test_char < 43335 ) { return true; }
		if( test_char >= 43360 && test_char < 43389 ) { return true; }
		if( test_char >= 43396 && test_char < 43443 ) { return true; }
		if( test_char == 43471 ) { return true; }
		if( test_char >= 43488 && test_char < 43493 ) { return true; }
		if( test_char >= 43494 && test_char < 43504 ) { return true; }
		if( test_char >= 43514 && test_char < 43519 ) { return true; }
		if( test_char >= 43520 && test_char < 43561 ) { return true; }
		if( test_char >= 43584 && test_char < 43587 ) { return true; }
		if( test_char >= 43588 && test_char < 43596 ) { return true; }
		if( test_char >= 43616 && test_char < 43639 ) { return true; }
		if( test_char == 43642 ) { return true; }
		if( test_char >= 43646 && test_char < 43696 ) { return true; }
		if( test_char == 43697 ) { return true; }
		if( test_char >= 43701 && test_char < 43703 ) { return true; }
		if( test_char >= 43705 && test_char < 43710 ) { return true; }
		if( test_char == 43712 ) { return true; }
		if( test_char == 43714 ) { return true; }
		if( test_char >= 43739 && test_char < 43742 ) { return true; }
		if( test_char >= 43744 && test_char < 43755 ) { return true; }
		if( test_char >= 43762 && test_char < 43765 ) { return true; }
		if( test_char >= 43777 && test_char < 43783 ) { return true; }
		if( test_char >= 43785 && test_char < 43791 ) { return true; }
		if( test_char >= 43793 && test_char < 43799 ) { return true; }
		if( test_char >= 43808 && test_char < 43815 ) { return true; }
		if( test_char >= 43816 && test_char < 43823 ) { return true; }
		if( test_char >= 43824 && test_char < 43867 ) { return true; }
		if( test_char >= 43868 && test_char < 43882 ) { return true; }
		if( test_char >= 43888 && test_char < 44003 ) { return true; }
		if( test_char >= 44032 && test_char < 55204 ) { return true; }
		if( test_char >= 55216 && test_char < 55239 ) { return true; }
		if( test_char >= 55243 && test_char < 55292 ) { return true; }
		if( test_char >= 63744 && test_char < 64110 ) { return true; }
		if( test_char >= 64112 && test_char < 64218 ) { return true; }
		if( test_char >= 64256 && test_char < 64263 ) { return true; }
		if( test_char >= 64275 && test_char < 64280 ) { return true; }
		if( test_char == 64285 ) { return true; }
		if( test_char >= 64287 && test_char < 64297 ) { return true; }
		if( test_char >= 64298 && test_char < 64311 ) { return true; }
		if( test_char >= 64312 && test_char < 64317 ) { return true; }
		if( test_char == 64318 ) { return true; }
		if( test_char >= 64320 && test_char < 64322 ) { return true; }
		if( test_char >= 64323 && test_char < 64325 ) { return true; }
		if( test_char >= 64326 && test_char < 64434 ) { return true; }
		if( test_char >= 64467 && test_char < 64830 ) { return true; }
		if( test_char >= 64848 && test_char < 64912 ) { return true; }
		if( test_char >= 64914 && test_char < 64968 ) { return true; }
		if( test_char >= 65008 && test_char < 65020 ) { return true; }
		if( test_char >= 65136 && test_char < 65141 ) { return true; }
		if( test_char >= 65142 && test_char < 65277 ) { return true; }
		if( test_char >= 65313 && test_char < 65339 ) { return true; }
		if( test_char >= 65345 && test_char < 65371 ) { return true; }
		if( test_char >= 65382 && test_char < 65471 ) { return true; }
		if( test_char >= 65474 && test_char < 65480 ) { return true; }
		if( test_char >= 65482 && test_char < 65488 ) { return true; }
		if( test_char >= 65490 && test_char < 65496 ) { return true; }
		if( test_char >= 65498 && test_char < 65501 ) { return true; }
		if( test_char >= 65536 && test_char < 65548 ) { return true; }
		if( test_char >= 65549 && test_char < 65575 ) { return true; }
		if( test_char >= 65576 && test_char < 65595 ) { return true; }
		if( test_char >= 65596 && test_char < 65598 ) { return true; }
		if( test_char >= 65599 && test_char < 65614 ) { return true; }
		if( test_char >= 65616 && test_char < 65630 ) { return true; }
		if( test_char >= 65664 && test_char < 65787 ) { return true; }
		if( test_char >= 66176 && test_char < 66205 ) { return true; }
		if( test_char >= 66208 && test_char < 66257 ) { return true; }
		if( test_char >= 66304 && test_char < 66336 ) { return true; }
		if( test_char >= 66349 && test_char < 66369 ) { return true; }
		if( test_char >= 66370 && test_char < 66378 ) { return true; }
		if( test_char >= 66384 && test_char < 66422 ) { return true; }
		if( test_char >= 66432 && test_char < 66462 ) { return true; }
		if( test_char >= 66464 && test_char < 66500 ) { return true; }
		if( test_char >= 66504 && test_char < 66512 ) { return true; }
		if( test_char >= 66560 && test_char < 66718 ) { return true; }
		if( test_char >= 66736 && test_char < 66772 ) { return true; }
		if( test_char >= 66776 && test_char < 66812 ) { return true; }
		if( test_char >= 66816 && test_char < 66856 ) { return true; }
		if( test_char >= 66864 && test_char < 66916 ) { return true; }
		if( test_char >= 66928 && test_char < 66939 ) { return true; }
		if( test_char >= 66940 && test_char < 66955 ) { return true; }
		if( test_char >= 66956 && test_char < 66963 ) { return true; }
		if( test_char >= 66964 && test_char < 66966 ) { return true; }
		if( test_char >= 66967 && test_char < 66978 ) { return true; }
		if( test_char >= 66979 && test_char < 66994 ) { return true; }
		if( test_char >= 66995 && test_char < 67002 ) { return true; }
		if( test_char >= 67003 && test_char < 67005 ) { return true; }
		if( test_char >= 67072 && test_char < 67383 ) { return true; }
		if( test_char >= 67392 && test_char < 67414 ) { return true; }
		if( test_char >= 67424 && test_char < 67432 ) { return true; }
		if( test_char >= 67456 && test_char < 67462 ) { return true; }
		if( test_char >= 67463 && test_char < 67505 ) { return true; }
		if( test_char >= 67506 && test_char < 67515 ) { return true; }
		if( test_char >= 67584 && test_char < 67590 ) { return true; }
		if( test_char == 67592 ) { return true; }
		if( test_char >= 67594 && test_char < 67638 ) { return true; }
		if( test_char >= 67639 && test_char < 67641 ) { return true; }
		if( test_char == 67644 ) { return true; }
		if( test_char >= 67647 && test_char < 67670 ) { return true; }
		if( test_char >= 67680 && test_char < 67703 ) { return true; }
		if( test_char >= 67712 && test_char < 67743 ) { return true; }
		if( test_char >= 67808 && test_char < 67827 ) { return true; }
		if( test_char >= 67828 && test_char < 67830 ) { return true; }
		if( test_char >= 67840 && test_char < 67862 ) { return true; }
		if( test_char >= 67872 && test_char < 67898 ) { return true; }
		if( test_char >= 67968 && test_char < 68024 ) { return true; }
		if( test_char >= 68030 && test_char < 68032 ) { return true; }
		if( test_char == 68096 ) { return true; }
		if( test_char >= 68112 && test_char < 68116 ) { return true; }
		if( test_char >= 68117 && test_char < 68120 ) { return true; }
		if( test_char >= 68121 && test_char < 68150 ) { return true; }
		if( test_char >= 68192 && test_char < 68221 ) { return true; }
		if( test_char >= 68224 && test_char < 68253 ) { return true; }
		if( test_char >= 68288 && test_char < 68296 ) { return true; }
		if( test_char >= 68297 && test_char < 68325 ) { return true; }
		if( test_char >= 68352 && test_char < 68406 ) { return true; }
		if( test_char >= 68416 && test_char < 68438 ) { return true; }
		if( test_char >= 68448 && test_char < 68467 ) { return true; }
		if( test_char >= 68480 && test_char < 68498 ) { return true; }
		if( test_char >= 68608 && test_char < 68681 ) { return true; }
		if( test_char >= 68736 && test_char < 68787 ) { return true; }
		if( test_char >= 68800 && test_char < 68851 ) { return true; }
		if( test_char >= 68864 && test_char < 68900 ) { return true; }
		if( test_char >= 69248 && test_char < 69290 ) { return true; }
		if( test_char >= 69296 && test_char < 69298 ) { return true; }
		if( test_char >= 69376 && test_char < 69405 ) { return true; }
		if( test_char == 69415 ) { return true; }
		if( test_char >= 69424 && test_char < 69446 ) { return true; }
		if( test_char >= 69488 && test_char < 69506 ) { return true; }
		if( test_char >= 69552 && test_char < 69573 ) { return true; }
		if( test_char >= 69600 && test_char < 69623 ) { return true; }
		if( test_char >= 69635 && test_char < 69688 ) { return true; }
		if( test_char >= 69745 && test_char < 69747 ) { return true; }
		if( test_char == 69749 ) { return true; }
		if( test_char >= 69763 && test_char < 69808 ) { return true; }
		if( test_char >= 69840 && test_char < 69865 ) { return true; }
		if( test_char >= 69891 && test_char < 69927 ) { return true; }
		if( test_char == 69956 ) { return true; }
		if( test_char == 69959 ) { return true; }
		if( test_char >= 69968 && test_char < 70003 ) { return true; }
		if( test_char == 70006 ) { return true; }
		if( test_char >= 70019 && test_char < 70067 ) { return true; }
		if( test_char >= 70081 && test_char < 70085 ) { return true; }
		if( test_char == 70106 ) { return true; }
		if( test_char == 70108 ) { return true; }
		if( test_char >= 70144 && test_char < 70162 ) { return true; }
		if( test_char >= 70163 && test_char < 70188 ) { return true; }
		if( test_char >= 70207 && test_char < 70209 ) { return true; }
		if( test_char >= 70272 && test_char < 70279 ) { return true; }
		if( test_char == 70280 ) { return true; }
		if( test_char >= 70282 && test_char < 70286 ) { return true; }
		if( test_char >= 70287 && test_char < 70302 ) { return true; }
		if( test_char >= 70303 && test_char < 70313 ) { return true; }
		if( test_char >= 70320 && test_char < 70367 ) { return true; }
		if( test_char >= 70405 && test_char < 70413 ) { return true; }
		if( test_char >= 70415 && test_char < 70417 ) { return true; }
		if( test_char >= 70419 && test_char < 70441 ) { return true; }
		if( test_char >= 70442 && test_char < 70449 ) { return true; }
		if( test_char >= 70450 && test_char < 70452 ) { return true; }
		if( test_char >= 70453 && test_char < 70458 ) { return true; }
		if( test_char == 70461 ) { return true; }
		if( test_char == 70480 ) { return true; }
		if( test_char >= 70493 && test_char < 70498 ) { return true; }
		if( test_char >= 70656 && test_char < 70709 ) { return true; }
		if( test_char >= 70727 && test_char < 70731 ) { return true; }
		if( test_char >= 70751 && test_char < 70754 ) { return true; }
		if( test_char >= 70784 && test_char < 70832 ) { return true; }
		if( test_char >= 70852 && test_char < 70854 ) { return true; }
		if( test_char == 70855 ) { return true; }
		if( test_char >= 71040 && test_char < 71087 ) { return true; }
		if( test_char >= 71128 && test_char < 71132 ) { return true; }
		if( test_char >= 71168 && test_char < 71216 ) { return true; }
		if( test_char == 71236 ) { return true; }
		if( test_char >= 71296 && test_char < 71339 ) { return true; }
		if( test_char == 71352 ) { return true; }
		if( test_char >= 71424 && test_char < 71451 ) { return true; }
		if( test_char >= 71488 && test_char < 71495 ) { return true; }
		if( test_char >= 71680 && test_char < 71724 ) { return true; }
		if( test_char >= 71840 && test_char < 71904 ) { return true; }
		if( test_char >= 71935 && test_char < 71943 ) { return true; }
		if( test_char == 71945 ) { return true; }
		if( test_char >= 71948 && test_char < 71956 ) { return true; }
		if( test_char >= 71957 && test_char < 71959 ) { return true; }
		if( test_char >= 71960 && test_char < 71984 ) { return true; }
		if( test_char == 71999 ) { return true; }
		if( test_char == 72001 ) { return true; }
		if( test_char >= 72096 && test_char < 72104 ) { return true; }
		if( test_char >= 72106 && test_char < 72145 ) { return true; }
		if( test_char == 72161 ) { return true; }
		if( test_char == 72163 ) { return true; }
		if( test_char == 72192 ) { return true; }
		if( test_char >= 72203 && test_char < 72243 ) { return true; }
		if( test_char == 72250 ) { return true; }
		if( test_char == 72272 ) { return true; }
		if( test_char >= 72284 && test_char < 72330 ) { return true; }
		if( test_char == 72349 ) { return true; }
		if( test_char >= 72368 && test_char < 72441 ) { return true; }
		if( test_char >= 72704 && test_char < 72713 ) { return true; }
		if( test_char >= 72714 && test_char < 72751 ) { return true; }
		if( test_char == 72768 ) { return true; }
		if( test_char >= 72818 && test_char < 72848 ) { return true; }
		if( test_char >= 72960 && test_char < 72967 ) { return true; }
		if( test_char >= 72968 && test_char < 72970 ) { return true; }
		if( test_char >= 72971 && test_char < 73009 ) { return true; }
		if( test_char == 73030 ) { return true; }
		if( test_char >= 73056 && test_char < 73062 ) { return true; }
		if( test_char >= 73063 && test_char < 73065 ) { return true; }
		if( test_char >= 73066 && test_char < 73098 ) { return true; }
		if( test_char == 73112 ) { return true; }
		if( test_char >= 73440 && test_char < 73459 ) { return true; }
		if( test_char == 73474 ) { return true; }
		if( test_char >= 73476 && test_char < 73489 ) { return true; }
		if( test_char >= 73490 && test_char < 73524 ) { return true; }
		if( test_char == 73648 ) { return true; }
		if( test_char >= 73728 && test_char < 74650 ) { return true; }
		if( test_char >= 74880 && test_char < 75076 ) { return true; }
		if( test_char >= 77712 && test_char < 77809 ) { return true; }
		if( test_char >= 77824 && test_char < 78896 ) { return true; }
		if( test_char >= 78913 && test_char < 78919 ) { return true; }
		if( test_char >= 82944 && test_char < 83527 ) { return true; }
		if( test_char >= 92160 && test_char < 92729 ) { return true; }
		if( test_char >= 92736 && test_char < 92767 ) { return true; }
		if( test_char >= 92784 && test_char < 92863 ) { return true; }
		if( test_char >= 92880 && test_char < 92910 ) { return true; }
		if( test_char >= 92928 && test_char < 92976 ) { return true; }
		if( test_char >= 92992 && test_char < 92996 ) { return true; }
		if( test_char >= 93027 && test_char < 93048 ) { return true; }
		if( test_char >= 93053 && test_char < 93072 ) { return true; }
		if( test_char >= 93760 && test_char < 93824 ) { return true; }
		if( test_char >= 93952 && test_char < 94027 ) { return true; }
		if( test_char == 94032 ) { return true; }
		if( test_char >= 94099 && test_char < 94112 ) { return true; }
		if( test_char >= 94176 && test_char < 94178 ) { return true; }
		if( test_char == 94179 ) { return true; }
		if( test_char >= 94208 && test_char < 100344 ) { return true; }
		if( test_char >= 100352 && test_char < 101590 ) { return true; }
		if( test_char >= 101632 && test_char < 101641 ) { return true; }
		if( test_char >= 110576 && test_char < 110580 ) { return true; }
		if( test_char >= 110581 && test_char < 110588 ) { return true; }
		if( test_char >= 110589 && test_char < 110591 ) { return true; }
		if( test_char >= 110592 && test_char < 110883 ) { return true; }
		if( test_char == 110898 ) { return true; }
		if( test_char >= 110928 && test_char < 110931 ) { return true; }
		if( test_char == 110933 ) { return true; }
		if( test_char >= 110948 && test_char < 110952 ) { return true; }
		if( test_char >= 110960 && test_char < 111356 ) { return true; }
		if( test_char >= 113664 && test_char < 113771 ) { return true; }
		if( test_char >= 113776 && test_char < 113789 ) { return true; }
		if( test_char >= 113792 && test_char < 113801 ) { return true; }
		if( test_char >= 113808 && test_char < 113818 ) { return true; }
		if( test_char >= 119808 && test_char < 119893 ) { return true; }
		if( test_char >= 119894 && test_char < 119965 ) { return true; }
		if( test_char >= 119966 && test_char < 119968 ) { return true; }
		if( test_char == 119970 ) { return true; }
		if( test_char >= 119973 && test_char < 119975 ) { return true; }
		if( test_char >= 119977 && test_char < 119981 ) { return true; }
		if( test_char >= 119982 && test_char < 119994 ) { return true; }
		if( test_char == 119995 ) { return true; }
		if( test_char >= 119997 && test_char < 120004 ) { return true; }
		if( test_char >= 120005 && test_char < 120070 ) { return true; }
		if( test_char >= 120071 && test_char < 120075 ) { return true; }
		if( test_char >= 120077 && test_char < 120085 ) { return true; }
		if( test_char >= 120086 && test_char < 120093 ) { return true; }
		if( test_char >= 120094 && test_char < 120122 ) { return true; }
		if( test_char >= 120123 && test_char < 120127 ) { return true; }
		if( test_char >= 120128 && test_char < 120133 ) { return true; }
		if( test_char == 120134 ) { return true; }
		if( test_char >= 120138 && test_char < 120145 ) { return true; }
		if( test_char >= 120146 && test_char < 120486 ) { return true; }
		if( test_char >= 120488 && test_char < 120513 ) { return true; }
		if( test_char >= 120514 && test_char < 120539 ) { return true; }
		if( test_char >= 120540 && test_char < 120571 ) { return true; }
		if( test_char >= 120572 && test_char < 120597 ) { return true; }
		if( test_char >= 120598 && test_char < 120629 ) { return true; }
		if( test_char >= 120630 && test_char < 120655 ) { return true; }
		if( test_char >= 120656 && test_char < 120687 ) { return true; }
		if( test_char >= 120688 && test_char < 120713 ) { return true; }
		if( test_char >= 120714 && test_char < 120745 ) { return true; }
		if( test_char >= 120746 && test_char < 120771 ) { return true; }
		if( test_char >= 120772 && test_char < 120780 ) { return true; }
		if( test_char >= 122624 && test_char < 122655 ) { return true; }
		if( test_char >= 122661 && test_char < 122667 ) { return true; }
		if( test_char >= 122928 && test_char < 122990 ) { return true; }
		if( test_char >= 123136 && test_char < 123181 ) { return true; }
		if( test_char >= 123191 && test_char < 123198 ) { return true; }
		if( test_char == 123214 ) { return true; }
		if( test_char >= 123536 && test_char < 123566 ) { return true; }
		if( test_char >= 123584 && test_char < 123628 ) { return true; }
		if( test_char >= 124112 && test_char < 124140 ) { return true; }
		if( test_char >= 124896 && test_char < 124903 ) { return true; }
		if( test_char >= 124904 && test_char < 124908 ) { return true; }
		if( test_char >= 124909 && test_char < 124911 ) { return true; }
		if( test_char >= 124912 && test_char < 124927 ) { return true; }
		if( test_char >= 124928 && test_char < 125125 ) { return true; }
		if( test_char >= 125184 && test_char < 125252 ) { return true; }
		if( test_char == 125259 ) { return true; }
		if( test_char >= 126464 && test_char < 126468 ) { return true; }
		if( test_char >= 126469 && test_char < 126496 ) { return true; }
		if( test_char >= 126497 && test_char < 126499 ) { return true; }
		if( test_char == 126500 ) { return true; }
		if( test_char == 126503 ) { return true; }
		if( test_char >= 126505 && test_char < 126515 ) { return true; }
		if( test_char >= 126516 && test_char < 126520 ) { return true; }
		if( test_char == 126521 ) { return true; }
		if( test_char == 126523 ) { return true; }
		if( test_char == 126530 ) { return true; }
		if( test_char == 126535 ) { return true; }
		if( test_char == 126537 ) { return true; }
		if( test_char == 126539 ) { return true; }
		if( test_char >= 126541 && test_char < 126544 ) { return true; }
		if( test_char >= 126545 && test_char < 126547 ) { return true; }
		if( test_char == 126548 ) { return true; }
		if( test_char == 126551 ) { return true; }
		if( test_char == 126553 ) { return true; }
		if( test_char == 126555 ) { return true; }
		if( test_char == 126557 ) { return true; }
		if( test_char == 126559 ) { return true; }
		if( test_char >= 126561 && test_char < 126563 ) { return true; }
		if( test_char == 126564 ) { return true; }
		if( test_char >= 126567 && test_char < 126571 ) { return true; }
		if( test_char >= 126572 && test_char < 126579 ) { return true; }
		if( test_char >= 126580 && test_char < 126584 ) { return true; }
		if( test_char >= 126585 && test_char < 126589 ) { return true; }
		if( test_char == 126590 ) { return true; }
		if( test_char >= 126592 && test_char < 126602 ) { return true; }
		if( test_char >= 126603 && test_char < 126620 ) { return true; }
		if( test_char >= 126625 && test_char < 126628 ) { return true; }
		if( test_char >= 126629 && test_char < 126634 ) { return true; }
		if( test_char >= 126635 && test_char < 126652 ) { return true; }
		if( test_char >= 131072 && test_char < 173792 ) { return true; }
		if( test_char >= 173824 && test_char < 177978 ) { return true; }
		if( test_char >= 177984 && test_char < 178206 ) { return true; }
		if( test_char >= 178208 && test_char < 183970 ) { return true; }
		if( test_char >= 183984 && test_char < 191457 ) { return true; }
		if( test_char >= 191472 && test_char < 192094 ) { return true; }
		if( test_char >= 194560 && test_char < 195102 ) { return true; }
		if( test_char >= 196608 && test_char < 201547 ) { return true; }
		if( test_char >= 201552 && test_char < 205744 ) { return true; }

		return false;
	}
	
	bool is_ascii(char32_t test_char) noexcept {
		if( test_char >= 0 && test_char < 128 ) { return true; }

		return false;
	}
	
	bool is_digit(char32_t test_char) noexcept {
		if( test_char >= 48 && test_char < 58 ) { return true; }
		if( test_char >= 178 && test_char < 180 ) { return true; }
		if( test_char == 185 ) { return true; }
		if( test_char >= 1632 && test_char < 1642 ) { return true; }
		if( test_char >= 1776 && test_char < 1786 ) { return true; }
		if( test_char >= 1984 && test_char < 1994 ) { return true; }
		if( test_char >= 2406 && test_char < 2416 ) { return true; }
		if( test_char >= 2534 && test_char < 2544 ) { return true; }
		if( test_char >= 2662 && test_char < 2672 ) { return true; }
		if( test_char >= 2790 && test_char < 2800 ) { return true; }
		if( test_char >= 2918 && test_char < 2928 ) { return true; }
		if( test_char >= 3046 && test_char < 3056 ) { return true; }
		if( test_char >= 3174 && test_char < 3184 ) { return true; }
		if( test_char >= 3302 && test_char < 3312 ) { return true; }
		if( test_char >= 3430 && test_char < 3440 ) { return true; }
		if( test_char >= 3558 && test_char < 3568 ) { return true; }
		if( test_char >= 3664 && test_char < 3674 ) { return true; }
		if( test_char >= 3792 && test_char < 3802 ) { return true; }
		if( test_char >= 3872 && test_char < 3882 ) { return true; }
		if( test_char >= 4160 && test_char < 4170 ) { return true; }
		if( test_char >= 4240 && test_char < 4250 ) { return true; }
		if( test_char >= 4969 && test_char < 4978 ) { return true; }
		if( test_char >= 6112 && test_char < 6122 ) { return true; }
		if( test_char >= 6160 && test_char < 6170 ) { return true; }
		if( test_char >= 6470 && test_char < 6480 ) { return true; }
		if( test_char >= 6608 && test_char < 6619 ) { return true; }
		if( test_char >= 6784 && test_char < 6794 ) { return true; }
		if( test_char >= 6800 && test_char < 6810 ) { return true; }
		if( test_char >= 6992 && test_char < 7002 ) { return true; }
		if( test_char >= 7088 && test_char < 7098 ) { return true; }
		if( test_char >= 7232 && test_char < 7242 ) { return true; }
		if( test_char >= 7248 && test_char < 7258 ) { return true; }
		if( test_char == 8304 ) { return true; }
		if( test_char >= 8308 && test_char < 8314 ) { return true; }
		if( test_char >= 8320 && test_char < 8330 ) { return true; }
		if( test_char >= 9312 && test_char < 9321 ) { return true; }
		if( test_char >= 9332 && test_char < 9341 ) { return true; }
		if( test_char >= 9352 && test_char < 9361 ) { return true; }
		if( test_char == 9450 ) { return true; }
		if( test_char >= 9461 && test_char < 9470 ) { return true; }
		if( test_char == 9471 ) { return true; }
		if( test_char >= 10102 && test_char < 10111 ) { return true; }
		if( test_char >= 10112 && test_char < 10121 ) { return true; }
		if( test_char >= 10122 && test_char < 10131 ) { return true; }
		if( test_char >= 42528 && test_char < 42538 ) { return true; }
		if( test_char >= 43216 && test_char < 43226 ) { return true; }
		if( test_char >= 43264 && test_char < 43274 ) { return true; }
		if( test_char >= 43472 && test_char < 43482 ) { return true; }
		if( test_char >= 43504 && test_char < 43514 ) { return true; }
		if( test_char >= 43600 && test_char < 43610 ) { return true; }
		if( test_char >= 44016 && test_char < 44026 ) { return true; }
		if( test_char >= 65296 && test_char < 65306 ) { return true; }
		if( test_char >= 66720 && test_char < 66730 ) { return true; }
		if( test_char >= 68160 && test_char < 68164 ) { return true; }
		if( test_char >= 68912 && test_char < 68922 ) { return true; }
		if( test_char >= 69216 && test_char < 69225 ) { return true; }
		if( test_char >= 69714 && test_char < 69723 ) { return true; }
		if( test_char >= 69734 && test_char < 69744 ) { return true; }
		if( test_char >= 69872 && test_char < 69882 ) { return true; }
		if( test_char >= 69942 && test_char < 69952 ) { return true; }
		if( test_char >= 70096 && test_char < 70106 ) { return true; }
		if( test_char >= 70384 && test_char < 70394 ) { return true; }
		if( test_char >= 70736 && test_char < 70746 ) { return true; }
		if( test_char >= 70864 && test_char < 70874 ) { return true; }
		if( test_char >= 71248 && test_char < 71258 ) { return true; }
		if( test_char >= 71360 && test_char < 71370 ) { return true; }
		if( test_char >= 71472 && test_char < 71482 ) { return true; }
		if( test_char >= 71904 && test_char < 71914 ) { return true; }
		if( test_char >= 72016 && test_char < 72026 ) { return true; }
		if( test_char >= 72784 && test_char < 72794 ) { return true; }
		if( test_char >= 73040 && test_char < 73050 ) { return true; }
		if( test_char >= 73120 && test_char < 73130 ) { return true; }
		if( test_char >= 73552 && test_char < 73562 ) { return true; }
		if( test_char >= 92768 && test_char < 92778 ) { return true; }
		if( test_char >= 92864 && test_char < 92874 ) { return true; }
		if( test_char >= 93008 && test_char < 93018 ) { return true; }
		if( test_char >= 120782 && test_char < 120832 ) { return true; }
		if( test_char >= 123200 && test_char < 123210 ) { return true; }
		if( test_char >= 123632 && test_char < 123642 ) { return true; }
		if( test_char >= 124144 && test_char < 124154 ) { return true; }
		if( test_char >= 125264 && test_char < 125274 ) { return true; }
		if( test_char >= 127232 && test_char < 127243 ) { return true; }
		if( test_char >= 130032 && test_char < 130042 ) { return true; }

		return false;
	}
	
	bool is_lower_case(char32_t test_char) noexcept {
		if( test_char >= 97 && test_char < 123 ) { return true; }
		if( test_char == 170 ) { return true; }
		if( test_char == 181 ) { return true; }
		if( test_char == 186 ) { return true; }
		if( test_char >= 223 && test_char < 247 ) { return true; }
		if( test_char >= 248 && test_char < 256 ) { return true; }
		if( test_char == 257 ) { return true; }
		if( test_char == 259 ) { return true; }
		if( test_char == 261 ) { return true; }
		if( test_char == 263 ) { return true; }
		if( test_char == 265 ) { return true; }
		if( test_char == 267 ) { return true; }
		if( test_char == 269 ) { return true; }
		if( test_char == 271 ) { return true; }
		if( test_char == 273 ) { return true; }
		if( test_char == 275 ) { return true; }
		if( test_char == 277 ) { return true; }
		if( test_char == 279 ) { return true; }
		if( test_char == 281 ) { return true; }
		if( test_char == 283 ) { return true; }
		if( test_char == 285 ) { return true; }
		if( test_char == 287 ) { return true; }
		if( test_char == 289 ) { return true; }
		if( test_char == 291 ) { return true; }
		if( test_char == 293 ) { return true; }
		if( test_char == 295 ) { return true; }
		if( test_char == 297 ) { return true; }
		if( test_char == 299 ) { return true; }
		if( test_char == 301 ) { return true; }
		if( test_char == 303 ) { return true; }
		if( test_char == 305 ) { return true; }
		if( test_char == 307 ) { return true; }
		if( test_char == 309 ) { return true; }
		if( test_char >= 311 && test_char < 313 ) { return true; }
		if( test_char == 314 ) { return true; }
		if( test_char == 316 ) { return true; }
		if( test_char == 318 ) { return true; }
		if( test_char == 320 ) { return true; }
		if( test_char == 322 ) { return true; }
		if( test_char == 324 ) { return true; }
		if( test_char == 326 ) { return true; }
		if( test_char >= 328 && test_char < 330 ) { return true; }
		if( test_char == 331 ) { return true; }
		if( test_char == 333 ) { return true; }
		if( test_char == 335 ) { return true; }
		if( test_char == 337 ) { return true; }
		if( test_char == 339 ) { return true; }
		if( test_char == 341 ) { return true; }
		if( test_char == 343 ) { return true; }
		if( test_char == 345 ) { return true; }
		if( test_char == 347 ) { return true; }
		if( test_char == 349 ) { return true; }
		if( test_char == 351 ) { return true; }
		if( test_char == 353 ) { return true; }
		if( test_char == 355 ) { return true; }
		if( test_char == 357 ) { return true; }
		if( test_char == 359 ) { return true; }
		if( test_char == 361 ) { return true; }
		if( test_char == 363 ) { return true; }
		if( test_char == 365 ) { return true; }
		if( test_char == 367 ) { return true; }
		if( test_char == 369 ) { return true; }
		if( test_char == 371 ) { return true; }
		if( test_char == 373 ) { return true; }
		if( test_char == 375 ) { return true; }
		if( test_char == 378 ) { return true; }
		if( test_char == 380 ) { return true; }
		if( test_char >= 382 && test_char < 385 ) { return true; }
		if( test_char == 387 ) { return true; }
		if( test_char == 389 ) { return true; }
		if( test_char == 392 ) { return true; }
		if( test_char >= 396 && test_char < 398 ) { return true; }
		if( test_char == 402 ) { return true; }
		if( test_char == 405 ) { return true; }
		if( test_char >= 409 && test_char < 412 ) { return true; }
		if( test_char == 414 ) { return true; }
		if( test_char == 417 ) { return true; }
		if( test_char == 419 ) { return true; }
		if( test_char == 421 ) { return true; }
		if( test_char == 424 ) { return true; }
		if( test_char >= 426 && test_char < 428 ) { return true; }
		if( test_char == 429 ) { return true; }
		if( test_char == 432 ) { return true; }
		if( test_char == 436 ) { return true; }
		if( test_char == 438 ) { return true; }
		if( test_char >= 441 && test_char < 443 ) { return true; }
		if( test_char >= 445 && test_char < 448 ) { return true; }
		if( test_char == 454 ) { return true; }
		if( test_char == 457 ) { return true; }
		if( test_char == 460 ) { return true; }
		if( test_char == 462 ) { return true; }
		if( test_char == 464 ) { return true; }
		if( test_char == 466 ) { return true; }
		if( test_char == 468 ) { return true; }
		if( test_char == 470 ) { return true; }
		if( test_char == 472 ) { return true; }
		if( test_char == 474 ) { return true; }
		if( test_char >= 476 && test_char < 478 ) { return true; }
		if( test_char == 479 ) { return true; }
		if( test_char == 481 ) { return true; }
		if( test_char == 483 ) { return true; }
		if( test_char == 485 ) { return true; }
		if( test_char == 487 ) { return true; }
		if( test_char == 489 ) { return true; }
		if( test_char == 491 ) { return true; }
		if( test_char == 493 ) { return true; }
		if( test_char >= 495 && test_char < 497 ) { return true; }
		if( test_char == 499 ) { return true; }
		if( test_char == 501 ) { return true; }
		if( test_char == 505 ) { return true; }
		if( test_char == 507 ) { return true; }
		if( test_char == 509 ) { return true; }
		if( test_char == 511 ) { return true; }
		if( test_char == 513 ) { return true; }
		if( test_char == 515 ) { return true; }
		if( test_char == 517 ) { return true; }
		if( test_char == 519 ) { return true; }
		if( test_char == 521 ) { return true; }
		if( test_char == 523 ) { return true; }
		if( test_char == 525 ) { return true; }
		if( test_char == 527 ) { return true; }
		if( test_char == 529 ) { return true; }
		if( test_char == 531 ) { return true; }
		if( test_char == 533 ) { return true; }
		if( test_char == 535 ) { return true; }
		if( test_char == 537 ) { return true; }
		if( test_char == 539 ) { return true; }
		if( test_char == 541 ) { return true; }
		if( test_char == 543 ) { return true; }
		if( test_char == 545 ) { return true; }
		if( test_char == 547 ) { return true; }
		if( test_char == 549 ) { return true; }
		if( test_char == 551 ) { return true; }
		if( test_char == 553 ) { return true; }
		if( test_char == 555 ) { return true; }
		if( test_char == 557 ) { return true; }
		if( test_char == 559 ) { return true; }
		if( test_char == 561 ) { return true; }
		if( test_char >= 563 && test_char < 570 ) { return true; }
		if( test_char == 572 ) { return true; }
		if( test_char >= 575 && test_char < 577 ) { return true; }
		if( test_char == 578 ) { return true; }
		if( test_char == 583 ) { return true; }
		if( test_char == 585 ) { return true; }
		if( test_char == 587 ) { return true; }
		if( test_char == 589 ) { return true; }
		if( test_char >= 591 && test_char < 660 ) { return true; }
		if( test_char >= 661 && test_char < 697 ) { return true; }
		if( test_char >= 704 && test_char < 706 ) { return true; }
		if( test_char >= 736 && test_char < 741 ) { return true; }
		if( test_char == 837 ) { return true; }
		if( test_char == 881 ) { return true; }
		if( test_char == 883 ) { return true; }
		if( test_char == 887 ) { return true; }
		if( test_char >= 890 && test_char < 894 ) { return true; }
		if( test_char == 912 ) { return true; }
		if( test_char >= 940 && test_char < 975 ) { return true; }
		if( test_char >= 976 && test_char < 978 ) { return true; }
		if( test_char >= 981 && test_char < 984 ) { return true; }
		if( test_char == 985 ) { return true; }
		if( test_char == 987 ) { return true; }
		if( test_char == 989 ) { return true; }
		if( test_char == 991 ) { return true; }
		if( test_char == 993 ) { return true; }
		if( test_char == 995 ) { return true; }
		if( test_char == 997 ) { return true; }
		if( test_char == 999 ) { return true; }
		if( test_char == 1001 ) { return true; }
		if( test_char == 1003 ) { return true; }
		if( test_char == 1005 ) { return true; }
		if( test_char >= 1007 && test_char < 1012 ) { return true; }
		if( test_char == 1013 ) { return true; }
		if( test_char == 1016 ) { return true; }
		if( test_char >= 1019 && test_char < 1021 ) { return true; }
		if( test_char >= 1072 && test_char < 1120 ) { return true; }
		if( test_char == 1121 ) { return true; }
		if( test_char == 1123 ) { return true; }
		if( test_char == 1125 ) { return true; }
		if( test_char == 1127 ) { return true; }
		if( test_char == 1129 ) { return true; }
		if( test_char == 1131 ) { return true; }
		if( test_char == 1133 ) { return true; }
		if( test_char == 1135 ) { return true; }
		if( test_char == 1137 ) { return true; }
		if( test_char == 1139 ) { return true; }
		if( test_char == 1141 ) { return true; }
		if( test_char == 1143 ) { return true; }
		if( test_char == 1145 ) { return true; }
		if( test_char == 1147 ) { return true; }
		if( test_char == 1149 ) { return true; }
		if( test_char == 1151 ) { return true; }
		if( test_char == 1153 ) { return true; }
		if( test_char == 1163 ) { return true; }
		if( test_char == 1165 ) { return true; }
		if( test_char == 1167 ) { return true; }
		if( test_char == 1169 ) { return true; }
		if( test_char == 1171 ) { return true; }
		if( test_char == 1173 ) { return true; }
		if( test_char == 1175 ) { return true; }
		if( test_char == 1177 ) { return true; }
		if( test_char == 1179 ) { return true; }
		if( test_char == 1181 ) { return true; }
		if( test_char == 1183 ) { return true; }
		if( test_char == 1185 ) { return true; }
		if( test_char == 1187 ) { return true; }
		if( test_char == 1189 ) { return true; }
		if( test_char == 1191 ) { return true; }
		if( test_char == 1193 ) { return true; }
		if( test_char == 1195 ) { return true; }
		if( test_char == 1197 ) { return true; }
		if( test_char == 1199 ) { return true; }
		if( test_char == 1201 ) { return true; }
		if( test_char == 1203 ) { return true; }
		if( test_char == 1205 ) { return true; }
		if( test_char == 1207 ) { return true; }
		if( test_char == 1209 ) { return true; }
		if( test_char == 1211 ) { return true; }
		if( test_char == 1213 ) { return true; }
		if( test_char == 1215 ) { return true; }
		if( test_char == 1218 ) { return true; }
		if( test_char == 1220 ) { return true; }
		if( test_char == 1222 ) { return true; }
		if( test_char == 1224 ) { return true; }
		if( test_char == 1226 ) { return true; }
		if( test_char == 1228 ) { return true; }
		if( test_char >= 1230 && test_char < 1232 ) { return true; }
		if( test_char == 1233 ) { return true; }
		if( test_char == 1235 ) { return true; }
		if( test_char == 1237 ) { return true; }
		if( test_char == 1239 ) { return true; }
		if( test_char == 1241 ) { return true; }
		if( test_char == 1243 ) { return true; }
		if( test_char == 1245 ) { return true; }
		if( test_char == 1247 ) { return true; }
		if( test_char == 1249 ) { return true; }
		if( test_char == 1251 ) { return true; }
		if( test_char == 1253 ) { return true; }
		if( test_char == 1255 ) { return true; }
		if( test_char == 1257 ) { return true; }
		if( test_char == 1259 ) { return true; }
		if( test_char == 1261 ) { return true; }
		if( test_char == 1263 ) { return true; }
		if( test_char == 1265 ) { return true; }
		if( test_char == 1267 ) { return true; }
		if( test_char == 1269 ) { return true; }
		if( test_char == 1271 ) { return true; }
		if( test_char == 1273 ) { return true; }
		if( test_char == 1275 ) { return true; }
		if( test_char == 1277 ) { return true; }
		if( test_char == 1279 ) { return true; }
		if( test_char == 1281 ) { return true; }
		if( test_char == 1283 ) { return true; }
		if( test_char == 1285 ) { return true; }
		if( test_char == 1287 ) { return true; }
		if( test_char == 1289 ) { return true; }
		if( test_char == 1291 ) { return true; }
		if( test_char == 1293 ) { return true; }
		if( test_char == 1295 ) { return true; }
		if( test_char == 1297 ) { return true; }
		if( test_char == 1299 ) { return true; }
		if( test_char == 1301 ) { return true; }
		if( test_char == 1303 ) { return true; }
		if( test_char == 1305 ) { return true; }
		if( test_char == 1307 ) { return true; }
		if( test_char == 1309 ) { return true; }
		if( test_char == 1311 ) { return true; }
		if( test_char == 1313 ) { return true; }
		if( test_char == 1315 ) { return true; }
		if( test_char == 1317 ) { return true; }
		if( test_char == 1319 ) { return true; }
		if( test_char == 1321 ) { return true; }
		if( test_char == 1323 ) { return true; }
		if( test_char == 1325 ) { return true; }
		if( test_char == 1327 ) { return true; }
		if( test_char >= 1376 && test_char < 1417 ) { return true; }
		if( test_char >= 4304 && test_char < 4347 ) { return true; }
		if( test_char >= 4348 && test_char < 4352 ) { return true; }
		if( test_char >= 5112 && test_char < 5118 ) { return true; }
		if( test_char >= 7296 && test_char < 7305 ) { return true; }
		if( test_char >= 7424 && test_char < 7616 ) { return true; }
		if( test_char == 7681 ) { return true; }
		if( test_char == 7683 ) { return true; }
		if( test_char == 7685 ) { return true; }
		if( test_char == 7687 ) { return true; }
		if( test_char == 7689 ) { return true; }
		if( test_char == 7691 ) { return true; }
		if( test_char == 7693 ) { return true; }
		if( test_char == 7695 ) { return true; }
		if( test_char == 7697 ) { return true; }
		if( test_char == 7699 ) { return true; }
		if( test_char == 7701 ) { return true; }
		if( test_char == 7703 ) { return true; }
		if( test_char == 7705 ) { return true; }
		if( test_char == 7707 ) { return true; }
		if( test_char == 7709 ) { return true; }
		if( test_char == 7711 ) { return true; }
		if( test_char == 7713 ) { return true; }
		if( test_char == 7715 ) { return true; }
		if( test_char == 7717 ) { return true; }
		if( test_char == 7719 ) { return true; }
		if( test_char == 7721 ) { return true; }
		if( test_char == 7723 ) { return true; }
		if( test_char == 7725 ) { return true; }
		if( test_char == 7727 ) { return true; }
		if( test_char == 7729 ) { return true; }
		if( test_char == 7731 ) { return true; }
		if( test_char == 7733 ) { return true; }
		if( test_char == 7735 ) { return true; }
		if( test_char == 7737 ) { return true; }
		if( test_char == 7739 ) { return true; }
		if( test_char == 7741 ) { return true; }
		if( test_char == 7743 ) { return true; }
		if( test_char == 7745 ) { return true; }
		if( test_char == 7747 ) { return true; }
		if( test_char == 7749 ) { return true; }
		if( test_char == 7751 ) { return true; }
		if( test_char == 7753 ) { return true; }
		if( test_char == 7755 ) { return true; }
		if( test_char == 7757 ) { return true; }
		if( test_char == 7759 ) { return true; }
		if( test_char == 7761 ) { return true; }
		if( test_char == 7763 ) { return true; }
		if( test_char == 7765 ) { return true; }
		if( test_char == 7767 ) { return true; }
		if( test_char == 7769 ) { return true; }
		if( test_char == 7771 ) { return true; }
		if( test_char == 7773 ) { return true; }
		if( test_char == 7775 ) { return true; }
		if( test_char == 7777 ) { return true; }
		if( test_char == 7779 ) { return true; }
		if( test_char == 7781 ) { return true; }
		if( test_char == 7783 ) { return true; }
		if( test_char == 7785 ) { return true; }
		if( test_char == 7787 ) { return true; }
		if( test_char == 7789 ) { return true; }
		if( test_char == 7791 ) { return true; }
		if( test_char == 7793 ) { return true; }
		if( test_char == 7795 ) { return true; }
		if( test_char == 7797 ) { return true; }
		if( test_char == 7799 ) { return true; }
		if( test_char == 7801 ) { return true; }
		if( test_char == 7803 ) { return true; }
		if( test_char == 7805 ) { return true; }
		if( test_char == 7807 ) { return true; }
		if( test_char == 7809 ) { return true; }
		if( test_char == 7811 ) { return true; }
		if( test_char == 7813 ) { return true; }
		if( test_char == 7815 ) { return true; }
		if( test_char == 7817 ) { return true; }
		if( test_char == 7819 ) { return true; }
		if( test_char == 7821 ) { return true; }
		if( test_char == 7823 ) { return true; }
		if( test_char == 7825 ) { return true; }
		if( test_char == 7827 ) { return true; }
		if( test_char >= 7829 && test_char < 7838 ) { return true; }
		if( test_char == 7839 ) { return true; }
		if( test_char == 7841 ) { return true; }
		if( test_char == 7843 ) { return true; }
		if( test_char == 7845 ) { return true; }
		if( test_char == 7847 ) { return true; }
		if( test_char == 7849 ) { return true; }
		if( test_char == 7851 ) { return true; }
		if( test_char == 7853 ) { return true; }
		if( test_char == 7855 ) { return true; }
		if( test_char == 7857 ) { return true; }
		if( test_char == 7859 ) { return true; }
		if( test_char == 7861 ) { return true; }
		if( test_char == 7863 ) { return true; }
		if( test_char == 7865 ) { return true; }
		if( test_char == 7867 ) { return true; }
		if( test_char == 7869 ) { return true; }
		if( test_char == 7871 ) { return true; }
		if( test_char == 7873 ) { return true; }
		if( test_char == 7875 ) { return true; }
		if( test_char == 7877 ) { return true; }
		if( test_char == 7879 ) { return true; }
		if( test_char == 7881 ) { return true; }
		if( test_char == 7883 ) { return true; }
		if( test_char == 7885 ) { return true; }
		if( test_char == 7887 ) { return true; }
		if( test_char == 7889 ) { return true; }
		if( test_char == 7891 ) { return true; }
		if( test_char == 7893 ) { return true; }
		if( test_char == 7895 ) { return true; }
		if( test_char == 7897 ) { return true; }
		if( test_char == 7899 ) { return true; }
		if( test_char == 7901 ) { return true; }
		if( test_char == 7903 ) { return true; }
		if( test_char == 7905 ) { return true; }
		if( test_char == 7907 ) { return true; }
		if( test_char == 7909 ) { return true; }
		if( test_char == 7911 ) { return true; }
		if( test_char == 7913 ) { return true; }
		if( test_char == 7915 ) { return true; }
		if( test_char == 7917 ) { return true; }
		if( test_char == 7919 ) { return true; }
		if( test_char == 7921 ) { return true; }
		if( test_char == 7923 ) { return true; }
		if( test_char == 7925 ) { return true; }
		if( test_char == 7927 ) { return true; }
		if( test_char == 7929 ) { return true; }
		if( test_char == 7931 ) { return true; }
		if( test_char == 7933 ) { return true; }
		if( test_char >= 7935 && test_char < 7944 ) { return true; }
		if( test_char >= 7952 && test_char < 7958 ) { return true; }
		if( test_char >= 7968 && test_char < 7976 ) { return true; }
		if( test_char >= 7984 && test_char < 7992 ) { return true; }
		if( test_char >= 8000 && test_char < 8006 ) { return true; }
		if( test_char >= 8016 && test_char < 8024 ) { return true; }
		if( test_char >= 8032 && test_char < 8040 ) { return true; }
		if( test_char >= 8048 && test_char < 8062 ) { return true; }
		if( test_char >= 8064 && test_char < 8072 ) { return true; }
		if( test_char >= 8080 && test_char < 8088 ) { return true; }
		if( test_char >= 8096 && test_char < 8104 ) { return true; }
		if( test_char >= 8112 && test_char < 8117 ) { return true; }
		if( test_char >= 8118 && test_char < 8120 ) { return true; }
		if( test_char == 8126 ) { return true; }
		if( test_char >= 8130 && test_char < 8133 ) { return true; }
		if( test_char >= 8134 && test_char < 8136 ) { return true; }
		if( test_char >= 8144 && test_char < 8148 ) { return true; }
		if( test_char >= 8150 && test_char < 8152 ) { return true; }
		if( test_char >= 8160 && test_char < 8168 ) { return true; }
		if( test_char >= 8178 && test_char < 8181 ) { return true; }
		if( test_char >= 8182 && test_char < 8184 ) { return true; }
		if( test_char == 8305 ) { return true; }
		if( test_char == 8319 ) { return true; }
		if( test_char >= 8336 && test_char < 8349 ) { return true; }
		if( test_char == 8458 ) { return true; }
		if( test_char >= 8462 && test_char < 8464 ) { return true; }
		if( test_char == 8467 ) { return true; }
		if( test_char == 8495 ) { return true; }
		if( test_char == 8500 ) { return true; }
		if( test_char == 8505 ) { return true; }
		if( test_char >= 8508 && test_char < 8510 ) { return true; }
		if( test_char >= 8518 && test_char < 8522 ) { return true; }
		if( test_char == 8526 ) { return true; }
		if( test_char >= 8560 && test_char < 8576 ) { return true; }
		if( test_char == 8580 ) { return true; }
		if( test_char >= 9424 && test_char < 9450 ) { return true; }
		if( test_char >= 11312 && test_char < 11360 ) { return true; }
		if( test_char == 11361 ) { return true; }
		if( test_char >= 11365 && test_char < 11367 ) { return true; }
		if( test_char == 11368 ) { return true; }
		if( test_char == 11370 ) { return true; }
		if( test_char == 11372 ) { return true; }
		if( test_char == 11377 ) { return true; }
		if( test_char >= 11379 && test_char < 11381 ) { return true; }
		if( test_char >= 11382 && test_char < 11390 ) { return true; }
		if( test_char == 11393 ) { return true; }
		if( test_char == 11395 ) { return true; }
		if( test_char == 11397 ) { return true; }
		if( test_char == 11399 ) { return true; }
		if( test_char == 11401 ) { return true; }
		if( test_char == 11403 ) { return true; }
		if( test_char == 11405 ) { return true; }
		if( test_char == 11407 ) { return true; }
		if( test_char == 11409 ) { return true; }
		if( test_char == 11411 ) { return true; }
		if( test_char == 11413 ) { return true; }
		if( test_char == 11415 ) { return true; }
		if( test_char == 11417 ) { return true; }
		if( test_char == 11419 ) { return true; }
		if( test_char == 11421 ) { return true; }
		if( test_char == 11423 ) { return true; }
		if( test_char == 11425 ) { return true; }
		if( test_char == 11427 ) { return true; }
		if( test_char == 11429 ) { return true; }
		if( test_char == 11431 ) { return true; }
		if( test_char == 11433 ) { return true; }
		if( test_char == 11435 ) { return true; }
		if( test_char == 11437 ) { return true; }
		if( test_char == 11439 ) { return true; }
		if( test_char == 11441 ) { return true; }
		if( test_char == 11443 ) { return true; }
		if( test_char == 11445 ) { return true; }
		if( test_char == 11447 ) { return true; }
		if( test_char == 11449 ) { return true; }
		if( test_char == 11451 ) { return true; }
		if( test_char == 11453 ) { return true; }
		if( test_char == 11455 ) { return true; }
		if( test_char == 11457 ) { return true; }
		if( test_char == 11459 ) { return true; }
		if( test_char == 11461 ) { return true; }
		if( test_char == 11463 ) { return true; }
		if( test_char == 11465 ) { return true; }
		if( test_char == 11467 ) { return true; }
		if( test_char == 11469 ) { return true; }
		if( test_char == 11471 ) { return true; }
		if( test_char == 11473 ) { return true; }
		if( test_char == 11475 ) { return true; }
		if( test_char == 11477 ) { return true; }
		if( test_char == 11479 ) { return true; }
		if( test_char == 11481 ) { return true; }
		if( test_char == 11483 ) { return true; }
		if( test_char == 11485 ) { return true; }
		if( test_char == 11487 ) { return true; }
		if( test_char == 11489 ) { return true; }
		if( test_char >= 11491 && test_char < 11493 ) { return true; }
		if( test_char == 11500 ) { return true; }
		if( test_char == 11502 ) { return true; }
		if( test_char == 11507 ) { return true; }
		if( test_char >= 11520 && test_char < 11558 ) { return true; }
		if( test_char == 11559 ) { return true; }
		if( test_char == 11565 ) { return true; }
		if( test_char == 42561 ) { return true; }
		if( test_char == 42563 ) { return true; }
		if( test_char == 42565 ) { return true; }
		if( test_char == 42567 ) { return true; }
		if( test_char == 42569 ) { return true; }
		if( test_char == 42571 ) { return true; }
		if( test_char == 42573 ) { return true; }
		if( test_char == 42575 ) { return true; }
		if( test_char == 42577 ) { return true; }
		if( test_char == 42579 ) { return true; }
		if( test_char == 42581 ) { return true; }
		if( test_char == 42583 ) { return true; }
		if( test_char == 42585 ) { return true; }
		if( test_char == 42587 ) { return true; }
		if( test_char == 42589 ) { return true; }
		if( test_char == 42591 ) { return true; }
		if( test_char == 42593 ) { return true; }
		if( test_char == 42595 ) { return true; }
		if( test_char == 42597 ) { return true; }
		if( test_char == 42599 ) { return true; }
		if( test_char == 42601 ) { return true; }
		if( test_char == 42603 ) { return true; }
		if( test_char == 42605 ) { return true; }
		if( test_char == 42625 ) { return true; }
		if( test_char == 42627 ) { return true; }
		if( test_char == 42629 ) { return true; }
		if( test_char == 42631 ) { return true; }
		if( test_char == 42633 ) { return true; }
		if( test_char == 42635 ) { return true; }
		if( test_char == 42637 ) { return true; }
		if( test_char == 42639 ) { return true; }
		if( test_char == 42641 ) { return true; }
		if( test_char == 42643 ) { return true; }
		if( test_char == 42645 ) { return true; }
		if( test_char == 42647 ) { return true; }
		if( test_char == 42649 ) { return true; }
		if( test_char >= 42651 && test_char < 42654 ) { return true; }
		if( test_char == 42787 ) { return true; }
		if( test_char == 42789 ) { return true; }
		if( test_char == 42791 ) { return true; }
		if( test_char == 42793 ) { return true; }
		if( test_char == 42795 ) { return true; }
		if( test_char == 42797 ) { return true; }
		if( test_char >= 42799 && test_char < 42802 ) { return true; }
		if( test_char == 42803 ) { return true; }
		if( test_char == 42805 ) { return true; }
		if( test_char == 42807 ) { return true; }
		if( test_char == 42809 ) { return true; }
		if( test_char == 42811 ) { return true; }
		if( test_char == 42813 ) { return true; }
		if( test_char == 42815 ) { return true; }
		if( test_char == 42817 ) { return true; }
		if( test_char == 42819 ) { return true; }
		if( test_char == 42821 ) { return true; }
		if( test_char == 42823 ) { return true; }
		if( test_char == 42825 ) { return true; }
		if( test_char == 42827 ) { return true; }
		if( test_char == 42829 ) { return true; }
		if( test_char == 42831 ) { return true; }
		if( test_char == 42833 ) { return true; }
		if( test_char == 42835 ) { return true; }
		if( test_char == 42837 ) { return true; }
		if( test_char == 42839 ) { return true; }
		if( test_char == 42841 ) { return true; }
		if( test_char == 42843 ) { return true; }
		if( test_char == 42845 ) { return true; }
		if( test_char == 42847 ) { return true; }
		if( test_char == 42849 ) { return true; }
		if( test_char == 42851 ) { return true; }
		if( test_char == 42853 ) { return true; }
		if( test_char == 42855 ) { return true; }
		if( test_char == 42857 ) { return true; }
		if( test_char == 42859 ) { return true; }
		if( test_char == 42861 ) { return true; }
		if( test_char >= 42863 && test_char < 42873 ) { return true; }
		if( test_char == 42874 ) { return true; }
		if( test_char == 42876 ) { return true; }
		if( test_char == 42879 ) { return true; }
		if( test_char == 42881 ) { return true; }
		if( test_char == 42883 ) { return true; }
		if( test_char == 42885 ) { return true; }
		if( test_char == 42887 ) { return true; }
		if( test_char == 42892 ) { return true; }
		if( test_char == 42894 ) { return true; }
		if( test_char == 42897 ) { return true; }
		if( test_char >= 42899 && test_char < 42902 ) { return true; }
		if( test_char == 42903 ) { return true; }
		if( test_char == 42905 ) { return true; }
		if( test_char == 42907 ) { return true; }
		if( test_char == 42909 ) { return true; }
		if( test_char == 42911 ) { return true; }
		if( test_char == 42913 ) { return true; }
		if( test_char == 42915 ) { return true; }
		if( test_char == 42917 ) { return true; }
		if( test_char == 42919 ) { return true; }
		if( test_char == 42921 ) { return true; }
		if( test_char == 42927 ) { return true; }
		if( test_char == 42933 ) { return true; }
		if( test_char == 42935 ) { return true; }
		if( test_char == 42937 ) { return true; }
		if( test_char == 42939 ) { return true; }
		if( test_char == 42941 ) { return true; }
		if( test_char == 42943 ) { return true; }
		if( test_char == 42945 ) { return true; }
		if( test_char == 42947 ) { return true; }
		if( test_char == 42952 ) { return true; }
		if( test_char == 42954 ) { return true; }
		if( test_char == 42961 ) { return true; }
		if( test_char == 42963 ) { return true; }
		if( test_char == 42965 ) { return true; }
		if( test_char == 42967 ) { return true; }
		if( test_char == 42969 ) { return true; }
		if( test_char >= 42994 && test_char < 42997 ) { return true; }
		if( test_char == 42998 ) { return true; }
		if( test_char >= 43000 && test_char < 43003 ) { return true; }
		if( test_char >= 43824 && test_char < 43867 ) { return true; }
		if( test_char >= 43868 && test_char < 43882 ) { return true; }
		if( test_char >= 43888 && test_char < 43968 ) { return true; }
		if( test_char >= 64256 && test_char < 64263 ) { return true; }
		if( test_char >= 64275 && test_char < 64280 ) { return true; }
		if( test_char >= 65345 && test_char < 65371 ) { return true; }
		if( test_char >= 66600 && test_char < 66640 ) { return true; }
		if( test_char >= 66776 && test_char < 66812 ) { return true; }
		if( test_char >= 66967 && test_char < 66978 ) { return true; }
		if( test_char >= 66979 && test_char < 66994 ) { return true; }
		if( test_char >= 66995 && test_char < 67002 ) { return true; }
		if( test_char >= 67003 && test_char < 67005 ) { return true; }
		if( test_char == 67456 ) { return true; }
		if( test_char >= 67459 && test_char < 67462 ) { return true; }
		if( test_char >= 67463 && test_char < 67505 ) { return true; }
		if( test_char >= 67506 && test_char < 67515 ) { return true; }
		if( test_char >= 68800 && test_char < 68851 ) { return true; }
		if( test_char >= 71872 && test_char < 71904 ) { return true; }
		if( test_char >= 93792 && test_char < 93824 ) { return true; }
		if( test_char >= 119834 && test_char < 119860 ) { return true; }
		if( test_char >= 119886 && test_char < 119893 ) { return true; }
		if( test_char >= 119894 && test_char < 119912 ) { return true; }
		if( test_char >= 119938 && test_char < 119964 ) { return true; }
		if( test_char >= 119990 && test_char < 119994 ) { return true; }
		if( test_char == 119995 ) { return true; }
		if( test_char >= 119997 && test_char < 120004 ) { return true; }
		if( test_char >= 120005 && test_char < 120016 ) { return true; }
		if( test_char >= 120042 && test_char < 120068 ) { return true; }
		if( test_char >= 120094 && test_char < 120120 ) { return true; }
		if( test_char >= 120146 && test_char < 120172 ) { return true; }
		if( test_char >= 120198 && test_char < 120224 ) { return true; }
		if( test_char >= 120250 && test_char < 120276 ) { return true; }
		if( test_char >= 120302 && test_char < 120328 ) { return true; }
		if( test_char >= 120354 && test_char < 120380 ) { return true; }
		if( test_char >= 120406 && test_char < 120432 ) { return true; }
		if( test_char >= 120458 && test_char < 120486 ) { return true; }
		if( test_char >= 120514 && test_char < 120539 ) { return true; }
		if( test_char >= 120540 && test_char < 120546 ) { return true; }
		if( test_char >= 120572 && test_char < 120597 ) { return true; }
		if( test_char >= 120598 && test_char < 120604 ) { return true; }
		if( test_char >= 120630 && test_char < 120655 ) { return true; }
		if( test_char >= 120656 && test_char < 120662 ) { return true; }
		if( test_char >= 120688 && test_char < 120713 ) { return true; }
		if( test_char >= 120714 && test_char < 120720 ) { return true; }
		if( test_char >= 120746 && test_char < 120771 ) { return true; }
		if( test_char >= 120772 && test_char < 120778 ) { return true; }
		if( test_char == 120779 ) { return true; }
		if( test_char >= 122624 && test_char < 122634 ) { return true; }
		if( test_char >= 122635 && test_char < 122655 ) { return true; }
		if( test_char >= 122661 && test_char < 122667 ) { return true; }
		if( test_char >= 122928 && test_char < 122990 ) { return true; }
		if( test_char >= 125218 && test_char < 125252 ) { return true; }

		return false;
	}
	
	bool is_numeric(char32_t test_char) noexcept {
		if( test_char >= 48 && test_char < 58 ) { return true; }
		if( test_char >= 178 && test_char < 180 ) { return true; }
		if( test_char == 185 ) { return true; }
		if( test_char >= 188 && test_char < 191 ) { return true; }
		if( test_char >= 1632 && test_char < 1642 ) { return true; }
		if( test_char >= 1776 && test_char < 1786 ) { return true; }
		if( test_char >= 1984 && test_char < 1994 ) { return true; }
		if( test_char >= 2406 && test_char < 2416 ) { return true; }
		if( test_char >= 2534 && test_char < 2544 ) { return true; }
		if( test_char >= 2548 && test_char < 2554 ) { return true; }
		if( test_char >= 2662 && test_char < 2672 ) { return true; }
		if( test_char >= 2790 && test_char < 2800 ) { return true; }
		if( test_char >= 2918 && test_char < 2928 ) { return true; }
		if( test_char >= 2930 && test_char < 2936 ) { return true; }
		if( test_char >= 3046 && test_char < 3059 ) { return true; }
		if( test_char >= 3174 && test_char < 3184 ) { return true; }
		if( test_char >= 3192 && test_char < 3199 ) { return true; }
		if( test_char >= 3302 && test_char < 3312 ) { return true; }
		if( test_char >= 3416 && test_char < 3423 ) { return true; }
		if( test_char >= 3430 && test_char < 3449 ) { return true; }
		if( test_char >= 3558 && test_char < 3568 ) { return true; }
		if( test_char >= 3664 && test_char < 3674 ) { return true; }
		if( test_char >= 3792 && test_char < 3802 ) { return true; }
		if( test_char >= 3872 && test_char < 3892 ) { return true; }
		if( test_char >= 4160 && test_char < 4170 ) { return true; }
		if( test_char >= 4240 && test_char < 4250 ) { return true; }
		if( test_char >= 4969 && test_char < 4989 ) { return true; }
		if( test_char >= 5870 && test_char < 5873 ) { return true; }
		if( test_char >= 6112 && test_char < 6122 ) { return true; }
		if( test_char >= 6128 && test_char < 6138 ) { return true; }
		if( test_char >= 6160 && test_char < 6170 ) { return true; }
		if( test_char >= 6470 && test_char < 6480 ) { return true; }
		if( test_char >= 6608 && test_char < 6619 ) { return true; }
		if( test_char >= 6784 && test_char < 6794 ) { return true; }
		if( test_char >= 6800 && test_char < 6810 ) { return true; }
		if( test_char >= 6992 && test_char < 7002 ) { return true; }
		if( test_char >= 7088 && test_char < 7098 ) { return true; }
		if( test_char >= 7232 && test_char < 7242 ) { return true; }
		if( test_char >= 7248 && test_char < 7258 ) { return true; }
		if( test_char == 8304 ) { return true; }
		if( test_char >= 8308 && test_char < 8314 ) { return true; }
		if( test_char >= 8320 && test_char < 8330 ) { return true; }
		if( test_char >= 8528 && test_char < 8579 ) { return true; }
		if( test_char >= 8581 && test_char < 8586 ) { return true; }
		if( test_char >= 9312 && test_char < 9372 ) { return true; }
		if( test_char >= 9450 && test_char < 9472 ) { return true; }
		if( test_char >= 10102 && test_char < 10132 ) { return true; }
		if( test_char == 11517 ) { return true; }
		if( test_char == 12295 ) { return true; }
		if( test_char >= 12321 && test_char < 12330 ) { return true; }
		if( test_char >= 12344 && test_char < 12347 ) { return true; }
		if( test_char >= 12690 && test_char < 12694 ) { return true; }
		if( test_char >= 12832 && test_char < 12842 ) { return true; }
		if( test_char >= 12872 && test_char < 12880 ) { return true; }
		if( test_char >= 12881 && test_char < 12896 ) { return true; }
		if( test_char >= 12928 && test_char < 12938 ) { return true; }
		if( test_char >= 12977 && test_char < 12992 ) { return true; }
		if( test_char == 13317 ) { return true; }
		if( test_char == 13443 ) { return true; }
		if( test_char == 14378 ) { return true; }
		if( test_char == 15181 ) { return true; }
		if( test_char == 19968 ) { return true; }
		if( test_char == 19971 ) { return true; }
		if( test_char == 19975 ) { return true; }
		if( test_char == 19977 ) { return true; }
		if( test_char == 20004 ) { return true; }
		if( test_char == 20061 ) { return true; }
		if( test_char == 20108 ) { return true; }
		if( test_char == 20116 ) { return true; }
		if( test_char == 20118 ) { return true; }
		if( test_char == 20140 ) { return true; }
		if( test_char >= 20159 && test_char < 20161 ) { return true; }
		if( test_char == 20191 ) { return true; }
		if( test_char == 20200 ) { return true; }
		if( test_char == 20237 ) { return true; }
		if( test_char == 20336 ) { return true; }
		if( test_char == 20457 ) { return true; }
		if( test_char == 20486 ) { return true; }
		if( test_char == 20740 ) { return true; }
		if( test_char == 20806 ) { return true; }
		if( test_char == 20841 ) { return true; }
		if( test_char == 20843 ) { return true; }
		if( test_char == 20845 ) { return true; }
		if( test_char == 21313 ) { return true; }
		if( test_char >= 21315 && test_char < 21318 ) { return true; }
		if( test_char == 21324 ) { return true; }
		if( test_char >= 21441 && test_char < 21445 ) { return true; }
		if( test_char == 22235 ) { return true; }
		if( test_char == 22769 ) { return true; }
		if( test_char == 22777 ) { return true; }
		if( test_char == 24186 ) { return true; }
		if( test_char >= 24318 && test_char < 24320 ) { return true; }
		if( test_char >= 24332 && test_char < 24335 ) { return true; }
		if( test_char == 24336 ) { return true; }
		if( test_char == 25296 ) { return true; }
		if( test_char == 25342 ) { return true; }
		if( test_char == 25420 ) { return true; }
		if( test_char == 26578 ) { return true; }
		if( test_char == 27934 ) { return true; }
		if( test_char == 28422 ) { return true; }
		if( test_char == 29590 ) { return true; }
		if( test_char == 30334 ) { return true; }
		if( test_char == 30357 ) { return true; }
		if( test_char == 31213 ) { return true; }
		if( test_char == 32902 ) { return true; }
		if( test_char == 33836 ) { return true; }
		if( test_char == 36014 ) { return true; }
		if( test_char == 36019 ) { return true; }
		if( test_char == 36144 ) { return true; }
		if( test_char == 37390 ) { return true; }
		if( test_char == 38057 ) { return true; }
		if( test_char == 38433 ) { return true; }
		if( test_char == 38470 ) { return true; }
		if( test_char == 38476 ) { return true; }
		if( test_char == 38520 ) { return true; }
		if( test_char == 38646 ) { return true; }
		if( test_char >= 42528 && test_char < 42538 ) { return true; }
		if( test_char >= 42726 && test_char < 42736 ) { return true; }
		if( test_char >= 43056 && test_char < 43062 ) { return true; }
		if( test_char >= 43216 && test_char < 43226 ) { return true; }
		if( test_char >= 43264 && test_char < 43274 ) { return true; }
		if( test_char >= 43472 && test_char < 43482 ) { return true; }
		if( test_char >= 43504 && test_char < 43514 ) { return true; }
		if( test_char >= 43600 && test_char < 43610 ) { return true; }
		if( test_char >= 44016 && test_char < 44026 ) { return true; }
		if( test_char == 63851 ) { return true; }
		if( test_char == 63859 ) { return true; }
		if( test_char == 63864 ) { return true; }
		if( test_char == 63922 ) { return true; }
		if( test_char == 63953 ) { return true; }
		if( test_char == 63955 ) { return true; }
		if( test_char == 63997 ) { return true; }
		if( test_char >= 65296 && test_char < 65306 ) { return true; }
		if( test_char >= 65799 && test_char < 65844 ) { return true; }
		if( test_char >= 65856 && test_char < 65913 ) { return true; }
		if( test_char >= 65930 && test_char < 65932 ) { return true; }
		if( test_char >= 66273 && test_char < 66300 ) { return true; }
		if( test_char >= 66336 && test_char < 66340 ) { return true; }
		if( test_char == 66369 ) { return true; }
		if( test_char == 66378 ) { return true; }
		if( test_char >= 66513 && test_char < 66518 ) { return true; }
		if( test_char >= 66720 && test_char < 66730 ) { return true; }
		if( test_char >= 67672 && test_char < 67680 ) { return true; }
		if( test_char >= 67705 && test_char < 67712 ) { return true; }
		if( test_char >= 67751 && test_char < 67760 ) { return true; }
		if( test_char >= 67835 && test_char < 67840 ) { return true; }
		if( test_char >= 67862 && test_char < 67868 ) { return true; }
		if( test_char >= 68028 && test_char < 68030 ) { return true; }
		if( test_char >= 68032 && test_char < 68048 ) { return true; }
		if( test_char >= 68050 && test_char < 68096 ) { return true; }
		if( test_char >= 68160 && test_char < 68169 ) { return true; }
		if( test_char >= 68221 && test_char < 68223 ) { return true; }
		if( test_char >= 68253 && test_char < 68256 ) { return true; }
		if( test_char >= 68331 && test_char < 68336 ) { return true; }
		if( test_char >= 68440 && test_char < 68448 ) { return true; }
		if( test_char >= 68472 && test_char < 68480 ) { return true; }
		if( test_char >= 68521 && test_char < 68528 ) { return true; }
		if( test_char >= 68858 && test_char < 68864 ) { return true; }
		if( test_char >= 68912 && test_char < 68922 ) { return true; }
		if( test_char >= 69216 && test_char < 69247 ) { return true; }
		if( test_char >= 69405 && test_char < 69415 ) { return true; }
		if( test_char >= 69457 && test_char < 69461 ) { return true; }
		if( test_char >= 69573 && test_char < 69580 ) { return true; }
		if( test_char >= 69714 && test_char < 69744 ) { return true; }
		if( test_char >= 69872 && test_char < 69882 ) { return true; }
		if( test_char >= 69942 && test_char < 69952 ) { return true; }
		if( test_char >= 70096 && test_char < 70106 ) { return true; }
		if( test_char >= 70113 && test_char < 70133 ) { return true; }
		if( test_char >= 70384 && test_char < 70394 ) { return true; }
		if( test_char >= 70736 && test_char < 70746 ) { return true; }
		if( test_char >= 70864 && test_char < 70874 ) { return true; }
		if( test_char >= 71248 && test_char < 71258 ) { return true; }
		if( test_char >= 71360 && test_char < 71370 ) { return true; }
		if( test_char >= 71472 && test_char < 71484 ) { return true; }
		if( test_char >= 71904 && test_char < 71923 ) { return true; }
		if( test_char >= 72016 && test_char < 72026 ) { return true; }
		if( test_char >= 72784 && test_char < 72813 ) { return true; }
		if( test_char >= 73040 && test_char < 73050 ) { return true; }
		if( test_char >= 73120 && test_char < 73130 ) { return true; }
		if( test_char >= 73552 && test_char < 73562 ) { return true; }
		if( test_char >= 73664 && test_char < 73685 ) { return true; }
		if( test_char >= 74752 && test_char < 74863 ) { return true; }
		if( test_char >= 92768 && test_char < 92778 ) { return true; }
		if( test_char >= 92864 && test_char < 92874 ) { return true; }
		if( test_char >= 93008 && test_char < 93018 ) { return true; }
		if( test_char >= 93019 && test_char < 93026 ) { return true; }
		if( test_char >= 93824 && test_char < 93847 ) { return true; }
		if( test_char >= 119488 && test_char < 119508 ) { return true; }
		if( test_char >= 119520 && test_char < 119540 ) { return true; }
		if( test_char >= 119648 && test_char < 119673 ) { return true; }
		if( test_char >= 120782 && test_char < 120832 ) { return true; }
		if( test_char >= 123200 && test_char < 123210 ) { return true; }
		if( test_char >= 123632 && test_char < 123642 ) { return true; }
		if( test_char >= 124144 && test_char < 124154 ) { return true; }
		if( test_char >= 125127 && test_char < 125136 ) { return true; }
		if( test_char >= 125264 && test_char < 125274 ) { return true; }
		if( test_char >= 126065 && test_char < 126124 ) { return true; }
		if( test_char >= 126125 && test_char < 126128 ) { return true; }
		if( test_char >= 126129 && test_char < 126133 ) { return true; }
		if( test_char >= 126209 && test_char < 126254 ) { return true; }
		if( test_char >= 126255 && test_char < 126270 ) { return true; }
		if( test_char >= 127232 && test_char < 127245 ) { return true; }
		if( test_char >= 130032 && test_char < 130042 ) { return true; }
		if( test_char == 131073 ) { return true; }
		if( test_char == 131172 ) { return true; }
		if( test_char == 131298 ) { return true; }
		if( test_char == 131361 ) { return true; }
		if( test_char == 133418 ) { return true; }
		if( test_char == 133507 ) { return true; }
		if( test_char == 133516 ) { return true; }
		if( test_char == 133532 ) { return true; }
		if( test_char == 133866 ) { return true; }
		if( test_char == 133885 ) { return true; }
		if( test_char == 133913 ) { return true; }
		if( test_char == 140176 ) { return true; }
		if( test_char == 141720 ) { return true; }
		if( test_char == 146203 ) { return true; }
		if( test_char == 156269 ) { return true; }
		if( test_char == 194704 ) { return true; }

		return false;
	}
	
	bool is_print(char32_t test_char) noexcept {
		if( test_char >= 32 && test_char < 127 ) { return true; }
		if( test_char >= 161 && test_char < 173 ) { return true; }
		if( test_char >= 174 && test_char < 888 ) { return true; }
		if( test_char >= 890 && test_char < 896 ) { return true; }
		if( test_char >= 900 && test_char < 907 ) { return true; }
		if( test_char == 908 ) { return true; }
		if( test_char >= 910 && test_char < 930 ) { return true; }
		if( test_char >= 931 && test_char < 1328 ) { return true; }
		if( test_char >= 1329 && test_char < 1367 ) { return true; }
		if( test_char >= 1369 && test_char < 1419 ) { return true; }
		if( test_char >= 1421 && test_char < 1424 ) { return true; }
		if( test_char >= 1425 && test_char < 1480 ) { return true; }
		if( test_char >= 1488 && test_char < 1515 ) { return true; }
		if( test_char >= 1519 && test_char < 1525 ) { return true; }
		if( test_char >= 1542 && test_char < 1564 ) { return true; }
		if( test_char >= 1565 && test_char < 1757 ) { return true; }
		if( test_char >= 1758 && test_char < 1806 ) { return true; }
		if( test_char >= 1808 && test_char < 1867 ) { return true; }
		if( test_char >= 1869 && test_char < 1970 ) { return true; }
		if( test_char >= 1984 && test_char < 2043 ) { return true; }
		if( test_char >= 2045 && test_char < 2094 ) { return true; }
		if( test_char >= 2096 && test_char < 2111 ) { return true; }
		if( test_char >= 2112 && test_char < 2140 ) { return true; }
		if( test_char == 2142 ) { return true; }
		if( test_char >= 2144 && test_char < 2155 ) { return true; }
		if( test_char >= 2160 && test_char < 2191 ) { return true; }
		if( test_char >= 2200 && test_char < 2274 ) { return true; }
		if( test_char >= 2275 && test_char < 2436 ) { return true; }
		if( test_char >= 2437 && test_char < 2445 ) { return true; }
		if( test_char >= 2447 && test_char < 2449 ) { return true; }
		if( test_char >= 2451 && test_char < 2473 ) { return true; }
		if( test_char >= 2474 && test_char < 2481 ) { return true; }
		if( test_char == 2482 ) { return true; }
		if( test_char >= 2486 && test_char < 2490 ) { return true; }
		if( test_char >= 2492 && test_char < 2501 ) { return true; }
		if( test_char >= 2503 && test_char < 2505 ) { return true; }
		if( test_char >= 2507 && test_char < 2511 ) { return true; }
		if( test_char == 2519 ) { return true; }
		if( test_char >= 2524 && test_char < 2526 ) { return true; }
		if( test_char >= 2527 && test_char < 2532 ) { return true; }
		if( test_char >= 2534 && test_char < 2559 ) { return true; }
		if( test_char >= 2561 && test_char < 2564 ) { return true; }
		if( test_char >= 2565 && test_char < 2571 ) { return true; }
		if( test_char >= 2575 && test_char < 2577 ) { return true; }
		if( test_char >= 2579 && test_char < 2601 ) { return true; }
		if( test_char >= 2602 && test_char < 2609 ) { return true; }
		if( test_char >= 2610 && test_char < 2612 ) { return true; }
		if( test_char >= 2613 && test_char < 2615 ) { return true; }
		if( test_char >= 2616 && test_char < 2618 ) { return true; }
		if( test_char == 2620 ) { return true; }
		if( test_char >= 2622 && test_char < 2627 ) { return true; }
		if( test_char >= 2631 && test_char < 2633 ) { return true; }
		if( test_char >= 2635 && test_char < 2638 ) { return true; }
		if( test_char == 2641 ) { return true; }
		if( test_char >= 2649 && test_char < 2653 ) { return true; }
		if( test_char == 2654 ) { return true; }
		if( test_char >= 2662 && test_char < 2679 ) { return true; }
		if( test_char >= 2689 && test_char < 2692 ) { return true; }
		if( test_char >= 2693 && test_char < 2702 ) { return true; }
		if( test_char >= 2703 && test_char < 2706 ) { return true; }
		if( test_char >= 2707 && test_char < 2729 ) { return true; }
		if( test_char >= 2730 && test_char < 2737 ) { return true; }
		if( test_char >= 2738 && test_char < 2740 ) { return true; }
		if( test_char >= 2741 && test_char < 2746 ) { return true; }
		if( test_char >= 2748 && test_char < 2758 ) { return true; }
		if( test_char >= 2759 && test_char < 2762 ) { return true; }
		if( test_char >= 2763 && test_char < 2766 ) { return true; }
		if( test_char == 2768 ) { return true; }
		if( test_char >= 2784 && test_char < 2788 ) { return true; }
		if( test_char >= 2790 && test_char < 2802 ) { return true; }
		if( test_char >= 2809 && test_char < 2816 ) { return true; }
		if( test_char >= 2817 && test_char < 2820 ) { return true; }
		if( test_char >= 2821 && test_char < 2829 ) { return true; }
		if( test_char >= 2831 && test_char < 2833 ) { return true; }
		if( test_char >= 2835 && test_char < 2857 ) { return true; }
		if( test_char >= 2858 && test_char < 2865 ) { return true; }
		if( test_char >= 2866 && test_char < 2868 ) { return true; }
		if( test_char >= 2869 && test_char < 2874 ) { return true; }
		if( test_char >= 2876 && test_char < 2885 ) { return true; }
		if( test_char >= 2887 && test_char < 2889 ) { return true; }
		if( test_char >= 2891 && test_char < 2894 ) { return true; }
		if( test_char >= 2901 && test_char < 2904 ) { return true; }
		if( test_char >= 2908 && test_char < 2910 ) { return true; }
		if( test_char >= 2911 && test_char < 2916 ) { return true; }
		if( test_char >= 2918 && test_char < 2936 ) { return true; }
		if( test_char >= 2946 && test_char < 2948 ) { return true; }
		if( test_char >= 2949 && test_char < 2955 ) { return true; }
		if( test_char >= 2958 && test_char < 2961 ) { return true; }
		if( test_char >= 2962 && test_char < 2966 ) { return true; }
		if( test_char >= 2969 && test_char < 2971 ) { return true; }
		if( test_char == 2972 ) { return true; }
		if( test_char >= 2974 && test_char < 2976 ) { return true; }
		if( test_char >= 2979 && test_char < 2981 ) { return true; }
		if( test_char >= 2984 && test_char < 2987 ) { return true; }
		if( test_char >= 2990 && test_char < 3002 ) { return true; }
		if( test_char >= 3006 && test_char < 3011 ) { return true; }
		if( test_char >= 3014 && test_char < 3017 ) { return true; }
		if( test_char >= 3018 && test_char < 3022 ) { return true; }
		if( test_char == 3024 ) { return true; }
		if( test_char == 3031 ) { return true; }
		if( test_char >= 3046 && test_char < 3067 ) { return true; }
		if( test_char >= 3072 && test_char < 3085 ) { return true; }
		if( test_char >= 3086 && test_char < 3089 ) { return true; }
		if( test_char >= 3090 && test_char < 3113 ) { return true; }
		if( test_char >= 3114 && test_char < 3130 ) { return true; }
		if( test_char >= 3132 && test_char < 3141 ) { return true; }
		if( test_char >= 3142 && test_char < 3145 ) { return true; }
		if( test_char >= 3146 && test_char < 3150 ) { return true; }
		if( test_char >= 3157 && test_char < 3159 ) { return true; }
		if( test_char >= 3160 && test_char < 3163 ) { return true; }
		if( test_char == 3165 ) { return true; }
		if( test_char >= 3168 && test_char < 3172 ) { return true; }
		if( test_char >= 3174 && test_char < 3184 ) { return true; }
		if( test_char >= 3191 && test_char < 3213 ) { return true; }
		if( test_char >= 3214 && test_char < 3217 ) { return true; }
		if( test_char >= 3218 && test_char < 3241 ) { return true; }
		if( test_char >= 3242 && test_char < 3252 ) { return true; }
		if( test_char >= 3253 && test_char < 3258 ) { return true; }
		if( test_char >= 3260 && test_char < 3269 ) { return true; }
		if( test_char >= 3270 && test_char < 3273 ) { return true; }
		if( test_char >= 3274 && test_char < 3278 ) { return true; }
		if( test_char >= 3285 && test_char < 3287 ) { return true; }
		if( test_char >= 3293 && test_char < 3295 ) { return true; }
		if( test_char >= 3296 && test_char < 3300 ) { return true; }
		if( test_char >= 3302 && test_char < 3312 ) { return true; }
		if( test_char >= 3313 && test_char < 3316 ) { return true; }
		if( test_char >= 3328 && test_char < 3341 ) { return true; }
		if( test_char >= 3342 && test_char < 3345 ) { return true; }
		if( test_char >= 3346 && test_char < 3397 ) { return true; }
		if( test_char >= 3398 && test_char < 3401 ) { return true; }
		if( test_char >= 3402 && test_char < 3408 ) { return true; }
		if( test_char >= 3412 && test_char < 3428 ) { return true; }
		if( test_char >= 3430 && test_char < 3456 ) { return true; }
		if( test_char >= 3457 && test_char < 3460 ) { return true; }
		if( test_char >= 3461 && test_char < 3479 ) { return true; }
		if( test_char >= 3482 && test_char < 3506 ) { return true; }
		if( test_char >= 3507 && test_char < 3516 ) { return true; }
		if( test_char == 3517 ) { return true; }
		if( test_char >= 3520 && test_char < 3527 ) { return true; }
		if( test_char == 3530 ) { return true; }
		if( test_char >= 3535 && test_char < 3541 ) { return true; }
		if( test_char == 3542 ) { return true; }
		if( test_char >= 3544 && test_char < 3552 ) { return true; }
		if( test_char >= 3558 && test_char < 3568 ) { return true; }
		if( test_char >= 3570 && test_char < 3573 ) { return true; }
		if( test_char >= 3585 && test_char < 3643 ) { return true; }
		if( test_char >= 3647 && test_char < 3676 ) { return true; }
		if( test_char >= 3713 && test_char < 3715 ) { return true; }
		if( test_char == 3716 ) { return true; }
		if( test_char >= 3718 && test_char < 3723 ) { return true; }
		if( test_char >= 3724 && test_char < 3748 ) { return true; }
		if( test_char == 3749 ) { return true; }
		if( test_char >= 3751 && test_char < 3774 ) { return true; }
		if( test_char >= 3776 && test_char < 3781 ) { return true; }
		if( test_char == 3782 ) { return true; }
		if( test_char >= 3784 && test_char < 3791 ) { return true; }
		if( test_char >= 3792 && test_char < 3802 ) { return true; }
		if( test_char >= 3804 && test_char < 3808 ) { return true; }
		if( test_char >= 3840 && test_char < 3912 ) { return true; }
		if( test_char >= 3913 && test_char < 3949 ) { return true; }
		if( test_char >= 3953 && test_char < 3992 ) { return true; }
		if( test_char >= 3993 && test_char < 4029 ) { return true; }
		if( test_char >= 4030 && test_char < 4045 ) { return true; }
		if( test_char >= 4046 && test_char < 4059 ) { return true; }
		if( test_char >= 4096 && test_char < 4294 ) { return true; }
		if( test_char == 4295 ) { return true; }
		if( test_char == 4301 ) { return true; }
		if( test_char >= 4304 && test_char < 4681 ) { return true; }
		if( test_char >= 4682 && test_char < 4686 ) { return true; }
		if( test_char >= 4688 && test_char < 4695 ) { return true; }
		if( test_char == 4696 ) { return true; }
		if( test_char >= 4698 && test_char < 4702 ) { return true; }
		if( test_char >= 4704 && test_char < 4745 ) { return true; }
		if( test_char >= 4746 && test_char < 4750 ) { return true; }
		if( test_char >= 4752 && test_char < 4785 ) { return true; }
		if( test_char >= 4786 && test_char < 4790 ) { return true; }
		if( test_char >= 4792 && test_char < 4799 ) { return true; }
		if( test_char == 4800 ) { return true; }
		if( test_char >= 4802 && test_char < 4806 ) { return true; }
		if( test_char >= 4808 && test_char < 4823 ) { return true; }
		if( test_char >= 4824 && test_char < 4881 ) { return true; }
		if( test_char >= 4882 && test_char < 4886 ) { return true; }
		if( test_char >= 4888 && test_char < 4955 ) { return true; }
		if( test_char >= 4957 && test_char < 4989 ) { return true; }
		if( test_char >= 4992 && test_char < 5018 ) { return true; }
		if( test_char >= 5024 && test_char < 5110 ) { return true; }
		if( test_char >= 5112 && test_char < 5118 ) { return true; }
		if( test_char >= 5120 && test_char < 5760 ) { return true; }
		if( test_char >= 5761 && test_char < 5789 ) { return true; }
		if( test_char >= 5792 && test_char < 5881 ) { return true; }
		if( test_char >= 5888 && test_char < 5910 ) { return true; }
		if( test_char >= 5919 && test_char < 5943 ) { return true; }
		if( test_char >= 5952 && test_char < 5972 ) { return true; }
		if( test_char >= 5984 && test_char < 5997 ) { return true; }
		if( test_char >= 5998 && test_char < 6001 ) { return true; }
		if( test_char >= 6002 && test_char < 6004 ) { return true; }
		if( test_char >= 6016 && test_char < 6110 ) { return true; }
		if( test_char >= 6112 && test_char < 6122 ) { return true; }
		if( test_char >= 6128 && test_char < 6138 ) { return true; }
		if( test_char >= 6144 && test_char < 6158 ) { return true; }
		if( test_char >= 6159 && test_char < 6170 ) { return true; }
		if( test_char >= 6176 && test_char < 6265 ) { return true; }
		if( test_char >= 6272 && test_char < 6315 ) { return true; }
		if( test_char >= 6320 && test_char < 6390 ) { return true; }
		if( test_char >= 6400 && test_char < 6431 ) { return true; }
		if( test_char >= 6432 && test_char < 6444 ) { return true; }
		if( test_char >= 6448 && test_char < 6460 ) { return true; }
		if( test_char == 6464 ) { return true; }
		if( test_char >= 6468 && test_char < 6510 ) { return true; }
		if( test_char >= 6512 && test_char < 6517 ) { return true; }
		if( test_char >= 6528 && test_char < 6572 ) { return true; }
		if( test_char >= 6576 && test_char < 6602 ) { return true; }
		if( test_char >= 6608 && test_char < 6619 ) { return true; }
		if( test_char >= 6622 && test_char < 6684 ) { return true; }
		if( test_char >= 6686 && test_char < 6751 ) { return true; }
		if( test_char >= 6752 && test_char < 6781 ) { return true; }
		if( test_char >= 6783 && test_char < 6794 ) { return true; }
		if( test_char >= 6800 && test_char < 6810 ) { return true; }
		if( test_char >= 6816 && test_char < 6830 ) { return true; }
		if( test_char >= 6832 && test_char < 6863 ) { return true; }
		if( test_char >= 6912 && test_char < 6989 ) { return true; }
		if( test_char >= 6992 && test_char < 7039 ) { return true; }
		if( test_char >= 7040 && test_char < 7156 ) { return true; }
		if( test_char >= 7164 && test_char < 7224 ) { return true; }
		if( test_char >= 7227 && test_char < 7242 ) { return true; }
		if( test_char >= 7245 && test_char < 7305 ) { return true; }
		if( test_char >= 7312 && test_char < 7355 ) { return true; }
		if( test_char >= 7357 && test_char < 7368 ) { return true; }
		if( test_char >= 7376 && test_char < 7419 ) { return true; }
		if( test_char >= 7424 && test_char < 7958 ) { return true; }
		if( test_char >= 7960 && test_char < 7966 ) { return true; }
		if( test_char >= 7968 && test_char < 8006 ) { return true; }
		if( test_char >= 8008 && test_char < 8014 ) { return true; }
		if( test_char >= 8016 && test_char < 8024 ) { return true; }
		if( test_char == 8025 ) { return true; }
		if( test_char == 8027 ) { return true; }
		if( test_char == 8029 ) { return true; }
		if( test_char >= 8031 && test_char < 8062 ) { return true; }
		if( test_char >= 8064 && test_char < 8117 ) { return true; }
		if( test_char >= 8118 && test_char < 8133 ) { return true; }
		if( test_char >= 8134 && test_char < 8148 ) { return true; }
		if( test_char >= 8150 && test_char < 8156 ) { return true; }
		if( test_char >= 8157 && test_char < 8176 ) { return true; }
		if( test_char >= 8178 && test_char < 8181 ) { return true; }
		if( test_char >= 8182 && test_char < 8191 ) { return true; }
		if( test_char >= 8208 && test_char < 8232 ) { return true; }
		if( test_char >= 8240 && test_char < 8287 ) { return true; }
		if( test_char >= 8304 && test_char < 8306 ) { return true; }
		if( test_char >= 8308 && test_char < 8335 ) { return true; }
		if( test_char >= 8336 && test_char < 8349 ) { return true; }
		if( test_char >= 8352 && test_char < 8385 ) { return true; }
		if( test_char >= 8400 && test_char < 8433 ) { return true; }
		if( test_char >= 8448 && test_char < 8588 ) { return true; }
		if( test_char >= 8592 && test_char < 9255 ) { return true; }
		if( test_char >= 9280 && test_char < 9291 ) { return true; }
		if( test_char >= 9312 && test_char < 11124 ) { return true; }
		if( test_char >= 11126 && test_char < 11158 ) { return true; }
		if( test_char >= 11159 && test_char < 11508 ) { return true; }
		if( test_char >= 11513 && test_char < 11558 ) { return true; }
		if( test_char == 11559 ) { return true; }
		if( test_char == 11565 ) { return true; }
		if( test_char >= 11568 && test_char < 11624 ) { return true; }
		if( test_char >= 11631 && test_char < 11633 ) { return true; }
		if( test_char >= 11647 && test_char < 11671 ) { return true; }
		if( test_char >= 11680 && test_char < 11687 ) { return true; }
		if( test_char >= 11688 && test_char < 11695 ) { return true; }
		if( test_char >= 11696 && test_char < 11703 ) { return true; }
		if( test_char >= 11704 && test_char < 11711 ) { return true; }
		if( test_char >= 11712 && test_char < 11719 ) { return true; }
		if( test_char >= 11720 && test_char < 11727 ) { return true; }
		if( test_char >= 11728 && test_char < 11735 ) { return true; }
		if( test_char >= 11736 && test_char < 11743 ) { return true; }
		if( test_char >= 11744 && test_char < 11870 ) { return true; }
		if( test_char >= 11904 && test_char < 11930 ) { return true; }
		if( test_char >= 11931 && test_char < 12020 ) { return true; }
		if( test_char >= 12032 && test_char < 12246 ) { return true; }
		if( test_char >= 12272 && test_char < 12288 ) { return true; }
		if( test_char >= 12289 && test_char < 12352 ) { return true; }
		if( test_char >= 12353 && test_char < 12439 ) { return true; }
		if( test_char >= 12441 && test_char < 12544 ) { return true; }
		if( test_char >= 12549 && test_char < 12592 ) { return true; }
		if( test_char >= 12593 && test_char < 12687 ) { return true; }
		if( test_char >= 12688 && test_char < 12772 ) { return true; }
		if( test_char >= 12783 && test_char < 12831 ) { return true; }
		if( test_char >= 12832 && test_char < 42125 ) { return true; }
		if( test_char >= 42128 && test_char < 42183 ) { return true; }
		if( test_char >= 42192 && test_char < 42540 ) { return true; }
		if( test_char >= 42560 && test_char < 42744 ) { return true; }
		if( test_char >= 42752 && test_char < 42955 ) { return true; }
		if( test_char >= 42960 && test_char < 42962 ) { return true; }
		if( test_char == 42963 ) { return true; }
		if( test_char >= 42965 && test_char < 42970 ) { return true; }
		if( test_char >= 42994 && test_char < 43053 ) { return true; }
		if( test_char >= 43056 && test_char < 43066 ) { return true; }
		if( test_char >= 43072 && test_char < 43128 ) { return true; }
		if( test_char >= 43136 && test_char < 43206 ) { return true; }
		if( test_char >= 43214 && test_char < 43226 ) { return true; }
		if( test_char >= 43232 && test_char < 43348 ) { return true; }
		if( test_char >= 43359 && test_char < 43389 ) { return true; }
		if( test_char >= 43392 && test_char < 43470 ) { return true; }
		if( test_char >= 43471 && test_char < 43482 ) { return true; }
		if( test_char >= 43486 && test_char < 43519 ) { return true; }
		if( test_char >= 43520 && test_char < 43575 ) { return true; }
		if( test_char >= 43584 && test_char < 43598 ) { return true; }
		if( test_char >= 43600 && test_char < 43610 ) { return true; }
		if( test_char >= 43612 && test_char < 43715 ) { return true; }
		if( test_char >= 43739 && test_char < 43767 ) { return true; }
		if( test_char >= 43777 && test_char < 43783 ) { return true; }
		if( test_char >= 43785 && test_char < 43791 ) { return true; }
		if( test_char >= 43793 && test_char < 43799 ) { return true; }
		if( test_char >= 43808 && test_char < 43815 ) { return true; }
		if( test_char >= 43816 && test_char < 43823 ) { return true; }
		if( test_char >= 43824 && test_char < 43884 ) { return true; }
		if( test_char >= 43888 && test_char < 44014 ) { return true; }
		if( test_char >= 44016 && test_char < 44026 ) { return true; }
		if( test_char >= 44032 && test_char < 55204 ) { return true; }
		if( test_char >= 55216 && test_char < 55239 ) { return true; }
		if( test_char >= 55243 && test_char < 55292 ) { return true; }
		if( test_char >= 63744 && test_char < 64110 ) { return true; }
		if( test_char >= 64112 && test_char < 64218 ) { return true; }
		if( test_char >= 64256 && test_char < 64263 ) { return true; }
		if( test_char >= 64275 && test_char < 64280 ) { return true; }
		if( test_char >= 64285 && test_char < 64311 ) { return true; }
		if( test_char >= 64312 && test_char < 64317 ) { return true; }
		if( test_char == 64318 ) { return true; }
		if( test_char >= 64320 && test_char < 64322 ) { return true; }
		if( test_char >= 64323 && test_char < 64325 ) { return true; }
		if( test_char >= 64326 && test_char < 64451 ) { return true; }
		if( test_char >= 64467 && test_char < 64912 ) { return true; }
		if( test_char >= 64914 && test_char < 64968 ) { return true; }
		if( test_char == 64975 ) { return true; }
		if( test_char >= 65008 && test_char < 65050 ) { return true; }
		if( test_char >= 65056 && test_char < 65107 ) { return true; }
		if( test_char >= 65108 && test_char < 65127 ) { return true; }
		if( test_char >= 65128 && test_char < 65132 ) { return true; }
		if( test_char >= 65136 && test_char < 65141 ) { return true; }
		if( test_char >= 65142 && test_char < 65277 ) { return true; }
		if( test_char >= 65281 && test_char < 65471 ) { return true; }
		if( test_char >= 65474 && test_char < 65480 ) { return true; }
		if( test_char >= 65482 && test_char < 65488 ) { return true; }
		if( test_char >= 65490 && test_char < 65496 ) { return true; }
		if( test_char >= 65498 && test_char < 65501 ) { return true; }
		if( test_char >= 65504 && test_char < 65511 ) { return true; }
		if( test_char >= 65512 && test_char < 65519 ) { return true; }
		if( test_char >= 65532 && test_char < 65534 ) { return true; }
		if( test_char >= 65536 && test_char < 65548 ) { return true; }
		if( test_char >= 65549 && test_char < 65575 ) { return true; }
		if( test_char >= 65576 && test_char < 65595 ) { return true; }
		if( test_char >= 65596 && test_char < 65598 ) { return true; }
		if( test_char >= 65599 && test_char < 65614 ) { return true; }
		if( test_char >= 65616 && test_char < 65630 ) { return true; }
		if( test_char >= 65664 && test_char < 65787 ) { return true; }
		if( test_char >= 65792 && test_char < 65795 ) { return true; }
		if( test_char >= 65799 && test_char < 65844 ) { return true; }
		if( test_char >= 65847 && test_char < 65935 ) { return true; }
		if( test_char >= 65936 && test_char < 65949 ) { return true; }
		if( test_char == 65952 ) { return true; }
		if( test_char >= 66000 && test_char < 66046 ) { return true; }
		if( test_char >= 66176 && test_char < 66205 ) { return true; }
		if( test_char >= 66208 && test_char < 66257 ) { return true; }
		if( test_char >= 66272 && test_char < 66300 ) { return true; }
		if( test_char >= 66304 && test_char < 66340 ) { return true; }
		if( test_char >= 66349 && test_char < 66379 ) { return true; }
		if( test_char >= 66384 && test_char < 66427 ) { return true; }
		if( test_char >= 66432 && test_char < 66462 ) { return true; }
		if( test_char >= 66463 && test_char < 66500 ) { return true; }
		if( test_char >= 66504 && test_char < 66518 ) { return true; }
		if( test_char >= 66560 && test_char < 66718 ) { return true; }
		if( test_char >= 66720 && test_char < 66730 ) { return true; }
		if( test_char >= 66736 && test_char < 66772 ) { return true; }
		if( test_char >= 66776 && test_char < 66812 ) { return true; }
		if( test_char >= 66816 && test_char < 66856 ) { return true; }
		if( test_char >= 66864 && test_char < 66916 ) { return true; }
		if( test_char >= 66927 && test_char < 66939 ) { return true; }
		if( test_char >= 66940 && test_char < 66955 ) { return true; }
		if( test_char >= 66956 && test_char < 66963 ) { return true; }
		if( test_char >= 66964 && test_char < 66966 ) { return true; }
		if( test_char >= 66967 && test_char < 66978 ) { return true; }
		if( test_char >= 66979 && test_char < 66994 ) { return true; }
		if( test_char >= 66995 && test_char < 67002 ) { return true; }
		if( test_char >= 67003 && test_char < 67005 ) { return true; }
		if( test_char >= 67072 && test_char < 67383 ) { return true; }
		if( test_char >= 67392 && test_char < 67414 ) { return true; }
		if( test_char >= 67424 && test_char < 67432 ) { return true; }
		if( test_char >= 67456 && test_char < 67462 ) { return true; }
		if( test_char >= 67463 && test_char < 67505 ) { return true; }
		if( test_char >= 67506 && test_char < 67515 ) { return true; }
		if( test_char >= 67584 && test_char < 67590 ) { return true; }
		if( test_char == 67592 ) { return true; }
		if( test_char >= 67594 && test_char < 67638 ) { return true; }
		if( test_char >= 67639 && test_char < 67641 ) { return true; }
		if( test_char == 67644 ) { return true; }
		if( test_char >= 67647 && test_char < 67670 ) { return true; }
		if( test_char >= 67671 && test_char < 67743 ) { return true; }
		if( test_char >= 67751 && test_char < 67760 ) { return true; }
		if( test_char >= 67808 && test_char < 67827 ) { return true; }
		if( test_char >= 67828 && test_char < 67830 ) { return true; }
		if( test_char >= 67835 && test_char < 67868 ) { return true; }
		if( test_char >= 67871 && test_char < 67898 ) { return true; }
		if( test_char == 67903 ) { return true; }
		if( test_char >= 67968 && test_char < 68024 ) { return true; }
		if( test_char >= 68028 && test_char < 68048 ) { return true; }
		if( test_char >= 68050 && test_char < 68100 ) { return true; }
		if( test_char >= 68101 && test_char < 68103 ) { return true; }
		if( test_char >= 68108 && test_char < 68116 ) { return true; }
		if( test_char >= 68117 && test_char < 68120 ) { return true; }
		if( test_char >= 68121 && test_char < 68150 ) { return true; }
		if( test_char >= 68152 && test_char < 68155 ) { return true; }
		if( test_char >= 68159 && test_char < 68169 ) { return true; }
		if( test_char >= 68176 && test_char < 68185 ) { return true; }
		if( test_char >= 68192 && test_char < 68256 ) { return true; }
		if( test_char >= 68288 && test_char < 68327 ) { return true; }
		if( test_char >= 68331 && test_char < 68343 ) { return true; }
		if( test_char >= 68352 && test_char < 68406 ) { return true; }
		if( test_char >= 68409 && test_char < 68438 ) { return true; }
		if( test_char >= 68440 && test_char < 68467 ) { return true; }
		if( test_char >= 68472 && test_char < 68498 ) { return true; }
		if( test_char >= 68505 && test_char < 68509 ) { return true; }
		if( test_char >= 68521 && test_char < 68528 ) { return true; }
		if( test_char >= 68608 && test_char < 68681 ) { return true; }
		if( test_char >= 68736 && test_char < 68787 ) { return true; }
		if( test_char >= 68800 && test_char < 68851 ) { return true; }
		if( test_char >= 68858 && test_char < 68904 ) { return true; }
		if( test_char >= 68912 && test_char < 68922 ) { return true; }
		if( test_char >= 69216 && test_char < 69247 ) { return true; }
		if( test_char >= 69248 && test_char < 69290 ) { return true; }
		if( test_char >= 69291 && test_char < 69294 ) { return true; }
		if( test_char >= 69296 && test_char < 69298 ) { return true; }
		if( test_char >= 69373 && test_char < 69416 ) { return true; }
		if( test_char >= 69424 && test_char < 69466 ) { return true; }
		if( test_char >= 69488 && test_char < 69514 ) { return true; }
		if( test_char >= 69552 && test_char < 69580 ) { return true; }
		if( test_char >= 69600 && test_char < 69623 ) { return true; }
		if( test_char >= 69632 && test_char < 69710 ) { return true; }
		if( test_char >= 69714 && test_char < 69750 ) { return true; }
		if( test_char >= 69759 && test_char < 69821 ) { return true; }
		if( test_char >= 69822 && test_char < 69827 ) { return true; }
		if( test_char >= 69840 && test_char < 69865 ) { return true; }
		if( test_char >= 69872 && test_char < 69882 ) { return true; }
		if( test_char >= 69888 && test_char < 69941 ) { return true; }
		if( test_char >= 69942 && test_char < 69960 ) { return true; }
		if( test_char >= 69968 && test_char < 70007 ) { return true; }
		if( test_char >= 70016 && test_char < 70112 ) { return true; }
		if( test_char >= 70113 && test_char < 70133 ) { return true; }
		if( test_char >= 70144 && test_char < 70162 ) { return true; }
		if( test_char >= 70163 && test_char < 70210 ) { return true; }
		if( test_char >= 70272 && test_char < 70279 ) { return true; }
		if( test_char == 70280 ) { return true; }
		if( test_char >= 70282 && test_char < 70286 ) { return true; }
		if( test_char >= 70287 && test_char < 70302 ) { return true; }
		if( test_char >= 70303 && test_char < 70314 ) { return true; }
		if( test_char >= 70320 && test_char < 70379 ) { return true; }
		if( test_char >= 70384 && test_char < 70394 ) { return true; }
		if( test_char >= 70400 && test_char < 70404 ) { return true; }
		if( test_char >= 70405 && test_char < 70413 ) { return true; }
		if( test_char >= 70415 && test_char < 70417 ) { return true; }
		if( test_char >= 70419 && test_char < 70441 ) { return true; }
		if( test_char >= 70442 && test_char < 70449 ) { return true; }
		if( test_char >= 70450 && test_char < 70452 ) { return true; }
		if( test_char >= 70453 && test_char < 70458 ) { return true; }
		if( test_char >= 70459 && test_char < 70469 ) { return true; }
		if( test_char >= 70471 && test_char < 70473 ) { return true; }
		if( test_char >= 70475 && test_char < 70478 ) { return true; }
		if( test_char == 70480 ) { return true; }
		if( test_char == 70487 ) { return true; }
		if( test_char >= 70493 && test_char < 70500 ) { return true; }
		if( test_char >= 70502 && test_char < 70509 ) { return true; }
		if( test_char >= 70512 && test_char < 70517 ) { return true; }
		if( test_char >= 70656 && test_char < 70748 ) { return true; }
		if( test_char >= 70749 && test_char < 70754 ) { return true; }
		if( test_char >= 70784 && test_char < 70856 ) { return true; }
		if( test_char >= 70864 && test_char < 70874 ) { return true; }
		if( test_char >= 71040 && test_char < 71094 ) { return true; }
		if( test_char >= 71096 && test_char < 71134 ) { return true; }
		if( test_char >= 71168 && test_char < 71237 ) { return true; }
		if( test_char >= 71248 && test_char < 71258 ) { return true; }
		if( test_char >= 71264 && test_char < 71277 ) { return true; }
		if( test_char >= 71296 && test_char < 71354 ) { return true; }
		if( test_char >= 71360 && test_char < 71370 ) { return true; }
		if( test_char >= 71424 && test_char < 71451 ) { return true; }
		if( test_char >= 71453 && test_char < 71468 ) { return true; }
		if( test_char >= 71472 && test_char < 71495 ) { return true; }
		if( test_char >= 71680 && test_char < 71740 ) { return true; }
		if( test_char >= 71840 && test_char < 71923 ) { return true; }
		if( test_char >= 71935 && test_char < 71943 ) { return true; }
		if( test_char == 71945 ) { return true; }
		if( test_char >= 71948 && test_char < 71956 ) { return true; }
		if( test_char >= 71957 && test_char < 71959 ) { return true; }
		if( test_char >= 71960 && test_char < 71990 ) { return true; }
		if( test_char >= 71991 && test_char < 71993 ) { return true; }
		if( test_char >= 71995 && test_char < 72007 ) { return true; }
		if( test_char >= 72016 && test_char < 72026 ) { return true; }
		if( test_char >= 72096 && test_char < 72104 ) { return true; }
		if( test_char >= 72106 && test_char < 72152 ) { return true; }
		if( test_char >= 72154 && test_char < 72165 ) { return true; }
		if( test_char >= 72192 && test_char < 72264 ) { return true; }
		if( test_char >= 72272 && test_char < 72355 ) { return true; }
		if( test_char >= 72368 && test_char < 72441 ) { return true; }
		if( test_char >= 72448 && test_char < 72458 ) { return true; }
		if( test_char >= 72704 && test_char < 72713 ) { return true; }
		if( test_char >= 72714 && test_char < 72759 ) { return true; }
		if( test_char >= 72760 && test_char < 72774 ) { return true; }
		if( test_char >= 72784 && test_char < 72813 ) { return true; }
		if( test_char >= 72816 && test_char < 72848 ) { return true; }
		if( test_char >= 72850 && test_char < 72872 ) { return true; }
		if( test_char >= 72873 && test_char < 72887 ) { return true; }
		if( test_char >= 72960 && test_char < 72967 ) { return true; }
		if( test_char >= 72968 && test_char < 72970 ) { return true; }
		if( test_char >= 72971 && test_char < 73015 ) { return true; }
		if( test_char == 73018 ) { return true; }
		if( test_char >= 73020 && test_char < 73022 ) { return true; }
		if( test_char >= 73023 && test_char < 73032 ) { return true; }
		if( test_char >= 73040 && test_char < 73050 ) { return true; }
		if( test_char >= 73056 && test_char < 73062 ) { return true; }
		if( test_char >= 73063 && test_char < 73065 ) { return true; }
		if( test_char >= 73066 && test_char < 73103 ) { return true; }
		if( test_char >= 73104 && test_char < 73106 ) { return true; }
		if( test_char >= 73107 && test_char < 73113 ) { return true; }
		if( test_char >= 73120 && test_char < 73130 ) { return true; }
		if( test_char >= 73440 && test_char < 73465 ) { return true; }
		if( test_char >= 73472 && test_char < 73489 ) { return true; }
		if( test_char >= 73490 && test_char < 73531 ) { return true; }
		if( test_char >= 73534 && test_char < 73562 ) { return true; }
		if( test_char == 73648 ) { return true; }
		if( test_char >= 73664 && test_char < 73714 ) { return true; }
		if( test_char >= 73727 && test_char < 74650 ) { return true; }
		if( test_char >= 74752 && test_char < 74863 ) { return true; }
		if( test_char >= 74864 && test_char < 74869 ) { return true; }
		if( test_char >= 74880 && test_char < 75076 ) { return true; }
		if( test_char >= 77712 && test_char < 77811 ) { return true; }
		if( test_char >= 77824 && test_char < 78896 ) { return true; }
		if( test_char >= 78912 && test_char < 78934 ) { return true; }
		if( test_char >= 82944 && test_char < 83527 ) { return true; }
		if( test_char >= 92160 && test_char < 92729 ) { return true; }
		if( test_char >= 92736 && test_char < 92767 ) { return true; }
		if( test_char >= 92768 && test_char < 92778 ) { return true; }
		if( test_char >= 92782 && test_char < 92863 ) { return true; }
		if( test_char >= 92864 && test_char < 92874 ) { return true; }
		if( test_char >= 92880 && test_char < 92910 ) { return true; }
		if( test_char >= 92912 && test_char < 92918 ) { return true; }
		if( test_char >= 92928 && test_char < 92998 ) { return true; }
		if( test_char >= 93008 && test_char < 93018 ) { return true; }
		if( test_char >= 93019 && test_char < 93026 ) { return true; }
		if( test_char >= 93027 && test_char < 93048 ) { return true; }
		if( test_char >= 93053 && test_char < 93072 ) { return true; }
		if( test_char >= 93760 && test_char < 93851 ) { return true; }
		if( test_char >= 93952 && test_char < 94027 ) { return true; }
		if( test_char >= 94031 && test_char < 94088 ) { return true; }
		if( test_char >= 94095 && test_char < 94112 ) { return true; }
		if( test_char >= 94176 && test_char < 94181 ) { return true; }
		if( test_char >= 94192 && test_char < 94194 ) { return true; }
		if( test_char >= 94208 && test_char < 100344 ) { return true; }
		if( test_char >= 100352 && test_char < 101590 ) { return true; }
		if( test_char >= 101632 && test_char < 101641 ) { return true; }
		if( test_char >= 110576 && test_char < 110580 ) { return true; }
		if( test_char >= 110581 && test_char < 110588 ) { return true; }
		if( test_char >= 110589 && test_char < 110591 ) { return true; }
		if( test_char >= 110592 && test_char < 110883 ) { return true; }
		if( test_char == 110898 ) { return true; }
		if( test_char >= 110928 && test_char < 110931 ) { return true; }
		if( test_char == 110933 ) { return true; }
		if( test_char >= 110948 && test_char < 110952 ) { return true; }
		if( test_char >= 110960 && test_char < 111356 ) { return true; }
		if( test_char >= 113664 && test_char < 113771 ) { return true; }
		if( test_char >= 113776 && test_char < 113789 ) { return true; }
		if( test_char >= 113792 && test_char < 113801 ) { return true; }
		if( test_char >= 113808 && test_char < 113818 ) { return true; }
		if( test_char >= 113820 && test_char < 113824 ) { return true; }
		if( test_char >= 118528 && test_char < 118574 ) { return true; }
		if( test_char >= 118576 && test_char < 118599 ) { return true; }
		if( test_char >= 118608 && test_char < 118724 ) { return true; }
		if( test_char >= 118784 && test_char < 119030 ) { return true; }
		if( test_char >= 119040 && test_char < 119079 ) { return true; }
		if( test_char >= 119081 && test_char < 119155 ) { return true; }
		if( test_char >= 119163 && test_char < 119275 ) { return true; }
		if( test_char >= 119296 && test_char < 119366 ) { return true; }
		if( test_char >= 119488 && test_char < 119508 ) { return true; }
		if( test_char >= 119520 && test_char < 119540 ) { return true; }
		if( test_char >= 119552 && test_char < 119639 ) { return true; }
		if( test_char >= 119648 && test_char < 119673 ) { return true; }
		if( test_char >= 119808 && test_char < 119893 ) { return true; }
		if( test_char >= 119894 && test_char < 119965 ) { return true; }
		if( test_char >= 119966 && test_char < 119968 ) { return true; }
		if( test_char == 119970 ) { return true; }
		if( test_char >= 119973 && test_char < 119975 ) { return true; }
		if( test_char >= 119977 && test_char < 119981 ) { return true; }
		if( test_char >= 119982 && test_char < 119994 ) { return true; }
		if( test_char == 119995 ) { return true; }
		if( test_char >= 119997 && test_char < 120004 ) { return true; }
		if( test_char >= 120005 && test_char < 120070 ) { return true; }
		if( test_char >= 120071 && test_char < 120075 ) { return true; }
		if( test_char >= 120077 && test_char < 120085 ) { return true; }
		if( test_char >= 120086 && test_char < 120093 ) { return true; }
		if( test_char >= 120094 && test_char < 120122 ) { return true; }
		if( test_char >= 120123 && test_char < 120127 ) { return true; }
		if( test_char >= 120128 && test_char < 120133 ) { return true; }
		if( test_char == 120134 ) { return true; }
		if( test_char >= 120138 && test_char < 120145 ) { return true; }
		if( test_char >= 120146 && test_char < 120486 ) { return true; }
		if( test_char >= 120488 && test_char < 120780 ) { return true; }
		if( test_char >= 120782 && test_char < 121484 ) { return true; }
		if( test_char >= 121499 && test_char < 121504 ) { return true; }
		if( test_char >= 121505 && test_char < 121520 ) { return true; }
		if( test_char >= 122624 && test_char < 122655 ) { return true; }
		if( test_char >= 122661 && test_char < 122667 ) { return true; }
		if( test_char >= 122880 && test_char < 122887 ) { return true; }
		if( test_char >= 122888 && test_char < 122905 ) { return true; }
		if( test_char >= 122907 && test_char < 122914 ) { return true; }
		if( test_char >= 122915 && test_char < 122917 ) { return true; }
		if( test_char >= 122918 && test_char < 122923 ) { return true; }
		if( test_char >= 122928 && test_char < 122990 ) { return true; }
		if( test_char == 123023 ) { return true; }
		if( test_char >= 123136 && test_char < 123181 ) { return true; }
		if( test_char >= 123184 && test_char < 123198 ) { return true; }
		if( test_char >= 123200 && test_char < 123210 ) { return true; }
		if( test_char >= 123214 && test_char < 123216 ) { return true; }
		if( test_char >= 123536 && test_char < 123567 ) { return true; }
		if( test_char >= 123584 && test_char < 123642 ) { return true; }
		if( test_char == 123647 ) { return true; }
		if( test_char >= 124112 && test_char < 124154 ) { return true; }
		if( test_char >= 124896 && test_char < 124903 ) { return true; }
		if( test_char >= 124904 && test_char < 124908 ) { return true; }
		if( test_char >= 124909 && test_char < 124911 ) { return true; }
		if( test_char >= 124912 && test_char < 124927 ) { return true; }
		if( test_char >= 124928 && test_char < 125125 ) { return true; }
		if( test_char >= 125127 && test_char < 125143 ) { return true; }
		if( test_char >= 125184 && test_char < 125260 ) { return true; }
		if( test_char >= 125264 && test_char < 125274 ) { return true; }
		if( test_char >= 125278 && test_char < 125280 ) { return true; }
		if( test_char >= 126065 && test_char < 126133 ) { return true; }
		if( test_char >= 126209 && test_char < 126270 ) { return true; }
		if( test_char >= 126464 && test_char < 126468 ) { return true; }
		if( test_char >= 126469 && test_char < 126496 ) { return true; }
		if( test_char >= 126497 && test_char < 126499 ) { return true; }
		if( test_char == 126500 ) { return true; }
		if( test_char == 126503 ) { return true; }
		if( test_char >= 126505 && test_char < 126515 ) { return true; }
		if( test_char >= 126516 && test_char < 126520 ) { return true; }
		if( test_char == 126521 ) { return true; }
		if( test_char == 126523 ) { return true; }
		if( test_char == 126530 ) { return true; }
		if( test_char == 126535 ) { return true; }
		if( test_char == 126537 ) { return true; }
		if( test_char == 126539 ) { return true; }
		if( test_char >= 126541 && test_char < 126544 ) { return true; }
		if( test_char >= 126545 && test_char < 126547 ) { return true; }
		if( test_char == 126548 ) { return true; }
		if( test_char == 126551 ) { return true; }
		if( test_char == 126553 ) { return true; }
		if( test_char == 126555 ) { return true; }
		if( test_char == 126557 ) { return true; }
		if( test_char == 126559 ) { return true; }
		if( test_char >= 126561 && test_char < 126563 ) { return true; }
		if( test_char == 126564 ) { return true; }
		if( test_char >= 126567 && test_char < 126571 ) { return true; }
		if( test_char >= 126572 && test_char < 126579 ) { return true; }
		if( test_char >= 126580 && test_char < 126584 ) { return true; }
		if( test_char >= 126585 && test_char < 126589 ) { return true; }
		if( test_char == 126590 ) { return true; }
		if( test_char >= 126592 && test_char < 126602 ) { return true; }
		if( test_char >= 126603 && test_char < 126620 ) { return true; }
		if( test_char >= 126625 && test_char < 126628 ) { return true; }
		if( test_char >= 126629 && test_char < 126634 ) { return true; }
		if( test_char >= 126635 && test_char < 126652 ) { return true; }
		if( test_char >= 126704 && test_char < 126706 ) { return true; }
		if( test_char >= 126976 && test_char < 127020 ) { return true; }
		if( test_char >= 127024 && test_char < 127124 ) { return true; }
		if( test_char >= 127136 && test_char < 127151 ) { return true; }
		if( test_char >= 127153 && test_char < 127168 ) { return true; }
		if( test_char >= 127169 && test_char < 127184 ) { return true; }
		if( test_char >= 127185 && test_char < 127222 ) { return true; }
		if( test_char >= 127232 && test_char < 127406 ) { return true; }
		if( test_char >= 127462 && test_char < 127491 ) { return true; }
		if( test_char >= 127504 && test_char < 127548 ) { return true; }
		if( test_char >= 127552 && test_char < 127561 ) { return true; }
		if( test_char >= 127568 && test_char < 127570 ) { return true; }
		if( test_char >= 127584 && test_char < 127590 ) { return true; }
		if( test_char >= 127744 && test_char < 128728 ) { return true; }
		if( test_char >= 128732 && test_char < 128749 ) { return true; }
		if( test_char >= 128752 && test_char < 128765 ) { return true; }
		if( test_char >= 128768 && test_char < 128887 ) { return true; }
		if( test_char >= 128891 && test_char < 128986 ) { return true; }
		if( test_char >= 128992 && test_char < 129004 ) { return true; }
		if( test_char == 129008 ) { return true; }
		if( test_char >= 129024 && test_char < 129036 ) { return true; }
		if( test_char >= 129040 && test_char < 129096 ) { return true; }
		if( test_char >= 129104 && test_char < 129114 ) { return true; }
		if( test_char >= 129120 && test_char < 129160 ) { return true; }
		if( test_char >= 129168 && test_char < 129198 ) { return true; }
		if( test_char >= 129200 && test_char < 129202 ) { return true; }
		if( test_char >= 129280 && test_char < 129620 ) { return true; }
		if( test_char >= 129632 && test_char < 129646 ) { return true; }
		if( test_char >= 129648 && test_char < 129661 ) { return true; }
		if( test_char >= 129664 && test_char < 129673 ) { return true; }
		if( test_char >= 129680 && test_char < 129726 ) { return true; }
		if( test_char >= 129727 && test_char < 129734 ) { return true; }
		if( test_char >= 129742 && test_char < 129756 ) { return true; }
		if( test_char >= 129760 && test_char < 129769 ) { return true; }
		if( test_char >= 129776 && test_char < 129785 ) { return true; }
		if( test_char >= 129792 && test_char < 129939 ) { return true; }
		if( test_char >= 129940 && test_char < 129995 ) { return true; }
		if( test_char >= 130032 && test_char < 130042 ) { return true; }
		if( test_char >= 131072 && test_char < 173792 ) { return true; }
		if( test_char >= 173824 && test_char < 177978 ) { return true; }
		if( test_char >= 177984 && test_char < 178206 ) { return true; }
		if( test_char >= 178208 && test_char < 183970 ) { return true; }
		if( test_char >= 183984 && test_char < 191457 ) { return true; }
		if( test_char >= 191472 && test_char < 192094 ) { return true; }
		if( test_char >= 194560 && test_char < 195102 ) { return true; }
		if( test_char >= 196608 && test_char < 201547 ) { return true; }
		if( test_char >= 201552 && test_char < 205744 ) { return true; }
		if( test_char >= 917760 && test_char < 918000 ) { return true; }

		return false;
	}
	
	bool is_space(char32_t test_char) noexcept {
		if( test_char >= 9 && test_char < 14 ) { return true; }
		if( test_char >= 28 && test_char < 33 ) { return true; }
		if( test_char == 133 ) { return true; }
		if( test_char == 160 ) { return true; }
		if( test_char == 5760 ) { return true; }
		if( test_char >= 8192 && test_char < 8203 ) { return true; }
		if( test_char >= 8232 && test_char < 8234 ) { return true; }
		if( test_char == 8239 ) { return true; }
		if( test_char == 8287 ) { return true; }
		if( test_char == 12288 ) { return true; }

		return false;
	}
	
	bool is_title_case(char32_t test_char) noexcept {
		if( test_char >= 65 && test_char < 91 ) { return true; }
		if( test_char >= 192 && test_char < 215 ) { return true; }
		if( test_char >= 216 && test_char < 223 ) { return true; }
		if( test_char == 256 ) { return true; }
		if( test_char == 258 ) { return true; }
		if( test_char == 260 ) { return true; }
		if( test_char == 262 ) { return true; }
		if( test_char == 264 ) { return true; }
		if( test_char == 266 ) { return true; }
		if( test_char == 268 ) { return true; }
		if( test_char == 270 ) { return true; }
		if( test_char == 272 ) { return true; }
		if( test_char == 274 ) { return true; }
		if( test_char == 276 ) { return true; }
		if( test_char == 278 ) { return true; }
		if( test_char == 280 ) { return true; }
		if( test_char == 282 ) { return true; }
		if( test_char == 284 ) { return true; }
		if( test_char == 286 ) { return true; }
		if( test_char == 288 ) { return true; }
		if( test_char == 290 ) { return true; }
		if( test_char == 292 ) { return true; }
		if( test_char == 294 ) { return true; }
		if( test_char == 296 ) { return true; }
		if( test_char == 298 ) { return true; }
		if( test_char == 300 ) { return true; }
		if( test_char == 302 ) { return true; }
		if( test_char == 304 ) { return true; }
		if( test_char == 306 ) { return true; }
		if( test_char == 308 ) { return true; }
		if( test_char == 310 ) { return true; }
		if( test_char == 313 ) { return true; }
		if( test_char == 315 ) { return true; }
		if( test_char == 317 ) { return true; }
		if( test_char == 319 ) { return true; }
		if( test_char == 321 ) { return true; }
		if( test_char == 323 ) { return true; }
		if( test_char == 325 ) { return true; }
		if( test_char == 327 ) { return true; }
		if( test_char == 330 ) { return true; }
		if( test_char == 332 ) { return true; }
		if( test_char == 334 ) { return true; }
		if( test_char == 336 ) { return true; }
		if( test_char == 338 ) { return true; }
		if( test_char == 340 ) { return true; }
		if( test_char == 342 ) { return true; }
		if( test_char == 344 ) { return true; }
		if( test_char == 346 ) { return true; }
		if( test_char == 348 ) { return true; }
		if( test_char == 350 ) { return true; }
		if( test_char == 352 ) { return true; }
		if( test_char == 354 ) { return true; }
		if( test_char == 356 ) { return true; }
		if( test_char == 358 ) { return true; }
		if( test_char == 360 ) { return true; }
		if( test_char == 362 ) { return true; }
		if( test_char == 364 ) { return true; }
		if( test_char == 366 ) { return true; }
		if( test_char == 368 ) { return true; }
		if( test_char == 370 ) { return true; }
		if( test_char == 372 ) { return true; }
		if( test_char == 374 ) { return true; }
		if( test_char >= 376 && test_char < 378 ) { return true; }
		if( test_char == 379 ) { return true; }
		if( test_char == 381 ) { return true; }
		if( test_char >= 385 && test_char < 387 ) { return true; }
		if( test_char == 388 ) { return true; }
		if( test_char >= 390 && test_char < 392 ) { return true; }
		if( test_char >= 393 && test_char < 396 ) { return true; }
		if( test_char >= 398 && test_char < 402 ) { return true; }
		if( test_char >= 403 && test_char < 405 ) { return true; }
		if( test_char >= 406 && test_char < 409 ) { return true; }
		if( test_char >= 412 && test_char < 414 ) { return true; }
		if( test_char >= 415 && test_char < 417 ) { return true; }
		if( test_char == 418 ) { return true; }
		if( test_char == 420 ) { return true; }
		if( test_char >= 422 && test_char < 424 ) { return true; }
		if( test_char == 425 ) { return true; }
		if( test_char == 428 ) { return true; }
		if( test_char >= 430 && test_char < 432 ) { return true; }
		if( test_char >= 433 && test_char < 436 ) { return true; }
		if( test_char == 437 ) { return true; }
		if( test_char >= 439 && test_char < 441 ) { return true; }
		if( test_char == 444 ) { return true; }
		if( test_char >= 452 && test_char < 454 ) { return true; }
		if( test_char >= 455 && test_char < 457 ) { return true; }
		if( test_char >= 458 && test_char < 460 ) { return true; }
		if( test_char == 461 ) { return true; }
		if( test_char == 463 ) { return true; }
		if( test_char == 465 ) { return true; }
		if( test_char == 467 ) { return true; }
		if( test_char == 469 ) { return true; }
		if( test_char == 471 ) { return true; }
		if( test_char == 473 ) { return true; }
		if( test_char == 475 ) { return true; }
		if( test_char == 478 ) { return true; }
		if( test_char == 480 ) { return true; }
		if( test_char == 482 ) { return true; }
		if( test_char == 484 ) { return true; }
		if( test_char == 486 ) { return true; }
		if( test_char == 488 ) { return true; }
		if( test_char == 490 ) { return true; }
		if( test_char == 492 ) { return true; }
		if( test_char == 494 ) { return true; }
		if( test_char >= 497 && test_char < 499 ) { return true; }
		if( test_char == 500 ) { return true; }
		if( test_char >= 502 && test_char < 505 ) { return true; }
		if( test_char == 506 ) { return true; }
		if( test_char == 508 ) { return true; }
		if( test_char == 510 ) { return true; }
		if( test_char == 512 ) { return true; }
		if( test_char == 514 ) { return true; }
		if( test_char == 516 ) { return true; }
		if( test_char == 518 ) { return true; }
		if( test_char == 520 ) { return true; }
		if( test_char == 522 ) { return true; }
		if( test_char == 524 ) { return true; }
		if( test_char == 526 ) { return true; }
		if( test_char == 528 ) { return true; }
		if( test_char == 530 ) { return true; }
		if( test_char == 532 ) { return true; }
		if( test_char == 534 ) { return true; }
		if( test_char == 536 ) { return true; }
		if( test_char == 538 ) { return true; }
		if( test_char == 540 ) { return true; }
		if( test_char == 542 ) { return true; }
		if( test_char == 544 ) { return true; }
		if( test_char == 546 ) { return true; }
		if( test_char == 548 ) { return true; }
		if( test_char == 550 ) { return true; }
		if( test_char == 552 ) { return true; }
		if( test_char == 554 ) { return true; }
		if( test_char == 556 ) { return true; }
		if( test_char == 558 ) { return true; }
		if( test_char == 560 ) { return true; }
		if( test_char == 562 ) { return true; }
		if( test_char >= 570 && test_char < 572 ) { return true; }
		if( test_char >= 573 && test_char < 575 ) { return true; }
		if( test_char == 577 ) { return true; }
		if( test_char >= 579 && test_char < 583 ) { return true; }
		if( test_char == 584 ) { return true; }
		if( test_char == 586 ) { return true; }
		if( test_char == 588 ) { return true; }
		if( test_char == 590 ) { return true; }
		if( test_char == 880 ) { return true; }
		if( test_char == 882 ) { return true; }
		if( test_char == 886 ) { return true; }
		if( test_char == 895 ) { return true; }
		if( test_char == 902 ) { return true; }
		if( test_char >= 904 && test_char < 907 ) { return true; }
		if( test_char == 908 ) { return true; }
		if( test_char >= 910 && test_char < 912 ) { return true; }
		if( test_char >= 913 && test_char < 930 ) { return true; }
		if( test_char >= 931 && test_char < 940 ) { return true; }
		if( test_char == 975 ) { return true; }
		if( test_char >= 978 && test_char < 981 ) { return true; }
		if( test_char == 984 ) { return true; }
		if( test_char == 986 ) { return true; }
		if( test_char == 988 ) { return true; }
		if( test_char == 990 ) { return true; }
		if( test_char == 992 ) { return true; }
		if( test_char == 994 ) { return true; }
		if( test_char == 996 ) { return true; }
		if( test_char == 998 ) { return true; }
		if( test_char == 1000 ) { return true; }
		if( test_char == 1002 ) { return true; }
		if( test_char == 1004 ) { return true; }
		if( test_char == 1006 ) { return true; }
		if( test_char == 1012 ) { return true; }
		if( test_char == 1015 ) { return true; }
		if( test_char >= 1017 && test_char < 1019 ) { return true; }
		if( test_char >= 1021 && test_char < 1072 ) { return true; }
		if( test_char == 1120 ) { return true; }
		if( test_char == 1122 ) { return true; }
		if( test_char == 1124 ) { return true; }
		if( test_char == 1126 ) { return true; }
		if( test_char == 1128 ) { return true; }
		if( test_char == 1130 ) { return true; }
		if( test_char == 1132 ) { return true; }
		if( test_char == 1134 ) { return true; }
		if( test_char == 1136 ) { return true; }
		if( test_char == 1138 ) { return true; }
		if( test_char == 1140 ) { return true; }
		if( test_char == 1142 ) { return true; }
		if( test_char == 1144 ) { return true; }
		if( test_char == 1146 ) { return true; }
		if( test_char == 1148 ) { return true; }
		if( test_char == 1150 ) { return true; }
		if( test_char == 1152 ) { return true; }
		if( test_char == 1162 ) { return true; }
		if( test_char == 1164 ) { return true; }
		if( test_char == 1166 ) { return true; }
		if( test_char == 1168 ) { return true; }
		if( test_char == 1170 ) { return true; }
		if( test_char == 1172 ) { return true; }
		if( test_char == 1174 ) { return true; }
		if( test_char == 1176 ) { return true; }
		if( test_char == 1178 ) { return true; }
		if( test_char == 1180 ) { return true; }
		if( test_char == 1182 ) { return true; }
		if( test_char == 1184 ) { return true; }
		if( test_char == 1186 ) { return true; }
		if( test_char == 1188 ) { return true; }
		if( test_char == 1190 ) { return true; }
		if( test_char == 1192 ) { return true; }
		if( test_char == 1194 ) { return true; }
		if( test_char == 1196 ) { return true; }
		if( test_char == 1198 ) { return true; }
		if( test_char == 1200 ) { return true; }
		if( test_char == 1202 ) { return true; }
		if( test_char == 1204 ) { return true; }
		if( test_char == 1206 ) { return true; }
		if( test_char == 1208 ) { return true; }
		if( test_char == 1210 ) { return true; }
		if( test_char == 1212 ) { return true; }
		if( test_char == 1214 ) { return true; }
		if( test_char >= 1216 && test_char < 1218 ) { return true; }
		if( test_char == 1219 ) { return true; }
		if( test_char == 1221 ) { return true; }
		if( test_char == 1223 ) { return true; }
		if( test_char == 1225 ) { return true; }
		if( test_char == 1227 ) { return true; }
		if( test_char == 1229 ) { return true; }
		if( test_char == 1232 ) { return true; }
		if( test_char == 1234 ) { return true; }
		if( test_char == 1236 ) { return true; }
		if( test_char == 1238 ) { return true; }
		if( test_char == 1240 ) { return true; }
		if( test_char == 1242 ) { return true; }
		if( test_char == 1244 ) { return true; }
		if( test_char == 1246 ) { return true; }
		if( test_char == 1248 ) { return true; }
		if( test_char == 1250 ) { return true; }
		if( test_char == 1252 ) { return true; }
		if( test_char == 1254 ) { return true; }
		if( test_char == 1256 ) { return true; }
		if( test_char == 1258 ) { return true; }
		if( test_char == 1260 ) { return true; }
		if( test_char == 1262 ) { return true; }
		if( test_char == 1264 ) { return true; }
		if( test_char == 1266 ) { return true; }
		if( test_char == 1268 ) { return true; }
		if( test_char == 1270 ) { return true; }
		if( test_char == 1272 ) { return true; }
		if( test_char == 1274 ) { return true; }
		if( test_char == 1276 ) { return true; }
		if( test_char == 1278 ) { return true; }
		if( test_char == 1280 ) { return true; }
		if( test_char == 1282 ) { return true; }
		if( test_char == 1284 ) { return true; }
		if( test_char == 1286 ) { return true; }
		if( test_char == 1288 ) { return true; }
		if( test_char == 1290 ) { return true; }
		if( test_char == 1292 ) { return true; }
		if( test_char == 1294 ) { return true; }
		if( test_char == 1296 ) { return true; }
		if( test_char == 1298 ) { return true; }
		if( test_char == 1300 ) { return true; }
		if( test_char == 1302 ) { return true; }
		if( test_char == 1304 ) { return true; }
		if( test_char == 1306 ) { return true; }
		if( test_char == 1308 ) { return true; }
		if( test_char == 1310 ) { return true; }
		if( test_char == 1312 ) { return true; }
		if( test_char == 1314 ) { return true; }
		if( test_char == 1316 ) { return true; }
		if( test_char == 1318 ) { return true; }
		if( test_char == 1320 ) { return true; }
		if( test_char == 1322 ) { return true; }
		if( test_char == 1324 ) { return true; }
		if( test_char == 1326 ) { return true; }
		if( test_char >= 1329 && test_char < 1367 ) { return true; }
		if( test_char >= 4256 && test_char < 4294 ) { return true; }
		if( test_char == 4295 ) { return true; }
		if( test_char == 4301 ) { return true; }
		if( test_char >= 5024 && test_char < 5110 ) { return true; }
		if( test_char >= 7312 && test_char < 7355 ) { return true; }
		if( test_char >= 7357 && test_char < 7360 ) { return true; }
		if( test_char == 7680 ) { return true; }
		if( test_char == 7682 ) { return true; }
		if( test_char == 7684 ) { return true; }
		if( test_char == 7686 ) { return true; }
		if( test_char == 7688 ) { return true; }
		if( test_char == 7690 ) { return true; }
		if( test_char == 7692 ) { return true; }
		if( test_char == 7694 ) { return true; }
		if( test_char == 7696 ) { return true; }
		if( test_char == 7698 ) { return true; }
		if( test_char == 7700 ) { return true; }
		if( test_char == 7702 ) { return true; }
		if( test_char == 7704 ) { return true; }
		if( test_char == 7706 ) { return true; }
		if( test_char == 7708 ) { return true; }
		if( test_char == 7710 ) { return true; }
		if( test_char == 7712 ) { return true; }
		if( test_char == 7714 ) { return true; }
		if( test_char == 7716 ) { return true; }
		if( test_char == 7718 ) { return true; }
		if( test_char == 7720 ) { return true; }
		if( test_char == 7722 ) { return true; }
		if( test_char == 7724 ) { return true; }
		if( test_char == 7726 ) { return true; }
		if( test_char == 7728 ) { return true; }
		if( test_char == 7730 ) { return true; }
		if( test_char == 7732 ) { return true; }
		if( test_char == 7734 ) { return true; }
		if( test_char == 7736 ) { return true; }
		if( test_char == 7738 ) { return true; }
		if( test_char == 7740 ) { return true; }
		if( test_char == 7742 ) { return true; }
		if( test_char == 7744 ) { return true; }
		if( test_char == 7746 ) { return true; }
		if( test_char == 7748 ) { return true; }
		if( test_char == 7750 ) { return true; }
		if( test_char == 7752 ) { return true; }
		if( test_char == 7754 ) { return true; }
		if( test_char == 7756 ) { return true; }
		if( test_char == 7758 ) { return true; }
		if( test_char == 7760 ) { return true; }
		if( test_char == 7762 ) { return true; }
		if( test_char == 7764 ) { return true; }
		if( test_char == 7766 ) { return true; }
		if( test_char == 7768 ) { return true; }
		if( test_char == 7770 ) { return true; }
		if( test_char == 7772 ) { return true; }
		if( test_char == 7774 ) { return true; }
		if( test_char == 7776 ) { return true; }
		if( test_char == 7778 ) { return true; }
		if( test_char == 7780 ) { return true; }
		if( test_char == 7782 ) { return true; }
		if( test_char == 7784 ) { return true; }
		if( test_char == 7786 ) { return true; }
		if( test_char == 7788 ) { return true; }
		if( test_char == 7790 ) { return true; }
		if( test_char == 7792 ) { return true; }
		if( test_char == 7794 ) { return true; }
		if( test_char == 7796 ) { return true; }
		if( test_char == 7798 ) { return true; }
		if( test_char == 7800 ) { return true; }
		if( test_char == 7802 ) { return true; }
		if( test_char == 7804 ) { return true; }
		if( test_char == 7806 ) { return true; }
		if( test_char == 7808 ) { return true; }
		if( test_char == 7810 ) { return true; }
		if( test_char == 7812 ) { return true; }
		if( test_char == 7814 ) { return true; }
		if( test_char == 7816 ) { return true; }
		if( test_char == 7818 ) { return true; }
		if( test_char == 7820 ) { return true; }
		if( test_char == 7822 ) { return true; }
		if( test_char == 7824 ) { return true; }
		if( test_char == 7826 ) { return true; }
		if( test_char == 7828 ) { return true; }
		if( test_char == 7838 ) { return true; }
		if( test_char == 7840 ) { return true; }
		if( test_char == 7842 ) { return true; }
		if( test_char == 7844 ) { return true; }
		if( test_char == 7846 ) { return true; }
		if( test_char == 7848 ) { return true; }
		if( test_char == 7850 ) { return true; }
		if( test_char == 7852 ) { return true; }
		if( test_char == 7854 ) { return true; }
		if( test_char == 7856 ) { return true; }
		if( test_char == 7858 ) { return true; }
		if( test_char == 7860 ) { return true; }
		if( test_char == 7862 ) { return true; }
		if( test_char == 7864 ) { return true; }
		if( test_char == 7866 ) { return true; }
		if( test_char == 7868 ) { return true; }
		if( test_char == 7870 ) { return true; }
		if( test_char == 7872 ) { return true; }
		if( test_char == 7874 ) { return true; }
		if( test_char == 7876 ) { return true; }
		if( test_char == 7878 ) { return true; }
		if( test_char == 7880 ) { return true; }
		if( test_char == 7882 ) { return true; }
		if( test_char == 7884 ) { return true; }
		if( test_char == 7886 ) { return true; }
		if( test_char == 7888 ) { return true; }
		if( test_char == 7890 ) { return true; }
		if( test_char == 7892 ) { return true; }
		if( test_char == 7894 ) { return true; }
		if( test_char == 7896 ) { return true; }
		if( test_char == 7898 ) { return true; }
		if( test_char == 7900 ) { return true; }
		if( test_char == 7902 ) { return true; }
		if( test_char == 7904 ) { return true; }
		if( test_char == 7906 ) { return true; }
		if( test_char == 7908 ) { return true; }
		if( test_char == 7910 ) { return true; }
		if( test_char == 7912 ) { return true; }
		if( test_char == 7914 ) { return true; }
		if( test_char == 7916 ) { return true; }
		if( test_char == 7918 ) { return true; }
		if( test_char == 7920 ) { return true; }
		if( test_char == 7922 ) { return true; }
		if( test_char == 7924 ) { return true; }
		if( test_char == 7926 ) { return true; }
		if( test_char == 7928 ) { return true; }
		if( test_char == 7930 ) { return true; }
		if( test_char == 7932 ) { return true; }
		if( test_char == 7934 ) { return true; }
		if( test_char >= 7944 && test_char < 7952 ) { return true; }
		if( test_char >= 7960 && test_char < 7966 ) { return true; }
		if( test_char >= 7976 && test_char < 7984 ) { return true; }
		if( test_char >= 7992 && test_char < 8000 ) { return true; }
		if( test_char >= 8008 && test_char < 8014 ) { return true; }
		if( test_char == 8025 ) { return true; }
		if( test_char == 8027 ) { return true; }
		if( test_char == 8029 ) { return true; }
		if( test_char == 8031 ) { return true; }
		if( test_char >= 8040 && test_char < 8048 ) { return true; }
		if( test_char >= 8072 && test_char < 8080 ) { return true; }
		if( test_char >= 8088 && test_char < 8096 ) { return true; }
		if( test_char >= 8104 && test_char < 8112 ) { return true; }
		if( test_char >= 8120 && test_char < 8125 ) { return true; }
		if( test_char >= 8136 && test_char < 8141 ) { return true; }
		if( test_char >= 8152 && test_char < 8156 ) { return true; }
		if( test_char >= 8168 && test_char < 8173 ) { return true; }
		if( test_char >= 8184 && test_char < 8189 ) { return true; }
		if( test_char == 8450 ) { return true; }
		if( test_char == 8455 ) { return true; }
		if( test_char >= 8459 && test_char < 8462 ) { return true; }
		if( test_char >= 8464 && test_char < 8467 ) { return true; }
		if( test_char == 8469 ) { return true; }
		if( test_char >= 8473 && test_char < 8478 ) { return true; }
		if( test_char == 8484 ) { return true; }
		if( test_char == 8486 ) { return true; }
		if( test_char == 8488 ) { return true; }
		if( test_char >= 8490 && test_char < 8494 ) { return true; }
		if( test_char >= 8496 && test_char < 8500 ) { return true; }
		if( test_char >= 8510 && test_char < 8512 ) { return true; }
		if( test_char == 8517 ) { return true; }
		if( test_char >= 8544 && test_char < 8560 ) { return true; }
		if( test_char == 8579 ) { return true; }
		if( test_char >= 9398 && test_char < 9424 ) { return true; }
		if( test_char >= 11264 && test_char < 11312 ) { return true; }
		if( test_char == 11360 ) { return true; }
		if( test_char >= 11362 && test_char < 11365 ) { return true; }
		if( test_char == 11367 ) { return true; }
		if( test_char == 11369 ) { return true; }
		if( test_char == 11371 ) { return true; }
		if( test_char >= 11373 && test_char < 11377 ) { return true; }
		if( test_char == 11378 ) { return true; }
		if( test_char == 11381 ) { return true; }
		if( test_char >= 11390 && test_char < 11393 ) { return true; }
		if( test_char == 11394 ) { return true; }
		if( test_char == 11396 ) { return true; }
		if( test_char == 11398 ) { return true; }
		if( test_char == 11400 ) { return true; }
		if( test_char == 11402 ) { return true; }
		if( test_char == 11404 ) { return true; }
		if( test_char == 11406 ) { return true; }
		if( test_char == 11408 ) { return true; }
		if( test_char == 11410 ) { return true; }
		if( test_char == 11412 ) { return true; }
		if( test_char == 11414 ) { return true; }
		if( test_char == 11416 ) { return true; }
		if( test_char == 11418 ) { return true; }
		if( test_char == 11420 ) { return true; }
		if( test_char == 11422 ) { return true; }
		if( test_char == 11424 ) { return true; }
		if( test_char == 11426 ) { return true; }
		if( test_char == 11428 ) { return true; }
		if( test_char == 11430 ) { return true; }
		if( test_char == 11432 ) { return true; }
		if( test_char == 11434 ) { return true; }
		if( test_char == 11436 ) { return true; }
		if( test_char == 11438 ) { return true; }
		if( test_char == 11440 ) { return true; }
		if( test_char == 11442 ) { return true; }
		if( test_char == 11444 ) { return true; }
		if( test_char == 11446 ) { return true; }
		if( test_char == 11448 ) { return true; }
		if( test_char == 11450 ) { return true; }
		if( test_char == 11452 ) { return true; }
		if( test_char == 11454 ) { return true; }
		if( test_char == 11456 ) { return true; }
		if( test_char == 11458 ) { return true; }
		if( test_char == 11460 ) { return true; }
		if( test_char == 11462 ) { return true; }
		if( test_char == 11464 ) { return true; }
		if( test_char == 11466 ) { return true; }
		if( test_char == 11468 ) { return true; }
		if( test_char == 11470 ) { return true; }
		if( test_char == 11472 ) { return true; }
		if( test_char == 11474 ) { return true; }
		if( test_char == 11476 ) { return true; }
		if( test_char == 11478 ) { return true; }
		if( test_char == 11480 ) { return true; }
		if( test_char == 11482 ) { return true; }
		if( test_char == 11484 ) { return true; }
		if( test_char == 11486 ) { return true; }
		if( test_char == 11488 ) { return true; }
		if( test_char == 11490 ) { return true; }
		if( test_char == 11499 ) { return true; }
		if( test_char == 11501 ) { return true; }
		if( test_char == 11506 ) { return true; }
		if( test_char == 42560 ) { return true; }
		if( test_char == 42562 ) { return true; }
		if( test_char == 42564 ) { return true; }
		if( test_char == 42566 ) { return true; }
		if( test_char == 42568 ) { return true; }
		if( test_char == 42570 ) { return true; }
		if( test_char == 42572 ) { return true; }
		if( test_char == 42574 ) { return true; }
		if( test_char == 42576 ) { return true; }
		if( test_char == 42578 ) { return true; }
		if( test_char == 42580 ) { return true; }
		if( test_char == 42582 ) { return true; }
		if( test_char == 42584 ) { return true; }
		if( test_char == 42586 ) { return true; }
		if( test_char == 42588 ) { return true; }
		if( test_char == 42590 ) { return true; }
		if( test_char == 42592 ) { return true; }
		if( test_char == 42594 ) { return true; }
		if( test_char == 42596 ) { return true; }
		if( test_char == 42598 ) { return true; }
		if( test_char == 42600 ) { return true; }
		if( test_char == 42602 ) { return true; }
		if( test_char == 42604 ) { return true; }
		if( test_char == 42624 ) { return true; }
		if( test_char == 42626 ) { return true; }
		if( test_char == 42628 ) { return true; }
		if( test_char == 42630 ) { return true; }
		if( test_char == 42632 ) { return true; }
		if( test_char == 42634 ) { return true; }
		if( test_char == 42636 ) { return true; }
		if( test_char == 42638 ) { return true; }
		if( test_char == 42640 ) { return true; }
		if( test_char == 42642 ) { return true; }
		if( test_char == 42644 ) { return true; }
		if( test_char == 42646 ) { return true; }
		if( test_char == 42648 ) { return true; }
		if( test_char == 42650 ) { return true; }
		if( test_char == 42786 ) { return true; }
		if( test_char == 42788 ) { return true; }
		if( test_char == 42790 ) { return true; }
		if( test_char == 42792 ) { return true; }
		if( test_char == 42794 ) { return true; }
		if( test_char == 42796 ) { return true; }
		if( test_char == 42798 ) { return true; }
		if( test_char == 42802 ) { return true; }
		if( test_char == 42804 ) { return true; }
		if( test_char == 42806 ) { return true; }
		if( test_char == 42808 ) { return true; }
		if( test_char == 42810 ) { return true; }
		if( test_char == 42812 ) { return true; }
		if( test_char == 42814 ) { return true; }
		if( test_char == 42816 ) { return true; }
		if( test_char == 42818 ) { return true; }
		if( test_char == 42820 ) { return true; }
		if( test_char == 42822 ) { return true; }
		if( test_char == 42824 ) { return true; }
		if( test_char == 42826 ) { return true; }
		if( test_char == 42828 ) { return true; }
		if( test_char == 42830 ) { return true; }
		if( test_char == 42832 ) { return true; }
		if( test_char == 42834 ) { return true; }
		if( test_char == 42836 ) { return true; }
		if( test_char == 42838 ) { return true; }
		if( test_char == 42840 ) { return true; }
		if( test_char == 42842 ) { return true; }
		if( test_char == 42844 ) { return true; }
		if( test_char == 42846 ) { return true; }
		if( test_char == 42848 ) { return true; }
		if( test_char == 42850 ) { return true; }
		if( test_char == 42852 ) { return true; }
		if( test_char == 42854 ) { return true; }
		if( test_char == 42856 ) { return true; }
		if( test_char == 42858 ) { return true; }
		if( test_char == 42860 ) { return true; }
		if( test_char == 42862 ) { return true; }
		if( test_char == 42873 ) { return true; }
		if( test_char == 42875 ) { return true; }
		if( test_char >= 42877 && test_char < 42879 ) { return true; }
		if( test_char == 42880 ) { return true; }
		if( test_char == 42882 ) { return true; }
		if( test_char == 42884 ) { return true; }
		if( test_char == 42886 ) { return true; }
		if( test_char == 42891 ) { return true; }
		if( test_char == 42893 ) { return true; }
		if( test_char == 42896 ) { return true; }
		if( test_char == 42898 ) { return true; }
		if( test_char == 42902 ) { return true; }
		if( test_char == 42904 ) { return true; }
		if( test_char == 42906 ) { return true; }
		if( test_char == 42908 ) { return true; }
		if( test_char == 42910 ) { return true; }
		if( test_char == 42912 ) { return true; }
		if( test_char == 42914 ) { return true; }
		if( test_char == 42916 ) { return true; }
		if( test_char == 42918 ) { return true; }
		if( test_char == 42920 ) { return true; }
		if( test_char >= 42922 && test_char < 42927 ) { return true; }
		if( test_char >= 42928 && test_char < 42933 ) { return true; }
		if( test_char == 42934 ) { return true; }
		if( test_char == 42936 ) { return true; }
		if( test_char == 42938 ) { return true; }
		if( test_char == 42940 ) { return true; }
		if( test_char == 42942 ) { return true; }
		if( test_char == 42944 ) { return true; }
		if( test_char == 42946 ) { return true; }
		if( test_char >= 42948 && test_char < 42952 ) { return true; }
		if( test_char == 42953 ) { return true; }
		if( test_char == 42960 ) { return true; }
		if( test_char == 42966 ) { return true; }
		if( test_char == 42968 ) { return true; }
		if( test_char == 42997 ) { return true; }
		if( test_char >= 65313 && test_char < 65339 ) { return true; }
		if( test_char >= 66560 && test_char < 66600 ) { return true; }
		if( test_char >= 66736 && test_char < 66772 ) { return true; }
		if( test_char >= 66928 && test_char < 66939 ) { return true; }
		if( test_char >= 66940 && test_char < 66955 ) { return true; }
		if( test_char >= 66956 && test_char < 66963 ) { return true; }
		if( test_char >= 66964 && test_char < 66966 ) { return true; }
		if( test_char >= 68736 && test_char < 68787 ) { return true; }
		if( test_char >= 71840 && test_char < 71872 ) { return true; }
		if( test_char >= 93760 && test_char < 93792 ) { return true; }
		if( test_char >= 119808 && test_char < 119834 ) { return true; }
		if( test_char >= 119860 && test_char < 119886 ) { return true; }
		if( test_char >= 119912 && test_char < 119938 ) { return true; }
		if( test_char == 119964 ) { return true; }
		if( test_char >= 119966 && test_char < 119968 ) { return true; }
		if( test_char == 119970 ) { return true; }
		if( test_char >= 119973 && test_char < 119975 ) { return true; }
		if( test_char >= 119977 && test_char < 119981 ) { return true; }
		if( test_char >= 119982 && test_char < 119990 ) { return true; }
		if( test_char >= 120016 && test_char < 120042 ) { return true; }
		if( test_char >= 120068 && test_char < 120070 ) { return true; }
		if( test_char >= 120071 && test_char < 120075 ) { return true; }
		if( test_char >= 120077 && test_char < 120085 ) { return true; }
		if( test_char >= 120086 && test_char < 120093 ) { return true; }
		if( test_char >= 120120 && test_char < 120122 ) { return true; }
		if( test_char >= 120123 && test_char < 120127 ) { return true; }
		if( test_char >= 120128 && test_char < 120133 ) { return true; }
		if( test_char == 120134 ) { return true; }
		if( test_char >= 120138 && test_char < 120145 ) { return true; }
		if( test_char >= 120172 && test_char < 120198 ) { return true; }
		if( test_char >= 120224 && test_char < 120250 ) { return true; }
		if( test_char >= 120276 && test_char < 120302 ) { return true; }
		if( test_char >= 120328 && test_char < 120354 ) { return true; }
		if( test_char >= 120380 && test_char < 120406 ) { return true; }
		if( test_char >= 120432 && test_char < 120458 ) { return true; }
		if( test_char >= 120488 && test_char < 120513 ) { return true; }
		if( test_char >= 120546 && test_char < 120571 ) { return true; }
		if( test_char >= 120604 && test_char < 120629 ) { return true; }
		if( test_char >= 120662 && test_char < 120687 ) { return true; }
		if( test_char >= 120720 && test_char < 120745 ) { return true; }
		if( test_char == 120778 ) { return true; }
		if( test_char >= 125184 && test_char < 125218 ) { return true; }
		if( test_char >= 127280 && test_char < 127306 ) { return true; }
		if( test_char >= 127312 && test_char < 127338 ) { return true; }
		if( test_char >= 127344 && test_char < 127370 ) { return true; }

		return false;
	}
	
	bool is_upper_case(char32_t test_char) noexcept {
		if( test_char >= 65 && test_char < 91 ) { return true; }
		if( test_char >= 192 && test_char < 215 ) { return true; }
		if( test_char >= 216 && test_char < 223 ) { return true; }
		if( test_char == 256 ) { return true; }
		if( test_char == 258 ) { return true; }
		if( test_char == 260 ) { return true; }
		if( test_char == 262 ) { return true; }
		if( test_char == 264 ) { return true; }
		if( test_char == 266 ) { return true; }
		if( test_char == 268 ) { return true; }
		if( test_char == 270 ) { return true; }
		if( test_char == 272 ) { return true; }
		if( test_char == 274 ) { return true; }
		if( test_char == 276 ) { return true; }
		if( test_char == 278 ) { return true; }
		if( test_char == 280 ) { return true; }
		if( test_char == 282 ) { return true; }
		if( test_char == 284 ) { return true; }
		if( test_char == 286 ) { return true; }
		if( test_char == 288 ) { return true; }
		if( test_char == 290 ) { return true; }
		if( test_char == 292 ) { return true; }
		if( test_char == 294 ) { return true; }
		if( test_char == 296 ) { return true; }
		if( test_char == 298 ) { return true; }
		if( test_char == 300 ) { return true; }
		if( test_char == 302 ) { return true; }
		if( test_char == 304 ) { return true; }
		if( test_char == 306 ) { return true; }
		if( test_char == 308 ) { return true; }
		if( test_char == 310 ) { return true; }
		if( test_char == 313 ) { return true; }
		if( test_char == 315 ) { return true; }
		if( test_char == 317 ) { return true; }
		if( test_char == 319 ) { return true; }
		if( test_char == 321 ) { return true; }
		if( test_char == 323 ) { return true; }
		if( test_char == 325 ) { return true; }
		if( test_char == 327 ) { return true; }
		if( test_char == 330 ) { return true; }
		if( test_char == 332 ) { return true; }
		if( test_char == 334 ) { return true; }
		if( test_char == 336 ) { return true; }
		if( test_char == 338 ) { return true; }
		if( test_char == 340 ) { return true; }
		if( test_char == 342 ) { return true; }
		if( test_char == 344 ) { return true; }
		if( test_char == 346 ) { return true; }
		if( test_char == 348 ) { return true; }
		if( test_char == 350 ) { return true; }
		if( test_char == 352 ) { return true; }
		if( test_char == 354 ) { return true; }
		if( test_char == 356 ) { return true; }
		if( test_char == 358 ) { return true; }
		if( test_char == 360 ) { return true; }
		if( test_char == 362 ) { return true; }
		if( test_char == 364 ) { return true; }
		if( test_char == 366 ) { return true; }
		if( test_char == 368 ) { return true; }
		if( test_char == 370 ) { return true; }
		if( test_char == 372 ) { return true; }
		if( test_char == 374 ) { return true; }
		if( test_char >= 376 && test_char < 378 ) { return true; }
		if( test_char == 379 ) { return true; }
		if( test_char == 381 ) { return true; }
		if( test_char >= 385 && test_char < 387 ) { return true; }
		if( test_char == 388 ) { return true; }
		if( test_char >= 390 && test_char < 392 ) { return true; }
		if( test_char >= 393 && test_char < 396 ) { return true; }
		if( test_char >= 398 && test_char < 402 ) { return true; }
		if( test_char >= 403 && test_char < 405 ) { return true; }
		if( test_char >= 406 && test_char < 409 ) { return true; }
		if( test_char >= 412 && test_char < 414 ) { return true; }
		if( test_char >= 415 && test_char < 417 ) { return true; }
		if( test_char == 418 ) { return true; }
		if( test_char == 420 ) { return true; }
		if( test_char >= 422 && test_char < 424 ) { return true; }
		if( test_char == 425 ) { return true; }
		if( test_char == 428 ) { return true; }
		if( test_char >= 430 && test_char < 432 ) { return true; }
		if( test_char >= 433 && test_char < 436 ) { return true; }
		if( test_char == 437 ) { return true; }
		if( test_char >= 439 && test_char < 441 ) { return true; }
		if( test_char == 444 ) { return true; }
		if( test_char == 452 ) { return true; }
		if( test_char == 455 ) { return true; }
		if( test_char == 458 ) { return true; }
		if( test_char == 461 ) { return true; }
		if( test_char == 463 ) { return true; }
		if( test_char == 465 ) { return true; }
		if( test_char == 467 ) { return true; }
		if( test_char == 469 ) { return true; }
		if( test_char == 471 ) { return true; }
		if( test_char == 473 ) { return true; }
		if( test_char == 475 ) { return true; }
		if( test_char == 478 ) { return true; }
		if( test_char == 480 ) { return true; }
		if( test_char == 482 ) { return true; }
		if( test_char == 484 ) { return true; }
		if( test_char == 486 ) { return true; }
		if( test_char == 488 ) { return true; }
		if( test_char == 490 ) { return true; }
		if( test_char == 492 ) { return true; }
		if( test_char == 494 ) { return true; }
		if( test_char == 497 ) { return true; }
		if( test_char == 500 ) { return true; }
		if( test_char >= 502 && test_char < 505 ) { return true; }
		if( test_char == 506 ) { return true; }
		if( test_char == 508 ) { return true; }
		if( test_char == 510 ) { return true; }
		if( test_char == 512 ) { return true; }
		if( test_char == 514 ) { return true; }
		if( test_char == 516 ) { return true; }
		if( test_char == 518 ) { return true; }
		if( test_char == 520 ) { return true; }
		if( test_char == 522 ) { return true; }
		if( test_char == 524 ) { return true; }
		if( test_char == 526 ) { return true; }
		if( test_char == 528 ) { return true; }
		if( test_char == 530 ) { return true; }
		if( test_char == 532 ) { return true; }
		if( test_char == 534 ) { return true; }
		if( test_char == 536 ) { return true; }
		if( test_char == 538 ) { return true; }
		if( test_char == 540 ) { return true; }
		if( test_char == 542 ) { return true; }
		if( test_char == 544 ) { return true; }
		if( test_char == 546 ) { return true; }
		if( test_char == 548 ) { return true; }
		if( test_char == 550 ) { return true; }
		if( test_char == 552 ) { return true; }
		if( test_char == 554 ) { return true; }
		if( test_char == 556 ) { return true; }
		if( test_char == 558 ) { return true; }
		if( test_char == 560 ) { return true; }
		if( test_char == 562 ) { return true; }
		if( test_char >= 570 && test_char < 572 ) { return true; }
		if( test_char >= 573 && test_char < 575 ) { return true; }
		if( test_char == 577 ) { return true; }
		if( test_char >= 579 && test_char < 583 ) { return true; }
		if( test_char == 584 ) { return true; }
		if( test_char == 586 ) { return true; }
		if( test_char == 588 ) { return true; }
		if( test_char == 590 ) { return true; }
		if( test_char == 880 ) { return true; }
		if( test_char == 882 ) { return true; }
		if( test_char == 886 ) { return true; }
		if( test_char == 895 ) { return true; }
		if( test_char == 902 ) { return true; }
		if( test_char >= 904 && test_char < 907 ) { return true; }
		if( test_char == 908 ) { return true; }
		if( test_char >= 910 && test_char < 912 ) { return true; }
		if( test_char >= 913 && test_char < 930 ) { return true; }
		if( test_char >= 931 && test_char < 940 ) { return true; }
		if( test_char == 975 ) { return true; }
		if( test_char >= 978 && test_char < 981 ) { return true; }
		if( test_char == 984 ) { return true; }
		if( test_char == 986 ) { return true; }
		if( test_char == 988 ) { return true; }
		if( test_char == 990 ) { return true; }
		if( test_char == 992 ) { return true; }
		if( test_char == 994 ) { return true; }
		if( test_char == 996 ) { return true; }
		if( test_char == 998 ) { return true; }
		if( test_char == 1000 ) { return true; }
		if( test_char == 1002 ) { return true; }
		if( test_char == 1004 ) { return true; }
		if( test_char == 1006 ) { return true; }
		if( test_char == 1012 ) { return true; }
		if( test_char == 1015 ) { return true; }
		if( test_char >= 1017 && test_char < 1019 ) { return true; }
		if( test_char >= 1021 && test_char < 1072 ) { return true; }
		if( test_char == 1120 ) { return true; }
		if( test_char == 1122 ) { return true; }
		if( test_char == 1124 ) { return true; }
		if( test_char == 1126 ) { return true; }
		if( test_char == 1128 ) { return true; }
		if( test_char == 1130 ) { return true; }
		if( test_char == 1132 ) { return true; }
		if( test_char == 1134 ) { return true; }
		if( test_char == 1136 ) { return true; }
		if( test_char == 1138 ) { return true; }
		if( test_char == 1140 ) { return true; }
		if( test_char == 1142 ) { return true; }
		if( test_char == 1144 ) { return true; }
		if( test_char == 1146 ) { return true; }
		if( test_char == 1148 ) { return true; }
		if( test_char == 1150 ) { return true; }
		if( test_char == 1152 ) { return true; }
		if( test_char == 1162 ) { return true; }
		if( test_char == 1164 ) { return true; }
		if( test_char == 1166 ) { return true; }
		if( test_char == 1168 ) { return true; }
		if( test_char == 1170 ) { return true; }
		if( test_char == 1172 ) { return true; }
		if( test_char == 1174 ) { return true; }
		if( test_char == 1176 ) { return true; }
		if( test_char == 1178 ) { return true; }
		if( test_char == 1180 ) { return true; }
		if( test_char == 1182 ) { return true; }
		if( test_char == 1184 ) { return true; }
		if( test_char == 1186 ) { return true; }
		if( test_char == 1188 ) { return true; }
		if( test_char == 1190 ) { return true; }
		if( test_char == 1192 ) { return true; }
		if( test_char == 1194 ) { return true; }
		if( test_char == 1196 ) { return true; }
		if( test_char == 1198 ) { return true; }
		if( test_char == 1200 ) { return true; }
		if( test_char == 1202 ) { return true; }
		if( test_char == 1204 ) { return true; }
		if( test_char == 1206 ) { return true; }
		if( test_char == 1208 ) { return true; }
		if( test_char == 1210 ) { return true; }
		if( test_char == 1212 ) { return true; }
		if( test_char == 1214 ) { return true; }
		if( test_char >= 1216 && test_char < 1218 ) { return true; }
		if( test_char == 1219 ) { return true; }
		if( test_char == 1221 ) { return true; }
		if( test_char == 1223 ) { return true; }
		if( test_char == 1225 ) { return true; }
		if( test_char == 1227 ) { return true; }
		if( test_char == 1229 ) { return true; }
		if( test_char == 1232 ) { return true; }
		if( test_char == 1234 ) { return true; }
		if( test_char == 1236 ) { return true; }
		if( test_char == 1238 ) { return true; }
		if( test_char == 1240 ) { return true; }
		if( test_char == 1242 ) { return true; }
		if( test_char == 1244 ) { return true; }
		if( test_char == 1246 ) { return true; }
		if( test_char == 1248 ) { return true; }
		if( test_char == 1250 ) { return true; }
		if( test_char == 1252 ) { return true; }
		if( test_char == 1254 ) { return true; }
		if( test_char == 1256 ) { return true; }
		if( test_char == 1258 ) { return true; }
		if( test_char == 1260 ) { return true; }
		if( test_char == 1262 ) { return true; }
		if( test_char == 1264 ) { return true; }
		if( test_char == 1266 ) { return true; }
		if( test_char == 1268 ) { return true; }
		if( test_char == 1270 ) { return true; }
		if( test_char == 1272 ) { return true; }
		if( test_char == 1274 ) { return true; }
		if( test_char == 1276 ) { return true; }
		if( test_char == 1278 ) { return true; }
		if( test_char == 1280 ) { return true; }
		if( test_char == 1282 ) { return true; }
		if( test_char == 1284 ) { return true; }
		if( test_char == 1286 ) { return true; }
		if( test_char == 1288 ) { return true; }
		if( test_char == 1290 ) { return true; }
		if( test_char == 1292 ) { return true; }
		if( test_char == 1294 ) { return true; }
		if( test_char == 1296 ) { return true; }
		if( test_char == 1298 ) { return true; }
		if( test_char == 1300 ) { return true; }
		if( test_char == 1302 ) { return true; }
		if( test_char == 1304 ) { return true; }
		if( test_char == 1306 ) { return true; }
		if( test_char == 1308 ) { return true; }
		if( test_char == 1310 ) { return true; }
		if( test_char == 1312 ) { return true; }
		if( test_char == 1314 ) { return true; }
		if( test_char == 1316 ) { return true; }
		if( test_char == 1318 ) { return true; }
		if( test_char == 1320 ) { return true; }
		if( test_char == 1322 ) { return true; }
		if( test_char == 1324 ) { return true; }
		if( test_char == 1326 ) { return true; }
		if( test_char >= 1329 && test_char < 1367 ) { return true; }
		if( test_char >= 4256 && test_char < 4294 ) { return true; }
		if( test_char == 4295 ) { return true; }
		if( test_char == 4301 ) { return true; }
		if( test_char >= 5024 && test_char < 5110 ) { return true; }
		if( test_char >= 7312 && test_char < 7355 ) { return true; }
		if( test_char >= 7357 && test_char < 7360 ) { return true; }
		if( test_char == 7680 ) { return true; }
		if( test_char == 7682 ) { return true; }
		if( test_char == 7684 ) { return true; }
		if( test_char == 7686 ) { return true; }
		if( test_char == 7688 ) { return true; }
		if( test_char == 7690 ) { return true; }
		if( test_char == 7692 ) { return true; }
		if( test_char == 7694 ) { return true; }
		if( test_char == 7696 ) { return true; }
		if( test_char == 7698 ) { return true; }
		if( test_char == 7700 ) { return true; }
		if( test_char == 7702 ) { return true; }
		if( test_char == 7704 ) { return true; }
		if( test_char == 7706 ) { return true; }
		if( test_char == 7708 ) { return true; }
		if( test_char == 7710 ) { return true; }
		if( test_char == 7712 ) { return true; }
		if( test_char == 7714 ) { return true; }
		if( test_char == 7716 ) { return true; }
		if( test_char == 7718 ) { return true; }
		if( test_char == 7720 ) { return true; }
		if( test_char == 7722 ) { return true; }
		if( test_char == 7724 ) { return true; }
		if( test_char == 7726 ) { return true; }
		if( test_char == 7728 ) { return true; }
		if( test_char == 7730 ) { return true; }
		if( test_char == 7732 ) { return true; }
		if( test_char == 7734 ) { return true; }
		if( test_char == 7736 ) { return true; }
		if( test_char == 7738 ) { return true; }
		if( test_char == 7740 ) { return true; }
		if( test_char == 7742 ) { return true; }
		if( test_char == 7744 ) { return true; }
		if( test_char == 7746 ) { return true; }
		if( test_char == 7748 ) { return true; }
		if( test_char == 7750 ) { return true; }
		if( test_char == 7752 ) { return true; }
		if( test_char == 7754 ) { return true; }
		if( test_char == 7756 ) { return true; }
		if( test_char == 7758 ) { return true; }
		if( test_char == 7760 ) { return true; }
		if( test_char == 7762 ) { return true; }
		if( test_char == 7764 ) { return true; }
		if( test_char == 7766 ) { return true; }
		if( test_char == 7768 ) { return true; }
		if( test_char == 7770 ) { return true; }
		if( test_char == 7772 ) { return true; }
		if( test_char == 7774 ) { return true; }
		if( test_char == 7776 ) { return true; }
		if( test_char == 7778 ) { return true; }
		if( test_char == 7780 ) { return true; }
		if( test_char == 7782 ) { return true; }
		if( test_char == 7784 ) { return true; }
		if( test_char == 7786 ) { return true; }
		if( test_char == 7788 ) { return true; }
		if( test_char == 7790 ) { return true; }
		if( test_char == 7792 ) { return true; }
		if( test_char == 7794 ) { return true; }
		if( test_char == 7796 ) { return true; }
		if( test_char == 7798 ) { return true; }
		if( test_char == 7800 ) { return true; }
		if( test_char == 7802 ) { return true; }
		if( test_char == 7804 ) { return true; }
		if( test_char == 7806 ) { return true; }
		if( test_char == 7808 ) { return true; }
		if( test_char == 7810 ) { return true; }
		if( test_char == 7812 ) { return true; }
		if( test_char == 7814 ) { return true; }
		if( test_char == 7816 ) { return true; }
		if( test_char == 7818 ) { return true; }
		if( test_char == 7820 ) { return true; }
		if( test_char == 7822 ) { return true; }
		if( test_char == 7824 ) { return true; }
		if( test_char == 7826 ) { return true; }
		if( test_char == 7828 ) { return true; }
		if( test_char == 7838 ) { return true; }
		if( test_char == 7840 ) { return true; }
		if( test_char == 7842 ) { return true; }
		if( test_char == 7844 ) { return true; }
		if( test_char == 7846 ) { return true; }
		if( test_char == 7848 ) { return true; }
		if( test_char == 7850 ) { return true; }
		if( test_char == 7852 ) { return true; }
		if( test_char == 7854 ) { return true; }
		if( test_char == 7856 ) { return true; }
		if( test_char == 7858 ) { return true; }
		if( test_char == 7860 ) { return true; }
		if( test_char == 7862 ) { return true; }
		if( test_char == 7864 ) { return true; }
		if( test_char == 7866 ) { return true; }
		if( test_char == 7868 ) { return true; }
		if( test_char == 7870 ) { return true; }
		if( test_char == 7872 ) { return true; }
		if( test_char == 7874 ) { return true; }
		if( test_char == 7876 ) { return true; }
		if( test_char == 7878 ) { return true; }
		if( test_char == 7880 ) { return true; }
		if( test_char == 7882 ) { return true; }
		if( test_char == 7884 ) { return true; }
		if( test_char == 7886 ) { return true; }
		if( test_char == 7888 ) { return true; }
		if( test_char == 7890 ) { return true; }
		if( test_char == 7892 ) { return true; }
		if( test_char == 7894 ) { return true; }
		if( test_char == 7896 ) { return true; }
		if( test_char == 7898 ) { return true; }
		if( test_char == 7900 ) { return true; }
		if( test_char == 7902 ) { return true; }
		if( test_char == 7904 ) { return true; }
		if( test_char == 7906 ) { return true; }
		if( test_char == 7908 ) { return true; }
		if( test_char == 7910 ) { return true; }
		if( test_char == 7912 ) { return true; }
		if( test_char == 7914 ) { return true; }
		if( test_char == 7916 ) { return true; }
		if( test_char == 7918 ) { return true; }
		if( test_char == 7920 ) { return true; }
		if( test_char == 7922 ) { return true; }
		if( test_char == 7924 ) { return true; }
		if( test_char == 7926 ) { return true; }
		if( test_char == 7928 ) { return true; }
		if( test_char == 7930 ) { return true; }
		if( test_char == 7932 ) { return true; }
		if( test_char == 7934 ) { return true; }
		if( test_char >= 7944 && test_char < 7952 ) { return true; }
		if( test_char >= 7960 && test_char < 7966 ) { return true; }
		if( test_char >= 7976 && test_char < 7984 ) { return true; }
		if( test_char >= 7992 && test_char < 8000 ) { return true; }
		if( test_char >= 8008 && test_char < 8014 ) { return true; }
		if( test_char == 8025 ) { return true; }
		if( test_char == 8027 ) { return true; }
		if( test_char == 8029 ) { return true; }
		if( test_char == 8031 ) { return true; }
		if( test_char >= 8040 && test_char < 8048 ) { return true; }
		if( test_char >= 8120 && test_char < 8124 ) { return true; }
		if( test_char >= 8136 && test_char < 8140 ) { return true; }
		if( test_char >= 8152 && test_char < 8156 ) { return true; }
		if( test_char >= 8168 && test_char < 8173 ) { return true; }
		if( test_char >= 8184 && test_char < 8188 ) { return true; }
		if( test_char == 8450 ) { return true; }
		if( test_char == 8455 ) { return true; }
		if( test_char >= 8459 && test_char < 8462 ) { return true; }
		if( test_char >= 8464 && test_char < 8467 ) { return true; }
		if( test_char == 8469 ) { return true; }
		if( test_char >= 8473 && test_char < 8478 ) { return true; }
		if( test_char == 8484 ) { return true; }
		if( test_char == 8486 ) { return true; }
		if( test_char == 8488 ) { return true; }
		if( test_char >= 8490 && test_char < 8494 ) { return true; }
		if( test_char >= 8496 && test_char < 8500 ) { return true; }
		if( test_char >= 8510 && test_char < 8512 ) { return true; }
		if( test_char == 8517 ) { return true; }
		if( test_char >= 8544 && test_char < 8560 ) { return true; }
		if( test_char == 8579 ) { return true; }
		if( test_char >= 9398 && test_char < 9424 ) { return true; }
		if( test_char >= 11264 && test_char < 11312 ) { return true; }
		if( test_char == 11360 ) { return true; }
		if( test_char >= 11362 && test_char < 11365 ) { return true; }
		if( test_char == 11367 ) { return true; }
		if( test_char == 11369 ) { return true; }
		if( test_char == 11371 ) { return true; }
		if( test_char >= 11373 && test_char < 11377 ) { return true; }
		if( test_char == 11378 ) { return true; }
		if( test_char == 11381 ) { return true; }
		if( test_char >= 11390 && test_char < 11393 ) { return true; }
		if( test_char == 11394 ) { return true; }
		if( test_char == 11396 ) { return true; }
		if( test_char == 11398 ) { return true; }
		if( test_char == 11400 ) { return true; }
		if( test_char == 11402 ) { return true; }
		if( test_char == 11404 ) { return true; }
		if( test_char == 11406 ) { return true; }
		if( test_char == 11408 ) { return true; }
		if( test_char == 11410 ) { return true; }
		if( test_char == 11412 ) { return true; }
		if( test_char == 11414 ) { return true; }
		if( test_char == 11416 ) { return true; }
		if( test_char == 11418 ) { return true; }
		if( test_char == 11420 ) { return true; }
		if( test_char == 11422 ) { return true; }
		if( test_char == 11424 ) { return true; }
		if( test_char == 11426 ) { return true; }
		if( test_char == 11428 ) { return true; }
		if( test_char == 11430 ) { return true; }
		if( test_char == 11432 ) { return true; }
		if( test_char == 11434 ) { return true; }
		if( test_char == 11436 ) { return true; }
		if( test_char == 11438 ) { return true; }
		if( test_char == 11440 ) { return true; }
		if( test_char == 11442 ) { return true; }
		if( test_char == 11444 ) { return true; }
		if( test_char == 11446 ) { return true; }
		if( test_char == 11448 ) { return true; }
		if( test_char == 11450 ) { return true; }
		if( test_char == 11452 ) { return true; }
		if( test_char == 11454 ) { return true; }
		if( test_char == 11456 ) { return true; }
		if( test_char == 11458 ) { return true; }
		if( test_char == 11460 ) { return true; }
		if( test_char == 11462 ) { return true; }
		if( test_char == 11464 ) { return true; }
		if( test_char == 11466 ) { return true; }
		if( test_char == 11468 ) { return true; }
		if( test_char == 11470 ) { return true; }
		if( test_char == 11472 ) { return true; }
		if( test_char == 11474 ) { return true; }
		if( test_char == 11476 ) { return true; }
		if( test_char == 11478 ) { return true; }
		if( test_char == 11480 ) { return true; }
		if( test_char == 11482 ) { return true; }
		if( test_char == 11484 ) { return true; }
		if( test_char == 11486 ) { return true; }
		if( test_char == 11488 ) { return true; }
		if( test_char == 11490 ) { return true; }
		if( test_char == 11499 ) { return true; }
		if( test_char == 11501 ) { return true; }
		if( test_char == 11506 ) { return true; }
		if( test_char == 42560 ) { return true; }
		if( test_char == 42562 ) { return true; }
		if( test_char == 42564 ) { return true; }
		if( test_char == 42566 ) { return true; }
		if( test_char == 42568 ) { return true; }
		if( test_char == 42570 ) { return true; }
		if( test_char == 42572 ) { return true; }
		if( test_char == 42574 ) { return true; }
		if( test_char == 42576 ) { return true; }
		if( test_char == 42578 ) { return true; }
		if( test_char == 42580 ) { return true; }
		if( test_char == 42582 ) { return true; }
		if( test_char == 42584 ) { return true; }
		if( test_char == 42586 ) { return true; }
		if( test_char == 42588 ) { return true; }
		if( test_char == 42590 ) { return true; }
		if( test_char == 42592 ) { return true; }
		if( test_char == 42594 ) { return true; }
		if( test_char == 42596 ) { return true; }
		if( test_char == 42598 ) { return true; }
		if( test_char == 42600 ) { return true; }
		if( test_char == 42602 ) { return true; }
		if( test_char == 42604 ) { return true; }
		if( test_char == 42624 ) { return true; }
		if( test_char == 42626 ) { return true; }
		if( test_char == 42628 ) { return true; }
		if( test_char == 42630 ) { return true; }
		if( test_char == 42632 ) { return true; }
		if( test_char == 42634 ) { return true; }
		if( test_char == 42636 ) { return true; }
		if( test_char == 42638 ) { return true; }
		if( test_char == 42640 ) { return true; }
		if( test_char == 42642 ) { return true; }
		if( test_char == 42644 ) { return true; }
		if( test_char == 42646 ) { return true; }
		if( test_char == 42648 ) { return true; }
		if( test_char == 42650 ) { return true; }
		if( test_char == 42786 ) { return true; }
		if( test_char == 42788 ) { return true; }
		if( test_char == 42790 ) { return true; }
		if( test_char == 42792 ) { return true; }
		if( test_char == 42794 ) { return true; }
		if( test_char == 42796 ) { return true; }
		if( test_char == 42798 ) { return true; }
		if( test_char == 42802 ) { return true; }
		if( test_char == 42804 ) { return true; }
		if( test_char == 42806 ) { return true; }
		if( test_char == 42808 ) { return true; }
		if( test_char == 42810 ) { return true; }
		if( test_char == 42812 ) { return true; }
		if( test_char == 42814 ) { return true; }
		if( test_char == 42816 ) { return true; }
		if( test_char == 42818 ) { return true; }
		if( test_char == 42820 ) { return true; }
		if( test_char == 42822 ) { return true; }
		if( test_char == 42824 ) { return true; }
		if( test_char == 42826 ) { return true; }
		if( test_char == 42828 ) { return true; }
		if( test_char == 42830 ) { return true; }
		if( test_char == 42832 ) { return true; }
		if( test_char == 42834 ) { return true; }
		if( test_char == 42836 ) { return true; }
		if( test_char == 42838 ) { return true; }
		if( test_char == 42840 ) { return true; }
		if( test_char == 42842 ) { return true; }
		if( test_char == 42844 ) { return true; }
		if( test_char == 42846 ) { return true; }
		if( test_char == 42848 ) { return true; }
		if( test_char == 42850 ) { return true; }
		if( test_char == 42852 ) { return true; }
		if( test_char == 42854 ) { return true; }
		if( test_char == 42856 ) { return true; }
		if( test_char == 42858 ) { return true; }
		if( test_char == 42860 ) { return true; }
		if( test_char == 42862 ) { return true; }
		if( test_char == 42873 ) { return true; }
		if( test_char == 42875 ) { return true; }
		if( test_char >= 42877 && test_char < 42879 ) { return true; }
		if( test_char == 42880 ) { return true; }
		if( test_char == 42882 ) { return true; }
		if( test_char == 42884 ) { return true; }
		if( test_char == 42886 ) { return true; }
		if( test_char == 42891 ) { return true; }
		if( test_char == 42893 ) { return true; }
		if( test_char == 42896 ) { return true; }
		if( test_char == 42898 ) { return true; }
		if( test_char == 42902 ) { return true; }
		if( test_char == 42904 ) { return true; }
		if( test_char == 42906 ) { return true; }
		if( test_char == 42908 ) { return true; }
		if( test_char == 42910 ) { return true; }
		if( test_char == 42912 ) { return true; }
		if( test_char == 42914 ) { return true; }
		if( test_char == 42916 ) { return true; }
		if( test_char == 42918 ) { return true; }
		if( test_char == 42920 ) { return true; }
		if( test_char >= 42922 && test_char < 42927 ) { return true; }
		if( test_char >= 42928 && test_char < 42933 ) { return true; }
		if( test_char == 42934 ) { return true; }
		if( test_char == 42936 ) { return true; }
		if( test_char == 42938 ) { return true; }
		if( test_char == 42940 ) { return true; }
		if( test_char == 42942 ) { return true; }
		if( test_char == 42944 ) { return true; }
		if( test_char == 42946 ) { return true; }
		if( test_char >= 42948 && test_char < 42952 ) { return true; }
		if( test_char == 42953 ) { return true; }
		if( test_char == 42960 ) { return true; }
		if( test_char == 42966 ) { return true; }
		if( test_char == 42968 ) { return true; }
		if( test_char == 42997 ) { return true; }
		if( test_char >= 65313 && test_char < 65339 ) { return true; }
		if( test_char >= 66560 && test_char < 66600 ) { return true; }
		if( test_char >= 66736 && test_char < 66772 ) { return true; }
		if( test_char >= 66928 && test_char < 66939 ) { return true; }
		if( test_char >= 66940 && test_char < 66955 ) { return true; }
		if( test_char >= 66956 && test_char < 66963 ) { return true; }
		if( test_char >= 66964 && test_char < 66966 ) { return true; }
		if( test_char >= 68736 && test_char < 68787 ) { return true; }
		if( test_char >= 71840 && test_char < 71872 ) { return true; }
		if( test_char >= 93760 && test_char < 93792 ) { return true; }
		if( test_char >= 119808 && test_char < 119834 ) { return true; }
		if( test_char >= 119860 && test_char < 119886 ) { return true; }
		if( test_char >= 119912 && test_char < 119938 ) { return true; }
		if( test_char == 119964 ) { return true; }
		if( test_char >= 119966 && test_char < 119968 ) { return true; }
		if( test_char == 119970 ) { return true; }
		if( test_char >= 119973 && test_char < 119975 ) { return true; }
		if( test_char >= 119977 && test_char < 119981 ) { return true; }
		if( test_char >= 119982 && test_char < 119990 ) { return true; }
		if( test_char >= 120016 && test_char < 120042 ) { return true; }
		if( test_char >= 120068 && test_char < 120070 ) { return true; }
		if( test_char >= 120071 && test_char < 120075 ) { return true; }
		if( test_char >= 120077 && test_char < 120085 ) { return true; }
		if( test_char >= 120086 && test_char < 120093 ) { return true; }
		if( test_char >= 120120 && test_char < 120122 ) { return true; }
		if( test_char >= 120123 && test_char < 120127 ) { return true; }
		if( test_char >= 120128 && test_char < 120133 ) { return true; }
		if( test_char == 120134 ) { return true; }
		if( test_char >= 120138 && test_char < 120145 ) { return true; }
		if( test_char >= 120172 && test_char < 120198 ) { return true; }
		if( test_char >= 120224 && test_char < 120250 ) { return true; }
		if( test_char >= 120276 && test_char < 120302 ) { return true; }
		if( test_char >= 120328 && test_char < 120354 ) { return true; }
		if( test_char >= 120380 && test_char < 120406 ) { return true; }
		if( test_char >= 120432 && test_char < 120458 ) { return true; }
		if( test_char >= 120488 && test_char < 120513 ) { return true; }
		if( test_char >= 120546 && test_char < 120571 ) { return true; }
		if( test_char >= 120604 && test_char < 120629 ) { return true; }
		if( test_char >= 120662 && test_char < 120687 ) { return true; }
		if( test_char >= 120720 && test_char < 120745 ) { return true; }
		if( test_char == 120778 ) { return true; }
		if( test_char >= 125184 && test_char < 125218 ) { return true; }
		if( test_char >= 127280 && test_char < 127306 ) { return true; }
		if( test_char >= 127312 && test_char < 127338 ) { return true; }
		if( test_char >= 127344 && test_char < 127370 ) { return true; }

		return false;
	}
	
};//! namespace txt

